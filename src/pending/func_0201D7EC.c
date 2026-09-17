/*
 * function: func_0201D7EC
 * address:  0x0201D7EC
 * packet:   pkt_0201D7EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   aGfFontC       0x020A7358  data
 *   sub_02030734   0x02030734  arm
 *   sub_020490F4   0x020490F4  arm
 *   func_0201D854  0x0201D854  thumb
 *   func_0201DA00  0x0201DA00  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Font;

extern const char aGfFontC[];

extern struct Font *sub_02030734(u32 heap, u32 size, u32 line, const char *file, u32 unk);
extern void *sub_020490F4(u32 a, u32 b);
extern void func_0201D854(struct Font *font, u32 arg1, u32 arg2, u32 arg3);
extern void func_0201DA00(struct Font *font, u32 arg1, u32 arg2);

struct Font *func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u32 heap)
{
    struct Font *font = sub_02030734(heap, 0x94, 0, aGfFontC, 0xC0);
    if (font != 0) {
        void *res = sub_020490F4(a, heap);
        *(void **)((char *)font + 0x50) = res;
        *(u32 *)((char *)font + 0x54) = b;
        func_0201D854(font, b, d, heap);
        func_0201DA00(font, c, heap);
    }
    return font;
}
