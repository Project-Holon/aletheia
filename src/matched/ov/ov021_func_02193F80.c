/*
 * function: func_02193F80
 * address:  0x02193F80
 * packet:   pkt_ov021_02193F80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm  arm9
 *   func_02161ECC  0x02161ECC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct E50 {
    u16 f00;
    u16 f02;
    u8  f04[0x30];
    u8  f34[0x18];
    u16 f4c;
    u16 f4e;
} E50;

extern void func_02161ECC(void *a);
extern void func_02082D44(void *src, void *dst, int n);

void func_02193F80(E50 *e, void *a, u8 *b, void *c)
{
    func_02161ECC(a);
    e->f00 = 1;
    func_02082D44(a, e->f34, 0x18);
    func_02082D44(c, e->f04, 0x30);
    e->f4c = b[0];
    e->f4e = b[1];
}
