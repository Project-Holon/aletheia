/*
 * function: func_021BC5F0
 * address:  0x021BC5F0
 * packet:   pkt_ov223_021BC5F0
 * region:   ov223
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Closed by the recursive MATCH unblocker (0x021A0000..0x021BFFFF): the +003C
 * ABS32 0x021BC944 is data in this function's own overlay (ov223, a .word-run
 * start) and the ROM word at the site 0x021BC62C already names it, so
 * `sole-ref/self` is the right class.  It only failed because the `ov223`
 * token on the symbols line made the hint contested (ov088 also starts a
 * func_021BC944 there) and this function loads no overlay id, so
 * self_hint_accepted() refused.  Dropping the token lets the function's own
 * region pick ov223 and the site resolves `sole-ref` with no outside evidence.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_021BC944     0x021BC944  data  a4
 */

extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(void *, int, int);
extern int func_0204B100(int, int, int);
typedef unsigned int   u32;
struct Bank;
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern int d_021BC944;

void func_021BC5F0(int *out, int a, int b)
{
    func_02082BCC(out, 0, 4);
    func_0204A48C(&d_021BC944, a, b);
    *out = func_0204B100(0x80, 0, b);
    func_0204B270((void *)*out);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
