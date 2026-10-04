/*
 * function: func_0217EC7C
 * address:  0x0217EC7C
 * packet:   pkt_ov018_0217EC7C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02035D20  0x02035D20  arm
 *   func_021A0F94  0x021A0F94  thumb  ov021
 *   func_02012B58  0x02012B58  thumb
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_0217F284  0x0217F284  thumb  ov018
 *   func_0217EC44  0x0217EC44  thumb  ov018
 *   func_0217EC5C  0x0217EC5C  thumb  ov018
 *   func_02013DD0  0x02013DD0  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_020257C4  0x020257C4  thumb
 *   d_02176AA0     0x02176AA0  data  a4
 *
 * blocker:  byte-correct; the two THM_CALLs to func_02013DD0 (arm9) have no
 *           witness: 0x02013DD0 is an unlabelled arm9 leaf inside
 *           func_02013D9C's listing extent, called only from here. Verified
 *           EXACT (match.py one --region arm9 --thumb) as:
 *             extern const int d_0209DFC0[];   (0x0209DFC0 data a4)
 *             int func_02013B10(int a0, const int *a1, int a2);
 *             int func_02013DD0(int a0)
 *             { return func_02013B10(a0, d_0209DFC0, 4); }
 *           Once that leaf is filed and in a shard, this file verifies EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct { u16 a, b; u8 x, y; } Ent;

typedef struct {
    unsigned int lo : 20;
    unsigned int id : 10;
    unsigned int hi : 2;
} Mon;

typedef struct {
    int l, t, r, b;
} Rect;

typedef struct {
    u16 id;
    u8 pad02[0x1A];
} QEnt;

typedef struct {
    u8 pad00[0xA0];
    QEnt e[3];
} Q;

typedef struct {
    int f00;
    u8 pad04[0x8C - 0x04];
    int f8C[3];
    u8 pad98[0xC4 - 0x98];
    int fC4;
    u8 padC8[0xD8 - 0xC8];
    u8 fD8;
    u8 fD9;
    u8 padDA[0x106 - 0xDA];
    u8 f106;
    u8 f107;
    u8 pad108[0x110 - 0x108];
    u16 f110;
    u8 f112;
    u8 f113;
    u8 pad114[0x168 - 0x114];
    u8 f168;
    u8 f169;
} Obj;

extern int func_0201210C(int a0);
extern int func_02188CCC(int a0);
extern int func_02012138(int a0);
extern int func_020120F4(int a0);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021A0F94(u32 a);
extern int func_02012B58(int a0);
extern int func_0204B3F4(int a0);
extern void func_0204B454(int a0, s16 *a1, int a2);
extern Mon *func_0217BEA8(int a0);
extern int func_0217F284(Obj *p);
extern void func_0217EC44(int x, int y, int w, int h, Rect *r);
extern int func_0217EC5C(u32 x, u32 y, Rect *r);
extern int func_02013DD0(int a0);
extern void func_020061E4(u32 a);
extern u32 func_02013D5C(u32 id);
extern int func_020257C4(int a0);
extern const Ent d_02176AA0[];

void func_0217EC7C(Q *q, Obj *p, int id)
{
    Rect rect;
    u32 tx;
    u32 ty;
    s16 pt[2];
    int x;
    int sel;
    int h;
    int i;
    int w;
    int a;
    const Ent *e;
    Mon *m;

    x = func_02188CCC(func_0201210C(p->f00));
    func_02012138(p->f00);
    h = func_020120F4(p->f00);
    if (p->f112 != 0 || p->f106 == 1 || !func_02035D20(&tx, &ty) || func_021A0F94(x) != 0) {
        return;
    }
    sel = func_02012B58(h);
    for (i = 0; i < 3; i++) {
        if (i == sel) {
            continue;
        }
        if (!(p->fD9 & (1 << i))) {
            continue;
        }
        w = p->f8C[i];
        if (func_0204B3F4(w) != 1) {
            continue;
        }
        func_0204B454(w, pt, 0);
        if (tx - 12 > pt[0] || tx + 12 < pt[0]) {
            continue;
        }
        if (ty - 12 > pt[1] || ty + 12 < pt[1]) {
            continue;
        }
        if (q == 0) {
            continue;
        }
        if (func_0217BEA8(q->e[i].id) == 0) {
            continue;
        }
        p->f169 = i;
        return;
    }
    if (func_0217F284(p) == 1) {
        return;
    }
    if (p->fD8 != func_02012B58(h)) {
        for (i = 0; i < 8; i++) {
            e = &d_02176AA0[i];
            func_0217EC44(e->x, e->y, 0x10, 0x10, &rect);
            if (func_0217EC5C(tx, ty, &rect) != 1) {
                continue;
            }
            a = e->a;
            if (id == a || id == e->b || (func_02013DD0(id) == 1 && func_02013DD0(a) == 1)) {
                func_020061E4(0x557);
                return;
            }
            if (i == 7) {
                p->f106 = 1;
                p->f107 = 0;
            } else {
                m = func_0217BEA8(a);
                if (m == 0) {
                    continue;
                }
                p->f110 = m->id;
                p->f112 = 1;
            }
            p->f113 = i;
            return;
        }
    }
    if (p->fD8 != func_02012B58(h)) {
        func_0217EC44(0x80, 0x5C, 0x10, 0x10, &rect);
        if (func_0217EC5C(tx, ty, &rect) == 1) {
            if (func_02013D5C(id) == 1) {
                func_020061E4(0x557);
                return;
            }
            p->f110 = 0x117;
            p->f112 = 1;
            p->f113 = 8;
            return;
        }
    }
    if (p->f168 == 0 && func_020257C4(p->fC4) == 1) {
        func_0217EC44(0xE0, 0x80, 0x1E, 0xC, &rect);
        if (func_0217EC5C(tx, ty, &rect) == 1) {
            p->f168 = 1;
        }
    }
}
