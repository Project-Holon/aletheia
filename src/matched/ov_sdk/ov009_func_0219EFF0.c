/*
 * function: func_0219EFF0
 * address:  0x0219EFF0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Prepares the block 0x60 bytes in and then the object itself.
 *
 * symbols:
 *   func_021A02E0  0x021A02E0  arm  ov009
 *   func_0219D8E0  0x0219D8E0  arm  ov009
 */

struct SBL;
extern void func_021A02E0(struct SBL *slist);
extern void func_0219D8E0(char *p);

void func_0219EFF0(char *p)
{
    func_021A02E0((struct SBL *)(p + 0x60));
    func_0219D8E0(p);
}

