/*
 * file:     bmp_menulist_p02.c
 * unit:     yes
 * function: func_02020CA0, func_02020CF8, func_02020D0C, func_02020D10, func_02020D18, func_02020D3C, func_02020D5C, func_02020DC8, func_02020DEC, func_02020E08, func_02020E60, func_02020F84, func_02020FB4, func_02020FE4, func_02021014, func_020210C8, func_02021288, func_020212B0, func_020212E4, func_0202130C, func_02021350, func_0202136C, func_0202138C, func_020213AC
 * address:  0x02020CA0
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
 *   func_02045730  0x02045730  arm
 *   func_02045770  0x02045770  arm
 *   func_0204169C  0x0204169C  arm
 *   func_02020A58  0x02020A58  thumb
 *   func_02020B5C  0x02020B5C  thumb
 *   func_02020D18_File  0x020A73A0  data
 *   func_02045808  0x02045808  arm
 *   func_020437AC  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_020439A0  0x020439A0  arm
 *   func_02045334  0x02045334  arm
 *   sub_0209E8CC_Obj  0x0209E8CC  data
 *   func_0200575C  0x0200575C  thumb
 *   func_020788AC  0x020788AC  arm
 *   func_02078C18  0x02078C18  arm
 *   g_020A73B0     0x020A73B0  data
 *   FS_CloseFile   0x02078A80  arm
 *   FS_SeekFile    0x02078B44  arm
 *   FS_ReadFile    0x02078B70  arm
 *   FS_GetLength   0x02078C28  arm
 *   sub_02030734   0x02030734  arm
 *   func_0202F170       0x0202F170  thumb
 *   func_020490F4       0x020490F4  arm
 *   func_02049250       0x02049250  arm
 *   func_02048F60       0x02048F60  arm
 *   item_gfx_member     0x0209EB6C  data
 *   item_gfx_member_x   0x0209E9E8  data
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   g_0209EAA0     0x0209EAA0  data
 *   g_0209E8EC     0x0209E8EC  data
 */
#include "../../matched/include/Obj17238.h"
#include "../../matched/include/Obj17240.h"
#include "../../matched/include/Obj15729.h"

struct Descriptor;
struct Obj020437AC;
struct U16Vec;
struct PrintSys;
struct Bmp;
struct ArcFile;
struct MsgBank;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Obj {
    u8    pad[0x3C];
    void *unk3C;
};

struct D {
    u8    pad[4];
    void *f4;
    void *f8;
};

typedef short          s16;

typedef int            s32;

struct Desc {
    u32   mode;
    void *f4;
    void *f8;
};

struct Handle {
    void *cell;
    u8    drawn;
};

struct FSFile {
    u8 raw[0x48];
};

struct ItemGfxMember {
    u16 lo;
    u16 hi;
};

typedef signed char    s8;

/* The sub-record at +0x10 of the header, seventeen bytes of packed fields. */
struct Sub {
    u8 b00_0 : 1;
    u8 b00_1 : 1;
    u8 b00_2 : 1;
    u8 b00_3 : 1;
    u8 b00_4 : 1;
    u8 b00_5 : 1;
    u8 b00_6 : 1;
    u8 b00_7 : 1;

    u8 b01_0 : 1;
    u8 b01_1 : 1;
    u8 b01_2 : 1;
    u8 b01_3 : 1;
    u8 b01_4 : 4;

    u8 b02_0 : 4;
    u8 b02_4 : 4;

    u8 b03_0 : 4;
    u8 b03_4 : 4;

    u8 b04_0 : 4;
    u8 b04_4 : 2;
    u8 b04_6 : 1;
    u8 b04_7 : 1;

    u8 b05_0 : 1;
    u8 b05_1 : 1;
    u8 b05_2 : 1;
    u8 b05_3 : 1;
    u8 b05_4 : 1;
    u8 b05_5 : 1;
    u8 b05_6 : 1;
    u8 b05_7 : 1;

    u8 b06_0 : 1;
    u8 b06_1 : 1;
    u8 b06_2 : 1;
    u8 b06_3 : 1;
    u8 b06_4 : 1;

    s8 f07;
    s8 f08;
    s8 f09;
    s8 f0A;
    s8 f0B;
    s8 f0C;
    u8 f0D;
    u8 f0E;
    s8 f0F;
    s8 f10;
    s8 f11;
};

/* The record header. */
struct Rec {
    u16 f00;
    u8  f02;
    u8  f03;
    u8  f04;
    u8  f05;
    u8  f06;
    u8  f07;
    u16 b08_0  : 5;
    u16 b08_5  : 1;
    u16 b08_6  : 1;
    u16 b08_7  : 4;
    u16 b08_11 : 5;
    u8  f0A;
    u8  f0B;
    u8  f0C;
    u8  f0D;
    u8  f0E;
    u8  f0F;
    u8  f10;
};

extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern u8 func_0204169C(int channel);
extern void  func_02020A58(void *bmp, u32 a, u32 b, u32 c, u32 off);
extern void  func_02020B5C(void *bmp, u32 a, u32 b, u32 c, u32 off);
extern void func_020206C0(struct Obj *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02045808(struct U16Vec *vec);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_02045334(struct Descriptor *d);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void *func_0200575C(u32 x);
extern void  func_020788AC(void *p);
extern void  func_02078C18(void *p, void *q);
extern void  FS_CloseFile(struct FSFile *file);
extern u32   FS_SeekFile(struct FSFile *file, int offset, u32 origin);
extern u32   FS_ReadFile(struct FSFile *file, void *dst, u32 size);
extern u32   FS_GetLength(struct FSFile *file);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32   func_0202F170(u32 item);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
void func_02020CA0(void *win, u32 a, u32 b, u32 c, u16 tile);
void func_02020CF8(struct Obj *p, int heap);
u32 func_02020D0C(u8 *p);
void func_02020D10(u8 *p, u32 v);
void *func_02020D18(u32 heap);
void func_02020D3C(struct D *p);
void func_02020D5C(struct Desc *d, u32 x, u32 y, struct Handle *h, void *dst, u32 f);
void func_02020DC8(char *p, int a);
void func_02020DEC(void *p, u32 x);
void *func_02020E08(u32 archive_id, u32 heap, u32 offset, u32 size);
u32 func_02020E60(u32 item, u32 which);
u32 func_02020F08(void);
u32 func_02020F0C(void);
u32 func_02020F10(void);
void *func_02020F14(u32 heap);
u32 func_02020F20(void *handle, u32 item, u32 arg);
void *func_02020F34(u32 item, u32 which, u32 heap);
void func_02020F84(void *dst, u32 entry, u32 heap);
void func_02020FB4(void *dst, u32 entry, u32 heap);
u32 func_02020FE4(void *a, u32 sel, u32 id);
u32 func_02021014(struct Rec *p, u32 sel);
int func_020210C8(struct Sub *q, u32 sel);
u32 func_02021288(u32 id);
u16 func_020212B0(u16 id);
u32 func_020212E4(u16 v);
u32 func_0202130C(u32 id);
u8 func_02021350(u16 id);
u32 func_0202136C(u16 v);
u8 func_0202138C(u16 v);
u16 func_020213AC(u32 i);
extern const char func_02020D18_File[];
extern u8 sub_0209E8CC_Obj[];
extern char g_020A73B0[];
extern struct ItemGfxMember item_gfx_member[];
extern struct ItemGfxMember item_gfx_member_x[];
extern const u16 g_0209EAA0[];
extern const u16 g_0209E8EC[];





/*
 * UNBLOCKED 2026-09-21: the two THM_CALL sites at +0x36 and +0x4e now
 * attest `matched` off src/matched/func_02020A58.c and the newly filed
 * src/matched/func_02020B5C.c.  All 5 relocation sites resolve and the
 * verdict is EXACT*; promoted from src/pending/ unchanged apart from
 * this header.  EXACT* only because 0x02020CF8 has no label.
 *
 * Window-fill front end.  The window descriptor names a BG channel
 * (func_02045730, the +2 accessor) and carries the bitmap it draws into
 * (func_02045770, the +0xc handle).  func_0204169C says whether that
 * channel is 8bpp; the 4bpp path calls func_02020A58 and the 8bpp path
 * func_02020B5C, and the caller's tile offset is converted to a byte
 * offset by the depth: (t & 0x7ff) << 5 for 4bpp, (t & 0x3ff) << 6 for
 * 8bpp, i.e. 32 or 64 bytes per tile.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020CA0.c \
 *       --func func_02020CA0 --addr 0x02020CA0 --cc 1.1p1 --thumb
 */
void func_02020CA0(void *win, u32 a, u32 b, u32 c, u16 tile)
{
    int   channel;
    void *bmp;

    channel = func_02045730(win);
    bmp = func_02045770(win);

    if (func_0204169C(channel) == 0)
        func_02020A58(bmp, a, b, c, (u32)(tile << 21) >> 16);
    else
        func_02020B5C(bmp, a, b, c, (u32)(tile << 22) >> 16);
}





/*
 * A whole translation unit, matched as one byte range.
 *
 * func_02020D0C and func_02020D10 carry no label in the generated listing:
 * they are a two-instruction word getter and a two-instruction byte setter
 * with no register-saving prologue, so disasm.py's prologue sweep never
 * fires on them and the listing prints them as a run of data between
 * func_02020CF8 and func_02020D18
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * func_02020D18 is a debug-allocator constructor in the
 * `sub_02030734(heap, size, count, file, line)` shape documented for
 * playtime.c: it allocates a 12-byte object tagged with the string at
 * 0x020A73A0 and line 0x3a, zeroing the first word when the allocation
 * succeeds.  0x020A73A0 spells "bmp_cursor.c", the second original source
 * file name this project has recovered (after playtime.c); the functions
 * keep their sub_<address> names because the file identity is attested and
 * the individual entry points are not.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020CF8.c \
 *       --addr 0x02020CF8 --thumb
 */
void func_02020CF8(struct Obj *p, int heap)
{
    func_02020DC8(p->unk3C, heap);
    func_020206C0(p);
}


u32 func_02020D0C(u8 *p)
{
    return ((struct Obj17238 *)p)->f1C;
}





void func_02020D10(u8 *p, u32 v)
{
    p[0x4A] = v;
}





void *func_02020D18(u32 heap)
{
    void *p = func_02030734((u16)heap, 0xc, 1, func_02020D18_File, 0x3a);

    if (p != 0) {
        ((struct Obj17240 *)p)->f0 = 0;
    }
    return p;
}





/*
 * A destructor: frees two owned sub-objects at +4 and +8 if present, then
 * hands the object itself to a common finalizer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020D3C.c \
 *       --func func_02020D3C --addr 0x02020D3C --cc 1.1p1 --thumb
 */
void func_02020D3C(struct D *p)
{
    if (p->f4 != 0) {
        func_02045808(p->f4);
    }
    if (p->f8 != 0) {
        func_020437AC(p->f8);
    }
    func_020307B0(p);
}



/*
 * Blits one cursor/icon out of its cell holder, choosing between two
 * targets by the descriptor's mode word: mode 1 draws through the
 * 0x0201C6FC window path and latches a "drawn" flag on the caller's
 * handle, anything else falls back to the plain 8x8 palette-0xf blit
 * at 0x020439A0 when a surface is configured, and releases the cell
 * afterwards.
 */
void func_02020D5C(struct Desc *d, u32 x, u32 y, struct Handle *h,
                   void *dst, u32 f)
{
    if (d->mode == 1) {
        func_0201C6FC(dst, (u32)func_02045770(h->cell), (s16)x, (s16)y, d->f4, f);
        h->drawn = 1;
    } else if (d->f8 != 0) {
        func_020439A0(d->f8, func_02045770(h->cell), 0, 0,
                      x + 2, y + 2, 8, 8, 0xf);
        func_02045334(h->cell);
    }
}



void func_02020DC8(char *p, int a)
{
    ((struct Obj15729 *)p)->f8 = (u32)func_020436FC((void *)((int)sub_0209E8CC_Obj), 1, 1, 0x20, a);
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020DEC.c \
 *       --func func_02020DEC --addr 0x02020DEC --cc 1.1p1 --thumb
 */
void func_02020DEC(void *p, u32 x)
{
    void *q;

    q = func_0200575C(x);
    func_020788AC(p);
    func_02078C18(p, q);
}




/*
 * "Read a byte range out of a whole file, by archive id", the raw-file
 * counterpart to the arc_tool.c NARC member API.  func_02020DEC (already
 * EXACT) opens the file whose path is name-table entry `archive_id`; this
 * function then seeks to `offset`, allocates `size` bytes on `heap` and
 * reads them in.  A zero `size` means "the whole file", which is why the
 * FS_GetLength call is guarded rather than unconditional.
 *
 * g_020A73B0 is the __FILE__ argument of the allocation site.  Its bytes
 * spell "file_util.c", and the run is fixed from outside this function by
 * the terminator of "bmp_cursor.c" immediately before it
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md), so the
 * enclosing translation unit for both this function and func_02020DEC is
 * file_util.c.
 *
 * The only caller in the image is sub_0201407C, the a/0/1/3 record reader
 * (src/matched/sub_0201407C.c), which passes archive_id 13 with size 10:
 * a/0/1/3 is a flat 2820-byte file, not a NARC, so it cannot go through
 * the member API at all.  See the "Archive readers traced by call graph"
 * section of docs/ASSETS.md.
 *
 * `size` has to stay live in its own local across the guarded call: the
 * compiler keeps r5 as both the parameter and the FS_GetLength result, so
 * writing the length into a fresh variable and selecting afterwards costs
 * an extra move.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020E08.c \
 *       --func func_02020E08 --addr 0x02020E08 --cc 1.1p1 --thumb
 */
void *func_02020E08(u32 archive_id, u32 heap, u32 offset, u32 size)
{
    struct FSFile file;
    void *buf;

    func_02020DEC(&file, archive_id);
    if (size == 0) {
        size = FS_GetLength(&file);
    }
    buf = sub_02030734(heap, size, 0, g_020A73B0, 0xAC);
    FS_SeekFile(&file, offset, 0);
    FS_ReadFile(&file, buf, size);
    FS_CloseFile(&file);
    return buf;
}



/*
 * The item archive's own accessor block: 0x02020E60..0x02020F84, seven
 * functions, five of them unlabelled leaves that print as a `.word`/`.byte`
 * run in the listing (see docs/idioms/unlabelled-leaf-functions-hide-in-
 * word-runs.md).
 *
 * This is the file that closes the item chain
 * func_02021014 <- func_02020FE4 <- func_02020F34: three separate functions
 * here name the item archive id 0x18 as a plain immediate
 * (func_02020F14's handle open, func_02020F34's one-shot member read) and
 * two name the item graphics archive 0x19 (func_02020F08 answers it as a
 * constant, func_02020F34 reads members of it).  Archive ids are the
 * decimal spelling of the a/X/Y/Z path, so 0x18 = 24 = a/0/2/4 and
 * 0x19 = 25 = a/0/2/5.
 *
 * 626 is the last item id: a/0/2/4 has 627 members, 0..626.  Both bounds
 * checks in this file clamp an out of range id to 0 rather than rejecting.
 *
 * Blocked at MATCH, not EXACT: three relocation sites have no witness
 * outside this range.
 *   - item_gfx_member_x (0x0209E9E8) and func_0202F170 (0x0202F170) are
 *     named only from here anywhere in the image.
 *   - item_gfx_member (0x0209EB6C) has exactly one literal witness,
 *     0x02020F7C, which is func_02020F34's own pool and therefore inside
 *     this range.  func_02020E60's copy of the same word sits at
 *     0x02020EF4 but is not indexed as a literal pool by disasm.py: that
 *     pool is inside the `.byte` run this unit's leaf functions live in.
 *     Splitting func_02020E60 and func_02020F34 into two files does not
 *     fix it either: verified separately, the split leaves
 *     func_02020E60 attested (literal 0x02020F7C, now outside its range)
 *     and func_02020F34 still not, since its only witness is its own
 *     pool word.  `tu --suggest-split` agrees and leaves both out.
 *
 * The middle piece that --suggest-split does keep, the five leaf
 * accessors 0x02020F08..0x02020F34, is filed EXACT on its own as
 * src/matched/unit_02020F08.c; this file stays as the whole-range record.
 *
 * Every concrete byte of this range is reproduced; only the relocation
 * fields above stay wildcarded.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02020E60.c \
 *       --addr 0x02020E60 --thumb
 */
u32 func_02020E60(u32 item, u32 which)
{
    if (item > 626) {
        item = 0;
    }

    switch (which) {
    case 0:
        if (item == 0 || item == 0xFFFF) {
            break;
        }
        return item;
    case 1:
        if (item == 0) {
            return 1001;
        }
        if (item == 0xFFFF) {
            return 1003;
        }
        return item_gfx_member[item].lo;
    case 2:
        if (item == 0) {
            return 1002;
        }
        if (item == 0xFFFF) {
            return 1004;
        }
        return item_gfx_member[item].hi;
    case 3:
        return item_gfx_member_x[func_0202F170(item)].lo;
    case 4:
        return item_gfx_member_x[func_0202F170(item)].hi;
    }

    return 0;
}



u32 func_02020F08(void)
{
    return 0x19;
}



u32 func_02020F0C(void)
{
    return 1;
}



u32 func_02020F10(void)
{
    return 0;
}



void *func_02020F14(u32 heap)
{
    return func_020490F4(0x18, heap);
}



u32 func_02020F20(void *handle, u32 item, u32 arg)
{
    if (item > 626) {
        item = 0;
    }

    return (u32)func_02049250(handle, item, arg);
}



void *func_02020F34(u32 item, u32 which, u32 heap)
{
    if (item > 626) {
        item = 0;
    }

    switch (which) {
    case 0:
        return func_02048F60(0x18, item, heap);
    case 1:
        return func_02048F60(0x19, item_gfx_member[item].lo, heap);
    case 2:
        return func_02048F60(0x19, item_gfx_member[item].hi, heap);
    }

    return 0;
}




/*
 * One of a pair of near-identical entry points (func_02020F84 uses table 0x36,
 * func_02020FB4 table 0x35) that open a message archive, read one entry into
 * the caller's buffer and close it again.  An out-of-range entry index falls
 * back to 0; the bound 0x272 is one more than the last id func_02021288
 * accepts, which is why it is a pool word rather than a folded immediate.
 *
 * The heap argument stays in r3 across the guard because it is the fourth
 * argument of the archive open, not a leftover: the ARM callee clobbers r0-r3,
 * so a value still in r3 at the second call could not have survived the first
 * (docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-
 * arity.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020F84.c  *       --func func_02020F84 --addr 0x02020F84 --cc 1.1p1 --thumb
 */
void func_02020F84(void *dst, u32 entry, u32 heap)
{
    void *arc;

    if (entry > 0x272) {
        entry = 0;
    }
    arc = func_02045B38(0, 2, 0x36, heap);
    func_02045CAC(arc, entry, dst);
    func_02045C04(arc);
}




/*
 * One of a pair of near-identical entry points (func_02020F84 uses table 0x36,
 * func_02020FB4 table 0x35) that open a message archive, read one entry into
 * the caller's buffer and close it again.  An out-of-range entry index falls
 * back to 0; the bound 0x272 is one more than the last id func_02021288
 * accepts, which is why it is a pool word rather than a folded immediate.
 *
 * The heap argument stays in r3 across the guard because it is the fourth
 * argument of the archive open, not a leftover: the ARM callee clobbers r0-r3,
 * so a value still in r3 at the second call could not have survived the first
 * (docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-
 * arity.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020FB4.c  *       --func func_02020FB4 --addr 0x02020FB4 --cc 1.1p1 --thumb
 */
void func_02020FB4(void *dst, u32 entry, u32 heap)
{
    void *arc;

    if (entry > 0x272) {
        entry = 0;
    }
    arc = func_02045B38(0, 2, 0x35, heap);
    func_02045CAC(arc, entry, dst);
    func_02045C04(arc);
}




/*
 * One-shot wrapper over the record getter of src/matched/unit_02021014.c:
 * build a temporary record for the id (with bit 15 forced on and the rest of
 * the id masked to fifteen bits), read one property out of it, free it, and
 * answer the property.
 *
 * 0x8000 costs no second pool word: the compiler keeps 0x7FFF in r3 for the
 * mask and derives the set bit from it with `adds r2, r3, #1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020FE4.c \
 *       --func func_02020FE4 --addr 0x02020FE4 --cc 1.1p1 --thumb
 */
u32 func_02020FE4(void *a, u32 sel, u32 id)
{
    void *rec;
    u32   v;

    rec = func_02020F34((u32)a, 0, (u16)((id & 0x7FFF) | 0x8000));
    v = func_02021014(rec, sel);
    func_020307B0(rec);
    return v;
}




/*
 * A whole translation unit range, matched as one byte range.
 *
 * The two halves of one property-getter interface over a packed record: a
 * caller hands in a record pointer and a property id, and gets an unsigned
 * quantity back.  Ids 0..0x11 are answered by func_02021014 out of the record
 * header; anything above that is delegated, for one of the two header layouts,
 * to func_020210C8 on the sub-record at +0x10, which answers ids 0x12..0x3E out
 * of a seventeen-byte bitfield block.
 *
 * The two are one file rather than two because func_02021014's call to
 * func_020210C8 is the only branch to that address anywhere in the image: as
 * separate files neither can attest the other and both cap at MATCH, while in
 * one translation unit the call is `local` and needs no image evidence at all
 * (docs/AGENT-BRIEF.md section 5, the `local` class).
 *
 * Two shape findings, both of which cost real bytes:
 *
 *  - func_02021014's dispatch runs in r2, not in the switch value's own r1
 *    (docs/idioms/a-void-return-frees-r0-for-the-switch-dispatch-index.md: the
 *    index register is the switch value's register only when that register is
 *    dead across the arms).  Here it is not dead, and the reason is the
 *    delegation: func_020210C8 takes the property id as its second argument,
 *    which is already sitting in r1, so the call site sets only r0 and r1 stays
 *    live to the end of the function.  Declaring func_020210C8 as a one
 *    argument function is byte for byte right everywhere else and wrong in
 *    those nine bytes.  func_020210C8's own `subs r1, #0x12` is the independent
 *    confirmation that its second parameter is the same id.
 *  - the fall-through of func_02021014 is a two-case `switch` on the header
 *    byte at +0xC, not a chain of `if`s: the switch form emits
 *    cmp/beq, cmp/beq, b-to-default, the `if` chain emits the inverted
 *    bne-over form and is two bytes shorter.
 *
 * The `ldrsb r0, [r0, r1]` arms of func_020210C8 are the signedness evidence
 * for the six plain fields at +7..+0xC and the three at +0xF..+0x11: there is
 * no immediate-offset `ldrsb`, so a signed byte load has to materialise its
 * offset in a register (docs/idioms/ldrsh-register-offset-is-signedness.md).
 * +0xD and +0xE load with a plain `ldrb` and are unsigned, which is why the
 * declared return type has to be signed for the rest to sign-extend.
 *
 * Addresses are Black-image addresses.  The bitfield block's contents are
 * content data, not code shape: if Pokemon White sizes this record
 * differently, the field list here is the thing to re-derive, not the dispatch.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02021014.c \
 *       --addr 0x02021014 --thumb
 */
u32 func_02021014(struct Rec *p, u32 sel)
{
    switch (sel) {
    case 0:
        return p->f00 * 10;
    case 1:
        return p->f02;
    case 2:
        return p->f03;
    case 3:
        return p->b08_5;
    case 4:
        return p->b08_6;
    case 5:
        return p->b08_7;
    case 6:
        return p->f0A;
    case 7:
        return p->f0B;
    case 8:
        return p->f04;
    case 9:
        return p->f05;
    case 10:
        return p->f06;
    case 11:
        return p->f07;
    case 12:
        return p->b08_0;
    case 13:
        return p->b08_11;
    case 14:
        return p->f0C;
    case 15:
        return p->f0D;
    case 16:
        return p->f0E;
    case 17:
        return p->f0F;
    }

    switch (p->f0C) {
    case 0:
        return p->f10;
    case 1:
        return func_020210C8((struct Sub *)&p->f10, sel);
    }
    return 0;
}


int func_020210C8(struct Sub *q, u32 sel)
{
    switch (sel) {
    case 0x12:
        return q->b00_0;
    case 0x13:
        return q->b00_1;
    case 0x14:
        return q->b00_2;
    case 0x15:
        return q->b00_3;
    case 0x16:
        return q->b00_4;
    case 0x17:
        return q->b00_5;
    case 0x18:
        return q->b00_6;
    case 0x19:
        return q->b00_7;
    case 0x1A:
        return q->b01_0;
    case 0x1B:
        return q->b01_1;
    case 0x1C:
        return q->b01_2;
    case 0x1D:
        return q->b01_3;
    case 0x1E:
        return q->b01_4;
    case 0x1F:
        return q->b02_0;
    case 0x20:
        return q->b02_4;
    case 0x21:
        return q->b03_0;
    case 0x22:
        return q->b03_4;
    case 0x23:
        return q->b04_0;
    case 0x24:
        return q->b04_4;
    case 0x25:
        return q->b04_6;
    case 0x26:
        return q->b04_7;
    case 0x27:
        return q->b05_0;
    case 0x28:
        return q->b05_1;
    case 0x29:
        return q->b05_2;
    case 0x2A:
        return q->b05_3;
    case 0x2B:
        return q->b05_4;
    case 0x2C:
        return q->b05_5;
    case 0x2D:
        return q->b05_6;
    case 0x2E:
        return q->b05_7;
    case 0x2F:
        return q->b06_0;
    case 0x30:
        return q->b06_1;
    case 0x31:
        return q->b06_2;
    case 0x32:
        return q->b06_3;
    case 0x33:
        return q->b06_4;
    case 0x34:
        return q->f07;
    case 0x35:
        return q->f08;
    case 0x36:
        return q->f09;
    case 0x37:
        return q->f0A;
    case 0x38:
        return q->f0B;
    case 0x39:
        return q->f0C;
    case 0x3A:
        return q->f0D;
    case 0x3B:
        return q->f0E;
    case 0x3C:
        return q->f0F;
    case 0x3D:
        return q->f10;
    case 0x3E:
        return q->f11;
    }
    return 0;
}



/*
 * The membership test for the two id windows this file's tables are indexed
 * by: 0x148..0x1A9 and 0x26A..0x26C.  Written as one disjunction so that both
 * true arms share the single `movs r0, #1` exit and both false arms the single
 * `movs r0, #0` (docs/idioms/disjunction-must-be-one-expression-to-share-its-
 * exit.md); as two separate `if` statements each window grows its own return.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021288.c \
 *       --func func_02021288 --addr 0x02021288 --cc 1.1p1 --thumb
 */
u32 func_02021288(u32 id)
{
    if ((id >= 0x148 && id <= 0x1A9) || (id >= 0x26A && id <= 0x26C)) {
        return 1;
    }
    return 0;
}




/*
 * Halfword lookup keyed by one of the two id windows func_02021288 accepts:
 * 0x148..0x1A9 maps to entries 0..0x61 of the table at 0x0209EAA0 and
 * 0x26A..0x26C continues at 0x62..0x64, which is why the second window's
 * subtrahend is 0x208 rather than its own start.  Ids outside both windows
 * answer 0.
 *
 * The two subtrahends are one constant: the compiler keeps 0x26A in r0 for the
 * window test and derives 0x208 from it with `subs r0, #0x62` rather than
 * spending a second pool word.
 *
 * The id parameter is `u16` and the subtraction is written back into it, not
 * into a fresh local.  That is what puts the index in r4, the parameter's own
 * callee-saved home, and leaves r0 free for the table base: with a separate
 * `u16 i` local the narrowed index is a dead temporary, lands in r0, and the
 * last three instructions come out in the other order, five bytes wrong.  A
 * `u32` parameter with an explicit `(u16)` cast is the same five bytes wrong,
 * so the `u16` parameter type is real evidence and not a spelling choice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020212B0.c \
 *       --func func_020212B0 --addr 0x020212B0 --cc 1.1p1 --thumb
 */
u16 func_020212B0(u16 id)
{
    if (func_02021288(id) == 0) {
        return 0;
    }
    if (id >= 0x26A) {
        id -= 0x208;
    } else {
        id -= 0x148;
    }
    return g_0209EAA0[id];
}




/*
 * Linear search of the six-entry tail of the same halfword table
 * func_020212B0 indexes, entries 0x5C..0x61.  The 0xB8 byte offset is kept out
 * of the `ldrh` encoding because it is past the halfword load's +62 reach
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md), so the address comes
 * out as base, plus the scaled index, plus a separate `adds r1, #0xb8`.
 *
 * The counter is a `u8`: the increment is `adds`/`lsls #0x18`/`lsrs #0x18`
 * through a scratch register, which a `u32` counter does not produce.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020212E4.c \
 *       --func func_020212E4 --addr 0x020212E4 --cc 1.1p1 --thumb
 */
u32 func_020212E4(u16 v)
{
    u8 i;

    for (i = 0; i < 6; i++) {
        if (v == g_0209EAA0[0x5C + i]) {
            return 1;
        }
    }
    return 0;
}




/*
 * Maps an id in one of func_02021288's two accepted windows onto a byte-wide
 * slot number, in three ranges with three different subtrahends: 0x26A.. off
 * 0x20E, 0x1A4..0x269 off 0x145, and the rest off 0x148.  Ids the window test
 * rejects answer 0xFF.
 *
 * Only two pool words: 0x26A is loaded once and 0x1A4 derived from it with
 * `subs r0, #0xc6`, the same constant-sharing func_020212B0 does.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202130C.c \
 *       --func func_0202130C --addr 0x0202130C --cc 1.1p1 --thumb
 */
u32 func_0202130C(u32 id)
{
    if (func_02021288(id) == 0) {
        return 0xFF;
    }
    if (id >= 0x26A) {
        return (u8)(id - 0x20E);
    }
    if (id >= 0x1A4) {
        return (u8)(id - 0x145);
    }
    return (u8)(id - 0x148);
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021350.c  *       --func func_02021350 --addr 0x02021350 --cc 1.1p1 --thumb
 */
u8 func_02021350(u16 id)
{
    if (id >= 0x1A4 && id <= 0x1A9) {
        return (u8)(id - 0x1A4);
    }
    return 0xFF;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202136C.c  *       --func func_0202136C --addr 0x0202136C --cc 1.1p1 --thumb
 */
u32 func_0202136C(u16 v)
{
    u32 i;

    for (i = 0; i < 0xC; i++) {
        if (v == g_0209E8EC[i]) {
            return 1;
        }
    }
    return 0;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202138C.c  *       --func func_0202138C --addr 0x0202138C --cc 1.1p1 --thumb
 */
u8 func_0202138C(u16 v)
{
    u32 i;

    for (i = 0; i < 0xC; i++) {
        if (v == g_0209E8EC[i]) {
            return (u8)i;
        }
    }
    return 0;
}




/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020213AC.c  *       --func func_020213AC --addr 0x020213AC --cc 1.1p1 --thumb
 */
u16 func_020213AC(u32 i)
{
    if (i >= 0xC) {
        return 0;
    }
    return g_0209E8EC[i];
}
