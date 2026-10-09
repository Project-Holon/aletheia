/*
 * file:     intrude_field_p05.c
 * unit:     yes
 * function: func_0217C2A0, func_0217C37C, func_0217C458, func_0217C4D0, func_0217C658, func_0217C688
 * address:  0x0217C2A0
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
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_02166618  0x02166618  thumb  ov010
 *   func_02166640  0x02166640  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0217C1D0  0x0217C1D0  thumb  ov018
 *   func_0202A128  0x0202A128  thumb
 *   func_0202A170  0x0202A170  thumb
 *   func_02005728  0x02005728  thumb
 *   d_02183678     0x02183678  data  a4
 *   d_021835F8     0x021835F8  data  a4
 *   d_02183650     0x02183650  data  a4
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0217F2B4  0x0217F2B4  thumb  ov018
 *   func_02174E14  0x02174E14  thumb  ov011
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217F528  0x0217F528  thumb  ov018
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_0217F574  0x0217F574  thumb  ov018
 *   func_02029830  0x02029830  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   func_0217F58C  0x0217F58C  thumb  ov018
 *   func_02012B58  0x02012B58  thumb
 *   func_02173FC0  0x02173FC0  thumb  ov011
 *   func_02175A24  0x02175A24  thumb  ov011
 *   func_0217F318  0x0217F318  thumb  ov018
 *   func_020061E4  0x020061E4  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0217BCDC  0x0217BCDC  thumb  ov018
 *   func_0216D410  0x0216D410  thumb  ov010
 *   d_021836A0     0x021836A0  data  a1
 */
struct Mon;
struct Sub0200852CObj;
struct Obj00020;
struct Ctx;
struct Desc;
struct Obj;
struct Evt;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct {
    u32 species : 11;
    u32 move : 10;
    u32 f21 : 2;
    u32 f23 : 6;
    u32 f29 : 3;
} Entry;

typedef struct {
    int f0;
    int f4;
    int f8;
} Ctx;

typedef struct {
    int w[13];
} B52;

typedef struct {
    u16 h0;
    u16 pad2;
    void *w4;
    u8 pad8[0x30];
    B52 b38;
    u8 pad6c[0x18];
    u8 b84;
    u8 pad85[3];
} Obj;

typedef signed short s16;

typedef struct {
    void *f0;
    int f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    int f14;
} Rec;

typedef struct {
    u32 lo : 4;
    u32 mid : 14;
    u32 hi : 11;
    u32 top : 3;
} Bits;

typedef struct {
    u8 mask : 3;
    u8 rest : 5;
} Mask;

typedef struct {
    int f00;
    Bits f04;
    Mask f08;
    u8 pad09;
    u16 f0A[3];
    u8 f10[8];
    u8 f18[0x1C];
} Info;

typedef struct {
    u16 f00;
    int f04;
    u8 f08[0x30];
    Info f38;
    Rec f6C;
    u8 f84;
} Work;

typedef struct {
    void *f0;
    int f4;
    s16 f8, fA;
    u16 fC;
    u8 fE, fF, f10, f11, f12, f13;
    int f14;
} Rec_0217C658;

typedef struct {
    void *f0;
    unsigned char *f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    int f14;
} Rec_0217C688;

extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_020307B0(void *p);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void *func_020173F0(u16, u16, u64, int);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02018A00(void *p, u32 a, u32 b);
extern u32 func_02017988(void *p, u32 a);
extern u16 func_0201808C(void *, u16);
extern void func_020180F4(void *p, int move);
extern int func_02166618(int);
extern int func_02166640(int);
extern u16 func_02188C84(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern int func_0202A128(int);
extern void func_0202A170(int);
extern u32 func_02005728(u32 range);
extern void func_0217C1D0(Ctx *, Entry *, u16, u16, u16, int);
extern u8 *func_02175B34(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *, int, int);
extern void func_0217F2B4();
extern void func_02174E14(u8 *p, int a);
extern void *func_020124E4(struct Obj *p);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void func_0217F528(void *, void *, int, int, int, int);
extern void func_021762D8(Info *, void *, int, u16);
extern void func_0217F574(void **p, unsigned int index, int a, int b);
extern void *func_02029830(void *a, u32 b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_02005F38(void);
extern void *func_02029620(void *a, u32 b, u32 c);
extern void func_0217F58C(void *);
extern u8 func_02012B58(const struct BigObj *p);
extern int func_02173FC0(int a, u8 *b);
extern int func_02175A24(u8 *);
extern void func_0217F318(void *);
extern void func_020061E4(u32 a);
extern int func_02188BE8(void *);
extern int func_0216D3CC(int a0);
extern void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag);
extern void func_0216D410(void *a0, u16 a1);
void *func_0217C2A0(int heap, void *a1, const Entry *e);
void func_0217C37C(int a0, int a1, Entry *list, int a3, int kind);
struct Desc *func_0217C458(void *a0, void *a1, u8 *a2, int a3);
int func_0217C4D0(void *task, int *state, Work *w);
void func_0217C658(Rec_0217C658 *p, void *a, int b, u16 c, u8 d, u8 e);
int func_0217C688(Rec_0217C688 *r, void *a1);
extern const u8 d_02183678[20][2];
extern const u8 d_021835F8[20][2];
extern const u8 d_02183650[20][2];
extern const u8 d_021836A0[4];




/*
 * The const on the entry pointer is what lets the bitfield loads be
 * scheduled above the outgoing stack-argument stores (48 bytes otherwise).
 */
void *func_0217C2A0(int heap, void *a1, const Entry *e)
{
    u8 *tbl;
    u8 lvl;
    u32 id;
    u32 pid;
    void *mon;

    tbl = (u8 *)func_0204A1BC(0xE3, 0, 0, heap);
    lvl = tbl[e->species];
    func_020307B0(tbl);
    id = func_02008530((const struct Sub0200852CObj *)func_02012944(a1));
    pid = func_020186C8(id, (u16)e->species, (u16)e->f23, e->f21, 0, 0);
    mon = func_020173F0(e->species, lvl, -1, heap);
    func_02017588(mon, e->species, lvl, id, -1, pid);
    func_02018A00(mon, e->species, e->f23);
    func_02017988(mon, (u16)e->f23);
    if (e->move != 0) {
        if (func_0201808C(mon, e->move) == 0xFFFF)
            func_020180F4(mon, (u16)e->move);
    }
    return mon;
}




void func_0217C37C(int a0, int a1, Entry *list, int a3, int kind)
{
    const u8 (*tbl)[2];
    Ctx ctx;
    void *obj;
    u16 cx;
    u16 cy;
    int i;
    int dx;
    int dy;
    int x;
    int y;

    if (func_02166618(kind))
        tbl = d_02183678;
    else if (func_02166640(kind))
        tbl = d_021835F8;
    else
        tbl = d_02183650;

    ctx.f0 = func_0202A128(func_02188C84((u8 *)a0));
    ctx.f4 = a0;
    ctx.f8 = a1;
    obj = func_021A3074(func_02188CB4((void *)a0));
    cx = func_0216D83C(obj);
    cy = func_0216D86C(obj);

    for (i = 0; i < 20; i++) {
        if (list[i].species != 0) {
            dx = func_02005728(2) - 1;
            dy = func_02005728(2) - 1;
            x = dx + tbl[i][0];
            y = dy + tbl[i][1];
            if (cx == x && cy == y) {
                if (dx != 0)
                    x -= dx;
                else if (dy != 0)
                    y -= dy;
                else
                    x++;
            }
            func_0217C1D0(&ctx, &list[i], i, x, y, 0);
        }
    }
    func_0202A170(ctx.f0);
}




struct Desc *func_0217C458(void *a0, void *a1, u8 *a2, int a3)
{
    B52 *src;
    Obj *o;
    struct Desc *x;

    src = (B52 *)func_02175B34(a2 + 0x1AC);
    func_020120F4(a0);
    x = func_020122C0(a0, 0, func_0217C4D0, 0x88);
    o = func_020124E8((struct Obj *)x);
    func_02082BCC(o, 0, 0x88);
    o->h0 = a3;
    o->w4 = a1;
    o->b38 = *src;
    o->b84 = 1;
    func_0217F2B4((u8 *)o + 8, a0);
    func_02174E14(a2, 5);
    return x;
}



/*
 * Task callback registered by func_0217C458 (0x88-byte work, state word
 * in the second argument).
 */
int func_0217C4D0(void *task, int *state, Work *w)
{
    void *sys;
    u8 *peer;
    u16 hi;
    u8 t;

    sys = func_020124E4(task);
    peer = (u8 *)func_02158344((int)((void *)func_02012138(sys)));
    if (peer == 0 && *state == 0)
        *state = 8;

    switch (*state) {
    case 0:
        if (w->f84 == 0) {
            *state = 4;
            break;
        }
        func_0217F528(w->f08, sys, 1, 1, 0x1E, 0x10);
        func_021762D8(&w->f38, w->f38.f18, *(int *)w->f08, w->f00);
        hi = w->f38.f04.hi;
        func_0217F574((void **)w->f08, (u16)w->f38.f04.lo, 8, 0);
        func_0217F574((void **)w->f08, (u16)hi, 8, 0x10);
        (*state)++;
        break;
    case 1:
        func_02012374(task, func_02029830(sys, 0x52B));
        (*state)++;
        break;
    case 2:
        if (func_02005F38() == 0) {
            func_02012374(task, func_02029620(sys, 0, 6));
            (*state)++;
        }
        break;
    case 3:
        func_0217F58C(w->f08);
        (*state)++;
        break;
    case 4:
        t = (int)func_02012B58(func_020120F4(sys));
        func_0217C658((Rec_0217C658 *)(&w->f6C), sys, w->f04, w->f38.f0A[t], w->f38.f10[t], w->f38.f08.mask & (1 << t));
        (*state)++;
        break;
    case 5:
        if (func_0217C688((Rec_0217C688 *)(&w->f6C), peer) == 1)
            (*state)++;
        break;
    case 6:
        if (peer != 0) {
            if (func_02173FC0((int)peer, peer + 0x1AC) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 7:
        if (peer != 0) {
            if (func_02175A24(peer + 0x1AC) == 1)
                (*state)++;
        } else {
            (*state)++;
        }
        break;
    case 8:
        func_0217F318(w->f08);
        if (peer != 0)
            func_02174E14(peer, 0);
        return 1;
    }
    return 0;
}


/*
 * extent: two alignment bytes at 0x0217C686.
 */
void func_0217C658(Rec_0217C658 *p, void *a, int b, u16 c, u8 d, u8 e)
{
    func_02082BCC(p, 0, sizeof(Rec_0217C658));
    p->f0 = a;
    p->f4 = b;
    p->fC = c;
    p->fE = d;
    p->fF = e;
    p->fA = 15;
    p->f8 = p->fA;
}



/*
 * Per-frame step of the 0x18-byte record func_0217C758 initialises.
 */
int func_0217C688(Rec_0217C688 *r, void *a1)
{
    void *obj;
    s16 v;

    switch (r->f10) {
    case 0:
        r->fA = 15;
        r->f8 = r->fA;
        func_020061E4(0x738);
        r->f10++;
        break;
    case 1:
        if (func_02188BE8(r->f4) == 1) {
            obj = func_021A3074(func_02188CB4((struct Obj00020 *)r->f4));
            if (func_0216D3CC((int)obj) == 1) {
                if (r->fA >= 15 && r->f12 != 0 && d_021836A0[r->f11] == 1) {
                    r->f10++;
                    break;
                }
                r->f11 = (r->f11 + 1) & 3;
                v = r->fA;
                r->f8 = v;
                if (r->f12 == 0) {
                    r->fA--;
                    if (r->fA <= 1) {
                        func_020120F4(r->f0);
                        func_0217BCDC(a1, r->f0, r->fC, r->fE, r->fF);
                        r->f12++;
                    }
                } else if (v < 15) {
                    r->fA++;
                }
                func_0216D410(obj, d_021836A0[r->f11]);
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}
