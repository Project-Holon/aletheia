/*
 * function: func_021E2B48
 * address:  0x021E2B48
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF57C  0x021EF57C  thumb  ov170
 *   func_021ED6E4  0x021ED6E4  thumb  ov170
 *   func_021EBA5C  0x021EBA5C  thumb  ov170
 *   func_021DD14C  0x021DD14C  thumb  ov170
 *   func_021EF670  0x021EF670  thumb  ov170
 *   func_021EF68C  0x021EF68C  thumb  ov170
 *   func_021E8FE0  0x021E8FE0  thumb  ov170
 *   func_021E8FC0  0x021E8FC0  thumb  ov170
 *
 * Re-key the p+0x2c+0x74 object, clear the frame, retag 0x18,
 *   forward the status bytes, refresh, then store state 0x11 with the
 *   0x021E070D thumb pointer as the selector.  Six-member wrapper family
 *   (see func_021E3BF8 / func_021E498C / func_021E4E6C / func_021E62BC /
 *   func_021E7258): only the mid call, the selector and the state differ.
 */


extern void func_021EF57C(int);
extern void func_021ED6E4(char *, int);
extern void func_021EBA5C(int, int);
extern void func_021DD14C(char *);
extern void func_021EF670(int);
extern void func_021EF68C(int);
extern int func_021E8FE0(char *, int);
extern void func_021E8FC0(char *, int, int);
void func_021E2B48(char *p)
{
    func_021EF57C(*(int *)(*(int *)(p + 0x2c) + 0x74));
    func_021ED6E4(p, 0);
    func_021EBA5C(*(int *)(p + 0x2c), 0x18);
    func_021DD14C(p);
    func_021EF670(*(int *)(p + 0x2c));
    func_021E8FC0(p, 0x21E070D, func_021E8FE0(p, 0x11));
}
