/*
 * function: func_021CC9C4
 * address:  0x021CC9C4
 * packet:   pkt_ov114_021CC9C4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_MONT_CTX_new (crypto_bobj1.o)
 *
 * symbols:
 *   func_021CAAB4  0x021CAAB4  arm  ov114
 *   func_021CC9F0  0x021CC9F0  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_021CAAB4(unsigned long);
extern void func_021CC9F0(u8 *);

void *func_021CC9C4(void)
{
    u8 *p = func_021CAAB4(0x50);
    if (p == 0)
        return 0;
    func_021CC9F0(p);
    *(u32 *)(p + 0x4c) = 1;
    return p;
}
