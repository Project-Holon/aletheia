/*
 * function: C_GEAR_IsAnyTileFlashing
 * address: 0x021F0A68
 * packet: pkt_ov029_021F0A68
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   C_GEAR_IsTileFlashing 0x021F0C68 thumb ov029
 */
extern int C_GEAR_IsTileFlashing(unsigned short *);
int C_GEAR_IsAnyTileFlashing(char *p)
{
    int result, i, j;
    result = 0;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            if (C_GEAR_IsTileFlashing((unsigned short *)(p + 0x2d0 + i * 32 + j * 8))) {
                result = 1;
                break;
            }
        }
    }
    return result;
}
