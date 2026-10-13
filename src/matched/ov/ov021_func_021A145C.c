/*
 * function: FIELD_SUBSCREEN_UpdateBeaconView
 * address: 0x021A145C
 * packet: pkt_ov021_021A145C
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_3dbg.c and filed here.
 *
 * symbols:
 *   BEACON_VIEW_Update 0x021F2344 thumb ov032
 */

typedef struct { unsigned char pad[0x20]; void *f20; } Obj_021A145C;
extern int BEACON_VIEW_Update(void *p);
int FIELD_SUBSCREEN_UpdateBeaconView(Obj_021A145C *p);

int FIELD_SUBSCREEN_UpdateBeaconView(Obj_021A145C *p) { return BEACON_VIEW_Update(p->f20); }
