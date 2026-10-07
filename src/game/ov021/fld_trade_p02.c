/*
 * file:     fld_trade_p02.c
 * unit:     yes
 * function: func_021CC23C, func_021CC38C, func_021CC390, func_021CC500, func_021CC544, func_021CC570
 * address:  0x021CC23C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021CBFB0  0x021CBFB0  thumb  ov021
 *   func_021CC098  0x021CC098  thumb  ov021
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0216C204  0x0216C204  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02014840  0x02014840  thumb
 *   d_021DE5A8     0x021DE5A8  data
 *   ov107_id       0x0000006B  data
 *   d_021F6D78     0x021F6D78  data  ov107
 */
struct BigObj;
struct Blk37;
struct Ctx;
struct Evt;
struct Party;
struct PartyMon;
struct Desc;
struct Obj;
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

typedef struct Task {
    void *f0;
    void *f4;
    void *f8;
    u8 fC;
    u8 fD;
    u8 padE[0x58 - 0xE];
    u32 f58;
} Task;

typedef struct Rec {
    u8 f0;
    u8 pad1[3];
    void *f4;
} Rec;

extern u32 func_02017E1C(void *obj, u32 key, u32 off);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0201AB28(void *p, u32 idx);
extern Obj *func_021CBFB0(u32 a, u32 b);
extern void func_021CC098(void *a, u16 b, void *mon, void *d, u32 e);
extern u8 *func_02012944(void *p);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *func_0200CA1C(void *p);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u8 func_02012984(const struct BigObj *p);
extern u32 func_0201B2B0(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_021CC040(Obj *o);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *p);
extern int func_0216C204(void *a, u8 *b);
extern void func_0215897C(void *a, void *b);
extern void *func_0215A5E4(void *a0);
extern void *func_02014840(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
void func_021CC23C(int obj);
void func_021CC38C(void *p);
int func_021CC390(void *a, u32 *state, Work *w);
void *func_021CC500(void *a, u32 b, u32 c);
int func_021CC544(void *task, void *p);
int func_021CC570(u32 unused, u32 a);
extern const u8 ov119_id[];
extern const u8 ov195_id[];
extern u8 d_021E75A8[];
extern u8 d_02208C40[];
extern const char d_021DE59C[];
extern const char d_021DE5A8[];
extern const u8 d_021F6D78[];
extern u8 ov107_id[];


/*
 * Straight unrolled key list: 33 calls to func_02017E1C(obj, key, 0).
 * EXACT* only because the follower at 0x021CC38C (`bx lr`) is an unlabelled
 * leaf, so the inferred extent runs long into its padding; report, not seeded.
 */
void func_021CC23C(int obj)
{
    func_02017E1C((void *)obj, 0, 0);
    func_02017E1C((void *)obj, 5, 0);
    func_02017E1C((void *)obj, 0x6f, 0);
    func_02017E1C((void *)obj, 6, 0);
    func_02017E1C((void *)obj, 7, 0);
    func_02017E1C((void *)obj, 8, 0);
    func_02017E1C((void *)obj, 9, 0);
    func_02017E1C((void *)obj, 0xa, 0);
    func_02017E1C((void *)obj, 0x6e, 0);
    func_02017E1C((void *)obj, 0x70, 0);
    func_02017E1C((void *)obj, 0xb, 0);
    func_02017E1C((void *)obj, 0xc, 0);
    func_02017E1C((void *)obj, 0xd, 0);
    func_02017E1C((void *)obj, 0xe, 0);
    func_02017E1C((void *)obj, 0xf, 0);
    func_02017E1C((void *)obj, 0x10, 0);
    func_02017E1C((void *)obj, 0x11, 0);
    func_02017E1C((void *)obj, 0x12, 0);
    func_02017E1C((void *)obj, 0x13, 0);
    func_02017E1C((void *)obj, 0x14, 0);
    func_02017E1C((void *)obj, 0x15, 0);
    func_02017E1C((void *)obj, 0x16, 0);
    func_02017E1C((void *)obj, 0x17, 0);
    func_02017E1C((void *)obj, 0x18, 0);
    func_02017E1C((void *)obj, 0x46, 0);
    func_02017E1C((void *)obj, 0x47, 0);
    func_02017E1C((void *)obj, 0x48, 0);
    func_02017E1C((void *)obj, 0x49, 0);
    func_02017E1C((void *)obj, 0x4a, 0);
    func_02017E1C((void *)obj, 0x4b, 0);
    func_02017E1C((void *)obj, 0x9a, 0);
    func_02017E1C((void *)obj, 0x9e, 0);
    func_02017E1C((void *)obj, 0x95, 0);
}

void func_021CC38C(void *p)
{
}


/*
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
 * Addresses are Black-image addresses.
 */
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
    u32 r;
    Req *q;

    switch (*state) {
    case 0:
        o = func_021CBFB0(4, w->fC);
        w->obj = o;
        func_021CC098(f4, 4, o->fC, o->f8, w->fC);
        func_021CC23C((int)w->obj->fC);
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
        func_02012374(a, func_020146F8(sys, (int)t, (int)ov119_id, (int)d_021E75A8, (int)w->f14));
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
            func_02012374(a, func_020146F8(sys, (int)h, (int)ov195_id, (int)d_02208C40, (int)q));
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


void *func_021CC500(void *a, u32 b, u32 c)
{
    void *t;
    void *x;
    void *h;
    Task *p;

    t = func_020120F4(a);
    x = func_02012934(t);
    h = func_020122C0(a, 0, (void *)func_021CC390, 0x5c);
    p = func_020124E8(h);
    p->f0 = a;
    p->f4 = t;
    p->f8 = x;
    p->fC = b;
    p->fD = c;
    p->f58 = 0;
    return h;
}


/*
 * Task step: hands the field's current map object to ov010 func_0215897C with a lookup through func_0216C204.
 *
 * Addresses are Black-image addresses.
 */
int func_021CC544(void *task, void *p)
{
    void *a = func_0215A5F4(p);
    void *b = func_0215A5DC(p);
    func_0215897C(a, (void *)func_0216C204((void *)b, (u8 *)func_0201210C(b)));
    return 1;
}


/*
 * Launches overlay 0x6B (107) over an 8-byte record with the ov107 process
 * table at 0x021F6D78, parks the result in the script slot.
 *
 * MATCH, bytes exact. Blocker: the two pooled ABS32 words ov107_id (0x6B)
 * and d_021F6D78 (ov107 data, contested/no witness) have no witness, and
 * func_02014840 is not in match.py OVERLAY_ID_CONSUMERS, so the overlay-id
 * class refuses both. Dropping the ov107 token (data a4) does not help.
 */
int func_021CC570(u32 unused, u32 a)
{
    void *s;
    void *sys;
    void *v;
    void *x;
    Rec *r;

    s = func_0215A5F4((void *)a);
    sys = func_0215A5DC((void *)a);
    v = func_0215A5E4((void *)a);
    x = func_0201210C((void *)sys);
    r = func_02030734(4, 8, 0, d_021DE5A8, 0x44);
    r->f0 = 0;
    r->f4 = v;
    func_0215897C(s, func_02014840(sys, (int)x, (u32)ov107_id, (int)d_021F6D78, (int)r, 0, (int)r));
    return 1;
}
