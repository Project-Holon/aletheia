/*
 * function: func_02040DA8
 * address:  0x02040DA8
 * packet:   pkt_02040DA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_0203422C  0x0203422C  arm
 *
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

typedef unsigned char u8;
typedef unsigned int  u32;

struct Slot { u8 pad_00[0x1f]; u8 depth; u8 pad_20[0xc]; };

struct Ctx {
    struct Slot slots[8];
    u8    pad_160[8];
    void *arena_a;
    void *arena_b;
    u32   base[8];
};

extern struct Ctx *g_02146A44;
typedef signed int     s32;
struct AreaMan;
extern void func_0203422C(struct AreaMan *p, u32 start, s32 len);

void func_02040DA8(u32 idx, u32 count, u32 tile)
{
    u32 unit;

    switch (idx) {
    case 0: case 1: case 2: case 3:
        unit = g_02146A44->slots[idx].depth;
        if (unit == 0x20) {
            func_0203422C(g_02146A44->arena_a,
                          (g_02146A44->base[idx] + tile * unit) >> 5, count);
        } else {
            func_0203422C(g_02146A44->arena_a,
                          (g_02146A44->base[idx] + tile * unit) >> 5, count * 2);
        }
        break;
    case 4: case 5: case 6: case 7:
        unit = g_02146A44->slots[idx].depth;
        if (unit == 0x20) {
            func_0203422C(g_02146A44->arena_b,
                          (g_02146A44->base[idx] + tile * unit) >> 5, count);
        } else {
            func_0203422C(g_02146A44->arena_b,
                          (g_02146A44->base[idx] + tile * unit) >> 5, count * 2);
        }
        break;
    }
}
