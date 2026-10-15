/*
 * function: dispatch_ip
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
 *   ip_isme                    0x0215793c arm ov009
 *   calc_checksum                    0x0215781c arm ov009
 *   reg_arpcache                    0x02157ff8 arm ov009
 *   check_frag                    0x0215a450 arm ov009
 *   dispatch_udp                    0x0215a23c arm ov009
 *   dispatch_icmp                    0x02158fe4 arm ov009
 *   dispatch_tcp                    0x0215a108 arm ov009
 *   gCpsNetVars                       0x021a826c data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u8 gCpsNetVars[];
extern u32 ip_isme(u32 ip);
extern int calc_checksum(int a, int b);
extern void reg_arpcache(unsigned char (*mac)[6], unsigned long ip, int new_entry);
extern u8 *check_frag(u8 *buf, u32 *fragmented);
extern void dispatch_udp(u8 *iphdr, u8 *udphdr, u32 len);
extern void dispatch_icmp(u8 *iphdr, u8 *icmpdata, u32 len);
extern void dispatch_tcp(u8 *iphdr, u8 *tcphdr, u32 len);

#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))

void dispatch_ip(u8 *buf, u32 len)
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
        if (ip_isme(NTOHL(buf + 0x10)) == 0)
            return;
        if (calc_checksum((int)buf, (buf[0] & 0xf) << 2) != 0xffff)
            return;
        if (*(u32 *)(gCpsNetVars + 0x50) == NTOHL(buf + 0x10))
            reg_arpcache((u8 (*)[6])(buf - 8), NTOHL(buf + 0xc), 1);
    }
    buf = check_frag(buf, &fragmented);
    if (buf == 0)
        return;
    header_len = (buf[0] & 0xf) << 2;
    type = buf[9];
    data = buf + header_len;
    len = NTOHS(buf + 2) - header_len;
    if (type == 0x11) {
        dispatch_udp(buf, data, len);
    } else if (*(u32 *)(gCpsNetVars + 0x50) != 0) {
        if (type == 1)
            dispatch_icmp(buf, data, len);
        else if (type == 6)
            dispatch_tcp(buf, data, len);
    }
    if (fragmented)
        (*(void (**)(void *))(gCpsNetVars + 0x44))(buf - 14);
}
