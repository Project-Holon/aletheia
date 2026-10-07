/*
 * file:     btlv_b_gauge_p08.c
 * unit:     yes
 * function: func_02208958, func_022089AC, func_022089BC, func_022089D4, func_02208B10, func_02208BFC, func_02208D24
 * address:  0x02208958
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
 *   func_0202D034  0x0202D034  thumb
 *   func_0204B898  0x0204B898  arm
 *   func_02005E50 0x02005E50 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_021F882C 0x021F882C thumb ov094
 *   func_02005D90 0x02005D90 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005C44 0x02005C44 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_0202173C 0x0202173C thumb
 *   func_02021ED8 0x02021ED8 thumb
 *   d_0220AB4C 0x0220AB4C data a4
 */
struct Obj;
struct Actor;
struct PtS;
struct Vec2;
struct Node;
typedef unsigned int u32;

typedef struct {
    int f00;                /* 0x40 in the work area */
    int h04;                /* 0x44 */
    int h08;                /* 0x48 */
    char pad0c[0x14 - 0x0c];
    int h14;                /* 0x54 */
    char pad18[0x40 - 0x18];
    int state;              /* 0x80 */
    char pad44[0x48 - 0x44];
    int f48;                /* 0x88 */
    int f4c;                /* 0x8c */
    char pad50[0x70 - 0x50];
    struct {
        u32 lo : 3;
        u32 b3 : 1;
        u32 mid : 16;
        u32 b20 : 1;
        u32 hi : 9;
        u32 b30 : 1;
        u32 b31 : 1;
    } flags;                /* 0xb0 */
    char pad74[0x80 - 0x74];
} Row;

typedef struct {
    char pad00[0x40];
    Row r[8];               /* 0x40 */
    struct {
        u32 lo : 4;
        u32 b4 : 1;
        u32 mid : 16;
        u32 b21 : 1;
        u32 b22 : 1;
        u32 hi : 9;
    } flags;                /* 0x440 */
} W;

typedef unsigned short u16;

typedef struct { char p0[0x40]; int f40, f44, f48, f4c; char p50[0x20]; u32 b0:1, b1:1, b2:1, b3:1, hi:28; char p74[12]; } E_022089D4;

typedef struct { char p0[0x40]; E_022089D4 e[8]; u32 b0:1, b1:1, b2:1, b3:1, hi:28; int f444; } O;

typedef signed short s16;

typedef struct E_02208B10 {
    void *f0, *f4, *f8, *fc, *f10, *f14;
    char p18[0x2c];
    int f44;
    char p48[0x28];
    unsigned int lo:16, count:4, hi:12;
    char p74[8];
    void *f7c;
} E_02208B10;

typedef unsigned char u8;

typedef struct { int bits[8]; } Masks;

typedef struct { int health; char pad4[4]; u32 active:1; char padc[0x74]; } EntryFlags;

typedef struct { char pad[0xa8]; EntryFlags entries[8]; } Owner;

typedef struct { Owner *owner; int state, mask, count; } State;

extern int func_0202D034(u32 a, u32 b);
extern u16 func_0204B898(struct Obj *p);
extern int func_02005E50(void);
extern int func_02005E9C(void);
extern int func_021F882C(void);
extern void func_02005D90(u32, u32);
extern void func_02005DF8(u32);
extern int func_02005E64(void);
extern u16 func_02005C44(void);
extern void func_02005E30(u32);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_02030EAC(struct Node *n);
extern int func_021F86E0(void);
extern void *func_021F86D4(void);
extern int func_0202173C(void *, u16, u16, s16, u8, u8, u16, void *);
extern u32 func_02021ED8(const char *);
extern int func_0200F300(void);
extern void func_02005DE4(void *p);
int func_02208958(W *w, int i, int *o1, int *o2);
void func_022089AC(W *w);
void func_022089BC(char *p, int i);
void func_022089D4(O *o);
void func_02208B10(void *h, E_02208B10 *e);
void func_02208BFC(void *unused, State *s);
void func_02208D24(int a);
extern const Masks d_0220AB4C;


int func_02208958(W *w, int i, int *o1, int *o2)
{
    if (w->r[i].f00 == 0 || !w->r[i].flags.b3 || w->r[i].flags.b30) {
        *o1 = 0;
        *o2 = 8;
        return 0;
    }
    *o1 = func_0202D034(w->r[i].f48, w->r[i].f4c);
    *o2 = func_0204B898((struct Obj *)w->r[i].h14);
    if (*o2 == 0)
        *o2 = 8;
    return 1;
}


void func_022089AC(W *w)
{
    w->flags.b22 = 1;
}

/*
 * lane O10 candidate
 */
void func_022089BC(char *p, int i)
{
    if (*(int *)(p + (i << 7) + 0x40) != 0)
        *(unsigned int *)(p + 0xb0 + (i << 7)) |= 0x40000000;
}

void func_022089D4(O *o)
{
    int busy, found, i;
    if (o->b1) {
        if (func_02005E50() != 0) return;
        o->b1 = 0;
        if (o->b2) {
            func_02005E9C();
            if (!o->b3 && func_021F882C() != 0) {
                func_02005D90(o->f444, 0xffff);
                o->b3 = 1;
            } else {
                func_02208D24(0);
            }
            func_02005DF8(24);
        } else {
            func_02208D24(1);
            func_02005E64();
            func_02005D90(0x47a, 0xffff);
        }
        o->b2 ^= 1;
        return;
    }
    busy = 0;
    found = 0;
    for (i = 0; i < 8; i++) {
        if (o->e[i].b0 || o->e[i].b1 || o->e[i].b2) {
            busy = 1;
        } else if (o->e[i].f44 == 0 && o->e[i].b3 && o->e[i].f40 != 4) {
            if (func_0202D034(o->e[i].f48, o->e[i].f4c) == 2) found = 1;
        }
    }
    if (!o->b2 && o->f444 != func_02005C44()) return;
    if (busy != 0) return;
    if ((o->b2 && found == 0) || (!o->b2 && found == 1)) {
        o->b1 = 1;
        func_02005E30(8);
    }
}

void func_02208B10(void *h, E_02208B10 *e)
{
    int step;
    s16 v[2];
    if (e->f44 != 0) step = 8;
    else step = -8;
    func_0204B454(e->f0, (struct PtS *)v, 0);
    v[0] += (s16)step;
    func_0204B404(e->f0, (const struct Vec2 *)v, 0);
    func_0204B454(e->f8, (struct PtS *)v, 0);
    v[0] += (s16)step;
    func_0204B404(e->f8, (const struct Vec2 *)v, 0);
    func_0204B454(e->f14, (struct PtS *)v, 0);
    v[0] += (s16)step;
    func_0204B404(e->f14, (const struct Vec2 *)v, 0);
    if (e->f44 == 0) {
        func_0204B454(e->f4, (struct PtS *)v, 0);
        v[0] += (s16)step;
        func_0204B404(e->f4, (const struct Vec2 *)v, 0);
    }
    if (e->f10 != 0) {
        func_0204B454(e->f10, (struct PtS *)v, 0);
        v[0] += (s16)step;
        func_0204B404(e->f10, (const struct Vec2 *)v, 0);
    }
    e->count--;
    if (e->count == 0) {
        func_02030EAC(h);
        e->f7c = 0;
    }
}

/*
 * lever: owner->entries[i] preserves the base/index register ordering;
 *   raw-offset EntryFlags casts and a named raw owner leave four bytes out.
 */
void func_02208BFC(void *unused, State *s)
{
    Masks masks = d_0220AB4C;
    int i;
    void *pal;
    switch (s->state) {
    case 0:
        s->mask = 0;
        for (i = 0; i < 8; i++) {
            if (s->owner->entries[i].active && s->owner->entries[i].health > 0)
                s->mask |= masks.bits[i];
        }
        if (s->mask) {
            pal = (void *)func_021F86E0();
            func_0202173C(pal, 4, s->mask, 0, 0, 8, 16, func_021F86D4());
            s->state = 1;
        }
        break;
    case 1:
        if (!func_02021ED8((const char *)func_021F86E0())) {
            pal = (void *)func_021F86E0();
            func_0202173C(pal, 4, s->mask, 0, 8, 0, 16, func_021F86D4());
            s->state = 2;
        }
        break;
    case 2:
        if (!func_02021ED8((const char *)func_021F86E0())) {
            s->count++;
            if (s->count == 3) {
                s->count = 0;
                s->state = 3;
            } else {
                s->state = 0;
            }
        }
        break;
    case 3:
        for (i = 0; i < 8; i++) {
            if (s->owner->entries[i].active)
                break;
        }
        if (i == 8)
            s->state = 0;
        break;
    }
}


void func_02208D24(int a)
{
    if (func_0200F300() != 1)
        func_02005DE4((void *)a);
}
