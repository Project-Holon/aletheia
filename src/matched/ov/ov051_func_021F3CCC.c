/*
 * function: FIELD_GIMMICK_D06_AddPanelPulse
 * address: 0x021F3CCC
 * packet: pkt_ov051_021F3CCC
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Original 021F3CFE stores r0 after 021C9258, whose filed void
 *       definition leaves its final call result live; caller uses unsigned.
 * symbols:
 *   FLDMMDL_MOVE_GridToVectorPos 0x02164280 thumb ov010
 *   FIELDMAP_GetEffect 0x02188CD0 thumb ov021
 *   FLDEFF_D06DENKI_StartPulse 0x021C9258 thumb ov021
 */

extern void FLDMMDL_MOVE_GridToVectorPos(int, int, int *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELDMAP_GetEffect(u8 *p);
extern unsigned FLDEFF_D06DENKI_StartPulse(unsigned, int *);

void FIELD_GIMMICK_D06_AddPanelPulse(int *a, unsigned *b, int x, int y, int z)
{
    int v[3];
    FLDMMDL_MOVE_GridToVectorPos((short)x, (short)z, v);
    v[1] = (int)(((unsigned)y << 16) + 0x8000u);
    *b = FLDEFF_D06DENKI_StartPulse(FIELDMAP_GetEffect((u8 *)a[2]), v);
}
