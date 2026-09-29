/*
 * function: func_021D5C44
 * address:  0x021D5C44
 * packet:   pkt_ov093_021D5C44
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _dflt   0x0209B750  arm
 *   _dfltu  0x0209B790  arm
 *   _ddiv   0x0209D1E0  arm
 *   _dgr    0x0209B864  arm
 *   _dmul   0x0209B2E8  arm
 *   _dadd   0x0209AC04  arm
 *   _dsub   0x0209AF34  arm
 *   _dfix   0x0209C508  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Rat {
    u8 pad0[0xe];
    u16 den;
    u16 num;
};

int func_021D5C44(struct Rat *p)
{
    double x = (double)(100 * p->num) / (double)p->den;
    double y;
    if (x > 0)
        y = 4096.0 * x + 0.5;
    else
        y = 4096.0 * x - 0.5;
    return (int)y;
}
