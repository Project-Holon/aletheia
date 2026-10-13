/*
 * function: EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes
 * address:  0x021BF564
 * packet:   pkt_ov021_021BF564
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BG_SYS_GetMainVisiblePlanes  0x02043658  arm
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm
 *   FIELDMAP_SetBgMode  0x02188DA0  thumb  ov021
 *   func_02043534  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 BG_SYS_GetMainVisiblePlanes(void);
extern u32 BG_SYS_GetSubVisiblePlanes(void);
extern void FIELDMAP_SetBgMode(void);
extern void func_02043534(u32 v);
extern void BG_SYS_SetSubVisiblePlanes(u32 v);

void EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes(void)
{
    u32 a = BG_SYS_GetMainVisiblePlanes();
    u32 b = BG_SYS_GetSubVisiblePlanes();

    FIELDMAP_SetBgMode();
    func_02043534(a);
    BG_SYS_SetSubVisiblePlanes(b);
}
