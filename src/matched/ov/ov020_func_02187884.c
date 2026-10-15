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
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 */
typedef unsigned int   u32;
extern u32 BG_SYS_GetMainVisiblePlanes(void);
extern void FIELDMAP_SetBgMode(void);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern void BG_SYS_FreeSlot(int a);
void EL_SCOREBOARD_SetupSharedDisplay(char *unused)
{
    int n;
    n = BG_SYS_GetMainVisiblePlanes();
    FIELDMAP_SetBgMode();
    BG_SYS_SetMainVisiblePlanes(n);
    BG_SYS_SetVisibleLayer(0, 1);
    BG_SYS_SetVisibleLayer(3, 0);
    BG_SYS_SetVisibleLayer(1, 3);
    BG_SYS_SetVisibleLayer(2, 3);
    BG_SYS_FreeSlot(3);
}
