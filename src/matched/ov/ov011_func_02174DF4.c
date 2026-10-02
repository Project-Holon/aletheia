/*
 * function: func_02174DF4
 * address: 0x02174DF4
 * packet: pkt_ov011_02174DF4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02173CB0 0x02173CB0 thumb ov011
 */
typedef unsigned char u8;
int func_02173CB0(int *a, int b);
void func_02174DF4(u8 *p)
{
    if (p[0x924] != 0) {
        if (func_02173CB0((int *)p, p[0x924]) == 1) {
            p[0x924] = 0;
        }
    }
}
