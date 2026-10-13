/*
 * function: CRYPTOi__BN_CTX_new
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
 *   CRYPTOi_MyAlloc  0x021CAAB4  arm  ov114
 *   CRYPTOi__BN_CTX_init  0x021CAD48  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void *CRYPTOi_MyAlloc(unsigned long);
extern void CRYPTOi__BN_CTX_init(u8 *);

void *CRYPTOi__BN_CTX_new(void)
{
    u8 *p = CRYPTOi_MyAlloc(0x110);
    if (p == 0)
        return 0;
    CRYPTOi__BN_CTX_init(p);
    *(u32 *)(p + 0x108) = 1;
    return p;
}
