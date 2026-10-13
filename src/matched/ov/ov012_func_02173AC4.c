/*
 * function: UNION_COMMAND_RecvPartnerMode
 * address: 0x02173AC4
 * packet: pkt_ov012_02173AC4
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
 * Extent reaches existing matched UNION_COMMAND_SendPartnerMode's initial push.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Link;
typedef struct { u8 pad[0x5a]; u8 low:2; u8 mode:2; u8 high:4; } Sub;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
void UNION_COMMAND_RecvPartnerMode(u32 a, int b, u32 *c, u8 *p)
{
    Sub *q = (Sub *)(p + 0x2830);
    if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) q->mode = (u8)*c;
}
