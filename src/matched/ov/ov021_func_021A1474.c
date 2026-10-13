/*
 * function: FIELD_SUBSCREEN_CheckBeaconViewRequest
 * address: 0x021A1474
 * packet: pkt_ov021_021A1474
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
 *   func_021F2404 0x021F2404 thumb ov032
 */

typedef struct { unsigned char pad[0x20]; void *f20; } Obj_021A1474;
extern int func_021F2404(void *p);
int FIELD_SUBSCREEN_CheckBeaconViewRequest(Obj_021A1474 *p);

int FIELD_SUBSCREEN_CheckBeaconViewRequest(Obj_021A1474 *p) { return func_021F2404(p->f20); }
