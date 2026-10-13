/*
 * function: func_021B23E0
 * address:  0x021B23E0
 * packet:   pkt_ov013_021B23E0
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctSession  0x021B60D8  data  ov013  a4
 *   gVctGroup  0x021B4BD0  data  ov013  a4
 *   gVctAnnounceTimeout  0x021B3C48  data  ov013  a4
 *   gVctPeerPool  0x021B4BE0  data  a4
 *   d_021B4C0C  0x021B4C0C  data  ov013  a4
 *   func_020870D0  0x020870D0  arm
 *   VCT_SESSION_BroadcastState  0x021B26DC  arm  ov013
 */

#include "../include/G_Pool.h"

typedef unsigned long long u64;

typedef struct Ctx {
    int f0;
    int (*cb)(int, int, int, int);
    int arg;
    int fC;
    int state;
} Ctx;

typedef struct Stat {
    int f0;
    int f4;
    u64 t;
} Stat;

extern Ctx gVctSession;
extern Stat gVctGroup;
extern u64 gVctAnnounceTimeout;
extern struct Pool gVctPeerPool;
extern char d_021B4C0C;
extern u64 func_020870D0(void);
extern void VCT_SESSION_BroadcastState(int);

void func_021B23E0(void)
{
    u64 now;

    now = func_020870D0();
    if (gVctSession.state != 2)
        return;
    if (gVctSession.fC == 0)
        return;
    if (gVctGroup.t == 0)
        return;
    if (now - gVctGroup.t <= gVctAnnounceTimeout)
        return;
    gVctGroup.t = 0;
    gVctPeerPool.active_state = 0;
    gVctPeerPool.active_fc = 0;
    VCT_SESSION_BroadcastState(0);
    gVctSession.cb(*((unsigned char *)&gVctPeerPool + 0x30), 9, (int)&d_021B4C0C, gVctSession.arg);
}
