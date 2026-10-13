/*
 * function: FIELD_PLACE_NAME_IsAllBlitted
 * address:  0x021BCA48
 * packet:   pkt_ov021_021BCA48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetMessageLength  0x021BD138  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x14A];
    u8 b14A;
} Obj;

extern int FIELD_PLACE_NAME_GetMessageLength(Obj *p);

int FIELD_PLACE_NAME_IsAllBlitted(Obj *p)
{
    if (FIELD_PLACE_NAME_GetMessageLength(p) <= p->b14A) {
        return 1;
    }
    return 0;
}
