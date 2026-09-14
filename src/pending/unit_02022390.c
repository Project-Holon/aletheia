/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x02022390..0x020223C0, two functions in pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 * function: func_02022390, func_020223AC
 *
 * func_020223AC reads an index out of its argument and calls
 * table[index](arg) through a fixed table at 0x0209F538; func_02022390 is
 * its only in-image caller, calling it as func_020223AC(p2) and clearing a
 * flag on the *first* argument when the dispatch returns 1.  Keeping both
 * functions in one translation unit makes the call between them `local`
 * (no witness needed) and confirms the argument passing, but the table
 * base 0x0209F538 has no witness anywhere else in the image: the only other
 * occurrence of that bit pattern is *at* address 0x0209F538 itself, holding
 * the table's own first entry (a pointer to func_020226E0, confirmed by
 * disasm.py's own resolution), not a second pool word that loads it. The
 * `literal` class therefore has nothing to stand on, and there is no
 * second caller to give `label` one either.
 *
 * symbols:
 *   g_0209F538  0x0209F538  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02022390.c \
 *       --addr 0x02022390 --thumb
 *
 * The `matched` class does not reach this: the table is data, which that
 * class deliberately never covers.
 */

typedef unsigned int u32;
typedef u32 (*Fn)(void *p);

extern Fn g_0209F538[];

u32 func_020223AC(void *p);

struct A {
    u32 unk0;
};

void func_02022390(struct A *obj, void *p)
{
    if (obj->unk0 != 0) {
        if (func_020223AC(p) == 1) {
            obj->unk0 = 0;
        }
    }
}

u32 func_020223AC(void *p)
{
    u32 idx = *(u32 *)p;
    return g_0209F538[idx](p);
}
