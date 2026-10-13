/*
 * function: C_GEAR_GetTilePalette
 * address: 0x021F0C70
 * packet: pkt_ov029_021F0C70
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   C_GEAR_IsCellMarked 0x021F2BB8 thumb ov029
 *   d_021F32B3 0x021F32B3 data a1
 */
typedef unsigned char  u8;
extern int C_GEAR_IsCellMarked(u8 *p, int row, int col);
extern const unsigned char d_021F32B3[][9];
int C_GEAR_GetTilePalette(void *p, int i, int j, int k)
{
    if (C_GEAR_IsCellMarked(p, j, k)) return d_021F32B3[i][4];
    return d_021F32B3[i][j];
}
