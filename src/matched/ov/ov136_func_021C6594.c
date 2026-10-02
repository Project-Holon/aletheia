/*
 * function: func_021C6594
 * address:  0x021C6594
 * packet:   pkt_ov136_021C6594
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204A600  0x0204A600  arm
 */

typedef unsigned char u8;
extern void func_0204A600(void *);
void func_021C6594(u8 *p)
{
    void *q = *(void **)(p + 0x1EC);
    if (q != 0) {
        func_0204A600(q);
    }
}
