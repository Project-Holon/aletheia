/*
 * function: func_022079C0
 * address:  0x022079C0
 * packet:   pkt_ov094_022079C0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AAD0  0x0220AAD0  data  ov094  a2
 *   d_0220AAC0  0x0220AAC0  data  ov094  a2
 *   d_0220AAD8  0x0220AAD8  data  ov094  a2
 *   d_0220AB0C  0x0220AB0C  data  ov094  a2
 *   d_0220AB2C  0x0220AB2C  data  ov094  a2
 */

typedef short s16;
typedef struct Point { s16 x, y; } Point;
typedef struct { Point p[2]; } P2;
typedef struct { Point p[6]; } P6;
typedef struct { Point p[8]; } P8;
typedef struct {
    void *h0;
    void *h1;
    void *h2;
    char pc[0x10 - 0xc];
    void *h4;
    void *h3;
    char p18[0x40 - 0x18];
    int state;
    char p44[0x80 - 0x44];
} Ent;
typedef struct {
    char p0[0x40];
    Ent e[1];
} W;
extern const P2 d_0220AAD0;
extern const P2 d_0220AAC0;
extern const P6 d_0220AAD8;
extern const P8 d_0220AB0C;
extern const P8 d_0220AB2C;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void func_022079C0(W *p, int i, Point *off)
{
    P6 tC;
    P8 tD;
    P8 tE;
    Point pos;
    P2 tA;
    P2 tB;
    int x;
    int y;

    tA = d_0220AAD0;
    tB = d_0220AAC0;
    tC = d_0220AAD8;
    tD = d_0220AB0C;
    tE = d_0220AB2C;
    if (p->e[i].state == 2) {
        x = tD.p[i].x;
        y = tD.p[i].y;
    } else if (p->e[i].state == 3) {
        x = tE.p[i].x;
        y = tE.p[i].y;
    } else {
        x = tC.p[i].x;
        y = tC.p[i].y;
    }
    if (off != 0) {
        x += off->x;
        y += off->y;
    }
    pos.x = x;
    pos.y = y;
    func_0204B404(p->e[i].h0, (const struct Vec2 *)(&pos), 0);
    if ((i & 1) == 0 && p->e[i].state == 0) {
        pos.x = x + 16;
        pos.y = y + 13;
        func_0204B404(p->e[i].h1, (const struct Vec2 *)(&pos), 0);
    } else if ((i & 1) == 0 && p->e[i].state != 1) {
        pos.x = x + 16;
        pos.y = y + 7;
        func_0204B404(p->e[i].h1, (const struct Vec2 *)(&pos), 0);
    }
    pos.x = x + tA.p[i & 1].x;
    pos.y = y + tA.p[i & 1].y;
    func_0204B404(p->e[i].h2, (const struct Vec2 *)(&pos), 0);
    pos.x = x + tB.p[i & 1].x;
    pos.y = y + tB.p[i & 1].y;
    func_0204B404(p->e[i].h3, (const struct Vec2 *)(&pos), 0);
    if (p->e[i].h4 != 0) {
        pos.x = x + 8;
        pos.y = y + 21;
        func_0204B404(p->e[i].h4, (const struct Vec2 *)(&pos), 0);
    }
}
