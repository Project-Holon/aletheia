/*
 * function: FLDMMDL_MOVE_InitFaceDirDownFlag
 * address: 0x0219BFB8
 * packet: pkt_ov021_0219BFB8
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
 *   FLDMMDL_MOVE_InitFaceDir 0x0219BF60 thumb
 */

typedef unsigned int   u32;
u32 FLDMMDL_MOVE_InitFaceDir();
u32 FLDMMDL_MOVE_InitFaceDirDownFlag(u32 a);

u32 FLDMMDL_MOVE_InitFaceDirDownFlag(u32 a) { return FLDMMDL_MOVE_InitFaceDir(a, 1, 1); }
