/*
 * function: func_021651AC
 * address:  0x021651AC
 * packet:   pkt_021651AC
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
 *   func_021651D4   0x021651D4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02027060(int);
extern void func_02026FB8(void *);
extern char *g_02146940;
extern void func_021651D4(void *, void *);

void func_021651AC(void *a0)
{
    if (func_02027060(0x7)) {
        func_021651D4(g_02146940 + 4, a0);
        func_02026FB8(g_02146940 + 4);
    }
}

