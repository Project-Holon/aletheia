/*
 * function: func_021D7BDC
 * address: 0x021D7BDC
 * packet: pkt_ov123_021D7BDC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7B68 0x021D7B68 thumb ov123
 *   func_021D746C 0x021D746C thumb ov123
 */
typedef unsigned char u8;
extern void func_021D6EE0(char *, int, int);
extern void func_021D7B68(char *p);
extern void func_021D746C(int a);
void func_021D7BDC(char *p)
{
    if (*(u8 *)(p + 0xa5)) {
        p[0xa7] = 0;
        func_021D6EE0(p, (int)func_021D7B68, 0x465);
        return;
    }
    if (*(u8 *)(p + 0xa4)) {
        p[0xa7] = 1;
        func_021D6EE0(p, (int)func_021D7B68, 0x46a);
        return;
    }
    if (*(u8 *)(p + 0xa6)) {
        p[0xa7] = 2;
        func_021D6EE0(p, (int)func_021D7B68, 0x46f);
        return;
    }
    func_021D6EE0(p, (int)func_021D746C, 0x472);
}
