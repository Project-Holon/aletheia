/*
 * unit:     yes
 * function: WIFICLUB_ShowScenePrompt, WIFICLUB_StatePickScene4, WIFICLUB_StatePickScene5, WIFICLUB_StatePickScene6
 * address:  0x021BC544
 * packet:   pkt_ov099_021BC544
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWifiClubSceneMessageIds     0x021C37DC  data  a4
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   WIFICLUB_SetPartnerNameWord  0x021BA874  thumb  ov099
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *   WIFICLUB_ResetTimeIcon  0x021BC090  thumb  ov099
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *
 * Unit of the lead function plus three unlabelled tail-call stubs
 * (0x021BC5C0/5D4/5E8) that store 0x4b/0x4c/0x4d at +0x132c and tail-call it.
 * The ov099 hint on the 12-byte table is contested, so the data token is bare.
 * The 0x242 offset is an enum-typed local (keeps r4 live, 0x1CC = o - 0x76).
 */
#include "../include/Obj06355.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

typedef struct { u32 a, b, c; } Tri;
typedef enum { K242 = 0x242 } Off;

extern const Tri gWifiClubSceneMessageIds;
extern u32 GFL_NET_IsParentAid(void);
extern void WIFICLUB_SetPartnerNameWord(char *p, int id);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);
extern void WIFICLUB_ResetTimeIcon(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, unsigned int a, unsigned int b);

int WIFICLUB_ShowScenePrompt(char *p, int v);

int WIFICLUB_ShowScenePrompt(char *p, int v)
{
    Tri t = gWifiClubSceneMessageIds;
    Off o;

    if (GFL_NET_IsParentAid() == 0) {
        o = K242;
        WIFICLUB_SetPartnerNameWord(p, *(u16 *)(p + o) - 1);
        WIFICLUB_ShowStreamedMessage(p, ((u32 *)&t)[((struct Obj06355 *)p)->f132C - 0x4b], 0);
        *(u32 *)(p + (o - 0x76)) = 0x4f;
    } else {
        WIFICLUB_ShowStreamedMessage(p, 0x4c, 0);
        WIFICLUB_ResetTimeIcon(p);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 0xa);
        ((struct Obj06355 *)p)->f1CC = 0x49;
    }
    return v;
}

int WIFICLUB_StatePickScene4(char *p, int v)
{
    ((struct Obj06355 *)p)->f132C = 0x4b;
    return WIFICLUB_ShowScenePrompt(p, v);
}

int WIFICLUB_StatePickScene5(char *p, int v)
{
    ((struct Obj06355 *)p)->f132C = 0x4c;
    return WIFICLUB_ShowScenePrompt(p, v);
}

int WIFICLUB_StatePickScene6(char *p, int v)
{
    ((struct Obj06355 *)p)->f132C = 0x4d;
    return WIFICLUB_ShowScenePrompt(p, v);
}
