/*
 * function: GF_FONT_ReadStreamedGlyph
 * address:  0x0201DBF4
 * packet:   pkt_0201DB20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204960C  0x0204960C  arm
 *   ARC_TOOL_ReadHandle  0x020495F4  arm
 *   GF_FONT_DecodeGlyph  0x0201DC44  thumb
 *
 * gf_font.c's glyph fetch for a streamed font: seek the resource handle to
 * the header base plus the glyph directory plus record i, read mapSize bytes
 * into the scratch buffer, then hand it to GF_FONT_DecodeGlyph with the last-tile
 * column count.
 *
 * The lever (wave 16) is `const` on the font parameter, exactly as in its
 * sibling src/matched/sub_0201DBBC.c: it moves the outgoing stack argument
 * `out` from third to last in the final call's setup (12 bytes out before,
 * docs/notes/sub_0201DBBC.c.txt).  The listing extent includes the two-byte
 * alignment pad at 0x0201DC42, hence EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DBBC.c \
 *       --func GF_FONT_ReadStreamedGlyph --addr 0x0201DBF4 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Font {
    u32   format;
    u32   measure;
    u32   decode;
    u8   *body;
    u8    pad10[0x40];
    void *handle;
    u8    pad54[0x22];
    u16   mapSize;
    u8    pad78[4];
    u16   lastCols;
    u8    tilesW;
    u8    tilesH;
    void *resHdr;
    void *bodyBuf;
    void *charMap;
    void *glyphDir;
    void *scratch;
};

extern void func_0204960C(void *handle, u32 off);
struct ArcFile;
extern void ARC_TOOL_ReadHandle(struct ArcFile *arc, u32 size, void *dst);
extern void GF_FONT_DecodeGlyph(struct Font *f, const u8 *g, u32 w, void *d, u8 *out);

void GF_FONT_ReadStreamedGlyph(const struct Font *f, u32 i, void *d, u8 *out)
{
    func_0204960C(f->handle, (u32)f->resHdr + ((u32)f->glyphDir + i * f->mapSize));
    ARC_TOOL_ReadHandle(f->handle, f->mapSize, f->scratch);
    GF_FONT_DecodeGlyph((struct Font *)f, f->scratch, f->lastCols, d, out);
}
