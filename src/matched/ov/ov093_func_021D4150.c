/*
 * function: BTL_NET_Init
 * address: 0x021D4150
 * packet: pkt_ov093_021D4150
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Separate loop counters; use the first counter's initialized zero
 * for f0d/f0e stores before entering that loop.
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   gBtlNetSourceName 0x021F3A98 data ov093 a4
 *   func_02030734 0x02030734 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   BTL_NET_BeginSync 0x021D4AF4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S {
    void *link;
    u16 heap;
    u8 id, f07;
    u16 mask;
    u8 f0a, count, f0c, f0d, f0e, f0f, f10, states[4];
    u8 pad[0x3ae4 - 0x15];
    void *tblA[4], *tblB[4], *tblC[4], *f3b14, *f3b18;
};
extern struct S *gBtlNet;
extern u8 gBtlNetSourceName[];
extern void *func_02030734(u32, u32, int, const char *, u16);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int GFL_NET_GetNegotiationNum(void);
extern void BTL_NET_BeginSync(int a);
void BTL_NET_Init(void *link, u16 mask, u16 heap)
{
    u32 count, i, j, k, limit;
    if (link) {
        gBtlNet = func_02030734(heap, 0x3b2c, 1, (const char *)gBtlNetSourceName, 0xd4);
        gBtlNet->link = link;
        gBtlNet->mask = mask;
        gBtlNet->heap = heap;
        gBtlNet->id = GFL_NET_GetHandleNetID(link);
        gBtlNet->f07 = 0x28;
        i = 0;
        gBtlNet->f0d = i;
        gBtlNet->f0e = i;
        count = 0;
        for (; i < 4; i++) if (mask & (1U << i)) count++;
        limit = GFL_NET_GetNegotiationNum();
        if (count > limit) count = limit;
        gBtlNet->count = count;
        gBtlNet->f0f = 0;
        gBtlNet->f10 = 0;
        gBtlNet->f0a = 0;
        for (j = 0; j < 4; j++) {
            gBtlNet->tblA[j] = 0;
            gBtlNet->tblB[j] = 0;
            gBtlNet->states[j] = 4;
        }
        for (k = 0; k < 4; k++) gBtlNet->tblC[k] = 0;
        gBtlNet->f3b14 = 0;
        gBtlNet->f3b18 = 0;
        BTL_NET_BeginSync(1);
    } else gBtlNet = 0;
}
