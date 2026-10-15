/*
 * function: UI_TestKeepAwakeFlagsGlobal
 * address:  0x02034FE8
 * packet:   pkt_02034FE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   UI_TestKeepAwakeFlags 0x02034FD4 arm
 *   gUiState  0x021469BC  data
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct UiCtx {
    u8 pad00[0x38];
    u8 always;
};
#define gUiState (*(struct UiCtx **)0x021469BC)
extern u32 UI_TestKeepAwakeFlags(struct UiCtx *p, u8 flags);

u32 UI_TestKeepAwakeFlagsGlobal(u8 flags)
{
    return UI_TestKeepAwakeFlags(gUiState, flags);
}
