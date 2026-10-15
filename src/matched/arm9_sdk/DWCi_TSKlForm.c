/*
 * function: NNSi_GfdAllocBlockUnaligned
 * address:  0x02061EA4
 * packet:   pkt_02061EA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_GfdAllocLnkVram 0x02061EB8 arm
 */

typedef unsigned int u32;
struct Blk;
extern int NNSi_GfdAllocLnkVram(struct Blk **list, struct Blk **pool, u32 *pRet, u32 size, u32 alignment);

int NNSi_GfdAllocBlockUnaligned(struct Blk **list, struct Blk **pool, u32 *pRet, u32 size)
{
    return NNSi_GfdAllocLnkVram(list, pool, pRet, size, 0);
}
