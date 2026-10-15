/*
 * function: POKE_SUMMARY_ACTOR_WaitDecide
 * address: 0x021B8110
 * packet: pkt_ov173_021B8110
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   POKE_SUMMARY_ACTOR_ToggleTaskMenu 0x021B7EB0 thumb ov173
 */
#include "../include/Obj05452.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void POKE_SUMMARY_ACTOR_ToggleTaskMenu(char *p, int flag);
int POKE_SUMMARY_ACTOR_WaitDecide(u8 *p)
{
    u8 *s;
    s=p+464;
    if(((struct Obj05452 *)s)->fA==0) {
        if(CLACT_IsActorAnimActive(*(void **)(p+260+((struct Obj05452 *)s)->f6*4))==0) return ((struct Obj05452 *)s)->f8;
    } else if(((struct Obj05452 *)s)->fA==1) {
        if(APP_TASKMENU_WIN_IsFinish(*(void **)(p+544+((struct Obj05452 *)s)->f6*4))!=0) {
            POKE_SUMMARY_ACTOR_ToggleTaskMenu((char *)p,0);
            return ((struct Obj05452 *)s)->f8;
        }
    }
    return 13;
}
