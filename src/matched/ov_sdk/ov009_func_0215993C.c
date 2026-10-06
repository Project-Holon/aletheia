/*
 * function: func_0215993C
 * address:  0x0215993C
 * packet:   pkt_ov009_0215993C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      merge_rwin_chunks (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_021599EC  0x021599EC  arm  ov009
 */

struct Chunk {
	unsigned long start;
	unsigned long len;
	unsigned long aux;
};

struct Soc {
	unsigned char pad0[0x24];
	unsigned long ackno;
	unsigned char pad1[0x28];
	unsigned long rcvbufp;
	unsigned char pad2[0x1c];
	struct Chunk chunks[4];
};

extern void func_021599EC(char *p);

void func_0215993C(struct Soc *soc)
{
	long ci;

again:
	if (soc->chunks[0].start != 0 && soc->rcvbufp >= soc->chunks[0].start) {
		soc->ackno += soc->chunks[0].start + soc->chunks[0].len - soc->rcvbufp;
		soc->rcvbufp = soc->chunks[0].start + soc->chunks[0].len;
		soc->chunks[0].start = 0;
		func_021599EC((char *)soc);
	}
	for (ci = 0; ci < 3; ci++) {
		if (soc->chunks[ci].start != 0 && soc->chunks[ci + 1].start != 0 &&
		    soc->chunks[ci].start + soc->chunks[ci].len >= soc->chunks[ci + 1].start) {
			soc->chunks[ci].len = soc->chunks[ci + 1].start + soc->chunks[ci + 1].len - soc->chunks[ci].start;
			soc->chunks[ci + 1].start = 0;
			func_021599EC((char *)soc);
			goto again;
		}
	}
}
