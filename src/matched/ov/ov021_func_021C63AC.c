/*
 * function: func_021C63AC
 * address:  0x021C63AC
 * packet:   pkt_ov021_021C63AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DE4A8     0x021DE4A8  data  ov021  a1
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    void *f8;
    void *fC;
} Work;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021DE4A8[];

Work *func_021C63AC(u32 heap, u32 n, u32 m)
{
    Work *w;

    w = func_02030734(heap, 0x14, 1, d_021DE4A8, 0x72);
    w->f8 = func_02030734(heap, n * 0x2c, 1, d_021DE4A8, 0x75);
    w->fC = func_02030734(heap, m * 0x68, 1, d_021DE4A8, 0x78);
    w->f0 = heap;
    w->f4 = n;
    w->f6 = m;
    w->f2 = 1;
    return w;
}
