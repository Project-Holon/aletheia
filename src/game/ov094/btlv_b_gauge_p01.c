/*
 * file:     btlv_b_gauge_p01.c
 * unit:     yes
 * function: func_022079C0, func_02207B4C, func_02207B68, func_02207B84, func_02207BAC
 * address:  0x022079C0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220AAD0  0x0220AAD0  data  ov094  a2
 *   d_0220AAC0  0x0220AAC0  data  ov094  a2
 *   d_0220AAD8  0x0220AAD8  data  ov094  a2
 *   d_0220AB0C  0x0220AB0C  data  ov094  a2
 *   d_0220AB2C  0x0220AB2C  data  ov094  a2
 *   func_02207DA0 0x02207DA0 thumb ov094
 *   func_02207EA8  0x02207EA8  thumb  ov094
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_02018584 0x02018584 thumb
 */
struct Obj;
struct Vec2;
struct S;
struct QF;
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
} W_022079C0;

typedef unsigned int   u32;

typedef struct {
    char pad[0x70];
    u32 a : 8;
    u32 b : 8;
    u32 c : 12;
    u32 d : 1;
    u32 e : 3;
    char pad2[0x80 - 0x74];
} E_02207B84;

typedef struct {
    char pad[0x40];
    E_02207B84 e[1];
} W_02207B84;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    char p0[0x48];
    int f48, f4c, f50, f54, f58, f5c;
    char p60[8];
    int f68;
    u8 f6c;
    char p6d[3];
    u32 lo : 2;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 f4 : 4;
    u32 f8 : 8;
    u32 mid : 12;
    u32 b28 : 1;
    u32 hi : 3;
    char p74[12];
} E_02207BAC;

typedef struct { char pad[0x40]; E_02207BAC e[8]; } O;

extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_02207DA0(void *obj, struct S *q, int n);
extern void func_02207EA8(struct S *p, int a);
extern int func_021D59B4(u8 *p, int k);
extern u16 func_021D5444(struct QF *p);
extern u32 func_02018584(u16, u16, u16);
void func_022079C0(W_022079C0 *p, int i, Point *off);
void func_02207B4C(char *p, int i, int n);
void func_02207B68(char *p, int i, int n);
void func_02207B84(W_02207B84 *p, int i, int c);
void func_02207BAC(O *o, void *q, int idx);
extern const P2 d_0220AAD0;
extern const P2 d_0220AAC0;
extern const P6 d_0220AAD8;
extern const P8 d_0220AB0C;
extern const P8 d_0220AB2C;


void func_022079C0(W_022079C0 *p, int i, Point *off)
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


/*
 * lane O10 candidate
 */
void func_02207B4C(char *p, int i, int n)
{
    func_02207DA0(p, (struct S *)(p + 0x40 + (i << 7)), n);
    *(int *)(p + (i << 7) + 0xb4) = 1;
}


void func_02207B68(char *p, int i, int n)
{
    func_02207DA0(p, (struct S *)(p + 0x40 + (i << 7)), n);
    *(int *)(p + (i << 7) + 0xb4) = 0;
}


void func_02207B84(W_02207B84 *p, int i, int c)
{
    p->e[i].b = 0;
    p->e[i].d = 1;
    func_02207EA8((struct S *)(&p->e[i]), c);
}

/*
 * extent: matched ov094_func_02207C94.c and its existing shard cover the
 *   48-byte follower at 02207C94; retain this lead as a single function.
 */
void func_02207BAC(O *o, void *q, int idx)
{
    int delta;
    u32 next;
    delta = o->e[idx].f58 - o->e[idx].f54;
    o->e[idx].f48 = func_021D59B4(q, 13);
    o->e[idx].f4c = func_021D59B4(q, 14);
    o->e[idx].f50 = (int)0x80000000;
    o->e[idx].f68 = 0;
    o->e[idx].f6c = func_021D59B4(q, 15);
    next = func_02018584(func_021D5444(q), func_021D59B4(q, 19), func_021D59B4(q, 15) + 1);
    o->e[idx].f5c = next - func_02018584(func_021D5444(q), func_021D59B4(q, 19), func_021D59B4(q, 15));
    o->e[idx].f4 = 0;
    o->e[idx].b2 = 1;
    o->e[idx].f8 = 0;
    o->e[idx].b28 = 1;
    func_02207EA8((struct S *)(&o->e[idx]), delta);
}
