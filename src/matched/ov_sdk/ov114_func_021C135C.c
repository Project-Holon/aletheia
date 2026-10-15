/*
 * function: ghiFreeCertificateInfo
 * address:  0x021C135C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Releases the handle at +0x00 and empties the +0x00/+0x04 pair.
 *
 * symbols:
 *   gsifree  0x0217EAE0  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern void gsifree(void *);

void ghiFreeCertificateInfo(u8 *p)
{
    void *q = *(void **)p;

    *(u32 *)(p + 4) = 0;
    gsifree(q);
    *(u32 *)p = 0;
}
