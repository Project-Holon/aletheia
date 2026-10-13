/*
 * function: GAMESYSTEM_CallProc
 * address:  0x020120B4
 * packet:   pkt_020120B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PROCSYS_Push  0x02031348  arm
 *
 * ica_anime.c.  Forwards the +0x08 handle and the caller's other three
 * arguments to the ARM routine at 0x02031348.  The frame
 * (push {r3,lr} / blx / pop {r3,pc}) where every one-argument spelling gets
 * a pool-word-and-bx sibling call (26 spellings in
 * docs/notes/pkt_020120B4.c.txt) is the tail-call-cannot-pass-a-fourth-
 * argument idiom: r1-r3 are passed through untouched, so they cost no
 * instruction, and r3 being live blocks the sibling call.  The arity is
 * independently evidenced by the only caller, GAMESYSTEM_CallFieldProc, which sets up
 * r1, r2 and r3 (r3 = r0) before the bl.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAMESYSTEM_CallProc.c \
 *       --func GAMESYSTEM_CallProc --addr 0x020120B4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct IcaAnime {
    u8    pad00[0x08];
    void *f8;           /* +0x08 */
};

extern void PROCSYS_Push(void *h, u32 id, void *a, void *b);

void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b)
{
    PROCSYS_Push(p->f8, id, a, b);
}
