/*
 * function: MYSTERY_TaskInitSave
 * address: 0x021D6D80
 * packet: pkt_ov121_021D6D80
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_CreateCardMenu 0x021D81B0 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_TaskFadeToMenu 0x021D6DB4 thumb ov121
 */
#include "../include/Obj00326.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MYSTERY_UTIL_SetMenuMessage(u8 *,int,int,int);
extern void MYSTERY_CreateCardMenu(u8 *,u32,int);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern void MYSTERY_TaskFadeToMenu(void *,int *);
void MYSTERY_TaskInitSave(void *a,int b,u8 *p)
{
    MYSTERY_UTIL_SetMenuMessage(*(u8 * *)&((struct Obj00326 *)p)->f284,((struct Obj00326 *)p)->f3A4,79,0);
    MYSTERY_CreateCardMenu(p,0,29);
    MYSTERY_UTIL_SetTaskHandler(a,(u32)MYSTERY_TaskFadeToMenu);
}
