/*
 * function: func_021CAD6C
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
 *   func_021CABC0  0x021CABC0  arm  ov114
 *   func_021CAAE8  0x021CAAE8  arm  ov114
 *
 * The twelve BIGNUMs embedded at ctx+4 (stride 20) are cleared, then the
 * context itself is released when its malloc flag is set.
 */

typedef unsigned char u8;

extern void func_021CABC0(void *);
extern void func_021CAAE8(void *);

void func_021CAD6C(u8 *ctx)
{
    int i;
    for (i = 0; i < 12; i++)
        func_021CABC0(ctx + 4 + i * 20);
    if (*(unsigned int *)(ctx + 0x108) & 1)
        func_021CAAE8(ctx);
}
