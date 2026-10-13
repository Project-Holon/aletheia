/*
 * function: FIELD_SUBSCREEN_UpdateDowsingNoTransition
 * address: 0x021A14C0
 * packet: pkt_ov021_021A14C0
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
 *   DOWSING_UpdateDisplay 0x021F05A4 thumb ov033
 */

typedef struct { unsigned char pad[0x20]; void *f20; } Obj_021A14C0;
extern int DOWSING_UpdateDisplay(void *p);
int FIELD_SUBSCREEN_UpdateDowsingNoTransition(Obj_021A14C0 *p);

int FIELD_SUBSCREEN_UpdateDowsingNoTransition(Obj_021A14C0 *p) { return DOWSING_UpdateDisplay(p->f20); }
