/*
 * function: FLDMMDL_MOVECODE_InitSpinRight
 * address: 0x0219A5D4
 * packet: pkt_ov021_0219A5D4
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
 *   FLDMMDL_MOVECODE_InitSpin 0x0219A5A4 thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
void FLDMMDL_MOVECODE_InitSpin(u32 a, u8 b);
void FLDMMDL_MOVECODE_InitSpinRight(u32 a);

void FLDMMDL_MOVECODE_InitSpinRight(u32 a) { FLDMMDL_MOVECODE_InitSpin(a, 3); }
