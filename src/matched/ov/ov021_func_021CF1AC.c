/*
 * unit:     yes
 * function: COMM_ENTRY_SendJoinRequest, COMM_ENTRY_RecvJoinAccept
 * address:  0x021CF1AC
 * packet:   pkt_ov021_021CF1AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: MYSTATUS_Copy (arm9 unlabelled leaf, the integrator's; no witness outside
 * the range). Verified EXACT arm9 thumb leaf C for it:
 *   extern void MI_CpuCopy8(const void *a, void *b, unsigned n);  (arm)
 *   void MYSTATUS_Copy(void *a, void *b) { MI_CpuCopy8(a, b, 0x20); }
 * COMM_ENTRY_RecvJoinAccept (unlabelled) is a tail-call stub into COMM_ENTRY_StoreJoinReply.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   MYSTATUS_Copy  0x02008494  thumb
 *   OS_GetMacAddress  0x02087C6C  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   COMM_ENTRY_StoreJoinReply  0x021CF110  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 name[0x20];
    u8 x[8];
} B;

extern void MI_CpuFill8(void *dst, int v, u32 n);
extern void MYSTATUS_Copy(void *src, void *dst);
extern void OS_GetMacAddress(void *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void COMM_ENTRY_StoreJoinReply(u8 *p, u32 v, void *a);

u32 COMM_ENTRY_SendJoinRequest(u32 a, u32 b, u32 c)
{
    B buf;

    MI_CpuFill8(&buf, 0, 0x28);
    MYSTATUS_Copy((void *)a, &buf);
    OS_GetMacAddress(buf.x);
    buf.x[6] = b;
    if (c == 1)
        GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0xff, 0x2700, 0x28, (u32)(&buf), 0, 0, 0);
    else
        return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x2700, 0x28, (u32)(&buf), 0, 0, 0);
}

void COMM_ENTRY_RecvJoinAccept(u32 a, u32 b, u32 c, u32 d)
{
    COMM_ENTRY_StoreJoinReply((u8 *)d, 1, (void *)c);
}
