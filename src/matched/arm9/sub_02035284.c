/*
 * function: UI_RunSuspendHook
 * address:  0x02035284
 * packet:   pkt_02035224
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Arm the context: run the +0x1c hook with the +0x2c argument and set the
 * armed flag at +0x41.  UI_RunResumeHook is the disarming half.  The flag is set
 * only when a hook was actually installed, so it stays inside the guard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/UI_RunSuspendHook.c \n *       --func UI_RunSuspendHook --addr 0x02035284 --cc 1.1p1 --arm
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

void UI_RunSuspendHook(struct UiCtx *p)
{
    if (p->on_1c != 0) {
        p->on_1c(p->arg_2c);
        p->armed = 1;
    }
}
