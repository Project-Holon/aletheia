/*
 * function: func_021CC390
 * address:  0x021CC390
 * packet:   pkt_ov021_021CC390
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five-step task callback (*state 0..4) that builds a mon through
 * func_021CC098, starts the ov119 and ov195 tasks and frees its work.
 *
 * Blocked (MATCH, every concrete byte right), three sites:
 *  - the pooled words 0x00000077 and 0x000000C3 are overlay ids (ov119_id,
 *    ov195_id) passed to func_020146F8's third argument; func_020146F8 is
 *    not in match.py's OVERLAY_ID_CONSUMERS and no pool word outside this
 *    range holds either value (same blocker as pending ov021_func_021CD348
 *    and ov021_func_021C5A54).
 *  - func_021CC38C is an unlabelled 4-byte leaf (`bx lr`, then 00 00
 *    padding) in ov021: `void func_021CC38C(void *p) {}`. Not filed here
 *    because the overlay ids cap this function at MATCH regardless; file it
 *    as pkt_ov021_021CC38C together with the id fix.
 * d_021E75A8 resolves only without its ov119 token (sole-ref on re-run).
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021CBFB0  0x021CBFB0  thumb  ov021
 *   func_021CC098  0x021CC098  thumb  ov021
 *   func_021CC23C  0x021CC23C  thumb  ov021
 *   func_021CC38C  0x021CC38C  thumb  ov021
 *   func_02012944  0x02012944  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0201AB48  0x0201AB48  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0201B2B0  0x0201B2B0  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021CC040  0x021CC040  thumb  ov021
 *   ov119_id       0x00000077  data  a1
 *   ov195_id       0x000000C3  data  a1
 *   d_021E75A8     0x021E75A8  data  a4
 *   d_02208C40     0x02208C40  data  ov195  a4
 *   d_021DE59C     0x021DE59C  data  ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    void *f8;
    void *fC;
    void *f10;
} Obj;

typedef struct {
    void *sys;      /* 0x00 */
    void *f4;       /* 0x04 */
    void *f8;       /* 0x08 */
    u8 fC;          /* 0x0C */
    u8 fD;          /* 0x0D */
    u8 padE[2];
    Obj *obj;       /* 0x10 */
    u8 f14[0x30];   /* 0x14 */
    void *f44;
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
} Work;

typedef struct {
    void *a;
    void *b;
    u16 h8;
    u8 bA;
    u8 bB;
    u32 fC;
    u32 f10;
} Req;

extern void *func_0201210C(void *sys);
extern void *func_0201AB28(void *party, int i);
extern Obj *func_021CBFB0(u32 a, u32 b);
extern void func_021CC098(void *a, u16 b, void *mon, void *d, u32 e);
extern void func_021CC23C(void *mon);
extern void func_021CC38C(void *p);
extern void *func_02012944(void *p);
extern void *func_020146F8(void *sys, void *h, const void *id, const void *tbl, void *arg);
extern void func_02012374(void *a, void *b);
extern void func_0201AB48(void *party, int idx, void *mon);
extern void *func_0200CA1C(void *p);
extern void func_0200CFA0(void *box, void *mon);
extern void func_0200CDE0(void *box, void *mon);
extern void *func_02012984(void *p);
extern u16 func_0201B2B0(void *a, void *b, u32 c, u32 d, void *e, u32 *f, u32 g);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_020307B0(void *p);
extern void func_021CC040(Obj *o);

extern const u8 ov119_id[];
extern const u8 ov195_id[];
extern u8 d_021E75A8[];
extern u8 d_02208C40[];
extern const char d_021DE59C[];

int func_021CC390(void *a, u32 *state, Work *w)
{
    void *sys = w->sys;
    void *f4 = w->f4;
    void *f8 = w->f8;
    void *h = func_0201210C(sys);
    void *m = func_0201AB28(f8, w->fD);
    Obj *o;
    void *t;
    void *box;
    u32 sel;
    u16 r;
    Req *q;

    switch (*state) {
    case 0:
        o = func_021CBFB0(4, w->fC);
        w->obj = o;
        func_021CC098(f4, 4, o->fC, o->f8, w->fC);
        func_021CC23C(w->obj->fC);
        func_021CC38C(w->obj->f8);
        *state = 1;
        break;
    case 1:
        t = func_0201210C(sys);
        w->f44 = f4;
        w->f50 = func_02012944(f4);
        w->f48 = m;
        w->f54 = w->obj->f10;
        w->f4C = w->obj->fC;
        func_02012374(a, func_020146F8(sys, t, ov119_id, d_021E75A8, w->f14));
        *state = 2;
        break;
    case 2:
        func_0201AB48(f8, w->fD, w->obj->fC);
        box = func_0200CA1C(f4);
        func_0200CFA0(box, w->obj->fC);
        func_0200CDE0(box, w->obj->fC);
        *state = 4;
        break;
    case 3:
        r = func_0201B2B0(f8, m, 1, 0, func_02012984(f4), &sel, 4);
        if (r != 0) {
            q = func_02030734(4, 0x14, 0, d_021DE59C, 0x1F0);
            q->a = f4;
            q->b = f8;
            q->h8 = r;
            q->bA = w->fD;
            q->bB = sel;
            q->fC = 1;
            q->f10 = 0;
            w->f58 = q;
            func_02012374(a, func_020146F8(sys, h, ov195_id, d_02208C40, q));
        }
        *state = 4;
        break;
    case 4:
        if (w->f58 != 0)
            func_020307B0(w->f58);
        func_021CC040(w->obj);
        return 1;
    }
    return 0;
}
