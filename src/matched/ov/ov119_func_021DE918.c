/*
 * function: POKETRADE_NEGO_StepSendDeclineConfirm
 * address:  0x021DE918
 * packet:   pkt_ov119_021DE918
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_NEGO_StepResolveConfirm  0x021DDF74  thumb  ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, u32 a, u32 b);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_NEGO_StepResolveConfirm(char *p);

void POKETRADE_NEGO_StepSendDeclineConfirm(void *p)
{
    u8 cmd;
    cmd = 0xC;
    if (GFL_NET_SendToHandle((struct Entry *)((u32)GFL_NET_HANDLE_GetCurrentHandle()), 0xC00, 1, (u32)(&cmd)) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1C, 8);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepResolveConfirm);
    }
}
