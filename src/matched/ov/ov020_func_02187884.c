/*
 * function: EL_SCOREBOARD_SetupSharedDisplay
 * address: 0x02187884
 * packet: pkt_ov020_02187884
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes.
 * symbols:
 *   BG_SYS_GetMainVisiblePlanes 0x02043658 arm
 *   FIELDMAP_SetBgMode 0x02188DA0 thumb ov021
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   func_0204047C 0x0204047C arm
 *   func_020414AC 0x020414AC arm
 */
typedef unsigned int   u32;
extern u32 BG_SYS_GetMainVisiblePlanes(void);
extern void FIELDMAP_SetBgMode(void);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void func_0204047C(int idx, unsigned short val);
extern void func_020414AC(int a);
void EL_SCOREBOARD_SetupSharedDisplay(char *unused)
{
    int n;
    n = BG_SYS_GetMainVisiblePlanes();
    FIELDMAP_SetBgMode();
    BG_SYS_SetMainVisiblePlanes(n);
    func_0204047C(0, 1);
    func_0204047C(3, 0);
    func_0204047C(1, 3);
    func_0204047C(2, 3);
    func_020414AC(3);
}
