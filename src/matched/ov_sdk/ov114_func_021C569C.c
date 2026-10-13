/*
 * function: DWCi_NdAlloc
 * address:  0x021C569C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Thunk: func_0205A17C(10, a, b) through the literal pool.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_0205A17C(int name, unsigned long size, int align);

void *DWCi_NdAlloc(int a, int b)
{
    return func_0205A17C(0xa, a, b);
}
