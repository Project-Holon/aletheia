/*
 * function: func_02165604
 * address:  0x02165604
 * packet:   pkt_02165604
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
 *   func_02165628   0x02165628  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02027060(int);
extern void func_02026FB8(void *);
extern char *g_02146940;
extern void func_02165628(void *);

void func_02165604(void)
{
    if (func_02027060(0x28)) {
        func_02165628(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}

