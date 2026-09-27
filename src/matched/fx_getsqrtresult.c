/*
 * function: FX_GetSqrtResult
 * address:  0x0207C904
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
 * Original (44 bytes, no relocation):
 *   ldr  r1, [pc, #0x1c]   ; 0x040002B0
 *   ldrh r0, [r1]
 *   tst  r0, #0x8000
 *   bne  -4
 *   ldr  r0, [pc, #0x10]   ; 0x040002B4
 *   ldr  r0, [r0]
 *   add  r0, r0, #0x200
 *   lsr  r0, r0, #0xa
 *   bx   lr
 */

typedef unsigned short u16;
typedef unsigned int u32;

u32 FX_GetSqrtResult(void)
{
    while (*(volatile u16 *)0x040002B0 & 0x8000)
        ;
    return (*(volatile u32 *)0x040002B4 + 0x200) >> 10;
}
