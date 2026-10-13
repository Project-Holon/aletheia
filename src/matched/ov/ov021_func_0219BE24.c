/*
 * function: FLDMMDL_MOVE_InitHideKind1Alt
 * address: 0x0219BE24
 * packet: pkt_ov021_0219BE24
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/unit_0219B508.c and filed here.
 *
 * symbols:
 *   FLDMMDL_MOVE_InitHide 0x0219BDC4 thumb
 */

typedef unsigned int   u32;
void FLDMMDL_MOVE_InitHide(u32 a, u32 b);
void FLDMMDL_MOVE_InitHideKind1Alt(u32 a);

void FLDMMDL_MOVE_InitHideKind1Alt(u32 a) { FLDMMDL_MOVE_InitHide(a, 1); }
