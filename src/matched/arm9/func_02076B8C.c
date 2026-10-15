/*
 * function: CARD_TryWaitBackupAsync
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
 *   CARDi_TryWaitAsync  0x02076070  arm
 *
 * Eight bytes of code and its own pool word: a bare tail call, the shortest
 * shape this front end emits for `void f(void) { g(); }`.  Its one
 * relocation is the pool word naming CARDi_TryWaitAsync, which has no outside
 * label, so the file only reaches EXACT once CARDi_TryWaitAsync itself is in a
 * shard (bottom-up: it was filed as src/matched/CARDi_TryWaitAsync.c first, and
 * the site then resolves through the `matched` class).
 */

typedef unsigned int u32;

extern int CARDi_TryWaitAsync(void);

u32 CARD_TryWaitBackupAsync(void)
{
    return CARDi_TryWaitAsync();
}
