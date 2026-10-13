/*
 * function: FLDMMDL_MOVECODE_InitTurnRandomSet10
 * address: 0x0219A144
 * packet: pkt_ov021_0219A144
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
 *   FLDMMDL_MOVECODE_InitTurnRandom 0x0219A098 thumb
 */

typedef unsigned int   u32;
int FLDMMDL_MOVECODE_InitTurnRandom(u32 a, u32 b);
int FLDMMDL_MOVECODE_InitTurnRandomSet10(u32 a);

int FLDMMDL_MOVECODE_InitTurnRandomSet10(u32 a) { return FLDMMDL_MOVECODE_InitTurnRandom(a, 10); }
