/*
 * function: func_021EBDD8
 * address:  0x021EBDD8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE200  0x021EE200  thumb  ov170
 *   func_021EBF50  0x021EBF50  thumb  ov170
 *   func_021EBE4C  0x021EBE4C  thumb  ov170
 *
 * Three teardown steps then the SDK pool release.
 */


extern void func_021EE200(char *);
extern void func_021EBF50(char *);
extern void func_021EBE4C(char *);
extern void func_0204A5AC(void);
void func_021EBDD8(char *p)
{
    func_021EE200(p);
    func_021EBF50(p);
    func_021EBE4C(p);
    func_0204A5AC();
}
