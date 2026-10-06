/*
 * function: func_021F669C
 * address:  0x021F669C
 * packet:   pkt_021F669C
 * region:   ov215
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 */

typedef unsigned int   u32;
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(int);

void func_021F669C(int *p)
{
    func_02046788(func_02048AC4((void *)(*p)));
}