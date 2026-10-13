/*
 * function: ITEMMENU_TaskInputGuardMessage
 * address:  0x021B8EA8
 * packet:   pkt_ov070_021B8EA8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   ITEMMENU_SortAndRedraw  0x021B809C  thumb  ov070
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   ITEMMENU_ShowMessage  0x021BACF0  thumb  ov070
 *   ITEMMENU_SetBackButtonAnim  0x021BB580  thumb  ov070
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskWaitMessageThenList  0x021B8F0C  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Actor;
struct MsgBank;
struct Obj;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void ITEMMENU_SortAndRedraw(u8 *p);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void ITEMMENU_ShowMessage(int p, int mode);
extern void ITEMMENU_SetBackButtonAnim(char *p, int v);
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskWaitMessageThenList(int p);

void ITEMMENU_TaskInputGuardMessage(int p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(*(int *)&((struct Obj00002 *)p)->f72C)) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C), 0);
        ITEMMENU_SortAndRedraw((u8 *)p);
        CLACT_SetActorAutoAnim((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 0);
        MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00002 *)p)->f51C), 0x8A, (void *)(*(int *)&((struct Obj00002 *)p)->f528));
        ITEMMENU_ShowMessage(p, 0);
        ITEMMENU_SetBackButtonAnim((char *)p, 0);
        ITEMMENU_UpdateSideButtons(p, 0);
        ITEMMENU_SetTask((char *)p, (int)ITEMMENU_TaskWaitMessageThenList);
    }
}
