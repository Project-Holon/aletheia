/*
 * file:     bmp_menu.c
 * unit:     yes
 * function: func_0201F53C, func_0201F548, func_0201F554, func_0201F57C, func_0201F5BC, func_0201F5DC, func_0201F614, func_0201F628, func_0201F73C, func_0201F79C, func_0201F7A8, func_0201F81C, func_0201F868, func_0201F878, func_0201F898, func_0201F8B8, func_0201F8F4, func_0201F91C, func_0201F93C, func_0201F9D0, func_0201F9E8, func_0201FA04, func_0201FAD0, func_0201FB30, func_0201FC1C, func_0201FC5C, func_0201FD18, func_0201FD54, func_0201FDA0, func_0201FEBC, func_0201FEF4
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
 *   func_02045874  0x02045874  arm
 *   func_02045808  0x02045808  arm
 *   sBmpMenuFile    0x020A7384  data
 *   func_02020D18   0x02020D18  thumb
 *   func_02020DC8   0x02020DC8  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02043B5C   0x02043B5C  arm
 *   func_0201C6FC   0x0201C6FC  thumb
 *   func_02020D5C   0x02020D5C  thumb
 *   func_02045B38   0x02045B38  arm
 *   func_02045C04   0x02045C04  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   func_020450F0   0x020450F0  arm
 *   func_0201D7EC   0x0201D7EC  thumb
 *   func_0201DC80   0x0201DC80  thumb
 *   func_0201C440   0x0201C440  thumb
 *   func_02045374   0x02045374  arm
 *   func_02045334   0x02045334  arm
 */
struct Descriptor;
struct Slot;
struct MsgBank;
struct U16Vec;
struct Obj;
struct D;
struct Bmp;
struct StrObj;
struct CharBuf;
struct Desc;
struct Handle;
struct PrintSys;
struct Cfg;
struct Font;
struct GfFont;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short s16;

typedef signed char s8;

typedef struct {
    const void *str;    /* +0x00 */
    u32         param;  /* +0x04 */
} BmpMenuWork;

struct Slot {
    union {
        u32   raw;
        void *ptr;
    } u;
    u32 tag;
};

typedef struct {
    void *cell;         /* +0x00 */
    u8    drawn;        /* +0x04 */
} PrintUtil;

typedef struct {
    BmpMenuWork *items; /* +0x00 */
    void *win;          /* +0x04 */
    u8   font;          /* +0x08 */
    u8   xmax;          /* +0x09  columns */
    u8   ymax;          /* +0x0A  rows    */
    u8   lineSpc : 4;   /* +0x0B */
    u8   cDisp   : 2;
    u8   bf0b6   : 2;
    u16  unk0c;         /* +0x0C */
    u16  unk0e;         /* +0x0E */
    u32  unk10;         /* +0x10 */
    PrintUtil *util;    /* +0x14 */
    void *que;          /* +0x18 */
    void *fontH;        /* +0x1C */
    u32  unk20;         /* +0x20 */
} BmpMenuHeader;

typedef struct {
    BmpMenuHeader hdr;  /* +0x00 */
    void *cursor;       /* +0x24 */
    u32 cancel;         /* +0x28 */
    u8  pad2c;
    u8  pos;            /* +0x2D */
    u8  width;          /* +0x2E */
    u8  px;             /* +0x2F */
    u8  py;             /* +0x30 */
    u8  xspc;           /* +0x31 */
    u8  yspc;           /* +0x32 */
    u8  lastDir;        /* +0x33 */
    u16 heap;           /* +0x34 */
    u16 pad36;
} BmpMenu;

typedef int            s32;

typedef struct {
    u8  frame;   /* +0 */
    u8  x;       /* +1 */
    u8  y;       /* +2 */
    u8  pal;     /* +3 */
    u16 chr;     /* +4  callers pass it as base */
} WinDat;

extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void *func_020496E4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5,
                          u32 a6);
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02020D18(u32 heap);
extern void func_02020DC8(char *p, int a);
extern void func_02020D3C(struct D *p);
extern u32  func_020362DC(void);
extern void func_020061E4(u32 id);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern s32 _s32_div_f(s32 num, s32 den);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02020D5C(struct Desc *d, u32 x, u32 y, struct Handle *h, void *dst, u32 f);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201DC80(struct Font *p);
extern u32 func_0201C440(void *p);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_020452E8(struct Descriptor *d);
u8 func_0201F53C(int i);
u8 func_0201F548(int i);
void func_0201F554(u32 a, u32 b, u32 c, u32 d);
void func_0201F57C(u32 a, u32 b, u32 c, u16 d);
void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
void *func_0201F5DC(void *a0, u32 a1, u32 a2, u16 a3);
void func_0201F614(int a, u32 x);
void func_0201F628(u16 id, u8 x, u8 y, u8 w, u8 h, u32 pal, u16 base);
void func_0201F73C(struct Descriptor *a0, int a1, u16 a2, u32 a3);
void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal);
void func_0201F7A8(void *desc, u32 kind);
BmpMenuWork *func_0201F81C(u32 n, u32 heap);
u32 func_0201F868(void *p);
void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
struct Slot *func_0201F8B8(struct Slot *s, u32 *tag_out);
void func_0201F8F4(struct Slot *s);
u32 func_0201F91C(struct Slot *s);
BmpMenu *func_0201F93C(const BmpMenuHeader *hdr, u8 px, u8 py, u8 pos, u16 heap, u32 cancel);
BmpMenu *func_0201F9D0(const BmpMenuHeader *hdr, u8 px, u8 py, u8 pos, u16 heap, u32 cancel);
void func_0201F9E8(BmpMenu *o, u8 *out);
u32 func_0201FA04(BmpMenu *o);
int func_0201FAD0(BmpMenu *o, u32 dir, u32 sound);
int func_0201FB30(BmpMenu *o, u32 dir);
u32 func_0201FC1C(BmpMenu *o);
void func_0201FC5C(BmpMenu *m);
void func_0201FD18(BmpMenu *m);
void func_0201FD54(BmpMenu *m, u8 *x, u8 *y, u8 pos);
BmpMenu *func_0201FDA0(const WinDat *winDat, u16 base, u8 pal, u8 pos, u16 heap);
u32 func_0201FEBC(BmpMenu *p);
void func_0201FEF4(BmpMenu *o);
extern u8 sub_0209E8C8_Map[];
extern u8 sub_0209E8CA_Map[];
extern char sBmpMenuWorkFile[];
extern char sBmpMenuFile[];









u8 func_0201F53C(int i)
{
    return sub_0209E8C8_Map[i];
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
u8 func_0201F548(int i)
{
    return sub_0209E8CA_Map[i];
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
void func_0201F554(u32 a, u32 b, u32 c, u32 d)
{
    func_02049624(5, func_0201F53C(c), a, b, 0, 0, d);
}









void func_0201F57C(u32 a, u32 b, u32 c, u16 d)
{
    u32 t = func_0201F548(c);

    if (a < 4) {
        func_02049B40(5, t, 0, b * 32, 0x20, d);
    } else {
        func_02049B40(5, t, 4, b * 32, 0x20, d);
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
void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_0201F554(a, b, d, e);
    func_0201F57C(a, c, d, e);
}








/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F5DC.c \
 *       --func func_0201F5DC --addr 0x0201F5DC --cc 1.1p1 --thumb
 */
void *func_0201F5DC(void *a0, u32 a1, u32 a2, u16 a3)
{
    void *r = func_020496E4(5, func_0201F53C(a2), (u32)a0, 0, 0, a3);

    func_0201F57C((u32)a0, a1, a2, a3);
    return r;
}









void func_0201F614(int a, u32 x)
{
    func_0203FB44((int)a, (u16)x, (u16)(x >> 16));
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
void func_0201F628(u16 id, u8 x, u8 y, u8 w, u8 h, u32 pal, u16 base)
{
    u32 y0;
    u32 x0;
    u32 x1;
    u32 y1;

    y0 = y - 1;
    x0 = x - 1;
    func_02041300(id, base,            x0, y0, 1, 1, pal);
    func_02041300(id, (u16)(base + 1), x,      y0, w, 1, pal);
    x1 = x + w;
    func_02041300(id, (u16)(base + 2), x1, y0, 1, 1, pal);
    func_02041300(id, (u16)(base + 3), x0, y,      1, h, pal);
    func_02041300(id, (u16)(base + 5), x1, y,      1, h, pal);
    y1 = y + h;
    func_02041300(id, (u16)(base + 6), x0, y1, 1, 1, pal);
    func_02041300(id, (u16)(base + 7), x,      y1, w, 1, pal);
    func_02041300(id, (u16)(base + 8), x1, y1, 1, 1, pal);
}






/*
 * note:     blocked on func_0201F628 (label class): its only image-wide
 *   caller is the +0040 site inside this same function, so no witness
 *   exists outside the range under test. --suggest-split confirms no
 *   partition frees it (best partition: 0 pieces, function left out).
 */
void func_0201F73C(struct Descriptor *a0, int a1, u16 a2, u32 a3)
{
    u8 ctx = func_02045730(a0);
    u8 v10 = func_02045758(a0);
    u8 v14 = func_02045760(a0);
    u8 v18 = func_02045748(a0);
    u8 v0  = func_02045750(a0);

    func_0201F628(ctx, v10, v14, v18, v0, a3, a2);

    if (a1 == 0) {
        func_020409B4(ctx);
    } else if (a1 == 1) {
        func_02041B6C(ctx);
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
void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal)
{
    func_0201F73C(desc, kind, (u16)base, pal);
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
void func_0201F7A8(void *desc, u32 kind)
{
    u8 id;
    u8 a;
    u8 b;
    u8 c;
    u8 d;

    id = func_02045730(desc);
    a = func_02045758(desc);
    b = func_02045760(desc);
    c = func_02045748(desc);
    d = func_02045750(desc);
    func_02041300(id, 0, (u8)(a - 1), (u8)(b - 1), (u8)(c + 2), (u8)(d + 2), 0);
    if (kind == 0) {
        func_020409B4(id);
        return;
    }
    if (kind == 1) {
        func_02041B6C(id);
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
 *   python tools/match.py one --src src/matched/func_0201F81C.c \
 *       --func func_0201F81C --addr 0x0201F81C --thumb
 */
BmpMenuWork *func_0201F81C(u32 n, u32 heap)
{
    BmpMenuWork *p;
    u32 i;

    p = func_02030734((u16)heap, (n + 1) * sizeof(BmpMenuWork), 1, sBmpMenuWorkFile, 0x29);
    if (p != 0) {
        for (i = 0; i < n; i++) {
            p[i].str = 0;
            p[i].param = 0;
        }
        p[i].str = (const void *)0xFFFFFFFF;
        p[i].param = heap;
    }
    return p;
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
 *   python tools/match.py one --src src/matched/func_0201F868.c \
 *       --func func_0201F868 --addr 0x0201F868 --cc 1.1p1 --thumb
 */
u32 func_0201F868(void *p)
{
    func_0201F8F4(p);
    return func_020307B0(p);
}









/*
 * Claims a slot through func_0201F8B8 and, if one was free, fills it with the
 * handle func_02045EC0 returns and the caller's tag.  The tag word the
 * claim function writes back is never used here; it lands in the pushed r3
 * home slot at sp+0, which is exactly why the prologue pushes r3 at all.
 * A failed claim is silent.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F878.c  *       --func func_0201F878 --addr 0x0201F878 --cc 1.1p1 --thumb
 */
void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap)
{
    struct Slot *slot;
    u32          unused;

    slot = func_0201F8B8(table, &unused);
    if (slot != 0) {
        slot->u.ptr = func_02045EC0((struct MsgBank *)a, b);
        slot->tag = tag;
    }
}






/*
 * Claims a slot through func_0201F8B8 and, if one was free, fills it with the
 * handle func_02045874 returns and the caller's third argument.  Note the
 * argument roles are not the same as in the neighbouring func_0201F878: here
 * the builder takes the caller's *fourth* argument and the slot's tag word
 * comes from the third, the mirror of that function.  The tag word the
 * claim function writes back is never used here; it lands in the pushed r3
 * home slot at sp+0, which is exactly why the prologue pushes r3 at all.
 * A failed claim is silent.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F898.c  *       --func func_0201F898 --addr 0x0201F898 --cc 1.1p1 --thumb
 */
void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag)
{
    struct Slot *slot;
    u32          unused;

    slot = func_0201F8B8(table, &unused);
    if (slot != 0) {
        slot->u.ptr = func_02045874((struct U16Vec *)a, tag);
        slot->tag = b;
    }
}







/*
 * Claims a slot in the same eight-byte-stride table func_0201F8F4 walks: it
 * scans for the first empty entry, gives up if the 0xFFFFFFFF terminator
 * arrives first, then runs on to the terminator record and hands its tag word
 * back through the out-parameter.  The empty slot is the return value, null on
 * a full table.
 *
 * Both loops read the word once per iteration and share the load between the
 * zero test and the terminator test, which is why this function needs no
 * union where func_0201F8F4 does: here both tests are u32.  The terminator
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
 *   python tools/match.py one --src src/matched/func_0201F8B8.c \
 *       --func func_0201F8B8 --addr 0x0201F8B8 --cc 1.1p1 --thumb
 */
struct Slot *func_0201F8B8(struct Slot *s, u32 *tag_out)
{
    struct Slot *free_slot;

    while (s->u.raw != 0) {
        if (s->u.raw == 0xFFFFFFFF)
            return 0;
        s++;
    }
    free_slot = s;
    while (s->u.raw != 0xFFFFFFFF)
        s++;
    *tag_out = s->tag;
    return free_slot;
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
 *   python tools/match.py one --src src/matched/func_0201F8F4.c \
 *       --func func_0201F8F4 --addr 0x0201F8F4 --cc 1.1p1 --thumb
 */
void func_0201F8F4(struct Slot *s)
{
    if (s->u.raw == 0xFFFFFFFF)
        return;
    do {
        if (s->u.ptr == 0)
            return;
        func_02045808(s->u.ptr);
        s->u.raw = 0;
        s++;
    } while (s->u.raw != 0xFFFFFFFF);
}






/*
 * Counts the occupied entries of the same eight-byte-stride table
 * func_0201F8B8 claims from, stopping at the 0xFFFFFFFF terminator.  An empty
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
 *   python tools/match.py one --src src/matched/func_0201F91C.c \
 *       --func func_0201F91C --addr 0x0201F91C --cc 1.1p1 --thumb
 */
u32 func_0201F91C(struct Slot *s)
{
    u32 n;

    n = 0;
    if (s->u.raw != 0xFFFFFFFF) {
        do {
            if (s->u.ptr != 0)
                n++;
            s++;
        } while (s->u.raw != 0xFFFFFFFF);
    }
    return n;
}






/*
 * bmp_menu.c constructor (line 0x61, __FILE__ 0x020A7384 "bmp_menu.c"):
 * allocate the 0x38-byte menu, copy the 0x24-byte header in, create the
 * cursor, record cancel mask, start position, widest item (func_0201FC1C),
 * heap id and the pixel origin, then draw (func_0201FC5C) and place the
 * cursor (func_0201FD18).
 *
 * The residue in docs/notes/func_0201F93C.c.txt (the stack-passed u16 heap
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
 *   python tools/match.py one --src src/matched/func_0201F93C.c \
 *       --func func_0201F93C --addr 0x0201F93C --thumb
 */
BmpMenu *func_0201F93C(const BmpMenuHeader *hdr, u8 px, u8 py, u8 pos, u16 heap, u32 cancel)
{
    BmpMenu *m = func_02030734((u32)(int)heap, sizeof(BmpMenu), 1, sBmpMenuFile, 0x61);

    m->hdr = *hdr;
    m->cursor = func_02020D18(heap);
    m->cancel = cancel;
    m->pos = pos;
    m->width = func_0201FC1C(m);
    m->heap = heap;
    m->px = px;
    m->py = py;
    func_02020DC8(m->cursor, (u32)heap);
    m->xspc = m->hdr.unk0c;
    m->yspc = m->hdr.unk0e;
    func_0201FC5C(m);
    func_0201FD18(m);
    return m;
}





/*
 * A pass-through onto func_0201F93C: the four register arguments are never
 * touched and only the two stacked ones are copied down into the new frame.
 * The fifth is a halfword and needs `add r4, sp, #0x10` + `ldrh` because
 * Thumb has no halfword load with an sp base; the sixth is a word and loads
 * directly.
 *
 * Blocked on the `label` class: 0x0201F93C has no branch reference anywhere
 * in the image except the one in this function, and the range cannot be cut
 * smaller than the single function, so no witness exists.  0x0201F93C is a
 * 148-byte constructor (debug allocator at 0x02030734, 0x38 bytes, line 97,
 * a nine-word ldm/stm copy of the caller's descriptor, then func_0201FC1C)
 * and was not attempted in wave 20B for budget reasons, not for difficulty.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F9D0.c \
 *       --func func_0201F9D0 --addr 0x0201F9D0 --cc 1.1p1 --thumb
 */
BmpMenu *func_0201F9D0(const BmpMenuHeader *hdr, u8 px, u8 py, u8 pos, u16 heap, u32 cancel)
{
    return func_0201F93C(hdr, px, py, pos, heap, cancel);
}






void func_0201F9E8(BmpMenu *o, u8 *out)
{
    if (out != 0) {
        *out = o->pos;
    }
    func_02020D3C((struct D *)o->cursor);
    func_020307B0(o);
}





/*
 * The menu's per-frame input step.  Field +0x33 is cleared first and holds
 * the direction that was accepted this frame (1..4).  A is a confirm: it
 * plays 0x54C and answers the selected entry's second word.  Any bit in the
 * caller-supplied cancel mask at +0x28 plays 0x551 and answers -2.  The four
 * direction bits each ask func_0201FAD0 to move the cursor with its own
 * sound id; a successful move records the direction at +0x33.  Every
 * direction path answers -1, and a frame with nothing pressed answers -1 as
 * well, spelled off the last mask constant so it costs no extra byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201FA04.c \
 *       --func func_0201FA04 --addr 0x0201FA04 --cc 1.1p1 --thumb
 */
u32 func_0201FA04(BmpMenu *o)
{
    u32 keys = func_020362DC();
    u32 one = 1;

    o->lastDir = 0;

    if (keys & one) {
        func_020061E4(0x54C);
        return o->hdr.items[o->pos].param;
    }
    if (keys & o->cancel) {
        func_020061E4(0x551);
        return one - 3;
    }
    if (keys & 0x40) {
        if (func_0201FAD0(o, 0, 0x548) == 1) {
            o->lastDir = (u8)one;
        }
        return -1;
    }
    if (keys & 0x80) {
        if (func_0201FAD0(o, one, 0x548) == 1) {
            o->lastDir = 2;
        }
        return -1;
    }
    if (keys & 0x20) {
        if (func_0201FAD0(o, 2, 0x548) == 1) {
            o->lastDir = 3;
        }
        return -1;
    }
    if (keys & 0x10) {
        if (func_0201FAD0(o, 3, 0x548) == 1) {
            o->lastDir = 4;
        }
        return -1;
    }
    return 0x10 - 0x11;
}



/*
 * Commit a cursor move: remember where the cursor was, ask func_0201FB30 to
 * step it, and on a refusal answer 0 without side effects.  On a move, redraw
 * from the old cell through func_0201FD54 into an on-stack pair, repaint at
 * the new position with func_02043AF4 and play the sound id the caller passed
 * in r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201FAD0.c \
 *       --func func_0201FAD0 --addr 0x0201FAD0 --cc 1.1p1 --thumb
 */
int func_0201FAD0(BmpMenu *o, u32 dir, u32 sound)
{
    u8 cell[2];
    u8 old;

    old = o->pos;
    if (func_0201FB30(o, dir) == 0) {
        return 0;
    }

    func_0201FD54(o, &cell[1], &cell[0], old);
    func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)o->hdr.win)), cell[1], cell[0], o->xspc,
                  o->yspc, 0xff);
    func_0201FD18(o);
    func_020061E4(sound);
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
 *   python tools/match.py one --src src/matched/func_0201FB30.c \
 *       --func func_0201FB30 --addr 0x0201FB30 --cc 1.1p1 --thumb
 */
int func_0201FB30(BmpMenu *o, u32 dir)
{
    s8 next;
    u8 cols;
    u8 cur;

    if (dir == 0) {
        cols = o->hdr.ymax;
        if (cols <= 1) {
            return 0;
        }
        cur = o->pos;
        if (cur % cols == 0) {
            if (o->hdr.bf0b6 == 0) {
                return 0;
            }
            next = (s8)(cur + (cols - 1));
        } else {
            next = (s8)(cur - 1);
        }
    } else if (dir == 1) {
        cols = o->hdr.ymax;
        if (cols <= 1) {
            return 0;
        }
        cur = o->pos;
        if (cur % cols == cols - 1) {
            if (o->hdr.bf0b6 == 0) {
                return 0;
            }
            next = (s8)(cur - (cols - 1));
        } else {
            next = (s8)(cur + 1);
        }
    } else if (dir == 2) {
        u8 rows = o->hdr.xmax;

        if (rows <= 1) {
            return 0;
        }
        cols = o->hdr.ymax;
        cur = o->pos;
        if (cur < cols) {
            if (o->hdr.bf0b6 == 0) {
                return 0;
            }
            next = (s8)(cur + cols * (rows - 1));
        } else {
            next = (s8)(cur - cols);
        }
    } else {
        u8 rows = o->hdr.xmax;

        if (rows <= 1) {
            return 0;
        }
        cur = o->pos;
        cols = o->hdr.ymax;
        if (cur >= cols * (rows - 1)) {
            if (o->hdr.bf0b6 == 0) {
                return 0;
            }
            next = (s8)(cur % cols);
        } else {
            next = (s8)(cur + cols);
        }
    }

    if (o->hdr.items[next].param == -3) {
        return 0;
    }
    o->pos = (u8)next;
    return 1;
}



u32 func_0201FC1C(BmpMenu *o)
{
    u32 best = 0;
    u8 i;

    for (i = 0; i < o->hdr.xmax * o->hdr.ymax; i++) {
        u32 r = (u8)func_0201D304((struct StrObj *)o->hdr.items[i].str, (u32)o->hdr.fontH, 0);

        if (best < r) {
            best = r;
        }
    }
    return best;
}




static inline void PrintUtil_Print(PrintUtil *util, void *que, s32 x, s32 y, const void *str, void *font)
{
    func_0201C6FC(que, (u32)func_02045770(util->cell), x, y, (void *)str, (u32)font);
    util->drawn = 1;
}




/*
 * bmp_menu.c: the three drawing helpers the constructor func_0201F93C calls.
 *   func_0201FC5C  clear the window bitmap to 0xFF and print every item of
 *                  the xmax * ymax grid (column-major index j + i * ymax)
 *                  through the print-util inline (the func_02020D5C shape:
 *                  print via func_0201C6FC, then util->drawn = 1).
 *   func_0201FD18  unless the cursor-display bitfield (+0x0B bits 4..5) is 1,
 *                  place the cursor at the pixel position of the current item.
 *   func_0201FD54  item index -> pixel position: column = pos / ymax, row =
 *                  pos % ymax.
 *
 * Declaration facts that closed them (all three had DIFF notes,
 * docs/notes/pkt_0201FC5C.c.txt and lane2_func_0201FD54.c.txt):
 *  - 0x0209C0A4 is _s32_div_f (layout/runtime_arm9.txt), which returns the
 *    quotient in r0 and the remainder in r1: the "unexplained" r1 of the
 *    second call in func_0201FD54 is `pos % ymax`, not a register tie
 *    (docs/idioms/div-and-mod-are-two-calls.md).
 *  - header byte +0x0B is three UNSIGNED bitfields 4:2:2 (func_0201FDA0
 *    writes them with 0x0F / 0x30 / 0xC0 masks); an unsigned field gives the
 *    `lsrs` func_0201FD18 needs where a shift expression gave `asrs`.
 *  - the print call is an inline taking the util handle first, which is what
 *    keeps the handle in a spill slot across the call in func_0201FC5C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201FC5C.c \
 *       --addr 0x0201FC5C --thumb
 */
void func_0201FC5C(BmpMenu *m)
{
    u8 i, j;
    u8 x, step;

    func_02043B5C(func_02045770(m->hdr.win), 0xFF);
    x = m->px;
    step = m->width + m->xspc * 2;
    for (i = 0; i < m->hdr.xmax; i++) {
        for (j = 0; j < m->hdr.ymax; j++) {
            PrintUtil_Print(m->hdr.util, m->hdr.que, x,
                            (u8)(m->py + j * (m->yspc + m->hdr.lineSpc)),
                            m->hdr.items[j + i * m->hdr.ymax].str, m->hdr.fontH);
        }
        x += step;
    }
}




void func_0201FD18(BmpMenu *m)
{
    u8 x, y;

    if (m->hdr.cDisp != 1) {
        func_0201FD54(m, &x, &y, m->pos);
        func_02020D5C(m->cursor, x, y, (struct Handle *)m->hdr.util, m->hdr.que, (u32)m->hdr.fontH);
    }
}




void func_0201FD54(BmpMenu *m, u8 *x, u8 *y, u8 pos)
{
    *x = (pos / m->hdr.ymax) * (m->width + m->xspc * 2);
    *y = m->py + (pos % m->hdr.ymax) * (m->yspc + m->hdr.lineSpc);
}




static inline void PrintUtil_Init(PrintUtil *util, void *cell)
{
    util->cell = cell;
    util->drawn = 0;
}




/*
 * bmp_menu.c: the yes/no menu builder (message archive 2 entry 0xE9, a
 * two-item BmpMenuWork list, a BmpMenuHeader filled on the stack, then
 * func_0201F9D0 and the window upload).  docs/notes/pkt_0201FC5C.c.txt.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 284/284, 2 bytes out for
 * five waves: the r3 home store `str r3, [sp, #0x14]` scheduled after
 * `ldr r4, [sp, #0x50]` / `adds r5, r0, #0`): the fifth (stack) parameter
 * is a heap id and is u16, with u16 on the heap parameter of every callee
 * it is passed to.  docs/idioms/a-u16-stack-parameter-passed-to-a-u16-
 * callee-stays-behind-a-spill-store.md is the same lever; with u16 heap
 * and the old u32 prototypes the body narrows at every call.
 */
BmpMenu *func_0201FDA0(const WinDat *winDat, u16 base, u8 pal, u8 pos, u16 heap)
{
    BmpMenuHeader hdr;
    void *msg;
    BmpMenuWork *list;
    BmpMenu *m;

    msg = func_02045B38(0, 2, 0xE9, heap);
    list = func_0201F81C(2, (int)(u16)heap);
    func_0201F878((struct Slot *)list, (u32)msg, 0, 0, heap);
    func_0201F878((struct Slot *)list, (u32)msg, 1, -2, heap);
    func_02045C04(msg);

    MI_CpuFill8(&hdr, 0, sizeof(hdr));
    hdr.items = list;
    hdr.win = (void *)func_020450F0(winDat->frame, winDat->x, winDat->y, 7, 4, winDat->pal, 1);
    hdr.xmax = 1;
    hdr.ymax = 2;
    hdr.lineSpc = 1;
    hdr.cDisp = 0;
    hdr.bf0b6 = 0;
    hdr.util = func_02030734(heap, sizeof(PrintUtil), 1, sBmpMenuFile, 0x263);
    hdr.fontH = func_0201D7EC(0x17, 0, 0, 0, heap);
    hdr.unk0e = func_0201DC80(hdr.fontH);
    hdr.unk0c = 10;
    PrintUtil_Init(hdr.util, hdr.win);
    hdr.que = (void *)func_0201C440((void *)heap);
    hdr.unk20 = 0;

    m = func_0201F9D0(&hdr, 0xE, 0, pos, heap, 2);
    func_02045374(hdr.win);
    func_0201F73C(hdr.win, 0, base, pal);
    func_020409B4(func_02045730(hdr.win));
    func_02045334(hdr.win);
    return m;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201FEBC.c \
 *       --func func_0201FEBC --addr 0x0201FEBC --cc 1.1p1 --thumb
 */
u32 func_0201FEBC(BmpMenu *p)
{
    u32 r = func_0201FA04(p);
    u32 t = func_0201C4E4((struct PrintSys *)p->hdr.que);

    if (p->hdr.unk20 == 0 && t != 0) {
        func_02045334((struct Descriptor *)p->hdr.win);
        p->hdr.unk20 = 1;
    }
    if (r != 0xffffffff) {
        func_0201FEF4(p);
    }
    return r;
}




void func_0201FEF4(BmpMenu *o)
{
    func_0201C6EC((struct PrintSys *)o->hdr.que);
    func_0201C4C0((struct PrintSys *)o->hdr.que);
    func_020307B0(o->hdr.util);
    func_0201F7A8(o->hdr.win, 0);
    func_0201D83C(o->hdr.fontH);
    func_0201F868(o->hdr.items);
    func_020452E8(o->hdr.win);
    func_0201F9E8(o, 0);
}
