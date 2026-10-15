/*
 * function: GTSNEGO_MSG_GetListRowY
 * address: 0x021D72C8
 * packet: pkt_ov120_021D72C8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
extern int _s32_div_f(int, int);
int GTSNEGO_MSG_GetListRowY(u8 *p, int index, int count)
{
    if (index == 0) return 0;
    count = (int)((u32)count - 1);
    if (index == count) return 132;
    return _s32_div_f((int)((u32)index * 132), count);
}
