/*
 * function: func_02034FD4
 * address:  0x02034FD4
 * packet:   pkt_02034FD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct UiCtx {
    u8 pad00[0x38];
    u8 always;
};
#define g_021469BC (*(struct UiCtx **)0x021469BC)

u32 func_02034FD4(struct UiCtx *p, u8 flags)
{
    return (p->always & flags) != 0;
}
