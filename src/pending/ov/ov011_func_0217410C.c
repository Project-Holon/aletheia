/*
 * function: func_0217410C
 * address:  0x0217410C
 * packet:   pkt_ov011_0217410C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * checks: older draft (docs/notes/pkt_ov011_0217410C.c.txt): 88 B off, 224 B (original 220 B).
 * recoup 2026-10-05 (lane Z5): the 4 extra bytes were a second movs r1,#1: in the original the
 * flag store (str r0,[sp]) and s[0x907] = 1 share one register holding 1 (ldr r1,offset; movs r0,#1;
 * str r0,[sp]; strb r0,[r4,r1]). Plain flag = 1 / s[0x907] = 1 in either order, chained forms, flag as
 * u32, flag read back through s, struct-typed s, u32 return for func_02026478: all 224 B, 87 to 88 off.
 * The six per-function pragmas: no change. Twin search: grep -l func_02176424|func_021763D8|func_02175E30
 * over src/matched/ov and src/pending/ov finds only the callees and ov018 callers, no twin.
 * Filed form: keep the call result in r and store r in both places (flag = r; s[0x907] = r). The
 * compiler then shares the call register and the size is right (220 B), 76 B off. The original has an
 * explicit movs r0,#1 there, so this is probably not the real source form. Residue: that one movs
 * (all later bytes shift by 2). Not a final answer.
 * Idioms checked: a-constant-stored-from-r0-before-its-base-is-loaded-is-the-return-value (not
 * applicable, void), a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it
 * (no change), the-block-constant-in-a-callee-saved-register-follows-the-order-of-the-stores (no change),
 * a-clamp-with-both-stores-in-each-arm... (stores already in the arm), a-store-stays-above-the-argument-
 * constant-only-when-the-call-result-is-stored (no change), two-long-lived-values-in-each-others-registers,
 * a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off (pragmas no change).
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_021763D8  0x021763D8  thumb  ov011
 *   func_02175E30  0x02175E30  thumb  ov011
 *   func_02176424  0x02176424  thumb  ov011
 *   func_02175D7C  0x02175D7C  thumb  ov011
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Rec {
    u32 pad0;
    u32 lo : 4;
};

extern void *func_02026478(void *);
extern u8 *func_020127B8(void *);
extern void *func_020399A8(void);
extern u32 func_0203D1A4(void *);
extern int func_02175DA8(u8 *);
extern void func_021763D8(u8 *, u32);
extern void func_02175E30(void *, u8 *, struct Rec *);
extern int func_02176424(u8 *, u8 *, u8 *);
extern void func_02175D7C(void *, u8 *, void *);

void func_0217410C(int a0, int a1, u8 *b, u8 *s)
{
    u8 *y;
    int flag;
    void *x;
    u8 buf[2];
    int r7;
    int r6;
    int r;

    x = func_02026478(*(void **)(s + 4));
    y = func_020127B8(x);
    buf[1] = 0;
    flag = 0;
    buf[0] = 0;
    r7 = 0;
    r6 = 0;
    if (b[0x2c] == 4) {
        return;
    }
    if (func_02175DA8(s + 0x1ac) == 1) {
        return;
    }
    if (b[0x28] == func_0203D1A4(func_020399A8())) {
        if (b[0x37] == 1) {
            func_021763D8(y, ((struct Rec *)b)->lo);
        } else {
            func_02175E30(x, s, (struct Rec *)b);
        }
        s[0x907] = 1;
        r = func_02176424(y, &buf[1], &buf[0]);
        if (r == 1) {
            flag = r;
            s[0x907] = r;
        }
        if (b[0x2e] == 1) {
            r6 = 1;
        } else {
            r7 = 1;
        }
        if (flag == 1) {
            r6 += buf[0];
            r7 += buf[1];
        }
        s[0x354] = r7;
        s[0x355] = r6;
        s[0x356] = 1;
        s[0x93e] = 1;
    }
    func_02175D7C(s, s + 0x1ac, b);
}
