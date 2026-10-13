/*
 * function: IRCBATTLEMENU_LoadActorResources
 * address:  0x02196FFC
 * packet:   pkt_ov021_02196FFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds three objects on one owner handle and stores them at +0x274,
 * +0x27C and +0x284.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04220.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterCharacter(void *h, u32 b, u32 c, u32 d, u16 e);
extern s32 CLACT_RegisterPaletteEx(void *h, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *h, u32 b, u32 c, u32 d);
extern void ARC_TOOL_DeleteHandle(void *h);

void IRCBATTLEMENU_LoadActorResources(u8 *p)
{
    void *h = func_020490F4(0x1D, ((struct Obj04220 *)p)->f10);

    ((struct Obj04220 *)p)->f27C = CLACT_RegisterCharacter(h, 5, 0, 1, ((struct Obj04220 *)p)->f10);
    ((struct Obj04220 *)p)->f274 = CLACT_RegisterPaletteEx(h, 3, 1, 0, 0, 0xA, ((struct Obj04220 *)p)->f10);
    ((struct Obj04220 *)p)->f284 = CLACT_RegisterCellAnim(h, 7, 0x10, ((struct Obj04220 *)p)->f10);
    ARC_TOOL_DeleteHandle(h);
}
