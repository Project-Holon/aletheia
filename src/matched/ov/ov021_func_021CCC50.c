/*
 * function: PARTY_SELECT_LIST_LoadStatusIconResources
 * address:  0x021CCC50
 * packet:   pkt_ov021_021CCC50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02027694  0x02027694  thumb
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   func_0202769C  0x0202769C  thumb
 *   func_020276A0  0x020276A0  thumb
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   func_02027698  0x02027698  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj04293.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02027694(void);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_0202769C(u32 a);
extern u32 func_020276A0(u32 a);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027698(void);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *h);

void PARTY_SELECT_LIST_LoadStatusIconResources(u8 *p)
{
    void *h;
    u32 a;
    u32 b;

    h = func_020490F4(0x53, ((struct Obj04293 *)p)->fC);
    ((struct Obj04293 *)p)->f98 = CLACT_RegisterPaletteEx(h, func_02027694(), 0, 0xc0, 0, 1, ((struct Obj04293 *)p)->fC);
    a = func_0202769C(1);
    b = func_020276A0(1);
    ((struct Obj04293 *)p)->f9A = CLACT_RegisterCellAnim(h, a, b, ((struct Obj04293 *)p)->fC);
    ((struct Obj04293 *)p)->f9C = CLACT_RegisterCharacter(h, func_02027698(), 0, 0, ((struct Obj04293 *)p)->fC);
    ARC_TOOL_DeleteHandle(h);
}
