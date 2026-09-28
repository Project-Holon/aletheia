/*
 * function: G3X_GetVectorMtx
 * address:  0x0207DCC8
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02082B60   0x02082B60  arm
 *
 * Original (92 bytes): the same shape as G3X_GetClipMtx, copying from
 * 0x04000680 with MI_Copy36B.
 */

typedef unsigned int u32;

extern void func_02082B60(const void *src, void *dst);

int G3X_GetVectorMtx(void *dst)
{
    if (*(volatile u32 *)0x04000600 & 0x08000000)
        return -1;
    func_02082B60((void *)0x04000680, dst);
    return 0;
}
