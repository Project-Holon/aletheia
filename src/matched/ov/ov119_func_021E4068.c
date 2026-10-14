/*
 * function: POKETRADE_2D_RegisterIconCharResources
 * address: 0x021E4068
 * packet: pkt_ov119_021E4068
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj03780.h"
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
extern u32 func_020275E4(void);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
void POKETRADE_2D_RegisterIconCharResources(char *p)
{
    void *v;
    int a;
    if (((struct Obj03780 *)p)->f888 == 0) {
        v = func_020490F4(func_020275E4(), ((struct Obj03780 *)p)->f5F4);
        ((struct Obj03780 *)p)->f8A4 = CLACT_RegisterCharacter(v, func_02027618(), 0, 1, ((struct Obj03780 *)p)->f5F4);
        ((struct Obj03780 *)p)->f888 = CLACT_RegisterPaletteEx(v, func_02027614(), 1, 0, 0, 3, ((struct Obj03780 *)p)->f5F4);
        a = func_0202761C(2);
        ((struct Obj03780 *)p)->f8B8 = CLACT_RegisterCellAnim(v, a, func_02027620(2), ((struct Obj03780 *)p)->f5F4);
        ARC_TOOL_DeleteHandle(v);
    }
}
