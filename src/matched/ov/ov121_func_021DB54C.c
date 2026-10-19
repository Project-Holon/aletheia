/*
 * function: MYSTERY_ALBUM_SetupSlot
 * address: 0x021DB54C
 * packet: pkt_ov121_021DB54C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (lane P9): first draft, no source existed. DIFF, 1024 vs 1004 bytes.
 *   Structure matches the listing (loops, tail, callee arguments). Separate locals
 *   for rect/pos/cur (not one struct) give the right heap/index prologue; a static
 *   inline ents(p) = p + 0x28 gives the double store of the table base.
 *   Residue: the original keeps the two signed divisions by 3 inside the y loop
 *   (dividend (u8)k hoisted to a spill slot, rem first, quot second); every form
 *   tried hoists the whole tile base out of the loop (parenthesised, one expression,
 *   u8 m, inline cast, cols=3 local: 12 compiles). Spill slot numbers and register
 *   colours (rx r5, x r4, yy r7) follow from that. The 0x100 in the final block is
 *   built as r4(=1)+0xff in the original, not reproduced. Pool-base adds (p+0xb08
 *   etc.) are shared in the draft but recomputed in the original.
 *   Idioms checked: a-u16-stack-parameter-reloaded-per-call-means-u16-callee-parameters
 *   (heap already u16 in all prototypes), narrow-stack-parameters-and-callee-prototype-
 *   free-the-narrow-home-store (prologue now matches for 14 bytes).
 * note 2026-10-05 (lane P9b): still DIFF, 1028 vs 1004 bytes. 13 more compiles, none changed
 *   the size. Tried: tile base as a static inline tb(k, y) called in the y body; separate
 *   rem/quo locals (rem first); tile expression written inside the x loop call argument;
 *   y loop as do/while; m = (u8)k assigned inside the y body instead of before the loop
 *   (mwcc hoists the cast AND both divisions out of the y loop in every form, so LICM
 *   hoists in one step through the whole chain); per-function pragmas opt_loop_invariants,
 *   opt_lifetimes, opt_propagation, opt_common_subs off (size 1028/1028/1064/1100, no help).
 *   The original hoists the (u8)k cast but keeps both calls in the y body: the divisions
 *   must be loop-variant or non-hoistable at IR level for a reason no source form tried
 *   shows. Untested guesses: a hoist budget limit, or a different dividend source.
 *   Idioms checked: signed-modulo-magic-reappears-when-the-source-divides-by-the-same-
 *   constant-twice (not applicable, divisor 3 is a real call here); matched twin ov217
 *   021BD178 has the divisions inside the loop only because its operands depend on i, j.
 * note 2026-10-05 final push G10L1: DIFF, 53 of 1004 bytes off (was 470 of 1028 at the start of
 *   the push). Size now equals the original. What closed most of the residue:
 *   (1) the tail pos.x chain is `if (a) x = h2; else if (b) x = h2 - 0x100; else if (b == 0)
 *   x = h2 + 0x100; else x = h2;` (the original tests a once; 1028 -> 1016 bytes);
 *   (2) the cur block is `if (a == 0) { if (b) x -= 0x100; else if (b == 0) x += 0x100; }`
 *   (1016 -> 1004); (3) `#pragma opt_loop_invariants off` keeps both /3 and %3 calls inside the
 *   y loop (the old lane tried it only while the size was still wrong); (4) do-while loops with
 *   `x = 0;` first in the y body and `y = 0;` before the loops give the original head order;
 *   (5) a local for MYSTERY_ALBUM_GetEntryBmp's result puts that call before the idx*4 address work;
 *   (6) declaration order off, tab, idx, y, y2, y3 (one counter per loop), m, src, k, ry, rx
 *   gives the original spill slots for most locals; tab = p + 0x28 plain (no inline helper);
 *   (7) dy = 0 before MI_CpuFill8.
 *   Residue (53 bytes): rx and x swapped (original x r4, rx r5; mine rx r4, x r5; decl order of
 *   x/rx did not move it, 2 compiles); index and ry slots swapped (original index sp+0x18, ry
 *   sp+0x1c); obj and the p+0xb88 base temp slots swapped (original obj sp+0x48, temp sp+0x44);
 *   `dx = 0` (movs r6) sits before the call to MYSTERY_ALBUM_GetEntryGraphicIndex in mine, just before the blx of
 *   CLACT_RegisterCharacter in the original.
 *   Idioms checked: of-two-equal-temps-the-later-born-one-gets-the-lower-register (no source
 *   order found that flips x/rx), a-separate-index-local-per-loop-reorders-spill-slots (y per
 *   loop: moved y2/y3 next to y), function-scope-versus-block-scope-decides-spill-slot-order,
 *   div-and-mod-are-two-calls, a-reloaded-loop-invariant-means-the-loop-was-not-rotated
 *   (goto loops still hoist). Twin: ov121 021DB938 (same top condition and loops).
 * note 2026-10-05 final push G10L1 round 2: DIFF, 28 of 1004 bytes off. `dx = 0;` moved to just
 *   after the CLACT_RegisterCharacter statement (53 -> 28; this also fixed the obj/temp slot swap).
 *   Remaining: x in r5 and rx in r4 (original x r4, rx r5), and the index/ry spill slots swapped
 *   (original index sp+0x18, ry sp+0x1c). Tried without effect: dx = 0 as a call argument (251),
 *   u8 rx/ry, a y=x=0 head, separate x2/x3 per loop, decl order of x/rx/tile; opt_propagation off
 *   (91), opt_common_subs off (758), opt_lifetimes off (25 but x r4, rx r6, tile r5, index/ry swap
 *   stays); callee prototypes re-grepped in src/matched (all match the draft). Without the
 *   pragma and with direct r.b[0]/r.b[1] reads (like matched 021DB938) the slots all match but
 *   both /3 and %3 are hoisted (84); `(u8)k` inline, `cols = 3` local did not stop the hoist.
 * note pass 2 2026-10-06 P2L41: EXACT (c99 and c). Closed with `#pragma opt_lifetimes off` (beside
 *   opt_loop_invariants off), one tile local per loop (tile, tile2, tile3, like y/y2/y3), x declared
 *   before rx, int ry passed straight to BG_SYS_FillTileMap with the u32 x/y prototype used by matched
 *   callers (ov217 021BA284, ov088 021BB810). Under lifetimes off the colour order follows degree
 *   then declaration order: per-loop tiles make the tiles drop out first, then rx, then x, giving
 *   x r4, rx r5, tile r6. Passing ry (not r.b[1]) keeps ry itself as the spilled web, so it takes
 *   the slot after k (sp+0x1c) and index takes sp+0x18.
 * symbols:
 *   d_021DF86E 0x021DF86E data ov121 a2
 *   d_021DF86F 0x021DF86F data ov121 a1
 *   MYSTERY_ALBUM_IsEntryValid 0x021DBF04 thumb ov121
 *   MYSTERY_ALBUM_GetEntryBmp 0x021DBF08 thumb ov121
 *   MYSTERY_ALBUM_CreateEntryArc 0x021DBF10 thumb ov121
 *   MYSTERY_ALBUM_GetEntryPaletteResId 0x021DBF40 thumb ov121
 *   MYSTERY_ALBUM_GetEntryIconPalette 0x021DBF70 thumb ov121
 *   MYSTERY_ALBUM_GetEntryGraphicIndex 0x021DBF9C thumb ov121
 *   MYSTERY_ALBUM_GetEntryCellResId 0x021DBFE4 thumb ov121
 *   MYSTERY_ALBUM_GetEntryCellAnimResId 0x021DC004 thumb ov121
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 *   MYSTERY_ALBUM_GetEntryIconX 0x021DC03C thumb ov121
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_CopyPixels 0x02043814 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef union Rect { s16 h[4]; u8 b[8]; } Rect;
typedef struct Cur { s16 x; s16 y; } Cur;
typedef struct Pos { s16 x; s16 y; u8 pad[3]; u8 flag; } Pos;
extern const Rect d_021DF86E[];
extern const u8 d_021DF86F[];
struct Descriptor;
struct CharBuf;
extern void BG_SYS_SetTileEntry(u32,u16,u8,u8,u8,u8,u8);
extern void BG_SYS_FillTileMap(u32,u32,u32,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
struct Bmp;
struct Obj;
struct Vec2;
extern void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src);
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern int CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *);
extern void MI_CpuFill8(void *, int, int);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int MYSTERY_ALBUM_IsEntryValid(int *p);
extern void *MYSTERY_ALBUM_GetEntryBmp(void *);
extern void *MYSTERY_ALBUM_CreateEntryArc(void *, u16);
extern u32 MYSTERY_ALBUM_GetEntryPaletteResId(void *);
extern u32 MYSTERY_ALBUM_GetEntryIconPalette(void *);
extern int MYSTERY_ALBUM_GetEntryGraphicIndex(void *);
extern int MYSTERY_ALBUM_GetEntryCellResId(void *);
extern int MYSTERY_ALBUM_GetEntryCellAnimResId(void *);
extern int MYSTERY_ALBUM_GetEntryKind(void *);
extern int MYSTERY_ALBUM_GetEntryIconX(void *);
#pragma opt_loop_invariants off
#pragma opt_lifetimes off
void MYSTERY_ALBUM_SetupSlot(char *p, int a, int b, int c, u16 index, u16 heap)
{
    void *obj;
    int off;
    char *tab;
    int idx;
    int y, y2, y3;
    int m;
    const Rect *src;
    int k, ry;
    int x, rx, yy, tile, tile2, tile3;
    s16 dx, dy;
    void *dsc;
    Rect r;
    Pos pos;
    Cur cur;
    k = index + c * 4;
    tab = p + 0x28;
    off = k * 0xdc;
    idx = index;
    src = &d_021DF86E[index];
    r = *src;
    if ((a && *(u32 *)(p + 0xad0) == 0) || (a == 0 && *(u32 *)(p + 0xad0))) {
        idx += 4;
        r.b[0] += 32;
        r.b[2] += 32;
    }
    y = 0;
    ry = r.b[1];
    rx = r.b[0];
    m = (u8)k;
    do {
        x = 0;
        yy = ry + y;
        tile = y * 32 + ((m % 3) * 64 + 0x58 + (m / 3) * 2);
        do {
            BG_SYS_SetTileEntry(3, (u16)(x + tile), (u8)(rx + x - 2), (u8)yy, 1, 1, 3);
            x++;
        } while (x < 2);
        y++;
    } while (y < 2);
    if (MYSTERY_ALBUM_IsEntryValid((int *)(tab + off)) == 0) {
        y2 = 0;
        do {
            x = 0;
            yy = ry + y2;
            tile2 = y2 * 32 + 384;
            do {
                BG_SYS_SetTileEntry(3, (u16)(x + tile2), (u8)(rx + x), (u8)yy, 1, 1, 3);
                x++;
            } while (x < 12);
            y2++;
        } while (y2 < 7);
        BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0xb08 + idx * 4)), 0);
        BMP_WIN_TransferChars(*(void **)(p + 0xb08 + idx * 4));
        return;
    }
    y3 = 0;
    do {
        x = 0;
        yy = ry + y3;
        tile3 = y3 * 32 + 0x40;
        do {
            BG_SYS_SetTileEntry(3, (u16)(x + tile3), (u8)(rx + x), (u8)yy, 1, 1, 5);
            x++;
        } while (x < 12);
        y3++;
    } while (y3 < 7);
    BG_SYS_FillTileMap(3, r.b[0], ry, 12, 7, (u8)MYSTERY_ALBUM_GetEntryIconX(tab + off));
    dsc = MYSTERY_ALBUM_GetEntryBmp(tab + off);
    BMP_CopyPixels(dsc, BMP_WIN_GetBmp(*(void **)(p + 0xb08 + idx * 4)));
    BMP_WIN_TransferChars(*(void **)(p + 0xb08 + idx * 4));
    obj = MYSTERY_ALBUM_CreateEntryArc(tab + off, heap);
    if (MYSTERY_ALBUM_GetEntryKind(tab + off) != 1)
        *(int *)(p + 0xb88 + idx * 4) = CLACT_RegisterPaletteEx(obj, MYSTERY_ALBUM_GetEntryPaletteResId(tab + off), 0, (u16)((idx + 4) << 5), 0, 1, heap);
    *(int *)(p + 0xb68 + idx * 4) = CLACT_RegisterCellAnim(obj, MYSTERY_ALBUM_GetEntryCellResId(tab + off), MYSTERY_ALBUM_GetEntryCellAnimResId(tab + off), heap);
    *(int *)(p + 0xb48 + idx * 4) = CLACT_RegisterCharacter(obj, MYSTERY_ALBUM_GetEntryGraphicIndex(tab + off), 0, 0, heap);
    dx = 0;
    ARC_TOOL_DeleteHandle(obj);
    dy = 0;
    MI_CpuFill8(&pos, 0, 8);
    pos.y = r.h[3];
    pos.flag = 1;
    if (MYSTERY_ALBUM_GetEntryKind(tab + off) == 2) {
        dx = 4;
        dy = 8;
    }
    if (a)
        pos.x = r.h[2];
    else if (b)
        pos.x = r.h[2] - 0x100;
    else if (b == 0)
        pos.x = r.h[2] + 0x100;
    else
        pos.x = r.h[2];
    pos.x += dx;
    pos.y += dy;
    *(void **)(p + 0xb28 + idx * 4) = CLACT_CreateActor(*(void **)(p + 8), *(u32 *)(p + 0xb48 + idx * 4),
        MYSTERY_ALBUM_GetEntryKind(tab + off) == 1 ? *(u32 *)(p + 0xba8) : *(u32 *)(p + 0xb88 + idx * 4),
        *(u32 *)(p + 0xb68 + idx * 4), &pos, 0, *(u16 *)(p + 0x24));
    CLACT_SetActorPaletteOffset(*(void **)(p + 0xb28 + idx * 4), (u8)MYSTERY_ALBUM_GetEntryIconPalette(tab + off), 0);
    CLACT_SetActorDrawEnable(*(void **)(p + 0xb28 + idx * 4), 1);
    if (*(u32 *)(p + 0xae0) && *(u16 *)(p + 0xade) == k) {
        cur.x = src->b[0] * 8 - 0x18;
        cur.y = d_021DF86F[index * 8] * 8 - 8;
        if (a == 0) {
            if (b)
                cur.x -= 0x100;
            else if (b == 0)
                cur.x += 0x100;
        }
        CLACT_AddActorSurfacePos(*(void **)(p + 0xaf0), (const struct Vec2 *)(&cur), 0);
    }
}
#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset
