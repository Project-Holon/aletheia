/*
 * function: func_020351D0
 * address:  0x020351D0
 * packet:   pkt_020351D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020351BC 0x020351BC arm
 *   gUiState 0x021469BC data
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct UiCtx {
    u8 pad00[0x38];
    u8 always;
};
#define gUiState (*(struct UiCtx **)0x021469BC)
extern u32 func_020351BC(struct UiCtx *p, u32 mask);

u32 func_020351D0(u32 mask)
{
    return func_020351BC(gUiState, mask);
}
