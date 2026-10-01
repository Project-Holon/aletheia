/*
 * function: func_022064CC
 * address:  0x022064CC
 * packet:   pkt_ov094_022064CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: one swapped pair. Case 5's block (shared by cases 2 and 3
 * through cross-jumping) is `ldrb x; ldrb y; strh x; strh y` in the
 * original but `ldrb x; strh x; ldrb y; strh y` here (cases 0/1 interleave in
 * both). Tried: y before x, comma form, u16 Point, const/struct entries,
 * a Point pointer (that moves r5 setup). Everything else is identical.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef struct Point { s16 x, y; } Point;
typedef struct { void *h; int x; } Slot;
typedef struct {
    char p0[0x68];
    u32 b0 : 5;
    u32 sel : 4;
    u32 rest : 23;
    char p6c[0x180 - 0x6c];
    Slot slots[6];
    char p1b0[0x274 - 0x1b0];
    u8 *f274;
} W;
extern void func_0204B3DC(void *, int);
extern void func_0204B404(void *, Point *, int);

void func_022064CC(W *p, u8 (*tab)[4], s8 (*rows)[12])
{
    Point pos;
    u8 *e;
    int k;
    int i;

    for (i = 0; i < 6; i++) {
        k = rows[p->sel][i];
        if (k >= 0) {
            e = tab[k];
            switch (i) {
            case 0:
                pos.x = e[2];
                pos.y = e[0];
                break;
            case 1:
                pos.x = e[3];
                pos.y = e[0];
                break;
            case 2:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 3:
                pos.x = e[3];
                pos.y = e[1];
                break;
            case 4:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 5:
                pos.x = e[3];
                pos.y = e[1];
                break;
            }
            func_0204B3DC(p->slots[i].h, *p->f274);
            func_0204B404(p->slots[i].h, &pos, 1);
        } else {
            func_0204B3DC(p->slots[i].h, 0);
        }
    }
}
