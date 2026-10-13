/*
 * function: APP_TASKMENU_DrawWinFrame
 * address:  0x020282D8
 * packet:   pkt_02028084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *
 * app_taskmenu.c: paints a window frame into the BG's tilemap.  Walks the
 * layer's rows (BMP_WIN_GetHeight) and columns (BMP_WIN_GetWidth) and, per 0x20-byte
 * tile, classifies the cell as one of eleven kinds -- four corners, three
 * edges, two style-dependent inner columns, the plain interior -- and copies
 * the matching tile out of the template's tile bank (cfg->f04->f14) into the
 * layer's tile memory.
 *
 * Two shape notes, both worth a byte each:
 *  - Both loops are a top guard plus a bottom back-edge (`for (;;)` with the
 *    `x >= n` / `y >= n` test written out at both ends), not a plain `for`:
 *    the original's guards are `bhi`/`bhs` on the freshly-called bound and
 *    the two back-edges land on 0x02028312 and 0x02028304, which a `for` does
 *    not reproduce (366 bytes, 291 wrong).  The row loop's `x = 0` sits after
 *    the row guard, which is what the `goto nextrow` preserves.
 *  - `rowbase` must be DECLARED BEFORE `dst`: the two are the only spilled
 *    locals and they take sp+0xc and sp+0x10 in declaration order, the later
 *    declaration at the lower address (docs/idioms/local-declaration-order-is-stack-order.md).
 *    The wrong order is otherwise byte-perfect and reads as exactly 4 bytes
 *    out, two stores and two loads with the slots swapped.
 *
 * EXACT*: the compiled body is 354 bytes and the listing's inferred extent is
 * 356 -- the follower at 0x0202843C has no label, so the extent ran two bytes
 * long over the alignment padding.  Not a byte difference.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Cfg {
    u32 pad00;
    struct { u8 pad[0x14]; u32 f14; } *f04;
};

struct Bmp;
struct Descriptor;
extern u8 BMP_WIN_GetHeight(struct Descriptor *p);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *bg);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 n);

void APP_TASKMENU_DrawWinFrame(u32 bg, struct Cfg *cfg, u32 style)
{
    u8  y;
    u8  x;
    u32 rowbase;
    u32 dst;
    u32 tEdgeB;
    u32 tEdgeA;
    u32 src;
    u32 t;

    y = 0;
    if (y >= BMP_WIN_GetHeight((struct Descriptor *)bg)) {
        return;
    }
    t = style - 1;
    tEdgeB = (t + t * 2 + 9) << 5;
    tEdgeA = (t + t * 2 + 10) << 5;
    for (;;) {
        x = 0;
        if (x >= BMP_WIN_GetWidth((struct Descriptor *)bg)) {
            goto nextrow;
        }
        for (;;) {
        dst = (u32)BMP_GetPixels((const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)bg)));
        rowbase = (x + y * BMP_WIN_GetWidth((struct Descriptor *)bg)) << 5;
        if (y == 0 && x == 0) {
            src = cfg->f04->f14;
        } else if (y == 0 && x == BMP_WIN_GetWidth((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + 0x40;
        } else if (y == 0) {
            src = cfg->f04->f14 + 0x20;
        } else if (y == BMP_WIN_GetHeight((struct Descriptor *)bg) - 1 && x == 0) {
            src = cfg->f04->f14 + 0xc0;
        } else if (y == BMP_WIN_GetHeight((struct Descriptor *)bg) - 1 && x == BMP_WIN_GetWidth((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + (1 << 8);
        } else if (y == BMP_WIN_GetHeight((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + 0xe0;
        } else if (style != 0 && x == BMP_WIN_GetWidth((struct Descriptor *)bg) - 3) {
            src = cfg->f04->f14 + tEdgeB;
        } else if (style != 0 && x == BMP_WIN_GetWidth((struct Descriptor *)bg) - 2) {
            src = cfg->f04->f14 + tEdgeA;
        } else if (x == 0) {
            src = cfg->f04->f14 + 0x60;
        } else if (x == BMP_WIN_GetWidth((struct Descriptor *)bg) - 1) {
            src = cfg->f04->f14 + 0xa0;
        } else {
            src = cfg->f04->f14 + 0x80;
        }
        MIi_CpuCopy32((const void *)src, (void *)(dst + rowbase), 0x20);
            x++;
            if (x >= BMP_WIN_GetWidth((struct Descriptor *)bg)) {
                break;
            }
        }
nextrow:
        y++;
        if (y >= BMP_WIN_GetHeight((struct Descriptor *)bg)) {
            return;
        }
    }
}
