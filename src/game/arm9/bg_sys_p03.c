/*
 * file:     bg_sys_p03.c
 * unit:     yes
 * function: sub_02040860, sub_02040968, sub_020409B4, func_020409E0, func_02040AE0, func_02040AF0, func_02040B1C, func_02040B58, func_02040B94, func_02040C14, func_02040DA8, func_02040E78, func_02040EBC, func_02040EE0, func_02040F84, func_02041090, func_020410D0, func_020411E8, func_02041300, func_020413B0
 * address:  0x02040860
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by hand from the verified parts of tools/restructure.py.
 *
 * symbols:
 *   func_0207D59C  0x0207D59C  arm
 *   g_BgConfig     0x02146A44  data
 *   func_020834C0  0x020834C0  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02082A60  0x02082A60  arm
 *   gUnk_02146A44  0x02146A44  data
 *   g_02146A44     0x02146A44  data
 *   g_020A7E5C     0x020A7E5C  data
 *   sub_02030734   0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02040968  0x02040968  arm
 *   func_0204241C  0x0204241C  arm
 *   func_02042508  0x02042508  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020425B4  0x020425B4  arm
 *   func_020341F0  0x020341F0  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_0203422C  0x0203422C  arm
 *   func_020426A0  0x020426A0  arm
 *   func_020428E8  0x020428E8  arm
 *   func_02042B24  0x02042B24  arm
 *   func_02042D2C  0x02042D2C  arm
 *   func_02042E34  0x02042E34  arm
 *   func_02042ED8  0x02042ED8  arm
 *   func_020422D4  0x020422D4  arm
 */
#include "../../matched/include/Obj16005.h"

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed int         s32;
typedef signed short       s16;
typedef int                BOOL;

struct AreaMan;
struct Mtx22;

struct Bg {
    void *buf;
    u32   bufSize;
    u32   unk_08;
    u32   scrollX;
    u32   scrollY;
    u8    type;
    u8    unk_15;
    u8    unk_16;
    u8    unk_17;
    u16   unk_18;
    u16   unk_1a;
    u32   unk_1c;
    u32   unk_20;
    u32   unk_24;
    u32   unk_28;
};

struct BgSys {
    u16       heapId;
    u16       unk_02;
    u16       unk_04;
    u16       unk_06;
    struct Bg bgs[8];
    void     *unk_168;
    void     *unk_16c;
    u32       unk_170[8];
    u32       unk_190[8];
    u32       unk_1b0[8];
};

struct Mtx { u32 w[4]; };
struct BgConfigLayer {
    char pad_00[0x1C];
    u8 mode;
    char pad_1D[0x0F];
};
struct BgCnt { u16 prio : 2; u16 rest : 14; };
struct Param {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
};

extern struct BgSys *g_02146A44;
extern char g_020A7E5C[];

void sub_02040860(u32 layer, u32 a, u32 b, u32 c);
void sub_02040968(void *dest, const void *src, u32 size);
void sub_020409B4(u32 index);
void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
void func_02040AE0(u32 index, const void *src, u32 mode);
void func_02040AF0(u32 index, const void *src, u32 mode, u32 offset);
void func_02040B1C(int index, const void *src, u32 size, u32 tile);
u32 func_02040B58(u32 index, const void *src, u32 size);
void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
void func_02040DA8(u32 idx, u32 count, u32 tile);
void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
void func_02040EBC(u32 a0, u32 a1);
u16 func_02040EE0(int x, int y, u32 code);
u16 func_02040F84(u32 x, u32 y, u8 w, u32 h);
void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6,
                   u8 a7, u8 a8, u8 a9);
void func_020411E8(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6,
                   u8 a7, u8 a8, u8 a9);
void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_0207D59C(void *reg, u32 a, u32 b, u32 c, u32 x, u32 y);
extern void func_020834C0(void *dest, const void *src, u32 size);
extern void func_02082A90(void *dest, const void *src, u32 size);
extern void func_02082A60(void *dest, const void *src, u32 size);
typedef unsigned int u8_unused;
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02040968(const void *src, void *dst, u32 mode);
extern void func_0204241C(u32 index, const void *src, u32 offset, u32 size);
extern char g_020A7E5C[];
extern void func_02042508(u32 index, const u32 *src, u32 mode, u32 size);
struct AreaMan;
extern u32 func_0203FA08(u32 index, u32 size, u32 flag);
extern void  func_02082BCC(void *dst, u32 value, u32 size);
extern void  func_020425B4(u32 layer, const void *src, u32 offset, u32 size);
extern s32 func_020341F0(struct AreaMan *p, u32 start, u32 len);
extern void  func_02082AC0(u32 value, void *dst, u32 size);
extern void func_0203422C(struct AreaMan *p, u32 start, s32 len);
extern void func_020862F0(void *, u32);
extern void func_0207E3D0(void *, u32, u32);
extern void func_0207E468(void *, u32, u32);
extern void func_020426A0(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9, u32 a10);
extern void func_020428E8(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9, u32 a10);
extern void func_02042B24(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9, u32 a10);
extern void func_02042D2C(void *p, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02042E34(void *p, u8 a1, int a2, int a3, u8 a4, u8 a5);
extern void func_02042ED8(void *p, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020422D4(u32 mode, u8 *a, u8 *b);

/*
 * The affine half of the BG scroll module: push a layer's transform, plus
 * its current scroll position, into that layer's hardware parameter block.
 * Only the four affine-capable layers have one, so only cases 2, 3, 6 and 7
 * do anything: main engine BG2 and BG3 at 0x04000020 and 0x04000030, sub
 * engine BG2 and BG3 at 0x04001020 and 0x04001030.  Cases 0, 1, 4, 5 and
 * everything above 7 share the exit.
 *
 * The empty arms are load-bearing, not decoration: the dense jump table
 * only exists because the case labels run from 0 without gaps
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).  Written as
 * four cases the compiler would emit a comparison chain instead.
 *
 * Unlike sub_02040618, the subscript here stays the variable `layer` in
 * every arm rather than the arm's own case constant.  That is what the
 * `mla lr, r0, ip, lr` inside each arm says: the multiply is still live,
 * so the index cannot have been a literal.  The four arms therefore differ
 * only in one pooled register address, which is also why all four share the
 * single 0x02146A44 pool word at the end of the function.
 *
 * The transform arguments are this function's own parameters 2 to 4, passed
 * straight through untouched (nothing in any arm writes r1, r2 or r3), and
 * the scroll pair goes on the stack as arguments 5 and 6.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02040860.c \
 *       --func sub_02040860 --addr 0x02040860 --cc 1.1p1 --arm
 */
void sub_02040860(u32 layer, u32 a, u32 b, u32 c)
{
    switch (layer) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        func_0207D59C((void *)0x04000020, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    case 3:
        func_0207D59C((void *)0x04000030, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        func_0207D59C((void *)0x04001020, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    case 7:
        func_0207D59C((void *)0x04001030, a, b, c,
                      g_02146A44->bgs[layer].scrollX, g_02146A44->bgs[layer].scrollY);
        break;
    }
}

void sub_02040968(void *dest, const void *src, u32 size)
{
    if (size == 0) {
        func_020834C0(dest, src, size);
        return;
    }

    if (((u32)dest & 3) == 0 && ((u32)src & 3) == 0 && ((u16)size % 4) == 0) {
        func_02082A90(dest, src, size);
        return;
    }

    func_02082A60(dest, src, size);
}

/*
 * Indexes the 0x2c-byte entry array reached through the pointer at
 * 0x02146A44 and tail-calls the worker at 0x020409E0 with three fields of
 * that entry plus the index itself.  The tail call is the usual pool word
 * and `bx ip`; ip rather than r3 is used so all four argument registers
 * survive.
 */
void sub_020409B4(u32 index)
{
    

    func_020409E0(index, g_02146A44->bgs[index].buf, g_02146A44->bgs[index].bufSize, g_02146A44->bgs[index].unk_08);
}

/*
 * Push a tile source into slot `index` of the 0x2c-byte table behind
 * 0x02146A44.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020409E0.c \
 *       --func func_020409E0 --addr 0x020409E0 --cc 1.1p1 --arm
 */
void func_020409E0(u32 index, const void *src, u32 mode, u32 offset)
{
    if (mode == 0) {
        void *tiles = g_02146A44->bgs[index].buf;

        if (tiles != 0) {
            func_02040968(src, tiles, mode);
            func_0204241C(index, tiles, g_02146A44->bgs[index].unk_08 * 2,
                          g_02146A44->bgs[index].bufSize);
        } else {
            u32   size = *(const u32 *)&((struct Obj16005 *)src)->f0 >> 8;
            void *buf = sub_02030734(
                (u16)((g_02146A44->heapId & 0x7fff) | 0x8000), size, 0,
                g_020A7E5C, 1252);

            func_02040968(src, buf, mode);
            func_0204241C(index, buf, offset * 2, size);
            func_020307B0(buf);
        }
    } else {
        func_0204241C(index, src, offset * 2, mode);
    }
}

/*
 * A four-instruction forwarder that binds the tile offset of func_02040AF0
 * to zero.  It has no label in the listing: the prologue saves nothing, so
 * disasm.py's rule does not see it and the whole function reads as part of
 * func_020409E0's literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  This is
 * also why func_020409E0 verifies EXACT*, its inferred extent running on
 * to 0x02040AF0; 0x02040AE0 wants seeding into
 * layout/function_starts.txt.
 *
 * The tail call is the usual pool word and `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), through ip rather than
 * r3 so the fourth argument register is still free to carry the zero
 * (docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040AE0.c \
 *       --func func_02040AE0 --addr 0x02040AE0 --cc 1.1p1 --arm
 */
void func_02040AE0(u32 index, const void *src, u32 mode)
{
    func_02040AF0(index, src, mode, 0);
}

/*
 * Decode a tile source straight into slot `index`'s tile buffer at a tile
 * offset.  The offset scales by two, so the buffer is addressed in
 * halfwords here even though func_020409E0 treats the same field as an
 * opaque destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040AF0.c \
 *       --func func_02040AF0 --addr 0x02040AF0 --cc 1.1p1 --arm
 */
void func_02040AF0(u32 index, const void *src, u32 mode, u32 offset)
{
    func_02040968(src, (u16 *)g_02146A44->bgs[index].buf + offset, mode);
}

/*
 * Forward a tile upload, scaling the destination tile index by the slot's
 * tile size: the byte at +0x1e of the 0x2c-byte slot record is zero for
 * 4bpp tiles (32 bytes each, shift 5) and non-zero for 8bpp (64 bytes,
 * shift 6).  The zero arm is the fall-through, so it is the `if` body
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040B1C.c \
 *       --func func_02040B1C --addr 0x02040B1C --cc 1.1p1 --arm
 */
void func_02040B1C(int index, const void *src, u32 size, u32 tile)
{
    if (g_02146A44->bgs[index].unk_16 == 0) {
        func_02042508(index, src, size, tile * 32);
    } else {
        func_02042508(index, src, size, tile * 64);
    }
}

/*
 * Reserve a run of tiles for slot `index`, then upload into it and hand the
 * caller the tile index it got.  The reservation is in tiles and the upload
 * offset in bytes, hence the fixed 32-byte (4bpp) scale; unlike
 * func_02040B1C this one does not consult the slot's depth byte.
 *
 * The `and r0, r7, #0xff` is the truncation at the second call, not a cast
 * in this function's own arithmetic: func_02042508 takes the slot index as
 * u8 while this function takes it as u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040B58.c \
 *       --func func_02040B58 --addr 0x02040B58 --cc 1.1p1 --arm
 */
u32 func_02040B58(u32 index, const void *src, u32 size)
{
    u32 tile = func_0203FA08(index, size, 0);

    func_02042508((u8)index, src, size, tile * 32);
    return tile;
}

/*
 * TU: bg_sys.c.
 *
 * Fill a run of the layer's tilemap with zeroes: take a scratch buffer of
 * `size` bytes off the heap (the heap id arrives as a plain argument here,
 * not out of the background system object, so it is masked and re-tagged the
 * same way the constructor's own allocation is), zero it, hand it to the
 * tilemap writer and release it again.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040B94.c \
 *       --func func_02040B94 --addr 0x02040B94 --cc 1.1p1 --arm
 */
void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId)
{
    void *buf = sub_02030734((u16)((heapId & 0x7fff) | 0x8000), size, 0,
                             g_020A7E5C, 1362);

    func_02082BCC(buf, 0, size);
    func_020425B4(layer, buf, offset, size);
    func_020307B0(buf);
}

/*
 * TU: bg_sys.c.
 *
 * Fill `count` tiles of layer `layer` starting at tile `index` with the
 * pixel value `value`.  The per-layer byte at +0x1f of the 0x2c-byte slot is
 * the tile stride: 0x20 for a 4bpp layer, anything else (0x40) for 8bpp.
 * The range is first reserved in the arena that owns the layer (+0x168 for
 * layers 0-3, +0x16c for 4-7, nothing at all for an out-of-range layer),
 * with both the offset and the length expressed in 32-byte units, then a
 * scratch buffer of count*stride bytes is filled with the replicated pixel
 * value and pushed to the layer.
 *
 * Two codegen notes.  The reserve arm must be spelled as an if/else with the
 * whole call written out in each arm, not as a ternary on the length
 * argument: the ternary hoists `count * 2` to the compare and cross-jumps the
 * `mla`, while the original shares only the `lsr` and the `bl`
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).  The two
 * pixel-replication chains have to be written right-associated with the two
 * operands of each inner pair reversed; see
 * docs/idioms/a-four-term-or-chain-is-right-associated-in-arm.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040C14.c \
 *       --func func_02040C14 --addr 0x02040C14 --cc 1.1p1 --arm
 */
void func_02040C14(u32 layer, u32 value, u32 count, u32 index)
{
    u32   size;
    void *buf;

    switch (layer) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            struct BgSys *p     = g_02146A44;
            u32           depth = p->bgs[layer].unk_17;

            if (depth == 0x20) {
                func_020341F0(p->unk_168,
                              (p->unk_170[layer] + index * depth) >> 5, count);
            } else {
                func_020341F0(p->unk_168,
                              (p->unk_170[layer] + index * depth) >> 5,
                              count * 2);
            }
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            struct BgSys *p     = g_02146A44;
            u32           depth = p->bgs[layer].unk_17;

            if (depth == 0x20) {
                func_020341F0(p->unk_16c,
                              (p->unk_170[layer] + index * depth) >> 5, count);
            } else {
                func_020341F0(p->unk_16c,
                              (p->unk_170[layer] + index * depth) >> 5,
                              count * 2);
            }
        }
        break;
    }

    size = count * g_02146A44->bgs[layer].unk_17;
    buf  = sub_02030734((u16)((g_02146A44->heapId & 0x7fff) | 0x8000),
                        size, 0, g_020A7E5C, 1421);

    if (g_02146A44->bgs[layer].unk_17 == 0x20) {
        u32 t = value | (value << 4 | (value << 12 | value << 8));

        value = t | (t << 16);
    } else {
        value = value | (value << 8 | (value << 24 | value << 16));
    }

    func_02082AC0(value, buf, size);
    func_020425B4((u8)layer, buf, index * g_02146A44->bgs[layer].unk_17,
                  size);
    func_020307B0(buf);
}

/*
 * bg_sys.c.  Release a run of tiles from one layer's arena.  The layer index
 * selects the arena (0-3 at +0x168, 4-7 at +0x16c, anything else a no-op) and
 * the slot's +0x1F bit-depth byte is both the multiplicand that turns a tile
 * index into a byte offset and the 0x20 test that doubles the count for the
 * 4bpp case.  The >> 5 is the arena's fixed 32-byte unit, not a division by
 * the depth.
 *
 * The declaration that closes this function is the depth byte's OFFSET: it is
 * +0x1F, not +0x1E.  Both bytes are live and independently read in this
 * family (func_02040B1C reads the +0x1E flag off the same 0x2C-stride
 * record); putting depth at +0x1E moves a live ldrb and loses the function.
 * See docs/families/bg_sys.h.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02040DA8.c \\
 *       --func func_02040DA8 --addr 0x02040DA8 --cc 1.1p1 --arm
 */
void func_02040DA8(u32 idx, u32 count, u32 tile)
{
    u32 unit;

    switch (idx) {
    case 0: case 1: case 2: case 3:
        unit = g_02146A44->bgs[idx].unk_17;
        if (unit == 0x20) {
            func_0203422C(g_02146A44->unk_168,
                          (g_02146A44->unk_170[idx] + tile * unit) >> 5, count);
        } else {
            func_0203422C(g_02146A44->unk_168,
                          (g_02146A44->unk_170[idx] + tile * unit) >> 5, count * 2);
        }
        break;
    case 4: case 5: case 6: case 7:
        unit = g_02146A44->bgs[idx].unk_17;
        if (unit == 0x20) {
            func_0203422C(g_02146A44->unk_16c,
                          (g_02146A44->unk_170[idx] + tile * unit) >> 5, count);
        } else {
            func_0203422C(g_02146A44->unk_16c,
                          (g_02146A44->unk_170[idx] + tile * unit) >> 5, count * 2);
        }
        break;
    }
}

void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4)
{
    func_020862F0(r6, r5);
    if (r7 < 4) {
        func_0207E3D0(r6, r4, r5);
    } else {
        func_0207E468(r6, r4, r5);
    }
}

void func_02040EBC(u32 a0, u32 a1)
{
    func_02040E78(a0, &a1, 2, 0);
}

/*
 * The (x, y) to linear screen-entry index helper the whole BG layer uses
 * (src/matched/sub_02042FB0.c and src/matched/func_020413B0.c are two of
 * its callers).  The third argument is the slot's screen-size code at +0x1d
 * of the 0x2c-byte slot record, and the six arms spell the DS BG screen
 * layouts out exactly:
 *
 *   0  256x256 text, one 32x32 map:      x + y * 32 is wrong, it is
 *                                        x + y * 16, i.e. a 16-wide map
 *   1  and 2                             x + y * 32, a 32-wide map
 *   3  512x256: the second 32x32 map follows the first, so the high bits
 *      of x select the map and the low five index inside it
 *   4  512x512: four 32x32 maps in a 2x2 grid, map index (y>>5)*2 + (x>>5)
 *      times 0x400 entries, plus (x & 31) + (y & 31) * 32 inside
 *   5  no map
 *
 * Everything is u16 arithmetic: case 4 truncates the scaled map index to
 * sixteen bits before adding the in-map offset, which is what the
 * `lsl #26` / `lsr #16` pair is, so the two partial results have to be u16
 * locals rather than one expression.
 *
 * x and y are signed (the shifts are `asr`, not `lsr`), and the switch has
 * no default arm at all: an out-of-range code falls straight out of the
 * dispatch to `bx lr` with x still in r0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040EE0.c \
 *       --func func_02040EE0 --addr 0x02040EE0 --cc 1.1p1 --arm
 */
u16 func_02040EE0(int x, int y, u32 code)
{
    u16 map;
    u16 off;

    switch (code) {
    case 0:
        return x + y * 16;
    case 1:
    case 2:
        return x + y * 32;
    case 3:
        return (x & 0x1f) + (y + (x & ~0x1f)) * 32;
    case 4:
        map = (y >> 5) * 2 + (x >> 5);
        off = (x & 0x1f) + (y & 0x1f) * 32;
        map = map * 0x400;
        return off + map;
    case 5:
        return 0;
    }
}

/*
 * The arbitrary-size cousin of src/matched/func_02040EE0.c: linear screen
 * entry index for (x, y) in a map that is `w` by `h` tiles, laid out as up to
 * four 32-wide/32-tall blocks.  The block is selected by `(x >> 5)` and
 * `(y >> 5)` folded into a single u8 selector, and the switch has cases 0..3
 * only, so the out-of-range dispatch falls straight through to `return base`
 * with base still zero.
 *
 * `w - 32` and `h - 32` are s16 locals, and they double as both the guard and
 * the stride of the right-hand and bottom blocks: a negative value means the
 * map is narrower (shorter) than one block, so block 0 uses `w` (`h`) as its
 * stride and the trailing blocks never exist.  Everything accumulates through
 * u16, which is what every `lsl #16` / `lsr #16` pair in the original is.
 *
 * Three shape notes, each of which cost bytes to find:
 *
 *  - `base += idx;` has to be written out inside both arms of the if/else in
 *    cases 0 and 2 (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *    Factored out after the if/else, the arms become one instruction each and
 *    the compiler if-converts them to `addge`/`mlalt`, which is four bytes
 *    shorter than the original's real branches.  Case 1's if/else really is
 *    predicated, and that is the contrast that names the shape.
 *  - `base` must be the first declaration, or it does not get ip
 *    (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 *    with w2 first the whole function comes out with ip, lr and r4 rotated.
 *  - but `base` must be *assigned* zero after `sel`, as a statement rather
 *    than an initialiser, because the original materialises the zero into
 *    sel's register and copies it into base's (`mov r6, #0` then
 *    `mov ip, r6`), not the other way round.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02040F84.c \
 *       --func func_02040F84 --addr 0x02040F84 --cc 1.1p1 --arm
 */
u16 func_02040F84(u32 x, u32 y, u8 w, u32 h)
{
    u16 base;
    s16 w2 = w - 32;
    s16 h2 = h - 32;
    u8  sel = 0;
    u16 idx;

    base = 0;

    if (x >> 5) {
        sel += 1;
    }
    if (y >> 5) {
        sel += 2;
    }

    switch (sel) {
    case 0:
        if (w2 >= 0) {
            idx = x + y * 32;
            base += idx;
        } else {
            idx = x + y * w;
            base += idx;
        }
        break;
    case 1:
        if (h2 >= 0) {
            base += 32 * 32;
        } else {
            base += h * 32;
        }
        idx = (x & 0x1f) + y * w2;
        base += idx;
        break;
    case 2:
        base += w * 32;
        if (w2 >= 0) {
            idx = x + (y & 0x1f) * 32;
            base += idx;
        } else {
            idx = x + (y & 0x1f) * w;
            base += idx;
        }
        break;
    case 3:
        base += (w + h2) * 32;
        idx = (x & 0x1f) + (y & 0x1f) * w2;
        base += idx;
        break;
    }
    return base;
}

/*
 * The short public entry point in front of src/matched/func_020410D0.c: it
 * drops the caller's second argument out of the register block, shifts the
 * third and fourth down into r1/r2, and rebuilds the ten-argument call with
 * the two u8 tail arguments duplicated and a pair of zeroes in between.
 *
 * Reading the callee's argument list back, this is the "no clip rectangle"
 * form: arguments 7 and 8 of func_020410D0 are the clip origin and are passed
 * as zero, while arguments 9 and 10 repeat the size pair given here, so the
 * clip box is the whole destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02041090.c \
 *       --func func_02041090 --addr 0x02041090 --cc 1.1p1 --arm
 */
void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5)
{
    func_020410D0(index, a2, a3, a4, a5, a1, 0, 0, a4, a5);
}

/*
 * The ten-argument sibling of src/pending/func_02041300.c: fan out on the
 * bit-depth byte at +0x1c of the 0x2c-byte slot behind 0x02146A44 and forward
 * the whole argument list, plus a trailing zero, to one of three blitters.
 * All three arms are byte-identical in their argument marshalling; only the
 * callee differs.
 *
 * The slot's sub-object pointer is spelled as byte arithmetic with the
 * constant added first and written out in every arm, for the reason recorded
 * in src/pending/func_02041300.c: `&g_02146A44[index].unk_08` contracts into
 * a single `mla` and loses twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020410D0.c \
 *       --func func_020410D0 --addr 0x020410D0 --cc 1.1p1 --arm
 */
void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6,
                   u8 a7, u8 a8, u8 a9)
{
    u8 kind = g_02146A44->bgs[index].type;

    if (kind == 0) {
        func_020426A0(&g_02146A44->bgs[index],
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 0);
    } else if (kind == 1) {
        func_020428E8(&g_02146A44->bgs[index],
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 0);
    } else {
        func_02042B24(&g_02146A44->bgs[index],
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 0);
    }
}

/*
 * The twin of src/matched/func_020410D0.c, differing only in the trailing
 * constant it appends to the blitter's argument list: 1 here, 0 there.  Fan
 * out on the bit-depth byte at +0x1c of the 0x2c-byte slot behind 0x02146A44
 * and forward the whole argument list to one of three blitters.  All three
 * arms are byte-identical in their argument marshalling; only the callee
 * differs.  The pair reads as a "transparent" flag threaded through the two
 * public entry points of the same fill.
 *
 * The slot's sub-object pointer is spelled as byte arithmetic with the
 * constant added first and written out in every arm, for the reason recorded
 * in src/pending/func_02041300.c: `&g_02146A44[index].unk_08` contracts into
 * a single `mla` and loses twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020411E8.c \
 *       --func func_020411E8 --addr 0x020411E8 --cc 1.1p1 --arm
 */
void func_020411E8(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6,
                   u8 a7, u8 a8, u8 a9)
{
    u8 kind = g_02146A44->bgs[index].type;

    if (kind == 0) {
        func_020426A0(&g_02146A44->bgs[index],
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 1);
    } else if (kind == 1) {
        func_020428E8(&g_02146A44->bgs[index],
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 1);
    } else {
        func_02042B24(&g_02146A44->bgs[index],
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 1);
    }
}

/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 */
void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6)
{
    u32 offset = layer * 0x2C;
    struct BgConfigLayer *bg = (struct BgConfigLayer *)((u8 *)g_02146A44 + offset);

    if (bg->mode == 0) {
        func_02042D2C((u8 *)g_02146A44 + 8 + offset, a1, a2, a3, a4, a5, a6);
    } else if (bg->mode == 1) {
        func_02042E34((u8 *)g_02146A44 + 8 + offset, (u8)a1, a2, a3, a4, a5);
    } else {
        func_02042ED8((u8 *)g_02146A44 + 8 + offset, a1, a2, a3, a4, a5, a6);
    }
}

/*
 * Recolour a rectangle of the screen buffer of table slot `index`: for every
 * tile entry in the (x0, y0, w, h) box, replace the palette nibble in bits
 * 12..15 with `pal` and leave the low twelve bits alone.
 *
 * func_020422D4 turns the slot's screen-size code at +0x1d into the layer's
 * width and height in tiles, returned through two u8 out-parameters; the
 * later declaration gets the lower stack address
 * (docs/idioms/local-declaration-order-is-stack-order.md), so `width` at
 * sp+9 has to be declared before `height` at sp+8.  The box is clipped
 * against those two: running off the right edge breaks the row, running off
 * the bottom returns outright.  func_02040EE0 is the same (x, y, size_code)
 * to linear-index helper src/matched/sub_02042FB0.c uses.
 *
 * Two loop-shape notes, each worth twelve bytes:
 *
 *  - The y bound must be only the `for` condition.  Writing the equivalent
 *    `if (y0 >= yEnd) return;` in front of the loop as well emits the
 *    predicated return twice: the compiler's own loop-rotation entry test
 *    already is that guard.
 *  - The x bound must stay an expression in the inner condition,
 *    `x < x0 + w`, not a local computed before the nest.  As an expression
 *    it is loop-invariant and gets hoisted into the outer loop's preheader,
 *    which is after the y guard; as a local it is computed before the guard,
 *    which is where the original does not have it.
 *
 * Both bounds are signed compares (bge/blt) because each is a sum of two u8
 * values and so has type int, while the two clip tests against width and
 * height are unsigned (bhs): there both sides are u8 and the front end knows
 * the range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020413B0.c \
 *       --func func_020413B0 --addr 0x020413B0 --cc 1.1p1 --arm
 */
void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal)
{
    u8   width;
    u8   height;
    u16 *screen;
    u8   x;
    int  yEnd;

    screen = (u16 *)g_02146A44->bgs[index].buf;
    if (screen == 0) {
        return;
    }

    func_020422D4(g_02146A44->bgs[index].unk_15, &width, &height);

    yEnd = y0 + h;

    for (; y0 < yEnd; y0++) {
        if (y0 >= height) {
            return;
        }
        for (x = x0; x < x0 + w; x++) {
            u32 i;

            if (x >= width) {
                break;
            }
            i = func_02040EE0(x, y0, g_02146A44->bgs[index].unk_15);
            screen[i] = (u16)((screen[i] & 0xfff) | (pal << 12));
        }
    }
}
