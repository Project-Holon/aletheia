/*
 * function: FIELD_PLACE_NAME_IsAllSpawned
 * address:  0x021BC910
 * packet:   pkt_ov021_021BC910
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetMessageLength  0x021BD138  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x148];
    u8 b148;
} Obj;

extern u8 FIELD_PLACE_NAME_GetMessageLength(u8 *p);

int FIELD_PLACE_NAME_IsAllSpawned(Obj *p)
{
    if (FIELD_PLACE_NAME_GetMessageLength((u8 *)p) <= p->b148) {
        return 1;
    }
    return 0;
}
