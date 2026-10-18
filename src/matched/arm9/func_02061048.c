/*
 * unit:     no
 * function: NNSi_FndAllocFromFrmHeapTail
 * address:  0x02061048
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

extern void MIi_CpuClear32(int a, int b, int c);
unsigned int NNSi_FndAllocFromFrmHeapTail(unsigned int *p, unsigned int a, unsigned int b)
{
    unsigned int v = (p[1] - a) & ~(b - 1);
    unsigned int r2;
    unsigned char c;
    if (v < p[0])
        return 0;
    r2 = p[1] - v;
    c = (unsigned char)p[-1];
    if (c & 1)
        MIi_CpuClear32(0, (int)v, (int)r2);
    p[1] = v;
    return v;
}

