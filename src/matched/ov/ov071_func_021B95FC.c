/*
 * function: MONOLITH_TOOL_LIST_LoadGraphics
 * address:  0x021B95FC
 * packet:   pkt_ov071_021B95FC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020498F4  0x020498F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020490F4  0x020490F4  arm
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   APP_ICON_LoadTouchBar  0x02027634  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../include/Obj09894.h"
#include "../include/Obj09895.h"

typedef unsigned int u32;

typedef unsigned short u16;

extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top);
extern void APP_ICON_LoadTouchBar(void *arc, int id, u32 heap, int base, u32 pal);
extern void ARC_TOOL_DeleteHandle(void *a);
extern void func_020409B4(u32 a);

void MONOLITH_TOOL_LIST_LoadGraphics(void *a, void *b)
{
    char *d = (char *)a;
    char *r5 = (char *)b;
    void *h;

    func_020498F4(((struct Obj09895 *)r5)->f30, 7, 6, 0, 0, 1, 0x61);
    func_02049658(((struct Obj09895 *)r5)->f30, 0xe, 5, 0, 0, 1, 0x61);
    func_020498F4(((struct Obj09895 *)r5)->f30, 9, 5, 0, 0, 1, 0x61);
    h = func_020490F4(0x53, 0x61);
    ((struct Obj09894 *)d)->f4 = (void *)BG_SYS_CreateRun(5, 0x80, 1);
    func_02049658(h, 0x1c, 5, (u32)(((struct Obj09894 *)d)->f4), 0x80, 0, 0x61);
    APP_ICON_LoadTouchBar(h, 5, 0x61, (int)(((struct Obj09894 *)d)->f4), 0xc);
    ARC_TOOL_DeleteHandle(h);
    func_020409B4(5);
    func_020409B4(6);
}
