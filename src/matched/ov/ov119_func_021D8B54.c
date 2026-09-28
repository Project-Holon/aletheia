/*
 * function: func_021D8B54
 * address:  0x021D8B54
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035CB8  0x02035CB8  arm
 */

typedef signed short s16;

extern unsigned int func_02035CB8(int *a, int *b);

void func_021D8B54(void *p)
{
    int o1, o2;
    int d;

    if (func_02035CB8(&o1, &o2) == 0)
        return;
    if (*(int *)((char *)p + 0xf60) == 0)
        *(int *)((char *)p + 0xf5c) = 0;
    if (*(int *)((char *)p + 0xf60) != 0) {
        d = ((s16)*(short *)((char *)p + 0xf64) - (s16)*(short *)((char *)p + 0xf68)) - o1;
        if (d < 0)
            d = -d;
        if (d > 2)
            *(int *)((char *)p + 0xf5c) = 1;
        d = ((s16)*(short *)((char *)p + 0xf66) - (s16)*(short *)((char *)p + 0xf6a)) - o2;
        if (d < 0)
            d = -d;
        if (d > 2)
            *(int *)((char *)p + 0xf5c) = 1;
        d = (s16)*(short *)((char *)p + 0xf64) - o1;
        if (d < 0)
            d = -d;
        if (d > 6) {
            d = (s16)*(short *)((char *)p + 0xf66) - o2;
            if (d < 0)
                d = -d;
            if (d > 6)
                *(int *)((char *)p + 0xf70) = 0;
        }
    }
    if ((unsigned int)o2 >= 0x10 && (unsigned int)o2 < 0x90) {
        *(int *)((char *)p + 0xf54) = o1;
        *(int *)((char *)p + 0xf58) = o2;
    }
}
