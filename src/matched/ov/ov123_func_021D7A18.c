/*
 * function: func_021D7A18
 * address: 0x021D7A18
 * packet: pkt_ov123_021D7A18
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5CF8 0x021D5CF8 thumb ov123
 *   func_021D79A4 0x021D79A4 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 */
extern int func_021D5CF8(int);
extern void func_021D79A4(void);
extern void func_021D6FF0(void);
extern void func_021D6EE0(int, int, int);
void func_021D7A18(int a)
{
    if (func_021D5CF8(*(int *)(a + 8))) {
        func_021D6EE0(a, (int)func_021D79A4, 0x415);
        return;
    }
    *(int *)(a + 0x80) = 0xfff0;
    func_021D6EE0(a, (int)func_021D6FF0, 0x419);
}
