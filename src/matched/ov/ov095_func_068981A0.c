/*
 * function: func_068981A0
 * address: 0x068981A0
 * packet: pkt_ov095_068981A0
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_068981B4 0x068981B4 thumb ov095
 *   func_068981C4 0x068981C4 thumb ov095
 */
extern int func_068981B4(int);
extern void func_068981C4(int, int);
void func_068981A0(void)
{
    int value;
    value = func_068981B4(61);
    func_068981C4(61, value + 1);
}
