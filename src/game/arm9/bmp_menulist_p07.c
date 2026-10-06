/*
 * file:     bmp_menulist_p07.c
 * unit:     yes
 * function: func_02020CA0, func_02020CF8, func_02020D0C, func_02020D10, func_02020D18, func_02020D3C, func_02020D5C, func_02020DC8, func_02020DEC, func_02020E08, func_02020E60
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
void func_02020CF8(struct Obj *p, int heap);
void func_02020DC8(char *p, int a);
extern void *func_0200575C(u32 x);
extern void  func_020788AC(void *p);
extern void  func_02078C18(void *p, void *q);
extern void  FS_CloseFile(struct FSFile *file);
extern u32   FS_SeekFile(struct FSFile *file, int offset, u32 origin);
extern u32   FS_ReadFile(struct FSFile *file, void *dst, u32 size);
extern u32   FS_GetLength(struct FSFile *file);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_02020DEC(void *p, u32 x);
void *func_02020E08(u32 archive_id, u32 heap, u32 offset, u32 size);
extern u32   func_0202F170(u32 item);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
void func_02020CA0(void *win, u32 a, u32 b, u32 c, u16 tile);
void func_02020CF8(struct Obj *p, int heap);
void func_02020D10(u8 *p, u32 v);
void *func_02020D18(u32 heap);
u32 func_02020E60(u32 item, u32 which);
u32 func_02020F08(void);
u32 func_02020F0C(void);
u32 func_02020F10(void);
void *func_02020F14(u32 heap);
u32 func_02020F20(void *handle, u32 item, u32 arg);
void *func_02020F34(u32 item, u32 which, u32 heap);
extern const char func_02020D18_File[];
extern u8 sub_0209E8CC_Obj[];
extern char g_020A73B0[];
extern struct ItemGfxMember item_gfx_member[];
extern struct ItemGfxMember item_gfx_member_x[];




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
u32 func_02020D0C(u8 *p)
{
    return ((struct Obj17238 *)p)->f1C;
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
void func_02020D10(u8 *p, u32 v)
{
    p[0x4A] = v;
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
