/*
 * function: func_021CA394
 * address: 0x021CA394
 * packet: pkt_ov093_021CA394
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: r1 is the halfword loaded at 021CA396; cast preserves the
 * original payload while retaining the callee's pointer prototype.
 * symbols:
 *   func_021BD170 0x021BD170 thumb ov093
 */
#include "../include/Obj21127.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BD170(u8 *, u8 *);
u8 func_021CA394(u8 *p, const u8 *q)
{
    u8 r;
    if (func_021BD170(p, (u8 *)(u32)*(const u16 *)&((struct Obj21127 *)q)->f4)) r = 1;
    else r = 0;
    return r;
}
