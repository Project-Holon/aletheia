/*
 * function: BMP_WIN_DrawFrame
 * address:  0x020454E0
 * packet:   pkt_020454E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_GetType  0x02041680  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *
 * The eight-piece frame around a window: base tile + 0..7 drawn at the
 * corners and edges one cell outside the on-screen extent (+7/+8), with the
 * palette nibble in the top of each cell unless the layer is 8bpp
 * (BG_SYS_GetType answers 1).
 *
 * Closed in wave 15 from a 2-byte residue (`mov r6, r2` against `mov r4,
 * r2`, the image gives pal and the palette bits one register).  Two facts,
 * each flat alone: the palette bits are computed IN PLACE in the pal
 * parameter as two compound statements (`pal &= 0xf; pal <<= 12;`), which
 * is what coalesces pal with its shifted value; and base is a u16
 * parameter (tile number), which restores the image's scheduling of the
 * sixth and seventh calls that the in-place form otherwise disturbs.  A
 * single-expression `pal = (pal & 0xf) << 12` or a separate pn local keeps
 * the 2-byte tie.  Found by tools/permuter.py hill (type:p base u32->u16)
 * from the in-place source.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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

extern u8 BG_SYS_GetType(int channel);
extern void BG_SYS_SetTileEntry(u32 index, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 m);

void BMP_WIN_DrawFrame(struct Cfg *cfg, u16 base, u32 pal)
{
    if (BG_SYS_GetType(cfg->unk_02) != 1) {
        pal &= 0xf;
        pal <<= 12;
    } else {
        pal = 0;
    }

    BG_SYS_SetTileEntry(cfg->unk_02, (u16)(pal | base), (u8)(cfg->unk_03 - 1),
                  (u8)(cfg->unk_04 - 1), 1, 1, 0x11);
    BG_SYS_SetTileEntry(cfg->unk_02, (u16)(pal | (base + 1)), cfg->unk_03,
                  (u8)(cfg->unk_04 - 1), cfg->unk_07, 1, 0x11);
    BG_SYS_SetTileEntry(cfg->unk_02, (u16)(pal | (base + 2)),
                  (u8)(cfg->unk_03 + cfg->unk_07), (u8)(cfg->unk_04 - 1),
                  1, 1, 0x11);
    BG_SYS_SetTileEntry(cfg->unk_02, (u16)(pal | (base + 3)),
                  (u8)(cfg->unk_03 - 1), cfg->unk_04, 1, cfg->unk_08, 0x11);
    BG_SYS_SetTileEntry(cfg->unk_02, (u16)(pal | (base + 4)),
                  (u8)(cfg->unk_03 + cfg->unk_07), cfg->unk_04,
                  1, cfg->unk_08, 0x11);
    BG_SYS_SetTileEntry(cfg->unk_02, (u16)(pal | (base + 5)),
                  (u8)(cfg->unk_03 - 1), (u8)(cfg->unk_04 + cfg->unk_08),
                  1, 1, 0x11);
    BG_SYS_SetTileEntry(cfg->unk_02, (u16)(pal | (base + 6)), cfg->unk_03,
                  (u8)(cfg->unk_04 + cfg->unk_08), cfg->unk_07, 1, 0x11);
    BG_SYS_SetTileEntry(cfg->unk_02, (u16)(pal | (base + 7)),
                  (u8)(cfg->unk_03 + cfg->unk_07),
                  (u8)(cfg->unk_04 + cfg->unk_08), 1, 1, 0x11);
}
