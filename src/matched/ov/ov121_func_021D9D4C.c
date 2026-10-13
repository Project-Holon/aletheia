/*
 * function: func_021D9D4C
 * address: 0x021D9D4C
 * packet: pkt_ov121_021D9D4C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: final push 2026-10-05 G4L9. heap is a u16 parameter and every heap-taking callee
 *   (func_02030734 first parameter, STRBUF_Create second, TCBL_Create first two) declares it u16.
 *   The stack heap then loads as a word and the entry block keeps the original order. See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 *   Twin: ov121 func_021D9CA4.
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
 *   func_020409B4 0x020409B4 arm
 *   TCBL_Create 0x0203101C arm
 *   func_02028470 0x02028470 thumb
 *   d_021DFBA0 0x021DFBA0 data a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor; struct CharBuf; struct Cfg; struct Tcbl; struct U16Vec;
extern const char d_021DFBA0[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, u32);
extern struct U16Vec *STRBUF_Create(u32 capacity, u16 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_02028470(u8 *p, u32 v);
void *func_021D9D4C(int a, u8 b, void *c, void *d, u16 heap)
{
    u8 *p;
    struct Descriptor *q;
    p = func_02030734(heap, 0x40, 0, d_021DFBA0, 0x1ae);
    MI_CpuFill8(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    func_02028470(p + 0x34, 2);
    *(struct U16Vec **)(p + 0x14) = STRBUF_Create(0x200, heap);
    q = (struct Descriptor *)BMP_WIN_Create((u8)a, 1, 21, 30, 2, b, 1);
    *(struct Descriptor **)(p + 0x10) = q;
    *(struct Descriptor **)(p + 0x1c) = q;
    p[0x20] = 0;
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(struct Descriptor **)(p + 0x10);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen((struct Cfg *)q);
    func_020409B4(BMP_WIN_GetBgLayer(q));
    *(struct Tcbl **)(p + 0xc) = TCBL_Create(heap, heap, 1, 32);
    return p;
}
