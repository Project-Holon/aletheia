/*
 * function: POKELIST_SetupDisplay
 * address:  0x021B6D90
 * packet:   pkt_ov091_021B6D90
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; 36 of 37 sites resolve.  The one wildcard is the arm9 call
 * at +013C to NNS_GfdResetVramTransferTaskQueue, which has no witness outside this range.
 * blocker:
 *   NNS_GfdResetVramTransferTaskQueue  0x02061C30  arm  (arm9, the integrator's leaf; unlabelled ARM
 *   tail-call stub `ldr ip,[pc,#4]; ldr r0,[pc,#4]; bx ip; .word 0x02061B5C;
 *   .word 0x02146B80`).  No verified C exists: src/pending/arm9_sdk/
 *   NNS_GfdResetVramTransferTaskQueue.c (`OS_WakeupThreadDirect(&dacktimer_thread);`) is DIFF,
 *   network.o is a 3.0.0.139 object no available mwcc build reproduces.
 *   Same blocker as src/pending/ov/ov091_func_021B6FEC.c.
 *
 * volatile: 0x021B6DCA/0x021B6DD4 re-read DISPCNT (0x04000000) and
 *   DB_DISPCNT (0x04001000), 0x021B6DFA POWCNT (0x04000304): SDK inlines
 *   GX_SetVisiblePlane, GXS_SetVisiblePlane, GX_SetDispSelect.
 *
 * symbols:
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   POKELIST_LoadBgPlane  0x021B7078  thumb  ov091
 *   POKELIST_SetupBgPlanes  0x021B6F0C  thumb  ov091
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   func_0207D63C  0x0207D63C  arm
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   NNS_GfdResetVramTransferTaskQueue  0x02061C30  arm
 *   d_021BEC3C     0x021BEC3C  data  a4
 *   d_021BEAEC     0x021BEAEC  data  a4
 *   d_021BEAFC     0x021BEAFC  data  a4
 *   d_021BEB1C     0x021BEB1C  data  a4
 *   d_021BEB3C     0x021BEB3C  data  a4
 *   d_021BEB5C     0x021BEB5C  data  a4
 *   d_021BEB9C     0x021BEB9C  data  a4
 *   d_021BEBBC     0x021BEBBC  data  a4
 *   d_021BEBDC     0x021BEBDC  data  a4
 *   gClActorInitParam     0x020A1448  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 w[12];
} A48;

typedef struct {
    u32 w[7];
} B28;

extern A48 d_021BEC3C;
extern B28 gClActorInitParam;
extern char d_021BEAEC[];
extern char d_021BEAFC[];
extern char d_021BEB1C[];
extern char d_021BEB3C[];
extern char d_021BEB5C[];
extern char d_021BEB9C[];
extern char d_021BEBBC[];
extern char d_021BEBDC[];

struct Cfg;
struct DispConfig;
struct DispVram;
extern int POKELIST_IsItemMode(u32 p);
extern void POKELIST_LoadBgPlane(const void *p, unsigned id, unsigned type);
extern void POKELIST_SetupBgPlanes(void *p);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
extern void WIPE_ResetWndMask(int a);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16 heapId);
extern void BMP_WIN_Init(u16 heapId);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void func_0207D63C(u32 r, int a, int b, int c, int d);
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void NNS_GfdResetVramTransferTaskQueue(void);

#define reg_GX_DISPCNT (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)

static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (u32)((reg_GX_DISPCNT & ~0x1f00) | (plane << 8));
}

static inline void GXS_SetVisiblePlane(int plane)
{
    reg_GXS_DB_DISPCNT = (u32)((reg_GXS_DB_DISPCNT & ~0x1f00) | (plane << 8));
}

typedef enum { GX_DISP_SELECT_SUB_MAIN = 0, GX_DISP_SELECT_MAIN_SUB = 1 } GXDispSelect;

static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~0x8000) | (sel << 15));
}

void POKELIST_SetupDisplay(u8 *p)
{
    A48 a;
    B28 b;

    a = d_021BEC3C;
    if (POKELIST_IsItemMode((u32)p) == 1) {
        a.w[6] = 8;
        a.w[8] = 0;
    } else {
        a.w[6] = 0x100;
    }
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask(1);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    BG_SYS_SetVramBanks((const struct DispVram *)(&a));
    BG_SYS_Create(*(u16 *)p);
    BMP_WIN_Init(*(u16 *)p);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BEAEC);
    POKELIST_LoadBgPlane(d_021BEBDC, 3, 0);
    POKELIST_LoadBgPlane(d_021BEBBC, 2, 0);
    POKELIST_LoadBgPlane(d_021BEB9C, 1, 0);
    POKELIST_LoadBgPlane(d_021BEB5C, 7, 0);
    POKELIST_LoadBgPlane(d_021BEB3C, 6, 0);
    POKELIST_LoadBgPlane(d_021BEB1C, 5, 0);
    POKELIST_LoadBgPlane(d_021BEAFC, 4, 0);
    POKELIST_SetupBgPlanes(p);
    func_0207D63C(0x04000050, 0x14, 8, 0x10, 10);
    func_0207D63C(0x04001050, 4, 8, 0x10, 10);
    BG_SYS_ChangeScrollImmediate(2, 0, 0x80);
    BG_SYS_ChangeScrollImmediate(1, 0, 0x80);
    b = gClActorInitParam;
    CLACT_InitSystem((const struct Cfg *)(&b), (u32)(&a), *(u16 *)p);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    NNS_GfdResetVramTransferTaskQueue();
}
