/*
 * function: MYSTERY_UTIL_CreateMenuWindow
 * address: 0x021D9CA4
 * packet: pkt_ov121_021D9CA4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lang: c99
 * lever: final push 2026-10-05 G3L5. heap is a u16 parameter and every heap-taking callee
 *   (func_02030734 first parameter, STRBUF_Create second, TCBL_Create first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order
 *   (lsls of the line constant after the heap load). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov177 WIFIBATTLEMATCH_UTIL_Create.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   TCBL_Create 0x0203101C arm
 *   d_021DFBA0 0x021DFBA0 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021DFBA0[];
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, u32);
extern void *STRBUF_Create(u32, u16);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32);
struct Tcbl;
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
static inline void *allocate(u16 heap, u32 size, const char *site, u16 line)
{
    return func_02030734(heap, size, 0, site, line);
}
void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    void *q;
    p = allocate(heap, 0x40, d_021DFBA0, 0x184);
    MI_CpuFill8(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    *(void **)(p + 0x14) = STRBUF_Create(0x300, heap);
    q = (void *)BMP_WIN_Create((u8)a, 1, 19, 30, 4, b, 1);
    *(void **)(p + 0x10) = q;
    *(void **)(p + 0x1c) = q;
    p[0x20] = 0;
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(void **)(p + 0x10);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(q));
    *(void **)(p + 0xc) = TCBL_Create(heap, heap, 1, 32);
    return p;
}
