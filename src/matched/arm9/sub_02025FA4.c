/*
 * function: func_02025FA4
 * address:  0x02025FA4
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UI_SetInputMode  0x020355D8  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void UI_SetInputMode(u8 v);

typedef void (*Callback)(u32, u8, u8);

struct Struct_02025CD0 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u8 field_C;
    u8 field_D;
    u8 field_E;
    u8 field_F;
    int field_10;
    int field_14;
    Callback *callback_ptr;
    u32 field_1C;
};

int func_02025FA4(struct Struct_02025CD0 *obj)
{
    int one = 1;

    UI_SetInputMode(0);
    obj->field_4 = one;
    obj->field_E = 0xff;
    obj->field_F = 0xff;
    (*obj->callback_ptr)(obj->field_1C, obj->field_D, obj->field_E);

    return one - 5;
}
