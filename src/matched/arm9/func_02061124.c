/*
 * unit:     no
 * function: NNS_FndAllocFromFrmHeapEx
 * address:  0x02061124
 * packet:   pkt_02060CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndAllocFromFrmHeapHead  0x02060FEC  arm
 *   NNSi_FndAllocFromFrmHeapTail  0x02061048  arm
 */

typedef unsigned int   u32;
struct Heap;
extern u32 NNSi_FndAllocFromFrmHeapHead(struct Heap *h, u32 size, u32 align);
extern unsigned int NNSi_FndAllocFromFrmHeapTail(unsigned int *p, unsigned int a, unsigned int b);
unsigned int NNS_FndAllocFromFrmHeapEx(char *p, int n, int v)
{
    if (n == 0)
        n = 1;
    n = (n + 3) & ~3;
    p += 0x24;
    if (v >= 0)
        return NNSi_FndAllocFromFrmHeapHead((struct Heap *)p, (unsigned int)n, (unsigned int)v);
    else
        return NNSi_FndAllocFromFrmHeapTail((unsigned int *)p, (unsigned int)n, (unsigned int)-v);
}
