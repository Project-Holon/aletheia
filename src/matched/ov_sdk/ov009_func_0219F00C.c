/*
 * function: func_0219F00C
 * address:  0x0219F00C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the two block helpers sixty bytes apart.
 *
 * symbols:
 *   func_0219EFF0  0x0219EFF0  arm  ov009
 *   func_0219F830  0x0219F830  arm  ov009
 */

extern void func_0219EFF0(char *p);
struct SBL;
extern void func_0219F830(struct SBL *slist);

void func_0219F00C(char *p)
{
    func_0219EFF0(p);
    func_0219F830((struct SBL *)(p + 0x60));
}

