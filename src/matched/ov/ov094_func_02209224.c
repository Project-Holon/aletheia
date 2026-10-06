/*
 * function: func_02209224
 * address:  0x02209224
 * packet:   pkt_ov094_02209224
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the `lsls #15 / lsrs #16` argument is `(u16)(v >> 1)`; `& 0x7fff`
 * or `& 0x1ffff` forms pool the mask and shift the registers.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_0220AEE0     0x0220AEE0  data  ov094
 *   func_020490F4  0x020490F4  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_021F86E0  0x021F86E0  thumb  ov094
 *   func_0204AEF4  0x0204AEF4  arm
 *   func_020216D4  0x020216D4  thumb
 *   func_02049238  0x02049238  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int h0;                 /* 0x00 */
    int h4;                 /* 0x04 */
    char pad08[0x40 - 0x08];
    int h40;                /* 0x40 */
    int h44;                /* 0x44 */
    int h48;                /* 0x48 */
    char pad4c[0x74 - 0x4c];
    u16 heap;               /* 0x74 */
} W;

typedef signed int     s32;
struct PalAnmSlot;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_0220AEE0[];
extern void *func_020490F4(u32 id, u32 heap);
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_021F86E0(void);
extern int func_0204AEF4(u32 idx, u32 alternate);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02049238(void * h);

W *func_02209224(u16 heap)
{
    W *w;
    void *a;
    void *s;

    w = func_02030734(heap, 0x78, 1, d_0220AEE0, 0x81);
    w->heap = heap;
    a = func_020490F4(0xb, (u16)((w->heap & 0x7fff) | 0x8000));
    w->h0 = (int)func_0204B100(6, 0, w->heap);
    w->h4 = (int)func_0204B100(6, 0, w->heap);
    w->h40 = func_0204A6C8(a, 0x7a, 0, 0, w->heap);
    w->h44 = func_0204AF28(a, 0x7b, 0x7c, w->heap);
    w->h48 = func_0204ABF0(a, 0xa2, 0, 0xe0, w->heap);
    s = (void *)func_021F86E0();
    func_020216D4(s, 2, (u16)(func_0204AEF4(w->h48, 0) >> 1), 0x20);
    func_02049238(a);
    return w;
}
