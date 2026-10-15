/*
 * function: ZUKAN_SEARCH_SCREEN_Init
 * address: 0x021BC670
 * packet: pkt_ov211_021BC670
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword stores to 04000050 at 021BC684 and
 * 04001050 at 021BC688; original clears display blend controls.
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   ZUKAN_SEARCH_SCREEN_SetupVram 0x021BC2B0 thumb ov211
 *   ZUKAN_SEARCH_SCREEN_InitBg 0x021BC318 thumb ov211
 *   ZUKAN_SEARCH_SCREEN_LoadGraphics 0x021BC474 thumb ov211
 *   ZUKAN_SEARCH_SCREEN_LoadSaveGraphics 0x021BC5B0 thumb ov211
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   ZUKAN_SEARCH_SCREEN_RegisterVBlank 0x021BC2F4 thumb ov211
 *   ZUKAN_StartWipeIn 0x021C93A8 thumb ov212
 */
extern void BG_SYS_SetMainVisiblePlanes(unsigned),BG_SYS_SetSubVisiblePlanes(unsigned),BG_SYS_SetLcdSwap(unsigned);
struct Object;
extern void ZUKAN_SEARCH_SCREEN_SetupVram(void);
extern void ZUKAN_SEARCH_SCREEN_InitBg(void);
extern void ZUKAN_SEARCH_SCREEN_LoadGraphics(struct Object *p);
extern void ZUKAN_SEARCH_SCREEN_LoadSaveGraphics(char *);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned),BG_SYS_SetSubPlaneVisible(unsigned,unsigned);
extern void ZUKAN_SEARCH_SCREEN_RegisterVBlank(unsigned char *p);
extern void ZUKAN_StartWipeIn(unsigned);
int ZUKAN_SEARCH_SCREEN_Init(char *p)
{
    BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    BG_SYS_SetLcdSwap(0);ZUKAN_SEARCH_SCREEN_SetupVram();ZUKAN_SEARCH_SCREEN_InitBg();
    ZUKAN_SEARCH_SCREEN_LoadGraphics((struct Object *)p);ZUKAN_SEARCH_SCREEN_LoadSaveGraphics(p);
    GFL_NET_RestartWithDefaultTimeout(1,126);BG_SYS_SetSubPlaneVisible(16,1);
    ZUKAN_SEARCH_SCREEN_RegisterVBlank((unsigned char *)p);ZUKAN_StartWipeIn(126);
    return 2;
}
