/*
 * function: GX_SetVCountEqVal
 * address:  0x0207D384
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
 *   ldr  r3, [pc, #0x1c]   ; 0x04000004
 *   lsl  r1, r0, #0x18
 *   ldrh r2, [r3]
 *   and  ip, r0, #0x100
 *   and  r0, r2, #0x3f
 *   orr  r0, r0, r1, lsr #16
 *   orr  r0, r0, ip, asr #1
 *   strh r0, [r3]
 *   bx   lr
 */

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

void GX_SetVCountEqVal(u32 v)
{
    u16 r = *(volatile u16 *)0x04000004;
    *(volatile u16 *)0x04000004 =
        (u16)((r & 0x3f) | ((v & 0xff) << 8) | ((s32)(v & 0x100) >> 1));
}
