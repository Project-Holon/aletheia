/*
 * file:     bmp_menu.c
 * unit:     yes
 * function: func_0201F53C, func_0201F548, func_0201F554, func_0201F57C, func_0201F5BC, func_0201F5DC, func_0201F614, func_0201F628, func_0201F73C, func_0201F79C, func_0201F7A8, BMP_MENUWORK_Create, BMP_MENUWORK_Delete, BMP_MENUWORK_AddMsgItem, BMP_MENUWORK_AddStrItem, BMP_MENUWORK_FindFreeEntry, BMP_MENUWORK_ReleaseItems, BMP_MENUWORK_CountItems, BMP_MENU_Create, BMP_MENU_Add, BMP_MENU_Delete, BMP_MENU_ProcessInput, BMP_MENU_MoveCursor, BMP_MENU_StepSelection, BMP_MENU_GetMaxItemWidth, BMP_MENU_DrawItems, BMP_MENU_DrawCursor, BMP_MENU_GetItemPixelPos, BMP_MENU_CreateYesNo, BMP_MENU_ProcessYesNo, BMP_MENU_DeleteYesNo
 * address:  0x0201F53C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0209E8C8_Map  0x0209E8C8  data
 *   sub_0209E8CA_Map  0x0209E8CA  data  a1
 *   func_0203FB44  0x0203FB44  arm
 *   func_02041300  0x02041300  arm
 *   func_02045730 0x02045730 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_02045748 0x02045748 arm
 *   func_02045750 0x02045750 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02030734        0x02030734  arm
 *   sBmpMenuWorkFile     0x020A7374  data
 *   func_020307B0  0x020307B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Clone  0x02045874  arm
 *   STRBUF_Delete  0x02045808  arm
 *   sBmpMenuFile    0x020A7384  data
 *   BMP_CURSOR_Create   0x02020D18  thumb
 *   BMP_CURSOR_SetTileBitmap   0x02020DC8  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02045770  0x02045770  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   BMP_Clear   0x02043B5C  arm
 *   func_0201C6FC   0x0201C6FC  thumb
 *   BMP_CURSOR_Draw   0x02020D5C  thumb
 *   func_02045B38   0x02045B38  arm
 *   MSGDATA_Delete   0x02045C04  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   BMP_WIN_Create   0x020450F0  arm
 *   GF_FONT_Create   0x0201D7EC  thumb
 *   func_0201DC80   0x0201DC80  thumb
 *   func_0201C440   0x0201C440  thumb
 *   BMP_WIN_MakeScreen   0x02045374  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_CURSOR_Delete  0x02020D3C  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 */
struct BmpWin;
struct MsgBank;
struct U16Vec;
struct BmpCursor;
struct GfFont;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short s16;

typedef signed char s8;

typedef struct {
    union {
        const void *text;   /* +0x00  item text */
        void       *handle; /* same word read as an owned string handle */
        u32         raw;    /* 0 = free entry, 0xFFFFFFFF = list terminator */
    } u;
    u32 value;              /* +0x04  value returned when chosen */
} BmpMenuWork;

typedef struct {
    struct BmpWin *win;     /* +0x00 */
    u8    printed;          /* +0x04  set after an item was printed */
} PrintUtil;

typedef struct {
    BmpMenuWork *items;     /* +0x00 */
    struct BmpWin *win;     /* +0x04 */
    u8   fontId;            /* +0x08 */
    u8   numColumns;        /* +0x09 */
    u8   itemsPerColumn;    /* +0x0A */
    u8   lineSpacing : 4;   /* +0x0B */
    u8   cursorMode  : 2;   /* 1 = no cursor drawn */
    u8   wrap        : 2;   /* nonzero = cursor wraps at the ends */
    u16  xPad;              /* +0x0C */
    u16  lineHeight;        /* +0x0E */
    u32  reserved10;        /* +0x10  zero, never read */
    PrintUtil *util;        /* +0x14 */
    void *que;              /* +0x18  print queue */
    struct GfFont *fontH;   /* +0x1C */
    u32  committed;         /* +0x20  window committed to VRAM */
} BmpMenuHeader;

typedef struct {
    BmpMenuHeader header;   /* +0x00 */
    struct BmpCursor *cursor; /* +0x24 */
    u32 cancelMask;         /* +0x28 */
    u8  pad2C;
    u8  selected;           /* +0x2D */
    u8  colWidth;           /* +0x2E */
    u8  originX;            /* +0x2F */
    u8  originY;            /* +0x30 */
    u8  xPad;               /* +0x31 */
    u8  lineHeight;         /* +0x32 */
    u8  movedDir;           /* +0x33  direction accepted this frame, 1..4 */
    u16 heapId;             /* +0x34 */
    u16 pad36;
} BmpMenu;

typedef int            s32;

typedef struct {
    u8  bgFrame; /* +0 */
    u8  x;       /* +1 */
    u8  y;       /* +2 */
    u8  palette; /* +3 */
    u16 charBase; /* +4  callers pass it as base */
} WinDat;

extern void func_02049624(u32 arcId, u32 fileId, u32 layer, u32 tileOffset, u32 flagA, u32 flagB, u32 heapId);
extern void func_02049B40(u32 arcId, u32 fileId, u32 palBase, u32 byteOffset, u32 byteSize, u32 heapId);
extern void *func_020496E4(u32 arcId, u32 fileId, u32 layer, u32 flagA, u32 flagB, u32 heapId);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02041300(u32 bgId, u32 tile, u8 x, u8 y, u8 width, u8 height,
                          u32 palette);
extern u8 func_02045730(struct BmpWin *p);
extern u8 func_02045758(struct BmpWin *p);
extern u8 func_02045760(struct BmpWin *p);
extern u8 func_02045748(struct BmpWin *p);
extern u8 func_02045750(struct BmpWin *p);
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Clone(const struct U16Vec *src, u32 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct BmpCursor *BMP_CURSOR_Create(u32 heap);
extern void BMP_CURSOR_SetTileBitmap(struct BmpCursor *cursor, int heapId);
extern void BMP_CURSOR_Delete(struct BmpCursor *p);
extern u32  func_020362DC(void);
extern void func_020061E4(u32 id);
extern void *func_02045770(struct BmpWin *p);
extern void BMP_FillRect(void *bitmap, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern s32 _s32_div_f(s32 num, s32 den);
extern u32 func_0201D304(const void *str, struct GfFont *font, u32 flags);
extern void BMP_Clear(void *bitmap, u8 value);
extern void func_0201C6FC(void *que, void *bitmap, u32 x, u32 y, const void *str, struct GfFont *font);
extern void BMP_CURSOR_Draw(struct BmpCursor *c, u32 x, u32 y, PrintUtil *util, void *que, struct GfFont *font);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern struct BmpWin *BMP_WIN_Create(u32 bgFrame, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 slotId);
extern struct GfFont *GF_FONT_Create(int fontKind, int flagA, int flagB, int flagC, u32 heapId);
extern u32 func_0201DC80(struct GfFont *p);
extern void *func_0201C440(void *heapIdAsPtr);
extern void BMP_WIN_MakeScreen(struct BmpWin *cfg);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern u32 PRINTSYS_QUE_Main(void *que);
extern void func_0201C6EC(void *que);
extern void func_0201C4C0(void *que);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern u32 func_020452E8(struct BmpWin *win);
u8 func_0201F53C(int index);
u8 func_0201F548(int index);
void func_0201F554(u32 layer, u32 tileOffset, u32 frameId, u32 heapId);
void func_0201F57C(u32 layer, u32 palSlot, u32 frameId, u16 heapId);
void func_0201F5BC(u32 layer, u32 tileOffset, u32 palSlot, u32 frameId, u16 heapId);
void *func_0201F5DC(u32 layer, u32 palSlot, u32 frameId, u16 heapId);
void func_0201F614(int layer, u32 packedOffsets);
void func_0201F628(u16 bgId, u8 x, u8 y, u8 width, u8 height, u32 palette, u16 tileBase);
void func_0201F73C(struct BmpWin *win, int commitMode, u16 tileBase, u32 palette);
void func_0201F79C(struct BmpWin *desc, u32 commitMode, u32 tileBase, u32 palette);
void func_0201F7A8(struct BmpWin *desc, u32 commitMode);
BmpMenuWork *BMP_MENUWORK_Create(u32 count, u32 heapId);
u32 BMP_MENUWORK_Delete(void *items);
void BMP_MENUWORK_AddMsgItem(BmpMenuWork *items, struct MsgBank *bank, u32 msgId, u32 param, u32 heapId);
void BMP_MENUWORK_AddStrItem(BmpMenuWork *items, const struct U16Vec *src, u32 param, u32 heapId);
BmpMenuWork *BMP_MENUWORK_FindFreeEntry(BmpMenuWork *items, u32 *outTerminatorValue);
void BMP_MENUWORK_ReleaseItems(BmpMenuWork *items);
u32 BMP_MENUWORK_CountItems(BmpMenuWork *items);
BmpMenu *BMP_MENU_Create(const BmpMenuHeader *header, u8 originX, u8 originY, u8 startPos, u16 heapId, u32 cancelMask);
BmpMenu *BMP_MENU_Add(const BmpMenuHeader *header, u8 originX, u8 originY, u8 startPos, u16 heapId, u32 cancelMask);
void BMP_MENU_Delete(BmpMenu *menu, u8 *outSelected);
u32 BMP_MENU_ProcessInput(BmpMenu *menu);
int BMP_MENU_MoveCursor(BmpMenu *menu, u32 dir, u32 sfxId);
int BMP_MENU_StepSelection(BmpMenu *menu, u32 dir);
u32 BMP_MENU_GetMaxItemWidth(BmpMenu *menu);
void BMP_MENU_DrawItems(BmpMenu *menu);
void BMP_MENU_DrawCursor(BmpMenu *menu);
void BMP_MENU_GetItemPixelPos(BmpMenu *menu, u8 *outX, u8 *outY, u8 itemPos);
BmpMenu *BMP_MENU_CreateYesNo(const WinDat *winData, u16 tileBase, u8 palette, u8 startPos, u16 heapId);
u32 BMP_MENU_ProcessYesNo(BmpMenu *menu);
void BMP_MENU_DeleteYesNo(BmpMenu *menu);
extern u8 sub_0209E8C8_Map[];
extern u8 sub_0209E8CA_Map[];
extern char sBmpMenuWorkFile[];
extern char sBmpMenuFile[];









u8 func_0201F53C(int index)
{
    return sub_0209E8C8_Map[index];
}









/*
 * Promoted from src/pending/func_0201F548.c on 2026-09-22 (family wave 5,
 * wordset.c).  Every concrete byte was already reproduced; only the one
 * relocation was open.
 *
 * The second of the two three-instruction byte-table lookups behind
 * src/matched/unit_0201F554.c -- func_0201F53C reads the table at 0x0209E8C8
 * and this one the table at 0x0209E8CA, two bytes further on.  Both are
 * `return table[i];` and nothing else.
 *
 * WHAT CHANGED.  The blocker was the ABS32 against 0x0209E8CA.  Its only
 * literal-pool referrer anywhere in the image is the word at 0x0201F550
 * inside this very function (layout/data_objects.txt), which every
 * second-referrer class discards as lying inside the range under test, and
 * 0x0209E8CA is interior to the datum the listings start at 0x0209E8C8, so
 * `sole-ref/data` refuses it as not-a-start.  It is now carried by
 * `sole-ref/self`: the target is in a data section and the ROM word at the
 * relocation site already names exactly the address the relocation writes
 * there, which is the whole of that sub-kind's evidence.  The sibling
 * func_0201F53C reaches EXACT by the stronger `sole-ref/data` instead,
 * because 0x0209E8C8 IS the datum start.
 *
 * Addresses are Black-image addresses.  The table's contents are a glyph
 * index map and are content data, not code shape; if it is ever sized
 * differently between Black and White that is a data-layout question, not a
 * code one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F548.c \
 *       --func func_0201F548 --addr 0x0201F548 --cc 1.1p1 --thumb
 */
u8 func_0201F548(int index)
{
    return sub_0209E8CA_Map[index];
}









/*
 * Two font-drawing wrappers, each turning a small id into a glyph-table index
 * through one of the two byte tables just before them and handing it to a
 * seven- and a six-argument SDK-style entry point.  The two table lookups are
 * func_0201F53C and func_0201F548, which are parked in
 * src/pending/sub_0201F53C.c because their tables have no outside witness;
 * the calls to them are ordinary `label` sites here, since func_0201F53C is
 * also called from 0x0201F5EA outside this range and func_0201F548 from ten
 * overlays.
 *
 * func_0201F57C hoists the lookup above the `if`, so the source binds it to a
 * local once rather than calling it in both arms; written in both arms the
 * compiler emits the call twice.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F554.c  *       --addr 0x0201F554 --thumb
 */
void func_0201F554(u32 layer, u32 tileOffset, u32 frameId, u32 heapId)
{
    func_02049624(5, func_0201F53C(frameId), layer, tileOffset, 0, 0, heapId);
}









void func_0201F57C(u32 layer, u32 palSlot, u32 frameId, u16 heapId)
{
    u32 palFileId = func_0201F548(frameId);

    if (layer < 4) {
        func_02049B40(5, palFileId, 0, palSlot * 32, 0x20, heapId);
    } else {
        func_02049B40(5, palFileId, 4, palSlot * 32, 0x20, heapId);
    }
}








/*
 * Forwards one five-argument call to two four-argument workers, dropping the
 * second argument from the first call and the third from the second.  The
 * fifth argument arrives on the caller's stack and is re-read with `ldrh`
 * through a cached frame pointer (r7 = sp + 0x18) both times, once per call,
 * which is what fixes it as u16 rather than a word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F5BC.c \
 *       --func func_0201F5BC --addr 0x0201F5BC --cc 1.1p1 --thumb
 */
void func_0201F5BC(u32 layer, u32 tileOffset, u32 palSlot, u32 frameId, u16 heapId)
{
    func_0201F554(layer, tileOffset, frameId, heapId);
    func_0201F57C(layer, palSlot, frameId, heapId);
}








/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F5DC.c \
 *       --func func_0201F5DC --addr 0x0201F5DC --cc 1.1p1 --thumb
 */
void *func_0201F5DC(u32 layer, u32 palSlot, u32 frameId, u16 heapId)
{
    void *charResult = func_020496E4(5, func_0201F53C(frameId), layer, 0, 0, heapId);

    func_0201F57C(layer, palSlot, frameId, heapId);
    return charResult;
}









void func_0201F614(int layer, u32 packedOffsets)
{
    func_0203FB44(layer, (u16)packedOffsets, (u16)(packedOffsets >> 16));
}









/*
 * A nine-slice window frame draw, the worker behind func_0201F73C
 * (src/matched/func_0201F73C.c).  Eight calls to func_02041300 place tiles
 * base+0, +1, +2, +3, +5, +6, +7, +8 around the rectangle (x, y, w, h); the
 * centre tile base+4 is never emitted, which is why the sequence skips 4.
 * The four corners are 1x1, the top and bottom edges are w x 1, the left and
 * right edges are 1 x h, and every call carries the same palette word.
 *
 * SIGNATURE, pinned by the load widths.  The fifth argument is re-read with
 * `ldrb` from its home slot at sp+0x38 and the sixth with `ldr` from sp+0x3c,
 * so `h` is a byte and `pal` a full word; the seventh is read with `ldrh`
 * from sp+0x40, so `base` is u16.  Declaring `pal` as u8 costs fourteen bytes
 * (262 instead of 276).
 *
 * THREE LEVERS, the last of which closed it:
 *
 *  - **func_02041300's second and third parameters are declared u8 here**,
 *    not u32 as src/pending/func_02041300.c declares them.  With u32 the
 *    truncation of `x - 1` becomes a source-level expression, mwccarm CSEs
 *    the whole `(u8)(x - 1)` and spills the truncated byte to a stack slot;
 *    the image keeps the untruncated `x - 1` in r7 and re-runs the
 *    `lsls #24 / lsrs #24` pair at each of its four uses, which is the
 *    argument-conversion form.  That change alone moves the residue from 228
 *    bytes to 86.  Same tell as
 *    docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md
 *    seen through the prototype rather than through the call.
 *
 *  - **`x1` and `y1` are computed between the calls that first need them**,
 *    not hoisted to the top: the image interleaves the two `adds` with the
 *    call sequence exactly where the source order puts them.
 *
 *  - **`id` is `u16`, not `u32`.**  This is what the earlier write-up in
 *    docs/notes/func_0201F628.c.txt read as a closed scheduler residue and
 *    told the next reader not to re-attempt.  It is not the scheduler: the
 *    remaining 86 bytes were three `str r5, [sp, #8]` palette stores and the
 *    top-of-function argument spill issued one slot late, and narrowing the
 *    first parameter moves all four.  The narrowing is real, not a trick --
 *    func_0201F73C hands this the result of func_02045730, which
 *    src/matched/func_0201F7A8.c (the sibling that calls func_02041300
 *    directly) already declares as a narrow byte accessor, so the caller
 *    side agrees.  With u32 the value is a fresh full-word value in mwccarm's
 *    value numbering and is created before the three stack-argument stores;
 *    with u16 it is created after them, which is the image's order.
 *    `--explain` reports the whole u32 residue as `r5 -> r0 x2` -- a single
 *    swapped pair, the declaration-level signature of this class.
 *
 *    Found by tools/permuter.py (--mode hill --budget 800 --jobs 8 --types),
 *    which reported `type:p(id:u32->u16)` at compile 249 of 800:
 *      baseline  DIFF   asm=1220  bytes-out=86  size=276/276
 *      249       EXACT  asm=0     bytes-out=0   size=276/276
 *
 * CONSEQUENCE.  0x0201F628 has exactly one caller image-wide,
 * func_0201F73C, so it could never be attested by the `label` class and no
 * cut creates a witness; now that this file is EXACT the `matched` class
 * carries that site, which is what src/matched/func_0201F73C.c was waiting
 * on.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F628.c \
 *       --func func_0201F628 --addr 0x0201F628 --cc 1.1p1 --thumb
 */
void func_0201F628(u16 bgId, u8 x, u8 y, u8 width, u8 height, u32 palette, u16 tileBase)
{
    u32 top;
    u32 left;
    u32 right;
    u32 bottom;

    top = y - 1;
    left = x - 1;
    func_02041300(bgId, tileBase,            left, top, 1, 1, palette);
    func_02041300(bgId, (u16)(tileBase + 1), x,      top, width, 1, palette);
    right = x + width;
    func_02041300(bgId, (u16)(tileBase + 2), right, top, 1, 1, palette);
    func_02041300(bgId, (u16)(tileBase + 3), left, y,      1, height, palette);
    func_02041300(bgId, (u16)(tileBase + 5), right, y,      1, height, palette);
    bottom = y + height;
    func_02041300(bgId, (u16)(tileBase + 6), left, bottom, 1, 1, palette);
    func_02041300(bgId, (u16)(tileBase + 7), x,      bottom, width, 1, palette);
    func_02041300(bgId, (u16)(tileBase + 8), right, bottom, 1, 1, palette);
}






/*
 * note:     blocked on func_0201F628 (label class): its only image-wide
 *   caller is the +0040 site inside this same function, so no witness
 *   exists outside the range under test. --suggest-split confirms no
 *   partition frees it (best partition: 0 pieces, function left out).
 */
void func_0201F73C(struct BmpWin *win, int commitMode, u16 tileBase, u32 palette)
{
    u8 bgId = func_02045730(win);
    u8 x = func_02045758(win);
    u8 y = func_02045760(win);
    u8 width = func_02045748(win);
    u8 height = func_02045750(win);

    func_0201F628(bgId, x, y, width, height, palette, tileBase);

    if (commitMode == 0) {
        func_020409B4(bgId);
    } else if (commitMode == 1) {
        func_02041B6C(bgId);
    }
}









/*
 * A width-narrowing wrapper on func_0201F73C, and the only evidence in the
 * image that func_0201F73C's third parameter is u16: the single
 * `lsls #16 / lsrs #16` pair here is the argument conversion, so the wrapper
 * takes the tile base as a full word and the worker takes it as a halfword.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F79C.c \
 *       --func func_0201F79C --addr 0x0201F79C --cc 1.1p1 --thumb
 */
void func_0201F79C(struct BmpWin *desc, u32 commitMode, u32 tileBase, u32 palette)
{
    func_0201F73C(desc, commitMode, (u16)tileBase, palette);
}









/*
 * The sibling of func_0201F73C: the same five ARM byte accessors on the same
 * descriptor, but the four geometry bytes are adjusted before the call, the
 * two extents shrunk by one and the two origins grown by two, and the worker
 * is func_02041300 with a zero second argument and a zero trailing one.
 * The four `lsls #24 / lsrs #24` pairs are the u8 truncation of each adjusted
 * value, not bitfield extraction: they are equal-amount pairs on values that
 * already left the accessors as bytes, so they only survive because the
 * arithmetic promoted to int in between.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F7A8.c \
 *       --func func_0201F7A8 --addr 0x0201F7A8 --cc 1.1p1 --thumb
 */
void func_0201F7A8(struct BmpWin *desc, u32 commitMode)
{
    u8 bgId;
    u8 x;
    u8 y;
    u8 width;
    u8 height;

    bgId = func_02045730(desc);
    x = func_02045758(desc);
    y = func_02045760(desc);
    width = func_02045748(desc);
    height = func_02045750(desc);
    func_02041300(bgId, 0, (u8)(x - 1), (u8)(y - 1), (u8)(width + 2), (u8)(height + 2), 0);
    if (commitMode == 0) {
        func_020409B4(bgId);
        return;
    }
    if (commitMode == 1) {
        func_02041B6C(bgId);
    }
}









/*
 * bmp_menuwork.c: allocate a menu item list of n cleared 8-byte entries plus
 * a terminator entry { 0xFFFFFFFF, heap } (line 0x29, __FILE__ anchor
 * 0x020A7374 "bmp_menuwork.c").  The previous reading
 * (docs/notes/pkt_0201F81C.c.txt) stored the index into both fields; the
 * loop stores ZERO (the `adds r1, r6, #0` before the loop is the zero
 * rematerialised off the index register and never updated), and with that
 * the index lands in r6 and the frame gets its own `sub sp, #4`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_Create.c \
 *       --func BMP_MENUWORK_Create --addr 0x0201F81C --thumb
 */
BmpMenuWork *BMP_MENUWORK_Create(u32 count, u32 heapId)
{
    BmpMenuWork *items;
    u32 idx;

    items = func_02030734((u16)heapId, (count + 1) * sizeof(BmpMenuWork), 1, sBmpMenuWorkFile, 0x29);
    if (items != 0) {
        for (idx = 0; idx < count; idx++) {
            items[idx].u.text = 0;
            items[idx].value = 0;
        }
        items[idx].u.raw = 0xFFFFFFFF;
        items[idx].value = heapId;
    }
    return items;
}









/*
 * Destructor pair: run the teardown at 0x0201F8F4, then release the object
 * itself through the allocator's free entry at 0x020307B0.  The pointer has
 * to survive the first call, which is what spends r4 and turns a two-call
 * leaf into a push/pop function.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_Delete.c \
 *       --func BMP_MENUWORK_Delete --addr 0x0201F868 --cc 1.1p1 --thumb
 */
u32 BMP_MENUWORK_Delete(void *items)
{
    BMP_MENUWORK_ReleaseItems(items);
    return func_020307B0(items);
}









/*
 * Claims a slot through BMP_MENUWORK_FindFreeEntry and, if one was free, fills it with the
 * handle func_02045EC0 returns and the caller's tag.  The tag word the
 * claim function writes back is never used here; it lands in the pushed r3
 * home slot at sp+0, which is exactly why the prologue pushes r3 at all.
 * A failed claim is silent.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_AddMsgItem.c  *       --func BMP_MENUWORK_AddMsgItem --addr 0x0201F878 --cc 1.1p1 --thumb
 */
void BMP_MENUWORK_AddMsgItem(BmpMenuWork *items, struct MsgBank *bank, u32 msgId, u32 param, u32 heapId)
{
    BmpMenuWork *entry;
    u32          unused;

    entry = BMP_MENUWORK_FindFreeEntry(items, &unused);
    if (entry != 0) {
        entry->u.handle = func_02045EC0(bank, msgId);
        entry->value = param;
    }
}






/*
 * Claims a slot through BMP_MENUWORK_FindFreeEntry and, if one was free, fills it with the
 * handle STRBUF_Clone returns and the caller's third argument.  Note the
 * argument roles are not the same as in the neighbouring BMP_MENUWORK_AddMsgItem: here
 * the builder takes the caller's *fourth* argument and the slot's tag word
 * comes from the third, the mirror of that function.  The tag word the
 * claim function writes back is never used here; it lands in the pushed r3
 * home slot at sp+0, which is exactly why the prologue pushes r3 at all.
 * A failed claim is silent.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_AddStrItem.c  *       --func BMP_MENUWORK_AddStrItem --addr 0x0201F898 --cc 1.1p1 --thumb
 */
void BMP_MENUWORK_AddStrItem(BmpMenuWork *items, const struct U16Vec *src, u32 param, u32 heapId)
{
    BmpMenuWork *entry;
    u32          unusedTerminator;

    entry = BMP_MENUWORK_FindFreeEntry(items, &unusedTerminator);
    if (entry != 0) {
        entry->u.handle = STRBUF_Clone(src, heapId);
        entry->value = param;
    }
}







/*
 * Claims a slot in the same eight-byte-stride table BMP_MENUWORK_ReleaseItems walks: it
 * scans for the first empty entry, gives up if the 0xFFFFFFFF terminator
 * arrives first, then runs on to the terminator record and hands its tag word
 * back through the out-parameter.  The empty slot is the return value, null on
 * a full table.
 *
 * Both loops read the word once per iteration and share the load between the
 * zero test and the terminator test, which is why this function needs no
 * union where BMP_MENUWORK_ReleaseItems does: here both tests are u32.  The terminator
 * constant is rematerialised with its own `movs`/`mvns` pair in each of the
 * two blocks that needs it rather than kept live across the first loop; see
 * docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md.
 *
 * It is a leaf, so `push {r3, r4}` / `pop {r3, r4}` + `bx lr` rather than a
 * pop into pc, and disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_FindFreeEntry.c \
 *       --func BMP_MENUWORK_FindFreeEntry --addr 0x0201F8B8 --cc 1.1p1 --thumb
 */
BmpMenuWork *BMP_MENUWORK_FindFreeEntry(BmpMenuWork *items, u32 *outTerminatorValue)
{
    BmpMenuWork *freeEntry;

    while (items->u.raw != 0) {
        if (items->u.raw == 0xFFFFFFFF)
            return 0;
        items++;
    }
    freeEntry = items;
    while (items->u.raw != 0xFFFFFFFF)
        items++;
    *outTerminatorValue = items->value;
    return freeEntry;
}






/*
 * Releases every live handle in an eight-byte-stride table and blanks its
 * slot.  The table is terminated by 0xFFFFFFFF and the walk also stops at the
 * first null slot.  0xFFFFFFFF is materialised as `movs`/`mvns`, not a pool
 * word.
 *
 * The first word is a union: the terminator test reads it as u32 and the
 * null test reads it as a pointer.  That is what keeps the second `ldr` in
 * the loop body alive, and it is the only spelling that does; with a single
 * u32 member the compiler forwards the guard's load into the body and the
 * function comes out two instructions short whether the loop is written as a
 * `while`, a `for`, or a guard plus `do`/`while`.  The call then has to take
 * the pointer member too, or the null test lands in r1 and the call argument
 * stays the stale guard value.  See
 * docs/idioms/a-sentinel-test-and-a-null-test-on-one-word-are-two-union-members.md.
 *
 * EXACT* is the extent walk running into the unlabelled leaf at 0x0201F91C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_ReleaseItems.c \
 *       --func BMP_MENUWORK_ReleaseItems --addr 0x0201F8F4 --cc 1.1p1 --thumb
 */
void BMP_MENUWORK_ReleaseItems(BmpMenuWork *items)
{
    if (items->u.raw == 0xFFFFFFFF)
        return;
    do {
        if (items->u.handle == 0)
            return;
        STRBUF_Delete(items->u.handle);
        items->u.raw = 0;
        items++;
    } while (items->u.raw != 0xFFFFFFFF);
}






/*
 * Counts the occupied entries of the same eight-byte-stride table
 * BMP_MENUWORK_FindFreeEntry claims from, stopping at the 0xFFFFFFFF terminator.  An empty
 * table returns zero without entering the loop.
 *
 * Two shape facts.  The terminator constant is `subs r1, r3, #1` off the
 * counter while it still holds zero rather than a `movs`/`mvns` pair, and it
 * is rematerialised that way twice, once per block.  And the occupancy test
 * has to read the word as a pointer while the terminator tests read it as
 * u32, or the guard's load is forwarded into the loop body and two
 * instructions disappear; see
 * docs/idioms/a-sentinel-test-and-a-null-test-on-one-word-are-two-union-members.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_CountItems.c \
 *       --func BMP_MENUWORK_CountItems --addr 0x0201F91C --cc 1.1p1 --thumb
 */
u32 BMP_MENUWORK_CountItems(BmpMenuWork *items)
{
    u32 count;

    count = 0;
    if (items->u.raw != 0xFFFFFFFF) {
        do {
            if (items->u.handle != 0)
                count++;
            items++;
        } while (items->u.raw != 0xFFFFFFFF);
    }
    return count;
}






/*
 * bmp_menu.c constructor (line 0x61, __FILE__ 0x020A7384 "bmp_menu.c"):
 * allocate the 0x38-byte menu, copy the 0x24-byte header in, create the
 * cursor, record cancelMask mask, start position, widest item (BMP_MENU_GetMaxItemWidth),
 * heap id and the pixel origin, then draw (BMP_MENU_DrawItems) and place the
 * cursor (BMP_MENU_DrawCursor).
 *
 * The residue in docs/notes/BMP_MENU_Create.c.txt (the stack-passed u16 heap
 * cached once in a callee-saved register instead of reloaded, 92 bytes out)
 * depended on the conversion at the allocation call: the allocator's heap
 * parameter is `u32`, and the explicit `(u32)(int)heap` keeps that site's
 * signed conversion distinct from the other uses. Without it, the u16 value
 * is zero-extended once and CSE'd into all four uses. With the conversion,
 * the first `ldrh` feeds r0 directly, the header pointer's register is
 * reused for the second load, and the frame shrinks to the original's
 * push {r3-r7,lr} / sub sp,#8.  Found by tools/permuter.py hill (a
 * `(int)heap` cast at that one site), then retained explicitly at the call
 * while preserving the allocator's unsigned-word parameter.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_Create.c \
 *       --func BMP_MENU_Create --addr 0x0201F93C --thumb
 */
BmpMenu *BMP_MENU_Create(const BmpMenuHeader *header, u8 originX, u8 originY, u8 startPos, u16 heapId, u32 cancelMask)
{
    BmpMenu *menu = func_02030734((u32)(int)heapId, sizeof(BmpMenu), 1, sBmpMenuFile, 0x61);

    menu->header = *header;
    menu->cursor = BMP_CURSOR_Create(heapId);
    menu->cancelMask = cancelMask;
    menu->selected = startPos;
    menu->colWidth = BMP_MENU_GetMaxItemWidth(menu);
    menu->heapId = heapId;
    menu->originX = originX;
    menu->originY = originY;
    BMP_CURSOR_SetTileBitmap(menu->cursor, (u32)heapId);
    menu->xPad = menu->header.xPad;
    menu->lineHeight = menu->header.lineHeight;
    BMP_MENU_DrawItems(menu);
    BMP_MENU_DrawCursor(menu);
    return menu;
}





/*
 * A pass-through onto BMP_MENU_Create: the four register arguments are never
 * touched and only the two stacked ones are copied down into the new frame.
 * The fifth is a halfword and needs `add r4, sp, #0x10` + `ldrh` because
 * Thumb has no halfword load with an sp base; the sixth is a word and loads
 * directly.
 *
 * Blocked on the `label` class: 0x0201F93C has no branch reference anywhere
 * in the image except the one in this function, and the range cannot be cut
 * smaller than the single function, so no witness exists.  0x0201F93C is a
 * 148-byte constructor (debug allocator at 0x02030734, 0x38 bytes, line 97,
 * a nine-word ldm/stm copy of the caller's descriptor, then BMP_MENU_GetMaxItemWidth)
 * and was not attempted in wave 20B for budget reasons, not for difficulty.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_Add.c \
 *       --func BMP_MENU_Add --addr 0x0201F9D0 --cc 1.1p1 --thumb
 */
BmpMenu *BMP_MENU_Add(const BmpMenuHeader *header, u8 originX, u8 originY, u8 startPos, u16 heapId, u32 cancelMask)
{
    return BMP_MENU_Create(header, originX, originY, startPos, heapId, cancelMask);
}






void BMP_MENU_Delete(BmpMenu *menu, u8 *outSelected)
{
    if (outSelected != 0) {
        *outSelected = menu->selected;
    }
    BMP_CURSOR_Delete(menu->cursor);
    func_020307B0(menu);
}





/*
 * The menu's per-frame input step.  Field +0x33 is cleared first and holds
 * the direction that was accepted this frame (1..4).  A is a confirm: it
 * plays 0x54C and answers the selected entry's second word.  Any bit in the
 * caller-supplied cancelMask mask at +0x28 plays 0x551 and answers -2.  The four
 * direction bits each ask BMP_MENU_MoveCursor to move the cursor with its own
 * sound id; a successful move records the direction at +0x33.  Every
 * direction path answers -1, and a frame with nothing pressed answers -1 as
 * well, spelled off the last mask constant so it costs no extra byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_ProcessInput.c \
 *       --func BMP_MENU_ProcessInput --addr 0x0201FA04 --cc 1.1p1 --thumb
 */
u32 BMP_MENU_ProcessInput(BmpMenu *menu)
{
    u32 pressed = func_020362DC();

    menu->movedDir = 0;

    if (pressed & 1) {
        func_020061E4(0x54C);
        return menu->header.items[menu->selected].value;
    }
    if (pressed & menu->cancelMask) {
        func_020061E4(0x551);
        return -2;
    }
    if (pressed & 0x40) {
        if (BMP_MENU_MoveCursor(menu, 0, 0x548) == 1) {
            menu->movedDir = 1;
        }
        return -1;
    }
    if (pressed & 0x80) {
        if (BMP_MENU_MoveCursor(menu, 1, 0x548) == 1) {
            menu->movedDir = 2;
        }
        return -1;
    }
    if (pressed & 0x20) {
        if (BMP_MENU_MoveCursor(menu, 2, 0x548) == 1) {
            menu->movedDir = 3;
        }
        return -1;
    }
    if (pressed & 0x10) {
        if (BMP_MENU_MoveCursor(menu, 3, 0x548) == 1) {
            menu->movedDir = 4;
        }
        return -1;
    }
    return -1;
}



/*
 * Commit a cursor move: remember where the cursor was, ask BMP_MENU_StepSelection to
 * step it, and on a refusal answer 0 without side effects.  On a move, redraw
 * from the old cell through BMP_MENU_GetItemPixelPos into an on-stack pair, repaint at
 * the new position with BMP_FillRect and play the sound id the caller passed
 * in r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_MoveCursor.c \
 *       --func BMP_MENU_MoveCursor --addr 0x0201FAD0 --cc 1.1p1 --thumb
 */
int BMP_MENU_MoveCursor(BmpMenu *menu, u32 dir, u32 sfxId)
{
    u8 cellXY[2];
    u8 oldSelected;

    oldSelected = menu->selected;
    if (BMP_MENU_StepSelection(menu, dir) == 0) {
        return 0;
    }

    BMP_MENU_GetItemPixelPos(menu, &cellXY[1], &cellXY[0], oldSelected);
    BMP_FillRect(func_02045770(menu->header.win), cellXY[1], cellXY[0], menu->xPad,
                  menu->lineHeight, 0xff);
    BMP_MENU_DrawCursor(menu);
    func_020061E4(sfxId);
    return 1;
}




/*
 * Grid cursor step.  The menu is cols x rows (unk0A wide, unk09 tall) with a
 * one-byte cursor at +0x2d; unk0B bits 2..3 are the wrap flag.  Each of the
 * four directions computes the candidate cell, wraps only when the flag is
 * set, and commits the move only when the entry's second word is not -3.
 * The row/column split needs the real quotient AND remainder, so it reads as
 * one _s32_div_f call per direction, not a division and a modulo.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_StepSelection.c \
 *       --func BMP_MENU_StepSelection --addr 0x0201FB30 --cc 1.1p1 --thumb
 */
int BMP_MENU_StepSelection(BmpMenu *menu, u32 dir)
{
    s8 nextPos;
    u8 perColumn;
    u8 curPos;

    if (dir == 0) {
        perColumn = menu->header.itemsPerColumn;
        if (perColumn <= 1) {
            return 0;
        }
        curPos = menu->selected;
        if (curPos % perColumn == 0) {
            if (menu->header.wrap == 0) {
                return 0;
            }
            nextPos = (s8)(curPos + (perColumn - 1));
        } else {
            nextPos = (s8)(curPos - 1);
        }
    } else if (dir == 1) {
        perColumn = menu->header.itemsPerColumn;
        if (perColumn <= 1) {
            return 0;
        }
        curPos = menu->selected;
        if (curPos % perColumn == perColumn - 1) {
            if (menu->header.wrap == 0) {
                return 0;
            }
            nextPos = (s8)(curPos - (perColumn - 1));
        } else {
            nextPos = (s8)(curPos + 1);
        }
    } else if (dir == 2) {
        u8 numColumns = menu->header.numColumns;

        if (numColumns <= 1) {
            return 0;
        }
        perColumn = menu->header.itemsPerColumn;
        curPos = menu->selected;
        if (curPos < perColumn) {
            if (menu->header.wrap == 0) {
                return 0;
            }
            nextPos = (s8)(curPos + perColumn * (numColumns - 1));
        } else {
            nextPos = (s8)(curPos - perColumn);
        }
    } else {
        u8 numColumns = menu->header.numColumns;

        if (numColumns <= 1) {
            return 0;
        }
        curPos = menu->selected;
        perColumn = menu->header.itemsPerColumn;
        if (curPos >= perColumn * (numColumns - 1)) {
            if (menu->header.wrap == 0) {
                return 0;
            }
            nextPos = (s8)(curPos % perColumn);
        } else {
            nextPos = (s8)(curPos + perColumn);
        }
    }

    if (menu->header.items[nextPos].value == -3) {
        return 0;
    }
    menu->selected = (u8)nextPos;
    return 1;
}



u32 BMP_MENU_GetMaxItemWidth(BmpMenu *menu)
{
    u32 maxWidth = 0;
    u8 idx;

    for (idx = 0; idx < menu->header.numColumns * menu->header.itemsPerColumn; idx++) {
        u32 width = (u8)func_0201D304(menu->header.items[idx].u.text, menu->header.fontH, 0);

        if (maxWidth < width) {
            maxWidth = width;
        }
    }
    return maxWidth;
}




static inline void PrintUtil_Print(PrintUtil *util, void *que, s32 x, s32 y, const void *str, struct GfFont *font)
{
    func_0201C6FC(que, func_02045770(util->win), x, y, str, font);
    util->printed = 1;
}




/*
 * bmp_menu.c: the three drawing helpers the constructor BMP_MENU_Create calls.
 *   BMP_MENU_DrawItems  clear the window bitmap to 0xFF and print every item of
 *                  the numColumns * itemsPerColumn grid (column-major index j + i * itemsPerColumn)
 *                  through the print-util inline (the BMP_CURSOR_Draw shape:
 *                  print via func_0201C6FC, then util->printed = 1).
 *   BMP_MENU_DrawCursor  unless the cursor-display bitfield (+0x0B bits 4..5) is 1,
 *                  place the cursor at the pixel position of the current item.
 *   BMP_MENU_GetItemPixelPos  item index -> pixel position: column = pos / itemsPerColumn, row =
 *                  pos % itemsPerColumn.
 *
 * Declaration facts that closed them (all three had DIFF notes,
 * docs/notes/pkt_0201FC5C.c.txt and lane2_func_0201FD54.c.txt):
 *  - 0x0209C0A4 is _s32_div_f (layout/runtime_arm9.txt), which returns the
 *    quotient in r0 and the remainder in r1: the "unexplained" r1 of the
 *    second call in BMP_MENU_GetItemPixelPos is `pos % itemsPerColumn`, not a register tie
 *    (docs/idioms/div-and-mod-are-two-calls.md).
 *  - header byte +0x0B is three UNSIGNED bitfields 4:2:2 (BMP_MENU_CreateYesNo
 *    writes them with 0x0F / 0x30 / 0xC0 masks); an unsigned field gives the
 *    `lsrs` BMP_MENU_DrawCursor needs where a shift expression gave `asrs`.
 *  - the print call is an inline taking the util handle first, which is what
 *    keeps the handle in a spill slot across the call in BMP_MENU_DrawItems.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201FC5C.c \
 *       --addr 0x0201FC5C --thumb
 */
void BMP_MENU_DrawItems(BmpMenu *menu)
{
    u8 col, row;
    u8 x, colStep;

    BMP_Clear(func_02045770(menu->header.win), 0xFF);
    x = menu->originX;
    colStep = menu->colWidth + menu->xPad * 2;
    for (col = 0; col < menu->header.numColumns; col++) {
        for (row = 0; row < menu->header.itemsPerColumn; row++) {
            PrintUtil_Print(menu->header.util, menu->header.que, x,
                            (u8)(menu->originY + row * (menu->lineHeight + menu->header.lineSpacing)),
                            menu->header.items[row + col * menu->header.itemsPerColumn].u.text, menu->header.fontH);
        }
        x += colStep;
    }
}




void BMP_MENU_DrawCursor(BmpMenu *menu)
{
    u8 x, y;

    if (menu->header.cursorMode != 1) {
        BMP_MENU_GetItemPixelPos(menu, &x, &y, menu->selected);
        BMP_CURSOR_Draw(menu->cursor, x, y, menu->header.util, menu->header.que, menu->header.fontH);
    }
}




void BMP_MENU_GetItemPixelPos(BmpMenu *menu, u8 *outX, u8 *outY, u8 itemPos)
{
    *outX = (itemPos / menu->header.itemsPerColumn) * (menu->colWidth + menu->xPad * 2);
    *outY = menu->originY + (itemPos % menu->header.itemsPerColumn) * (menu->lineHeight + menu->header.lineSpacing);
}




static inline void PrintUtil_Init(PrintUtil *util, void *cell)
{
    util->win = cell;
    util->printed = 0;
}




/*
 * bmp_menu.c: the yes/no menu builder (message archive 2 entry 0xE9, a
 * two-item BmpMenuWork list, a BmpMenuHeader filled on the stack, then
 * BMP_MENU_Add and the window upload).  docs/notes/pkt_0201FC5C.c.txt.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 284/284, 2 bytes out for
 * five waves: the r3 home store `str r3, [sp, #0x14]` scheduled after
 * `ldr r4, [sp, #0x50]` / `adds r5, r0, #0`): the fifth (stack) parameter
 * is a heap id and is u16, with u16 on the heap parameter of every callee
 * it is passed to.  docs/idioms/a-u16-stack-parameter-passed-to-a-u16-
 * callee-stays-behind-a-spill-store.md is the same lever; with u16 heap
 * and the old u32 prototypes the body narrows at every call.
 */
BmpMenu *BMP_MENU_CreateYesNo(const WinDat *winData, u16 tileBase, u8 palette, u8 startPos, u16 heapId)
{
    BmpMenuHeader header;
    struct MsgBank *yesNoText;
    BmpMenuWork *items;
    BmpMenu *menu;

    yesNoText = func_02045B38(0, 2, 0xE9, heapId);
    items = BMP_MENUWORK_Create(2, (int)(u16)heapId);
    BMP_MENUWORK_AddMsgItem(items, yesNoText, 0, 0, heapId);
    BMP_MENUWORK_AddMsgItem(items, yesNoText, 1, -2, heapId);
    MSGDATA_Delete(yesNoText);

    MI_CpuFill8(&header, 0, sizeof(header));
    header.items = items;
    header.win = BMP_WIN_Create(winData->bgFrame, winData->x, winData->y, 7, 4, winData->palette, 1);
    header.numColumns = 1;
    header.itemsPerColumn = 2;
    header.lineSpacing = 1;
    header.cursorMode = 0;
    header.wrap = 0;
    header.util = func_02030734(heapId, sizeof(PrintUtil), 1, sBmpMenuFile, 0x263);
    header.fontH = GF_FONT_Create(0x17, 0, 0, 0, heapId);
    header.lineHeight = func_0201DC80(header.fontH);
    header.xPad = 10;
    PrintUtil_Init(header.util, header.win);
    header.que = func_0201C440((void *)heapId);
    header.committed = 0;

    menu = BMP_MENU_Add(&header, 0xE, 0, startPos, heapId, 2);
    BMP_WIN_MakeScreen(header.win);
    func_0201F73C(header.win, 0, tileBase, palette);
    func_020409B4(func_02045730(header.win));
    BMP_WIN_TransferChars(header.win);
    return menu;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/pending/BMP_MENU_ProcessYesNo.c \
 *       --func BMP_MENU_ProcessYesNo --addr 0x0201FEBC --cc 1.1p1 --thumb
 */
u32 BMP_MENU_ProcessYesNo(BmpMenu *menu)
{
    u32 result = BMP_MENU_ProcessInput(menu);
    u32 printDone = PRINTSYS_QUE_Main(menu->header.que);

    if (menu->header.committed == 0 && printDone != 0) {
        BMP_WIN_TransferChars(menu->header.win);
        menu->header.committed = 1;
    }
    if (result != 0xffffffff) {
        BMP_MENU_DeleteYesNo(menu);
    }
    return result;
}




void BMP_MENU_DeleteYesNo(BmpMenu *menu)
{
    func_0201C6EC(menu->header.que);
    func_0201C4C0(menu->header.que);
    func_020307B0(menu->header.util);
    func_0201F7A8(menu->header.win, 0);
    GF_FONT_Delete(menu->header.fontH);
    BMP_MENUWORK_Delete(menu->header.items);
    func_020452E8(menu->header.win);
    BMP_MENU_Delete(menu, 0);
}
