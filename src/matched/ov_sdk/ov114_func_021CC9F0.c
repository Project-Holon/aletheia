/*
 * function: func_021CC9F0
 * address:  0x021CC9F0
 * packet:   pkt_ov114_021CC9F0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CRYPTOi__BN_MONT_CTX_init (crypto_bobj1.o)
 *
 * symbols:
 *   func_021CACD0  0x021CACD0  arm  ov114
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021CACD0(int a);

void func_021CC9F0(u8 *p)
{
    *(u32 *)p = 0;
    *(u32 *)(p + 8) = 0;
    func_021CACD0((int)(p + 0xc));
    func_021CACD0((int)(p + 0x20));
    func_021CACD0((int)(p + 0x34));
    *(u32 *)(p + 0x4c) = 0;
}
