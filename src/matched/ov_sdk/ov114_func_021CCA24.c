/*
 * function: CRYPTOi__BN_MONT_CTX_free
 * address:  0x021CCA24
 * packet:   pkt_ov114_021CCA24
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_MONT_CTX_free (crypto_bobj1.o)
 *
 * symbols:
 *   CRYPTOi__BN_free  0x021CABDC  arm  ov114
 *   CRYPTOi_MyFree  0x021CAAE8  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void CRYPTOi__BN_free(u8 *);
extern void CRYPTOi_MyFree(void *);

void CRYPTOi__BN_MONT_CTX_free(u8 *p)
{
    CRYPTOi__BN_free(p + 0xc);
    CRYPTOi__BN_free(p + 0x20);
    CRYPTOi__BN_free(p + 0x34);
    if (*(u32 *)(p + 0x4c) & 1)
        CRYPTOi_MyFree(p);
}
