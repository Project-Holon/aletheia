/*
 * function: FIELD_PLACE_NAME_IncrementFrame
 * address:  0x021BD0B0
 * packet:   pkt_ov021_021BD0B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x42];
    u16 h42;
} Obj;

void FIELD_PLACE_NAME_IncrementFrame(Obj *p)
{
    p->h42++;
}
