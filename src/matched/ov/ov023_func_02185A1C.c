/*
 * function: OEKAKI_StepWaitSyncTimer
 * address:  0x02185A1C
 * packet:   pkt_ov023_02185A1C
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   UNION_APP_GetJoinedBits  0x021841A0  thumb  ov022
 *   UNION_APP_GetMemberCount  0x021841A4  thumb  ov022
 *   OEKAKI_GetJoinedCount  0x0218654C  thumb  ov023
 *   OEKAKI_GetJoinedBits  0x02186558  thumb  ov023
 *   OEKAKI_ClearMessageWindow  0x021862F4  thumb  ov023
 *   OEKAKI_NotifyHostSync  0x02186304  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 */
#include "../include/Obj02104.h"

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int  UNION_APP_GetMemberCount(unsigned char *p);
extern unsigned char UNION_APP_GetJoinedBits(unsigned char *p);
extern int  OEKAKI_GetJoinedCount(char *p);
extern int  OEKAKI_GetJoinedBits(char *p);
extern void OEKAKI_ClearMessageWindow(char *p);
extern void OEKAKI_NotifyHostSync(char *p, int a);
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern void OEKAKI_ApplyRemoteStrokes(char *p);

int OEKAKI_StepWaitSyncTimer(char *p, int a1)
{
    if (!((((struct Obj02104 *)p)->f927C == 0 || ((struct Obj02104 *)p)->f927C == OEKAKI_GetJoinedCount(p))
          && (OEKAKI_GetJoinedBits(p) & ((struct Obj02104 *)p)->f9280)))
        ((struct Obj02104 *)p)->f927C = 0;
    ((struct Obj02104 *)p)->f1A4 += 1;
    if (((struct Obj02104 *)p)->f1A4 > 0x3c && ((struct Obj02104 *)p)->f927C == 0) {
        OEKAKI_ClearMessageWindow(p);
        OEKAKI_SetNextScene(p, 4);
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            ((struct Obj02104 *)p)->f9E6C = 1;
            OEKAKI_NotifyHostSync(p, 1);
        }
        ((struct Obj02104 *)p)->f1AC = UNION_APP_GetMemberCount(**(unsigned char ** *)&((struct Obj02104 *)p)->f4);
        ((struct Obj02104 *)p)->f1B0 = UNION_APP_GetJoinedBits((unsigned char *)(**(u32 * *)&((struct Obj02104 *)p)->f4));
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return a1;
}
