/*
 * unit:     yes
 * address:  0x02018430
 * packet:   pkt_02017FB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02018430, func_02018438
 *
 * The record's level accessor: it unlocks the block area, reads ids 5, 0x6F
 * and 8 out of it (species, form and experience), locks it again and hands the
 * three to func_0201850C (src/matched/unit_0201850C.c), which is the same
 * computation id 0x9E of func_02018E34 performs directly on the substructs.
 * func_02018430 in front of it is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk with no prologue, and
 * its pool word is `local` because its target is the next function in the same
 * unit.
 *
 * The three values are held in word locals and truncated at the call, not at
 * the assignment: the two `lsls #0x10` / `lsrs #0x10` pairs sit immediately in
 * front of the `bl`, after the lock call, which is what fixes func_0201850C's
 * first two parameters as u16 and func_02017E88's return as a word.  The same
 * shape appears in src/matched/unit_02017E64.c and src/pending/unit_0201854C.c.
 *
 * The range stops at 0x02018480, where another eight byte thunk forwards to
 * func_02018488; that thunk's pool word is the only reference to func_02018488
 * in the image, and func_02018488 in turn is the only caller of 0x020084F8, so
 * neither can be attested and both are left out.
 *
 * Nothing here is version specific: 5, 0x6F and 8 are field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02018430.c \
 *       --addr 0x02018430 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02017DBC(void *p);
extern u32 func_02017DE4(void *p, u32 f);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_0201850C(u16 species, u16 form, u32 exp);

u32 func_02018438(void *p);

u32 func_02018430(void *p)
{
    return func_02018438(p);
}

u32 func_02018438(void *p)
{
    u32 t = func_02017DBC(p);
    u32 species = func_02017E88(p, 5, 0);
    u32 form = func_02017E88(p, 0x6F, 0);
    u32 exp = func_02017E88(p, 8, 0);

    func_02017DE4(p, t);
    return func_0201850C((u16)species, (u16)form, exp);
}
