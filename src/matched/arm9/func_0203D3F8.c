/*
 * function: GFL_NET_SendData
 * address:  0x0203D3F8
 * packet:   pkt_0203D3F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A7CA0     0x020A7CA0  data
 *   g_020A7CEC     0x020A7CEC  data
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_IsHandleReady  0x0203D394  arm
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *   GFL_NET_SYSTEM_IsSendQueueEntry  0x02039468  arm
 *   func_02034714  0x02034714  arm
 *   GFL_NET_SYSTEM_SetSendQueue  0x02038C18  arm
  * blocker:  label - 0x02038C18 and 0x020395EC each have exactly one branch in
 *           the image and it is the call inside this function, so `label` has
 *           no outside witness for either and no manifest entry covers them
 *           yet.  File those two addresses first and this graduates with no
 *           change to its C (every other site resolves).
 *
*/

typedef unsigned char u8;
typedef unsigned int  u32;

extern char g_020A7CA0[];
extern char g_020A7CEC[];

extern void *GFL_NET_GetInitParam(void);
struct NetEntry;
extern u32 GFL_NET_IsHandleReady(struct NetEntry *e);
struct Entry;
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);
extern u32   GFL_NET_SYSTEM_IsSendQueueEntry(u32 a, u32 b);
extern void  func_02034714(const char *file, u32 line, const char *msg);
extern int GFL_NET_SYSTEM_SetSendQueue(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h)
{
    u8 mask;

    GFL_NET_GetInitParam();
    mask = 0xff;
    if (GFL_NET_IsHandleReady((struct NetEntry *)entry) == 0 && c >= 0x11) {
        return 0;
    }
    if (g != 0 && GFL_NET_SYSTEM_IsSendQueueEntry(c, GFL_NET_HANDLE_GetNetHandleID((void *)entry)) != 0) {
        return 0;
    }
    if (sendID != 0xff) {
        if (sendID >= 7) {
            func_02034714(g_020A7CA0, 1019, g_020A7CEC);
        }
        mask = 1 << sendID;
    }
    return GFL_NET_SYSTEM_SetSendQueue(c, e, d, f, GFL_NET_HANDLE_GetNetHandleID((void *)entry), mask, h);
}
