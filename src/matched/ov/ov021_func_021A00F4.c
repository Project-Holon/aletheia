/*
 * function: FLDMMDL_DRAW_DeleteEffectAlias
 * address: 0x021A00F4
 * packet: pkt_ov021_021A00F4
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_fog.c and filed here.
 *
 * symbols:
 *   FLDMMDL_DRAW_DeleteEffect 0x021A00E0 thumb
 */

typedef unsigned int   u32;
void FLDMMDL_DRAW_DeleteEffect(u32 a);
void FLDMMDL_DRAW_DeleteEffectAlias(u32 a);

void FLDMMDL_DRAW_DeleteEffectAlias(u32 a) { FLDMMDL_DRAW_DeleteEffect(a); }
