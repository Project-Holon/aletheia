/*
 * function: func_02193398
 * address:  0x02193398
 * packet:   pkt_ov021_02193398
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: only the prologue schedule differs: original copies p/c to r6/r5 then computes p + p->f08 before the stack stores (13 bytes). Local temp and narrow c/d did not move it.
 *
 * symbols:
 *   func_021D14C4  0x021D14C4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void func_021D14C4(u8 *o, u32 a, u8 *b, u32 c, u32 d, u32 e);

void func_02193398(u8 *o, u8 *p, u32 c, u32 d, u32 e)
{
    func_021D14C4(o, 0, p + *(u32 *)(p + 8), c, d, e);
    *(u32 *)(o + 0x100) = 1;
}
