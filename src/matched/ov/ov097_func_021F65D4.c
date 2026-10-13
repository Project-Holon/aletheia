/*
 * function: VS_MULTI_LIST_StateSetup
 * address:  0x021F65D4
 * packet:   pkt_ov097_021F65D4
 * region:   ov097
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   VS_MULTI_LIST_InitMons  0x021F6A28  thumb  ov097
 *   VS_MULTI_LIST_SetVramBanks  0x021F682C  thumb  ov097
 *   VS_MULTI_LIST_InitBgs  0x021F683C  thumb  ov097
 *   VS_MULTI_LIST_LoadBgGraphics  0x021F68FC  thumb  ov097
 *   VS_MULTI_LIST_CreateTextResources  0x021F6970  thumb  ov097
 *   VS_MULTI_LIST_CreateWindows  0x021F6A98  thumb  ov097
 *   VS_MULTI_LIST_InitIcons  0x021F6F24  thumb  ov097
 *   VS_MULTI_LIST_CreateBgFrames  0x021F734C  thumb  ov097
 *   VS_MULTI_LIST_AddVBlankTask  0x021F69E4  thumb  ov097
 *   VS_MULTI_LIST_EnterWaitState  0x021F681C  thumb  ov097
 *   VS_MULTI_LIST_StartWipeIn  0x021F67C8  thumb  ov097
 */

typedef unsigned short u16;

typedef unsigned int   u32;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
typedef unsigned char  u8;
struct P;
extern void VS_MULTI_LIST_InitMons(int *p);
extern void VS_MULTI_LIST_SetVramBanks(void);
extern void VS_MULTI_LIST_InitBgs(void);
extern void VS_MULTI_LIST_LoadBgGraphics(int);
extern void VS_MULTI_LIST_CreateTextResources(u8 *p);
extern void VS_MULTI_LIST_CreateWindows(int);
extern void VS_MULTI_LIST_InitIcons(struct P *p);
extern void VS_MULTI_LIST_CreateBgFrames(struct P *p);
extern void VS_MULTI_LIST_AddVBlankTask(u8 *p);
extern int VS_MULTI_LIST_EnterWaitState(u8 *p, int count, int result);
extern int VS_MULTI_LIST_StartWipeIn(u8 *p, int value);

void VS_MULTI_LIST_StateSetup(int a)
{
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetLcdSwap(1);
    VS_MULTI_LIST_InitMons((int *)a);
    VS_MULTI_LIST_SetVramBanks();
    VS_MULTI_LIST_InitBgs();
    VS_MULTI_LIST_LoadBgGraphics(a);
    VS_MULTI_LIST_CreateTextResources((u8 *)a);
    VS_MULTI_LIST_CreateWindows(a);
    VS_MULTI_LIST_InitIcons((struct P *)a);
    VS_MULTI_LIST_CreateBgFrames((struct P *)a);
    GFL_NET_RestartWithDefaultTimeout(1, 0x71);
    BG_SYS_SetMainPlaneVisible(0x17, 1);
    VS_MULTI_LIST_AddVBlankTask((u8 *)a);
    VS_MULTI_LIST_StartWipeIn((u8 *)a, VS_MULTI_LIST_EnterWaitState((u8 *)a, 0x80, 4));
}
