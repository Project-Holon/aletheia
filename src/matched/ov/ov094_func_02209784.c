/*
 * function: func_02209784
 * address:  0x02209784
 * packet:   pkt_ov094_02209784
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_0220AEF0     0x0220AEF0  data  ov094
 *   func_020056A0  0x020056A0  thumb
 *   func_02209A54  0x02209A54  thumb  ov094
 *   func_021F896C  0x021F896C  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[8];
    u16 heap;               /* 0x08 */
} W;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_0220AEF0[];
extern void *func_020056A0(void (*cb)(void *), void *ctx, int pri);
extern void func_02209A54(void *h);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);

void func_02209784(W *w, u32 a, u32 b)
{
    u32 *o;

    o = func_02030734((u16)((w->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEF0, 0x67);
    o[0] = a;
    o[1] = b;
    func_021F896C(func_020056A0(func_02209A54, o, 0), 0, 0);
}
