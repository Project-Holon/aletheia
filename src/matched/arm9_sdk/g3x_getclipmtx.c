/*
 * function: G3X_GetClipMtx
 * address:  0x0207DC98
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02082BA0   0x02082BA0  arm
 *
 * Original (48 bytes):
 *   push  {r3, lr}
 *   ldr   r2, [pc, #0x20]   ; 0x04000600
 *   mov   r1, r0
 *   ldr   r0, [r2]
 *   tst   r0, #0x8000000
 *   mvnne r0, #0
 *   popne {r3, pc}
 *   add   r0, r2, #0x40
 *   bl    #0x02082BA0
 *   mov   r0, #0
 *   pop   {r3, pc}
 */

typedef unsigned int u32;

extern void func_02082BA0(const void *src, void *dst);

int G3X_GetClipMtx(void *dst)
{
    if (*(volatile u32 *)0x04000600 & 0x08000000)
        return -1;
    func_02082BA0((void *)0x04000640, dst);
    return 0;
}
