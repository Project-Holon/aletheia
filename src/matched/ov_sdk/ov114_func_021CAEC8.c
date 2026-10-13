/*
 * function: CRYPTOi__BN_set_word
 * address:  0x021CAEC8
 * packet:   pkt_ov114_021CAEC8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_set_word (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_RECP_CTX_set
 *
 * symbols:
 *   CRYPTOi__bn_expand2  0x021CADAC  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *CRYPTOi__bn_expand2(u8 *a, int n);

int CRYPTOi__BN_set_word(u8 *a, unsigned long w)
{
    u8 *A;
    A = (*(int *)(a + 8) < 1) ? CRYPTOi__bn_expand2(a, 2) : a;
    if (A == 0)
        return 0;
    *(u32 *)(a + 0xc) = 0;
    *(u32 *)(a + 4) = 0;
    *(u32 *)*(u32 **)a = w;
    if (*(u32 *)*(u32 **)a != 0)
        *(u32 *)(a + 4) = 1;
    return 1;
}
