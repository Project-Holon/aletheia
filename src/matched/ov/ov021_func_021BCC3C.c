/*
 * function: FIELD_PLACE_NAME_StateIdle
 * address:  0x021BCC3C
 * packet:   pkt_ov021_021BCC3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FIELD_PLACE_NAME_GetForceShowRequest  0x021BCA88  thumb  ov021
 *   FIELD_PLACE_NAME_ClearForceShowRequest  0x021BCA6C  thumb  ov021
 *   FIELD_PLACE_NAME_GetZoneChangeRequest  0x021BCA74  thumb  ov021
 *   FIELD_PLACE_NAME_HasPlaceNameChanged  0x021BCA8C  thumb  ov021
 *   FIELD_PLACE_NAME_ClearZoneChangeRequest  0x021BCA80  thumb  ov021
 *   FIELD_PLACE_NAME_SetState  0x021BCB9C  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELD_PLACE_NAME_GetForceShowRequest(u8 *p);
extern u8 *FIELD_PLACE_NAME_ClearForceShowRequest(u8 *p);
extern u32 FIELD_PLACE_NAME_GetZoneChangeRequest(u8 *p);
extern int FIELD_PLACE_NAME_HasPlaceNameChanged(void *p);
extern void FIELD_PLACE_NAME_ClearZoneChangeRequest(u8 *p);
extern void FIELD_PLACE_NAME_SetState(void *p, int a);

void FIELD_PLACE_NAME_StateIdle(void *p)
{
    int r = 0;

    if (FIELD_PLACE_NAME_GetForceShowRequest(p)) {
        r = 1;
        FIELD_PLACE_NAME_ClearForceShowRequest(p);
    } else if (FIELD_PLACE_NAME_GetZoneChangeRequest(p)) {
        if (FIELD_PLACE_NAME_HasPlaceNameChanged(p)) {
            r = 1;
        }
        FIELD_PLACE_NAME_ClearZoneChangeRequest(p);
    }
    if (r) {
        FIELD_PLACE_NAME_SetState(p, 1);
    }
}
