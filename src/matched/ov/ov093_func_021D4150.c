/*
 * function: func_021D4150
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
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   d_021F3A98 0x021F3A98 data ov093 a4
 *   func_02030734 0x02030734 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_021D4AF4 0x021D4AF4 thumb ov093
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
extern struct S *d_021F3B88;
extern u8 d_021F3A98[];
extern void *func_02030734(u16, int, int, const void *, u16);
extern u32 func_0203D1A4(void *);
extern u32 func_0203D1B4(void);
extern void func_021D4AF4(u8);
void func_021D4150(void *link, u16 mask, u16 heap)
{
    u32 count, i, j, k, limit;
    if (link) {
        d_021F3B88 = func_02030734(heap, 0x3b2c, 1, d_021F3A98, 0xd4);
        d_021F3B88->link = link;
        d_021F3B88->mask = mask;
        d_021F3B88->heap = heap;
        d_021F3B88->id = func_0203D1A4(link);
        d_021F3B88->f07 = 0x28;
        i = 0;
        d_021F3B88->f0d = i;
        d_021F3B88->f0e = i;
        count = 0;
        for (; i < 4; i++) if (mask & (1U << i)) count++;
        limit = func_0203D1B4();
        if (count > limit) count = limit;
        d_021F3B88->count = count;
        d_021F3B88->f0f = 0;
        d_021F3B88->f10 = 0;
        d_021F3B88->f0a = 0;
        for (j = 0; j < 4; j++) {
            d_021F3B88->tblA[j] = 0;
            d_021F3B88->tblB[j] = 0;
            d_021F3B88->states[j] = 4;
        }
        for (k = 0; k < 4; k++) d_021F3B88->tblC[k] = 0;
        d_021F3B88->f3b14 = 0;
        d_021F3B88->f3b18 = 0;
        func_021D4AF4(1);
    } else d_021F3B88 = 0;
}
