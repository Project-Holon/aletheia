/*
 * function: func_020392EC
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
 *   func_0203D788  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *   g_021469D0     0x021469D0  data
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
 *   python tools/match.py one --src src/matched/func_020392EC.c \
 *       --func func_020392EC --addr 0x020392EC --cc 1.1p1 --arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern struct LinkState *g_021469D0;

int func_020392EC(void)
{
    u8 *s = func_0203D788();
    u8 *p = func_0203D798();

    if ((*(u32 *)&g_021469D0) != 0 && (u8)(p[0x65] + 0xFF) <= 3)
        return 1;

    return (*(int (**)(void))(*(u32 *)(s + 0x340) + 0x6C))();
}
