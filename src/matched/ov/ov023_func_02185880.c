/*
 * function: OEKAKI_StepWaitFinishMessage
 * address: 0x02185880
 * packet: pkt_ov023_02185880
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return at 0x021858B4.
 * symbols:
 *   OEKAKI_IsMessageDone 0x021862B0 thumb ov023
 *   OEKAKI_SetNextScene 0x02186444 thumb ov023
 *   OEKAKI_ApplyRemoteStrokes 0x02185354 thumb ov023
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 * Original narrows r3 to u16 before GFL_NET_HANDLE_SetUserInfo, retained in the call prototype.
 */
#include "../include/Obj20354.h"
typedef unsigned short u16;
extern int OEKAKI_IsMessageDone(char *);
extern void OEKAKI_SetNextScene(char *, unsigned int);
extern void OEKAKI_ApplyRemoteStrokes(char *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c);
int OEKAKI_StepWaitFinishMessage(char *p, int a)
{
    if (OEKAKI_IsMessageDone(p)) {
        OEKAKI_SetNextScene(p, 0x14);
        GFL_NET_HANDLE_SetUserInfo((char *)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8, 0x29, (u16)((struct Obj20354 *)p)->f1B0);
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return a;
}
