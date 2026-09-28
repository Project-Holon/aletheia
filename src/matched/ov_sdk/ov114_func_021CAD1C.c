/*
 * function: func_021CAD1C
 * address:  0x021CAD1C
 * packet:   pkt_ov114_021CAD1C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_CTX_new (crypto_bobj1.o)
 *
 * symbols:
 *   func_021CAAB4  0x021CAAB4  arm  ov114
 *   func_021CAD48  0x021CAD48  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_021CAAB4(unsigned long);
extern void func_021CAD48(u8 *);

void *func_021CAD1C(void)
{
    u8 *p = func_021CAAB4(0x110);
    if (p == 0)
        return 0;
    func_021CAD48(p);
    *(u32 *)(p + 0x108) = 1;
    return p;
}
