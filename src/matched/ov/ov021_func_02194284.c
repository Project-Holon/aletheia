/*
 * function: func_02194284
 * address:  0x02194284
 * packet:   pkt_ov021_02194284
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDA70     0x021DDA70  data  a4
 */

typedef unsigned short u16;

extern int d_021DDA70;

void *func_02030734(int a, int b, int c, void *d, int e);

void *func_02194284(int a, void *b, int heap, int c)
{
    int n = 0xc;
    char *p = (char *)func_02030734(heap, n, 1, &d_021DDA70, 0x5d);

    *(u16 *)p = a;
    *(u16 *)(p + 2) = c;
    *(void **)(p + 4) = b;
    *(void **)(p + 8) = func_02030734(heap, n * a, 1, &d_021DDA70, 0x63);
    return p;
}
