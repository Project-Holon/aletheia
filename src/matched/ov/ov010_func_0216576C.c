/*
 * function: func_0216576C
 * address:  0x0216576C
 * packet:   pkt_ov010_0216576C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Test id 0x2F against the overlay's table and, when it takes, file the
 * record at the shared globals pointer (sibling of func_02165634).
 *
 * symbols:
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_02165794   0x02165794  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern char *g_02146940;
extern void func_02165794(void *, void *);

void func_0216576C(void *a0)
{
    if (func_02027060(0x2F)) {
        func_02165794(g_02146940 + 4, a0);
        func_02026FB8(g_02146940 + 4);
    }
}
