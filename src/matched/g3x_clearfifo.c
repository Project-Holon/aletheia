/*
 * function: G3X_ClearFifo
 * address:  0x0207DAF8
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0207DECC   0x0207DECC  arm
 *
 * Original (36 bytes):
 *   push  {r4, lr}
 *   ldr   r4, [pc, #0x14]   ; 0x04000400
 *   mov   r0, r4
 *   bl    #0x0207DECC
 *   ldr   r0, [r4, #0x200]
 *   tst   r0, #0x8000000
 *   bne   -4
 *   pop   {r4, pc}
 */

typedef unsigned int u32;

extern void func_0207DECC(void *reg);

void G3X_ClearFifo(void)
{
    volatile u32 *p = (volatile u32 *)0x04000400;
    func_0207DECC((void *)p);
    while (p[0x80] & 0x08000000)
        ;
}
