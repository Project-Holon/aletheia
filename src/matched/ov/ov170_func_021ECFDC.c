/*
 * function: func_021ECFDC
 * address: 0x021ECFDC
 * packet: pkt_ov170_021ECFDC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EC08C 0x021EC08C thumb ov170
 */
extern void func_021EC000(char *, int, int);
extern void func_021EC08C(char *p, int i, unsigned short a, unsigned short b, unsigned short c);
void func_021ECFDC(char *p, int a, int b)
{
    int k = a + 0x1c;
    func_021EC000(p, k, 1);
    func_021EC08C(p, k, 0x58, 0x38, 1);
    if (b != 0 && a != b) {
        k = b + 0x1c;
        func_021EC000(p, k, 1);
        func_021EC08C(p, k, 0x7a, 0x38, 1);
    }
}
