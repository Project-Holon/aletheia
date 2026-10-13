/*
 * function: WIFICLUB_StatePollRequestPrompt
 * address: 0x021C0554
 * packet: pkt_ov099_021C0554
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-05, wD9r lane82): the enum-typed offset local and the enum inline helper (stand-ins)
 *   are removed. The real form is a pointer local `st = p + 0x24c;` set as the first statement and
 *   passed to the first WIFICLUB_GetStatusSeatFlag; the other uses are plain p + 0x274, p + 0x1cc and p + 0x1f0.
 *   mwcc keeps 0x24C in r6 and derives the other offsets from it, as in the image. EXACT in c99 and c.
 * symbols:
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 *   WIFICLUB_PollYesNoMenu 0x021BA858 thumb ov099
 *   WIFICLUB_FindPeerActor 0x021BE2A8 thumb ov099
 *   WIFICLUBACTOR_TickBlink 0x021B9B64 thumb ov099
 *   WIFICLUB_GetStatusSeatFlag 0x021C27E0 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 *   WIFICLUBACTOR_RestoreActorUpdate 0x021B9AE0 thumb ov099
 */
#include "../include/Obj00008.h"
extern int WIFICLUBACTOR_GetPickResult(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 WIFICLUB_PollYesNoMenu(char *p);
extern void *WIFICLUB_FindPeerActor(char *,int);
extern void WIFICLUBACTOR_TickBlink(char *);
extern int WIFICLUB_GetStatusSeatFlag(void *);
extern void WIFICLUB_ShowStreamedMessage(char *,int,int);
extern void WIFICLUB_ClearTalkWindow(char *);
extern void WIFICLUB_SetOwnStatusAndPublish(char *,int,int);
extern void WIFICLUB_DisableTouchBar(char *);
extern void WIFICLUBACTOR_RestoreActorUpdate(void *w, u8 *s);
int WIFICLUB_StatePollRequestPrompt(char *p,int ret) {
    int i;
    int r;
    void *q;
    char *st;
    st=p+0x24c;
    i=WIFICLUBACTOR_GetPickResult(p+0x274);
    r=WIFICLUB_PollYesNoMenu(p);
    q=WIFICLUB_FindPeerActor(p,i);
    WIFICLUBACTOR_TickBlink(p+0x274);
    if(r==-1)return ret;
    if(r==0){
        *(int *)&((struct Obj00008 *)p)->f135C=2;
        if(WIFICLUB_GetStatusSeatFlag(st)==WIFICLUB_GetStatusSeatFlag(((struct Obj00008 *)p)->f8)){
            *(int *)(p+0x1cc)=118;
        }else{
            if(WIFICLUB_GetStatusSeatFlag(((struct Obj00008 *)p)->f8))WIFICLUB_ShowStreamedMessage(p,73,0);
            else WIFICLUB_ShowStreamedMessage(p,72,0);
            ((struct Obj00008 *)p)->f1CC=55;
        }
    } else {
        WIFICLUB_ClearTalkWindow(p);
        WIFICLUB_SetOwnStatusAndPublish(p,1,2);
        *(int *)(p+0x1f0)=-1;
        WIFICLUB_DisableTouchBar(p);
        *(int *)(p+0x1cc)=11;
        if(q)WIFICLUBACTOR_RestoreActorUpdate(p+0x274,q);
    }
    return ret;
}
