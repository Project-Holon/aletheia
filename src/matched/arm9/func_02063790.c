/*
 * function: NNSi_G2dInitVramHandle
 * address:  0x02063790
 * packet:   pkt_02063790
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void NNSi_G2dInitVramHandle(u32 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p[i] = 0xffffffff;
    }
}
