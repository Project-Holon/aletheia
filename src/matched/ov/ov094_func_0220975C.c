/*
 * function: func_0220975C
 * address:  0x0220975C
 * packet:   pkt_ov094_0220975C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AEF0     0x0220AEF0  data  ov094
 */

typedef unsigned short u16;
typedef struct {
    void *f0;
    int f4;
    u16 f8;
} W;
extern W *func_02030734(u16 heap, int size, int clear, char *file, int line);
extern char d_0220AEF0[];

W *func_0220975C(void *a, u16 heap)
{
    W *w = func_02030734(heap, 0xc, 1, d_0220AEF0, 0x48);
    w->f0 = a;
    w->f8 = heap;
    return w;
}
