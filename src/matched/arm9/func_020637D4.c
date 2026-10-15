/*
 * function: NNSi_G2dInitVramHandleEx
 * address:  0x020637D4
 * packet:   pkt_020637BC
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

void NNSi_G2dInitVramHandleEx(u32 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p[i + 2] = 0xffffffff;
    }
}
