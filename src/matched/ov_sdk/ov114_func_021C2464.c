/*
 * function: ghiFreePost
 * address:  0x021C2464
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Releases the +0x00 handle, clears it, then tears the record down.
 *
 * symbols:
 *   gsifree  0x0217EAE0  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021841B0(u32);
extern void gsifree(u8 *);

void ghiFreePost(u8 *p)
{
    if (*(u32 *)p != 0)
        func_021841B0(*(u32 *)p);
    *(u32 *)p = 0;
    gsifree(p);
}
