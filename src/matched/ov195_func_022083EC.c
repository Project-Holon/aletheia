/*
 * function: func_022083EC
 * address:  0x022083EC
 * packet:   pkt_022083EC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022081A4 0x022081A4 thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Fade {
    u8 f00[0x28];
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

extern void func_022081A4(Fade *p, int x, u16 color, s16 cur, s16 end, s16 wait, s16 step);

void func_022083EC(Fade *p, int x)
{
    p->state = 2;
    func_022081A4(p, x, 0x7fff, 0, 31, 0, 1);
}
