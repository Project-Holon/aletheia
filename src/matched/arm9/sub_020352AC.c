/*
 * function: sub_020352AC
 * address:  0x020352AC
 * packet:   pkt_02035224
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The disarming half of sub_02035284: run the +0x18 hook with the same
 * +0x2c argument and clear the armed flag, but only if the context was armed
 * in the first place.
 *
 * The two conditions are one `&&`, not a nested pair of `if`s: they share a
 * single `popeq` epilogue, which the chain-of-returns spelling would split
 * into two (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020352AC.c \n *       --func sub_020352AC --addr 0x020352AC --cc 1.1p1 --arm
 */

typedef unsigned char u8;

typedef void (*UiCb)(void *);
typedef int  (*UiPred)(void *);

struct UiCtx {
    u8      pad00[0x10];
    UiCb    on_10;
    UiCb    on_14;
    UiCb    on_18;
    UiCb    on_1c;
    UiCb    on_20;
    UiPred  on_24;
    void   *arg_28;
    void   *arg_2c;
    void   *arg_30;
    void   *arg_34;
    u8      always;
    u8      pad39[8];
    u8      armed;
};

void sub_020352AC(struct UiCtx *p)
{
    if (p->on_18 != 0 && p->armed != 0) {
        p->on_18(p->arg_2c);
        p->armed = 0;
    }
}
