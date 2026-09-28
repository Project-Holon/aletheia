/*
 * function: func_0216566C
 * address:  0x0216566C
 * packet:   pkt_0216566C
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
 *   func_02165690   0x02165690  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02027060(int);
extern void func_02026FB8(void *);
extern char *g_02146940;
extern void func_02165690(void *);

void func_0216566C(void)
{
    if (func_02027060(0x2A)) {
        func_02165690(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}

