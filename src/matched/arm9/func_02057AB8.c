/*
 * function: func_02057AB8
 * address:  0x02057AB8
 * packet:   pkt_02057830
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned short u16;
typedef unsigned char u8;

struct Obj {
    u8 _00[0x2e];
    u16 _2e;
};

void func_02057AB8(struct Obj *o, int unused, int t)
{
    u16 v;

    v = (0xff - t) * 0x1f / 255;
    o->_2e = (o->_2e & ~0x3e0) | ((v & 0x1f) << 5);
}
