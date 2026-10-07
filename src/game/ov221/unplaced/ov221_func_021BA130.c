/*
 * function: func_021BA130
 * address:  0x021BA130
 * packet:   pkt_ov221_021BA130
 * region:   ov221
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048AC4  0x02048AC4  arm
 *   func_02046788  0x02046788  arm
 */

typedef unsigned int   u32;
extern u32 func_02048AC4(void *ptr);
extern int func_02046788(int);

int func_021BA130(int *p)
{
    return func_02046788(func_02048AC4((void *)(*p)));
}
