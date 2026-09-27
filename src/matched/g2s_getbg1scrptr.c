/*
 * function: G2S_GetBG1ScrPtr
 * address:  0x0207DFE8
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
 * Original (32 bytes, no relocation):
 *   ldr  r0, [pc, #0x14]   ; 0x0400100A
 *   ldrh r0, [r0]
 *   and  r0, r0, #0x1f00
 *   asr  r0, r0, #8
 *   lsl  r0, r0, #0xb
 *   add  r0, r0, #0x6200000
 *   bx   lr
 */

typedef unsigned int u32;

u32 G2S_GetBG1ScrPtr(void)
{
    return (u32)((((*(volatile unsigned short *)0x0400100A & 0x1f00) >> 8) << 11) + 0x6200000);
}
