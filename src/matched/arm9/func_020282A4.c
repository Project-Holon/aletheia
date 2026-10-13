/*
 * unit:     no
 * function: APP_TASKMENU_WIN_ResetDecide
 * address:  0x020282A4
 * packet:   pkt_020282A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A leaf that clears the word at offset 8 and the halfword at offset 0x10.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u32 pad_00[2];
    u32 field_08;
    u32 pad_0c;
    u16 field_10;
    u16 pad_12;
};

void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj)
{
    obj->field_08 = 0;
    obj->field_10 = 0;
}
