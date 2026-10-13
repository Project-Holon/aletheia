/*
 * function: MONOLITH_TOOL_LIST_InitWindows
 * address:  0x021B96A4
 * packet:   pkt_ov071_021B96A4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F554  0x0201F554  thumb
 *   func_0201F548  0x0201F548  thumb
 *   PALANM_LoadArcPaletteToSlotAt  0x020215EC  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../include/Obj04341.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Cfg;
struct CharBuf;
struct Descriptor;
struct PalAnmSlot;
extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
extern u8 func_0201F548(int i);
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_020409B4(u32 a);

void MONOLITH_TOOL_LIST_InitWindows(char *a, void **b)
{
    func_0201F554(4, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(*b, 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    ((struct Obj04341 *)a)->f280 = (void *)BMP_WIN_Create(4, 1, 0x13, 0x1e, 4, 0xd, 1);
    BMP_Clear(func_02045770(((struct Obj04341 *)a)->f280), 0xff);
    ((struct Obj04341 *)a)->f284 = (void *)BMP_WIN_Create(4, 0, 0, 0x20, 3, 0xd, 1);
    BMP_WIN_MakeScreen(((struct Obj04341 *)a)->f284);
    func_020409B4(4);
    ((struct Obj04341 *)a)->f288 = ((struct Obj04341 *)a)->f284;
    ((struct Obj04341 *)a)->f28C = 0;
}
