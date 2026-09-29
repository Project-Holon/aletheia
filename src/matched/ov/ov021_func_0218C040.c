/*
 * function: func_0218C040
 * address:  0x0218C040
 * packet:   pkt_ov021_0218C040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020477A4  0x020477A4  arm
 *   func_02047804  0x02047804  arm
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020477A4(void *h, u16 i);
extern void func_02047804(void *h, u16 i);
extern u8 *func_0218BCAC(void *p);

void func_0218C040(void *a, void **b)
{
    u8 *t;
    u32 n;
    int i;

    t = func_0218BCAC(*(void **)b[1]);
    n = t[2];
    for (i = 0; i < 4 && i < n; i++) {
        func_020477A4(b[0], i);
        func_02047804(b[0], i);
        b[2 + i] = (void *)1;
    }
    for (; i < 4; i++)
        b[2 + i] = 0;
}
