/*
 * file:     unit_021573C4_p20.c
 * unit:     yes
 * function: func_0215A71C, func_0215A900
 * address:  0x0215A71C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215793C                    0x0215793c arm ov009
 *   func_0215781C                    0x0215781c arm ov009
 *   func_02157FF8                    0x02157ff8 arm ov009
 *   func_0215A450                    0x0215a450 arm ov009
 *   func_0215A23C                    0x0215a23c arm ov009
 *   func_02158FE4                    0x02158fe4 arm ov009
 *   func_0215A108                    0x0215a108 arm ov009
 *   g_021A826C                       0x021a826c data
 *   func_02157C7C  0x02157C7C  arm  ov009
 *   func_02158C68  0x02158C68  arm  ov009
 *   func_02157D48  0x02157D48  arm  ov009
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

extern u32 func_0215793C(u32 ip);
extern int func_0215781C(int a, int b);
extern void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry);
extern u8 *func_0215A450(u8 *buf, u32 *fragmented);
extern void func_0215A23C(u8 *iphdr, u8 *udphdr, u32 len);
extern void func_02158FE4(u8 *iphdr, u8 *icmpdata, u32 len);
extern void func_0215A108(u8 *iphdr, u8 *tcphdr, u32 len);
extern unsigned char *func_02157C7C(unsigned long *len);
extern void func_02158C68(unsigned char *buf, unsigned long len);
extern void func_02157D48(void);
void func_0215A71C(u8 *buf, u32 len);
void func_0215A900(void);
extern u8 g_021A826C[];


#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))

#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))


/*
 * sdk:      dispatch_ip (libcps.TWL.HYB.a network.o)
 */
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


/*
 * sdk:      tcpip (libcps.TWL.HYB.a(network.o))
 */
void func_0215A900(void)
{
    unsigned long len;
    unsigned char *buf;

    for (;;) {
        buf = func_02157C7C(&len);
        if (len > 0x22) {
            unsigned short t = *(unsigned short *)(buf + 0xc);
            unsigned short type = (unsigned short)((t >> 8) | (t << 8));

            switch (type) {
            case 0x800:
                func_0215A71C(buf + 0xe, len - 0xe);
                break;
            case 0x806:
                func_02158C68(buf + 0xe, len - 0xe);
                break;
            }
        }
        func_02157D48();
    }
}
