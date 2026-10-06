/*
 * function: func_0204A648
 * address:  0x0204A648
 * packet:   pkt_0204A600
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74    0x02146A74  data
 *   func_0204BB04 0x0204BB04  arm
 *   func_0204BB20 0x0204BB20  arm
 *   func_0204BCF4 0x0204BCF4  arm
 *   func_0204C7A4 0x0204C7A4  arm
 *
 * The cell-actor manager's teardown pass, and the exact inverse of
 * src/pending/sub_0204A600.c: each guard re-reads the context pointer from
 * its slot (the two `popeq` exits are the short-circuit returns, which is why
 * neither guard is predicated), the +0xEC latch decides whether the +0xE0
 * sub-object is released, and the flag goes back to 1.
 *
 * The 0x0204BCF4 call site resolves off the `label` class (its own
 * src/pending/func_0204BCF4.c is capped, but the branch has witnesses outside
 * this range), so this file is EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204A648.c \
 *       --func func_0204A648 --addr 0x0204A648 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sys {
    u8  pad_000[0xec];
    u32 unk_0ec;
};

extern struct Sys *g_02146A74;

extern u32  func_0204BB04(void);
extern void func_0204BB20(u32 v);
struct Obj;
struct Table;
extern void func_0204BCF4(struct Obj *o);
extern void func_0204C7A4(struct Table *t);

void func_0204A648(void)
{
    if (g_02146A74 == 0)
        return;
    if (func_0204BB04() == 0)
        return;

    func_0204BCF4((struct Obj *)g_02146A74);

    if (g_02146A74->unk_0ec != 0)
        func_0204C7A4((struct Table *)((char *)g_02146A74 + 0xe0));

    func_0204BB20(1);
}
