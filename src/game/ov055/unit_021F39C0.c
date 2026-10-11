/*
 * file:     unit_021F39C0.c
 * unit:     yes
 * function: func_021F39C0, func_021F3A64, func_021F3AA4, func_021F3B10, func_021F3B20, func_021F3B48, func_021F3C2C, func_021F3CE4, func_021F3CF4, func_021F3D0C, func_021F3D90, func_021F3DBC, func_021F3DD4, func_021F3E84, func_021F3F20, func_021F3F30, func_021F3F9C, func_021F405C, func_021F40F4, func_021F4124, func_021F414C, func_021F4174, func_021F41F0, func_021F42AC, func_021F4318, func_021F4388, func_021F43D8, func_021F4430, func_021F4458, func_021F4474, func_021F4510, func_021F4530, func_021F4574, func_021F459C
 * address:  0x021F39C0
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021690B4  0x021690B4  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189A68  0x02189A68  thumb  ov021
 *   func_02189A38  0x02189A38  thumb  ov021
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021F4620     0x021F4620  data  ov055  a4
 *   d_021F4620_b   0x021F4620  data  ov055  a4
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216DCCC  0x0216DCCC  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216CF2C 0x0216CF2C thumb ov010
 *   d_021F45C0 0x021F45C0 data a4
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   d_021F45C8     0x021F45C8  data  ov055  a4
 *   func_0216D5B8 0x0216D5B8 thumb ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_020490F4  0x020490F4  arm
 *   func_02049250  0x02049250  arm
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   func_0216DB4C 0x0216DB4C thumb ov010
 *   func_0216DC98 0x0216DC98 thumb ov010
 *   func_0216DAE0 0x0216DAE0 thumb ov010
 *   func_0216D5B4 0x0216D5B4 thumb ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216DAB4  0x0216DAB4  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_02045B38  0x02045B38  arm
 *   func_021F45A4 0x021F45A4 thumb ov055
 *   func_02045C04 0x02045C04 arm
 *   d_021F45E0 0x021F45E0 data a1
 *   d_021F45D0 0x021F45D0 data a1
 *   func_02191870  0x02191870  thumb  ov021
 *   func_0219196C  0x0219196C  thumb  ov021
 */
#include "../../matched/include/Obj09846.h"
#include "../../matched/include/Obj13119.h"
#include "../../matched/include/Obj13120.h"
#include "../../matched/include/G_V.h"
#include "../../matched/include/Obj13122.h"
#include "../../matched/include/Obj00204.h"
#include "../../matched/include/Obj13123.h"
#include "../../matched/include/Obj05137.h"
#include "../../matched/include/Obj07666.h"
#include "../../matched/include/Obj07667.h"
#include "../../matched/include/Obj20580.h"
#include "../../matched/include/Obj05138.h"

struct Ctx;
struct O;
struct T;
struct Obj00020;
struct S;
struct ArcFile;
struct Entry;
struct Table;
struct Rec;
struct MsgBank;
struct S_021F4388;
struct Fx;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef short          s16_021F3B20;

typedef struct Entry {
    u8 active;
    u8 f1;
    u8 kind;
    u8 f3;
    u8 pad4[8];
    void *obj;
    u8 pad10[8];
} Entry;

typedef struct Table {
    u8 hdr[8];
    Entry e[32];
} Table;

typedef struct V V;

typedef struct O {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 ha;
    int fc;
    void *f10;
    u16 h14;
    u16 h16;
} O;

typedef struct Ent {
    int key;
    u16 h[6];
} Ent;

typedef struct T {
    u8 pad0[0xd];
    u8 n;
    u16 h[21];
    Ent *f38;
    u32 f3c;
} T;

struct R { u16 h0, h2, h4, h6; };

typedef struct S_021F3E84 {
    char pad[0x32];
    short cnt[2];
    int f38;
    u32 f3c;
} S_021F3E84;

typedef struct E_021F3B20 { char b[12]; } E_021F3B20;

typedef struct S_021F3F30 {
    short lim[6];
    u8 n;
    u8 pad[13];
    E_021F3B20 ent[2];
    short cnt[2];
} S_021F3F30;

typedef struct E_021F405C { char b[10]; u16 w; } E_021F405C;

typedef struct S_021F3B20 {
    short lim[6];
    u8 n;
    u8 pad[13];
    E_021F405C ent[2];
    short cnt[2];
} S_021F3B20;

typedef signed short   s16_021F4388;

typedef struct S_021F4388 {
    u16 a;
    u8 b;
    u8 c;
    u16 d;
    u16 e;
} S_021F4388;

extern u32 func_02188C54(u8 *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C7C(unsigned char *p);
extern u16 func_02188C9C(u8 *p);
extern int func_021690B4(int);
extern u16 func_02188C84(u8 *p);
extern void func_02189A68(char *a, int b);
extern int func_02189A38(int);
extern int func_02189A2C(int *a);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern u32 func_020056EC(u32);
extern int func_0216CE60(int, void *, int);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern int func_0216DCCC(void *a0, int a1);
extern void func_0216D8C0(int, int *);
extern void func_0216CF2C(int a0);
extern u16 func_0216D598(void *p);
extern void func_0216E618(V *, int, int, int);
extern void func_0216E0AC(void *a0, void *a1);
extern u32 func_0216D5B8(void *p);
extern u16 func_0216D5F8(void *p);
extern u16 func_021642A4(int i);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
extern void func_0216D410(void *a0, u16 a1);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern int func_0216DB4C(void *a0, int a1);
extern int func_0216DC98(void *a0, int a1);
extern void func_0216DAE0(unsigned int *,unsigned int);
extern void func_0216D5B4(void *p, u16 v);
extern int func_0216D454();
extern void *func_021A3074(unsigned char *p);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D55C(int a, int b);
extern int func_0216DAB4(void *a);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_021F45A4(unsigned short *,unsigned int);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02191870(struct Fx *a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h);
extern void func_0219196C(u32 a, u32 b);
void func_021F39C0(int a, int b, char *c);
void func_021F3A64(int a, int b, char *c);
void func_021F3AA4(int a, int b, char *c);
void func_021F3B10(char *c);
u8 *func_021F3B20(u8 *p);
Entry *func_021F3B48(Table *t, int x, int y, unsigned int dir, int unused, int *out);
void func_021F3C2C(O *o, int a, int b, const T *s, int i);
void func_021F3CE4(char *p);
void func_021F3CF4(unsigned char *p, int a, int b);
void func_021F3D0C(O *o, int a1, int a2, int idx, u16 p4, u16 p5, u16 p6, u16 p7, void *p8);
void func_021F3D90(unsigned char *p);
void func_021F3DBC(unsigned char *p);
void func_021F3DD4(u8 *p, u32 x);
void func_021F3E84(S_021F3E84 *o, int b, int key, u16 c);
void func_021F3F20(unsigned char *p);
void func_021F3F30(S_021F3F30 *p, char *q, int k);
void func_021F3F9C(const char *a, int b, const u16 *c, u8 *d, u16 e);
void func_021F405C(S_021F3B20 *p, char *q, int k);
u32 func_021F40F4(u8 *p);
void func_021F4124(unsigned char *p);
void func_021F414C(unsigned char *p);
void func_021F4174(u8 *a, u32 b);
void func_021F41F0(u8 *a, u32 b, u32 c);
int func_021F42AC(u8 *a, void *b, u32 *c, u16 d, u16 e);
int func_021F4318(const u8 *a, void *b, u16 c, u16 d);
int func_021F4388(int a, int b, int c, int d, u16 hi, u16 lo, u16 dir);
void func_021F43D8(u32 *a, u32 b, s16_021F4388 *c, u32 d, u16 e);
void func_021F4430(unsigned char *p);
void func_021F4458(unsigned char *p);
void func_021F4474(s16_021F4388 *a, s16_021F4388 *b, int *c);
void func_021F4510(S_021F4388 *p, int i);
void func_021F4530(u16 *p, u32 a, u32 b, u32 c, u32 d);
void func_021F4574(u16 *p, u32 x);
void func_021F459C(void *p);
extern struct V d_021F4620;
extern struct V d_021F4620_b;
extern const u8 d_021F45E0[];
extern const u8 d_021F45D0[];




void func_021F39C0(int a, int b, char *c)
{
    int i;
    u16 t4;
    int t0, t1, t2, t3;

    t0 = func_02188C54((u8 *)b);
    t1 = (int)func_020120F4(func_02188C80((void *)b));
    ((struct Obj09846 *)c)->f0 = func_02188CB4((void *)b);
    ((struct Obj09846 *)c)->f4 = func_02188C7C((void *)b);
    t2 = func_02188C9C((u8 *)b);
    t3 = func_021690B4(t1);
    t4 = func_02188C84((u8 *)b);
    func_021F3E84((S_021F3E84 *)(c + 0x308), t3, t2, t4);
    for (i = 0; i < 0x20; i++)
        func_021F3C2C((struct O *)(c + 8 + i * 0x18), (int)(((struct Obj09846 *)c)->f4), t2, (const struct T *)(c + 0x308), i);
    func_021F405C((S_021F3B20 *)(c + 0x308), c, t3);
    func_021F43D8((u32 *)(c + 0x348), t0, (s16_021F4388 *)(c + 0x308), t3, t4);
    func_02189A68((char *)b, (int)c);
}




void func_021F3A64(int a, int b, char *c)
{
    int i;

    func_02189A68((char *)b, 0);
    for (i = 0; i < 0x20; i++)
        func_021F3CE4(c + 8 + i * 0x18);
    func_021F3F20((unsigned char *)(c + 0x308));
    func_021F4430((unsigned char *)(c + 0x348));
    ((struct Obj13119 *)c)->f0 = 0;
    ((struct Obj13119 *)c)->f4 = 0;
}



void func_021F3AA4(int a, int b, char *c)
{
    int i;

    func_021F3F30((S_021F3F30 *)(c + 0x308), c, func_02189A38(b));
    if (func_02189A2C((int *)b)) {
        for (i = 0; i < 0x20; i++)
            func_021F3D90((unsigned char *)(c + 8 + i * 0x18));
    }
    for (i = 0; i < 0x20; i++)
        func_021F3CF4((unsigned char *)(c + 8 + i * 0x18), ((struct Obj13120 *)c)->f4, ((struct Obj13120 *)c)->f0);
    func_021F4474((s16 *)(c + 0x348), (s16 *)(c + 0x308), (int *)b);
}


void func_021F3B10(char *c)
{
    func_021F4458((unsigned char *)(c + 0x348));
}






u8 *func_021F3B20(u8 *p)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        int off = i * 0x18;

        if (p[off + 8] == 0) {
            return (u8 *)(p + 8) + off;
        }
    }
    return 0;
}







/*
 * The switch lists case 3 before case 2: the original lays the dx = 1 arm
 * out ahead of the dx = -1 arm.
 */
Entry *func_021F3B48(Table *t, int x, int y, unsigned int dir, int unused, int *out)
{
    int dx;
    int dy;
    int i;
    s16_021F3B20 ex;
    s16_021F3B20 ey;
    int px;
    int py;

    switch (dir) {
    case 0:
        dx = 0;
        dy = -1;
        break;
    case 1:
        dx = 0;
        dy = 1;
        break;
    case 3:
        dx = 1;
        dy = 0;
        break;
    case 2:
        dx = -1;
        dy = 0;
        break;
    }
    *out = 0;
    for (i = 0; i < 32; i++) {
        if (t->e[i].active != 0 && t->e[i].kind == 1) {
            px = func_0216D83C(t->e[i].obj);
            py = func_0216D86C(t->e[i].obj);
            ex = px - x;
            ey = py - y;
            if (ex != 0) {
                ex = ex / (ex < 0 ? -ex : ex);
            }
            if (ey != 0) {
                ey = ey / (ey < 0 ? -ey : ey);
            }
            if (ex == 0 && ey == 0) {
                *out = 1;
                return &t->e[i];
            }
            if (ex == dx && ey == dy) {
                return &t->e[i];
            }
        }
    }
    return 0;
}







void func_021F3C2C(O *o, int a, int b, const T *s, int i)
{
    u32 k;
    u32 r;
    u16 x;

    k = 0;
    x = s->h[func_020056EC(0) % s->n];
    d_021F4620.h2 = x;
    r = func_020056EC(0);
    o->h8 = i + 0x30;
    for (k = 0; k < s->f3c; k++) {
        if (x == s->f38[k].key) {
            o->h6 = s->f38[k].h[r % 6];
            break;
        }
    }
    o->fc = func_0216CE60(a, &d_021F4620_b, b);
    o->f0 = 0;
    o->f1 = 0;
    o->f2 = 0;
    o->f3 = 0;
    o->ha = func_021F40F4((u8 *)s);
    func_0216DAC8((unsigned int *)o->fc, 1);
    func_0216DCCC((void *)o->fc, 1);
    {
        int v[3] = {0, 0, 0};
        v[0] = func_020056EC(0x8000) - 0x4000;
        func_0216D8C0(o->fc, v);
    }
}






void func_021F3CE4(char *p) { func_0216CF2C((int)(*(unsigned char * *)&((struct Obj13122 *)p)->fC)); ((struct Obj13122 *)p)->fC=0; }






extern void (*d_021F45C0[])(unsigned char *,unsigned int,unsigned int);






void func_021F3CF4(unsigned char *p, int a, int b) { if (p[0]) d_021F45C0[p[2]](p,a,b); }





extern void (* const d_021F45C8[])(O *);






void func_021F3D0C(O *o, int a1, int a2, int idx, u16 p4, u16 p5, u16 p6, u16 p7, void *p8)
{
    V v;

    o->f0 = 1;
    func_0216DAC8((unsigned int *)o->fc, 0);
    v = d_021F4620;
    v.h2 = func_0216D598((void *)o->fc);
    v.hc = p6;
    v.h0 = o->h8;
    func_0216E618(&v, p4, p5, 0);
    func_0216E0AC((void *)o->fc, &v);
    o->f2 = idx;
    o->f3 = p6;
    o->f1 = 0;
    o->h4 = p7;
    o->h14 = 0;
    o->h16 = 0;
    func_0216DCCC((void *)o->fc, 1);
    o->f10 = p8;
    d_021F45C8[idx](o);
}





void func_021F3D90(unsigned char *p) { if (p[0]==1 && p[2]==1 && func_0216D5B8(((struct Obj00204 *)p)->fC)==2000) { p[2]=0; func_021F4124(p); } }





void func_021F3DBC(unsigned char *p) { p[0]=0; p[2]=0; p[3]=0; p[1]=0; func_0216DAC8((unsigned int *)(*(int *)&((struct Obj00204 *)p)->fC),1); }





#pragma opt_lifetimes off





/*
 * 2026-10-05 (wFlags): EXACT (176 B, c99 and c) with `#pragma opt_lifetimes off` above the function (lifetime splitting off,
 *   per-function pragma, approved form). Plain -O4,p gave the 26 B p/a register swap; the other compiler versions and
 *   flags tried (wFlags) did not change it.
 * 2026-10-05 (wD9r laneS6): still DIFF 26 bytes (p/a swap). Draft code checked against HEAD (only notes differ, same 26 B).
 *   Read the mwcc source model (Coloring.c, SpillCode.c, ALLOCATOR_CASEBOOK.md; PPC build, same colour engine): webs
 *   with degree below K are pushed in ascending vreg order and the last pushed colours first; webs at or above K are
 *   pushed by minimum spill_cost/degree (def weight 2, use weight 1, times block weight), the lowest score colours
 *   last. The four long-lived webs here (p, a, xx, y0) all sit above K in Thumb (r4-r7 only), so the order is
 *   cost/degree, not declaration order. Test: locals declared xx, yy, y0, r, then a, t0 (a gets the lowest decl slot): 26,
 *   same swap, which agrees with the cost model (decl order inert). Model: p needs a higher cost/degree than a. a already
 *   has six defs (weight 2 each) that the image has too, and earlier extra p uses did not flip it, so the parameter-copy
 *   web seems to be ranked by a rule other than plain cost (a load-defined p is an ordinary web and wins). No further
 *   source form follows from the model; left DIFF.
 * 2026-10-05 (wD9r lane141): still DIFF 26 bytes (p/a swap). New try: p as an int parameter cast to u8 * at
 *   every use (no local copy, so no second vreg for p): 26, same code. The parameter's type and spelling do
 *   not move the colour order.
 * 2026-10-05 (wD9r lane134): still DIFF 26 bytes (p/a swap). New try: p as a const u8 * parameter (reads
 *   through const, the two end stores cast to u8 *): 26, same. Reading: the a-web has 16 uses against 12 for
 *   p; if this build colours the heavier web first, the image needs a split a-web that is not coalesced,
 *   which the separate t0/a/n locals already tried do not give.
 * 2026-10-05 (wD9r lane123): still DIFF 26 bytes (p/a swap). New tries, each a real compile: the bound result
 *   in a separate local n (`n = a; if (out) n = func_021642A4(a);`, n used by D410 and the 0x16 store): 26; the
 *   rect pointer read inline at each of the four bound reads (no r local, more p uses): 26; the end stores
 *   through a block-local `u16 *c = (u16 *)(p + 0x14)` (36, the add is kept); c set at the top and used for all
 *   0x14/0x16 accesses (174). Use count of p and a split of the last a-web do not move the colour order.
 * 2026-10-05 (wD9r lane103): still DIFF 26 bytes (p/a swap). New tries: the D410 call and both stores as a
 *   static inline SetCur(u32 a, u8 *p) with a first (26); the whole body as a static inline Body(u32 x, u8 *p)
 *   called from the real function, and as Body(u8 *p, u32 x) (26, both). Inline parameter order does not move
 *   the colour order.
 * 2026-10-05 (wD9r lane89): still DIFF 26 bytes (p/a swap). New tries: int t0 and a with the u32 prototypes (27);
 *   the final stores as ((u16 *)p)[10] / [11] (26); a third local d for the first-part result with a = d before
 *   the rect test, and with `else a = d` in each arm (26, both). Probes (stand-ins, not kept): `p = p;` at entry,
 *   after the first call, before the 41E8 sum, before the D410 call and at the end, and `a = a;` at the end: all
 *   26, so no definition point of p or a moves the colour order here.
 * 2026-10-05 (wD9r lane77): still DIFF 26 bytes (p/a swap). New tries: `register` on the p parameter (26);
 *   `register` on a (26); the bound test operands swapped (`p[3] == t0 || func_021642A4(t0) == p[3]`, 26, same
 *   code). The ov055 callers (021F4174, 021F41F0) pass (a, loc) with loc from func_021F42AC, so x is an
 *   object pointer as lane44 read; no twin of this routine exists in src/matched.
 * 2026-10-05 (wD9r lane62): still DIFF 26 bytes (p/a swap, the only diff). New tries: C99 declarations at
 *   first use with initialisers (t0, xx, y0 initialised from their calls, a/yy/r declared after them): 26,
 *   same; `a == 0 || a == 1` for the bound test (26, compiles identically); `a < 2` (28). Model test: with
 *   func_0216D5F8(0) instead of (x) the swap stays, so the x parameter web plays no part in it.
 * 2026-10-05 (wD9r lane44): still DIFF 26 bytes (p/a swap). Read: func_0216D5F8 is `ldrh r0,[r0,#0x18]`
 *   (x is an object pointer; t0/a is a direction), 41E8/41F8 are dx/dy tables, 42A4 the reverse direction.
 *   Tried: one variable a for t0 and a with `a = (u16)(a + 2)` in each rand arm (26, same; with the +2
 *   hoisted above the rand test: 168 B, layout breaks); D410 and both stores written in each out-of-range
 *   arm with return (226 B, tails not merged, swap stays); parameter x reused as a (178 B, x homed r4);
 *   x reused as xx or y0 (178 B, x copied to a callee-saved register at entry). Every form keeps p r5.
 * 2026-10-05 (wD9r lane34): still DIFF 26 bytes (p/a swap). Tried (all 26): p as a real struct
 *   pointer (fields b3, ha, obj, rect, active, cur); x as a u16 parameter; the matched prototypes
 *   (u16 func_0216D5F8(void *), u16 func_021642A4(u16), 021641E8/F8(u16), 0216D410(void *, u16)) with
 *   u16 t0/a (u32/int locals give 184 B); the final call and two stores as a static inline SetCur(p, a);
 *   p as a local copy of an int or void * parameter, assigned before or after the first call. Reading:
 *   the ov021 sibling 0219A8C0 gives the call result r4 and the parameters r5/r6 (reverse order), the
 *   same rule as this build; the image gives p r4, so p behaves like the first-defined local there.
 * 2026-10-05 (wD9r lane07): still DIFF 26 bytes (p/a swap). Tried: s16_021F3B20 nx/ny as new locals for the
 *   41E8/41F8 sums (26, same); the a <= 1 test as switch (a) {case 0: case 1: ... default:} (182 B, worse);
 *   int return with `return 1` (r0 = 1 at the exit in the image; 26, same); 0x14/0x16 as one struct copy
 *   (186 B, worse). Model tests (one call, then D410 and the two stores): p/a swap is present in every
 *   reduced form (no first part, no rect test, no xx/y0); in the reduced model only a LAST use of p after
 *   the last use of a (store a first, then 0x14 = 1) gives p r4, but in the full function that order is
 *   inert (still 26) and emits the stores in the wrong order.
 * 2026-10-05 (wD9 lane07): still DIFF 26 bytes (p/a swap). Tried: xx, yy, y0 as s16_021F3B20 with func_0216D83C/86C
 *   returning s16_021F3B20 (same 26); the rect test as a static inline Outside() returning 0/1 with one
 *   `if (Outside(..)) a = func_021642A4(a)` (77, the bool is not folded, swap stays).
 * 2026-10-05 (wD7 lane14): still DIFF 26 bytes. Tried: the second part (from the 021641E8 call to the end) as a static inline
 *   Fin(p, a, xx, y0) (same 26, p/a swap stays). Same residue shape as ov020 02186470 (parameter copied first gets r5, first
 *   long-lived call result gets r4).
 * 2026-10-05 (wave D6 lane 19): still DIFF, 26 bytes, p/a swap. Callee listings checked
 *   (rule 1): all six ov010 callees read r0 only, no hidden argument. Tried: the first part as a
 *   static inline returning a (same 26); the a <= 1 bound test as one ternary condition (worse, 188
 *   bytes); `goto out` with the tail written in both paths (79, swap stays); x reused as t0/a (167).
 * note (2026-10-05, wD5 lane01): now 26 bytes: r is loaded inside each arm of the a <= 1 test
 *   (the compiler hoists both loads to just after the cmp, as in the image). Residue: p/a colour
 *   swap only (image p r4, a r5; ours p r5, a r4). Tried, all inert: store order 0x16/0x14, u16
 *   returns for func_0216D5F8/func_021642A4 with u16 t0 and a, x0/xx and y0/yy split or merged,
 *   r as inline expression or two locals, declaration order of all locals (two orders), a copy of p.
 *   Worse: x reused as t0/a (167), the whole tail repeated per first-part arm (385), a join
 *   argument local for the shared func_021642A4 call (108). Model tests show that extra
 *   callee-saved locals (xx, y0) move p from r4 to r5 even when the first part matches, so the
 *   swap comes from the long-lived local set, not from the first part.
 * note (2026-10-05, wD4 lane17): still DIFF, 28 bytes, register names only (p r5/a r4 vs original p r4/a r5). New tries: t0 and a merged into one local (no change); `r` loaded inside each arm (moves the ldr after the cmp as in the original, 26 bytes left, not applied here); if-else inverted on the 0x14 test (74 bytes, block order breaks). The remaining residue is the colour of p versus the first call result.
 *
 * 2026-10-05 (wD8 lane09): still DIFF 26 bytes. Tried: x reassigned as t0 (`x = func_0216D5F8(x)`) with a
 *   separate a: worse (88 bytes, x takes r4 and p r5, the parameter copy order changes). The a-web gets the
 *   lower register in every form so far.
 * 2026-10-05 (wD9r lane148): still DIFF 26 bytes (p/a swap). New tries from the callee listings: real return
 *   types (021641E8/F8 return s16_021F3B20, `lsls/asrs`; 021642A4 and 0216D5F8 return u16) with u16 parameters, u16 t0/a
 *   and a u16 D410 parameter: 26, same swap (u32 t0/a with these prototypes: worse). A K&R definition
 *   `void func_021F3DD4(p, x) u8 *p; u32 x;`: 26, same. Block-by-block recheck of the logic against the listing
 *   found no difference.
 * 2026-10-05 (wD9r lane159): still DIFF 26 bytes (p/a swap). New tries from the narrow-local idiom: u16 a and
 *   t0 with u16 callee prototypes and the widening done through a static inline helper at each arithmetic use
 *   (`Add(u32 v, u32 k)` for t0 + 2 and for the 0xa field + a): 26, same; the helper with a u16 parameter: 26;
 *   u16 a with u32 t0: 178 B; u32 a with u16 t0: 182 B; u16 locals with u32 returns: 178 B. Narrow width of
 *   the cursor value does not move the colour order. Model finding (reduced model and the matched ov019
 *   0217F310): in a small function the parameter gets r4 when a register-offset access through p exists
 *   (`*(p + 0x400)` or `p + 0x2810`, pool offset) or when a constant store through p follows the last use of a;
 *   in this full function none of these flips it (extra p-only temps, 8 or 16 extra p stores, p + 0x400 at
 *   the top or end: all keep p r5). Of 79 game functions with the image shape (param r4, first call result r5),
 *   this one and ov019 0217F310 are the only ones whose first call does not read the parameter.
 * 2026-10-05 (wD9r lane173): still DIFF 26 bytes (p/a swap). Checked for a shared logic or type error: no
 *   matched twin calls 021641E8 with 021642A4 or 020056EC; callee bodies (42A4 table u16, 41E8 s16_021F3B20, 5F8 u16 field,
 *   83C int field, D410 (void *, u16)) agree with the draft; every result is used; p fields are read in listing
 *   order. New tries: t0 as a block-scope local of the first part only (26, same); the end stores through a
 *   block-local `u16 *c = (u16 *)p` as c[0xa] / c[0xb] (26, same).
 * 2026-10-05 (wD9r lane182): still DIFF 26 bytes (p/a swap). New tries from the colour idioms: `unsigned long`
 *   for a, for t0 and a, for xx/yy/y0 (long-colours-apart-from-int idiom): 26 each; p as a distinct local copy
 *   of a renamed parameter with a unsigned long (second-same-typed-local idiom): 26; static inline u16 field
 *   getter/setter H(p,k)/SH(p,k,v) for the 0x14/0x16 accesses: 26. Dying-local idiom: no dying local exists
 *   (x is dead after the first call but reusing it was tried by earlier lanes: 167 to 178 B).
 * 2026-10-05 (wD9r lane188): still DIFF 26 bytes (p/a swap). Read ov019 0217F310 in full (matched twin of the
 *   image shape): its parameter keeps r4 with FEWER uses than the first call result, so the colour order is not a plain
 *   use count there; its p accesses are register-offset (`ldr r0,[r4,r0]`), which this function does not have. New
 *   tries: the 0x16 field read into its own block local before `a = q` (idiom a-field-read-into-its-own-local-...):
 *   26; a pointer copy `pp = p` at entry used for both end stores: 26. Idioms read, no new form:
 *   a-call-between-a-buffer-handle-and-its-first-read-keeps-it-in-a-register,
 *   a-flag-set-after-the-call-that-consumes-its-input-shares-that-inputs-register.
 * 2026-10-05 (wD9r lane201): still DIFF 26 bytes (p/a swap). New tries: part 1 (the 0x14 test and the else chain)
 *   wrapped in `do { } while (0)` to raise block weight, and the whole pre-call part in it: both fold away in the
 *   front end, 26, same code. Use counts: p has about 12 uses, a about 16 (all in straight-line code, no loop in the
 *   listing, so no source change can give p a loop weight). Read the matched ov021 0219A8C0 (params r6/r5, call result
 *   r4: the most-used web takes r4, the later-defined local first), which agrees with a-first in our build; the image
 *   needs p first. Idioms read: a-derived-wide-local-keeps-a-coordinate-update-before-its-first-call (fresh local vs
 *   reuse: lanes 34/89 did it), a-pos-accumulation-settles-a-callee-saved-rotation (no accumulator here),
 *   a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie, a-spilled-pointer-parameter-tie-is-the-front-ends.
 *   No new form.
 * 2026-10-05 (wD9r lane208): still DIFF 26 bytes (p/a swap). Diagnostic: with the parameter changed to `u8 **pp` and
 *   `u8 *p = *pp;` as the first local (p defined by a load, not a parameter copy), the rest of the function matches:
 *   1 byte differs (`ldr r4,[r0]` for `adds r4,r0,#0`). So the body, order and all of a/t0 are right; only the colour
 *   of a parameter-copy web against the first call result differs. A load-defined p takes r4, a parameter copy takes
 *   r5. This is a probe, not a source form (the image copies the parameter). Idioms: two-long-lived-values-in-each-
 *   others-registers, a-derived-wide-local-keeps-a-coordinate-update-before-its-first-call, a-pos-accumulation-settles-
 *   a-callee-saved-rotation: no new form.
 * 2026-10-05 (wD9r lane213): still DIFF 26 bytes (p/a swap). Forms that make p a copy created like a different kind
 *   of web, each a real compile, all 26: static inline accessor `Obj(void *o)` called at entry; parameter `struct X *`
 *   with `u8 *p = (u8 *)o;`; `void *` parameter with p assigned after the first call; C99 `u8 *p = o;` first in the
 *   body; `u16 *q = o` with byte offsets cast from q; `u8 *const p = o;`; a pass-through `Self(o, x)` inline. One-field
 *   struct parameter by value (179 B, worse). Idioms read: two-long-lived-values-in-each-others-registers,
 *   a-field-read-into-its-own-local-before-a-getter-subtraction-sets-the-colour-order,
 *   a-result-computed-in-a-dying-local-takes-that-locals-register, const-on-a-read-only-source-parameter-settles-a-register-tie,
 *   a-long-loop-counter-keeps-its-copy-of-a-parameter-out-of-the-entry-guard: no new form. A parameter copy is
 *   coalesced with the incoming r0 whatever its source spelling, so only a load-defined p (lane208 probe) changes it.
 */
/*
 * 2026-10-05 (wFlags): EXACT (176 B, c99 and c) with `#pragma opt_lifetimes off` above the function (lifetime splitting off,
 *   per-function pragma, approved form). Plain -O4,p gave the 26 B p/a register swap; the other compiler versions and
 *   flags tried (wFlags) did not change it.
 * 2026-10-05 (wD9r laneS6): still DIFF 26 bytes (p/a swap). Draft code checked against HEAD (only notes differ, same 26 B).
 *   Read the mwcc source model (Coloring.c, SpillCode.c, ALLOCATOR_CASEBOOK.md; PPC build, same colour engine): webs
 *   with degree below K are pushed in ascending vreg order and the last pushed colours first; webs at or above K are
 *   pushed by minimum spill_cost/degree (def weight 2, use weight 1, times block weight), the lowest score colours
 *   last. The four long-lived webs here (p, a, xx, y0) all sit above K in Thumb (r4-r7 only), so the order is
 *   cost/degree, not declaration order. Test: locals declared xx, yy, y0, r, then a, t0 (a gets the lowest decl slot): 26,
 *   same swap, which agrees with the cost model (decl order inert). Model: p needs a higher cost/degree than a. a already
 *   has six defs (weight 2 each) that the image has too, and earlier extra p uses did not flip it, so the parameter-copy
 *   web seems to be ranked by a rule other than plain cost (a load-defined p is an ordinary web and wins). No further
 *   source form follows from the model; left DIFF.
 * 2026-10-05 (wD9r lane141): still DIFF 26 bytes (p/a swap). New try: p as an int parameter cast to u8 * at
 *   every use (no local copy, so no second vreg for p): 26, same code. The parameter's type and spelling do
 *   not move the colour order.
 * 2026-10-05 (wD9r lane134): still DIFF 26 bytes (p/a swap). New try: p as a const u8 * parameter (reads
 *   through const, the two end stores cast to u8 *): 26, same. Reading: the a-web has 16 uses against 12 for
 *   p; if this build colours the heavier web first, the image needs a split a-web that is not coalesced,
 *   which the separate t0/a/n locals already tried do not give.
 * 2026-10-05 (wD9r lane123): still DIFF 26 bytes (p/a swap). New tries, each a real compile: the bound result
 *   in a separate local n (`n = a; if (out) n = func_021642A4(a);`, n used by D410 and the 0x16 store): 26; the
 *   rect pointer read inline at each of the four bound reads (no r local, more p uses): 26; the end stores
 *   through a block-local `u16 *c = (u16 *)(p + 0x14)` (36, the add is kept); c set at the top and used for all
 *   0x14/0x16 accesses (174). Use count of p and a split of the last a-web do not move the colour order.
 * 2026-10-05 (wD9r lane103): still DIFF 26 bytes (p/a swap). New tries: the D410 call and both stores as a
 *   static inline SetCur(u32 a, u8 *p) with a first (26); the whole body as a static inline Body(u32 x, u8 *p)
 *   called from the real function, and as Body(u8 *p, u32 x) (26, both). Inline parameter order does not move
 *   the colour order.
 * 2026-10-05 (wD9r lane89): still DIFF 26 bytes (p/a swap). New tries: int t0 and a with the u32 prototypes (27);
 *   the final stores as ((u16 *)p)[10] / [11] (26); a third local d for the first-part result with a = d before
 *   the rect test, and with `else a = d` in each arm (26, both). Probes (stand-ins, not kept): `p = p;` at entry,
 *   after the first call, before the 41E8 sum, before the D410 call and at the end, and `a = a;` at the end: all
 *   26, so no definition point of p or a moves the colour order here.
 * 2026-10-05 (wD9r lane77): still DIFF 26 bytes (p/a swap). New tries: `register` on the p parameter (26);
 *   `register` on a (26); the bound test operands swapped (`p[3] == t0 || func_021642A4(t0) == p[3]`, 26, same
 *   code). The ov055 callers (021F4174, 021F41F0) pass (a, loc) with loc from func_021F42AC, so x is an
 *   object pointer as lane44 read; no twin of this routine exists in src/matched.
 * 2026-10-05 (wD9r lane62): still DIFF 26 bytes (p/a swap, the only diff). New tries: C99 declarations at
 *   first use with initialisers (t0, xx, y0 initialised from their calls, a/yy/r declared after them): 26,
 *   same; `a == 0 || a == 1` for the bound test (26, compiles identically); `a < 2` (28). Model test: with
 *   func_0216D5F8(0) instead of (x) the swap stays, so the x parameter web plays no part in it.
 * 2026-10-05 (wD9r lane44): still DIFF 26 bytes (p/a swap). Read: func_0216D5F8 is `ldrh r0,[r0,#0x18]`
 *   (x is an object pointer; t0/a is a direction), 41E8/41F8 are dx/dy tables, 42A4 the reverse direction.
 *   Tried: one variable a for t0 and a with `a = (u16)(a + 2)` in each rand arm (26, same; with the +2
 *   hoisted above the rand test: 168 B, layout breaks); D410 and both stores written in each out-of-range
 *   arm with return (226 B, tails not merged, swap stays); parameter x reused as a (178 B, x homed r4);
 *   x reused as xx or y0 (178 B, x copied to a callee-saved register at entry). Every form keeps p r5.
 * 2026-10-05 (wD9r lane34): still DIFF 26 bytes (p/a swap). Tried (all 26): p as a real struct
 *   pointer (fields b3, ha, obj, rect, active, cur); x as a u16 parameter; the matched prototypes
 *   (u16 func_0216D5F8(void *), u16 func_021642A4(u16), 021641E8/F8(u16), 0216D410(void *, u16)) with
 *   u16 t0/a (u32/int locals give 184 B); the final call and two stores as a static inline SetCur(p, a);
 *   p as a local copy of an int or void * parameter, assigned before or after the first call. Reading:
 *   the ov021 sibling 0219A8C0 gives the call result r4 and the parameters r5/r6 (reverse order), the
 *   same rule as this build; the image gives p r4, so p behaves like the first-defined local there.
 * 2026-10-05 (wD9r lane07): still DIFF 26 bytes (p/a swap). Tried: s16 nx/ny as new locals for the
 *   41E8/41F8 sums (26, same); the a <= 1 test as switch (a) {case 0: case 1: ... default:} (182 B, worse);
 *   int return with `return 1` (r0 = 1 at the exit in the image; 26, same); 0x14/0x16 as one struct copy
 *   (186 B, worse). Model tests (one call, then D410 and the two stores): p/a swap is present in every
 *   reduced form (no first part, no rect test, no xx/y0); in the reduced model only a LAST use of p after
 *   the last use of a (store a first, then 0x14 = 1) gives p r4, but in the full function that order is
 *   inert (still 26) and emits the stores in the wrong order.
 * 2026-10-05 (wD9 lane07): still DIFF 26 bytes (p/a swap). Tried: xx, yy, y0 as s16 with func_0216D83C/86C
 *   returning s16 (same 26); the rect test as a static inline Outside() returning 0/1 with one
 *   `if (Outside(..)) a = func_021642A4(a)` (77, the bool is not folded, swap stays).
 * 2026-10-05 (wD7 lane14): still DIFF 26 bytes. Tried: the second part (from the 021641E8 call to the end) as a static inline
 *   Fin(p, a, xx, y0) (same 26, p/a swap stays). Same residue shape as ov020 02186470 (parameter copied first gets r5, first
 *   long-lived call result gets r4).
 * 2026-10-05 (wave D6 lane 19): still DIFF, 26 bytes, p/a swap. Callee listings checked
 *   (rule 1): all six ov010 callees read r0 only, no hidden argument. Tried: the first part as a
 *   static inline returning a (same 26); the a <= 1 bound test as one ternary condition (worse, 188
 *   bytes); `goto out` with the tail written in both paths (79, swap stays); x reused as t0/a (167).
 * note (2026-10-05, wD5 lane01): now 26 bytes: r is loaded inside each arm of the a <= 1 test
 *   (the compiler hoists both loads to just after the cmp, as in the image). Residue: p/a colour
 *   swap only (image p r4, a r5; ours p r5, a r4). Tried, all inert: store order 0x16/0x14, u16
 *   returns for func_0216D5F8/func_021642A4 with u16 t0 and a, x0/xx and y0/yy split or merged,
 *   r as inline expression or two locals, declaration order of all locals (two orders), a copy of p.
 *   Worse: x reused as t0/a (167), the whole tail repeated per first-part arm (385), a join
 *   argument local for the shared func_021642A4 call (108). Model tests show that extra
 *   callee-saved locals (xx, y0) move p from r4 to r5 even when the first part matches, so the
 *   swap comes from the long-lived local set, not from the first part.
 * note (2026-10-05, wD4 lane17): still DIFF, 28 bytes, register names only (p r5/a r4 vs original p r4/a r5). New tries: t0 and a merged into one local (no change); `r` loaded inside each arm (moves the ldr after the cmp as in the original, 26 bytes left, not applied here); if-else inverted on the 0x14 test (74 bytes, block order breaks). The remaining residue is the colour of p versus the first call result.
 *
 * 2026-10-05 (wD8 lane09): still DIFF 26 bytes. Tried: x reassigned as t0 (`x = func_0216D5F8(x)`) with a
 *   separate a: worse (88 bytes, x takes r4 and p r5, the parameter copy order changes). The a-web gets the
 *   lower register in every form so far.
 * 2026-10-05 (wD9r lane148): still DIFF 26 bytes (p/a swap). New tries from the callee listings: real return
 *   types (021641E8/F8 return s16, `lsls/asrs`; 021642A4 and 0216D5F8 return u16) with u16 parameters, u16 t0/a
 *   and a u16 D410 parameter: 26, same swap (u32 t0/a with these prototypes: worse). A K&R definition
 *   `void func_021F3DD4(p, x) u8 *p; u32 x;`: 26, same. Block-by-block recheck of the logic against the listing
 *   found no difference.
 * 2026-10-05 (wD9r lane159): still DIFF 26 bytes (p/a swap). New tries from the narrow-local idiom: u16 a and
 *   t0 with u16 callee prototypes and the widening done through a static inline helper at each arithmetic use
 *   (`Add(u32 v, u32 k)` for t0 + 2 and for the 0xa field + a): 26, same; the helper with a u16 parameter: 26;
 *   u16 a with u32 t0: 178 B; u32 a with u16 t0: 182 B; u16 locals with u32 returns: 178 B. Narrow width of
 *   the cursor value does not move the colour order. Model finding (reduced model and the matched ov019
 *   0217F310): in a small function the parameter gets r4 when a register-offset access through p exists
 *   (`*(p + 0x400)` or `p + 0x2810`, pool offset) or when a constant store through p follows the last use of a;
 *   in this full function none of these flips it (extra p-only temps, 8 or 16 extra p stores, p + 0x400 at
 *   the top or end: all keep p r5). Of 79 game functions with the image shape (param r4, first call result r5),
 *   this one and ov019 0217F310 are the only ones whose first call does not read the parameter.
 * 2026-10-05 (wD9r lane173): still DIFF 26 bytes (p/a swap). Checked for a shared logic or type error: no
 *   matched twin calls 021641E8 with 021642A4 or 020056EC; callee bodies (42A4 table u16, 41E8 s16, 5F8 u16 field,
 *   83C int field, D410 (void *, u16)) agree with the draft; every result is used; p fields are read in listing
 *   order. New tries: t0 as a block-scope local of the first part only (26, same); the end stores through a
 *   block-local `u16 *c = (u16 *)p` as c[0xa] / c[0xb] (26, same).
 * 2026-10-05 (wD9r lane182): still DIFF 26 bytes (p/a swap). New tries from the colour idioms: `unsigned long`
 *   for a, for t0 and a, for xx/yy/y0 (long-colours-apart-from-int idiom): 26 each; p as a distinct local copy
 *   of a renamed parameter with a unsigned long (second-same-typed-local idiom): 26; static inline u16 field
 *   getter/setter H(p,k)/SH(p,k,v) for the 0x14/0x16 accesses: 26. Dying-local idiom: no dying local exists
 *   (x is dead after the first call but reusing it was tried by earlier lanes: 167 to 178 B).
 * 2026-10-05 (wD9r lane188): still DIFF 26 bytes (p/a swap). Read ov019 0217F310 in full (matched twin of the
 *   image shape): its parameter keeps r4 with FEWER uses than the first call result, so the colour order is not a plain
 *   use count there; its p accesses are register-offset (`ldr r0,[r4,r0]`), which this function does not have. New
 *   tries: the 0x16 field read into its own block local before `a = q` (idiom a-field-read-into-its-own-local-...):
 *   26; a pointer copy `pp = p` at entry used for both end stores: 26. Idioms read, no new form:
 *   a-call-between-a-buffer-handle-and-its-first-read-keeps-it-in-a-register,
 *   a-flag-set-after-the-call-that-consumes-its-input-shares-that-inputs-register.
 * 2026-10-05 (wD9r lane201): still DIFF 26 bytes (p/a swap). New tries: part 1 (the 0x14 test and the else chain)
 *   wrapped in `do { } while (0)` to raise block weight, and the whole pre-call part in it: both fold away in the
 *   front end, 26, same code. Use counts: p has about 12 uses, a about 16 (all in straight-line code, no loop in the
 *   listing, so no source change can give p a loop weight). Read the matched ov021 0219A8C0 (params r6/r5, call result
 *   r4: the most-used web takes r4, the later-defined local first), which agrees with a-first in our build; the image
 *   needs p first. Idioms read: a-derived-wide-local-keeps-a-coordinate-update-before-its-first-call (fresh local vs
 *   reuse: lanes 34/89 did it), a-pos-accumulation-settles-a-callee-saved-rotation (no accumulator here),
 *   a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie, a-spilled-pointer-parameter-tie-is-the-front-ends.
 *   No new form.
 * 2026-10-05 (wD9r lane208): still DIFF 26 bytes (p/a swap). Diagnostic: with the parameter changed to `u8 **pp` and
 *   `u8 *p = *pp;` as the first local (p defined by a load, not a parameter copy), the rest of the function matches:
 *   1 byte differs (`ldr r4,[r0]` for `adds r4,r0,#0`). So the body, order and all of a/t0 are right; only the colour
 *   of a parameter-copy web against the first call result differs. A load-defined p takes r4, a parameter copy takes
 *   r5. This is a probe, not a source form (the image copies the parameter). Idioms: two-long-lived-values-in-each-
 *   others-registers, a-derived-wide-local-keeps-a-coordinate-update-before-its-first-call, a-pos-accumulation-settles-
 *   a-callee-saved-rotation: no new form.
 * 2026-10-05 (wD9r lane213): still DIFF 26 bytes (p/a swap). Forms that make p a copy created like a different kind
 *   of web, each a real compile, all 26: static inline accessor `Obj(void *o)` called at entry; parameter `struct X *`
 *   with `u8 *p = (u8 *)o;`; `void *` parameter with p assigned after the first call; C99 `u8 *p = o;` first in the
 *   body; `u16 *q = o` with byte offsets cast from q; `u8 *const p = o;`; a pass-through `Self(o, x)` inline. One-field
 *   struct parameter by value (179 B, worse). Idioms read: two-long-lived-values-in-each-others-registers,
 *   a-field-read-into-its-own-local-before-a-getter-subtraction-sets-the-colour-order,
 *   a-result-computed-in-a-dying-local-takes-that-locals-register, const-on-a-read-only-source-parameter-settles-a-register-tie,
 *   a-long-loop-counter-keeps-its-copy-of-a-parameter-out-of-the-entry-guard: no new form. A parameter copy is
 *   coalesced with the incoming r0 whatever its source spelling, so only a load-defined p (lane208 probe) changes it.
 */
void func_021F3DD4(u8 *p, u32 x)
{
    u32 a;
    u32 t0;
    int xx;
    int yy;
    int y0;
    struct R *r;
    t0 = func_0216D5F8((void *)x);
    xx = func_0216D83C(*(void **)(p + 0xc));
    y0 = func_0216D86C(*(void **)(p + 0xc));
    if (*(u16 *)(p + 0x14) != 0) {
        a = *(u16 *)(p + 0x16);
    } else {
        if (t0 == p[3] || p[3] == func_021642A4(t0)) {
            if (func_020056EC(2) == 0) {
                a = (u16)(t0 + 2);
            } else {
                a = func_021642A4((u16)(t0 + 2));
            }
        } else {
            a = func_021642A4(t0);
        }
    }
    xx = (s16_021F3B20)(xx + func_021641E8(a));
    yy = (s16_021F3B20)(y0 + func_021641F8(a));
    if (a <= 1) {
        r = *(struct R **)(p + 0x10);
        if (yy < r->h0 || yy > r->h2) {
            a = func_021642A4(a);
        }
    } else {
        r = *(struct R **)(p + 0x10);
        if (xx < r->h4 || xx > r->h6) {
            a = func_021642A4(a);
        }
    }
    func_0216D410(*(void **)(p + 0xc), (u16)(*(u16 *)(p + 0xa) + a));
    *(u16 *)(p + 0x14) = 1;
    *(u16 *)(p + 0x16) = a;
}






#pragma opt_lifetimes reset






void func_021F3E84(S_021F3E84 *o, int b, int key, u16 c)
{
    void *h;
    int *tbl;
    u32 n, i;
    u32 m;
    int j;

    m = (c & 0x7fff) | 0x8000;
    h = func_020490F4(0xba, m);
    tbl = func_02049250(h, (int)5, (u16)m);
    n = func_020493D4(h, 5) >> 2;
    for (i = 0; i < n; i++) {
        if (key == tbl[i])
            break;
    }
    func_0204944C(h, i, 0, 0x32, o);
    func_020307B0(tbl);
    n = func_020493D4(h, 6);
    o->f38 = (int)func_02049250(h, (int)6, (u16)c);
    o->f3c = n >> 4;
    func_02049238(h);
    for (j = 0; j < 2; j++)
        o->cnt[j] = 0;
}





void func_021F3F20(unsigned char *p) { func_020307B0(((struct Obj13123 *)p)->f38); ((struct Obj13123 *)p)->f38=0; }






void func_021F3F30(S_021F3F30 *p, char *q, int k)
{
    int i;

    for (i = 0; i < p->n; i++) {
        u8 *e;
        if (p->cnt[i] >= p->lim[k]) {
            e = func_021F3B20((u8 *)q);
            if (e) {
                func_021F3F9C(q, (int)p, (const u16 *)(&p->ent[i]), e, 0);
                p->cnt[i] = 0;
            }
        } else {
            p->cnt[i]++;
        }
    }
}






/*
 * Levers, each measured: func_021F3D0C's u16 parameters (its own file) put
 * y in r7 and spill x; the else arm's x is an if/else, not a ternary (the
 * shared truncation then stays ahead of the c[0]/c[1] loads); u8 t0 moves
 * the stack parameter's load to the front of the prologue; const a and c
 * let the final call's field loads rise above the argument stores.
 */
void func_021F3F9C(const char *a, int b, const u16 *c, u8 *d, u16 e)
{
    int out;
    u16 x;
    u16 y;
    u8 t0;
    u32 rnd;
    u16 m;

    t0 = 0;
    rnd = func_020056EC(0);
    m = c[4];
    if (m <= 1) {
        x = c[2] + rnd % (c[3] - c[2] + 1);
        if (m == 0)
            y = c[0] - e;
        else
            y = c[0] + e;
    } else {
        if (m == 2)
            x = c[2] - e;
        else
            x = c[2] + e;
        y = c[0] + rnd % (c[1] - c[0] + 1);
    }
    if (func_021F3B48((struct Table *)a, x, y, m, 1, &out) == 0) {
        if (rnd % 10 == 0)
            t0 = 1;
    }
    if (out == 0)
        func_021F3D0C((struct O *)d, *(const int *)&((struct Obj05137 *)a)->f4, *(const int *)&((struct Obj05137 *)a)->f0, t0, x, y, c[4], (u16)(c[5] - e), (void *)c);
}





void func_021F405C(S_021F3B20 *p, char *q, int k)
{
    int i, j, n, acc;

    for (i = 0; i < p->n; i++) {
        n = (p->ent[i].w * 6) / p->lim[k];
        acc = 0;
        for (j = 0; j < n; j++) {
            u8 *e = func_021F3B20((u8 *)q);
            if (e) {
                func_021F3F9C(q, (int)p, (const u16 *)(&p->ent[i]), e, (u16)(acc / 6));
                acc += p->lim[k];
            }
        }
    }
}





u32 func_021F40F4(u8 *p)
{
    u32 v = p[0x18];

    if (v == 2)  return 0x14;
    if (v == 4)  return 0x10;
    if (v == 6)  return 0x4c;
    if (v == 8)  return 0xc;
    if (v == 16) return 8;
    return 0xc;
}




void func_021F4124(unsigned char *p) { func_0216DB4C(*(unsigned int * *)&((struct Obj00204 *)p)->fC,1); func_0216DC98(*(unsigned int * *)&((struct Obj00204 *)p)->fC,1); func_0216DAE0(*(unsigned int * *)&((struct Obj00204 *)p)->fC,0); func_0216D5B4((void *)(*(unsigned int *)&((struct Obj00204 *)p)->fC),2000); }




void func_021F414C(unsigned char *p) { func_0216DB4C(*(unsigned int * *)&((struct Obj07666 *)p)->fC,1); func_0216DC98(*(unsigned int * *)&((struct Obj07666 *)p)->fC,1); func_0216DAE0(*(unsigned int * *)&((struct Obj07666 *)p)->fC,1); func_0216D5B4((void *)(*(unsigned int *)&((struct Obj07666 *)p)->fC),2000); }





void func_021F4174(u8 *a, u32 b)
{
    u32 loc;

    switch (a[1]) {
    case 0:
        if (func_0216D454(*(u32 *)&((struct Obj00204 *)a)->fC) == 0) {
            return;
        }
        a[1] = a[1] + 1;
    case 1:
        if (((struct Obj00204 *)a)->f4 == 0) {
            a[1] = 2;
            return;
        }
        if (func_021F42AC(a, (void *)b, &loc, 2, 0)) {
            func_021F3DD4(a, loc);
        } else {
            func_0216D410((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), (u16)(((struct Obj00204 *)a)->fA + a[3]));
            ((struct Obj00204 *)a)->f4 = ((struct Obj00204 *)a)->f4 - 1;
        }
        a[1] = 0;
        return;
    case 2:
        func_021F3DBC(a);
        return;
    }
}





void func_021F41F0(u8 *a, u32 b, u32 c)
{
    u32 loc;
    void *x;

    switch (a[1]) {
    case 0:
        if (func_0216D454(*(u32 *)&((struct Obj00204 *)a)->fC) == 0) {
            return;
        }
        a[1] = a[1] + 1;
    case 1:
        if (((struct Obj00204 *)a)->f4 == 0) {
            a[1] = 2;
            return;
        }
        x = (void *)func_021A3074((void *)c);
        c = 1;
        if (func_021F4318(a, x, 1, 1)) {
            func_0216D5B4((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), ((struct Obj00204 *)a)->f6);
            return;
        }
        if (func_021F42AC(a, (void *)b, &loc, c, 0)) {
            func_021F3DD4(a, loc);
            func_0216D5B4((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), 0x7d0);
            func_021F3D90(a);
        } else {
            func_0216D410((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), (u16)(((struct Obj00204 *)a)->fA + a[3]));
            ((struct Obj00204 *)a)->f4 = ((struct Obj00204 *)a)->f4 - 1;
            func_0216D5B4((void *)(*(u32 *)&((struct Obj00204 *)a)->fC), 0x7d0);
        }
        a[1] = 0;
        return;
    case 2:
        func_021F3DBC(a);
        return;
    }
}





/*
 * d and e are u16, as are func_021F4318's last two parameters (its own
 * file): with u32 the stack parameter's load (ldr r6, [sp, #0x20]) sinks to
 * the first call instead of leading the prologue.
 */
int func_021F42AC(u8 *a, void *b, u32 *c, u16 d, u16 e)
{
    u32 iter = 0;
    u32 cur;

    while (func_0216DD1C(b, (struct Rec **)(&cur), &iter) == 1) {
        if (*(u32 *)&((struct Obj00204 *)a)->fC != cur && func_0216D55C(cur, 0x80) == 0 &&
            func_0216DAB4((void *)cur) == 0 && func_021F4318(a, (void *)cur, d, e) != 0) {
            *c = cur;
            return 1;
        }
    }
    return 0;
}





int func_021F4318(const u8 *a, void *b, u16 c, u16 d)
{
    int x0 = func_0216D83C(b);
    int y0 = func_0216D86C(b);
    int x1 = func_0216D83C(*(void * const *)&((struct Obj00204 *)a)->fC);
    int y1 = func_0216D86C(*(void * const *)&((struct Obj00204 *)a)->fC);
    int x2;
    int y2;

    if (func_021F4388(x1, y1, x0, y0, c, d, a[3])) {
        return 1;
    }
    x2 = func_0216D804(b);
    y2 = func_0216D81C(b);
    return func_021F4388(x1, y1, x2, y2, c, d, a[3]);
}




int func_021F4388(int a, int b, int c, int d, u16 hi, u16 lo, u16 dir)
{
    int x, y;

    switch (dir) {
    case 0:
        x = b - d;
        y = a - c;
        break;
    case 1:
        x = d - b;
        y = a - c;
        break;
    case 2:
        x = a - c;
        y = b - d;
        break;
    case 3:
        x = c - a;
        y = b - d;
        break;
    }
    if (x <= hi && x >= lo && y == 0) {
        return 1;
    }
    return 0;
}




void func_021F43D8(u32 *a, u32 b, s16_021F4388 *c, u32 d, u16 e)
{
    int i;
    u32 t;
    s16_021F4388 m;
    u16 *h = (u16 *)a;
    u8 *q;

    i = 0;
    t = func_020056EC(0);
    m = c[d];
    h[0] = i;
    h[1] = 0x10 + t % m;
    a[2] = (u32)func_02045B38(0, 3, 0x9f, e);
    a[3] = b;
    a[1] = t & 0xf;
    q = (u8 *)a + 0x10;
    for (i = 0; i < 16; i++) {
        func_021F4510((struct S_021F4388 *)(q + i * 8), (u16)i);
    }
}



void func_021F4430(unsigned char *p) { int i; for (i=0;i<16;i++) func_021F45A4((unsigned short *)(p+16+i*8),((struct Obj07667 *)p)->fC); ((struct Obj07667 *)p)->fC=0; func_02045C04(((struct Obj07667 *)p)->f8); ((struct Obj07667 *)p)->f8=0; }



void func_021F4458(unsigned char *p) { int i; for (i=0;i<16;i++) func_021F45A4((unsigned short *)(p+16+i*8),((struct Obj20580 *)p)->fC); }




void func_021F4474(s16_021F4388 *a, s16_021F4388 *b, int *c)
{
    int i;
    u32 rnd;
    int x;
    u8 *q;

    i = 0;
    rnd = func_020056EC(0);
    x = func_02189A38((int)c);
    if (func_02189A2C(c) == 0) {
        a[0] = a[0] + 1;
        if (a[0] >= a[1]) {
            func_021F4530((u16 *)((u8 *)a + 0x10 + ((u32 *)a)[1] * 8), ((u32 *)a)[3], ((u32 *)a)[2],
                          ((u8 *)b)[0x16], ((u8 *)b)[0x17]);
            a[0] = i;
            ((u32 *)a)[1] = (((u32 *)a)[1] + 1) & 0xf;
            a[1] = 0x10 + rnd % b[x];
        }
        i = 0;
        q = (u8 *)a + 0x10;
        for (; i < 16; i++) {
            func_021F4574((u16 *)(q + i * 8), ((u32 *)a)[3]);
        }
    } else {
        q = (u8 *)a + 0x10;
        for (i = 0; i < 16; i++) {
            func_021F45A4((u16 *)(q + i * 8), ((u32 *)a)[3]);
        }
    }
}



void func_021F4510(S_021F4388 *p, int i)
{
    p->a = 0;
    p->b = d_021F45E0[i];
    p->c = d_021F45D0[i];
    p->d = i;
    p->e = 0;
}




void func_021F4530(u16 *p, u32 a, u32 b, u32 c, u32 d)
{
    u32 r = func_020056EC(0);

    p[0] = 1;
    p[3] = 0;
    func_02191870((struct Fx *)a, b, c + r % d, p[2], ((u8 *)p)[2], ((u8 *)p)[3], 8, 2);
}




/*
 * Unlabelled leaf callee of func_021F4474.
 */
void func_021F4574(u16 *p, u32 x)
{
    if (p[0] != 0) {
        s16_021F4388 *c = (s16_021F4388 *)p + 3;

        *c = *c + 1;
        if (*c >= 0x10) {
            func_0219196C(x, p[2]);
            func_021F459C(p);
        }
    }
}




/*
 * Clear the two halfwords at 0x6 and 0x0.
 */
void func_021F459C(void *p)
{
    ((struct Obj05138 *)p)->f6 = 0;
    ((struct Obj05138 *)p)->f0 = 0;
}
