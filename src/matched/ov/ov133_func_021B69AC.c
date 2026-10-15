/*
 * function: DUP_FITTING_InitDisplay
 * address: 0x021B69AC
 * packet: pkt_ov133_021B69AC
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 data 020A1448 has no independent witness; keep the ROM-pool Config copy.
 * blocker: ARM9 unit_0204349C.c omits BG_SYS_ClearMainPlanes from function:; unit_02043570.c omits BG_SYS_ClearSubPlanes.
 * blocker: 020434CC verified MATCH 16 bytes (nested 020434B4 missing in the same unit):
 *   extern void BG_SYS_ClearMainBgPlanes(void),BG_SYS_ClearMainObjPlane(void);
 *   void BG_SYS_ClearMainPlanes(void) { BG_SYS_ClearMainBgPlanes(); BG_SYS_ClearMainObjPlane(); }
 *   The unit's BG_SYS_ClearMainObjPlane body is g_02146A48.unk_04 &= 0xf (second word).
 * blocker: 02043588 verified EXACT 16 bytes:
 *   extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 *   void BG_SYS_ClearSubPlanes(void) { BG_SYS_ClearSubBgPlanes(); BG_SYS_ClearSubObjPlane(); }
 * tu: MATCH 504 bytes; --suggest-split leaves the sole function OUT, no viable partition.
 * volatile: hardware display-register accesses at 021B69BE,021B69C8,021B69F8,021B6A64.
 * symbols:
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetLowBit 0x0204044C arm
 *   DUP_FITTING_InitBgLayer 0x021B6E4C thumb ov133
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BILLBOARD_Create 0x0204EBD4 arm
 *   d_021BA518 0x021BA518 data a4
 *   d_021BA3F4 0x021BA3F4 data a4
 *   d_021BA40C 0x021BA40C data a4
 *   d_021BA400 0x021BA400 data a4
 *   d_021BA418 0x021BA418 data a4
 *   d_021BA428 0x021BA428 data a4
 *   d_021BA438 0x021BA438 data a4
 *   d_021BA458 0x021BA458 data a4
 *   d_021BA478 0x021BA478 data a4
 *   d_021BA4F8 0x021BA4F8 data a4
 *   d_021BA498 0x021BA498 data a4
 *   d_021BA4B8 0x021BA4B8 data a4
 *   d_021BA4D8 0x021BA4D8 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   d_021BA5C4 0x021BA5C4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 x,y,z; } Vec;
typedef struct { u32 words[2]; u8 a,b,c,d; u32 field; u16 dims[6]; } Config;
extern u8 d_021BA518[],d_021BA418[],d_021BA428[],d_021BA438[],d_021BA458[],d_021BA478[],d_021BA4F8[],d_021BA498[],d_021BA4B8[],d_021BA4D8[];
extern Vec d_021BA3F4,d_021BA40C,d_021BA400;
extern Config gClActorInitParam,d_021BA5C4;
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32,u32);
extern u32 WIPE_ResetWndMask(void *);
struct Bank;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Light;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,Vec *,Vec *,Vec *,u16);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void func_0207DCF8(void *);
extern void BG_SYS_Create(u16),BMP_WIN_Init(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_SetLowBit(u32);
extern void DUP_FITTING_InitBgLayer(const void *t, unsigned int id);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(void *,int,int,int,int);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32,u32),BG_SYS_SetSubPlaneVisible(u32,u32);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void *BILLBOARD_Create(u8 *,void *);
typedef enum { DISP_SUB_MAIN=0, DISP_MAIN_SUB=1 } DispSelect;
static inline void visible_main(int plane)
{
    *(volatile u32 *)0x04000000 = (u32)((*(volatile u32 *)0x04000000 & ~0x1f00u) | (plane << 8));
}
static inline void visible_sub(int plane)
{
    *(volatile u32 *)0x04001000 = (u32)((*(volatile u32 *)0x04001000 & ~0x1f00u) | (plane << 8));
}
static inline void select_display(DispSelect sel)
{
    *(volatile u16 *)0x04000304 = (u16)((*(volatile u16 *)0x04000304 & ~0x8000u) | (sel << 15));
}
void DUP_FITTING_InitDisplay(u8 *p)
{
    Config cfg, board;
    BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    visible_main(0);
    visible_sub(0);
    WIPE_SetBrightnessFadeOut(0,0); WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0); WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    select_display(DISP_SUB_MAIN);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BA518);
    G3D_SYSTEM_Init(0,2,0,1,0,*(u16 *)p,0);
    G3D_SYSTEM_SetSwapBuffersMode(0,1);
    *(u32 **)(p+0x1888) = G3D_CAMERA_Create(2,0xc000,0,0,0x10000,0x1000,0x3e8000,0,&d_021BA3F4,&d_021BA40C,&d_021BA400,*(u16 *)p);
    G3D_CAMERA_Reset(*(void **)(p+0x1888));
    func_0207DCF8(d_021BA418);
    *(volatile u16 *)0x04000060 &= 0xcfdf;
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
    BG_SYS_Create(*(u16 *)p); BMP_WIN_Init(*(u16 *)p);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BA428); BG_SYS_SetLowBit(1);
    DUP_FITTING_InitBgLayer(d_021BA438,1); DUP_FITTING_InitBgLayer(d_021BA458,2);
    DUP_FITTING_InitBgLayer(d_021BA478,3); DUP_FITTING_InitBgLayer(d_021BA4F8,7);
    DUP_FITTING_InitBgLayer(d_021BA498,4); DUP_FITTING_InitBgLayer(d_021BA4B8,5); DUP_FITTING_InitBgLayer(d_021BA4D8,6);
    func_02040588(0,1);
    func_0207D63C((void *)0x04001050,0,15,4,16);
    cfg = gClActorInitParam;
    cfg.a = 16; cfg.b = 112;
    CLACT_InitSystem((const struct Cfg *)(&cfg),(u32)d_021BA518,*(u16 *)p);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
    *(void **)(p+0x1848) = CLACT_CreateUnit(24,0,*(u16 *)p);
    CLACT_SetUnitDefaultRenderer(*(void **)(p+0x1848));
    board = d_021BA5C4;
    *(void **)(p+0x188c) = BILLBOARD_Create((u8 *)&board,(void *)*(u16 *)p);
}
