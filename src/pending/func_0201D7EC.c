/*
 * function: func_0201D7EC
 * address:  0x0201D7EC
 * packet:   pkt_0201D7EC
 * status:   MATCH
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201D854 0x0201D854 thumb
 *   func_0201DA00 0x0201DA00 thumb
 *   lbl_020A7358  0x020A7358 data
 */

typedef unsigned int u32;

struct GfFont {
    char pad_00[0x50];
    void *field_50;
    int field_54;
};

extern void *func_02030734(u32 heapId, u32 size, u32 align, const char *file, u32 line);
extern void *func_020490F4(int a0, u32 heapId);
extern void func_0201D854(struct GfFont *font, int a1, int a3, u32 heapId);
extern void func_0201DA00(struct GfFont *font, int a2, u32 heapId);
extern const char lbl_020A7358[];

struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId)
{
    struct GfFont *font = func_02030734(heapId, 0x94, 0, lbl_020A7358, 0xC0);

    if (font != 0) {
        font->field_50 = func_020490F4(a0, heapId);
        font->field_54 = a1;
        func_0201D854(font, a1, a3, heapId);
        func_0201DA00(font, a2, heapId);
    }
    return font;
}
