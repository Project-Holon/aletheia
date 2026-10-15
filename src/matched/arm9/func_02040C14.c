/*
 * unit:     no
 * function: BG_SYS_Init
 * address:  0x02040C14
 * packet:   pkt_02040B94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   g_020A7E5C     0x020A7E5C  data
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020341F0  0x020341F0  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   BG_SYS_LoadTileLayerEx  0x020425B4  arm
 *
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
 *   python tools/match.py one --src src/matched/BG_SYS_Init.c \
 *       --func BG_SYS_Init --addr 0x02040C14 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u16 heapId;
    u8  pad_02[0x1d];
    u8  depth;
    u8  pad_20[0xc];
};

struct BgSys {
    struct Slot slots[8];
    u8    pad_160[8];
    void *unk_168;
    void *unk_16c;
    u32   unk_170[8];
};

extern struct BgSys *g_02146A44;
extern char g_020A7E5C[];

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern u32 func_020307B0(void *p);
typedef signed int     s32;
struct AreaMan;
extern s32 func_020341F0(struct AreaMan *p, u32 start, u32 len);
extern void  MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void  BG_SYS_LoadTileLayerEx(u32 layer, const void *src, u32 offset, u32 size);

void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index)
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
            u32           depth = p->slots[layer].depth;

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
            u32           depth = p->slots[layer].depth;

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

    size = count * g_02146A44->slots[layer].depth;
    buf  = GFL_HEAP_Alloc((u16)((g_02146A44->slots[0].heapId & 0x7fff) | 0x8000),
                        size, 0, g_020A7E5C, 1421);

    if (g_02146A44->slots[layer].depth == 0x20) {
        u32 t = value | (value << 4 | (value << 12 | value << 8));

        value = t | (t << 16);
    } else {
        value = value | (value << 8 | (value << 24 | value << 16));
    }

    MIi_CpuClearFast(value, buf, size);
    BG_SYS_LoadTileLayerEx((u8)layer, buf, index * g_02146A44->slots[layer].depth,
                  size);
    func_020307B0(buf);
}
