/*
 * function: FLDMMDL_MOVE_InitWallWalkMode2Hand1
 * address: 0x0219C10C
 * packet: pkt_ov021_0219C10C
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
 *   FLDMMDL_MOVE_InitWallWalk 0x0219C0D4 thumb
 */

typedef unsigned int   u32;
void FLDMMDL_MOVE_InitWallWalk();
void FLDMMDL_MOVE_InitWallWalkMode2Hand1(u32 a);

void FLDMMDL_MOVE_InitWallWalkMode2Hand1(u32 a) { FLDMMDL_MOVE_InitWallWalk(a, 2, 1); }
