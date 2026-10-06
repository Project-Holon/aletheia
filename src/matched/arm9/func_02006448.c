/*
 * function: func_02006448
 * address:  0x02006448
 * packet:   pkt_020063B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * promoted: from src/pending 2026-09-19, no C change: blocker 0x02074A98 is filed in layout/matched/arm9/pkt_02074A6C.json and every site resolves (gate: manifest --verify --shard layout/matched/arm9/pkt_020063B4.json, then 0 rewritten).
 * blocker (RESOLVED 2026-09-19):  02074A98 - reached from the identical `blx` in
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
#include "../include/Obj11220.h"

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

extern void *func_02074324(int index);
extern void *func_020743EC(int index);
extern void   sub_0200597C(void);
extern u32 func_02074A98(u32 a, u32 b);
extern void   func_02074694(u32 a, u32 b);
extern int sub_020059A0(u32 a);

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
    half = ((struct Obj11220 *)hdr)->f4;
    q = func_020743EC(half);
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
