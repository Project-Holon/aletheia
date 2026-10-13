/*
 * function: CRYPTOi__BN_CTX_free
 * address:  0x021CAD6C
 * packet:   pkt_ov114_021CAD6C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_CTX_free (crypto_bobj1.o)
 *
 * symbols:
 *   CRYPTOi__BN_clear_free  0x021CABC0  arm  ov114
 *   CRYPTOi_MyFree  0x021CAAE8  arm  ov114
 *
 * The twelve BIGNUMs embedded at ctx+4 (stride 20) are cleared, then the
 * context itself is released when its malloc flag is set.
 */

typedef unsigned char u8;

extern void CRYPTOi__BN_clear_free(int a);
extern void CRYPTOi_MyFree(void *);

void CRYPTOi__BN_CTX_free(u8 *ctx)
{
    int i;
    for (i = 0; i < 12; i++)
        CRYPTOi__BN_clear_free((int)(ctx + 4 + i * 20));
    if (*(unsigned int *)(ctx + 0x108) & 1)
        CRYPTOi_MyFree(ctx);
}
