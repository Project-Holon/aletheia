/*
 * function: FX_Sqrt
 * address:  0x0207C7B4
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0207C904   0x0207C904  arm
 *
 * Original (52 bytes):
 *   push  {r3, lr}
 *   cmp   r0, #0
 *   movle r0, #0
 *   pople {r3, pc}
 *   ldr   r1, [pc, #0x18]   ; 0x040002B0
 *   mov   r2, #1
 *   strh  r2, [r1]
 *   mov   r2, #0
 *   str   r2, [r1, #8]
 *   str   r0, [r1, #0xc]
 *   bl    #0x0207C904
 *   pop   {r3, pc}
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern u32 func_0207C904(void);

u32 FX_Sqrt(s32 x)
{
    if (x <= 0)
        return 0;
    *(volatile u16 *)0x040002B0 = 1;
    *(volatile u32 *)0x040002B8 = 0;
    *(volatile u32 *)0x040002BC = x;
    return func_0207C904();
}
