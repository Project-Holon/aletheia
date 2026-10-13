/*
 * function: OEKAKI_StepSendFinishRequest
 * address:  0x02185814
 * packet:   pkt_ov023_02185814
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 *   OEKAKI_RegisterPlayerName  0x021857F4  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 */

typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void OEKAKI_ApplyRemoteStrokes(char *p);
extern void OEKAKI_RegisterPlayerName(char *p, int a, int b);
extern void OEKAKI_SetNextScene(char *p, u32 v);

int OEKAKI_StepSendFinishRequest(char *p, int a1)
{
    int z;
    z = 0;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetNetHandle(0xff), 0x2906, 0, 0)) {
        OEKAKI_SetNextScene(p, 0x12);
        OEKAKI_RegisterPlayerName(p, z, z);
        a1 = 2;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return a1;
}
