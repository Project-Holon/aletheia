/*
 * function: FIELD_PLACE_NAME_HasPlaceNameChanged
 * address:  0x021BCA8C
 * packet:   pkt_ov021_021BCA8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x44];
    u16 h44;
    u16 h46;
} Obj;

typedef unsigned int   u32;
extern u32 func_02013E4C(u32 id);

int FIELD_PLACE_NAME_HasPlaceNameChanged(Obj *p)
{
    int a = func_02013E4C(p->h44);

    if (a != func_02013E4C(p->h46)) {
        return 1;
    }
    return 0;
}
