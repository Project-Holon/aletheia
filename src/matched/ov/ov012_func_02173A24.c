/*
 * function: UNION_COMMAND_RecvPartnerSelectB
 * address: 0x02173A24
 * packet: pkt_ov012_02173A24
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 * Extent reaches existing matched UNION_COMMAND_SendPartnerSelectB's initial push.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Link;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
void UNION_COMMAND_RecvPartnerSelectB(u32 a, int b, u32 *c, u8 *p)
{
    u8 *q = p + 0x2830;
    if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) q[0x2e] = *c;
}
