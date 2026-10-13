/*
 * function: CRYPTOi__BN_RECP_CTX_set
 * address:  0x021CCAAC
 * packet:   pkt_ov114_021CCAAC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_RECP_CTX_set (crypto_bobj1.o)
 *
 * symbols:
 *   CRYPTOi__BN_copy  0x021CAE20  arm  ov114
 *   CRYPTOi__BN_set_word  0x021CAEC8  arm  ov114
 *   CRYPTOi__BN_num_bits  0x021CAB94  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *CRYPTOi__BN_copy(u8 *a, u8 *b);
extern int CRYPTOi__BN_set_word(u8 *, unsigned long);
extern char *CRYPTOi__BN_num_bits(u8 *p);

int CRYPTOi__BN_RECP_CTX_set(u8 *p, u8 *b)
{
    CRYPTOi__BN_copy(p, b);
    CRYPTOi__BN_set_word(p + 0x14, 0);
    *(u32 *)(p + 0x28) = (u32)CRYPTOi__BN_num_bits(b);
    *(u32 *)(p + 0x2c) = 0;
    return 1;
}
