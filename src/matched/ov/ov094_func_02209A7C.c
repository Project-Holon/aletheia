/*
 * function: func_02209A7C
 * address:  0x02209A7C
 * packet:   pkt_ov094_02209A7C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_0220AEFC     0x0220AEFC  data  ov094
 *   func_020490F4  0x020490F4  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204AC18  0x0204AC18  arm
 *   CLACT_GetPaletteVramAddress  0x0204AEF4  arm
 *   func_020216D4  0x020216D4  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_02049238  0x02049238  arm
 *   func_021F86D4  0x021F86D4  thumb  ov094
 *   func_02030DA8  0x02030DA8  arm
 *   func_02209CC4  0x02209CC4  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int h0;                 /* 0x00 */
    int pad04;
    void *task;             /* 0x08 */
    int h0c;                /* 0x0c */
    int h10;                /* 0x10 */
    int h14;                /* 0x14 */
    char pad18[0x2c - 0x18];
    u16 heap;               /* 0x2c */
} W;

typedef signed int     s32;
struct PalAnmSlot;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_0220AEFC[];
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
struct Bank;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_02049238(void * h);
extern void *func_021F86D4(void);
extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 a3);
extern void func_02209CC4(void *a, void *b);

W *func_02209A7C(void *a0, u32 b, u16 heap)
{
    W *w;
    void *a;

    w = func_02030734(heap, 0x30, 1, d_0220AEFC, 0x52);
    a = func_020490F4(0xb, (u16)((heap & 0x7fff) | 0x8000));
    w->heap = heap;
    w->h0c = func_0204A6C8(a, 0xd9, 0, 1, heap);
    w->h14 = func_0204AF28(a, 0xdb, 0xdc, heap);
    w->h10 = func_0204AC18(a, 0xda, 1, (u16)(b << 5), 0, 1, heap);
    func_020216D4(a0, 3, (u16)(CLACT_GetPaletteVramAddress(w->h10, 1) >> 1), 0x20);
    w->h0 = (int)func_0204B100(1, 0, heap);
    func_02049238(a);
    w->task = func_02030DA8(func_021F86D4(), func_02209CC4, w, 0);
    return w;
}
