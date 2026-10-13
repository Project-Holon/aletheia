/*
 * file:     waza_oshie.c
 * unit:     yes
 * function: WAZA_OSHIE_Create, WAZA_OSHIE_Delete, WAZA_OSHIE_CreateMoveList, WAZA_OSHIE_IsListEntryValid, WAZA_OSHIE_LoadTexPlttByName, WAZA_OSHIE_GetTexFormatCount, WAZA_OSHIE_ClearBitmap, WAZA_OSHIE_PrintToClearedBitmap, WAZA_OSHIE_ConvertToTileOrder, WAZA_OSHIE_UploadTextTexture, WAZA_OSHIE_UploadPalette, TOWN_MAP_SPOT_Classify
 * address:  0x0216F918
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trcard_sys.c (it held four originals); __FILE__ anchors: event_battle.c 0x0216E95C, trcard_sys.c 0x0216F0AC, waza_oshie.c 0x0216F918.
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   d_02172B74 0x02172B74 data ov010 a1
 *   POKE_PERSONAL_LoadDataDirect  0x0201ADD0  thumb
 *   func_02047250        0x02047250  arm
 *   STD_GetStringLength  0x0208CC78  arm
 *   NNS_G3dGetResDataByName        0x0206E62C  arm
 *   GF_FONT_Create        0x0201D7EC  thumb
 *   GF_FONT_Delete        0x0201D83C  thumb
 *   d_021726A0           0x021726A0  data
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 *   WAZA_OSHIE_ClearBitmap 0x0216FC50 thumb ov010
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_GetTileBytes  0x02043994  arm
 *   BMP_Create  0x02043678  arm
 *   func_0207F7A0  0x0207F7A0  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   func_0207F7FC  0x0207F7FC  arm
 *   func_0207F9B4  0x0207F9B4  arm
 *   BMP_Delete  0x020437AC  arm
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 */

struct GfFont;
struct Bmp;
struct Bmp;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef struct {
    u16 x;
    u16 y;
    int z;
} Pos;

typedef struct LearnsetEntry {
    u16 move;
    u16 level;
} LearnsetEntry;

typedef struct TexResource {
    u8 pad00[8];
    u32 texVramKey;     /* 0x08 */
    u8 pad0C[2];
    u16 texDict;        /* 0x0E */
    u8 pad10[0x2C - 0x10];
    u32 plttVramKey;    /* 0x2C */
    u8 pad30[4];
    u16 plttDict;       /* 0x34 */
} TexResource;

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

struct Rec {
    u8 x;
    u8 y;
    u8 pad[10];
};

struct Pos {
    u8 pad[0x0c];
    u16 x;
    u16 y;
};

extern unsigned int func_02017E1C(void *a, unsigned int b, unsigned int c);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern void POKE_PERSONAL_LoadDataDirect(unsigned int a, int b, void *buf);
extern TexResource *func_02047250(void *p);
extern int STD_GetStringLength(const char *s);
extern void *NNS_G3dGetResDataByName(const void *dict, const char *name);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 GF_FONT_Delete(void *ptr);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
void *WAZA_OSHIE_Create(u32 heapId);
void WAZA_OSHIE_Delete(void *work, unsigned unused1, unsigned unused2, unsigned unused3);
u16 *WAZA_OSHIE_CreateMoveList(void *pokemon, u32 heapId);
int WAZA_OSHIE_IsListEntryValid(u16 *p);
int WAZA_OSHIE_LoadTexPlttByName(void *file, const char *texName, void *extra, const char *plttName, u32 text, u16 xPos, u16 yPos, u16 color, u16 heapId, TexKey *out);
int WAZA_OSHIE_GetTexFormatCount(void);
void WAZA_OSHIE_ClearBitmap(void *bmp);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern u8 BMP_GetTileBytes(struct Bmp *b);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heapId);
extern void func_0207F7A0(void);
extern void DWCi_ScreenDC_FlushRange(void *p, int n);
extern void func_0207F7FC(void *p, int src, int n);
extern void func_0207F9B4(void);
extern void BMP_Delete(struct Bmp *p);
extern void func_0207FA0C(void);
extern void func_0207FA40(void *,u32,u32);
extern void func_0207FADC(void);
void WAZA_OSHIE_PrintToClearedBitmap(void *text, u16 xPos, u16 yPos, u16 color, void *bmp, void *font);
void WAZA_OSHIE_ConvertToTileOrder(void *srcBmp, void *dstBmp);
void WAZA_OSHIE_UploadTextTexture(TexReq *req, u32 text, u16 xPos, u16 yPos, u16 color, u16 heapId);
void WAZA_OSHIE_UploadPalette(TexReq *req, void *dest);
int TOWN_MAP_SPOT_Classify(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags);
extern char d_02172B74[];
extern const TexFormat d_021726A0[];


void *WAZA_OSHIE_Create(u32 heapId)
{
    void *work;

    work = func_02030734(heapId, 28, 0, d_02172B74, 35);
    MI_CpuFill8(work, 0, 28);
    return work;
}





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_020307B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WAZA_OSHIE_Delete.c \
 *       --func WAZA_OSHIE_Delete --addr 0x0216F940 --region ov010 --cc dsi/1.1p1 --thumb
 */
void WAZA_OSHIE_Delete(void *work, unsigned unused1, unsigned unused2, unsigned unused3)
{
    func_020307B0(work);
}





static inline int LearnsetEntry_IsEnd(LearnsetEntry x)
{
    return x.move == 0xFFFF && x.level == 0xFFFF;
}





static inline u16 LearnsetEntry_Level(LearnsetEntry x)
{
    return x.level;
}





static inline u16 LearnsetEntry_Move(LearnsetEntry x)
{
    return x.move;
}





/*
 * Builds the list of level-up moves a mon could still learn: reads
 * species/form/level and its 4 current moves, loads the learnset (26
 * {move, level} pairs, 0xFFFF/0xFFFF terminated) with POKE_PERSONAL_LoadDataDirect, and
 * collects moves at or below its level that it neither knows nor already
 * collected. Returns the 0x34-byte list (caller frees); frees the learnset.
 *
 * pass 2 2026-10-06 P2L52: EXACT (also EXACT with --lang c). Load-bearing:
 *   - Every entry access is a by-value inline helper called on `tbl[j]`
 *     itself (no named entry local). The argument is not a plain local, so
 *     each call keeps its own parameter copy (the 8 stack LearnsetEntry slots of the
 *     image): CSE makes the shared tbl[j] temp at sp+0x18, loop invariants
 *     make the copies before the k and m loops, and the parameter copies in
 *     the loops keep their stores inside the loop. Named LearnsetEntry locals or
 *     helpers called on a plain local are copy-propagated or substituted.
 *   - `for` loops everywhere with `n = 0, j = 0` in the j loop (propagation
 *     on: the hoisted zero argument is the copy of i, the m guard is
 *     `cmp n,#0; bls`). A do-while k or m loop hoists the in-loop copy.
 *   - `LearnsetEntry *tbl` declared first: spill slots species 0x10, form 0xc, tbl 0x14.
 *   - The file name pool word is d_02172B74 (the old header said 02173B74).
 */
u16 *WAZA_OSHIE_CreateMoveList(void *mon, u32 heap)
{
    LearnsetEntry *tbl;
    u16 cur[4];
    u16 species;
    u8 form;
    u8 level;
    u8 i;
    u8 n;
    u8 j;
    u8 k;
    u8 m;
    u16 *out;

    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6F, 0);
    level = func_02017E1C(mon, 0x9E, 0);
    for (i = 0; i < 4; i++)
        cur[i] = func_02017E1C(mon, 0x36 + i, 0);
    tbl = (LearnsetEntry *)func_02030734(heap, 0x68, 0, d_02172B74, 0x55);
    out = (u16 *)func_02030734(heap, 0x34, 0, d_02172B74, 0x56);
    POKE_PERSONAL_LoadDataDirect(species, form, tbl);
    for (n = 0, j = 0; j < 26; j++) {
        if (LearnsetEntry_IsEnd(tbl[j])) {
            out[n] = 0xFFFF;
            break;
        }
        if (LearnsetEntry_Level(tbl[j]) > level)
            continue;
        for (k = 0; k < 4; k++) {
            if (cur[k] == LearnsetEntry_Move(tbl[j]))
                break;
        }
        if (k != 4)
            continue;
        for (m = 0; m < n; m++) {
            if (out[m] == LearnsetEntry_Move(tbl[j]))
                break;
        }
        if (m != n)
            continue;
        out[n] = LearnsetEntry_Move(tbl[j]);
        n++;
    }
    func_020307B0(tbl);
    return out;
}



int WAZA_OSHIE_IsListEntryValid(u16 *p) { if (*p != 0xffff) return 1; return 0; }




/*
 * Look up a texture and a palette by name in a G3D texture resource,
 * derive their formats from the 7-entry d_021726A0 table, and load them
 * through WAZA_OSHIE_UploadTextTexture (optionally WAZA_OSHIE_UploadPalette). One lever: the four
 * stack aggregates declared in reverse of their frame order.
 */
int WAZA_OSHIE_LoadTexPlttByName(void *file, const char *texName, void *extra, const char *plttName, u32 text, u16 xPos, u16 yPos, u16 color, u16 heap, TexKey *out)
{
    TexKey key;
    char tn[16];
    char pn[16];
    TexReq req;
    u16 ofs;
    TexResource *res;
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
    res = func_02047250(file);
    key.texVramKey = res->texVramKey;
    key.plttVramKey = res->plttVramKey;
    ofs = res->texDict;
    for (i = 0; i < STD_GetStringLength(texName); i++)
        tn[i] = texName[i];
    for (; i < 16; i++)
        tn[i] = 0;
    e = NNS_G3dGetResDataByName((u8 *)res + ofs, tn);
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
    ofs = res->plttDict;
    for (i = 0; i < STD_GetStringLength(plttName); i++)
        pn[i] = plttName[i];
    for (; i < 16; i++)
        pn[i] = 0;
    e = NNS_G3dGetResDataByName((u8 *)res + ofs, pn);
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
    WAZA_OSHIE_UploadTextTexture(&req, text, xPos, yPos, color, heap);
    if (extra != 0)
        WAZA_OSHIE_UploadPalette(&req, extra);
    GF_FONT_Delete(font);
    if (out != 0)
        *out = key;
    return 1;
}



int WAZA_OSHIE_GetTexFormatCount(void)
{
    return 7;
}




/*
 * Clears the pixel buffer of a bitmap: gets the buffer (BMP_GetPixels) and
 * its byte size (BMP_GetByteSize), then stores 0 in every byte. The loop label
 * sits on the strb, so the `adds r1, r2, #0` before it is the zero copied
 * from the counter, not a store of i (docs/idioms/a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero.md).
 */
void WAZA_OSHIE_ClearBitmap(void *bmp)
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


void WAZA_OSHIE_PrintToClearedBitmap(void *text, u16 xPos, u16 yPos, u16 color, void *bmp, void *font)
{
    WAZA_OSHIE_ClearBitmap(bmp);
    PRINTSYS_PrintColor(bmp, xPos, yPos, text, font, color);
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
void WAZA_OSHIE_ConvertToTileOrder(void *srcBmp, void *dstBmp)
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
 * lets mwcc sink the divide chain below func_0207F7A0; int n keeps it before the call as the
 * original does). Table const, order of wi/hi loads, n position, int/u16 h, callee u32 params,
 * and the six per-function pragmas (on the earlier form) did not help.
 * Residue: (1) entry spills: the original stores r2, r3, r1 with the table index load between;
 * ours stores r1, r2, r3 and loads the u16 argument f before the h spill. (2) base (a+0xc) is
 * loaded early into r4 and off into r5 in the original; ours loads base after the chain into r5
 * and off into r4, so the final add is r5,r4 instead of r4,r5.
 *
 * final push 2026-10-05 G5L10 (40 compiles, 3 rounds): 23 -> 7 B. Fixes: (1) c and d are u16
 * here and u16 in WAZA_OSHIE_PrintToClearedBitmap (the caller WAZA_OSHIE_LoadTexPlttByName declares them u16): the entry
 * spills come out r2, r3, r1 as in the original; b is u32 (FAB4 passes u32). (2) the tail
 * mirrors the matched sibling WAZA_OSHIE_UploadPalette (u32 b,a; a = base field first, then b = (u16)field*8):
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
void WAZA_OSHIE_UploadTextTexture(TexReq *req, u32 text, u16 xPos, u16 yPos, u16 color, u16 heapId)
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
    WAZA_OSHIE_PrintToClearedBitmap((void *)text, xPos, yPos, color, buf, req->font);
    WAZA_OSHIE_ConvertToTileOrder(buf, tmp);
    vram = BMP_GetPixels(tmp);
    base = req->texOfs;
    off = (u16)req->texVramKey << 3;
    n = ((int)(wi * h) / 8) << 5;
    func_0207F7A0();
    DWCi_ScreenDC_FlushRange(vram, n);
    func_0207F7FC(vram, base + off, n);
    func_0207F9B4();
    BMP_Delete(buf);
    BMP_Delete(tmp);
}


void WAZA_OSHIE_UploadPalette(TexReq *req, void *dest)
{
    u32 plttKeyOfs;
    u32 plttBase;

    plttBase = req->plttOfs;
    plttKeyOfs = (u16)req->plttVramKey * 8;
    func_0207FA0C();
    DWCi_ScreenDC_FlushRange(dest, 32);
    func_0207FA40(dest, plttBase + plttKeyOfs, 32);
    func_0207FADC();
}



/*
 * Classifies table entry idx (12-byte records) against a position:
 * 0 = inside, 1 = within three steps on one axis, 2 = out of reach or
 * locked. 0xFF marks an unused record; 0xFE records are gated by a bit
 * (idx - 0x21) of the 16-bit mask at flags.
 */
int TOWN_MAP_SPOT_Classify(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags)
{
    int x;
    int y;
    int m;

    x = tbl[idx].x;
    if (x == 0xff)
        return 2;
    if (x == 0xfe) {
        m = flags[0] | (flags[1] << 8);
        if (m & (1 << (idx - 0x21)))
            return 0;
        return 2;
    }
    if (x <= pos->x) {
        y = tbl[idx].y;
        if (y <= pos->y)
            return 0;
        if (y - pos->y <= 3)
            return 1;
    } else {
        y = tbl[idx].y;
        if (y <= pos->y) {
            if (x <= pos->x)
                return 0;
            if (x - pos->x <= 3)
                return 1;
        }
    }
    return 2;
}
