/*
 * function: ZUKAN_DETAIL_PROCSYS_FreeNode
 * address:  0x021BC26C
 * packet:   pkt_021BC26C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0  arm
 *
 * Tail call to the ARM9 function at 0x020307B0: loads the pointer from the pool and branches through it.
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void ZUKAN_DETAIL_PROCSYS_FreeNode(void *p)
{
    func_020307B0(p);
}
