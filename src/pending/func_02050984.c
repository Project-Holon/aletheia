/*
 * function: func_02050984
 * address:  0x02050984
 * packet:   pkt_02050984
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH*
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 *
 * PARKED AT MATCH.  Every one of the 92 compiled bytes is right - the
 * four-way `switch` head, all four case arms and the zero-returning default -
 * but three of its four ABS32 pool words have no witness, so those sites stay
 * wildcarded:
 *   blocker: label; ABS32 to 0x02050A58, 0x02050A00 and 0x020509E0 each have
 *            exactly one mention image wide and it is the pool word inside
 *            this very function (0x020509E0 is even inside this listing
 *            extent), so neither `label`, `literal` nor `matched` reaches
 *            them.  Only the fourth word, 0x020509E8, resolves (`matched`).
 *
 * The switch normalises the id with two subtracts and no `mov` of the base,
 * which is the whole reason the case labels read 0x3FFC..0x3FFF: the image
 * subtracts 0x3FC and then 0x3C00, i.e. 0x3FFC, and spelling the cases
 * 0x43FC..0x43FF makes the second subtract `#0x4000` and the four case arms
 * come out in the wrong order.  Writing the cases in DESCENDING source order
 * is what reproduces the image's arm order (case 0x3FFF's arm nearest the
 * table); ascending order puts case 0x3FFC's arm there and differs in four
 * branch instructions.
 *
 * `return <function address>;` is the shape: each arm is `ldr r0, [pc, #n];
 * bx lr` and the fall-through is `mov r0, #0; bx lr`.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   func_02050A58  0x02050A58  arm
 *   func_02050A00  0x02050A00  arm
 *   func_020509E8  0x020509E8  arm
 *   func_020509E0  0x020509E0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02050984.c \
 *       --func func_02050984 --addr 0x02050984 --cc 1.1p1 --arm
 */

typedef void (*Fn)(void);
typedef unsigned int u32;

extern void func_02050A58(void);
extern void func_02050A00(void);
extern void func_020509E8(void);
extern void func_020509E0(void);

Fn func_02050984(u32 id)
{
    switch (id) {
    case 0x3FFF: return func_020509E0;
    case 0x3FFE: return func_020509E8;
    case 0x3FFD: return func_02050A00;
    case 0x3FFC: return func_02050A58;
    }
    return 0;
}
