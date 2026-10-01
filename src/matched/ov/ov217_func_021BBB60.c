/*
 * function: func_021BBB60
 * address: 0x021BBB60
 * packet: pkt_ov217_021BBB60
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BC40C receives original visible r0=context even though its body uses only globals; preserve that input.
 * symbols:
 *   func_021BC41C 0x021BC41C thumb ov217
 *   func_021BC40C 0x021BC40C thumb ov217
 *   func_021BC3D4 0x021BC3D4 thumb ov217
 *   func_021BC3E0 0x021BC3E0 thumb ov217
 *   func_021BC2CC 0x021BC2CC thumb ov217
 */
typedef unsigned char u8;
extern unsigned func_021BC41C(void);
extern int func_021BC40C(u8 *);
extern unsigned func_021BC3D4(void);
extern unsigned func_021BC3E0(void);
extern void func_021BC2CC(void *, unsigned, unsigned, unsigned);
void func_021BBB60(u8 *p)
{
    int start, end, step, low, high, low2, high2;
    start = *(int *)(p + 0x34);
    end = start;
    if ((int)func_021BC41C() < start) end = func_021BC40C(p) + 24;
    else if (start < 0) end = 144;
    low = func_021BC3D4();
    high = func_021BC3E0();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 3;
    low2 = func_021BC3D4();
    high2 = func_021BC3E0();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 1;
    func_021BC2CC(p, start, end, step);
}
