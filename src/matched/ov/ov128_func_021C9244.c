/*
 * function: WF2DMAP_TOUCH_FriendEditScreen
 * address: 0x021C9244
 * packet: pkt_ov128_021C9244
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed halfword switch offsets map cases 0 and 1 to a shared
 * setup tail; case 0 clears the two halfwords before falling through.
 * symbols:
 *   WF2DMAP_TOUCH_StartFriendEdit 0x021C9238 thumb ov128
 *   WF2DMAP_TOUCH_InitEditScreen 0x021C97A0 thumb ov128
 *   WF2DMAP_TOUCH_GetMenuInput 0x021C9544 thumb ov128
 *   WF2DMAP_TOUCH_StartEditAnim 0x021C958C thumb ov128
 *   WF2DMAP_TOUCH_StepSlideIn 0x021C95CC thumb ov128
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   WF2DMAP_TOUCH_FindPrevEntry 0x021C9D0C thumb ov128
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WF2DMAP_TOUCH_ReleaseEditWidgets 0x021C98EC thumb ov128
 *   Wf2dmapFriend_SetState 0x021C6438 thumb ov128
 *   WF2DMAP_TOUCH_DeleteEditWidgets 0x021C9730 thumb ov128
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   WF2DMAP_TOUCH_CloseEditScreen 0x021C987C thumb ov128
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
#include "../include/Obj00773.h"
#include "../include/Obj10491.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WF2DMAP_TOUCH_StartFriendEdit(char *p, void *b, void *c, void *d);
extern void WF2DMAP_TOUCH_InitEditScreen(u8 *,u8 *,u8 *,u16);
extern int WF2DMAP_TOUCH_GetMenuInput(void *,int *,char *);
extern void WF2DMAP_TOUCH_StartEditAnim(char *,void *,void *,int);
extern int WF2DMAP_TOUCH_StepSlideIn(u8 *,void *,void *,int);
struct Actor;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);
extern int WF2DMAP_TOUCH_FindPrevEntry(u8 *,int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void WF2DMAP_TOUCH_ReleaseEditWidgets(char *p, u8 *q);
extern void Wf2dmapFriend_SetState(u8 *,u8,u8);
extern void WF2DMAP_TOUCH_DeleteEditWidgets(u8 *,void *,u8 *);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void WF2DMAP_TOUCH_CloseEditScreen(u8 *,u8 *);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 WIPE_SYS_EndCheck(void);
int WF2DMAP_TOUCH_FriendEditScreen(u8 *p,u8 *q,u8 *r,u16 heap)
{
    switch(q[8]) {
    case 0:
        ((struct Obj00773 *)p)->fE=0; ((struct Obj00773 *)p)->f0=0;
    case 1:
        WF2DMAP_TOUCH_StartFriendEdit((char *)p,q,r,(void *)heap);
        WF2DMAP_TOUCH_InitEditScreen(p,q,r,heap);
        q[8]=2;
        break;
    case 2: q[8]=WF2DMAP_TOUCH_GetMenuInput(p,(int *)q,(char *)r); break;
    case 3:
        WF2DMAP_TOUCH_StartEditAnim((char *)p,q,r,heap);
        WF2DMAP_TOUCH_StepSlideIn(p,q,r,heap);
        q[8]=4; break;
    case 4: if(WF2DMAP_TOUCH_StepSlideIn(p,q,r,heap)==1)q[8]=5; break;
    case 5:
        if(PRINTSYS_QUE_IsFinished(((struct Obj10491 *)r)->f34)==1) {
            BG_SYS_ResetSlot(2,0,0);BG_SYS_ResetSlot(3,0,0);q[8]=2;
        } break;
    case 6:
        if(((struct Obj00773 *)p)->fE) {
            --((struct Obj00773 *)p)->fC;
            if(((struct Obj00773 *)p)->fC)break;
        }
        if(WF2DMAP_TOUCH_FindPrevEntry(q,((struct Obj00773 *)p)->f8)) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            WF2DMAP_TOUCH_ReleaseEditWidgets((char *)p,r);
            Wf2dmapFriend_SetState(q,4,1);
            ((struct Obj00773 *)p)->fE=1;
            WF2DMAP_TOUCH_DeleteEditWidgets(p,q,r);
            return 1;
        } else q[8]=2;
        break;
    case 7:
        if(CLACT_IsActorAnimActive(((struct Obj10491 *)r)->f164)!=1) {
            WF2DMAP_TOUCH_CloseEditScreen(p,r);
            Wf2dmapFriend_SetState(q,1,11);
            WF2DMAP_TOUCH_DeleteEditWidgets(p,q,r);
            return 1;
        } break;
    case 8: if(CLACT_IsActorAnimActive(((struct Obj10491 *)r)->f168)!=1)q[8]=9; break;
    case 9: WIPE_SYS_Start(0,0,0,0,6,1,heap);q[8]=10;break;
    case 10: if(WIPE_SYS_EndCheck()) {
        Wf2dmapFriend_SetState(q,6,0);WF2DMAP_TOUCH_DeleteEditWidgets(p,q,r);return 1;
        }break;
    }
    return 0;
}
