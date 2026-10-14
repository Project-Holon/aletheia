/*
 * function: BTLV_SCU_SetupDisplay
 * address: 0x021EB028
 * packet: pkt_ov093_021EB028
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   PALANM_LoadArcPaletteToSlotAt 0x020215EC thumb
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   func_02041300 0x02041300 arm
 *   func_02040C14 0x02040C14 arm
 *   BTLV_SCU_LoadArcTiles 0x021EB1D8 thumb ov093
 *   func_0204989C 0x0204989C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BTLV_SCU_InitMsgWinFade 0x021ED76C thumb ov093
 *   BTLV_SCU_InitMonSlots 0x021ED930 thumb ov093
 *   BTLV_SCU_InitNamePlates 0x021EDB3C thumb ov093
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   gBtlvScuBgTemplateMsg 0x021F3930 data a4
 *   gBtlvScuBgTemplateName 0x021F3950 data a4
 *   gBtlvScuBgTemplateBack 0x021F3970 data a4
 */
#include "../include/Obj00970.h"
#include "../include/G__anon_V.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate;
extern struct _anon_V gBtlvScuBgTemplateBack;
extern const struct BgTemplate gBtlvScuBgTemplateMsg, gBtlvScuBgTemplateName;
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
struct S;
extern int BTLV_EFFECT_GetPalanm(void);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct PalAnmSlot;
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02040C14(u32, u32, u32, u32);
extern u16 BTLV_SCU_LoadArcTiles(u8 *, u32, u32, u32);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_DrawFrame(struct Cfg *cfg, u16 base, u32 pal);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BTLV_SCU_InitMsgWinFade(struct S *s, int a);
extern void BTLV_SCU_InitMonSlots(char *s);
extern void BTLV_SCU_InitNamePlates(struct S *s, char *a1);
extern void func_020409B4(u32 index);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

void BTLV_SCU_SetupDisplay(u8 *p)
{
    u16 zero;
    u32 tile;
    func_0203FCA0(1, &gBtlvScuBgTemplateMsg, 0);
    func_0203FCA0(2, &gBtlvScuBgTemplateName, 0);
    func_0203FCA0(3, &(*(struct BgTemplate *)&gBtlvScuBgTemplateBack), 0);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), 0xb, 0x5a, ((struct Obj00970 *)p)->f13C, 0, 0x20, 0, 0);
    PALANM_LoadArcPaletteToSlotAt((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), 0xb, 0xd6, ((struct Obj00970 *)p)->f13C, 0, 0x60, 0x10, 0x10);
    zero = 0;
    PALANM_CopyToSlot((struct PalAnmSlot *)BTLV_EFFECT_GetPalanm(), &zero, 0, 0, 2);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02040C14(1, 0, 1, 0);
    tile = BTLV_SCU_LoadArcTiles(p, 0xb, 0x59, 1);
    *(u32 *)&((struct Obj00970 *)p)->f14 = BTLV_SCU_LoadArcTiles(p, 0xb, 0xd5, 3);
    func_0204989C(0xb, 0xd7, 2, 0, 0, 0, ((struct Obj00970 *)p)->f13C);
    func_0204989C(0xb, 0xd8, 3, 0, 0, 0, ((struct Obj00970 *)p)->f13C);
    ((struct Obj00970 *)p)->f0 = (void *)BMP_WIN_Create(1, 1, 0x13, 0x1e, 4, 0, 0);
    ((struct Obj00970 *)p)->f4 = BMP_WIN_GetBmp(((struct Obj00970 *)p)->f0);
    BMP_WIN_MakeScreen(((struct Obj00970 *)p)->f0);
    BMP_WIN_DrawFrame(((struct Obj00970 *)p)->f0, tile, 0);
    BMP_Clear(((struct Obj00970 *)p)->f4, 0xc);
    BMP_WIN_TransferChars(((struct Obj00970 *)p)->f0);
    ((struct Obj00970 *)p)->f10 = BTLV_SCU_LoadArcTiles(p, 0xb, 0xdd, 3);
    ((struct Obj00970 *)p)->f8 = (void *)BMP_WIN_Create(3, 0x15, 0x25, 0xa, 0xc, 3, 0);
    ((struct Obj00970 *)p)->fC = BMP_WIN_GetBmp(((struct Obj00970 *)p)->f8);
    BTLV_SCU_InitMsgWinFade((struct S *)(p + 0x154), (int)(((struct Obj00970 *)p)->f0));
    BTLV_SCU_InitMonSlots((char *)p);
    BTLV_SCU_InitNamePlates((struct S *)p, ((struct Obj00970 *)p)->f14);
    func_020409B4(1);
    func_020409B4(2);
    func_020409B4(3);
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
}
