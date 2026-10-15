/*
 * function: STAFF_ROLL_Setup
 * address:  0x021B9630
 * packet:   pkt_021B9630
 * region:   ov181
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
 *   GFL_USE_PlayFanfare  0x02005DAC  thumb
 *   STAFF_ROLL_SetupVramBanks  0x021B98F4  thumb  ov181
 *   STAFF_ROLL_SetupBackgrounds  0x021B9908  thumb  ov181
 *   STAFF_ROLL_LoadGraphics  0x021B99F8  thumb  ov181
 *   STAFF_ROLL_InitText  0x021B9B1C  thumb  ov181
 *   STAFF_ROLL_InitWindows  0x021B9D34  thumb  ov181
 *   STAFF_ROLL_Init3d  0x021B9E14  thumb  ov181
 *   STAFF_ROLL_LoadRows  0x021B9D04  thumb  ov181
 *   STAFF_ROLL_AddVblankTask  0x021B9AF8  thumb  ov181
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
extern void GFL_USE_PlayFanfare(void *arg);
extern void STAFF_ROLL_SetupVramBanks(void);
extern void STAFF_ROLL_SetupBackgrounds(void);
extern void STAFF_ROLL_LoadGraphics(void);
extern void STAFF_ROLL_InitText(char *p);
extern void STAFF_ROLL_InitWindows(char *p);
extern void STAFF_ROLL_Init3d(char *p);
extern void STAFF_ROLL_LoadRows(char *p);
extern void STAFF_ROLL_AddVblankTask(char *p);
extern u8 ov067_id[];

int STAFF_ROLL_Setup(u8 *p)
{
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetLcdSwap(1);
    GXx_SetMasterBrightness_((void *)0x0400006c, -0x10);
    GXx_SetMasterBrightness_((void *)0x0400106c, -0x10);
    STAFF_ROLL_SetupVramBanks();
    STAFF_ROLL_SetupBackgrounds();
    STAFF_ROLL_LoadGraphics();
    STAFF_ROLL_InitText((char *)p);
    STAFF_ROLL_InitWindows((char *)p);
    STAFF_ROLL_Init3d((char *)p);
    STAFF_ROLL_LoadRows((char *)p);
    STAFF_ROLL_AddVblankTask((char *)p);
    GFL_USE_PlayFanfare((void *)0x3f8);
    return 3;
}

