/*
 * function: send_ip
 * address:  0x0215832C
 * packet:   pkt_ov009_0215832C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_ip (libcps.TWL.HYB.a network.o)
 * symbols:
 *   send_ip_frag                    0x02158204 arm ov009
 *   g_021A826C                       0x021a826c data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct CPSVars {
    u8 pad0[2];
    u16 ipid;
    u8 pad1[0x50 - 4];
    u32 myip;
};
extern struct CPSVars g_021A826C;
extern void send_ip_frag(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u32 offset);

#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define IPID g_021A826C.ipid
#define MYIP g_021A826C.myip

void send_ip(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u8 proto)
{
    u16 offset;
    u8 *bodytmp;
    u32 this_len;

    offset = 0;
    hdr[-0x14] = 0x45;
    hdr[-0x13] = 0;
    IPID++;
    *(u16 *)(hdr - 0x10) = HTONS(IPID);
    hdr[-0xc] = 0x80;
    hdr[-0xb] = proto;
    *(u16 *)(hdr - 8) = HTONS(MYIP >> 16);
    *(u16 *)(hdr - 6) = HTONS(MYIP);
    *(u16 *)(hdr - 4) = HTONS(ip_to >> 16);
    *(u16 *)(hdr - 2) = HTONS(ip_to);

    if (hdr_len > 0x5c8) {
        bodytmp = hdr;
        while (hdr_len > 0x5c8) {
            send_ip_frag(hdr, 0, bodytmp, 0x5c8, ip_to, offset | 0x2000);
            bodytmp += 0x5c8;
            hdr_len -= 0x5c8;
            offset += 0xb9;
        }
        if (hdr_len != 0) {
            if (body_len != 0)
                send_ip_frag(hdr, 0, bodytmp, hdr_len, ip_to, offset | 0x2000);
            else
                send_ip_frag(hdr, 0, bodytmp, hdr_len, ip_to, offset);
            offset += hdr_len >> 3;
            hdr_len = 0;
        }
    }
    while (hdr_len + body_len > 0x5c8) {
        this_len = 0x5c8 - hdr_len;
        send_ip_frag(hdr, hdr_len, body, this_len, ip_to, offset | 0x2000);
        body_len -= this_len;
        hdr_len = 0;
        body += this_len;
        offset += 0xb9;
    }
    if (hdr_len + body_len == 0)
        return;
    send_ip_frag(hdr, hdr_len, body, body_len, ip_to, offset);
}
