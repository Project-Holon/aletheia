/*
 * function: func_021EF1AC
 * address:  0x021EF1AC
 * packet:   pkt_021EF1AC
 * region:   ov188
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 */
typedef unsigned int u32;

extern void func_02082D44(void *, void *, int);

int func_021EF1AC(char *p, char *q)
{
    u32 a = *(u32 *)(p + 0x94);

    if (a != 0) {
        u32 b = *(u32 *)(p + 0x98);

        if (b < 0xc00) {
            *(u32 *)(q + 0x34) = b;
            func_02082D44((void *)a, q + 0x38, b);
            return 1;
        }
    }
    return 0;
}
