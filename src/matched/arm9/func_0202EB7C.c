/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: COMM_HISTORY_InsertIfLanguageSet
 * address:  0x0202EB7C
 * packet:   pkt_0202EB7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * All 30 concrete bytes are right; the call to COMM_HISTORY_InsertOrReplace is the only open
 * site and it is blocked on `label`: the sole branch to 0x0202EB9C image-wide
 * is the one inside this function, so there is no witness outside the
 * compared range and no cut helps (the range cannot be smaller than the one
 * function holding the call).  It closes when COMM_HISTORY_InsertOrReplace itself gets a
 * manifest entry or a second caller appears.
 *
 * The trailing `*` is the unlabelled follower at 0x0202EB9C: the listing's
 * extent runs 32 bytes against 30 compiled because the follower carries no
 * `func_` label in the generated listing (disasm.py only labels a prologue
 * that saves lr, and this one's first instruction is not visible from here).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/COMM_HISTORY_InsertIfLanguageSet.c \
 *       --func COMM_HISTORY_InsertIfLanguageSet --addr 0x0202EB7C --cc 1.1p1 --thumb
 *
 * symbols:
 *   COMM_HISTORY_InsertOrReplace  0x0202EB9C  thumb
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u32 COMM_HISTORY_InsertOrReplace(u32 a, void *b);

u32 COMM_HISTORY_InsertIfLanguageSet(u32 a0, u32 a1)
{
    if (func_0200856C((const struct Sub0200852CObj *)a1) == 0) {
        return 0;
    }
    return COMM_HISTORY_InsertOrReplace(a0, (void *)a1);
}
