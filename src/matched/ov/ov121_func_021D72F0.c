/*
 * function: MYSTERY_TaskMenuAction
 * address: 0x021D72F0
 * packet: pkt_ov121_021D72F0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_CreateCardMenu 0x021D81B0 thumb ov121
 *   MYSTERY_PollCardMenu 0x021D83B0 thumb ov121
 *   MYSTERY_DeleteCardMenu 0x021D8380 thumb ov121
 *   MYSTERY_UTIL_SetTaskArg 0x021DA8C0 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_UTIL_GetMenuState 0x021D9FF8 thumb ov121
 *   MYSTERY_UTIL_GetTaskArg 0x021DA8C4 thumb ov121
 *   MYSTERY_TaskMenu 0x021D6E3C thumb ov121
 */
#include "../include/Obj00326.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d);
extern void MYSTERY_CreateCardMenu(u8 *p, u32 which, int heap);
extern int MYSTERY_PollCardMenu(char *p);
extern void MYSTERY_DeleteCardMenu(char *p);
extern void MYSTERY_UTIL_SetTaskArg(u32 *p, u32 a);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
extern void MYSTERY_UTIL_GetTaskArg(u32 *p);
extern void MYSTERY_TaskMenu(void *task, u32 *state, u8 *p);
void MYSTERY_TaskMenuAction(void *a, int *state, char *p)
{
    int result;
    switch (*state) {
    case 0:
        MYSTERY_UTIL_SetMenuMessage(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 126, 0);
        MYSTERY_CreateCardMenu((u8 *)p, 3, 29);
        *state = 2;
        break;
    case 2:
        result = MYSTERY_PollCardMenu(p);
        if (result == -1) break;
        MYSTERY_DeleteCardMenu(p);
        if (result == 0) {
            MYSTERY_UTIL_SetMenuMessage(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 132, 1);
            MYSTERY_UTIL_SetTaskArg(a, 0);
            *state = 3;
        } else if (result == 1) {
            MYSTERY_UTIL_SetMenuMessage(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 133, 1);
            MYSTERY_UTIL_SetTaskArg(a, 0);
            *state = 3;
        } else if (result == 2) {
            MYSTERY_UTIL_SetMenuMessage(((struct Obj00326 *)p)->f284, ((struct Obj00326 *)p)->f3A4, 134, 1);
            MYSTERY_UTIL_SetTaskArg(a, 0);
            *state = 3;
        } else if (result == 3) {
            MYSTERY_UTIL_SetTaskHandler(a, (u32)MYSTERY_TaskMenu);
        }
        break;
    case 3:
        if (MYSTERY_UTIL_GetMenuState(((struct Obj00326 *)p)->f284)) MYSTERY_UTIL_GetTaskArg(a);
        break;
    }
}
