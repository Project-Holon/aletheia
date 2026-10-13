/*
 * function: func_02068EA0
 * address:  0x02068EA0
 * packet:   pkt_02068808
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Per-file compiler pin, the re-read/forward form of the "kept constants"
 * family (docs/FRONTEND-PINS.md, the NNSi_G3dAnmObjInitNsBva row). The image RE-READS
 * the font's header chain a second time before the switch dispatch,
 * `ldr r1, [r7]` at 0x02068F00 (`00 10 97 e5`) then `ldr r3, [r1, #8]` at
 * 0x02068F04 (`08 30 91 e5`), although the same chain was already loaded at
 * 0x02068EE8/0x02068EEC for the stride computation two instructions earlier.
 * dsi/1.1p1 -O4,p forwards the register it still has live and collapses the
 * pair to a single `ldr r3, [r3, #8]`, giving 284 bytes against the original's
 * 292 with everything from the dispatch onward shifted by four. A volatile
 * qualifier on the outer load, struct-typed field chains, binding the header
 * to a local before or after out[1], and a fresh `(*font)->hdr` chain spelled
 * out in every switch arm all CSE identically at 284. Under the pin the same C
 * is 292 bytes, 0 mismatches.
 *
 * Draw one glyph: look the character up in the font's range table, fall back
 * to the font's default glyph when the lookup returns its 0xFFFF "not found"
 * sentinel (the pool word at 0x02068FC0), then adjust the pen position by the
 * glyph's own bearings according to the header's layout kind before handing
 * both the glyph record and the metrics record to the context's draw hook.
 *
 * symbols:
 *   NNS_G2dFontGetGlyphIndex    0x02067F9C  arm
 *   func_02067FE4    0x02067FE4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02068EA0.c \
 *       --func func_02068EA0 --addr 0x02068EA0 --cc ../2.0/sp2 --arm
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
extern u32 NNS_G2dFontGetGlyphIndex(struct Obj **a0, u32 key);
struct NNSG2dCharWidths;
struct NNSG2dFont;
extern const struct NNSG2dCharWidths *func_02067FE4(const struct NNSG2dFont *pFont, u32 idx);

struct Hdr { u16 f0; u16 stride; u8 pad[3]; u8 kind; };
struct Fnt { struct Hdr *hdr; };
struct Fnt2 { u16 f0; u16 dflt; u8 p[4]; struct Hdr *hdr; };
struct Ctx { u8 pad[0x14]; void **vt; };

s8 func_02068EA0(struct Ctx *ctx, struct Fnt2 **font, int x, int y, int a6, u16 code)
{
    s8 *out[2];
    u32 idx;
    s8 *g;
    u8 k;

    idx = NNS_G2dFontGetGlyphIndex((struct Obj **)font, code);
    if (idx == 0xffff)
        idx = (*font)->dflt;
    out[0] = (s8 *)func_02067FE4((const struct NNSG2dFont *)font, idx);
    out[1] = (s8 *)((char *)(*font)->hdr + 8 + idx * (*font)->hdr->stride);
    g = out[0];
    k = (*font)->hdr->kind;

    switch (k) {
    case 0:
    case 7:
        x += g[0];
        break;
    case 1:
    case 2:
        x -= ((u8 *)(*font)->hdr)[0];
        y += g[0];
        break;
    case 3:
    case 4:
        x -= g[0] + (u8)g[1];
        y -= ((u8 *)(*font)->hdr)[1];
        break;
    case 5:
    case 6:
        y -= g[0] + ((u8 *)(*font)->hdr)[1];
        break;
    }
    ((void (*)(struct Ctx *, void *, int, int, int, s8 **))ctx->vt[0])(ctx, font, x, y, a6, out);
    return out[0][2];
}
