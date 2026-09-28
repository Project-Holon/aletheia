/*
 * function: func_02025D1C
 * address:  0x02025D1C
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

struct Struct_02025D1C {
    u8 pad[12];
    u8 field_C;
};

void func_02025D1C(struct Struct_02025D1C *obj)
{
    obj->field_C = 1;
}
