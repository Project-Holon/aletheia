/*
 * function: func_02180538
 * address:  0x02180538
 * packet:   pkt_ov018_02180538
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback: a 13-state sequence driving the Ov018Obj at +0x04. State 0
 * waits for the link partner and snapshots its 0x3C-byte record into +0xEC.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_021756A4  0x021756A4  thumb  ov011
 *   func_0217F2B4  0x0217F2B4  thumb
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_020127B8  0x020127B8  thumb
 *   func_02034714  0x02034714  arm
 *   func_02175DE4  0x02175DE4  thumb  ov011
 *   func_0200BE24  0x0200BE24  thumb
 *   func_0200BE00  0x0200BE00  thumb
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_0217F528  0x0217F528  thumb
 *   func_0217F574  0x0217F574  thumb
 *   func_0217F58C  0x0217F58C  thumb
 *   func_0217F4A0  0x0217F4A0  thumb
 *   func_02029830  0x02029830  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_0200823C  0x0200823C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF78  0x0200BF78  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F318  0x0217F318  thumb
 *   func_0217CA84  0x0217CA84  thumb
 *   func_0201235C  0x0201235C  thumb
 *   str_02183B48   0x02183B48  data   ov018  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    u32 f00;
    u32 lo : 4;
    u32 mid : 14;
    u32 f18 : 11;
    u32 hi : 3;
    u8 rest[0x3C - 8];
} Rec3C;

typedef struct {
    u16 f00;            /* 0x00 */
    u16 pad02;
    Ov018Obj obj;       /* 0x04 */
    void *f34;          /* 0x34 */
    u8 pad38[0xEC - 0x38];
    Rec3C fEC;          /* 0xEC */
    u16 f128;           /* 0x128 */
    u16 f12A;           /* 0x12A */
    int f12C;           /* 0x12C */
    u32 f130;           /* 0x130 */
    u8 f134;            /* 0x134 */
    u8 f135;            /* 0x135 */
    u16 f136;           /* 0x136 */
} Outer;

typedef struct {
    u8 f0 : 1;
    u8 rest : 7;
} B1;

extern char str_02183B48[];

typedef signed int     s32;
struct Big;
struct BigObj;
struct Ctx;
struct Evt;
struct Obj;
struct Rec1B0;
struct S0201235C;
struct WordSet;
void *func_020124E4(struct Obj *p);
struct Ctx;
u32 func_02012138(const struct Ctx *p);
void *func_020120F4(const struct Ctx *p);
struct Ctx;
void *func_0201210C(const struct Ctx *p);
u32 func_02026454(void *);
u32 func_02026474(void *obj);
u32 func_0200FB24(void);
int func_02175E90(void *p, u8 *q);
int func_02175DA8(u8 *);
u8 func_021756A4(char *p);
void func_0217F2B4(Ov018Obj *p, void *sub);
u8 *func_02175BCC(u8 *p);
void *func_020127B8(void *);
void func_02034714(const char *expr, u32 line, const char *file);
int func_02175DE4(u8 *, u8 *);
void func_0200BE24(struct Rec1B0 *p, s32 v);
void func_0200BE00(struct Rec1B0 *p, s32 v);
void func_021762D8(void *, void *, void *, u32);
void func_0217F528(Ov018Obj *p, void *sub, int b, int c, int d, int e);
void func_0217F574(void **p, unsigned int index, int a, int b);
void func_0217F58C(Ov018Obj *p);
void func_0217F4A0(void **p, unsigned int index, int a, int b);
void *func_02029830(void *a, u32 b);
void func_02012374(struct Evt *evt, struct Evt **out);
int func_02005F38(void);
void *func_02029620(void *a, u32 b, u32 c);
void *func_0201292C(const struct BigObj *p);
u32 func_02007FB8(u8 *base, u16 id, u16 d);
u32 func_0200823C(u32 a);
u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
void *func_02012EBC(struct Big *p);
u16 *func_0200BE48(void *sys);
u32 func_0200BF78(struct Rec1B0 *p);
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void func_0217F3C4(Ov018Obj *p, int a);
int func_0217F40C(Ov018Obj *p);
void func_0217F318(Ov018Obj *p);
int func_0217CA84(void *a, int b);
void func_0201235C(struct S0201235C *o, u32 *out);

int func_02180538(void *a, int *state, Outer *c)
{
    void *sub;
    void *t;
    void *w;
    u8 *v;
    Rec3C *e;
    void *h;
    void *m;
    u32 x;
    u32 n;

    sub = func_020124E4(a);
    t = (void *)func_02012138(sub);
    w = func_020120F4(sub);
    func_0201210C(sub);
    switch (*state) {
    case 0:
        v = 0;
        if (func_02026454(t) == 2) {
            v = (u8 *)func_02026474(t);
        }
        if (c->f34 == 0) {
            if (v != 0 && func_0200FB24() == 0 && func_02175E90(v, v + 0x1AC) == 1) {
                ((B1 *)(v + 0x904))->f0 = 1;
            }
            return 1;
        }
        if (v != 0 && func_02175DA8(v + 0x1AC) == 1 && func_021756A4((char *)v) == 1) {
            if (func_02175E90(v, v + 0x1AC) == 0) {
                return 1;
            }
            c->f134 = v[0x358];
            c->f135 = v[0x359];
            func_0217F2B4(&c->obj, sub);
            e = (Rec3C *)func_02175BCC(v + 0x1AC);
            h = func_020127B8(w);
            if (e == 0) {
                func_02034714(str_02183B48, 0, str_02183B48);
            }
            c->fEC = *e;
            c->f128 = e->lo;
            c->f12A = e->f18;
            c->f12C = func_02175E90(v, v + 0x1AC);
            c->f130 = func_02175DE4(v, v + 0x1AC);
            func_0200BE24(h, c->f135);
            func_0200BE00(h, c->f134);
            (*state)++;
            break;
        }
        if (v == 0 || func_0200FB24() != 0) {
            return 1;
        }
        break;
    case 1:
        func_021762D8(&c->fEC, (u8 *)c + 0x104, c->obj.f00, c->f00);
        func_0217F528(&c->obj, sub, 1, 4, 0x1E, 0x10);
        func_0217F574((void **)(&c->obj), c->f128, 8, 0);
        func_0217F574((void **)(&c->obj), c->f12A, 8, 0x10);
        (*state)++;
        break;
    case 2:
        c->f136++;
        if (c->f136 > 60) {
            func_0217F58C(&c->obj);
            *state = 3;
        }
        break;
    case 3:
        if (c->f12C == 1) {
            func_0217F4A0((void **)(&c->obj), 0x19, 0, 0);
            func_02012374(a, func_02029830(sub, 0x52C));
            *state = 4;
        } else {
            func_0217F4A0((void **)(&c->obj), 0x17, 0, 0);
            func_02012374(a, func_02029830(sub, 0x52D));
            *state = 11;
        }
        break;
    case 4:
        if (func_02005F38() == 0) {
            func_02012374(a, func_02029620(sub, 0, 6));
            m = func_0201292C(w);
            x = func_02007FB8(m, 0x23F, c->f00);
            n = c->f130;
            if (func_0200823C(0x23F) < x + n) {
                n = func_0200823C(0x23F) - x;
            }
            func_02007E50(m, 0x23F, n, c->f00);
            func_0200BF78((struct Rec1B0 *)func_0200BE48(func_02012EBC(w)));
            func_0201EFA4(c->obj.f00, 0, c->f130, 3, 0, 1);
            func_0217F3C4(&c->obj, 0x18);
            (*state)++;
        }
        break;
    case 5:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (c->f135 != 0) {
            func_0201EFA4(c->obj.f00, 0, c->f135, 3, 0, 1);
            func_0217F3C4(&c->obj, 0x30);
            (*state)++;
        } else {
            *state = 8;
        }
        break;
    case 7:
        if (func_0217F40C(&c->obj) == 1) {
            (*state)++;
        }
        break;
    case 8:
        if (c->f134 != 0) {
            func_0201EFA4(c->obj.f00, 0, c->f134, 3, 0, 1);
            func_0217F3C4(&c->obj, 0x31);
            (*state)++;
        } else {
            *state = 10;
        }
        break;
    case 9:
        if (func_0217F40C(&c->obj) == 1) {
            *state = 10;
        }
        break;
    case 10:
        *state = 12;
        break;
    case 11:
        if (func_02005F38() == 0) {
            func_02012374(a, func_02029620(sub, 0, 6));
            *state = 12;
        }
        break;
    case 12:
        func_0217F318(&c->obj);
        func_0201235C(a, (void *)func_0217CA84(sub, 0));
        return 0;
    }
    return 0;
}
