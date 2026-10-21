/*
 * file:     text_texture.c
 * unit:     yes
 * function: TEXT_TEXTURE_LoadTexPlttByName, TEXT_TEXTURE_GetTexFormatCount, TEXT_TEXTURE_ClearBitmap, TEXT_TEXTURE_PrintToClearedBitmap, TEXT_TEXTURE_ConvertToTileOrder, TEXT_TEXTURE_UploadTextTexture, TEXT_TEXTURE_UploadPalette
 * address:  0x0216FAB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from waza_oshie.c, town_map_spot.c by tools/splitfile.py.
 *
 * symbols:
 *   G3D_SYSTEM_GetResourceTex        0x02047250  arm
 *   STD_GetStringLength  0x0208CC78  arm
 *   NNS_G3dGetResDataByName        0x0206E62C  arm
 *   GF_FONT_Create        0x0201D7EC  thumb
 *   GF_FONT_Delete        0x0201D83C  thumb
 *   d_021726A0           0x021726A0  data
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 *   TEXT_TEXTURE_ClearBitmap 0x0216FC50 thumb ov010
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_GetTileBytes  0x02043994  arm
 *   BMP_Create  0x02043678  arm
 *   GX_BeginLoadTex  0x0207F7A0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadTex  0x0207F7FC  arm
 *   GX_EndLoadTex  0x0207F9B4  arm
 *   BMP_Delete  0x020437AC  arm
 *   GX_BeginLoadTexPltt 0x0207FA0C arm
 *   GX_LoadTexPltt 0x0207FA40 arm
 *   GX_EndLoadTexPltt 0x0207FADC arm
 */

struct GfFont;

struct Bmp;

struct Bmp;

#include "../types.h"

#include "../arm9/nns_g3d_anm_calc_types.h"

typedef struct TexFormat {
    u16 formatId;       /* 0x00 */
    u16 reserved02;
    u32 tex;            /* 0x04 */
    u32 pltt;           /* 0x08 */
} TexFormat;

typedef struct TexKey {
    u16 texFmt;         /* 0x00 */
    u16 plttFmt;        /* 0x02 */
    u32 texVramKey;     /* 0x04 */
    u32 plttVramKey;    /* 0x08 */
    u32 texOfs;         /* 0x0C */
    u32 plttOfs;        /* 0x10 */
} TexKey;

typedef struct TexReq {
    u16 texFmt;         /* 0x00 */
    u16 plttFmt;        /* 0x02 */
    u32 texVramKey;     /* 0x04 */
    u32 plttVramKey;    /* 0x08 */
    u32 texOfs;         /* 0x0C */
    u32 plttOfs;        /* 0x10 */
    void *font;         /* 0x14 */
} TexReq;
struct G3dResource;
struct NNSG3dResTex;

#include "../arm9/g3d_system.h"

#include "../arm9/std_string.h"


#include "../arm9/gf_font.h"


typedef short s16_p07;
#include "../arm9/bmp.h"


struct Strbuf;
int TEXT_TEXTURE_LoadTexPlttByName(void *file, const char *texName, void *extra, const char *plttName, struct Strbuf *text, u16 xPos, u16 yPos, u16 color, u16 heapId, TexKey *out);

int TEXT_TEXTURE_GetTexFormatCount(void);

void TEXT_TEXTURE_ClearBitmap(void *bmp);
struct Strbuf;

#include "../arm9/printsys.h"





#include "../arm9/gx_load3d.h"

#include "../arm9/os_cache.h"
#include "../arm9/nns_g3d_res.h"







void TEXT_TEXTURE_PrintToClearedBitmap(struct Strbuf *text, u16 xPos, u16 yPos, u16 color, void *bmp, void *font);

void TEXT_TEXTURE_ConvertToTileOrder(void *srcBmp, void *dstBmp);

void TEXT_TEXTURE_UploadTextTexture(TexReq *req, struct Strbuf *text, u16 xPos, u16 yPos, u16 color, u16 heapId);

void TEXT_TEXTURE_UploadPalette(TexReq *req, void *dest);

extern const TexFormat d_021726A0[];

/*
 * Look up a texture and a palette by name in a G3D texture resource,
 * derive their formats from the 7-entry d_021726A0 table, and load them
 * through TEXT_TEXTURE_UploadTextTexture (optionally TEXT_TEXTURE_UploadPalette). One lever: the four
 * stack aggregates declared in reverse of their frame order.
 */
int TEXT_TEXTURE_LoadTexPlttByName(void *file, const char *texName, void *extra, const char *plttName, struct Strbuf *text, u16 xPos, u16 yPos, u16 color, u16 heap, TexKey *out)
{
    TexKey key;
    char tn[16];
    char pn[16];
    TexReq req;
    u16 ofs;
    NNSG3dResTex *res;
    u16 *e;
    u32 v;
    u32 fmtT;
    u32 fmtP;
    u32 j;
    int i;
    void *font;

    key.texFmt = 6;
    key.plttFmt = 6;
    key.texOfs = 0;
    key.plttOfs = 0;
    res = G3D_SYSTEM_GetResourceTex(file);
    key.texVramKey = res->texInfo.vramKey;
    key.plttVramKey = res->plttInfo.vramKey;
    ofs = res->texInfo.ofsDict;
    for (i = 0; i < STD_GetStringLength(texName); i++)
        tn[i] = texName[i];
    for (; i < 16; i++)
        tn[i] = 0;
    e = NNS_G3dGetResDataByName((const NNSG3dResDict *)((u8 *)res + ofs), (const NNSG3dResName *)tn);
    if (e == 0)
        return 0;
    v = *(u32 *)e;
    key.texOfs = (v & 0xFFFF) << 3;
    fmtT = (v & 0x700000) >> 20;
    fmtP = (v & 0x3800000) >> 23;
    for (j = 0; j < 7; j++) {
        if (fmtT == d_021726A0[j].tex) {
            key.texFmt = j;
            break;
        }
    }
    for (j = 0; j < 7; j++) {
        if (fmtP == d_021726A0[j].pltt) {
            key.plttFmt = j;
            break;
        }
    }
    ofs = res->plttInfo.ofsDict;
    for (i = 0; i < STD_GetStringLength(plttName); i++)
        pn[i] = plttName[i];
    for (; i < 16; i++)
        pn[i] = 0;
    e = NNS_G3dGetResDataByName((const NNSG3dResDict *)((u8 *)res + ofs), (const NNSG3dResName *)pn);
    if (e == 0)
        return 0;
    if (e[1] == 1)
        return 0;
    key.plttOfs = (e[0] & 0xFFFF) << 3;
    font = GF_FONT_Create(0x17, 0, 0, 0, heap);
    req.texFmt = key.texFmt;
    req.plttFmt = key.plttFmt;
    req.texVramKey = key.texVramKey;
    req.font = font;
    req.texOfs = key.texOfs;
    req.plttVramKey = key.plttVramKey;
    req.plttOfs = key.plttOfs;
    TEXT_TEXTURE_UploadTextTexture(&req, text, xPos, yPos, color, heap);
    if (extra != 0)
        TEXT_TEXTURE_UploadPalette(&req, extra);
    GF_FONT_Delete(font);
    if (out != 0)
        *out = key;
    return 1;
}

int TEXT_TEXTURE_GetTexFormatCount(void)
{
    return 7;
}

/*
 * Clears the pixel buffer of a bitmap: gets the buffer (BMP_GetPixels) and
 * its byte size (BMP_GetByteSize), then stores 0 in every byte. The loop label
 * sits on the strb, so the `adds r1, r2, #0` before it is the zero copied
 * from the counter, not a store of i (docs/idioms/a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero.md).
 */
void TEXT_TEXTURE_ClearBitmap(void *bmp)
{
    u8 *buf;
    u32 n;
    u32 i;

    buf = (u8 *)BMP_GetPixels(bmp);
    n = BMP_GetByteSize(bmp);
    for (i = 0; i < n; i++) {
        buf[i] = 0;
    }
}

void TEXT_TEXTURE_PrintToClearedBitmap(struct Strbuf *text, u16 xPos, u16 yPos, u16 color, void *bmp, void *font)
{
    TEXT_TEXTURE_ClearBitmap(bmp);
    PRINTSYS_PrintColor(bmp, (s16)xPos, yPos, text, font, color);
}

/*
 * DIFF, 12 concrete bytes, 180/180 bytes, all 9 relocations resolved.
 * Tile-order copy: w, h in 8-pixel units, d = depth byte, t = (d<<13)>>16;
 * dst[i] = src[(r/t + w*(q/8))*d + (q%8)*t + r%t] with s = w*t, q = i/s, r = i%s.
 * recoup 2026-10-05 (lane B2, 21 compiles): the old draft (docs/notes) had the
 * right logic. Division calls are CSE'd by mwcc (equal calls merge at the first
 * use), so the old tmp/q/pad locals were unnecessary. Clean form with r named and
 * the quotient written inline twice gives the hoisted stride spilled (as the
 * original) and the original register colours, 24 B off. Residue: the original
 * calls i/s FIRST (quotient into r4) then i%s (remainder into r7); mwcc emits the
 * remainder first, and the four spill slots (w, d, total, stride) come out in
 * reverse order of the original (orig 8,4,0xc,0x10; ours 0x10,0xc,4,8).
 * Tried and worse: named q (97 B, stride no longer hoisted, i/q colours swap),
 * all-inline with quotient term leftmost (24 B, same) or rightmost (81 B),
 * named q plus inline r (97 B), q named plus one inline quotient (73 B), s named
 * in loop (127 B), total as loop bound (124 B), w/h/t as plain /8 (166 B: the
 * original keeps the lsls 13 / lsrs 16 pair), pragmas scheduling,
 * opt_propagation, opt_lifetimes off (24, 27, 24 B).
 * Callee types checked: BMP_GetWidth/E4 u16, BMP_GetTileBytes u8 (BMP_GetTileBytes.c),
 * BMP_GetPixels returns a pointer (ov208 callers); all as declared here.
 * No tile-order twin (grep BMP_GetTileBytes, BMP_GetHeight+BMP_GetWidth in src/matched/ov).
 * Idioms read: div-and-mod-are-two-calls, a-self-recompute-pins-an-operand-before-the-other-side-calls,
 * a-field-captured-before-a-named-divider-stays-live-across-the-call,
 * binding-a-modulo-result-to-a-local-moves-the-add-destination,
 * a-byte-count-local-preserves-word-spills-and-reloads,
 * a-spilled-value-below-the-cse-temps-is-an-inline-expression-not-a-named-local.
 *
 * final push 2026-10-05 G6L2 (about 38 compiles, 3 rounds): 24 -> 12 B. The lsls #13 / lsrs #16
 * pair is the u16 truncation of x / 8: w, h, t are u16 locals (w = f() / 8, t = d / 8) and d is
 * a u8 local (the callee returns u8). Narrow locals take the lowest spill slots: the four spill
 * slots now match the original (d 4, w 8, total 0xc, stride 0x10). With >> 3 instead of / 8 the
 * w and d slots swap (19 B).
 * Residue (12 B): the original calls i / s FIRST (quotient into r4) and i % s second (remainder
 * into r7); we emit the remainder first, and the tail copy of (q % 8) goes into r2 where we copy t.
 * Call order follows source order only when q is a named statement before r; every such form
 * (named q with named or inline r, s named inside or before the loop, block-scope locals,
 * declaration orders, opt_propagation/opt_lifetimes/scheduling off) emitted the quotient first
 * but kept the stride in r7 and spilled the remainder (182 B, about 95 B off). All-inline index
 * in any term order (q%8 first, r%t first, w*q/8 first) and a named q%8 term keep remainder first.
 * Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register,
 * opt-propagation-off-with-named-locals-pins-argument-constants-against-stack-stores,
 * div-and-mod-are-two-calls, binding-a-modulo-result-to-a-local-moves-the-add-destination.
 * Matched twin for callee types: ov121 021DA338 (u16, u16, u8).
 *
 * pass 2 2026-10-06 P2L24: EXACT (c99 and c). Fix: q = i / s as a named statement before r = i % s
 * (quotient call first, as the original) together with (q / 8) * w instead of w * (q / 8): the operand
 * order of that product decides which value the allocator spills, and with it the named-q form keeps
 * the stride spilled. The unused `total` local is dropped (the loop bound is the inline product).
 */
void TEXT_TEXTURE_ConvertToTileOrder(void *srcBmp, void *dstBmp)
{
  u8 *src;
  u8 *dst;
  u16 w;
  u16 h;
  u8 d;
  u16 t;
  int i;
  int r;
  int q;
  w = BMP_GetWidth(srcBmp) / 8;
  h = BMP_GetHeight(srcBmp) / 8;
  d = BMP_GetTileBytes(srcBmp);
  t = d / 8;
  src = BMP_GetPixels(srcBmp);
  dst = BMP_GetPixels(dstBmp);
  for (i = 0; i < ((w * h) * d); i++)
  {
    q = i / (w * t);
    r = i % (w * t);
    dst[i] = src[((r / t) + (q / 8) * w) * d + (q % 8) * t + r % t];
  }
}

/*
 * EXACT in --lang c99 and --lang c, 176/176 bytes, all 12 relocations resolved.
 * recoup 2026-10-05 (lane C1, ~27 compiles): the older draft (docs/notes) was 110 B off at 172 B.
 * Fixes: hi and wi are plain u32 with an unsigned shift, no u16 or enum (no lsls/lsrs pairs),
 * the area is signed (int)(wi * h) / 8 with h the raw table halfword, and n is an int (a u32 n
 * lets mwcc sink the divide chain below GX_BeginLoadTex; int n keeps it before the call as the
 * original does). Table const, order of wi/hi loads, n position, int/u16 h, callee u32 params,
 * and the six per-function pragmas (on the earlier form) did not help.
 * Residue: (1) entry spills: the original stores r2, r3, r1 with the table index load between;
 * ours stores r1, r2, r3 and loads the u16 argument f before the h spill. (2) base (a+0xc) is
 * loaded early into r4 and off into r5 in the original; ours loads base after the chain into r5
 * and off into r4, so the final add is r5,r4 instead of r4,r5.
 *
 * final push 2026-10-05 G5L10 (40 compiles, 3 rounds): 23 -> 7 B. Fixes: (1) c and d are u16
 * here and u16 in TEXT_TEXTURE_PrintToClearedBitmap (the caller TEXT_TEXTURE_LoadTexPlttByName declares them u16): the entry
 * spills come out r2, r3, r1 as in the original; b is u32 (FAB4 passes u32). (2) the tail
 * mirrors the matched sibling TEXT_TEXTURE_UploadPalette (u32 b,a; a = base field first, then b = (u16)field*8):
 * base is read BEFORE off and declared AFTER it (u32 off; u32 base;), which gives the base load
 * right after the offset load and the final add r4,r5.
 * Residue (7 B): the original loads the heap halfword f (add r3,sp,#0x38; ldrh r3,[r3,#4])
 * after the wi index load (ldrh r0,[r5]) and after the h spill and lsrs; ours hoists it above
 * the h spill. Tried without effect: const a, struct view of a, inline alloc helper, u16 heap
 * local, *(u16 *)&f, w local, wi/hi inline or reordered (wi before hi or h declared last
 * moves spill slots, 154 B), u32 heap callee param (117 B), five opt_ pragmas, peephole off.
 * pass 2 2026-10-06 P2L15 (40 compiles, 3 rounds, no change to the form, still 7 B): cause found.
 * The image's heap load waits for `str h` because that store goes to a memory OBJECT; a spill
 * store never blocks a stack-parameter load. Diagnostic `BMP_Delete(&h)` puts the f load at
 * +0x20 exactly; `&vram, &buf, &h` with declarations vram, buf, h also gives the image frame
 * (h 0x14, buf 0x18, vram 0x1c), so the original keeps h, buf and vram in memory. Every memory
 * form tried (aggregate {h,buf,vram} with an address use, value temp, wi first, u32 c/d, u16 b)
 * also flips the entry (str r1,[sp,#8] first, index in r1). Forms that do not keep h in memory:
 * inline out-pointer helper, hp = &h, unused &w, union, one-member struct/array, nested blocks
 * (all folded or scalarised). optimization_level 1 shows the f load is textually last.
 * pass 3 2026-10-06 P3L08 (3 compiles): EXACT. h is a u16 local (the table halfword) and
 * hi = (u32)h >> 3 keeps lsrs. mwcc keeps the u16 stack parameter f load behind the spill
 * store of a narrow local, but hoists it above the spill of a u32 local (docs/idioms
 * a-u16-stack-parameter-passed-to-a-u16-callee-stays-behind-a-spill-store.md, SHINKA_CHECK_CheckEvolution
 * pidHigh; a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md for the (u32) widen).
 * The earlier u16 h try (154 B) used h >> 3, which promotes to int and gives asrs.
 */
void TEXT_TEXTURE_UploadTextTexture(TexReq *req, struct Strbuf *text, u16 xPos, u16 yPos, u16 color, u16 heapId)
{
    u16 h;
    u32 hi;
    u32 wi;
    void *buf;
    void *tmp;
    void *vram;
    int n;
    u32 off;
    u32 base;

    h = d_021726A0[req->plttFmt].formatId;
    hi = (u32)h >> 3;
    wi = (u32)d_021726A0[req->texFmt].formatId >> 3;
    tmp = BMP_Create(wi, hi, 0x20, heapId);
    buf = BMP_Create(wi, hi, 0x20, heapId);
    TEXT_TEXTURE_PrintToClearedBitmap(text, xPos, yPos, color, buf, req->font);
    TEXT_TEXTURE_ConvertToTileOrder(buf, tmp);
    vram = BMP_GetPixels(tmp);
    base = req->texOfs;
    off = (u16)req->texVramKey << 3;
    n = ((int)(wi * h) / 8) << 5;
    GX_BeginLoadTex();
    DC_FlushRange(vram, n);
    GX_LoadTex(vram, base + off, n);
    GX_EndLoadTex();
    BMP_Delete(buf);
    BMP_Delete(tmp);
}

void TEXT_TEXTURE_UploadPalette(TexReq *req, void *dest)
{
    u32 plttKeyOfs;
    u32 plttBase;

    plttBase = req->plttOfs;
    plttKeyOfs = (u16)req->plttVramKey * 8;
    GX_BeginLoadTexPltt();
    DC_FlushRange(dest, 32);
    GX_LoadTexPltt(dest, plttBase + plttKeyOfs, 32);
    GX_EndLoadTexPltt();
}
