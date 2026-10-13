/*
 * function: GFL_NET_SYSTEM_SetWaitMode
 * address:  0x020394F0
 * packet:   pkt_020394F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _pNetSys     0x021469D0  data
 *   func_0203D798  0x0203D798  arm
 */

#include "../include/G_LinkState.h"

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u8 pad_000[0x65];
    u8 f065;
} T_0203D798;

extern T_0203D798 *func_0203D798(void);
extern struct LinkState *_pNetSys;

void GFL_NET_SYSTEM_SetWaitMode(u32 a)
{
    u8 v = func_0203D798()->f065;

    if ((u8)(v + 0xff) > 1) {
        return;
    }
    _pNetSys->f1AC = a;
    if (a == 0) {
        return;
    }
    _pNetSys->f1B0 = 0;
    _pNetSys->f1b4 = 0;
    _pNetSys->f1b8 = 0;
}
