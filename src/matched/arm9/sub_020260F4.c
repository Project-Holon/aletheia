/*
 * function: CURSOR_MOVE_SetState
 * address:  0x020260F4
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef void (*Callback)(u32, u8, int);

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
    Callback *callbacks;
    u32 field_1C;
};

void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state)
{
    obj->field_4 = state;
    if (state == 1) {
        obj->field_E = 0xff;
        obj->field_F = 0xff;
        obj->callbacks[0](obj->field_1C, obj->field_D, -1);
    } else {
        obj->callbacks[1](obj->field_1C, obj->field_D, -1);
    }
}
