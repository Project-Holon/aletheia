/*
 * function: func_021BD398
 * address: 0x021BD398
 * packet: pkt_ov209_021BD398
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_021BD5D4 0x021BD5D4 thumb ov209
 *   d_021BE990 0x021BE990 data a1
 */
typedef unsigned char u8;
extern void func_02045088(unsigned short);
extern unsigned func_020450F0(unsigned, unsigned, unsigned, unsigned, u8, u8, u8);
extern void func_021BD5D4(char *);
extern const u8 d_021BE990[][6];
void func_021BD398(char *p)
{
    unsigned i;
    func_02045088(107);
    for (i = 0; i < 3; i++)
        *(unsigned *)(p + i * 8 + 32) = func_020450F0(d_021BE990[i][0], d_021BE990[i][1], d_021BE990[i][2], d_021BE990[i][3], d_021BE990[i][4], d_021BE990[i][5], 1);
    func_021BD5D4(p);
}
