/*
 * function: WIFICLUB_StateShowRulePreview
 * address:  0x021BCECC
 * packet:   pkt_ov099_021BCECC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   WIFICLUB_LoadOwnRegulation  0x021BCC4C  thumb  ov099
 *   WIFICLUB_ShowRuleWindow  0x021BBEB4  thumb  ov099
 *   WIFICLUB_SetPartnerNameWord  0x021BA874  thumb  ov099
 *   WIFICLUB_PrintTalkMessage  0x021BA978  thumb  ov099
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *   WIFICLUB_ResetTimeIcon  0x021BC090  thumb  ov099
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 */
#include "../include/Obj05262.h"
#include "../include/Obj22034.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern u32 GFL_NET_IsParentAid(void);
extern void WIFICLUB_LoadOwnRegulation(void *a);
struct O;
extern void WIFICLUB_ShowRuleWindow(struct O *p, int mask, u32 a, int mode);
extern void WIFICLUB_SetPartnerNameWord(char *p, int id);
extern void WIFICLUB_PrintTalkMessage(char *p, int a, int b, int c);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);
extern void WIFICLUB_ResetTimeIcon(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, unsigned int a, unsigned int b);

int WIFICLUB_StateShowRulePreview(char *p, int v)
{
    if (GFL_NET_IsParentAid() == 0) {
        WIFICLUB_LoadOwnRegulation(p);
        WIFICLUB_ShowRuleWindow((struct O *)p, 0, ((struct Obj22034 *)(*(u8 * *)&((struct Obj05262 *)p)->f248))->f48, 1);
        WIFICLUB_SetPartnerNameWord(p, ((struct Obj05262 *)p)->f242 - 1);
        WIFICLUB_PrintTalkMessage(p, ((struct Obj05262 *)p)->f134C + 0x69 + (((struct Obj05262 *)p)->f134E << 2), 0, 1);
        ((struct Obj05262 *)p)->f1CC = 0x7A;
    } else {
        WIFICLUB_ShowStreamedMessage(p, 0x4C, 0);
        WIFICLUB_ResetTimeIcon(p);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1B, 0xA);
        ((struct Obj05262 *)p)->f1CC = 0x49;
    }
    return v;
}
