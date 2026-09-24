/*
 * function: func_021BAE90
 * address:  0x021BAE90
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BADE0  0x021BADE0  arm  ov114
 *
 *
 * Walks the unlink list, flushing each node through func_021BADE0.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BADE0(void *, int, int);

void func_021BAE90(u32 **p, int v)
{
    u32 *n = *p;
    while (n != 0) {
        func_021BADE0(p, v, n[2]);
        n = *p;
    }
}
