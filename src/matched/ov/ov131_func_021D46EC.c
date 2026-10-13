/*
 * function: P_STATUS_InitGraphics
 * address: 0x021D46EC
 * packet: pkt_ov131_021D46EC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: complete original 020160C0 bytes 41 64 70 47 store r1 at
 *   r0+0x44 and return. Caller supplies object and full word 0x10000.
 *   02046440 owner's s16 heap is u16 here: original ldrh zero-extends its
 *   outgoing stack word. Lower 16-bit callee conversion remains unchanged.
 *   Config c initializes all 28 bytes before h[0] and consumer reads.
 * lever: game hardware writes use vendor visible-plane and enum display
 *   selection inlines; raw compound assignments change constant sharing.
 * witness: 020160C0 filed as src/matched/arm9/MCSS_SetGlobalScale.c.
 * volatile: hardware DISPCNT/BLDCNT/POWCNT1/DISP3DCNT registers
 * symbols:
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   P_STATUS_InitBgLayer 0x021D4940 thumb ov131
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   func_0204044C 0x0204044C arm
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetGlobalScale 0x020160C0 thumb
 *   g_C0E4 0x021DC0E4 data ov131
 *   g_BFF4 0x021DBFF4 data ov131
 *   g_C004 0x021DC004 data ov131
 *   ClactSysDefaultSetup 0x020A1448 data
 *   g_BFC0 0x021DBFC0 data ov131
 *   g_BFE4 0x021DBFE4 data ov131
 */
#include "../include/Obj01739.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct DispVram;
struct DispConfig;
struct BgConfig {u32 w[8];};
struct Cfg {u32 w[4];u16 h[6];};
struct Vec3 {u32 x,y,z;};
extern const struct DispVram g_C0E4;
extern struct DispConfig g_BFF4;
extern struct BgConfig g_C004[7];
extern struct Cfg ClactSysDefaultSetup;
extern struct Vec3 g_BFC0[3];
extern u16 g_BFE4[8];
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32,u32);
extern u32 WIPE_ResetWndMask(void *);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void func_0203F8F4(u16),BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *);
extern void P_STATUS_InitBgLayer(struct BgConfig *,u32,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(u32 *,u32,u32,u32,u32);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32,u32),BG_SYS_SetSubPlaneVisible(u32,u32);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u16,void (*)(void));
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,struct Vec3 *,struct Vec3 *,struct Vec3 *,u16);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void func_0207DCF8(const void *);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32),func_0204044C(u32);
extern void *MCSS_Init(u32,void *);
extern void MCSS_SetTextureTransAdrs(void *,u32);
extern void MCSS_SetGlobalScale(char *p, unsigned int v);
typedef enum {GX_DISP_SELECT_SUB_MAIN=0, GX_DISP_SELECT_MAIN_SUB=1} GXDispSelect;
static inline void GX_SetVisiblePlane(int plane)
{ *(volatile u32 *)0x04000000=(u32)((*(volatile u32 *)0x04000000 & ~0x1f00) | (plane<<8)); }
static inline void GXS_SetVisiblePlane(int plane)
{ *(volatile u32 *)0x04001000=(u32)((*(volatile u32 *)0x04001000 & ~0x1f00) | (plane<<8)); }
static inline void GX_SetDispSelect(GXDispSelect sel)
{ *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel<<15)); }
void P_STATUS_InitGraphics(char *p)
{
    struct Cfg c;
    BG_SYS_ClearMainPlanes();BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0);GXS_SetVisiblePlane(0);
    WIPE_SetBrightnessFadeOut(0,0);WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0);WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    BG_SYS_SetVramBanks(&g_C0E4);
    func_0203F8F4(((struct Obj01739 *)p)->f0);BMP_WIN_Init(((struct Obj01739 *)p)->f0);
    func_0203FC28(&g_BFF4);
    P_STATUS_InitBgLayer(&g_C004[6],1,0);P_STATUS_InitBgLayer(&g_C004[4],2,0);P_STATUS_InitBgLayer(&g_C004[0],3,0);
    func_02040588(0,1);
    P_STATUS_InitBgLayer(&g_C004[1],4,0);P_STATUS_InitBgLayer(&g_C004[2],5,0);P_STATUS_InitBgLayer(&g_C004[3],6,0);P_STATUS_InitBgLayer(&g_C004[5],7,0);
    func_0207D63C((u32 *)0x04000050,4,30,13,16);
    func_0207D63C((u32 *)0x04001050,4,8,13,16);
    c=ClactSysDefaultSetup;c.h[0]=110;
    CLACT_InitSystem(&c,(u32)(&g_C0E4),((struct Obj01739 *)p)->f0);
    ((struct Obj01739 *)p)->f174=CLACT_CreateUnit(96,0,((struct Obj01739 *)p)->f0);
    CLACT_SetUnitDefaultRenderer(((struct Obj01739 *)p)->f174);
    BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);
    G3D_SYSTEM_Init(0,2,0,1,0,((struct Obj01739 *)p)->f0,0);
    *(u32 * *)&((struct Obj01739 *)p)->f70=G3D_CAMERA_Create(2,0xc0000,0,0,0x100000,0x80000,0x200000,0,&g_BFC0[0],&g_BFC0[2],&g_BFC0[1],((struct Obj01739 *)p)->f0);
    G3D_CAMERA_Reset(((struct Obj01739 *)p)->f70);
    func_0207DCF8(g_BFE4);
    *(volatile u16 *)0x04000060 &= ~0x3020;
    G3D_SYSTEM_SetSwapBuffersMode(0,0);func_0204044C(0);
    ((struct Obj01739 *)p)->f78=MCSS_Init(2,(void *)((struct Obj01739 *)p)->f0);
    MCSS_SetTextureTransAdrs(((struct Obj01739 *)p)->f78,0);
    MCSS_SetGlobalScale(((struct Obj01739 *)p)->f78,0x10000);
}
