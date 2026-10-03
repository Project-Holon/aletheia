/*
 * function: func_021F0D80
 * address: 0x021F0D80
 * packet: pkt_ov029_021F0D80
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F2B9C 0x021F2B9C thumb ov029
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021F2B9C(u8 *p, int row, int col);
int func_021F0D80(void *p, int value)
{
    int j, i, count;
    if (value == 4) return 1;
    count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 9; j++) {
            if (value == func_021F2B9C(p, j, i)) count++;
        }
    }
    return count;
}
