/*
 * function: FLDMMDL_MOVECODE_InitFixedDirUp
 * address: 0x0219A574
 * packet: pkt_ov021_0219A574
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/unit_02198D3C.c and filed here.
 *
 * symbols:
 *   FLDMMDL_MOVECODE_InitFixedDir 0x0219A528 thumb
 */

typedef unsigned int   u32;
int FLDMMDL_MOVECODE_InitFixedDir();
int FLDMMDL_MOVECODE_InitFixedDirUp(u32 a);

int FLDMMDL_MOVECODE_InitFixedDirUp(u32 a) { return FLDMMDL_MOVECODE_InitFixedDir(a, 0); }
