/*
 * function: func_021CCAAC
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
 *   func_021CAE20  0x021CAE20  arm  ov114
 *   func_021CAEC8  0x021CAEC8  arm  ov114
 *   func_021CAB94  0x021CAB94  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021CAE20(u8 *a, u8 *b);
extern int func_021CAEC8(u8 *, unsigned long);
extern int func_021CAB94(u8 *);

int func_021CCAAC(u8 *p, u8 *b)
{
    func_021CAE20(p, b);
    func_021CAEC8(p + 0x14, 0);
    *(u32 *)(p + 0x28) = func_021CAB94(b);
    *(u32 *)(p + 0x2c) = 0;
    return 1;
}
