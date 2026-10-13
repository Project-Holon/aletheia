/*
 * function: func_021D43F8
 * address: 0x021D43F8
 * packet: pkt_ov124_021D43F8
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display read-modify-writes 021D440E/021D4416, 021D4418/021D441C; POWCNT1 021D443E/021D4444.
 * symbols:
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_021D4534 0x021D4534 thumb ov124
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021D4CC4 0x021D4CC4 data a4
 *   d_021D4BF4 0x021D4BF4 data a4
 *   d_021D4C44 0x021D4C44 data a4
 *   d_021D4C64 0x021D4C64 data a4
 *   d_021D4C84 0x021D4C84 data a4
 *   d_021D4C24 0x021D4C24 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   WIPE_ResetWndMask  0x02022224  thumb  arm9
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb  arm9
 */
#include "../include/Obj00068.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b; u8 c, d, e, f; u32 g; u16 h, i, j, k, l, m; } Config;
extern const Config gClActorInitParam;
extern const u32 d_021D4CC4[], d_021D4BF4[], d_021D4C44[], d_021D4C64[], d_021D4C84[], d_021D4C24[];
extern void BG_SYS_ResetSubDisplay(void), BG_SYS_ClearMainPlanes(void), BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
extern u32 WIPE_ResetWndMask(void *);
struct Cfg;
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203F8F4(u16), BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *cfg);
struct BgTemplate;
extern void func_021D4534(const struct BgTemplate *p, int layer, int type);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
static inline void visible(int plane)
{
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x1f00) | (plane << 8);
}
static inline void subvisible(int plane)
{
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00) | (plane << 8);
}
void func_021D43F8(char *p)
{
    Config cfg;
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    visible(0);
    subvisible(0);
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021D4CC4);
    func_0203F8F4(((struct Obj00068 *)p)->f0);
    BMP_WIN_Init(((struct Obj00068 *)p)->f0);
    func_0203FC28((struct DispConfig *)d_021D4BF4);
    func_021D4534((const struct BgTemplate *)d_021D4C44, 4, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C64, 5, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C84, 6, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C24, 7, 0);
    func_0207D63C(0x04001050, 4, 8, 15, 4);
    cfg = gClActorInitParam;
    cfg.h = 0x40;
    CLACT_InitSystem((const struct Cfg *)(&cfg), (u32)d_021D4CC4, ((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f4C = CLACT_CreateUnit(0x30, 0, ((struct Obj00068 *)p)->f0);
    CLACT_SetUnitDefaultRenderer(((struct Obj00068 *)p)->f4C);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
