/*
 * function: STARTMENU_ConfigPromptSetupGraphics
 * address:  0x021BC62C
 * packet:   pkt_ov088_021BC62C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   STARTMENU_InitBgLayer  0x021BC734  thumb  ov088
 *   BMP_WIN_Init  0x02045088  arm
 *   func_02049B40  0x02049B40  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_0201F5BC  0x0201F5BC  thumb
 *   FADE_Start  0x0204E720  arm
 *   d_021BD8B8     0x021BD8B8  data  ov088  a4
 *   d_021BD848     0x021BD848  data  a4
 *   d_021BD858     0x021BD858  data  a4
 *   d_021BD878     0x021BD878  data  a4
 *   d_021BD898     0x021BD898  data  a4
 *
 * The POWCNT clear is spelled `& ~0x8000` (the SDK display-select inline):
 * the original pools 0xFFFF7FFF, where `&= 0x7FFF` derives the mask from
 * the -16 already in a register.  The four ov088 data hints were contested
 * or unwitnessed with the ov088 token; without it they resolve as sole-ref.
 */
#include "../include/Obj20830.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct GfFont;
extern void func_0207D534(volatile u16 *reg, int brightness);
typedef signed int     s32;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void STARTMENU_InitBgLayer(const void *p, int bg);
extern void BMP_WIN_Init(u16 heapId);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern char d_021BD8B8[];
extern char d_021BD848[];
extern char d_021BD858[];
extern char d_021BD878[];
extern char d_021BD898[];

void STARTMENU_ConfigPromptSetupGraphics(char *p)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BD8B8);
    func_0203F8F4(0x39);
    func_0203FC28((struct DispConfig *)d_021BD848);
    *(u16 *)0x04000304 = (u16)(*(u16 *)0x04000304 & ~0x8000);
    STARTMENU_InitBgLayer(d_021BD858, 3);
    STARTMENU_InitBgLayer(d_021BD878, 1);
    STARTMENU_InitBgLayer(d_021BD898, 5);
    BMP_WIN_Init(0x39);
    func_02049B40(0x17, 5, 0, 0, 0x20, 0x39);
    func_02049B40(0x17, 5, 4, 0, 0x20, 0x39);
    ((struct Obj20830 *)p)->f8 = (u32)GF_FONT_Create(0x17, 0, 0, 0, 0x39);
    func_0201F5BC(1, 1, 3, 0, 0x39);
    func_0201F5BC(1, 0x1f, 4, 0, 0x39);
    func_0201F5BC(5, 1, 1, 0, 0x39);
    *(u16 *)0x05000000 = 0x7D8C;
    *(u16 *)0x05000400 = 0x7D8C;
    FADE_Start(3, 0x10, 0, 0);
}
