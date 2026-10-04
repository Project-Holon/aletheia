/*
 * function: func_021FD104
 * address:  0x021FD104
 * packet:   pkt_021FD104
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   tbl_02203668   0x02203668  data  a4
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    u32 bg;
} WinDef;

typedef struct {
    u8 pad0[0xD40];
    u32 frame;
    u8 padD44[0xD50 - 0xD44];
    u32 side[2];
    u8 padD58[0xD90 - 0xD58];
    u32 win[16];
    u8 padDD0[0x12FC - 0xDD0];
    u32 flag;
} Menu;

extern const WinDef tbl_02203668[];

extern u32 func_020450F0(u8 bg, u8 x, u8 y, u8 w, u8 h, u8 pal, u16 base);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(u32 v);
extern u32 func_02045730(u32 v);
extern void func_02041B6C(u32 v);

void func_021FD104(Menu *p)
{
    int i;
    const WinDef *d;
    u32 v;

    p->frame = func_020450F0(4, 2, 0x13, 0x1b, 4, 1, 1);
    if (p->flag == 0) {
        p->side[0] = func_020450F0(4, 1, 0x15, 0xd, 2, 1, 1);
        p->side[1] = func_020450F0(4, 0x11, 0x15, 0xd, 2, 1, 1);
    }
    for (i = 0; i < 16; i++) {
        d = &tbl_02203668[i];
        if (d->bg == 2) {
            p->win[i] = func_020450F0(d->bg, d->x, d->y, d->w, d->h, 0xd, 1);
        } else {
            p->win[i] = func_020450F0(d->bg, d->x, d->y, d->w, d->h, 1, 1);
        }
        v = p->win[i];
        func_02045334((struct Descriptor *)v);
        func_02045374(v);
        func_02041B6C(func_02045730(v));
    }
}
