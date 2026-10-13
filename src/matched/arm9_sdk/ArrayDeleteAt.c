/*
 * function: ArrayDeleteAt
 * address:  0x02005D90
 * packet:   pkt_02005D90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005F90 0x02005F90 thumb
 *   func_02005D34 0x02005D34 thumb
 */

typedef unsigned int u32;
extern void func_02005F90(void);
extern void *func_02005D34(u32 a0, u32 a1);

void ArrayDeleteAt(u32 a0, u32 a1)
{
    func_02005F90();
    func_02005D34(a0, a1);
}
