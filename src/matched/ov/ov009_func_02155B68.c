/*
 * function: func_02155B68
 * address: 0x02155B68
 * packet: pkt_ov009_02155B68
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021A8264 0x021A8264 data ov009 a4
 *   func_02155B00 0x02155B00 thumb ov009
 */
typedef unsigned char u8;
extern u8 *d_021A8264;
extern int func_02155B00(int, int);
void func_02155B68(void)
{
    int value;
    if (d_021A8264[0x7A7]) {
        value = 0;
        if (func_02155B00((int)&value, 4))
            d_021A8264[0x7A7] = 0;
    }
}
