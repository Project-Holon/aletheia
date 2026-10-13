/*
 * function: CRYPTOi__BN_new
 * address:  0x021CACE4
 * packet:   pkt_ov114_021CACE4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_new (crypto_bobj1.o)
 *
 * symbols:
 *   CRYPTOi_MyAlloc  0x021CAAB4  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void *CRYPTOi_MyAlloc(unsigned long);

void *CRYPTOi__BN_new(void)
{
    u8 *p = CRYPTOi_MyAlloc(0x14);
    if (p == 0)
        return 0;
    *(u32 *)(p + 0x10) = 1;
    *(u32 *)(p + 4) = 0;
    *(u32 *)(p + 0xc) = 0;
    *(u32 *)(p + 8) = 0;
    *(u32 *)p = 0;
    return p;
}
