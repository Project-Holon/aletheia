/*
 * function: func_021DB300
 * address:  0x021DB300
 * packet:   pkt_021DB300
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the tick from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x140 word of the fourth argument.
 */

typedef unsigned long u32;

extern u32 func_020399A8(void);
extern u32 func_0203D1A4(u32 v);

void func_021DB300(u32 a, u32 b, u32 c, char *d, u32 e)
{
    if (e != func_020399A8())
        return;
    if (a == func_0203D1A4(func_020399A8()))
        return;
    *(u32 *)(d + 0x140) = 1;
}

