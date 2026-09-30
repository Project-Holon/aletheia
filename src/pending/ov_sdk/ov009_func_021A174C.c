/*
 * function: func_021A174C
 * address:  0x021A174C
 * packet:   pkt_ov009_021A174C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * u1: family check done - ../2.0/base + ../2.0/sp1p2 byte-identical (112 B), ../1.2/sp3 115 B. Swap-temporary allocation.
 *
 * near miss (w3_s4): 112 bytes differ, register allocation of the swap temporaries. Original holds cookie in r5 with temps r4/r8/r3/r6 and loads the six constants into r7/r6/r5/r4/lr/fp after the swap has started; mine keeps cookie in r4. Interleaved stores, pointer-increment stores, array initializer (becomes a ldr/str copy loop) tried.
 *
 * sdk:      SBSendNatNegotiateCookieToServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_021A1620  0x021A1620  arm  ov009
 */

extern int func_021A1620(void *slist, unsigned int ip, unsigned short port, char *data, int len);
#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
int func_021A174C(void *slist, unsigned int ip, unsigned short port, int cookie)
{
	unsigned char negotiateBuffer[10];
	unsigned char *p;
	unsigned char *src;
	p = negotiateBuffer;
	*p++ = 0xfd;
	*p++ = 0xfc;
	*p++ = 0x1e;
	*p++ = 0x66;
	*p++ = 0x6a;
	*p++ = 0xb2;
	cookie = SWAP32((unsigned int)cookie);
	src = (unsigned char *)&cookie;
	*p++ = *src++;
	*p++ = *src++;
	*p++ = *src++;
	*p++ = *src++;
	return func_021A1620(slist, ip, port, (char *)negotiateBuffer, 10);
}
