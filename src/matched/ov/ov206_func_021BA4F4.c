/*
 * unit: yes
 * function: ZUKAN_INFO_ClearActors,ZUKAN_INFO_NotifyMoveDone,ZUKAN_INFO_NotifyFadeDone,ZUKAN_INFO_IsMoving,ZUKAN_INFO_IsDone,ZUKAN_INFO_Start
 * address: 0x021BA4F4
 * packet: pkt_ov206_021BA4F4
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_INFO_ClearSlotWindows 0x021BAF50 thumb ov206
 *   ZUKAN_INFO_DeleteActorPair 0x021BBBD8 thumb ov206
 *   ZUKAN_INFO_DeleteRow 0x021BB92C thumb ov206
 */
#include "../include/Obj14635.h"
#include "../include/Obj14636.h"
#include "../include/Obj25395.h"
#include "../include/Obj25396.h"
#include "../include/Obj25397.h"
#include "../include/Obj25398.h"
extern void ZUKAN_INFO_ClearSlotWindows(char *p);
struct S;
extern void ZUKAN_INFO_DeleteActorPair(struct S *p, int i);
extern void ZUKAN_INFO_DeleteRow(char *p, int index);
void ZUKAN_INFO_ClearActors(char *p)
{
    ZUKAN_INFO_ClearSlotWindows(p);
    ZUKAN_INFO_DeleteActorPair((struct S *)p,((struct Obj14635 *)p)->f190);
    ZUKAN_INFO_DeleteRow(p,((struct Obj14635 *)p)->fE0);
}
void ZUKAN_INFO_NotifyMoveDone(char *p)
{
    ((struct Obj25395 *)p)->f58=1;
}
void ZUKAN_INFO_NotifyFadeDone(char *p)
{
    ((struct Obj25396 *)p)->f5C=1;
}
int ZUKAN_INFO_IsMoving(char *p)
{
    int result=0;
    if(((struct Obj25397 *)p)->f54==4) result=1;
    return result;
}
int ZUKAN_INFO_IsDone(char *p)
{
    int result=0;
    if(((struct Obj25398 *)p)->f54==6) result=1;
    return result;
}
void ZUKAN_INFO_Start(char *p)
{
    if(((struct Obj14636 *)p)->f54==0) ((struct Obj14636 *)p)->f54=1;
}
