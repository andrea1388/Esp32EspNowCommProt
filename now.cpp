#include "sys/time.h"
#include <cstdint>
uint32_t now() {
    uint32_t r;
    struct timeval now;
    gettimeofday(&now, NULL);
    r=now.tv_usec/1000;
    return (uint32_t)now.tv_sec * 1000 + r;
    
}
