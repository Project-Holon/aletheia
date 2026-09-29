/*
 * function: func_021C8268
 * address:  0x021C8268
 * packet:   pkt_ov021_021C8268
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02014204  0x02014204  thumb
 *   func_021C82C4  0x021C82C4  thumb  ov021
 */

extern int func_020122C0(int a, int b, void *c, int d);
extern int *func_020124E8(int a);
extern void func_02082BCC(void *p, int v, int n);
extern void func_020120F4(int a);
extern void func_02012944();
extern int func_02008550();
extern void func_02014204(void *p, int v);
extern void func_021C82C4();

int func_021C8268(int a, int b, int c)
{
    int r7;
    int *r4;
    int v;

    r7 = func_020122C0(a, 0, func_021C82C4, 0x30);
    r4 = func_020124E8(r7);
    func_02082BCC(r4, 0, 0x30);
    r4[0] = a;
    r4[2] = c;
    func_020120F4(a);
    func_02012944();
    if (func_02008550() == 0) {
        r4[10] = 11;
        v = 12;
    } else {
        r4[10] = 18;
        v = 19;
    }
    r4[11] = v;
    func_02014204(r4 + 3, (unsigned short)c);
    return r7;
}
