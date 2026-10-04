/*
 * function: func_021652C4
 * address:  0x021652C4
 * packet:   pkt_021652C4
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
 *   func_021652EC   0x021652EC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern char *g_02146940;
struct Obj;
extern void func_021652EC(struct Obj *p, u32 v);

void func_021652C4(void *a0)
{
    if (func_02027060(0x12)) {
        func_021652EC((struct Obj *)(g_02146940 + 4), (u32)a0);
        func_02026FB8(g_02146940 + 4);
    }
}

