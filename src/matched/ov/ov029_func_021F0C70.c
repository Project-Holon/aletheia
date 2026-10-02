/*
 * function: func_021F0C70
 * address: 0x021F0C70
 * packet: pkt_ov029_021F0C70
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F2BB8 0x021F2BB8 thumb ov029
 *   d_021F32B3 0x021F32B3 data a1
 */
extern int func_021F2BB8(void *, int, int);
extern const unsigned char d_021F32B3[][9];
int func_021F0C70(void *p, int i, int j, int k)
{
    if (func_021F2BB8(p, j, k)) return d_021F32B3[i][4];
    return d_021F32B3[i][j];
}
