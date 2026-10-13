/*
 * function: BTLV_BG_Create
 * address:  0x0220975C
 * packet:   pkt_ov094_0220975C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sBtlvBgSiteName     0x0220AEF0  data  ov094
 */

typedef unsigned short u16;
typedef struct {
    void *f0;
    int f4;
    u16 f8;
} W;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char sBtlvBgSiteName[];

W *BTLV_BG_Create(void *a, u16 heap)
{
    W *w = func_02030734(heap, 0xc, 1, sBtlvBgSiteName, 0x48);
    w->f0 = a;
    w->f8 = heap;
    return w;
}
