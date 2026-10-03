/*
 * function: func_021BAD58
 * address:  0x021BAD58
 * packet:   pkt_ov213_021BAD58
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Closed by the recursive MATCH unblocker (0x021A0000..0x021BFFFF): the +003C
 * ABS32 0x021BB18C is data in this function's own overlay (ov213, a .word-run
 * start) and the ROM word at the site 0x021BAD94 already names it, so
 * `sole-ref/self` is the right class.  It only failed because the `ov213`
 * token on the symbols line made the hint contested (ov223 also starts a
 * func_021BB18C there) and this function loads no overlay id, so
 * self_hint_accepted() refused.  Dropping the token lets the function's own
 * region pick ov213 and the site resolves `sole-ref` with no outside evidence.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   d_021BB18C     0x021BB18C  data  a4
 */

extern void func_02082BCC(void *, int, int);
extern void func_0204A48C(void *, int, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern int d_021BB18C;

void func_021BAD58(void **out, int a, int b)
{
    func_02082BCC(out, 0, 4);
    func_0204A48C(&d_021BB18C, a, b);
    *out = func_0204B100(0x80, 0, b);
    func_0204B270(*out);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}