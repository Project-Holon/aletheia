/*
 * function: func_02208814
 * address:  0x02208814
 * packet:   pkt_02208814
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02208A38 0x02208A38 thumb
 */

typedef unsigned int   u32;
extern void func_02208A38(char *p, u32 v);

void func_02208814(char *a)
{
    func_02208A38((char *)(*(int *)(a + 0x10)), 0x1e);
    if (*(int *)(a + 8) == 1)
        *(int *)(a + 8) = 2;
}