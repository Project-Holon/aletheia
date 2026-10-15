/*
 * function: NNSi_G2dFixupMultiCellAnimBankTbl
 * address:  0x0206295C
 * packet:   pkt_0206295C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_G2dFixupOffsets 0x02062BAC arm
 */

typedef unsigned char u8;
struct Tbl;
extern void NNSi_G2dFixupOffsets(struct Tbl *t);

void NNSi_G2dFixupMultiCellAnimBankTbl(void *animBank)
{
    NNSi_G2dFixupOffsets((struct Tbl *)((u8 *)animBank + 8));
}
