/*
 * function: func_0201DBBC
 * address:  0x0201DBBC
 * packet:   pkt_0201DB20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0201DC44  0x0201DC44  thumb
 *
 * gf_font.c's glyph fetch for a preloaded font: copy glyph record i
 * (mapSize bytes) out of the resident body into the scratch buffer, then
 * hand it to func_0201DC44 with the last-tile column count.
 *
 * The lever (wave 16) is `const` on the font parameter, which is only read
 * here.  With a plain pointer the outgoing stack argument `out` was stored
 * third in the final call's setup; with `const struct Font *` it is stored
 * last, as in the image (12 bytes out before, every spelling and 3000
 * permuter compiles flat: docs/notes/sub_0201DBBC.c.txt).  Field names
 * follow docs/families/gf_font.h.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DBBC.c \
 *       --func func_0201DBBC --addr 0x0201DBBC --cc 1.1p1 --thumb
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

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_0201DC44(struct Font *f, const u8 *g, u32 w, void *d, u8 *out);

void func_0201DBBC(const struct Font *f, u32 i, void *d, u8 *out)
{
    MI_CpuCopy8(f->body + i * f->mapSize, f->scratch, f->mapSize);
    func_0201DC44((struct Font *)f, f->scratch, f->lastCols, d, out);
}
