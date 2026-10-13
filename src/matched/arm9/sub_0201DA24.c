/*
 * function: GF_FONT_InitPreloadedGlyphs
 * address:  0x0201DA24
 * packet:   pkt_0201DA00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201DA24_File  0x020A7358  data
 *   ARC_TOOL_GetHandleMemberSize       0x020493D4  arm
 *   func_02030734       0x02030734  arm
 *   sub_0204944C        0x0204944C  arm
 *   GF_FONT_ReadPreloadedGlyph       0x0201DBBC  thumb
 *   GF_FONT_DecodeGlyph8x8       0x0201DE40  thumb
 *   GF_FONT_DecodeGlyph8x16       0x0201E538  thumb
 *   GF_FONT_DecodeGlyph16x8       0x0201E738  thumb
 *   GF_FONT_DecodeGlyph16x16       0x0201E928  thumb
 */
typedef unsigned char  u8;
typedef unsigned int   u32;

struct Font {
    u32   unk00;
    u32   unk04;
    u32   unk08;
    void *unk0C;
    u8    pad10[0x40];
    void *unk50;
    u32   unk54;
    u8    pad58[0x34];
    u32   unk8C;
};

extern const char func_0201DA24_File[];

typedef unsigned short u16;
struct ArcFile;
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void sub_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);

extern void GF_FONT_ReadPreloadedGlyph(const struct Font *f, u32 i, void *d, u8 *out);
extern void GF_FONT_DecodeGlyph8x8(const u8 *src, u32 n, u16 *dst);
extern void GF_FONT_DecodeGlyph8x16(const u8 *src, u32 n, u16 *dst);
extern void GF_FONT_DecodeGlyph16x8(const u8 *src, u32 n, u16 *dst);
extern void GF_FONT_DecodeGlyph16x16(const u8 *src, u32 n, u16 *dst);

void GF_FONT_InitPreloadedGlyphs(struct Font *f, u32 a, u32 b, u8 heap)
{
    u32 size;
    u32 p;

    size = ARC_TOOL_GetHandleMemberSize(f->unk50, f->unk54) - f->unk8C;
    f->unk0C = func_02030734(heap, size, 0, func_0201DA24_File, 363);
    sub_0204944C(f->unk50, f->unk54, f->unk8C, size, f->unk0C);
    f->unk04 = (u32)GF_FONT_ReadPreloadedGlyph;
    if (a == 1) {
        p = (u32)GF_FONT_DecodeGlyph8x8;
        if (b != 1) {
            p = (u32)GF_FONT_DecodeGlyph8x16;
        }
        f->unk08 = p;
    } else {
        p = (u32)GF_FONT_DecodeGlyph16x8;
        if (b != 1) {
            p = (u32)GF_FONT_DecodeGlyph16x16;
        }
        f->unk08 = p;
    }
}
