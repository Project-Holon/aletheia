/*
 * function: EVENTDATA_SYSTEM_ToggleSubscreenEvent
 * address: 0x021646A0
 * packet: pkt_ov010_021646A0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetSubscreen 0x02188CCC thumb ov021
 *   FIELD_SUBSCREEN_GetMode 0x021A0F90 thumb ov021
 *   FIELD_SUBSCREEN_RequestMode 0x021A0F30 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern u32 FIELD_SUBSCREEN_GetMode(u8 *p);
extern int FIELD_SUBSCREEN_RequestMode(u32 a, u32 b);
int EVENTDATA_SYSTEM_ToggleSubscreenEvent(void *a,void *b,void **p){void *v=(void *)FIELDMAP_GetSubscreen(p[1]); if(FIELD_SUBSCREEN_GetMode(v)==6)FIELD_SUBSCREEN_RequestMode((u32)v,0);else FIELD_SUBSCREEN_RequestMode((u32)v,6);return 1;}
