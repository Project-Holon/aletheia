/*
 * function: func_021BBBE4
 * address: 0x021BBBE4
 * packet: pkt_ov217_021BBBE4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: non-strict min/max ternaries retain the original ble/bge branches.
 * symbols:
 *   func_021BC3D4 0x021BC3D4 thumb ov217
 *   func_021BC3E0 0x021BC3E0 thumb ov217
 *   func_021BBF1C 0x021BBF1C thumb ov217
 *   func_021BC2CC 0x021BC2CC thumb ov217
 */
typedef unsigned char u8;
extern unsigned func_021BC3D4(void);
extern unsigned func_021BC3E0(void);
extern unsigned func_021BBF1C(unsigned, unsigned);
extern void func_021BC2CC(void *, unsigned, unsigned, unsigned);
void func_021BBBE4(u8 *p)
{
    int center, target, start, end;
    center = (int)(func_021BC3D4() + func_021BC3E0()) / 2;
    target = func_021BBF1C((unsigned)p, p[0x32]) * 8;
    if (center < target) {
        start = func_021BC3E0();
        end = (target - center) + func_021BC3E0();
    } else {
        start = func_021BC3D4();
        end = func_021BC3D4() - (center - target);
    }
    func_021BC2CC(p, start, end, ((start >= end ? start : end) - (start <= end ? start : end)) / 3);
}
