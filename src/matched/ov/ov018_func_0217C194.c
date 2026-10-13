/*
 * function: INTRUDE_FIELD_AddMarkerMmdls
 * address: 0x0217C194
 * packet: pkt_ov018_0217C194
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two alignment bytes at 0x0217C1CE.
 * symbols:
 *   FIELDMAP_GetZoneId 0x02188C9C thumb ov021
 *   ZONEDATA_IsZone117 0x02013D5C thumb
 *   INTRUDE_FIELD_AddMarkerMmdl 0x0217C14C thumb ov018
 */
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetZoneId(u8 *p);
typedef unsigned int   u32;
extern u32 ZONEDATA_IsZone117(u32 id);
extern void INTRUDE_FIELD_AddMarkerMmdl(int, u16, u16, int);
void INTRUDE_FIELD_AddMarkerMmdls(int p)
{
    int i;
    if (ZONEDATA_IsZone117(FIELDMAP_GetZoneId((u8 *)p)) != 0) {
        for (i = 0; i < 3; ++i)
            INTRUDE_FIELD_AddMarkerMmdl(p, (((i << 22) + 0x1f8000) >> 12) / 16, 29, 32);
    }
}
