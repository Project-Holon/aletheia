/*
 * function: func_021EDE54
 * address: 0x021EDE54
 * packet: pkt_ov093_021EDE54
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020437EC 0x020437EC arm
 *   func_020437D4 0x020437D4 arm
 *   func_02082A90 0x02082A90 arm
 *   func_021EEE24 0x021EEE24 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_020437EC(const void *);
extern void *func_020437D4(const void *);
extern void func_02082A90(const void *, void *, u32);
extern void func_0201DD78(u32, u32, u32);
extern void func_021EEE24(u32, u16, u32, ...);
extern u32 func_0201D33C(void *, u32, u32, u32 *, u32);
extern u32 func_0201D304(void *, u32, u32);
extern u32 func_0201D37C(void *, void *, u32);
extern void func_0201C7A4(void *, s16, s16, void *, u32);
void func_021EDE54(u8 *p)
{
    u8 *q;
    u32 size;
    void *pixels;
    u32 widths[2];
    int right;
    int left;
    int gap;
    int extra;
    int half;
    u32 edge;
    u32 width;
    u32 center;
    q = *(u8 **)p;
    size = func_020437EC(*(void **)(p + 4));
    pixels = func_020437D4(*(void **)(p + 4));
    func_02082A90(*(u8 **)(*(u8 **)(*(u8 **)p + 0xdc) + 0x14) + p[0xa] * 0x900, pixels, size);
    func_0201DD78(1, 2, 0);
    func_021EEE24(*(u32 *)(q + 0x38), 0x67, 2, p[0xc], *(u16 *)(p + 8));
    if ((u8)func_0201D33C(*(void **)(q + 0x38), *(u32 *)(q + 0x28), 0, widths, 2) > 1) {
        width = widths[0];
        edge = width + 8;
        right = 0x84 - widths[1];
        gap = edge - right;
        if (gap < 12) {
            extra = 12 - gap;
            half = extra / 2;
            edge += half;
            extra -= half;
            right -= extra;
        }
        left = edge;
        left = left - width;
        if (left < 0) left = 0;
        if (right < 0) right = 0;
        func_0201D37C(*(void **)(q + 0x38), *(void **)(q + 0x3c), 0);
        func_0201C7A4(*(void **)(p + 4), left, 7, *(void **)(q + 0x3c), *(u32 *)(q + 0x28));
        func_0201D37C(*(void **)(q + 0x38), *(void **)(q + 0x3c), 1);
        func_0201C7A4(*(void **)(p + 4), right, 18, *(void **)(q + 0x3c), *(u32 *)(q + 0x28));
    } else {
        center = (0x88 - func_0201D304(*(void **)(q + 0x38), *(u32 *)(q + 0x28), 0)) / 2;
        if ((int)center < 0) center = 0;
        func_0201C7A4(*(void **)(p + 4), center, 18, *(void **)(q + 0x38), *(u32 *)(q + 0x28));
    }
}
