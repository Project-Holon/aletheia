/*
 * function: BUTTON_MAN_SetRot
 * address:  0x02051880
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Setter on the same object as its packet-mate src/matched/BUTTON_MAN_FindRowData.c:
 * copies a three-component 16-bit vector into the object's 0x50..0x54
 * triple.  The three loads come out ahead of the three stores, which is the
 * plain field-by-field spelling; a struct assignment would be ldm/stm.
 */

typedef unsigned short u16;

struct Vec3 {
    u16 x;
    u16 y;
    u16 z;
};

struct Obj {
    char pad[0x50];
    u16 x;
    u16 y;
    u16 z;
};

void BUTTON_MAN_SetRot(struct Obj *o, const struct Vec3 *v)
{
    o->x = v->x;
    o->y = v->y;
    o->z = v->z;
}
