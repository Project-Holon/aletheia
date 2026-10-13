/*
 * function: UI_IsSleepInhibited
 * address:  0x020353F8
 * packet:   pkt_020353B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The context's veto predicate: the byte at +0x38 forces a yes, otherwise a
 * hook at +0x24 decides, and with no hook the answer is no.  The hook
 * pointer stays in r1 from its own null test through the `blx`, which is why
 * the argument at +0x34 is fetched into r0 second.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_IsSleepInhibited.c \n *       --func UI_IsSleepInhibited --addr 0x020353F8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

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
};

int UI_IsSleepInhibited(struct UiCtx *p)
{
    if (p->always != 0) {
        return 1;
    }
    if (p->on_24 == 0) {
        return 0;
    }
    return p->on_24(p->arg_34);
}
