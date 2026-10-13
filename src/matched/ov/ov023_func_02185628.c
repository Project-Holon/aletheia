/*
 * function: OEKAKI_StepSendQuitConfirm
 * address:  0x02185628
 * packet:   pkt_ov023_02185628
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern void func_02082BCC(void *p, int v, int n);
typedef unsigned int   u32;
struct Entry;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern void OEKAKI_ApplyRemoteStrokes(char *p);

int OEKAKI_StepSendQuitConfirm(char *p, int x)
{
    u8 b[4];

    func_02082BCC(b, 0, 4);
    b[2] = 1;
    b[0] = GFL_NET_SYSTEM_GetCurrentAid();
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2905, 4, (u32)((void *)b)))
        OEKAKI_SetNextScene(p, 12);
    OEKAKI_ApplyRemoteStrokes(p);
    return x;
}
