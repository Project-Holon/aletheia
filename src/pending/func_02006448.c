/*
 * function: func_02006448
 * address:  0x02006448
 * packet:   pkt_020063B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02074A98 - reached from the identical `blx` in
 *           src/matched/func_02006448.c's loop only, so `label` has no
 *           witness outside the compared range and the callee is not
 *           matched.  All 102 concrete bytes and every other site are right.
 *
 * symbols:
 *   g_020AA260     0x020AA260  data
 *   func_02074324  0x02074324  arm
 *   func_020743EC  0x020743EC  arm
 *   sub_0200597C   0x0200597C  thumb
 *   func_02074A98  0x02074A98  arm
 *   func_02074694  0x02074694  arm
 *   sub_020059A0   0x020059A0  thumb
 *
 * The four-voice "open with these handles" path: resolve the handle block,
 * split its header word and its halfword, and rebuild the table from it;
 * then check every one of the four 16-bit entries against 0xFFFF and bail
 * with 0 the first time a registration call fails (the loop counter is the
 * only thing the failure arm does not need, which is why the zero is
 * rematerialised rather than loaded from a local).
 *
 * The header word and the halfword at +4 are two separate loads before the
 * second call, and the *first* one goes to the stack slot the tail uses -
 * so the source read them in that order and passed them to func_020743EC
 * swapped (`func_020743EC(halfword, word)`).  The word at +0 of the returned
 * block is a full 32-bit load: it is the same field family as the four
 * halfwords at +4, but the first member is a `u32`, and spelling it as one
 * changes `ldrh` to `ldr` and nothing else.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02006448.c \
 *       --func func_02006448 --addr 0x02006448 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02006448Pair {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u16 unk08;
    u16 unk0A;
};

extern char g_020AA260[];

extern u32   *func_02074324(u32 a);
extern struct Sub02006448Pair *func_020743EC(u32 a, u32 b);
extern void   sub_0200597C(void);
extern int    func_02074A98(u32 a, u32 b);
extern void   func_02074694(u32 a, u32 b);
extern void   sub_020059A0(u32 a);

int func_02006448(u32 a0, u32 a1, u32 a2)
{
    u32 *hdr;
    struct Sub02006448Pair *q;
    u32 word;
    u16 half;
    u32 v;
    int i;

    hdr = func_02074324(a2);
    word = hdr[0];
    half = *(u16 *)((char *)hdr + 4);
    q = func_020743EC(half, word);
    v = q->unk00;
    sub_0200597C();
    for (i = 0; i < 4; i++) {
        if (*(u16 *)((char *)q + 4 + i * 2) != 0xFFFF) {
            if (func_02074A98(*(u16 *)((char *)q + 4 + i * 2),
                              *(u32 *)(g_020AA260 + 0x10)) == 0) {
                return 0;
            }
        }
    }
    func_02074694(v, a1);
    func_02074694(word, a0);
    sub_020059A0(a2);
    return 1;
}
