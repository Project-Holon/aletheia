/*
 * function: func_0216E4B0
 * address: 0x0216E4B0
 * packet: pkt_ov010_0216E4B0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: declaring x and y before the unsigned-long index restores the
 * table base, sentinel and index register allocation. The once300
 * permuter found this ordering; explicit-region one resolves both pools.
 * symbols:
 *   d_02172A70 0x02172A70 data a2
 */

typedef unsigned short u16;
extern const u16 d_02172A70[][4];

int func_0216E4B0(int a, int b)
{
    int x;
    int y;
    unsigned long i;
    i = 0;
    do
    {
        x = d_02172A70[i][0];
        y = d_02172A70[i][1];
        if ((x == a) && (y == b))
            return d_02172A70[i][2];
        i++;
    }
    while ((x != 65535) && (y != 65535));
    return 30;
}
