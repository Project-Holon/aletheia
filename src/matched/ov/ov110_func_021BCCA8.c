/*
 * function: PMSIV_MENU_UpdateItemHighlight
 * address: 0x021BCCA8
 * packet: pkt_ov110_021BCCA8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_GetSentenceType 0x021BF6E4 thumb ov110
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   PMSIV_MENU_StopItemBlend 0x021BD470 thumb ov110
 *   PMSIV_MENU_SetItemAnim 0x021BD0F8 thumb ov110
 *   PMSIV_MENU_StartItemBlend 0x021BD448 thumb ov110
 *   gPmsivMenuItemAnimSeq 0x021C38DF data a1
 *   gPmsivMenuItemOrder 0x021C38D4 data a1
 */
#include "../include/Obj13784.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x70]; void *items[8]; } Object;
extern int PMS_INPUT_GetSentenceType(u8 *p);
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void PMSIV_MENU_StopItemBlend(u8 *p, int i);
extern void PMSIV_MENU_SetItemAnim(u8 *p, int i, int flag);
extern void PMSIV_MENU_StartItemBlend(u8 *p, int i);
extern const u8 gPmsivMenuItemAnimSeq[],gPmsivMenuItemOrder[];
void PMSIV_MENU_UpdateItemHighlight(Object *p) {
    int old,new;
    int selected;
    int i;
    int state;
    old=-1; new=-1;
    selected=PMS_INPUT_GetSentenceType(((struct Obj13784 *)p)->f4);
    for(i=1;i<=5;i++) {
        state=CLACT_GetActorAnimSeq(p->items[i]);
        if(state==gPmsivMenuItemAnimSeq[i*2+1]) { old=i; break; }
    }
    for(i=0;i<5;i++) {
        if(i==selected) { new=gPmsivMenuItemOrder[i]; break; }
    }
    if(old>=0 && old!=new) PMSIV_MENU_StopItemBlend((u8 *)p,old);
    for(i=0;i<5;i++) PMSIV_MENU_SetItemAnim((u8 *)p,gPmsivMenuItemOrder[i],i==selected);
    if(new>=0 && old!=new) PMSIV_MENU_StartItemBlend((u8 *)p,new);
}
