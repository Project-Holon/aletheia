/*
 * function: IRC_COMPATIBLE_MENU_HandleOpen
 * address: 0x021B8320
 * packet: pkt_ov102_021B8320
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_MENU_PrintMessage 0x021B7DFC thumb ov102
 *   COMPATIBLE_IRC_SYS_ClearValues 0x021B63C4 thumb ov101
 *   COMPATIBLE_IRC_SYS_ResetStep 0x021B63BC thumb ov101
 *   COMPATIBLE_IRC_SYS_StepShutdown 0x021B61E8 thumb ov101
 *   IRC_COMPATIBLE_MENU_SetHandler 0x021B7F08 thumb ov102
 *   IRC_COMPATIBLE_MENU_HandleChoice 0x021B81B0 thumb ov102
 */
#include "../include/Obj10237.h"
#include "../include/Obj22152.h"
#include "../include/Obj22153.h"
#include "../include/Obj22154.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void IRC_COMPATIBLE_MENU_PrintMessage(u8 *, void *, int, int, s16);
extern void COMPATIBLE_IRC_SYS_ClearValues(int *);
extern void COMPATIBLE_IRC_SYS_ResetStep(int *);
struct Obj;
extern int COMPATIBLE_IRC_SYS_StepShutdown(struct Obj *o);
extern void IRC_COMPATIBLE_MENU_SetHandler(unsigned p, unsigned x);
extern void IRC_COMPATIBLE_MENU_HandleChoice(u8 *, u16 *);
void IRC_COMPATIBLE_MENU_HandleOpen(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        IRC_COMPATIBLE_MENU_PrintMessage(p + 0xac, p + 0x9c, 5, 0, 0);
        COMPATIBLE_IRC_SYS_ClearValues(*(int * *)&((struct Obj22152 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4);
        COMPATIBLE_IRC_SYS_ResetStep(*(int * *)&((struct Obj22153 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4);
        *state = 1;
        break;
    case 1:
        if (COMPATIBLE_IRC_SYS_StepShutdown((struct Obj *)(*(int * *)&((struct Obj22154 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4)))
            *state = 2;
        break;
    case 2:
        IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p, (unsigned int)IRC_COMPATIBLE_MENU_HandleChoice);
        break;
    }
}
