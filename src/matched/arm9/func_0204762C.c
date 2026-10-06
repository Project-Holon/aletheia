/*
 * function: func_0204762C
 * address:  0x0204762C
 * packet:   pkt_02047564
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A5C      0x02146A5C  data
 *   func_0206E388   0x0206E388  arm
 *   func_020307B0   0x020307B0  arm
 *
 * The sibling of func_02047504 for the other record tag: 0x59D1 instead of
 * 0x7A14 and func_0206E388 instead of func_0206E358.  Everything else,
 * including the register allocation and the reuse of the pooled tag for the
 * decrement, is identical.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204762C.c \
 *       --func func_0204762C --addr 0x0204762C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 tag;
    u16 unk_02;
    u32 unk_04;
};

extern u32 g_02146A5C;
extern void func_0206E388(u32 ctx, u32 field);
extern u32 func_020307B0(void *p);

void func_0204762C(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x59D1)
        return;

    func_0206E388(g_02146A5C, p->unk_04);
    p->tag = 0x59D1 - 1;
    func_020307B0(p);
}
