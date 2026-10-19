/*
 * function: EVENT_FIELD_MENU_CreateForZone
 * address: 0x0215FCE0
 * packet: pkt_ov010_0215FCE0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   EVENT_FIELD_MENU_Create 0x0215FC40 thumb ov010
 *   func_020124E8 0x020124E8 thumb
 *   FIELDMAP_GetZoneId 0x02188C9C thumb ov021
 *   ZONEDATA_IsZone96Pair 0x02013CE0 thumb
 */

typedef unsigned int u32;
struct Desc;
extern struct Desc *EVENT_FIELD_MENU_Create(int a0, int a1, unsigned short a2);
struct Obj;
extern void *func_020124E8(struct Obj *p);
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u32 ZONEDATA_IsZone96Pair(u32);
int EVENT_FIELD_MENU_CreateForZone(int a, int b, unsigned short c) { int task; u32 *p; task=(int)EVENT_FIELD_MENU_Create(a,b,c); p=func_020124E8((struct Obj *)task); p[6]=ZONEDATA_IsZone96Pair(FIELDMAP_GetZoneId((void *)b)) == 1 ? 5 : 2; return task; }
