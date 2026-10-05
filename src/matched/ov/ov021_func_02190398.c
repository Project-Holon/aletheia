/*
 * function: func_02190398
 * address:  0x02190398
 * packet:   pkt_ov021_02190398
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02194798  0x02194798  thumb  ov021
 *   func_02192E0C  0x02192E0C  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   func_02192EB8  0x02192EB8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;

extern void func_02194798(unsigned char *a);
extern void func_02192E0C(u32 *p);
extern u32 func_020056A0(void *fn, void *arg, int z);
typedef unsigned char  u8;
extern void func_02192EB8(u32 a, u8 *b);

void func_02190398(u32 *p)
{
    if (p[0x57] != 0) {
        func_02194798((unsigned char *)p[0x57]);
    }
    func_02192E0C(p);
    if (p[0x5b] == 0) {
        p[0x5b] = func_020056A0((void *)func_02192EB8, p, 0);
    }
}
