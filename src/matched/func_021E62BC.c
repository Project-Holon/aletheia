/*
 * function: func_021E62BC
 * address:  0x021E62BC
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
 * Wrapper family member: func_021EF670, state 0x39 and
 *   0x021E0E51 as the selector.
 */


extern void func_021EF57C(int);
extern void func_021ED6E4(char *, int);
extern void func_021EBA5C(int, int);
extern void func_021DD14C(char *);
extern void func_021EF670(int);
extern void func_021EF68C(int);
extern int func_021E8FE0(char *, int);
extern void func_021E8FC0(char *, int, int);
void func_021E62BC(char *p)
{
    func_021EF57C(*(int *)(*(int *)(p + 0x2c) + 0x74));
    func_021ED6E4(p, 0);
    func_021EBA5C(*(int *)(p + 0x2c), 0x18);
    func_021DD14C(p);
    func_021EF670(*(int *)(p + 0x2c));
    func_021E8FC0(p, 0x21E0E51, func_021E8FE0(p, 0x39));
}
