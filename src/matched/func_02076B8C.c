/*
 * function: func_02076B8C
 * address:  0x02076B8C
 * packet:   pkt_02076B8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02076070  0x02076070  arm
 *
 * Eight bytes of code and its own pool word: a bare tail call, the shortest
 * shape this front end emits for `void f(void) { g(); }`.  Its one
 * relocation is the pool word naming func_02076070, which has no outside
 * label, so the file only reaches EXACT once func_02076070 itself is in a
 * shard (bottom-up: it was filed as src/matched/func_02076070.c first, and
 * the site then resolves through the `matched` class).
 */

typedef unsigned int u32;

extern u32 func_02076070(void);

void func_02076B8C(void)
{
    func_02076070();
}
