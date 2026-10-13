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
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 * Extent reaches existing matched func_02173A48's initial push.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Link;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
void UNION_COMMAND_RecvPartnerSelectB(u32 a, int b, u32 *c, u8 *p)
{
    u8 *q = p + 0x2830;
    if (a != func_0203D1A4((struct Link *)func_020399A8())) q[0x2e] = *c;
}
