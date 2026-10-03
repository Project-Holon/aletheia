/*
 * function: func_0204C83C
 * address:  0x0204C83C
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_0204C804  0x0204C804  arm
 *   func_0204C8A4  0x0204C8A4  arm
 *
 * The per-record callback src/matched/func_0204C660.c hands to func_02066934,
 * which is why its address only ever appears as a pool word and never as a
 * branch target.
 *
 * The selector local really is uninitialised on the path where the first
 * argument is neither 0x13 nor 0x23: r4 is written only inside the two
 * predicated arms and is read again at the call below, with no `mov r4, ...`
 * on the fall-through.  Giving it a default value in the C adds that `mov`
 * and four bytes, so the original's C had an `if`/`else if` with no `else`.
 *
 * The handle passed to func_0204C8A4 is func_0204C804's return value left in
 * r0, not a reload; the selector chain in between touches only r4 and the
 * flags.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C83C.c \
 *       --func func_0204C83C --addr 0x0204C83C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u8 pad_00[4];
};

struct Sys {
    u8         pad_000[0xe0];
    struct Sub unk_0e0;   /* 0xe0 */
};

extern struct Sys *g_02146A74;

extern void *func_0204C804(struct Sub *s);
struct Entry;
extern void func_0204C8A4(struct Entry *e, u32 sel, u32 a, u32 b, u32 c);

u32 func_0204C83C(u32 kind, u32 a, u32 b, u32 c)
{
    void *h;
    u32   sel;

    h = func_0204C804(&g_02146A74->unk_0e0);

    if (kind == 0x13) {
        sel = 0;
    } else if (kind == 0x23) {
        sel = 1;
    }

    if (c != 0) {
        func_0204C8A4(h, sel, a, b, c);
    }

    return 1;
}
