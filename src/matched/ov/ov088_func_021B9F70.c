/*
 * function: func_021B9F70
 * address:  0x021B9F70
 * packet:   pkt_ov088_021B9F70
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (36) runs 2 bytes past the compiled function (34);
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 */

extern void func_0204A8D4(int);
extern void func_0204ADA4(int);
extern void func_0204AFD8(int);
extern void func_0204B1CC(int);
extern void func_0204A5AC(void);

void func_021B9F70(int *p)
{
    func_0204A8D4(p[12]);
    func_0204ADA4(p[11]);
    func_0204AFD8(p[13]);
    func_0204B1CC(p[0]);
    func_0204A5AC();
}
