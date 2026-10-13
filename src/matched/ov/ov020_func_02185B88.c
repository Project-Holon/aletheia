/*
 * function: EVENT_MAPCHANGE_SetPlayerVanish
 * address: 0x02185B88
 * packet: pkt_ov020_02185B88
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetFieldPlayer 0x02188CB4 thumb ov021
 *   FIELD_PLAYER_GetMmdl 0x021A3074 thumb ov021
 *   FLDMMDL_SetStatusBitVanish 0x0216DAC8 thumb ov010
 */
typedef unsigned char  u8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *, unsigned int);
void EVENT_MAPCHANGE_SetPlayerVanish(void *p, unsigned int v)
{
    FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(p)), v);
}
