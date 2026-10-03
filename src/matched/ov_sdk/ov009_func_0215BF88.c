/*
 * function: func_0215BF88
 * address:  0x0215BF88
 * packet:   pkt_ov009_0215BF88
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * lane04 (2026-10-01): EXACT. The old p/mode r3<->ip swap came from modelling
 *           network.o's .bss as one struct: the vendor variables are separate
 *           objects, so 1.1p1 proves the in-loop stores cannot alias
 *           CPSDhcpMode and hoists `CPSDhcpMode & 2` itself (the optimizer's
 *           temporary takes ip, the bumped s takes r3). The .bss is modelled
 *           as zero-initialised file statics laid out at the vendor offsets
 *           (mwcc sorts .bss by size; definition order below gives the vendor
 *           order), stores grouped in one struct `cps` after CPSDhcpMode. All
 *           anchor on .bss+0 = wfailed, as in the vendor. Only DWARF locals
 *           remain: the bump reads s[0xef] into `c` before `s += 0xf0`.
 *
 * sdk:      dhcp_analyze_response (libcps.TWL.HYB.a network.o)
 * symbols:
 *   OS_GetTick                       0x020870d0 arm
 *   func_0215B504                    0x0215b504 arm ov009
 *   func_02157390                    0x02157390 arm ov009
 *   func_0215AEB0                    0x0215aeb0 arm ov009
 *   func_021579BC                    0x021579bc arm ov009
 *   func_0215B064                    0x0215b064 arm ov009
 *   g_021A1C9C                       0x021a1c9c data
 *   g_021A82D4                       0x021a82d4 data
 *   wfailed                          0x021a826c data
 *   ip_conflict                      0x021a826d data
 *   ipid                             0x021a826e data
 *   mymss                            0x021a8270 data
 *   eport                            0x021a8272 data
 *   pingseq                          0x021a8274 data
 *   CPSDhcpMode                      0x021a8278 data
 *   cps                              0x021a827c data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

/* network.o .bss from 0x021A827C: the variables dhcp_analyze_response
 * stores, at their vendor offsets relative to that address */
struct CPSBss {
    u32 netmask;             /* 0x00 CPSNetMask */
    u8 pad04[4];             /* 0x04 CPSiAlloc */
    int (*link_is_on)(void); /* 0x08 link_is_on */
    u32 dhcp_server;         /* 0x0C CPSDhcpServerIp */
    u8 pad10[0x1c - 0x10];
    u32 gateway;             /* 0x1C CPSGatewayIp */
    u8 pad20[0x28 - 0x20];
    u32 offered_myip;        /* 0x28 offered_myip */
    u32 lease_time;          /* 0x2C lease_time */
    u8 pad30[0x40 - 0x30];
    u32 myip;                /* 0x40 CPSMyIp */
    u8 pad44[0x60 - 0x44];
    u32 dns[2];              /* 0x60 CPSDnsIp */
};

extern u8 g_021A1C9C[];
extern u8 g_021A82D4[];
static u8 ip_conflict = 0;
static u8 wfailed = 0;
static u16 eport = 0;
static u16 mymss = 0;
static u16 pingseq = 0;
static u16 ipid = 0;
static u32 CPSDhcpMode = 0;
static struct CPSBss cps = {0};
extern unsigned long long OS_GetTick(void);
extern long func_0215B504(void);
extern void func_02157390(void);
extern u8 *func_0215AEB0(u32 *len);
extern int func_021579BC(u8 *a, u8 *b);
extern void func_0215B064(u32 len);

#define TICK() ((u32)(OS_GetTick() >> 16))
#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))
#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))
#define G16(p) ((u16)(((p)[0] << 8) | (p)[1]))
#define G32(p) (((u32)G16(p) << 16) | G16((p) + 2))

int func_0215BF88(u32 id, int retry)
{
    u8 *s;
    u8 *end;
    u32 len;
    u32 start;
    int result;
    u32 myip_tmp;
    u8 c;
    long timeout;

    timeout = g_021A1C9C[retry] * 7;
    start = TICK();
    result = 0;
    while (cps.link_is_on() && result == 0 && (long)(TICK() - start) < timeout) {
        if (func_0215B504() == 0) {
            func_02157390();
            continue;
        }
        s = func_0215AEB0(&len);
        if (len > 0xf0 && s[0] == 2 && NTOHL(s + 4) == id && func_021579BC(s + 0x1c, g_021A82D4) == 0) {
            myip_tmp = G32(s + 0x10);
            end = s + len;
            result = 3;
            if (s[0xec] == 0x63 && s[0xed] == 0x82 && s[0xee] == 0x53 && (c = s[0xef], s += 0xf0, c == 0x63)) {
                while (s < end && (c = *s++) != 0xff) {
                    if (c == 0)
                        continue;
                    switch (c) {
                    case 1:
                        cps.netmask = G32(s + 1);
                        break;
                    case 3:
                        cps.gateway = G32(s + 1);
                        break;
                    case 6:
                        if ((CPSDhcpMode & 2) == 0) {
                            if (s[0] < 8)
                                cps.dns[1] = 0;
                            else
                                cps.dns[1] = G32(s + 5);
                            cps.dns[0] = G32(s + 1);
                        }
                        break;
                    case 0x33:
                        cps.lease_time = G32(s + 1);
                        break;
                    case 0x35:
                        switch (s[1]) {
                        case 2:
                            result = 1;
                            cps.offered_myip = myip_tmp;
                            break;
                        case 5:
                            result = 2;
                            cps.myip = myip_tmp;
                            break;
                        }
                        break;
                    case 0x36:
                        cps.dhcp_server = G32(s + 1);
                        break;
                    }
                    s += *s + 1;
                }
            }
        }
        func_0215B064(len);
    }
    return result;
}
