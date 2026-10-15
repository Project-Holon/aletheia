/*
 * function: CTVT_CALL_InitDisplay
 * address:  0x021BD5D8
 * packet:   pkt_ov172_021BD5D8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05: EXACT once the contested ov172 token is dropped from the d_021C70x0 data lines.
 *
 * symbols:
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   CTVT_CALL_InitBgLayer  0x021BD820  thumb  ov172
 *   G2_GetBG2ScrPtr  0x0207E008  arm
 *   G2_GetBG3ScrPtr  0x0207E100  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02040588  0x02040588  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   d_021C7050     0x021C7050  data  a4
 *   d_021C7060     0x021C7060  data  a4
 *   d_021C7080     0x021C7080  data  a4
 *   d_021C70A0     0x021C70A0  data  a4
 *   d_021C70C0     0x021C70C0  data  a4
 *   d_021C70E0     0x021C70E0  data  a4
 *   d_021C7100     0x021C7100  data  a4
 *   d_021C7120     0x021C7120  data  a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 w[7]; } Cfg7;
struct Bank;
struct DispConfig;
struct BgTemplate;

extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 b);
struct Cfg;
struct DispVram;
extern u32 WIPE_ResetWndMask(void *win);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16 heap);
extern void BMP_WIN_Init(u16 heap);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void CTVT_CALL_InitBgLayer(const struct BgTemplate *tmpl, u32 bgId, u32 type);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MI_CpuFill8(void *p, int c, u32 n);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern const Cfg7 gClActorInitParam;
extern u8 d_021C7050[];
extern u8 d_021C7060[];
extern u8 d_021C7080[];
extern u8 d_021C70A0[];
extern u8 d_021C70C0[];
extern u8 d_021C70E0[];
extern u8 d_021C7100[];
extern u8 d_021C7120[];

#define WININ (*(volatile u16 *)0x04000048)
#define WINOUT (*(volatile u16 *)0x0400004a)
static inline void inside0(int wnd, int effect)
{
    u32 tmp;
    tmp = (WININ & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WININ = (u16)tmp;
}
static inline void inside1(int wnd, int effect)
{
    u32 tmp;
    tmp = (WININ & ~0x3f00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    WININ = (u16)tmp;
}
static inline void outside(int wnd, int effect)
{
    u32 tmp;
    tmp = (WINOUT & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    WINOUT = (u16)tmp;
}

void CTVT_CALL_InitDisplay(u8 *p)
{
    u32 size;
    u32 mode;
    struct Bank *bank;
    Cfg7 cfg;

    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FF;
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000304 |= 0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C7120);
    BG_SYS_Create(*(u16 *)p);
    BMP_WIN_Init(*(u16 *)p);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021C7050);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C70A0, 0, 0);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C7100, 1, 0);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C70C0, 4, 0);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C70E0, 5, 0);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C7080, 6, 0);
    CTVT_CALL_InitBgLayer((const struct BgTemplate *)d_021C7060, 7, 0);
    *(volatile u16 *)0x0400000C = (*(volatile u16 *)0x0400000C & 0x43) | 0x4484;
    *(volatile u16 *)0x0400000E = (*(volatile u16 *)0x0400000E & 0x43) | 0x4A84;
    size = 0x18000;
    MI_CpuFill8(G2_GetBG2ScrPtr(), 0, size);
    MI_CpuFill8((void *)G2_GetBG3ScrPtr(), 0, size);
    *(volatile u16 *)0x0400000C = (*(volatile u16 *)0x0400000C & ~3) | 1;
    *(volatile u16 *)0x0400000E = (*(volatile u16 *)0x0400000E & ~3) | 2;
    func_02040588(2, 1);
    mode = 3;
    func_02040588(mode, 1);
    cfg = gClActorInitParam;
    CLACT_InitSystem((const struct Cfg *)(&cfg), (u32)d_021C7120, *(u16 *)p);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    bank = CLACT_CreateUnit(0x40, 0, *(u16 *)p);
    *(struct Bank **)(p + 0x1AC) = bank;
    CLACT_SetUnitDefaultRenderer(bank);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | (mode << 13);
    inside0(0x1f, 1);
    inside1(0x1f, 1);
    outside(0x13, 1);
    *(volatile u16 *)0x04000040 = 0xff;
    *(volatile u16 *)0x04000044 = 0xc0;
    *(volatile u16 *)0x04000042 = 0x20 << 10;
    *(volatile u16 *)0x04000046 = 0xc0;
}
