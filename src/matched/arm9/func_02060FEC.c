/*
 * function: NNSi_FndAllocFromFrmHeapHead
 * address:  0x02060FEC
 * packet:   pkt_02060FA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Heap {
    u32 cur;    /* +0x00 */
    u32 limit;  /* +0x04 */
};

extern void MIi_CpuClear32(u32 data, void *dest, u32 size);

u32 NNSi_FndAllocFromFrmHeapHead(struct Heap *h, u32 size, u32 align)
{
    u32 amask = align - 1;
    u32 p = (amask + h->cur) & ~amask;
    u32 e = size + p;
    u32 sz;

    if (e > h->limit) {
        return 0;
    }

    sz = e - h->cur;
    if ((u8)((u32 *)h)[-1] & 1) {
        MIi_CpuClear32(0, (void *)h->cur, sz);
    }

    h->cur = e;
    return p;
}
