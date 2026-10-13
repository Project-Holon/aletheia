/*
 * unit:     no
 * function: APP_TASKMENU_CreateWindows
 * address:  0x02027A24
 * packet:   pkt_02027A24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_Create   0x020450F0  arm
 *   APP_TASKMENU_DrawWinFrame  0x020282D8  thumb
 *   func_02045770  0x02045770  arm
 *   PRINTSYS_PrintQueColor   0x0201C724  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Build the o->count BG layers of a multi-row menu, one per iteration: the
 * layer handle goes into o->layers[i], the per-row descriptor lives in the
 * 0xc-byte array at o->rows[i], and the same four-call teardown quartet that
 * APP_TASKMENU_WIN_CreateEx runs once per object runs once per layer here.
 *
 * The flag at +0x2c picks between a plain origin (+0x30, +0x31) and one
 * inset by +0x32 / (+0x33 * +0x24); both arms narrow to u8, which is what
 * keeps the two lsls/lsrs #0x18 pairs alive.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Cfg {
    u8  pad00[0x10];
    u32 f10;
    u32 f14;
};

struct Row {
    u32 f00;
    u16 f04;
    u8  pad06[8 - 6];
    u32 f08;
};

struct Glyph {
    u16 f00;
    u16 f02;
};

struct Obj {
    u8  pad00[0x18];
    u32 *layers;
    struct Row *rows;
    u8  pad20[0x24 - 0x20];
    u8  count;
    u8  pad25[0x2c - 0x25];
    u32 inset;
    u8  x0;
    u8  y0;
    u8  dx;
    u8  dy;
    struct Glyph *glyph;
};

extern u32   BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d,
                          u8 slot);
extern void  APP_TASKMENU_DrawWinFrame(u32 bg, struct Cfg *c, u32 d);
struct Descriptor;
extern void *func_02045770(struct Descriptor *bg);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void  BMP_WIN_TransferChars(struct Descriptor *bg);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void  func_02041B6C(u32 bit);

void APP_TASKMENU_CreateWindows(struct Obj *o, struct Cfg *cfg)
{
    u32 ox;
    u32 oy;
    u8  i;
    u32 bg;
    struct Row *rows;
    struct Row *row;

    if (o->inset == 0) {
        ox = o->x0;
        oy = o->y0;
    } else {
        ox = (u8)(o->x0 - o->dx);
        oy = (u8)(o->y0 - o->dy * o->count);
    }
    for (i = 0; i < o->count; i++) {
        o->layers[i] = BMP_WIN_Create((u8)o->glyph->f00, ox,
                                    (u8)(oy + i * o->dy), o->dx,
                                    o->dy, (u8)(o->glyph->f02 + 1), 1);
        APP_TASKMENU_DrawWinFrame(o->layers[i], cfg, o->rows[i].f08);
        rows = o->rows;
        row = &rows[i];
        PRINTSYS_PrintQueColor((void *)cfg->f14, (u32)func_02045770((struct Descriptor *)o->layers[i]), 0xa, 6,
                     rows[i].f00, cfg->f10, row->f04);
        bg = o->layers[i];
        BMP_WIN_TransferChars((struct Descriptor *)bg);
        BMP_WIN_MakeScreen((struct Cfg *)bg);
        func_02041B6C(func_02045730((struct Descriptor *)bg));
    }
}
