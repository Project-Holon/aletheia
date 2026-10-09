/*
 * file:     intrude_subdisp_p04.c
 * unit:     yes
 * function: func_0217DAA8, func_0217DB4C, func_0217DBAC, func_0217DC14, func_0217DC9C, func_0217DCFC, func_0217DD48, func_0217DE44, func_0217DE68, func_0217E014, func_0217E0F4
 * address:  0x0217DAA8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021836CC     0x021836CC  data  a4
 *   d_02176AA0     0x02176AA0  data  a4
 *   func_0204B6F4  0x0204B6F4  arm
 *   d_021836E4  0x021836E4  data  a4
 *   d_021836DC  0x021836DC  data  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02012B58  0x02012B58  thumb
 *   d_021836D4  0x021836D4  data  a4
 *   d_021836EC  0x021836EC  data  a4
 *   func_0217F1E8  0x0217F1E8  thumb  ov018
 *   d_021836C4  0x021836C4  data  a4
 *   func_02043678  0x02043678  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_02025774  0x02025774  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_02012B70  0x02012B70  thumb
 *   d_021836AA     0x021836AA  data   a2
 *   d_021836F4     0x021836F4  data   a4
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_0217F284  0x0217F284  thumb  ov018
 *   func_02082A60  0x02082A60  arm
 *   func_02021F64  0x02021F64  thumb
 *   func_0204B404  0x0204B404  arm
 *   func_0217E2E0  0x0217E2E0  thumb  ov018
 *   func_0204B954  0x0204B954  arm
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_0204B714  0x0204B714  arm
 *   func_0204B454  0x0204B454  arm
 *   d_021836A4     0x021836A4  data   a1
 */
struct Obj;
struct BigObj;
struct Ctx;
struct Sub0200852CObj;
struct Bmp;
struct MsgBank;
struct U16Vec;
struct Grid;
struct Param;
struct Sys;
struct Obj020437AC;
struct Vec2;
struct Actor;
struct PtS;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

typedef struct { u8 pad[4]; u8 a, b; } Ent_0217DAA8;

typedef unsigned int   u32;

typedef struct {
    void *f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
} Tmpl;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    int f0c;
    void *f10;
    u8 pad14[0x1c - 0x14];
    void *f1c;
    u8 pad20[0x28 - 0x20];
    void *f28;
    void *f2c;
    u8 pad30[0x54 - 0x30];
    void *f54;
    u8 pad58[0x9c - 0x58];
    void *f9c;
    u8 padA0[0xb0 - 0xa0];
    void *fb0;
    void *fb4[3];
    void *fc0[2];
    u8 padC8[0x168 - 0xc8];
    u8 f168;
} Work_0217DD48;

typedef signed char s8;

typedef signed short s16;

typedef struct {
    void *f00;
    u8 pad04[0x5c - 0x04];
    void *f5c[8];
    void *f7c;
    u8 pad80[0xd8 - 0x80];
    u8 fd8;
    u8 padD9[0x113 - 0xd9];
    u8 f113;
    u8 f114;
    u8 f115;
    u8 pad116[2];
    s16 f118;
    s8 f11a;
    u8 f11b;
    u8 f11c;
    u8 pad11D[3];
    u16 f120[4];
    u16 f128[4];
    u16 f130[4];
} Work_0217DE68;

typedef struct {
    s16 x;
    s16 y;
} Pos;

typedef struct {
    u8 slot[4];
    Pos pos;
} Layout;

typedef struct {
    void *ptr;
    u16 id;
} Slot;

typedef struct {
    void *f00;
    u8 pad04[0x80 - 0x04];
    void *f80[3];
    void *f8c[3];
    u8 pad98[0xa0 - 0x98];
    void *fa0[3];
    u8 padAC[0xd8 - 0xac];
    u8 fd8;
    u8 fd9;
    u8 padDA[0xec - 0xda];
    Slot fec[3];
} Work_0217E0F4;

typedef struct {
    u8 pad00[0x14];
    u16 f14;
    u16 lo : 3;
    u16 mid : 6;
    u16 hi : 6;
    u8 pad18[4];
} Ent_0217E0F4;

typedef struct {
    u8 pad00[0x8c];
    Ent_0217E0F4 ent[3];
} Mon;

typedef struct {
    Pos p2;
    Pos p;
} Pair;

extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_0204B6F4(struct Obj *o, unsigned int v, unsigned int flag);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern int func_0217F1E8(u8 *p);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_02025774(u8 *g, u32 a);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern int func_02012B70(const struct BigObj *p);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern int func_0217F284(u8 *p);
extern void func_02082A60(const void *, void *, int);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0217E2E0(Work_0217E0F4 *);
extern void func_0204B954(struct Actor *a, u32 v);
extern u32 func_02013D5C(u32 id);
extern u8 *func_0217BEA8(u16);
extern u32 func_0204B714(struct Obj *o);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
void func_0217DAA8(int *p, void *a1);
void func_0217DB4C(int *p, void *a1);
void func_0217DBAC(int *p, void *a1);
void func_0217DC14(int *p, void *a1);
void func_0217DC9C(int *p, void *a1);
void func_0217DCFC(int *p, void *a1);
void func_0217DD48(Work_0217DD48 *p);
void func_0217DE44(void **p);
void func_0217DE68(Work_0217DE68 *p);
void func_0217E014(u8 *p, int a1);
void func_0217E0F4(Work_0217E0F4 *p, Mon *m);
extern const Rect d_021836CC;
extern const Ent_0217DAA8 d_02176AA0[];
extern const Rect d_021836E4;
extern const Rect d_021836DC;
extern const Rect d_021836D4;
extern const Rect d_021836EC;
extern const Rect d_021836C4;
extern const unsigned short d_021836AA[];
extern const Tmpl d_021836F4;
extern const s8 d_021836A4[3][2];


void func_0217DAA8(int *p, void *a1)
{
    Rect r;
    int i;

    r = d_021836CC;
    for (i = 0; i <= 7; i++) {
        r.a = d_02176AA0[i].a;
        r.b = d_02176AA0[i].b;
        p[0x5c / 4 + i] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
        func_0204B92C((struct Obj *)p[0x5c / 4 + i], 1);
    }
    r.c = 8;
    r.a = 0x80;
    r.b = 0x5c;
    p[0x7c / 4] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
    func_0204B3DC((struct Obj *)p[0x7c / 4], 0);
    func_0204B92C((struct Obj *)p[0x7c / 4], 1);
}


void func_0217DB4C(int *p, void *a1)
{
    Rect r;
    int i;

    r = d_021836E4;
    for (i = 9; i <= 11; i++) {
        p[0x5c / 4 + i] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B6F4((struct Obj *)p[0x5c / 4 + i], (u8)(i - 8), 1);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
    }
}


void func_0217DBAC(int *p, void *a1)
{
    Rect r;
    int i;

    r = d_021836DC;
    for (i = 12; i <= 14; i++) {
        p[0x5c / 4 + i] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B6F4((struct Obj *)p[0x5c / 4 + i], (u8)(i - 11), 1);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
        func_0204B92C((struct Obj *)p[0x5c / 4 + i], 1);
    }
}


void func_0217DC14(int *p, void *a1)
{
    Rect r;
    int h;

    r = d_021836D4;
    h = (int)func_020120F4((const struct Ctx *)p[0]);
    if (func_02008550((const struct Sub0200852CObj *)func_02012944((void *)h)) == 1) {
        r.c = 3;
    }
    p[0x98 / 4] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
    func_0204B6F4((struct Obj *)p[0x98 / 4], (u8)(func_02012B58((const struct BigObj *)h) + 1), 1);
    func_0204B3DC((struct Obj *)p[0x98 / 4], 0);
    func_0204B92C((struct Obj *)p[0x98 / 4], 1);
}


void func_0217DC9C(int *p, void *a1)
{
    Rect r;
    int i;

    r = d_021836EC;
    for (i = 17; i <= 19; i++) {
        p[0x5c / 4 + i] = (int)func_0204B294((void *)p[0x54 / 4], p[1], p[2], p[4], &r, 0, 0x70);
        func_0204B6F4((struct Obj *)p[0x5c / 4 + i], (u8)(i - 16), 1);
        func_0204B3DC((struct Obj *)p[0x5c / 4 + i], 0);
    }
}


void func_0217DCFC(int *p, void *a1)
{
    Rect r;
    int h;

    r = d_021836C4;
    h = func_0217F1E8((u8 *)p);
    p[0xac / 4] = (int)func_0204B294((void *)p[0x54 / 4], p[5], p[2], p[6], &r, 0, 0x70);
    func_0204B3DC((struct Obj *)p[0xac / 4], h);
}


void func_0217DD48(Work_0217DD48 *p)
{
    void *sys;
    int i;
    void *str;
    Tmpl a;
    Tmpl t;

    sys = func_020120F4(p->f00);
    p->f9c = func_0204B294(p->f54, (unsigned int)p->f04, (unsigned int)p->f08, (unsigned int)p->f10, d_021836AA, 0, 0x70);
    func_0204B3DC(p->f9c, 0);
    t = d_021836F4;
    for (i = 0; i < 2; i++) {
        a = t;
        p->fb4[i] = func_02043678(6, 2, 0x20, 0x70);
        a.f00 = p->fb4[i];
        a.f08 = p->f0c;
        p->fc0[i] = func_020255A0(p->fb0, (const struct Param *)(&a));
        func_02025774(p->fc0[i], 0);
        str = func_02045EC0(p->f2c, i + 0x45);
        func_0201C724(p->f28, (u32)p->fb4[i], 0, 0, (u32)str, (u32)p->f1c, 0x3c40);
        func_02045808(str);
    }
    if (p->f168 == 0 && func_02012B70(sys) == 0) {
        func_0204B3DC(p->f9c, 1);
        func_02025774(p->fc0[1], 1);
    }
}

void func_0217DE44(void **p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_0202570C(p[0xc0 / 4 + i]);
        func_020437AC(p[0xb4 / 4 + i]);
    }
}


void func_0217DE68(Work_0217DE68 *p)
{
    void *sys;
    int i;
    int c;
    int q;
    void *act;

    sys = func_020120F4(p->f00);
    if (func_0217F284((u8 *)p) == 1) {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(p->f5c[i], 0);
        }
        func_0204B3DC(p->f7c, 0);
    } else if (p->fd8 == func_02012B58(sys) || func_02012B70(sys) == 0) {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(p->f5c[i], 0);
        }
        func_0204B3DC(p->f7c, 0);
    } else {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(p->f5c[i], 1);
        }
        func_0204B3DC(p->f7c, 1);
    }
    for (i = 6; i <= 8; i++) {
        func_02082A60((void *)(0x05000602 + (p->fd8 + 1) * 32), (void *)(0x0500060C + i * 32), 2);
    }
    if (p->f114 == 1) {
        if (p->f115 % 2 == 0) {
            if (((unsigned)p->f115 >> 1) & 1) {
                c = 6;
            } else {
                c = 7;
            }
            q = p->f113;
            if (q != 8) {
                act = p->f5c[q];
            } else {
                act = p->f7c;
            }
            func_0204B6F4(act, (u8)c, (int)1);
        }
        if (p->f115 < 10) {
            p->f115++;
        }
        return;
    }
    if (p->f11b == 0xff) {
        return;
    }
    if (p->f11a == 0) {
        p->f118 += 0x100;
        if (p->f118 >= 0x1100) {
            p->f118 = 0x2000 - p->f118;
            p->f11a = 1;
        }
    } else {
        p->f118 -= 0x100;
        if (p->f118 < 0) {
            p->f118 = 0x100 - p->f118;
            p->f11a = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        func_02021F64(&p->f120[i], &p->f130[i], 1, p->f118 >> 8, p->f128[i]);
    }
    p->f11c = 1;
}


#pragma opt_propagation off

/*
 * final push 2026-10-05 G7L8: closed with opt_propagation off, a named slot
 * pointer `s` (declared first, assigned after the call, used for the three
 * zero stores and the first loop), n zeroed right before the first loop,
 * do-while loops (for loops gain entry guards under the pragma), an explicit
 * `if (n > 0)` guard on the second loop, and the mask test written as
 * `p[0xd9] & (1 << i)`.
 */
void func_0217E014(u8 *p, int a1)
{
    u8 *s;
    void *act;
    int cur;
    int sel;
    int max;
    int n;
    int i;
    int j;
    Layout l;

    func_020120F4(*(void **)p);
    s = l.slot;
    s[0] = 0;
    s[1] = 0;
    s[2] = 0;
    max = p[0xda];
    cur = p[0xd8];
    sel = 0;
    l.pos.y = 0x1c;
    n = 0;
    i = 0;
    do {
        if (p[0xd9] & (1 << i)) {
            s[n] = i;
            if (i == cur) {
                sel = n;
            }
            n++;
        }
        i++;
    } while (i < 3);
    j = 0;
    i = 0;
    if (n > 0) {
        do {
            if (sel != i) {
                if (l.slot[i] == cur + 1 || (l.slot[i] == 0 && cur == max - 1)) {
                    l.pos.x = 0xa0;
                } else {
                    l.pos.x = 0x60;
                }
                act = ((void **)(p + 0x80))[j];
                func_0204B404(act, (const struct Vec2 *)(&l.pos), 0);
                func_0204B6F4(act, (u8)(l.slot[i] + 1), 1);
                func_0204B3DC(act, 1);
                j++;
            }
            i++;
        } while (i < n);
    }
    for (; i < 3; i++) {
        func_0204B3DC(((void **)(p + 0x80))[i], 0);
    }
}

#pragma opt_propagation reset


void func_0217E0F4(Work_0217E0F4 *p, Mon *m)
{
    void *sys;
    int cur;
    int i;
    int k;
    void *a;
    Ent_0217E0F4 *e;
    u8 *prev;
    u16 previd;
    u8 *obj;
    void *b;
    Pair l;

    sys = func_020120F4(p->f00);
    cur = p->fd8;
    func_0217E2E0(p);
    for (i = 0; i < 3; i++) {
        obj = 0;
        prev = p->fec[i].ptr;
        previd = p->fec[i].id;
        if (i != func_02012B58(sys)) {
            p->fec[i].ptr = 0;
            p->fec[i].id = 0x1ab;
        }
        a = p->f8c[i];
        b = p->fa0[i];
        if (i == func_02012B58(sys)) {
            func_0204B3DC(a, 0);
            func_0204B3DC(b, 0);
            continue;
        }
        if (m == 0) {
            func_0204B3DC(a, 0);
            func_0204B3DC(b, 0);
            continue;
        }
        if (p->fd9 & (1 << i)) {
            e = &m->ent[i];
        } else {
            func_0204B3DC(a, 0);
            func_0204B3DC(b, 0);
            continue;
        }
        if (e->hi == 2) {
            func_0204B954(a, 0x2000);
        } else {
            func_0204B954(a, 0x1000);
        }
        if (e->lo == cur) {
            if (func_02013D5C(e->f14) == 1) {
                l.p.x = d_021836A4[i][0] + 0x80;
                l.p.y = d_021836A4[i][1] + 0x4c;
                func_0204B3DC(b, 0);
            } else {
                if (e->f14 != previd) {
                    obj = func_0217BEA8(e->f14);
                } else {
                    obj = prev;
                }
                if (obj != 0) {
                    l.p.x = obj[0xa] + d_021836A4[i][0];
                    l.p.y = obj[0xb] + d_021836A4[i][1];
                    func_0204B3DC(b, 0);
                } else {
                    l.p.x = 0xe8;
                    l.p.y = i * 0x18 + 0x50;
                    l.p2 = l.p;
                    l.p2.x = 0xf0;
                    func_0204B404(b, (const struct Vec2 *)(&l.p2), 0);
                    func_0204B3DC(b, 1);
                }
            }
            func_0204B404(a, (const struct Vec2 *)(&l.p), 0);
            p->fec[i].ptr = obj;
            p->fec[i].id = e->f14;
        } else {
            func_0204B3DC(b, 0);
            for (k = 0; k < 3; k++) {
                if (func_0204B714(p->f80[k]) == i + 1) {
                    func_0204B454(p->f80[k], (struct PtS *)&l.p, 0);
                    break;
                }
            }
            if (k == 3) {
                func_0204B3DC(a, 0);
                continue;
            }
            l.p.x += d_021836A4[i][0];
            l.p.y += d_021836A4[i][1];
            func_0204B404(a, (const struct Vec2 *)(&l.p), 0);
        }
        func_0204B3DC(a, 1);
    }
}
