/*
 * function: sub_02045374
 * address:  0x02045374
 * packet:   pkt_02045374
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_02146A50     0x02146A50  data
 *   str_020A7E70   0x020A7E70  data
 *   func_02041680  0x02041680  arm
 *   func_02030734  0x02030734  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Fill a rectangle of the screen described by the configuration block with
 * a run of consecutive tile numbers.  func_02041680 says whether the layer
 * is 8bpp (answer 1, one byte per cell) or 16bpp (two bytes per cell, each
 * carrying the palette number from +9 in its top nibble); either way a
 * scratch buffer of w*h cells is allocated from the heap named by the word
 * behind 0x02146A50, filled with an increasing counter seeded from +0xa,
 * handed to func_020410D0 and freed again.
 *
 * The palette nibble is hoisted as `lsl r4, r2, #0x1c` before the branch
 * and consumed as `orr r2, r5, r4, lsr #16` inside the loop: that is one
 * `(x & 0xf) << 12`, split so that only the cheap half stays in the loop,
 * not two separate shifts.
 *
 * The two allocation sites carry different line numbers, 0x133 and 0x13e,
 * and that is load-bearing: give both the same constant and the compiler
 * hoists the single pool load above the branch, which costs one
 * instruction, one pool word and shifts every later pc-relative offset.
 * Eleven source lines apart matches the two arms of one if/else.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Cfg {
    u8  pad_00[2];
    u8  unk_02;
    u8  unk_03;
    u8  unk_04;
    u8  unk_05;
    u8  unk_06;
    u8  unk_07;
    u8  unk_08;
    u8  unk_09;
    u16 unk_0a;
};

extern u16 *g_02146A50;
extern const char str_020A7E70[];

extern u32 func_02041680(u32 layer);
extern void *func_02030734(u16 heap, u32 size, u32 flags, const char *file, u32 line);
extern void func_020410D0(u32 a, u32 b, u32 c, u32 d, u32 e, void *cells,
                          u32 f, u32 g, u32 w, u32 h);
extern void func_020307B0(void *p);

void sub_02045374(struct Cfg *cfg)
{
    u16 count = cfg->unk_05 * cfg->unk_06;
    u32 palette = (cfg->unk_09 & 0xf) << 12;
    u16 tile = cfg->unk_0a;
    void *cells;
    s32 i;

    if (func_02041680(cfg->unk_02) != 1) {
        u16 *p = func_02030734((u16)((*g_02146A50 & 0x7fff) | 0x8000),
                               count * 2, 0, str_020A7E70, 0x133);

        cells = p;
        for (i = 0; i < count; i++) {
            p[i] = tile | palette;
            tile = tile + 1;
        }
    } else {
        u8 *p = func_02030734((u16)((*g_02146A50 & 0x7fff) | 0x8000),
                              count, 0, str_020A7E70, 0x13e);

        cells = p;
        for (i = 0; i < count; i++) {
            p[i] = (u8)tile;
            tile = tile + 1;
        }
    }

    func_020410D0(cfg->unk_02, cfg->unk_03, cfg->unk_04, cfg->unk_07,
                  cfg->unk_08, cells, 0, 0, cfg->unk_05, cfg->unk_06);
    func_020307B0(cells);
}
