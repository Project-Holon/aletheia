/*
 * function: C_GEAR_CountCellsOfKind
 * address: 0x021F0D80
 * packet: pkt_ov029_021F0D80
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   C_GEAR_GetCellKind 0x021F2B9C thumb ov029
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 C_GEAR_GetCellKind(u8 *p, int row, int col);
int C_GEAR_CountCellsOfKind(void *p, int value)
{
    int j, i, count;
    if (value == 4) return 1;
    count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (value == C_GEAR_GetCellKind(p, j, i)) count++;
        }
    }
    return count;
}
