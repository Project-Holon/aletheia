/*
 * function: C_GEAR_Open
 * address:  0x021F27D8
 * packet:   pkt_ov029_021F27D8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_Create  0x021F279C  thumb  ov029
 *   C_GEAR_ChangeStep  0x021EFEF8  thumb  ov029
 *   C_GEAR_StepOpen  0x021F21F8  thumb  ov029
 *   func_020056EC  0x020056EC  thumb
 *   C_GEAR_LoadSkinMember  0x021F3190  thumb  ov029
 *   C_GEAR_UpdateTileMarkers  0x021F20AC  thumb  ov029
 */
#include "../include/Obj03633.h"

typedef unsigned int   u32;
extern void *C_GEAR_Create(int a, int b, int c, int d);
extern void C_GEAR_ChangeStep(char *p, void (*f)(void), int a);
extern void C_GEAR_StepOpen(char *p);
extern u32 func_020056EC(u32 range);
extern void C_GEAR_LoadSkinMember(int a, int b, int c, int d);
extern void C_GEAR_UpdateTileMarkers(char *p);

char *C_GEAR_Open(int a0, int a1, int a2, void (*cb)(int), int arg, int flag)
{
    char *p = C_GEAR_Create(a0, a1, a2, flag);

    *(void (**)(int))(p + 0x1fc) = cb;
    ((struct Obj03633 *)p)->f200 = arg;
    if (flag != 0) {
        C_GEAR_ChangeStep(p, (void (*)(void))C_GEAR_StepOpen, 0x1160);
        ((struct Obj03633 *)p)->f45B = 0;
    } else {
        if (*(void (**)(int))(p + 0x1fc) != 0)
            (*(void (**)(int))(p + 0x1fc))(((struct Obj03633 *)p)->f200);
        *(int *)&((struct Obj03633 *)p)->f1FC = 0;
        ((struct Obj03633 *)p)->f200 = 0;
    }
    C_GEAR_LoadSkinMember(a0, ((struct Obj03633 *)p)->f24, func_020056EC(10), 0x70);
    C_GEAR_UpdateTileMarkers(p);
    return p;
}
