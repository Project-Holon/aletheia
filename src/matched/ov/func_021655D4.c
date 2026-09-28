/*
 * function: func_021655D4
 * address:  0x021655D4
 * packet:   pkt_021655D4
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
 *   func_021655F8   0x021655F8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02027060(int);
extern void func_02026FB8(void *);
extern char *g_02146940;
extern void func_021655F8(void *);

void func_021655D4(void)
{
    if (func_02027060(0x27)) {
        func_021655F8(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}

