/*
 * function: sub_02035268
 * address:  0x02035268
 * packet:   pkt_02035224
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The +0x10 callback slot, same shape as sub_0203524C and sharing its
 * argument word at +0x28.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035268.c \n *       --func sub_02035268 --addr 0x02035268 --cc 1.1p1 --arm
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

void sub_02035268(struct UiCtx *p)
{
    if (p->on_10 != 0) {
        p->on_10(p->arg_28);
    }
}
