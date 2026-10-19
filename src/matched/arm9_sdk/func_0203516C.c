/*
 * function: UI_SetSoftResetInhibitGlobal
 * address:  0x0203516C
 * packet:   pkt_0203516C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203515C 0x0203515C arm
 *   gUiState 0x021469BC data
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct UiCtx {
    u8 pad00[0x38];
    u8 always;
};
#define gUiState (*(struct UiCtx **)0x021469BC)
extern void func_0203515C(struct UiCtx *p, u8 mask);

void UI_SetSoftResetInhibitGlobal(u8 mask)
{
    func_0203515C(gUiState, mask);
}
