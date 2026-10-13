/*
 * function: IRCBATTLEMATCH_StepAnimateIcons
 * address: 0x021BB180
 * packet: pkt_ov100_021BB180
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: BA00 tail forwards to D768; full D768 body reads state at0,
 *   words at4/8 for state0, and never the uninitialized padding at2 in that arm.
 * lever: b before a places their Word locals at sp+4 and sp+0 respectively.
 * symbols:
 *   IRCBATTLEMATCH_FreeMessageWindows 0x021BA5F4 thumb ov100
 *   IRCBATTLEMATCH_PrintMainMessage 0x021BA3A4 thumb ov100
 *   IRCBATTLEMATCH_DeleteActor 0x021BA64C thumb ov100
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   func_02040588 0x02040588 arm
 *   IRCBATTLEMATCH_IconAnimLeft 0x021BB0C4 thumb ov100
 *   IRCBATTLEMATCH_IconAnimRight 0x021BB10C thumb ov100
 *   gIrcBattleMatchMsgIconsParent 0x021BB69C data a4
 *   gIrcBattleMatchMsgIconsChild 0x021BB68C data a4
 */
#include "../include/Obj02449.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Word { int x; };
struct Task { u16 state,pad; int context; void (*callback)(int); };
extern const struct Word gIrcBattleMatchMsgIconsParent,gIrcBattleMatchMsgIconsChild;
extern void IRCBATTLEMATCH_FreeMessageWindows(unsigned a);
extern void IRCBATTLEMATCH_PrintMainMessage(struct Word *,int);
extern void IRCBATTLEMATCH_DeleteActor(unsigned a, unsigned b);
struct Actor;
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void IRCBATTLEMATCH_IconAnimLeft(int),IRCBATTLEMATCH_IconAnimRight(int);
void IRCBATTLEMATCH_StepAnimateIcons(int p)
{
    struct Word b,a;
    struct Task task;
    IRCBATTLEMATCH_FreeMessageWindows(p);
    if(((struct Obj02449 *)p)->fC8C==1) {
        if(((struct Obj02449 *)p)->fC7C) {
            b=gIrcBattleMatchMsgIconsParent;
            IRCBATTLEMATCH_PrintMainMessage(&b,p);
        } else {
            a=gIrcBattleMatchMsgIconsChild;
            IRCBATTLEMATCH_PrintMainMessage(&a,p);
            IRCBATTLEMATCH_DeleteActor(p,0);
            IRCBATTLEMATCH_DeleteActor(p,2);
        }
        IRCBATTLEMATCH_DeleteActor(p,6);
        IRCBATTLEMATCH_DeleteActor(p,7);
        IRCBATTLEMATCH_DeleteActor(p,4);
        IRCBATTLEMATCH_DeleteActor(p,5);
        IRCBATTLEMATCH_DeleteActor(p,1);
        IRCBATTLEMATCH_DeleteActor(p,3);
        if(((struct Obj02449 *)p)->fC7C) {
            task.state=0;
            task.context=p;
            task.callback=IRCBATTLEMATCH_IconAnimLeft;
            CLACT_ApplyActorAnimCommand((struct Actor *)(((struct Obj02449 *)p)->f2C8),(const struct Cmd *)(&task));
            task.callback=IRCBATTLEMATCH_IconAnimRight;
            CLACT_ApplyActorAnimCommand((struct Actor *)(((struct Obj02449 *)p)->f2D0),(const struct Cmd *)(&task));
        }
        ((struct Obj02449 *)p)->fC8C=0;
    }
    ((struct Obj02449 *)p)->fC98=(int)(*(u32 *)&((struct Obj02449 *)p)->fC98+1);
    if(((struct Obj02449 *)p)->fC98>8 && ((struct Obj02449 *)p)->fCEC) {
        ((struct Obj02449 *)p)->fC94=0;
        func_02040588(1,0);
    }
}
