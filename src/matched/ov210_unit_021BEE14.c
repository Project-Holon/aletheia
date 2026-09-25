/*
 * unit:     yes
 * function: func_021BEE14, func_021BEE38, func_021BEE58
 * address:  0x021BEE14
 * packet:   pkt_021BEE14
 * region:   ov210
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B688 0x0204B688 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B454 0x0204B454 arm
 */

extern void func_0204B688(void *, int);
extern void func_0204B404(void *, void *, unsigned short);
extern void func_0204B454(void *, void *, unsigned short);

void func_021BEE14(char *p, int idx, int flag)
{
    if (flag == 1)
    {
        func_0204B688(*(void **)(p + 0x28 + idx * 4), 1);
    }
    else
    {
        func_0204B688(*(void **)(p + 0x28 + idx * 4), 0);
    }
}

void func_021BEE38(char *p, int idx, unsigned short a, unsigned short b, unsigned short c)
{
    unsigned short buf[2];
    buf[0] = a;
    buf[1] = b;
    func_0204B404(*(void **)(p + idx * 4 + 0x28), buf, c);
}

void func_021BEE58(char *p, int idx, short *outA, short *outB, unsigned short in)
{
    short buf[2];
    func_0204B454(*(void **)(p + idx * 4 + 0x28), buf, in);
    *outA = buf[0];
    *outB = buf[1];
}
