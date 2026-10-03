/*
 * function: func_0216530C
 * address:  0x0216530C
 * packet:   pkt_0216530C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Test the id against the overlay's table and, when it takes,
 * re-submit the record at the shared globals pointer.
 *
 * symbols:
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_02165334   0x02165334  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern char *g_02146940;
extern void func_02165334(void *, void *);

void func_0216530C(void *a0)
{
    if (func_02027060(0x13)) {
        func_02165334(g_02146940 + 4, a0);
        func_02026FB8(g_02146940 + 4);
    }
}

