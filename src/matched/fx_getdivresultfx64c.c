/*
 * function: FX_GetDivResultFx64c
 * address:  0x0207C848
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
 * Original (36 bytes, no relocation):
 *   ldr  r1, [pc, #0x14]   ; 0x04000280
 *   ldrh r0, [r1]
 *   tst  r0, #0x8000
 *   bne  -4
 *   ldr  r1, [pc, #8]      ; 0x040002A0
 *   ldm  r1, {r0, r1}
 *   bx   lr
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

u64 FX_GetDivResultFx64c(void)
{
    while (*(volatile u16 *)0x04000280 & 0x8000)
        ;
    return *(u64 *)0x040002A0;
}
