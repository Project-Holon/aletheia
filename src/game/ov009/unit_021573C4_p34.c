/*
 * file:     unit_021573C4_p34.c
 * unit:     yes
 * function: func_0215C508, func_0215C538, func_0215C7E0, func_0215C814, func_0215C8B4, func_0215C910
 * address:  0x0215C508
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
 *   func_0215B470                    0x0215b470 arm ov009
 *   OS_GetTick                       0x020870d0 arm
 *   func_0215B504                    0x0215b504 arm ov009
 *   OS_Sleep                         0x02085a38 arm
 *   func_0215AEB0                    0x0215aeb0 arm ov009
 *   func_0215C508                    0x0215c508 arm ov009
 *   MI_CpuCopy                       0x02082ea4 arm
 *   func_0215B064                    0x0215b064 arm ov009
 *   g_021A826C                       0x021a826c data
 *   func_0215C7E0  0x0215C7E0  arm  ov009
 *   func_0215AB10  0x0215AB10  arm  ov009
 *   func_0215AA88  0x0215AA88  arm  ov009
 *   func_0215AAB0  0x0215AAB0  arm  ov009
 *   func_0215AB5C  0x0215AB5C  arm  ov009
 *   func_021578C8            0x021578C8  arm  ov009
 *   func_02157D8C            0x02157D8C  arm  ov009
 *   func_02157F60            0x02157F60  arm  ov009
 *   wfailed                  0x021A826C  data
 *   CPSDnsIp                 0x021A82DC  data
 */
#define TICK() ((u32)(OS_GetTick() >> 16))
#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define GET16(p) ((u16)((p)[1] | ((p)[0] << 8)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

struct CPSVars {
    u8 pad0[0x18];
    int (*link_is_on)(void);
};

typedef struct {
	unsigned long long x;
	unsigned long long mul;
	unsigned long long add;
} RandCtx;

extern u32 func_0215B470(u8 *buf, u32 len);
extern unsigned long long OS_GetTick(void);
extern long func_0215B504(void);
extern void OS_Sleep(u32 msec);
extern u8 *func_0215AEB0(u32 *len);
extern u8 *func_0215C508(u8 *p);
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);
extern void func_0215B064(u32 len);
extern unsigned long func_0215C7E0(unsigned char *s, unsigned char **end);
extern void func_0215AB10(void);
extern void func_0215AA88(void);
extern void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern void func_0215AB5C(void);
extern unsigned long func_021578C8(unsigned long ip);
u32 func_0215C538(u8 *name, u32 type, u16 id, u8 *rname, u32 rname_max);
unsigned long func_0215C814(unsigned char *name, unsigned long *pip);
unsigned long func_0215C8B4(unsigned char *name, unsigned long dnsip, unsigned short id);
unsigned long func_0215C910(char *name);
extern struct CPSVars g_021A826C;
extern unsigned long CPSDnsIp[2];


static unsigned char *dns_skipname(unsigned char *s)
{
	unsigned char c;

	while ((c = *s++) != 0) {
		if ((c & 0xc0) == 0xc0) {
			s++;
			break;
		}
		s += c;
	}
	return s;
}


static inline u16 get16(u8 *p)
{
    return (u16)((p[0] << 8) | p[1]);
}



/*
 * sdk:      resolve_common (libcps.TWL.HYB.a network.o)
 */
u32 func_0215C538(u8 *name, u32 type, u16 id, u8 *rname, u32 rname_max)
{
    u8 outbuf[68];
    u8 *buf;
    u8 *d;
    u8 *d0;
    u32 len;
    u32 cnt;
    u8 c;
    u32 ip;
    u32 start;
    u8 *end;

    *(u16 *)(outbuf + 0) = HTONS(id);
    if (type != 0x20)
        *(u16 *)(outbuf + 2) = 0x0001;
    else
        *(u16 *)(outbuf + 2) = 0x1001;
    *(u16 *)(outbuf + 4) = 0x100;
    *(u16 *)(outbuf + 6) = 0;
    *(u16 *)(outbuf + 8) = 0;
    *(u16 *)(outbuf + 10) = 0;
    d0 = outbuf + 12;
    d = d0 + 1;
    len = 0;
    while ((c = *name++) != 0) {
        if (d - outbuf > 0x3c)
            return 0xffffffff;
        if (c != '.') {
            len++;
            *d++ = c;
        } else if (len != 0) {
            *d0 = len;
            d0 = d;
            len = 0;
            d++;
        }
    }
    *d0 = len;
    ip = 0;
    d[0] = 0;
    d[1] = type >> 8;
    d[2] = type;
    d[3] = 0;
    d[4] = 1;
    func_0215B470(outbuf, d + 5 - outbuf);
    start = TICK();
    while (g_021A826C.link_is_on() && ip == 0 && (int)(TICK() - start) < 0xf) {
        if (func_0215B504() == 0) {
            OS_Sleep(10);
            continue;
        }
        buf = func_0215AEB0(&len);
        if (len > 12 && HTONS(*(u16 *)buf) == id) {
            if ((buf[3] & 0xf) == 3) {
                ip = 0xffffffff;
            } else if ((buf[3] & 0xf) == 0) {
                end = buf + len;
                d = buf + 12;
                cnt = GET16(buf + 4);
                while (cnt-- != 0)
                    d = func_0215C508(d) + 4;
                while (d < end) {
                    d = func_0215C508(d);
                    cnt = get16(d + 8);
                    if (get16(d) == type) {
                        if (type != 0xc) {
                            ip = ((u32)get16((u8 *)((u32)d + 6 + cnt)) << 16) | get16((u8 *)((u32)d + 8 + cnt));
                        } else if (cnt > rname_max) {
                            ip = 2;
                        } else {
                            MI_CpuCopy(d + 10, rname, cnt);
                            ip = 1;
                        }
                        break;
                    }
                    d += cnt + 10;
                }
            }
        }
        func_0215B064(len);
    }
    return ip;
}


static unsigned long strtol10(unsigned char *s, unsigned char **endptr)
{
	unsigned long acc = 0;
	unsigned char c;

	*endptr = s;
	for (;;) {
		c = *s;
		if ((unsigned char)(c - '0') > 9)
			break;
		acc = acc * 10 + (unsigned char)(c - '0');
		s++;
		*endptr = s;
	}
	return acc;
}



/*
 * sdk:      rawip (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215C814(unsigned char *name, unsigned long *pip)
{
    unsigned long ip = 0;
    int i = 0;
    unsigned long field;
    unsigned char *next;

    do {
        field = func_0215C7E0(name, &next);
        if (name == next)
            return 0;
        name = next;
        if (field > 0xff)
            goto fail;
        if (i != 3) {
            unsigned char c = *name++;

            if (c != '.')
                goto fail;
        }
        if (i == 3) {
            if (*name != 0) {
fail:
                return 0;
            }
        }
        ip = field | (ip << 8);
        i++;
    } while (i < 4);
    *pip = ip;
    return 1;
}



/*
 * sdk:      resolve_sub (libcps.TWL.HYB.a(network.o))
 */
unsigned long func_0215C8B4(unsigned char *name, unsigned long dnsip, unsigned short id)
{
    unsigned long ip;

    if (dnsip == 0)
        return 0xffffffff;
    func_0215AB10();
    func_0215AA88();
    func_0215AAB0(0, 0x35, dnsip);
    ip = func_0215C538(name, 1, id, 0, 0);
    func_0215AB5C();
    return ip;
}


extern unsigned char (*func_02157D8C(unsigned long ip))[6];


extern unsigned char (*func_02157F60(unsigned long ip))[6];


static unsigned char ip_conflict = 0;


static unsigned char wfailed = 0;


static unsigned short eport = 0;


static unsigned short mymss = 0;


static unsigned short pingseq = 0;


static unsigned short ipid = 0;


static unsigned long CPSMyIp = 0;


static int CPSNoIpReason = 0;


static void *checkNConfig_callback = 0;


static void (*CPSiFree)(void *) = 0;


static unsigned long sleep_save = 0;


static unsigned long lease_time = 0;


static void *scavenger_callback = 0;


static unsigned long offered_myip = 0;


static int scavenger_force_exit = 0;


static unsigned long wlan_buflen = 0;


static void *dhcp_callback = 0;


static int yield_wait = 0;


static void *wlan_buf = 0;


static unsigned long CPSDhcpServerIp = 0;


static int link_is_on = 0;


static unsigned long CPSGatewayIp = 0;


static void *receiver_thread = 0;


static unsigned long wlan_putpnt = 0;


static unsigned long CPSDhcpMode = 0;


static unsigned long CPSNetMask = 0;


static unsigned long xid = 0;


static unsigned long wlan_getpnt = 0;


static void *(*CPSiAlloc)(unsigned long) = 0;


static unsigned char CPSMyMac[6] = {0};



unsigned long CPSDnsIp[2] = {0};


RandCtx CPSiRand32ctx = {0};



static inline unsigned long rand32(RandCtx *context, unsigned long max)
{
	context->x = context->mul * context->x + context->add;
	return (unsigned long)(max ? (((context->x >> 32) * max) >> 32) : (context->x >> 32));
}



/*
 * closed (2026-10-01, ov SDK wave 3 lane30): the rand context is network.o's
 *   global CPSiRand32ctx (.bss+0x78, reached through the wfailed anchor), not a
 *   field of an extern struct. Modelled as the network.o .bss statics (list from
 *   02157290; ip_conflict before wfailed so the 1-byte group keeps wfailed at
 *   +0); as a distinct object the compiler proves the x stores do not alias and
 *   schedules them as the image. CPSDnsIp is a global (vendor STB_GLOBAL) with
 *   a prior extern declaration (public header), so 1.1p1 addresses it by name
 *   (own pool word, as in the vendor reloc list) instead of via the anchor.
 *   The 4-byte group order is not the vendor's (unreferenced here).
 *
 * old blocker (resolved): three one-slot schedule swaps around the inlined
 *           rand32 (see lane notes below).
 *
 * sdk:      CPS_Resolve (libcps.TWL.HYB.a network.o)
 *
 * lane T5 (2026-09-30).  Pin sweep (all 9 dsi compilers x 4 flag sets): 1.1p1
 * -O4,p at 380 bytes / 24 concrete bytes is the unique best (1.6sp1/sp2 give 30).
 * Residue already named in the blocker above (the two schedule swaps in the id
 * set-up); no new spelling was spent on it this wave.
 *
 * lane U41 (2026-09-30).  Re-measured: still 380 compiled / 380 extent with 24
 * concrete bytes, three one-slot schedule swaps:
 *   +0008  image `ldr r2, [pc, #0x164]` | ours `mov r1, #0`
 *   +006c  image `orr r7, r7, fp, lsr #16` | ours `str r6, [r2, #0x78]`
 *   +007c  image `mov sl, r0` | ours `str r4, [r2, #0x7c]`
 * Eleven more spellings measured, all 24 diffs: `retries = 0;` before `ip = 0;`,
 * the two id stores first, a split id[i] pair, `ask_this` before the ids,
 * `ip = 0, retries = 0;` comma, the initialisers moved into the declarations,
 * `retries` declared `long`, `0u`, and the loop counter fixed in the `for`
 * header.  The 5/5 pool words and all 7 relocations resolve; this is the list
 * scheduler's slot tie-break, not a body shape.
 *
 * lane W8 (2026-09-30).  Two more spellings against the same three one-slot
 * swaps, both no better: computing rand32's return into a temp BEFORE the
 * context->x store (the compute-a-stores-operands-before-the-store lever) is
 * still 24 (the front end canonicalises it back); an aggregate initialiser
 * `unsigned short id[2] = { rand32(...), rand32(...) };` disables the
 * cross-call interleaving and blows up to 97.  Residue unchanged; all 7
 * relocations resolve.
 *
 * lane W8.2 (2026-10-01).  Three more spellings, all still exactly these three
 * one-slot schedule swaps at 380/24: `rand32` rewritten to compute both the
 * LCG x and the return into named temps before the `context->x` store (the
 * store-operands-first lever) stays 24; `const char *name` on the read-only
 * source parameter (the const-source-pointer tie lever) stays 24; `const` on
 * the read-only extern `g_021A82DC[2]` blows up to 384/159.  Reverted to the
 * 24-byte state.  This is the list scheduler's slot tie-break, not a body
 * shape: all 7 relocations resolve and every instruction opcode is right.
 *
 * lane W8.3 (2026-10-01).  Confirmed this is the same list-scheduler tie the
 * sibling rand32 consumer in this very overlay already documents:
 * docs/idioms/a-pool-word-order-residue-is-a-list-scheduler-tie.md
 * (ov009_func_021685CC.c, DWCi_GetMathRand32, identical 64-bit LCG rand32
 * body).  The three residue slots (+0008 context ldr above mov r1,#0; +006c
 * orr above str r6; +007c mov sl above str r4) are all independent-issue
 * hoists around the inlined rand32 epilogue, i.e. the same scheduler
 * slot tie-break the idiom says no C shape reaches.  No new spelling spent;
 * 380/24 unchanged, all 7 relocations resolve.
 * lane 05 (2026-10-01): still 380/24.  New and inert: rand32 spelled as the
 * SDK's MATH_Rand32 if/else (max == 0 ? x>>32 : ...), moving ip/retries
 * around the id draws (97 when ip follows them), a `for (server...)` id
 * loop (not unrolled, 368/large).
 */
unsigned long func_0215C910(char *name)
{
	unsigned long ip;
	int retries;
	int server;
	unsigned short id[2];
	unsigned char ask_this[2];
	unsigned long t;

	ip = 0;
	retries = 0;
	id[0] = (unsigned short)rand32(&CPSiRand32ctx, 0x10000);
	id[1] = (unsigned short)rand32(&CPSiRand32ctx, 0x10000);
	if (func_0215C814((unsigned char *)name, &ip))
		return ip;
	ask_this[0] = 1;
	ask_this[1] = 1;
	for (; retries < 3; retries++) {
		for (server = 0; server < 2; server++) {
			if (!ask_this[server])
				continue;
			if (CPSDnsIp[server] == 0 || (t = func_021578C8(CPSDnsIp[server])) == 0) {
				ask_this[server] = 0;
				continue;
			}
			if (func_02157D8C(t) == 0 && func_02157F60(t) == 0) {
				ask_this[server] = 0;
				continue;
			}
			ip = func_0215C8B4((unsigned char *)name, CPSDnsIp[server], id[server]);
			if (ip != 0 && ip != 0xffffffff)
				goto done;
			if (ip == 0xffffffff)
				ask_this[server] = 0;
		}
	}
done:
	if (ip == 0xffffffff)
		ip = 0;
	return ip;
}
