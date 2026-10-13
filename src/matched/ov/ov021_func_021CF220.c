/*
 * unit:     yes
 * function: COMM_ENTRY_SendJoinAccept, COMM_ENTRY_RecvJoinRedirect
 * address:  0x021CF220
 * packet:   pkt_ov021_021CF220
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * COMM_ENTRY_RecvJoinRedirect (unlabelled) is a tail-call stub into COMM_ENTRY_StoreJoinReply.
 *
 * symbols:
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   MYSTATUS_GetSize  0x02008468  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   COMM_ENTRY_StoreJoinReply  0x021CF110  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern int MYSTATUS_GetSize(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void COMM_ENTRY_StoreJoinReply(u8 *p, u32 v, void *a);

void COMM_ENTRY_SendJoinAccept(u32 a, u32 flag, u32 c)
{
    u32 h;

    if (flag == 1) {
        h = (u32)GFL_NET_HANDLE_GetNetHandle(0xff);
        GFL_NET_SendData(h, a, 0x2701, MYSTATUS_GetSize(), c, 0, 0, 0);
    } else {
        h = (u32)GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_SendData(h, a, 0x2701, MYSTATUS_GetSize(), c, 0, 0, 0);
    }
}

void COMM_ENTRY_RecvJoinRedirect(u32 a, u32 b, u32 c, u32 d)
{
    COMM_ENTRY_StoreJoinReply((u8 *)d, 2, (void *)c);
}
