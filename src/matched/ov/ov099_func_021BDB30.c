/*
 * function: WIFICLUB_StateHandlePeerPhase
 * address: 0x021BDB30
 * packet: pkt_ov099_021BDB30
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototypes: BCB70 matched callers declare void; original consumes r0 after BL, so the return is int here. 399A8 own void tail-forwarder leaves r0 live and caller passes that result to D1E8/39C68. BDD54 own u8 return is widened to retain the original explicit u16 truncation.
 * symbols:
 *   WIFICLUB_GetStatusPhase 0x021BDD54 thumb ov099
 *   WIFICLUB_StartVoiceChat 0x021BC104 thumb ov099
 *   WIFICLUB_StartBgmFade 0x021C24A4 thumb ov099
 *   WIFICLUB_ShowMessage 0x021BAADC thumb ov099
 *   WIFICLUB_CheckPartyAgainstRules 0x021BCB70 thumb ov099
 *   WIFICLUB_CheckSavedRegulation 0x021BCBBC thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_NotifyUserEvent 0x0203D1E8 arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj02155.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFICLUB_GetStatusPhase(char *, void *);
extern void WIFICLUB_StartVoiceChat(char *);
extern void WIFICLUB_StartBgmFade(void *, int);
extern void WIFICLUB_ShowMessage(char *, int, int);
struct BigObj;
extern int WIFICLUB_CheckPartyAgainstRules(void *rules, const struct BigObj *obj, u32 *mask);
extern int WIFICLUB_CheckSavedRegulation(int, int, int *);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern void *GFL_NET_GetInitParam(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_NotifyUserEvent(u32, void *);
extern u32 GFL_NET_IsParentAid(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);
int WIFICLUB_StateHandlePeerPhase(char *p, int v)
{
    u16 state;
    int out;
    state = (u16)WIFICLUB_GetStatusPhase(p, ((struct Obj02155 *)p)->f8);
    switch (state) {
    case 4:
        GFL_NET_GetInitParam();
        WIFICLUB_StartVoiceChat(p);
        WIFICLUB_StartBgmFade(p, 0);
        WIFICLUB_ShowMessage(p, 0x7b, 0);
        ((struct Obj02155 *)p)->f1355 = 0;
        ((struct Obj02155 *)p)->f1CC = 0x10;
        return v;
    case 5:
        ((struct Obj02155 *)p)->f1D0 = state;
        return 2;
    case 6:
        WIFICLUB_StartVoiceChat(p);
        ((struct Obj02155 *)p)->f1D0 = state;
        return 2;
    default:
        GFL_NET_NotifyUserEvent((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
        if (GFL_NET_IsParentAid()) {
            if (WIFICLUB_CheckPartyAgainstRules((void *)(((struct Obj02155 *)p)->f1348), (const struct BigObj *)(((struct Obj02155 *)p)->fC4), (u32 *)(&out)) &&
                WIFICLUB_CheckSavedRegulation(((struct Obj02155 *)p)->f1348, ((struct Obj02155 *)p)->fCC, &out)) {
                WIFICLUB_ShowStreamedMessage(p, 0x68, 0);
                ((struct Obj02155 *)p)->f1CC = 0x74;
                return v;
            }
            ((struct Obj02155 *)p)->f1CC = 0x5b;
        } else {
            GFL_NET_HANDLE_SetTimingSyncRange((void *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 0xa);
            ((struct Obj02155 *)p)->f1CC = 0x49;
        }
        return v;
    }
}
