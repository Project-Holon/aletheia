/*
 * function: func_021A10D4
 * address:  0x021A10D4
 * packet:   pkt_ov009_021A10D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessMaploop (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0219F6C8  0x0219F6C8  arm  ov009
 *   func_0219F7C4  0x0219F7C4  arm  ov009
 *   func_0219F978  0x0219F978  arm  ov009
 */

#include "../../../matched/arm9_sdk/libc/string.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct SBServerList SBServerList;
typedef void (*SBMapLoopCallback)(SBServerList *slist, void *server, long changeTime, int count, char **mapList, void *instance);

struct SBServerList {
    char pad0[0x48c];
    SBMapLoopCallback callback;
    char pad490[4];
    void *instance;
};

extern int func_0219F6C8(SBServerList *slist, u32 ip, u16 port);
extern void *func_0219F7C4(SBServerList *slist, int i);
extern int func_0219F978(char *buf, int len);

int func_021A10D4(SBServerList *slist, char *buf, int len)
{
    long changeTime;
    u32 ip;
    u16 port;
    void *server;
    u8 mapCount;
    int i;
    char *mapList[16];
    int maplen;

    if (len < 11)
        return 4;
    memcpy(&ip, buf, 4);
    memcpy(&port, &buf[4], 2);
    i = func_0219F6C8(slist, ip, port);
    if (i == -1)
        return 0;
    server = func_0219F7C4(slist, i);
    memcpy(&changeTime, &buf[6], 4);
    changeTime = (((u32)changeTime >> 24) & 0xFF) | (((u32)changeTime >> 8) & 0xFF00) | (((u32)changeTime << 8) & 0xFF0000) | (((u32)changeTime << 24) & 0xFF000000);
    mapCount = buf[10];
    buf += 11;
    len -= 11;
    for (i = 0; i < mapCount && i < 16; i++) {
        if (len < 1)
            break;
        maplen = func_0219F978(buf, len);
        if (maplen == -1)
            return 4;
        mapList[i] = buf;
        buf += maplen;
        len -= maplen;
    }
    if (slist->callback == 0)
        return 0;
    slist->callback(slist, server, changeTime, i, mapList, slist->instance);
    return 0;
}
