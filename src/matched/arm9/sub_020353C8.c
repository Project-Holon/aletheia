/*
 * function: sub_020353C8
 * address:  0x020353C8
 * packet:   pkt_020353B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020353B0  0x020353B0  arm
 *
 * Run the +0x20 hook, but only when one is installed and sub_020353B0 says
 * the state allows it.  The two guards each carry their own `popeq`: a call
 * sits between them, so they cannot share an exit block and are two `if`s
 * rather than one `&&`.
 *
 * The hook pointer is re-read after the sub_020353B0 call, and the argument
 * at +0x30 is loaded before it, because nothing proves the call left the
 * context alone.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020353C8.c \n *       --func sub_020353C8 --addr 0x020353C8 --cc 1.1p1 --arm
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

extern int func_020353B0(void);

void sub_020353C8(struct UiCtx *p)
{
    if (p->on_20 == 0) {
        return;
    }
    if (func_020353B0() == 0) {
        return;
    }
    p->on_20(p->arg_30);
}
