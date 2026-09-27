/*
 * function: FX_InvAsync
 * address:  0x0207C8A0
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
 * Original (48 bytes, no relocation):
 *   ldr  r3, [pc, #0x24]   ; 0x04000280
 *   mov  r1, #1
 *   strh r1, [r3]
 *   mov  r2, #0
 *   str  r2, [r3, #0x10]
 *   mov  r1, #0x1000
 *   str  r1, [r3, #0x14]
 *   str  r0, [r3, #0x18]
 *   mov  r0, r2
 *   str  r0, [r3, #0x1c]
 *   bx   lr
 */

typedef unsigned short u16;
typedef unsigned int u32;

void FX_InvAsync(u32 x)
{
    u32 zero = 0;
    *(volatile u16 *)0x04000280 = 1;
    *(volatile u32 *)0x04000290 = zero;
    *(volatile u32 *)0x04000294 = 0x1000;
    *(volatile u32 *)0x04000298 = x;
    *(volatile u32 *)0x0400029C = zero;
}
