/*
 * function: func_021BBADC
 * address: 0x021BBADC
 * packet: pkt_ov217_021BBADC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BBB5E..021BBB60 is two zero bytes of alignment padding.
 * arity: BC400 forwards entry r0 to BC3F8 despite its legacy void parameter list; retain the visible byte argument.
 * symbols:
 *   func_021BC400 0x021BC400 thumb ov217
 *   func_021BC3F8 0x021BC3F8 thumb ov217
 *   func_021BC3D4 0x021BC3D4 thumb ov217
 *   func_021BC3E0 0x021BC3E0 thumb ov217
 *   func_021BC2CC 0x021BC2CC thumb ov217
 */
typedef unsigned char u8;
extern unsigned func_021BC400(unsigned);
extern unsigned func_021BC3F8(unsigned);
extern unsigned func_021BC3D4(void);
extern unsigned func_021BC3E0(void);
extern void func_021BC2CC(void *, unsigned, unsigned, unsigned);
void func_021BBADC(u8 *p)
{
    int start, end, low, high, step, low2, high2;
    start = *(int *)(p + 0x34);
    if (p[0x32] < p[0x33]) end = func_021BC400(p[0x33]) + 1;
    else end = func_021BC3F8(p[0x33]);
    low = func_021BC3D4();
    high = func_021BC3E0();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 4;
    low2 = func_021BC3D4();
    high2 = func_021BC3E0();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 0;
    func_021BC2CC(p, start, end, step);
}
