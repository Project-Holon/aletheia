/*
 * function: func_0215A71C
 * address:  0x0215A71C
 * packet:   pkt_ov009_0215A71C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispatch_ip (libcps.TWL.HYB.a network.o)
 * symbols:
 *   func_0215793C                    0x0215793c arm ov009
 *   func_0215781C                    0x0215781c arm ov009
 *   func_02157FF8                    0x02157ff8 arm ov009
 *   func_0215A450                    0x0215a450 arm ov009
 *   func_0215A23C                    0x0215a23c arm ov009
 *   func_02158FE4                    0x02158fe4 arm ov009
 *   func_0215A108                    0x0215a108 arm ov009
 *   g_021A826C                       0x021a826c data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u8 g_021A826C[];
extern u32 func_0215793C(u32 ip);
extern int func_0215781C(int a, int b);
extern void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry);
extern u8 *func_0215A450(u8 *buf, u32 *fragmented);
extern void func_0215A23C(u8 *iphdr, u8 *udphdr, u32 len);
extern void func_02158FE4(u8 *iphdr, u8 *icmpdata, u32 len);
extern void func_0215A108(u8 *iphdr, u8 *tcphdr, u32 len);

#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))

void func_0215A71C(u8 *buf, u32 len)
{
    u8 *data;
    u32 header_len;
    u8 type;
    u32 fragmented;

    if (NTOHL(buf + 0x10) != NTOHL(buf + 0xc)) {
        if (len < 20)
            return;
        if ((buf[0] & 0xf) < 5)
            return;
        if (NTOHS(buf + 2) < (buf[0] & 0xf) * 4)
            return;
        if (len < NTOHS(buf + 2))
            return;
        if (func_0215793C(NTOHL(buf + 0x10)) == 0)
            return;
        if (func_0215781C((int)buf, (buf[0] & 0xf) << 2) != 0xffff)
            return;
        if (*(u32 *)(g_021A826C + 0x50) == NTOHL(buf + 0x10))
            func_02157FF8((u8 (*)[6])(buf - 8), NTOHL(buf + 0xc), 1);
    }
    buf = func_0215A450(buf, &fragmented);
    if (buf == 0)
        return;
    header_len = (buf[0] & 0xf) << 2;
    type = buf[9];
    data = buf + header_len;
    len = NTOHS(buf + 2) - header_len;
    if (type == 0x11) {
        func_0215A23C(buf, data, len);
    } else if (*(u32 *)(g_021A826C + 0x50) != 0) {
        if (type == 1)
            func_02158FE4(buf, data, len);
        else if (type == 6)
            func_0215A108(buf, data, len);
    }
    if (fragmented)
        (*(void (**)(void *))(g_021A826C + 0x44))(buf - 14);
}
