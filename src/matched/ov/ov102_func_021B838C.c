/*
 * function: IRC_COMPATIBLE_MENU_HandleQuit
 * address: 0x021B838C
 * packet: pkt_ov102_021B838C
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_ClearValues 0x021B63C4 thumb ov101
 *   COMPATIBLE_IRC_SYS_ResetStep 0x021B63BC thumb ov101
 *   COMPATIBLE_IRC_SYS_StepShutdown 0x021B61E8 thumb ov101
 *   IRC_COMPATIBLE_MENU_SetFinished 0x021B7F18 thumb ov102
 */
#include "../include/Obj07976.h"
#include "../include/Obj22155.h"
#include "../include/Obj22156.h"
#include "../include/Obj22157.h"
#include "../include/Obj22158.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void COMPATIBLE_IRC_SYS_ClearValues(int *);
extern void COMPATIBLE_IRC_SYS_ResetStep(int *);
struct Obj;
extern int COMPATIBLE_IRC_SYS_StepShutdown(struct Obj *o);
extern void IRC_COMPATIBLE_MENU_SetFinished(u8 *);
void IRC_COMPATIBLE_MENU_HandleQuit(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        *state = 1;
        COMPATIBLE_IRC_SYS_ClearValues(*(int * *)&((struct Obj22155 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4);
        COMPATIBLE_IRC_SYS_ResetStep(*(int * *)&((struct Obj22156 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4);
        break;
    case 1:
        if (COMPATIBLE_IRC_SYS_StepShutdown((struct Obj *)(*(int * *)&((struct Obj22157 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4)))
            *state = 2;
        break;
    case 2:
        ((struct Obj22158 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->fC = 2;
        IRC_COMPATIBLE_MENU_SetFinished(p);
        break;
    }
}
