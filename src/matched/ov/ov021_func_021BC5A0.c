/*
 * function: FIELD_PLACE_NAME_ForceShowForZone
 * address:  0x021BC5A0
 * packet:   pkt_ov021_021BC5A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLACE_NAME_SetZoneId  0x021BD120  thumb  ov021
 *   FIELD_PLACE_NAME_Interrupt  0x021BCBC8  thumb  ov021
 *   FIELD_PLACE_NAME_RequestForceShow  0x021BCA64  thumb  ov021
 */

typedef unsigned short u16;

extern void FIELD_PLACE_NAME_SetZoneId(void *p, u16 v);
typedef unsigned char  u8;
extern void FIELD_PLACE_NAME_Interrupt(char *p);
extern void FIELD_PLACE_NAME_RequestForceShow(u8 *p);

void FIELD_PLACE_NAME_ForceShowForZone(void *p, int v)
{
    FIELD_PLACE_NAME_SetZoneId(p, (u16)v);
    FIELD_PLACE_NAME_Interrupt(p);
    FIELD_PLACE_NAME_RequestForceShow(p);
}
