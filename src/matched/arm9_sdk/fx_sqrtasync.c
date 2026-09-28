/*
 * function: FX_SqrtAsync
 * address:  0x0207C8D0
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (52 bytes, no relocation):
 *   ldr    r1, [pc, #0x28]   ; 0x040002B0
 *   cmp    r0, #0
 *   movgt  r2, #1
 *   strhgt r2, [r1]
 *   movgt  r2, #0
 *   strgt  r2, [r1, #8]
 *   movle  r0, #1
 *   strhle r0, [r1]
 *   movle  r0, #0
 *   strle  r0, [r1, #8]
 *   str    r0, [r1, #0xc]
 *   bx     lr
 */

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

void FX_SqrtAsync(s32 x)
{
    if (x > 0) {
        *(volatile u16 *)0x040002B0 = 1;
        *(volatile u32 *)0x040002B8 = 0;
    } else {
        *(volatile u16 *)0x040002B0 = 1;
        *(volatile u32 *)0x040002B8 = 0;
        x = 0;
    }
    *(volatile u32 *)0x040002BC = x;
}
