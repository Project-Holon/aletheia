/*
 * function: func_021BD3B8
 * address:  0x021BD3B8
 * packet:   pkt_ov088_021BD3B8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020071A8  0x020071A8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    void *p0;
    u8 _4;
    u8 _5;
    u8 _6;
    u8 f7;
} Req;

extern int func_020071A8(int a0);

void func_021BD3B8(Req *r)
{
    if (r->f7 == 0 && r->_4 != 3) {
        func_020071A8((int)r->p0);
        r->f7 = 1;
    }
}
