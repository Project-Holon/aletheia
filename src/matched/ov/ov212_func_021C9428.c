/*
 * function: func_021C9428
 * address:  0x021C9428
 * packet:   pkt_021C9428
 * region:   ov212
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 */

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);

void func_021C9428(int p, int b, int c)
{
    unsigned char *q = func_02030734(c, 0x48, 1, (const char *)0x021C99A8, 0x1ce);

    *(int *)q = p;
    *(int *)(q + 4) = b;
    *(unsigned short *)(q + 8) = 0;
    *(int *)(q + 0xc) = 0;
    *(unsigned short *)(q + 0x10) = 0;
    *(int *)(q + 0x3c) = 0;
    *(unsigned short *)(q + 0x40) = 0;
    *(int *)(q + 0x44) = 0;
}
