/*
 * function: func_022082DC
 * address:  0x022082DC
 * packet:   pkt_022082DC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02061CA4 0x02061CA4 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Fade {
    u8 f00[4];
    char *f04;
    u8 f08[0x10];
    u32 f18;
    u8 f1c[0xc];
    int state;
    u16 pal[16];
    u16 color;
    s16 cur;
    s16 end;
    s16 wait;
    s16 step;
    s16 level;
    s16 count;
} Fade;

extern void func_02061CA4(int, u32, void *, int);

void func_022082DC(Fade *p)
{
    u16 *src = *(u16 **)(p->f04 + 0xc);
    u8 i;
    s16 tr, tg, tb;
    s16 r, g, b;
    s16 level;

    tr = (s16)(p->color & 0x1f);
    tg = (s16)((p->color & 0x3e0) >> 5);
    tb = (s16)((p->color & 0x7c00) >> 10);

    for (i = 1; i < 16; i++) {
        r = (s16)(src[i] & 0x1f);
        g = (s16)((src[i] & 0x3e0) >> 5);
        b = (s16)((src[i] & 0x7c00) >> 10);
        level = p->level;
        if (level == 31) {
            r = tr;
            g = tg;
            b = tb;
        } else {
            r = (s16)(r + ((tr - r) * level >> 5));
            g = (s16)(g + ((tg - g) * level >> 5));
            b = (s16)(b + ((tb - b) * level >> 5));
            r = r > 31 ? 31 : (r < 0 ? 0 : r);
            g = g > 31 ? 31 : (g < 0 ? 0 : g);
            b = b > 31 ? 31 : (b < 0 ? 0 : b);
        }
        p->pal[i] = r | (g << 5) | (b << 10);
    }
    func_02061CA4(1, p->f18, p->pal, 0x20);
}
