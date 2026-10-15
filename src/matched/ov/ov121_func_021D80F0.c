/*
 * function: MYSTERY_TaskMessage
 * address: 0x021D80F0
 * packet: pkt_ov121_021D80F0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_UTIL_GetMenuState 0x021D9FF8 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_TaskMenu 0x021D6E3C thumb ov121
 */
#include "../include/Obj10409.h"
typedef unsigned char u8;
extern void MYSTERY_UTIL_SetMenuMessage(u8 *, int, int, int);
typedef unsigned int   u32;
extern unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern void MYSTERY_TaskMenu(void *task, u32 *state, u8 *p);
void MYSTERY_TaskMessage(void *a, int *state, u8 *p)
{
    switch (*state) {
    case 0: MYSTERY_UTIL_SetMenuMessage(*(u8 * *)&((struct Obj10409 *)p)->f284, ((struct Obj10409 *)p)->f3A0, 22, 1); *state = 1; break;
    case 1: if (MYSTERY_UTIL_GetMenuState(((struct Obj10409 *)p)->f284)) MYSTERY_UTIL_SetTaskHandler(a, (u32)MYSTERY_TaskMenu); break;
    }
}
