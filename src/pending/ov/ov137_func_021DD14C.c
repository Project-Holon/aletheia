/*
 * function: func_021DD14C
 * address: 0x021DD14C
 * packet: pkt_ov137_021DD14C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * symbols:
 * func_0207E51C 0x0207E51C arm
 * d_021E1AEE 0x021E1AEE data a1
 * d_021E1AEF 0x021E1AEF data a1
 *
 * note 2026-10-05 (wave P20 lane 2): DIFF 5/88 bytes. The older draft in
 * docs/notes/pkt_ov137_021DD14C.c.txt (56 B) had the wrong table logic. The listing
 * reads TWO pool words: d_021E1AEE[i*2] (count) and d_021E1AEF[i*2] (frame, tested
 * against 0xff and shifted by 5), as two separate u8 externs. With that, everything
 * matches except one colour swap: the original has index r4 (shift temp r3) and
 * counter r5; this draft gives index r5 and counter r4 (the form without an index
 * local gives index r3, shift r4, counter r5).
 * Tried (no change or other swap): unsigned long / int i, counter local c before or after
 * i, c read before i, declaration order of v and i, v->index++, i++ then store, Pair
 * struct tables, pointer-form tables, six pragmas (lifetimes, propagation, common_subs,
 * dead_assignments, scheduling, peephole) on the i form. Callee func_0207E51C takes
 * three words (matched callers agree). No no-op cast closes it.
 *
 * recoup 2026-10-05 P29R8: still DIFF 5/88 (same index/counter colour swap). New tries, all
 * 5 B unless noted: counter in a local c read after i; counter compare as table < counter
 * (7 B); int index type; braces on the 255 test; first compare reading v->index directly;
 * i = i + 1 then store and test through i; v declared after i; c local with table < c (7 B);
 * struct-typed parameter with nested State (72 B); non-const tables (17 B); table through a
 * u8 * local (15 B); early-return form with the else first (56 B); else via v->counter += 1
 * (21 B, original uses the p base r1 so the raw p+32 access is right). Note: p+32 is the
 * same word as v->counter.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct State { u32 enable; u32 index; int counter; u32 spare; u8 *object; };
extern const u8 d_021E1AEE[];
extern const u8 d_021E1AEF[];
extern void func_0207E51C(void *, int, int);
void func_021DD14C(int unused, u8 *p)
{
    struct State *v = (struct State *)(p + 24);
    u32 i;
    if (v->enable) {
        i = v->index;
        if (v->counter > d_021E1AEE[i * 2]) {
            v->index = i + 1;
            v->counter = 0;
            if (d_021E1AEF[v->index * 2] == 255) v->index = 0;
            func_0207E51C(*(u8 **)(v->object + 12) + (d_021E1AEF[v->index * 2] << 5), 0, 32);
            return;
        }
        *(u32 *)(p + 32) += 1;
    }
}
