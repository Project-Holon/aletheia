/*
 * file:     unit_021573C4_p32.c
 * unit:     yes
 * function: func_0215BD58, func_0215BD8C, func_0215BE80, func_0215BF88
 * address:  0x0215BD58
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
 *   MI_CpuFill8                      0x02082bcc arm
 *   func_0215BC04  0x0215BC04  arm  ov009
 *   func_0215BD58  0x0215BD58  arm  ov009
 *   func_0215B470  0x0215B470  arm  ov009
 *   g_021A826C     0x021A826C  data
 *   g_021A878E     0x021A878E  data
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
struct NetVars {
	unsigned char pad0[0x30];
	unsigned long xid;
	unsigned char pad1[4];
	unsigned long offered_myip;
	unsigned char pad2[0x3c];
	unsigned long long rand_state;
	unsigned long long rand_mult;
	unsigned long long rand_inc;
};

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

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern unsigned char *func_0215BC04(unsigned char *d, int type);
extern unsigned char *func_0215BD58(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen);
extern unsigned long func_0215B470(unsigned char *buf, unsigned long len);
extern unsigned long long OS_GetTick(void);
extern long func_0215B504(void);
extern void func_02157390(void);
extern u8 *func_0215AEB0(u32 *len);
extern int func_021579BC(unsigned short *a, unsigned short *b);
extern void func_0215B064(u32 len);
/* * sdk: dhcp_send_discover (libcps.TWL.HYB.a(network.o)) */ unsigned long func_0215BD8C(void);
/* * sdk: dhcp_send_request (libcps.TWL.HYB.a network.o) */ unsigned long func_0215BE80(int mode);
/* * lane04 (2026-10-01): EXACT. The old p/mode r3<->ip swap came from modelling * network.o's .bss as one struct: the vendor variables are separate * objects, so 1.1p1 proves the in-loop stores cannot alias * CPSDhcpMode and hoists `CPSDhcpMode & 2` itself (the optimizer's * temporary takes ip, the bumped s takes r3). The .bss is modelled * as zero-initialised file statics laid out at the vendor offsets * (mwcc sorts .bss by size; definition order below gives the vendor * order), stores grouped in one struct `cps` after CPSDhcpMode. All * anchor on .bss+0 = wfailed, as in the vendor. Only DWARF locals * remain: the bump reads s[0xef] into `c` before `s += 0xf0`. * * sdk: dhcp_analyze_response (libcps.TWL.HYB.a network.o) */ int func_0215BF88(u32 id, int retry);
extern struct NetVars g_021A826C;
extern unsigned char g_021A878E[];
extern u8 g_021A1C9C[];
extern u8 g_021A82D4[];



static unsigned char *pad_mem(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen)
{
	unsigned long n;

	if (curlen < minimum) {
		n = minimum - curlen;
		MI_CpuFill8(d, pattern, n);
		d += n;
	}
	return d;
}



/*
 * sdk:      dhcp_send_discover (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215BD8C(void)
{
	unsigned char *buf = g_021A878E;
	unsigned char *d;

	g_021A826C.rand_state = g_021A826C.rand_mult * g_021A826C.rand_state + g_021A826C.rand_inc;
	g_021A826C.xid = (unsigned long)(g_021A826C.rand_state >> 32);
	d = func_0215BC04(buf, 1);
	if (g_021A826C.offered_myip != 0) {
		*d++ = 0x32;
		*d++ = 4;
		*d++ = (unsigned short)(g_021A826C.offered_myip >> 16) >> 8;
		*d++ = g_021A826C.offered_myip >> 16;
		*d++ = (unsigned short)g_021A826C.offered_myip >> 8;
		*d++ = g_021A826C.offered_myip;
	}
	*d++ = 0xff;
	d = func_0215BD58(0, 300, d, d - buf);
	func_0215B470(buf, d - buf);
	return g_021A826C.xid;
}

#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))

#define HI16(x) ((unsigned short)((x) >> 16))

#define LO16(x) ((unsigned short)(x))

#define TICK() ((u32)(OS_GetTick() >> 16))

#define NTOHS(p) ((u16)((*(u16 *)(p) >> 8) | (*(u16 *)(p) << 8)))

#define NTOHL(p) (((u32)NTOHS(p) << 16) | NTOHS((u8 *)(p) + 2))

#define G16(p) ((u16)(((p)[0] << 8) | (p)[1]))

#define G32(p) (((u32)G16(p) << 16) | G16((p) + 2))



/*
 * sdk:      dhcp_send_request (libcps.TWL.HYB.a network.o)
 */
unsigned long func_0215BE80(int mode)
{
	unsigned char *buf;
	unsigned char *d;

	buf = g_021A878E;
	d = func_0215BC04(buf, 3);
	if (mode == 0) {
		d[0] = 0x32;
		d[1] = 4;
		d[2] = (unsigned char)(HI16(NV(0x38, unsigned long)) >> 8);
		d[3] = (unsigned char)HI16(NV(0x38, unsigned long));
		d[4] = (unsigned char)(LO16(NV(0x38, unsigned long)) >> 8);
		d[5] = (unsigned char)LO16(NV(0x38, unsigned long));
		d[6] = 0x36;
		d[7] = 4;
		d[8] = (unsigned char)(HI16(NV(0x1c, unsigned long)) >> 8);
		d[9] = (unsigned char)HI16(NV(0x1c, unsigned long));
		d[10] = (unsigned char)(LO16(NV(0x1c, unsigned long)) >> 8);
		d[11] = (unsigned char)LO16(NV(0x1c, unsigned long));
		d += 12;
	}
	*d++ = 0xff;
	d = func_0215BD58(0, 300, d, d - buf);
	func_0215B470(buf, d - buf);
	return NV(0x30, unsigned long);
}


static u8 ip_conflict = 0;


static u8 wfailed = 0;


static u16 eport = 0;


static u16 mymss = 0;


static u16 pingseq = 0;


static u16 ipid = 0;


static u32 CPSDhcpMode = 0;


static struct CPSBss cps = {0};



/*
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
 */
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
        if (len > 0xf0 && s[0] == 2 && NTOHL(s + 4) == id && func_021579BC((short unsigned int *)(s + 0x1c), (short unsigned int *)g_021A82D4) == 0) {
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
