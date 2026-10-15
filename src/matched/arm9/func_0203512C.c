/*
 * function: UI_SetWakePoweredHook
 * address:  0x0203512C
 * packet:   pkt_0203512C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     2026-10-12 lane HF0: hidden function filed.
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*UiCb)(void *);
struct UiCtx {
    u8 pad_00[0x20];
    UiCb on_20;
    u8 pad_24[0xC];
    void *arg_30;
};

void UI_SetWakePoweredHook(struct UiCtx *p, UiCb fn, void *arg)
{
    p->on_20 = fn;
    p->arg_30 = arg;
}
