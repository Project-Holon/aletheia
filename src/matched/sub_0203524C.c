/*
 * function: sub_0203524C
 * address:  0x0203524C
 * packet:   pkt_02035224
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * One of the five optional callback slots the UI context carries: run the
 * hook at +0x14 with its own argument at +0x28 if one is installed, and do
 * nothing otherwise.  The argument is loaded only on the taken path, after
 * the null test, so the null check cannot be folded into the call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203524C.c \n *       --func sub_0203524C --addr 0x0203524C --cc 1.1p1 --arm
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

void sub_0203524C(struct UiCtx *p)
{
    if (p->on_14 != 0) {
        p->on_14(p->arg_28);
    }
}
