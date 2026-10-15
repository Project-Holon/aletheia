/*
 * function: gsiSoapTaskCleanup
 * address:  0x02180080
 * packet:   pkt_02180080
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Destructor: releases three optional sub-objects then the object itself, and
 * always reports success.
 *
 * symbols:
 *   gsXmlFreeReader  0x02181DA0  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   ghttpFreePostAndUpdateConnection  0x021C2324  arm  ov114
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void gsXmlFreeReader(int x);
void gsifree(void *p);
void ghttpFreePostAndUpdateConnection(int x, int y);

int gsiSoapTaskCleanup(int *p)
{
    if (p[5])
        gsXmlFreeReader(p[5]);
    if (p[6])
        gsifree((void *)p[6]);
    if (p[7])
        ghttpFreePostAndUpdateConnection(p[10], p[7]);
    gsifree((void *)((int)p));
    return 1;
}
