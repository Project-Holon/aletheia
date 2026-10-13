/*
 * function: GFL_NET_SYSTEM_IsDeviceReady
 * address:  0x020392EC
 * packet:   pkt_020392EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *   _pNetSys     0x021469D0  data
 *
 * Returns 1 while the state byte at +0x65 is one to four, but only while the
 * global at 0x021469D0 is live; otherwise it dispatches through the vtable at
 * +0x340 of the net state and returns that hook's value (+0x6C slot).
 *
 * The `add r0, r0, #0xff` / `and r0, r0, #0xff` pair is `(u8)(v - 1)`: mwcc
 * writes the -1 as +0xFF because the truncation to u8 makes the two
 * equivalent and 0xFF keeps the `and` mask a plain immediate.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_IsDeviceReady.c \
 *       --func GFL_NET_SYSTEM_IsDeviceReady --addr 0x020392EC --cc 1.1p1 --arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GFL_NET_GetSession(void);
extern void *func_0203D798(void);
extern struct LinkState *_pNetSys;

int GFL_NET_SYSTEM_IsDeviceReady(void)
{
    u8 *s = GFL_NET_GetSession();
    u8 *p = func_0203D798();

    if ((*(u32 *)&_pNetSys) != 0 && (u8)(p[0x65] + 0xFF) <= 3)
        return 1;

    return (*(int (**)(void))(*(u32 *)(s + 0x340) + 0x6C))();
}
