/*
 * function: FLDMMDL_MOVECODE_InitFixedDirLeft
 * address: 0x0219A58C
 * packet: pkt_ov021_0219A58C
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
int FLDMMDL_MOVECODE_InitFixedDirLeft(u32 a);

int FLDMMDL_MOVECODE_InitFixedDirLeft(u32 a) { return FLDMMDL_MOVECODE_InitFixedDir(a, 2); }
