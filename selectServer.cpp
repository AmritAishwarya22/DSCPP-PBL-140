#include "Loadbalancer.h"
#include <algorithm>
uint32_t hashValue(uint32_t x) 
{
 x ^= x >> 16;
 x *= 0x7feb352dU;
 x ^= x >> 15;
 x *= 0x846ca68bU;
 x ^= x >> 16;
 return x;
}
std::vector<HashNode> buildHashRing(Server s[], int n, int replicas) {
    std::vector<HashNode> ring;
    for (int i = 0; i < n; i++) {
        uint32_t baseKey = (s[i].serverId != 0)
            ? static_cast<uint32_t>(s[i].serverId)
            : static_cast<uint32_t>(i + 1);
        for (int r = 0; r < replicas; r++) {
            uint32_t h = hashValue(baseKey * 10007U + static_cast<uint32_t>(r) * 97U + 13U);
            ring.push_back({h, i});
        }
    }
    std::sort(ring.begin(), ring.end(), [](const HashNode& a, const HashNode& b) {
        if (a.hash == b.hash) return a.serverIndex < b.serverIndex;
        return a.hash < b.hash;
    });
    return ring;
}

int selectServer1(Server s[], int n, Task t) {
    if (n <= 0) return -1;

    std::vector<HashNode> ring = buildHashRing(s, n, 3);
    if (ring.empty()) return -1;

    uint32_t taskKey = static_cast<uint32_t>(t.id) * 2654435761U + static_cast<uint32_t>(t.priority) * 40503U;
    uint32_t taskHash = hashValue(taskKey);

    size_t startIdx = 0;
    while (startIdx < ring.size() && ring[startIdx].hash < taskHash) {
        startIdx++;
    }
    if (startIdx == ring.size()) {
        startIdx = 0;
    }

    for (size_t offset = 0; offset < ring.size(); offset++) {
        size_t idx = (startIdx + offset) % ring.size();
        int srvIdx = ring[idx].serverIndex;
        if (checkEligibility1(s[srvIdx], t)) {
            return srvIdx;
        }
    }

    return -1;
}