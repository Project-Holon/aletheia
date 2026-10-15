/*
 * function: DENDOU_VIEW_StateExit
 * address: 0x021DCF38
 * packet: pkt_ov171_021DCF38
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DENDOU_VIEW_StopVBlankTask 0x021DC8D4 thumb ov171
 *   DENDOU_VIEW_ExitActors 0x021DE014 thumb ov171
 *   DENDOU_VIEW_ExitWindows 0x021DD8BC thumb ov171
 *   DENDOU_VIEW_ExitText 0x021DCC88 thumb ov171
 *   DENDOU_VIEW_ExitPalAnm 0x021DCB8C thumb ov171
 *   DENDOU_VIEW_ExitBgs 0x021DCA40 thumb ov171
 *   DENDOU_VIEW_FreeHallOfFame 0x021DCE28 thumb ov171
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
extern int DENDOU_VIEW_StopVBlankTask(int *);
extern void DENDOU_VIEW_ExitActors(int *);
extern void DENDOU_VIEW_ExitWindows(int *);
extern void DENDOU_VIEW_ExitText(char *p);
extern void DENDOU_VIEW_ExitPalAnm(int *);
extern void DENDOU_VIEW_ExitBgs(void);
extern void DENDOU_VIEW_FreeHallOfFame(char *p);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_02034A5C(int);
extern char ov067_id[];
int DENDOU_VIEW_StateExit(int *p)
{
    DENDOU_VIEW_StopVBlankTask(p);
    DENDOU_VIEW_ExitActors(p);
    DENDOU_VIEW_ExitWindows(p);
    DENDOU_VIEW_ExitText((char *)p);
    DENDOU_VIEW_ExitPalAnm(p);
    DENDOU_VIEW_ExitBgs();
    DENDOU_VIEW_FreeHallOfFame((char *)p);
    GXx_SetMasterBrightness_((void *)0x0400006c, -16);
    GXx_SetMasterBrightness_((void *)0x0400106c, -16);
    *(unsigned short *)0x04000050 = 0;
    *(unsigned short *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02034A5C((int)ov067_id);
    return 11;
}
