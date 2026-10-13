/*
 * function: FIELD_PLACE_NAME_SetStateRaw
 * address:  0x021BD0A0
 * packet:   pkt_ov021_021BD0A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    char pad[0x3C];
    int f3C;
} Obj;

void FIELD_PLACE_NAME_SetStateRaw(Obj *p, int v)
{
    p->f3C = v;
}
