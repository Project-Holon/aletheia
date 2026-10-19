/*
 * function: OEKAKI_StepShowSyncMessage
 * address:  0x02185974
 * packet:   pkt_ov023_02185974
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   OEKAKI_PrintMessage  0x021861C4  thumb  ov023
 *   OEKAKI_CloseMenuIfOpen  0x02186480  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_HostOpenGroupLimited  0x02186304  thumb  ov023
 *   OEKAKI_GetJoinedCount  0x0218654C  thumb  ov023
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 */
#include "../include/Obj00336.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
typedef unsigned char  u8;
extern void OEKAKI_PrintMessage(u8 *w, u32 msg, int mode);
extern void OEKAKI_CloseMenuIfOpen(char *p);
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern void OEKAKI_HostOpenGroupLimited(char *p, int a);
extern int  OEKAKI_GetJoinedCount(char *p);
extern void OEKAKI_ApplyRemoteStrokes(char *p);

int OEKAKI_StepShowSyncMessage(char *p, int a1)
{
    OEKAKI_PrintMessage((u8 *)p, 2, 1);
    OEKAKI_CloseMenuIfOpen(p);
    OEKAKI_SetNextScene(p, 0x19);
    GFL_USE_PlaySeDefaultVolume(0x54c);
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
        OEKAKI_HostOpenGroupLimited(p, 0);
    ((struct Obj00336 *)p)->f927C = OEKAKI_GetJoinedCount(p);
    OEKAKI_ApplyRemoteStrokes(p);
    return a1;
}
