/*
 * function: UNION_COMMAND_SendMyMac
 * address: 0x02173A90
 * packet: pkt_ov012_02173A90
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02087C6C 0x02087C6C arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 * 020399A8 leaves the used r0 payload live. Send forwards its pointer
 * unchanged as a full-word payload (matched send wrapper).
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[6]; u8 flag; u8 tail; } Packet;
extern void func_02082BCC(void *p, int v, int n);
extern void func_02087C6C(void *p);
typedef unsigned short u16;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int UNION_COMMAND_SendMyMac(void)
{
    Packet p;
    func_02082BCC(&p, 0, 8);
    func_02087C6C(&p);
    p.flag = 1;
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x1403, 8, (u32)&p);
}
