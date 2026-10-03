/*
 * function: func_0216556C
 * address:  0x0216556C
 * packet:   pkt_0216556C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Gate on an id test, then submit the record at the shared globals
 * pointer.
 *
 * symbols:
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_02165590   0x02165590  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern char *g_02146940;
extern void func_02165590(void *);

void func_0216556C(void)
{
    if (func_02027060(0x25)) {
        func_02165590(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}

