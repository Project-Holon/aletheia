/*
 * file:     unit_021573C4_p13.c
 * unit:     yes
 * function: func_0215993C, func_021599EC
 * address:  0x0215993C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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

struct S { int a, b, c; };

void func_0215993C(struct Soc *soc);
void func_021599EC(char *p);


/*
 * sdk:      merge_rwin_chunks (libcps.TWL.HYB.a(network.o))
 */
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


/*
 * For every one of the three 0xc-byte records whose +0x70 triple is zero,
 * pulls the +0x7c triple down into +0x70 and clears +0x7c.
 */
void func_021599EC(char *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        char *e = p + i * 0xc;

        if (*(int *)(e + 0x70) == 0) {
            *(struct S *)(e + 0x70) = *(struct S *)(e + 0x7c);
            *(int *)(e + 0x7c) = 0;
        }
    }
}
