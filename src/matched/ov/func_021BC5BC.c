/*
 * function: FIELD_PLACE_NAME_Cancel
 * address:  0x021BC5BC
 * packet:   pkt_021BC5BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_PLACE_NAME_SetState  0x021BCB9C  thumb  ov021
 *   FIELD_PLACE_NAME_ClearZoneChangeRequest  0x021BCA80  thumb  ov021
 *   FIELD_PLACE_NAME_ClearForceShowRequest  0x021BCA6C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *FIELD_PLACE_NAME_ClearForceShowRequest(u8 *p);
extern void FIELD_PLACE_NAME_ClearZoneChangeRequest(u8 *p);
extern void FIELD_PLACE_NAME_SetState(void *p, int keep);

int FIELD_PLACE_NAME_Cancel(u8 *a)
{
FIELD_PLACE_NAME_SetState((void *)a, 0);
FIELD_PLACE_NAME_ClearZoneChangeRequest((u8 *)a);
return (int)FIELD_PLACE_NAME_ClearForceShowRequest(a);
}

