/*
 * file:     unit_021573C4_p02.c
 * unit:     yes
 * function: func_02157FF8, func_02158134, func_02158204, func_0215832C, func_02158524, func_021585D8
 * address:  0x02157FF8
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
 *   func_02157888            0x02157888  arm  ov009
 *   func_02157928            0x02157928  arm  ov009
 *   OS_GetTick               0x020870D0  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   g_021A826C               0x021A826C  data
 *   g_021A8384               0x021A8384  data
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157D8C  0x02157D8C  arm  ov009
 *   func_02157F60  0x02157F60  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   func_021579E8  0x021579E8  arm  ov009
 *   g_021A82D4  0x021A82D4  data
 *   func_0215781C            0x0215781C  arm  ov009
 *   OS_DisableInterrupts     0x02087988  arm
 *   func_02157A44            0x02157A44  arm  ov009
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   g_021A1CC0               0x021A1CC0  data
 *   func_02157700  0x02157700  arm  ov009
 *   func_02157808  0x02157808  arm  ov009
 *   g_02150FEC  0x02150FEC  data
 *   wfailed  0x021A826C  data
 *   ip_conflict  0x021A826D  data
 *   ipid  0x021A826E  data
 *   mymss  0x021A8270  data
 *   eport  0x021A8272  data
 *   _ZZ13func_02158524PhmP3SocE7pingseq  0x021A8274  data
 */
#include "cps_types.h"
#include "../../matched/include/G_ArpEntry.h"

#define HTONS(x) ((u16)(((u16)(x) >> 8) | ((u16)(x) << 8)))
#define IPID g_021A826C.ipid
#define MYIP g_021A826C.myip
struct SocBuf {
	unsigned long len;
	unsigned char *data;
};

extern unsigned long func_02157888(unsigned long ip);
extern int func_02157928(unsigned v);
extern u64 OS_GetTick(void);
extern void MI_CpuCopy(const void *srcp, void *destp, u32 size);
extern unsigned long func_021578C8(unsigned long ip);
extern unsigned char *func_02157D8C(unsigned long ip);
extern unsigned char *func_02157F60(unsigned long ip);
extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
extern unsigned short func_0215781C(unsigned char *s, int len);
extern unsigned long OS_DisableInterrupts(void);
extern void func_02157A44(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf1, unsigned long size1, unsigned char *buf2, unsigned long size2);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum);
extern unsigned short func_02157808(unsigned short sum);
void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry);
void func_02158134(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type);
void func_02158204(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset);
void func_0215832C(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u8 proto);
void func_02158524(unsigned char *pattern, unsigned long len, struct _CPSSoc *soc);
void func_021585D8(unsigned char *data, unsigned long len, struct _CPSSoc *soc);
extern struct ArpEntry g_021A8384[8];
extern unsigned char g_021A82D4[6];
extern u8 g_021A1CC0[];






/*
 * sdk:      reg_arpcache (libcps.TWL.HYB.a network.o)
 */
void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry)
{
	unsigned long i;
	unsigned long candidate;
	unsigned short now;
	unsigned short oldest_time;

	if (ip == 0x7f000001 || ip == g_021A826C.myip)
		return;
	if (!func_02157888(ip))
		return;
	if (func_02157928(ip))
		return;
	now = (unsigned short)(OS_GetTick() >> 16);
	for (i = 0; i < 8; i++) {
		if (g_021A8384[i].ip == ip) {
			g_021A8384[i].when = now;
			MI_CpuCopy(mac, g_021A8384[i].mac, 6);
			return;
		}
	}
	if (!new_entry)
		return;
	oldest_time = 0;
	candidate = 0;
	for (i = 0; i < 8; i++) {
		if (g_021A8384[i].ip == 0) {
			candidate = i;
			break;
		}
		if ((short)(now - g_021A8384[i].when) > oldest_time) {
			candidate = i;
			oldest_time = now - g_021A8384[i].when;
		}
	}
	g_021A8384[candidate].ip = ip;
	MI_CpuCopy(mac, g_021A8384[candidate].mac, 6);
	g_021A8384[candidate].when = now;
}










/*
 * sdk:      send_ether (libcps.TWL.HYB.a(network.o))
 */
void func_02158134(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type)
{
	unsigned char *mac_to;

	*(unsigned short *)(hdr - 2) = (type >> 8) | (type << 8);
	if (!func_02157928(ip_to)) {
		ip_to = func_021578C8(ip_to);
		if (ip_to == 0)
			return;
		mac_to = func_02157D8C(ip_to);
		if (mac_to == 0)
			mac_to = func_02157F60(ip_to);
		if (mac_to == 0)
			return;
		func_02082EA4(mac_to, hdr - 0xe, 6);
	} else {
		hdr[-0xe] = 1;
		hdr[-0xd] = 0;
		hdr[-0xc] = 0x5e;
		hdr[-0xb] = (ip_to >> 16) & 0x7f;
		hdr[-0xa] = ip_to >> 8;
		hdr[-9] = ip_to;
	}
	func_02082EA4(g_021A82D4, hdr - 8, 6);
	func_021579E8(hdr - 0xe, hdr_len + 0xe, body, body_len);
}


static inline unsigned short swap16(unsigned short x)
{
	return (unsigned short)((x >> 8) | (x << 8));
}



/*
 * sdk:      send_ip_frag (libcps.TWL.HYB.a network.o)
 */
void func_02158204(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset)
{
	unsigned long enabled;

	*(unsigned short *)(hdr - 0x12) = swap16((unsigned short)(hdr_len + 0x14 + body_len));
	*(unsigned short *)(hdr - 0xe) = swap16((unsigned short)offset);
	*(unsigned short *)(hdr - 0xa) = 0;
	*(unsigned short *)(hdr - 0xa) = swap16(func_0215781C(hdr - 0x14, 0x14));
	if (ip_to != 0x7f000001 && ip_to != g_021A826C.myip)
		func_02158134(hdr - 0x14, hdr_len + 0x14, body, body_len, ip_to, 0x800);
	if (ip_to != 0x7f000001 && ip_to != g_021A826C.myip && !func_02157928(ip_to))
		return;
	MI_CpuCopy(g_021A1CC0, hdr - 0x1c, 8);
	enabled = OS_DisableInterrupts();
	func_02157A44(g_021A82D4, g_021A82D4, hdr - 0x1c, hdr_len + 0x1c, body, body_len);
	OS_RestoreInterrupts(enabled);
}



/*
 * sdk:      send_ip (libcps.TWL.HYB.a network.o)
 */
void func_0215832C(u8 *hdr, u32 hdr_len, u8 *body, u32 body_len, u32 ip_to, u8 proto)
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
            func_02158204(hdr, 0, bodytmp, 0x5c8, ip_to, offset | 0x2000);
            bodytmp += 0x5c8;
            hdr_len -= 0x5c8;
            offset += 0xb9;
        }
        if (hdr_len != 0) {
            if (body_len != 0)
                func_02158204(hdr, 0, bodytmp, hdr_len, ip_to, offset | 0x2000);
            else
                func_02158204(hdr, 0, bodytmp, hdr_len, ip_to, offset);
            offset += hdr_len >> 3;
            hdr_len = 0;
        }
    }
    while (hdr_len + body_len > 0x5c8) {
        this_len = 0x5c8 - hdr_len;
        func_02158204(hdr, hdr_len, body, this_len, ip_to, offset | 0x2000);
        body_len -= this_len;
        hdr_len = 0;
        body += this_len;
        offset += 0xb9;
    }
    if (hdr_len + body_len == 0)
        return;
    func_02158204(hdr, hdr_len, body, body_len, ip_to, offset);
}



static u8 ip_conflict = 0;



static u8 wfailed = 0;



static u16 eport = 0;



static u16 mymss = 0;



static u16 ipid = 0;



static inline unsigned short SWAP16(unsigned short v)
{
	return (v >> 8) | (v << 8);
}



/*
 * u21: the defining object network.o is .comment 4.0.0.1024 -> dsi/1.1p1 and the size is already
 *      exact (180 B). The 46 concrete bytes are instruction ORDER in the prologue: the image loads
 *      both pool bases (wfailed, OSi_ThreadInfo) and the second OSi_ThreadInfo word before the
 *      first strh, 1.1p1 schedules the store first. First divergence +0018
 *      image `ldr r2, [pc, #0x90]` | ours `strh r4, [r5, #0x22]`.
 * u1: re-measured, unchanged (180 B, 46 concrete B).
 *
 * near miss (w2_s1): 46 bytes differ, schedule and register naming only: original loads the two pool bases (netvars, then OSi_ThreadInfo) before the first strh and keeps soc/icmp in r6/r5; 30+ statement orders and the chained-assignment forms tried.
 *
 * w8: recovered the vendor object's own DWARF via tools/sdkobj.py send_ping --region ov009
 *     (sdk/TwlWiFi/lib/ARM9-TS/Rom/libcps.TWL.HYB.a(network.o)). Its .debug_line gives the
 *     original statement order: 1229 icmp=soc->sndbuf.data, 1230 icmp+0x22=8, 1231 icmp+0x26=
 *     OSi_ThreadInfo[1], 1232 icmp+0x24=0, 1233 soc->local_port=seq=wfailed.ping_seq, 1234
 *     icmp+0x28/ping_seq++, 1235 checksum store, 1236 send_ip. Its .debug_info lists exactly ONE
 *     local (unsigned char *icmp) and declares wfailed as `unsigned char`, OSi_ThreadInfo as `int`.
 *     Ordering to the vendor line order flips the literal-pool emission (OSi_ThreadInfo first)
 *     because 1.1p1 materialises the first-referenced constant; the image keeps netvars first.
 *     `const` on OSi_ThreadInfo hoists its base above the first strh but also flips the pair.
 *     across the first strh (vendor hoists both bases; ours sinks the second) plus the seq home
 *     (vendor lr, ours ip). DWARF order reproduced gets the pool words right but not the schedule.
 *
 * w8 re-probed-2 (all parked at 46 B unless stated): making g_021A826C `const` AND storing ping_seq
 *     through a const-stripping cast does NOT let its base win the materialisation race -- still
 *     OSi first, same as OSi const alone, so the flip is not about the write. A `const unsigned
 *     long *osi = g_02150FEC` local with `(u16)osi[1]` also leaves 46 B. DWARF order plus
 *     `soc->local_port = seq = ...` chained = 55 B. Loading OSi[1] into a u16 local *ahead of* the
 *     0x22 store DOES hoist both bases with netvars first (pool pair correct) but overshoots: the
 *     netvars value load goes to the very top, 60 B. Decision: pure 1.1p1 pre-RA scheduling.
 *
 * w8 re-probed (all still 46 concrete B): `const` on g_02150FEC hoists BOTH bases above the
 *     first strh -- the schedule half of the residue -- but materialises OSi_ThreadInfo first,
 *     flipping the pool pair (netvars must stay first). const-read/const-pointer-local of either
 *     base, a named local for the loaded OSi word, and moving the netvars store earlier all fail
 *     to hoist without flipping the pair; DWARF statement order gives 56 B (OSi first, load sunk).
 *
 * lane03 (2026-10-01): network.o's symbol table has
 *     `_ZZ9send_pingPhmP7_CPSSocE7pingseq`, a FUNCTION-LOCAL `static u16 pingseq`
 *     at .bss+8 (the "wfailed" relocation is the .bss section base). As a
 *     local static whose address is never taken it cannot alias the icmp
 *     stores, so 1.1p1 hoists its load and increment above them exactly as the
 *     image does; no `seq`/`ck` stand-ins remain (DWARF: icmp only; the byte
 *     swap is a static inline, a macro would call the checksum twice).
 *     46 B -> 2 B. Residue: our .bss holds only pingseq, so it sits at +0 and
 *     the two halfword accesses use #0 where the image uses #8; the .bss
 *     relocation stays wildcarded (the vendor `.bss` route is ARM9-only).
 *     File-scope copies of the five leading statics (wfailed, ip_conflict,
 *     ipid, mymss, eport) are always laid out after a function static, and
 *     file-scope or struct-member pingseq loses the no-alias hoist (184 B).
 *
 * lane17 (2026-10-01): EXACT. network.o's leading .bss statics written as
 *     zero-initialised file statics (wfailed, ip_conflict, ipid, mymss,
 *     eport, declared in the order 1.1p1's size-group reshuffle lays out as
 *     +0..+6), so pingseq lands at .bss+8 as in the vendor symtab; each
 *     static named in symbols: so the .bss reloc resolves (6 agree on base).
 *
 * sdk:      send_ping (libcps.TWL.HYB.a(network.o))
 */
void func_02158524(unsigned char *pattern, unsigned long len, struct _CPSSoc *soc)
{
	static unsigned short pingseq;
	unsigned char *icmp;

	icmp = soc->sndbuf.data;
	*(unsigned short *)(icmp + 0x22) = 8;
	*(unsigned short *)(icmp + 0x26) = (u32)g_02150FEC.current;
	*(unsigned short *)(icmp + 0x24) = 0;
	soc->local_port = pingseq;
	*(unsigned short *)(icmp + 0x28) = pingseq++;
	*(unsigned short *)(icmp + 0x24) = SWAP16(func_02157808((unsigned short)func_02157700(pattern, len, func_02157700(icmp + 0x22, 8, 0))));
	func_0215832C(icmp + 0x22, 8, pattern, len, soc->remote_ip, 1);
}



/*
 * sdk:      send_udp (libcps.TWL.HYB.a network.o)
 */
void func_021585D8(unsigned char *data, unsigned long len, struct _CPSSoc *soc)
{
	unsigned char *hdr;

	hdr = soc->sndbuf.data + 0x22;
	*(unsigned short *)(hdr - 0xc) = swap16((unsigned short)(g_021A826C.myip >> 16));
	*(unsigned short *)(hdr - 0xa) = swap16((unsigned short)g_021A826C.myip);
	*(unsigned short *)(hdr - 0x8) = swap16((unsigned short)(soc->remote_ip >> 16));
	*(unsigned short *)(hdr - 0x6) = swap16((unsigned short)soc->remote_ip);
	*(unsigned short *)(hdr - 0x4) = 0x1100;
	*(unsigned short *)(hdr + 4) = swap16((unsigned short)(len + 8));
	*(unsigned short *)(hdr - 0x2) = *(unsigned short *)(hdr + 4);
	*(unsigned short *)(hdr + 2) = swap16(soc->remote_port);
	*(unsigned short *)(hdr + 0) = swap16(soc->local_port);
	*(unsigned short *)(hdr + 6) = 0;
	*(unsigned short *)(hdr + 6) = swap16(func_02157808((unsigned short)func_02157700(data, len, func_02157700(hdr - 0xc, 0x14, 0))));
	func_0215832C(hdr, 8, data, len, soc->remote_ip, 0x11);
}
