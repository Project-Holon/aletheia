/*
 * function: func_021CCA80
 * address:  0x021CCA80
 * packet:   pkt_ov114_021CCA80
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_RECP_CTX_free (crypto_bobj1.o)
 *
 * symbols:
 *   func_021CABDC  0x021CABDC  arm  ov114
 *   func_021CAAE8  0x021CAAE8  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021CABDC(u8 *);
extern void func_021CAAE8(void *);

void func_021CCA80(u8 *p)
{
    func_021CABDC(p);
    func_021CABDC(p + 0x14);
    if (*(u32 *)(p + 0x30) & 1)
        func_021CAAE8(p);
}
