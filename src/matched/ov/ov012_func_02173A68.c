/*
 * function: UNION_COMMAND_RecvPartnerMac
 * address: 0x02173A68
 * packet: pkt_ov012_02173A68
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Link;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void func_02082D44(void *src, void *dst, u32 n);
void UNION_COMMAND_RecvPartnerMac(u32 a, int b, void *c, u8 *p)
{
    u8 *q = p + 0x2830;
    if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) func_02082D44(c, q + 0x24, 8);
}
