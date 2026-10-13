/*
 * function: ITEMMENU_TaskWaitSideButtonPress
 * address: 0x021B8CB4
 * packet: pkt_ov070_021B8CB4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   ITEMMENU_SetTask 0x021B6100 thumb ov070
 */
#include "../include/Obj00002.h"
typedef unsigned short u16;
typedef void (*Callback)(void *);
typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void ITEMMENU_SetTask(char *p, int k);
void ITEMMENU_TaskWaitSideButtonPress(char *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(*(int *)(p + 0x710 + ((struct Obj00002 *)p)->f864 * 4))) == 0) {
        ((struct Obj00002 *)p)->f864 = 0;
        ITEMMENU_SetTask(p, (int)(*(Callback *)&((struct Obj00002 *)p)->f868));
    }
}
