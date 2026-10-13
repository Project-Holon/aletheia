/*
 * function: DELIVERY_BEACON_Create
 * address:  0x021576D0
 * packet:   pkt_ov010_021576D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082D44  0x02082D44  arm
 *   d_021727F4  0x021727F4  data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082D44(void *, void *, u32);
extern const char d_021727F4[];

void *DELIVERY_BEACON_Create(u8 *p)
{
    void *buf;

    buf = func_02030734(*(u16 *)(p + 6), 0x31C0, 1, d_021727F4, 0x127);
    func_02082D44(p, buf, 0x7C);
    return buf;
}
