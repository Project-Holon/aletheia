/*
 * function: DENDOU_VIEW_StateInit
 * address:  0x021DCEA4
 * packet:   pkt_021DCEA4
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   DENDOU_VIEW_LoadHallOfFame  0x021DCCC8  thumb  ov171
 *   DENDOU_VIEW_InitVram  0x021DC910  thumb  ov171
 *   DENDOU_VIEW_InitBgs  0x021DC92C  thumb  ov171
 *   DENDOU_VIEW_LoadGraphics  0x021DCA7C  thumb  ov171
 *   DENDOU_VIEW_InitPalAnm  0x021DCB70  thumb  ov171
 *   DENDOU_VIEW_InitText  0x021DCC24  thumb  ov171
 *   DENDOU_VIEW_InitWindows  0x021DD874  thumb  ov171
 *   DENDOU_VIEW_InitActors  0x021DDFE8  thumb  ov171
 *   DENDOU_VIEW_StateChangeRow  0x021DD0E8  thumb  ov171
 *   DENDOU_VIEW_InitBlend  0x021DCC0C  thumb  ov171
 *   DENDOU_VIEW_StartVBlankTask  0x021DC8B8  thumb  ov171
 *   DENDOU_VIEW_StartWipeIn  0x021DD4A4  thumb  ov171
 *   ov067_id       0x00000043  data
 */
typedef unsigned char u8;
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
extern int func_02034AC4(s32 handle);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
struct P;
extern void DENDOU_VIEW_LoadHallOfFame(struct P *p);
extern void DENDOU_VIEW_InitVram(void);
extern void DENDOU_VIEW_InitBgs(void);
extern void DENDOU_VIEW_LoadGraphics(void);
extern void DENDOU_VIEW_InitPalAnm(int *p);
extern void DENDOU_VIEW_InitText(char *p);
extern void DENDOU_VIEW_InitWindows(char *p);
extern void DENDOU_VIEW_InitActors(u8 *p);
extern int DENDOU_VIEW_StateChangeRow(u8 *p);
extern void DENDOU_VIEW_InitBlend(void);
extern void DENDOU_VIEW_StartVBlankTask(int *p);
extern int DENDOU_VIEW_StartWipeIn(u8 *p, int v);
extern u8 ov067_id[];

void DENDOU_VIEW_StateInit(u8 *p)
{
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetLcdSwap(0);
    GXx_SetMasterBrightness_((void *)0x0400006c, -0x10);
    GXx_SetMasterBrightness_((void *)0x0400106c, -0x10);
    DENDOU_VIEW_LoadHallOfFame((struct P *)p);
    DENDOU_VIEW_InitVram();
    DENDOU_VIEW_InitBgs();
    DENDOU_VIEW_LoadGraphics();
    DENDOU_VIEW_InitPalAnm((int *)p);
    DENDOU_VIEW_InitText((char *)p);
    DENDOU_VIEW_InitWindows((char *)p);
    DENDOU_VIEW_InitActors(p);
    DENDOU_VIEW_StateChangeRow(p);
    DENDOU_VIEW_InitBlend();
    GFL_NET_RestartWithDefaultTimeout(1, 0x8c);
    DENDOU_VIEW_StartVBlankTask((int *)p);
    DENDOU_VIEW_StartWipeIn(p, 4);
}
