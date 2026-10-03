/*
 * function: func_02165374
 * address:  0x02165374
 * packet:   pkt_ov010_02165374
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Looks the id up in a five-entry byte table; on a hit re-submits the
 * record at the shared globals pointer.
 *
 * symbols:
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   d_02171CA0      0x02171CA0  data  ov010  a1
 *   func_021653B4   0x021653B4  thumb  ov010
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern char *g_02146940;
extern u8 d_02171CA0[5];
extern void func_021653B4(void *, unsigned);

void func_02165374(unsigned a0)
{
    unsigned i;

    if (func_02027060(0x16)) {
        for (i = 0; i < 5; i++) {
            if (a0 == d_02171CA0[i]) {
                func_021653B4(g_02146940 + 4, a0);
                func_02026FB8(g_02146940 + 4);
                return;
            }
        }
    }
}
