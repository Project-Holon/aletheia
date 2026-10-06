/*
 * file:     gf_font_p08.c
 * unit:     yes
 * function: func_0201F0F8, func_0201F104, func_0201F124, func_0201F134, func_0201F140, func_0201F14C, func_0201F158, func_0201F164, func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8, func_0201F1E0, func_0201F230, func_0201F250, func_0201F31C, func_0201F344, func_0201F35C, func_0201F41C, func_0201F448, func_0201F47C, func_0201F4A0
 * address:  0x0201F0F8
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
 *   unk_020A7370   0x020A7370  data
 *   func_0204581C  0x0204581C  arm
 *   func_02045AFC  0x02045AFC  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   g_0209E784     0x0209E784  data
 *   g_0209E758     0x0209E758  data
 *   g_0209E838     0x0209E838  data
 *   func_0201F4A0_Table  0x0209E864  data
 */
struct MsgBank;
struct Obj;
struct Rec;
struct Tag;
struct U16Vec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32_0201F0F8;

struct Entry_0201F0F8 {
    u8 tag[5];
    void *str;
};

struct WordSet_0201F0F8 {
    u32 count;
    u32 heap;
    struct Entry_0201F0F8 *entries;
    void *buf;
};

struct Entry_0201F250 {
    u32   unk00;
    u8    unk04;
    u8    pad05[3];
    void *unk08;
};

struct WordSet_0201F250 {
    u32 pad00[2];
    struct Entry_0201F250 *unk08;
};

struct Entry_0201F31C { u8 tag[5]; void *str; };

struct WordSet_0201F31C { u32 count; u32 heap; struct Entry_0201F31C *entries; void *buf; };

typedef int            s32_0201F35C;

typedef signed int     s32_0201F4A0;

struct Lim {
    u32 hi;
    u32 bias;
    u32 hi2;
};

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u16 func_02045F50(const struct Obj *o);
extern void  sub_02008500(void *a, void *b);
extern u32   func_02025B94(u32 a);
extern u32 func_0202A230(void *a, u32 idx);
extern void func_0200785C(void *save, u32 box, void *dest);
extern void func_0201ED64(struct WordSet_0201F0F8 *p, u32 i);
extern void func_0201ED84(struct WordSet_0201F0F8 *p, u32 i, const void *src,
                          const struct Tag *tag);
extern void func_0201EDD0(struct WordSet_0201F0F8 *p, u32 i, u32 id, u32 v);
extern void func_0201F0F8(struct WordSet_0201F0F8 *p, u32 i, u32 v);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_0204581C(struct U16Vec *vec);
extern u16  func_02045A98(void);
extern void func_02045AFC(struct U16Vec *vec, u16 value);
extern u32   func_0201D5C4(void);
extern u32   func_0201D5CC(const u16 *p);
extern void  func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr);
extern u32   func_0201D670(const u16 *p, u32 i);
extern u16  *func_0201D688(u16 *p);
extern u32  _u32_div_f(u32 a, u32 b);
extern u16 func_020458F8(struct U16Vec *vec);
extern void func_02045AA8(struct U16Vec *dst, struct U16Vec *src);
void func_0201F35C(void *ctx, s32_0201F35C n, u32 kind, u32 mode, u32 flag);
void func_0201F41C(const u16 *src, u16 *dst, u32 n);
u32 func_0201F448(const u16 *a, const u16 *b);
u32 func_0201F47C(void *s);
void func_0201F4A0(void *dest, void *src);
extern void *unk_020A7370;
extern u16  g_0209E784[];
extern u16  g_0209E758[];
extern u32  g_0209E838[];
extern const u16 func_0201F4A0_Table[];


/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F0F8(struct WordSet_0201F0F8 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xBF, v);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F104(struct WordSet_0201F0F8 *p, u32 i, u32 a)
{
    func_0201F0F8(p, i, (u8)func_0202A230((void *)a, 1));
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F124(struct WordSet_0201F0F8 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x11B, v);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F134(struct WordSet_0201F0F8 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xBE, v);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F140(struct WordSet_0201F0F8 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0xB4, v);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F14C(struct WordSet_0201F0F8 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x37, v);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F158(struct WordSet_0201F0F8 *p, u32 i, u32 v)
{
    func_0201EDD0(p, i, 0x59, v);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F164(struct WordSet_0201F0F8 *p, u32 i, u32 a, u32 b)
{
    func_0200785C((void *)a, b, p->buf);
    func_0201ED84(p, i, p->buf, 0);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F184(struct WordSet_0201F0F8 *p, u32 i, s32_0201F0F8 v)
{
    if (v >= 0x30) {
        v = 0;
    }
    func_0201EDD0(p, i, 0xA0, v);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F198(struct WordSet_0201F0F8 *p, u32 i, u32 v)
{
    if (v > 8) {
        func_0201ED64(p, i);
        return;
    }
    func_0201EDD0(p, i, 0x2B, v);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F1B0(struct WordSet_0201F0F8 *p, u32 i, u8 v)
{
    if (v > 0x91) {
        func_0201ED64(p, i);
        return;
    }
    func_0201EDD0(p, i, 0, v);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F1C8(struct WordSet_0201F0F8 *p, u32 i, u32 v)
{
    if (v > 8) {
        func_0201ED64(p, i);
        return;
    }
    func_0201EDD0(p, i, 0x38, v);
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F1E0(struct WordSet_0201F0F8 *p, u32 i, u32 v)
{
    void *s = func_02045B38(0, 3, (u16)0x1CD, (u16)p->heap);

    func_0201ED64(p, i);
    if (v <= 6 && s != 0) {
        func_02045CAC(s, v + 0x2B, p->buf);
        func_0201ED84(p, i, p->buf, 0);
        func_02045C04(s);
    }
}

/*
 *           func_0201F140, func_0201F14C, func_0201F158, func_0201F164,
 *           func_0201F184, func_0201F198, func_0201F1B0, func_0201F1C8,
 *           func_0201F1E0, func_0201F230
 *
 * The second half of the wordset.c setter run, 0x0201F0F8..0x0201F250.
 * Every one of these is the same shape: clamp or range-check the caller's
 * value, then render one message id through func_0201EDD0.  The constants are
 * message ids and the ones above 255 (0x116, 0x11B, 0x1CD) arrive from the
 * function's own literal pool because Thumb's `movs` immediate stops at 255;
 * they are plain numbers, not relocations, which is the negative case of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * func_0201F184 clamps with a signed `blt`, so its value parameter is `s32`
 * while every other clamp in the file is an unsigned `bls`/`bhi`.
 *
 * func_0201F1E0 clears the slot unconditionally before the range check and
 * only overwrites it when the id is in range, so a caller with an
 * out-of-range id leaks the rendered string; that is what the bytes say and
 * it is reproduced here rather than tidied.
 *
 * The calls to func_0201ED64 are carried by the `matched` class through
 * src/matched/unit_0201ED04.c; all six of its callers are inside this packet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F0F8.c  *       --addr 0x0201F0F8 --thumb
 */
void func_0201F230(struct WordSet_0201F0F8 *p, u32 i, u32 v)
{
    if (v < 1) {
        v = 1;
    } else if (v > 0xC) {
        v = 0xC;
    }
    func_0201EDD0(p, i, 0x116, v - 1);
}


/*
 * wordset.c's message expander, 204 bytes.  It walks the source message a
 * halfword at a time and rewrites it into the destination buffer: an ordinary
 * character is copied straight through, a 0xF000 tag that is not a word
 * reference is copied verbatim halfword by halfword, and a word reference is
 * replaced by the stored word itself.
 *
 * The tag primitives it calls are the seven of src/matched/unit_0201D5C4.c:
 * func_0201D5C4 is the 0xF000 marker, func_0201D5CC says whether the tag is a
 * word reference, func_0201D670 reads parameter 0 (the word index),
 * func_0201D60C writes a new tag, and func_0201D688 steps the cursor past a
 * tag.  The word table hangs off the object at +8 and its entries are 0xC
 * bytes: a flag at +4 and the word's own message at +8.  When the flag is set
 * the expansion is bracketed by two freshly built 0xBD tags, kinds 6 and 4,
 * whose single parameter is the word index and the constant 0x54.
 *
 * Three details cost time:
 *
 *   - **The entry pointer is a named local for the first tag write and the
 *     written-out expression for the second.**  `&tbl[i]` must be bound to a
 *     local, because the two `strh`s into the parameter buffer sit between the
 *     flag test and the first write, and the buffer has its address taken, so
 *     re-reading `ws->unk08` after them costs a reload the original does not
 *     have.  Binding it for the *second* write as well is four bytes too long
 *     the other way: the local would then be live across func_0201D60C and the
 *     index has to be spilled.  The original recomputes the address from the
 *     two callee-saved registers it already holds, which is what writing the
 *     expression out gives.
 *   - **The character copies are `*p++`, not `p[0]` then `p++`.**  With the
 *     increment spelled separately the compiler sinks it past the call and
 *     then folds the loop-bottom re-read into the copy's own load; the
 *     function is four bytes short and the bottom of the loop is wrong.
 *   - **`q` is declared before `p`.**  The two cursors are the only locals
 *     live across the inner loop, and declaring `p` first swaps r4 and r5
 *     throughout (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * EXACT*: the two bytes after the epilogue are the unit's alignment padding
 * and 0x0201F31C, the next function, already carries a label.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201F250.c \
 *       --func func_0201F250 --addr 0x0201F250 --cc 1.1p1 --thumb
 */
void func_0201F250(struct WordSet_0201F250 *ws, void *dst, void *src)
{
    u16 buf[2];
    u32 term;
    u32 marker;
    u16 *q;
    u16 *p;
    u32 i;
    struct Entry_0201F250 *e;

    p = func_02045A90(src);
    func_0204581C(dst);
    term = func_02045A98();
    marker = func_0201D5C4();
    while (p[0] != term) {
        if (p[0] == marker) {
            if (func_0201D5CC(p) != 0) {
                i = func_0201D670(p, 0);
                e = &ws->unk08[i];
                if (e->unk04 != 0) {
                    buf[1] = (u16)i;
                    buf[0] = 0x54;
                    func_0201D60C(e->unk08, 0xBD, 6, 1, &buf[1]);
                    func_0201D60C(ws->unk08[i].unk08, 0xBD, 4, 1, &buf[0]);
                }
                func_0201F4A0(dst, ws->unk08[i].unk08);
                p = func_0201D688(p);
            } else {
                q = p;
                p = func_0201D688(p);
                while (q < p) {
                    func_02045AFC(dst, *q++);
                }
            }
        } else {
            func_02045AFC(dst, *p++);
        }
    }
}


/*
 * The wordset.c "clear every slot" walk and the one-line initialiser that
 * fills the file-scope template string at 0x020A7370.  That pointer is loaded
 * by func_0201EE60 in src/matched/unit_0201ED04.c and by seven functions
 * outside this region, so the `literal` class has witnesses to spare.
 *
 * func_0201F344 takes its heap id as a u16: the 4th argument of
 * func_02045B38 is a u16 and the original passes the incoming register
 * straight through with no `lsls`/`lsrs` truncation pair, which a u32
 * parameter would have cost.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F31C.c  *       --addr 0x0201F31C --thumb
 */
void func_0201F31C(struct WordSet_0201F31C *p)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        func_0204581C(p->entries[i].str);
    }
}

/*
 * The wordset.c "clear every slot" walk and the one-line initialiser that
 * fills the file-scope template string at 0x020A7370.  That pointer is loaded
 * by func_0201EE60 in src/matched/unit_0201ED04.c and by seven functions
 * outside this region, so the `literal` class has witnesses to spare.
 *
 * func_0201F344 takes its heap id as a u16: the 4th argument of
 * func_02045B38 is a u16 and the original passes the incoming register
 * straight through with no `lsls`/`lsrs` truncation pair, which a u32
 * parameter would have cost.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F31C.c  *       --addr 0x0201F31C --thumb
 */
void func_0201F344(u16 heap)
{
    unk_020A7370 = func_02045B38(0, 2, 0x46, heap);
}


/*
 *           The three data pool words -- g_0209E784, g_0209E758, g_0209E838 -- have no
 *           witness outside 0201F35C..0201F41C: each address appears in exactly one
 *           literal pool image-wide, this function's own, so the 'literal' class has
 *           nothing to offer and no other matched entry names them. A second reader of
 *           any of the three tables would release this file to EXACT.
 */
void func_0201F35C(void *ctx, s32_0201F35C n, u32 kind, u32 mode, u32 flag)
{
    u16 *tbl;
    u32 d;
    u32 q;

    if (flag == 0) {
        tbl = g_0209E784;
    } else {
        tbl = g_0209E758;
    }
    func_0204581C(ctx);

    if ((u16)(n < 0) != 0) {
        u32 ch;
        s32_0201F35C neg = ~0;
        n = neg * n;
        if (flag == 0) {
            ch = 0x30FC;
        } else {
            ch = 0x2D;
        }
        func_02045AFC(ctx, (u16)ch);
    }

    d = g_0209E838[kind];
    while (d != 0) {
        q = _u32_div_f((u32)n, d);
        q = (u16)q;
        n = n - d * q;
        if (q >= 10) {
            q = 10;
        }
        if (mode == 2) {
            func_02045AFC(ctx, tbl[q]);
        } else if (q != 0 || d == 1) {
            mode = 2;
            func_02045AFC(ctx, tbl[q]);
        } else if (mode == 1) {
            u32 ch;
            if (flag == 0) {
                ch = 0x3000;
            } else {
                ch = 0x20;
            }
            func_02045AFC(ctx, (u16)ch);
        }
        d = _u32_div_f(d, 10);
    }
}


/*
 * Decimal number printer.  func_0204581C(ctx) resets the glyph writer;
 * func_02045AFC(ctx, u16) emits one glyph; _u32_div_f is the mwccarm
 * integer-division helper (docs/idioms/runtime-helper-reloc.md).
 *
 * `flag` selects one of two glyph tables (0x0209E784 full-width,
 * 0x0209E758 half-width) and the matching minus / space glyphs
 * (0x30FC vs 0x2D, 0x3000 vs 0x20): this is the full-width/half-width
 * font pair, not a version-specific table.
 *
 * Two idioms carried the last four bytes: the negation is `~0 * n`, not
 * `-n` (which compiles to `rsbs`), and the remainder is `n - d * q`, not
 * `n - q * d` (docs/idioms/commutative-operand-order-names-the-temporary.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201F35C.c \
 *       --func func_0201F35C --addr 0x0201F35C --cc 1.1p1 --thumb
 */


/*
 * Two wide-string helpers.  func_0201F41C is a bounded copy that always
 * terminates the destination; func_0201F448 is an equality test.  Both read
 * the terminator character from func_02045A98 rather than from a constant,
 * and both hold it in a named local, which is what puts the call result in
 * the left slot of func_0201F41C's `cmp r0, r1`
 * (docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * The last store of func_0201F41C is `*(dst + n - 1) = eos`, not
 * `dst[n - 1] = eos`.  The two are the same value and different code: the
 * subscript form folds the subtraction into the index and scales once
 * (`subs`/`lsls`/`strh` with a register offset), while the pointer form
 * scales `n`, adds it to the base and then subtracts the element size
 * (`lsls`/`adds`/`subs #2`/`strh`).  Seven bytes, and nothing else in the
 * function moves; see
 * docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F41C.c  *       --addr 0x0201F41C --thumb
 */
void func_0201F41C(const u16 *src, u16 *dst, u32 n)
{
    u16 eos = func_02045A98();
    u32 i;

    for (i = 0; i < n; i++) {
        dst[i] = src[i];
        if (eos == src[i]) {
            break;
        }
    }
    *(dst + n - 1) = eos;
}


/*
 * Two wide-string helpers.  func_0201F41C is a bounded copy that always
 * terminates the destination; func_0201F448 is an equality test.  Both read
 * the terminator character from func_02045A98 rather than from a constant,
 * and both hold it in a named local, which is what puts the call result in
 * the left slot of func_0201F41C's `cmp r0, r1`
 * (docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * The last store of func_0201F41C is `*(dst + n - 1) = eos`, not
 * `dst[n - 1] = eos`.  The two are the same value and different code: the
 * subscript form folds the subtraction into the index and scales once
 * (`subs`/`lsls`/`strh` with a register offset), while the pointer form
 * scales `n`, adds it to the base and then subtracts the element size
 * (`lsls`/`adds`/`subs #2`/`strh`).  Seven bytes, and nothing else in the
 * function moves; see
 * docs/idioms/pointer-minus-one-scales-before-the-subtraction.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F41C.c  *       --addr 0x0201F41C --thumb
 */
u32 func_0201F448(const u16 *a, const u16 *b)
{
    u16 eos = func_02045A98();

    while (*a != eos) {
        if (*a != *b) {
            return 0;
        }
        a++;
        b++;
    }
    if (*b != eos) {
        return 0;
    }
    return 1;
}


/*
 * "Is this string a packed nine-bit run", the predicate func_0201F4A0 tests
 * before unpacking.  A non-empty string whose first character is 0xF100 is
 * one; the marker is materialised as `movs r0, #0xF1` / `lsls r0, #8` rather
 * than from a pool word, so it is a plain constant.
 *
 * The two tests share one `movs r0, #0; pop` exit and neither jumps over an
 * inline epilogue, which is the single-conjunction shape of
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md:
 * written as two separate early returns the function grows a second epilogue.
 *
 * This is its own file rather than part of src/pending/sub_0201F4A0.c
 * because func_0201F4A0 holds the only call to it in the image.  Matched
 * apart, that call is an ordinary `label` witness from outside this range,
 * and the `matched` class then carries the site in func_0201F4A0 itself.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F47C.c \
 *       --addr 0x0201F47C --thumb
 */
u32 func_0201F47C(void *s)
{
    if (func_020458F8(s) != 0 && *func_02045A90(s) == 0xF100) {
        return 1;
    }
    return 0;
}


/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * The nine-bit unpacker.  A string whose first character is 0xF100
 * (func_0201F47C, src/matched/unit_0201F47C.c) carries its text as a run of
 * nine-bit codes packed into the halfwords after the marker; this walks them
 * and appends one character at a time to the destination.  0x1FF is the
 * terminator as well as the field mask, codes 0x100..0x131 are translated
 * through a 16-bit table and anything at or above 0x132 becomes 0x3F, '?'.
 *
 * Every concrete byte is reproduced.  The one unresolved relocation is the
 * table address 0x0209E864, and the pool word inside this function is the
 * only word in the image that holds it, so the `literal` class discards its
 * only witness and no cut helps.  Expressing the address as an offset from
 * func_0201F35C's nearby table would resolve it, but that is a claim that the
 * two are one object and the image does not say so.
 *
 * Three details cost time and are worth keeping:
 *
 *  - the bit cursor is signed.  `cmp r5, #0x10` / `blt` is a signed compare
 *    even though the value is never negative, so the local is `s32`; `u32`
 *    gives `blo` and one wrong byte.
 *  - the two range limits and the table bias live in a local aggregate, not
 *    in scalars.  Each of the two limits is stored twice, once as 0x1FF and
 *    once as 0x1FF - 0xCD, because mwccarm's value numbering follows a scalar
 *    local but stops at a member of an aggregate; written as scalars the
 *    constants fold and six instructions disappear.  That is
 *    docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md seen
 *    from the assignment side rather than the test side.
 *  - the unpacking loop is the fall-through arm and the plain-string copy is
 *    the `else`.  Written as an early return for the plain case the copy is
 *    emitted first and every branch in the function moves
 *    (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/sub_0201F4A0.c  *       --addr 0x0201F4A0 --thumb
 */
void func_0201F4A0(void *dest, void *src)
{
    u32 mask = 0x1FF;
    struct Lim lim;
    const u16 *p;
    s32_0201F4A0 bit;
    u16 v;

    if (func_0201F47C(src) != 0) {
        p = func_02045A90(src) + 1;
        lim.hi = mask;
        lim.hi -= 0xCD;
        lim.hi2 = mask;
        lim.hi2 -= 0xCD;
        lim.bias = mask + 1;
        bit = 0;
        for (;;) {
            v = (*p >> bit) & mask;
            bit += 9;
            if (bit >= 16) {
                p++;
                bit -= 16;
                if (bit != 0) {
                    v |= (*p << (9 - bit)) & mask;
                }
            }
            if (v == mask) {
                return;
            }
            if (v >= 0x100 && v < lim.hi) {
                v = *(const u16 *)((const u8 *)&func_0201F4A0_Table[v]
                                   - lim.bias);
            } else if (v >= lim.hi2) {
                v = 0x3F;
            }
            func_02045AFC(dest, v);
        }
    } else {
        func_02045AA8(dest, src);
    }
}
