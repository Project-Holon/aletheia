/*
 * function: G3X_SetClearColor
 * address:  0x0207DD24
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
 * Original (40 bytes, no relocation):
 *   ldr   ip, [sp]
 *   orr   r0, r0, r1, lsl #16
 *   orr   r1, r0, r3, lsl #24
 *   cmp   ip, #0
 *   ldr   r0, [pc, #0xc]   ; 0x04000350
 *   orrne r1, r1, #0x8000
 *   str   r1, [r0]
 *   strh  r2, [r0, #4]
 *   bx    lr
 */

typedef unsigned short u16;
typedef unsigned int u32;

void G3X_SetClearColor(u32 r, u32 g, u32 b, u32 a, u32 flag)
{
    u32 v = r | (g << 16) | (a << 24);
    if (flag != 0)
        v |= 0x8000;
    *(volatile u32 *)0x04000350 = v;
    *(volatile u16 *)0x04000354 = (u16)b;
}
