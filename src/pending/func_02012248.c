/*
 * function: func_02012248
 * address:  0x02012248
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * symbols:
 *   func_02012220     0x02012220  thumb
 *   func_02035138     0x02035138  thumb
 *
 * A tail call (pool word plus `bx r3`, so the callee is an extern at its own
 * address): the incoming argument moves to r1 and the address of
 * func_02012220 goes to r0, i.e. `func_02035138(func_02012220, arg)`.
 * func_02012248 is registered as a callback with the same signature as its
 * neighbour, which is what the pool word 0x02012221 (the Thumb bit) shows.
 *
 * blocker:  label, two sites, and structurally hopeless for a cut: both
 *           pool words are reached by `bx r3` rather than by a branch, so
 *           0x02012220 and 0x02035138 have no branch witness anywhere in the
 *           image (every caller of both goes through its own pool word).  No
 *           cut can help - the pool words are this function's own - and no
 *           EXACT entry covers either address.  Byte-correct.
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02012248.c \
 *       --func func_02012248 --addr 0x02012248 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct IcaAnime;

extern void func_02012220(struct IcaAnime *p);
extern void func_02035138(void *fn, u32 arg);

void func_02012248(struct IcaAnime *p)
{
    func_02035138((void *)func_02012220, (u32)p);
}
