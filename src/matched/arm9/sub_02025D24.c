/*
 * function: CURSOR_MOVE_SetMode
 * address:  0x02025D24
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct Struct_02025D24 {
    u8 pad[8];
    u32 field_8;
};

void CURSOR_MOVE_SetMode(struct Struct_02025D24 *obj)
{
    obj->field_8 = 1;
}
