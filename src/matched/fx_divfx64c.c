/*
 * function: FX_DivFx64c
 * address:  0x0207C788
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0207C8A0   0x0207C8A0  arm
 *
 * Original (44 bytes):
 *   push {r3, lr}
 *   bl   #0x0207C8A0
 *   ldr  r1, [pc, #0x14]   ; 0x04000280
 *   ldrh r0, [r1]
 *   tst  r0, #0x8000
 *   bne  -4
 *   ldr  r1, [pc, #8]      ; 0x040002A0
 *   ldm  r1, {r0, r1}
 *   pop  {r3, pc}
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern void func_0207C8A0(u32 x);

u64 FX_DivFx64c(u32 x)
{
    func_0207C8A0(x);
    while (*(volatile u16 *)0x04000280 & 0x8000)
        ;
    return *(volatile u64 *)0x040002A0;
}
