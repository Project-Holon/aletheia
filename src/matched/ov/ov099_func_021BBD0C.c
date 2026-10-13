/*
 * function: WIFICLUB_LoadPartyIcons
 * address:  0x021BBD0C
 * packet:   pkt_ov099_021BBD0C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   WIFICLUB_CreatePartyIcons  0x021BBC34  thumb  ov099
 *   WIFICLUB_FreezePartyIcons  0x021BBE50  thumb  ov099
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj03731.h"

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0201BC3C(void);
typedef signed int     s32;
typedef unsigned int   u32;
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void WIFICLUB_CreatePartyIcons(char *p, void *a, int k, u32 o);
extern void WIFICLUB_FreezePartyIcons(void *p);
extern void ARC_TOOL_DeleteHandle(void *o);

void WIFICLUB_LoadPartyIcons(char *p, int a, int b)
{
    void *o;
    int t;

    o = func_020490F4(7, 0x21);
    ((struct Obj03731 *)p)->f148 = (void *)CLACT_RegisterPaletteCompressed(o, func_0201BC3C(), 0, 0x160, 0x21);
    t = func_0201BC78();
    ((struct Obj03731 *)p)->f14C = (void *)CLACT_RegisterCellAnim(o, t, func_0201BCB4(), 0x21);
    WIFICLUB_CreatePartyIcons(p, (void *)a, 0, (u32)o);
    WIFICLUB_CreatePartyIcons(p, (void *)b, 6, (u32)o);
    WIFICLUB_FreezePartyIcons(p);
    ARC_TOOL_DeleteHandle(o);
}
