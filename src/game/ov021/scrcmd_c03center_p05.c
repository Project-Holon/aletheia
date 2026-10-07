/*
 * file:     scrcmd_c03center_p05.c
 * unit:     yes
 * function: func_021B636C, func_021B63D4, func_021B647C, func_021B654C, func_021B6590, func_021B65D8, func_021B6628, func_021B66B8, func_021B6708, func_021B6850, func_021B6904
 * address:  0x021B636C
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
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A2E4  0x0215A2E4  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02166C4C  0x02166C4C  thumb  ov010
 *   func_021CBFB0  0x021CBFB0  thumb  ov021
 *   func_021CC040  0x021CC040  thumb  ov021
 *   func_021CC060  0x021CC060  thumb  ov021
 *   func_021CC068  0x021CC068  thumb  ov021
 *   func_021CC500  0x021CC500  thumb  ov021
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201292C  0x0201292C  thumb
 *   func_02007FA0  0x02007FA0  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_020081DC  0x020081DC  thumb
 *   func_020212B0  0x020212B0  thumb
 *   func_02012FD8  0x02012FD8  thumb
 *   func_0200E7BC  0x0200E7BC  thumb
 *   func_02158F7C  0x02158F7C  thumb ov010
 *   func_02158F74  0x02158F74  thumb ov010
 *   func_0200E740  0x0200E740  thumb
 *   func_0200E7AC  0x0200E7AC  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_021B6934  0x021B6934  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0201293C  0x0201293C  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0202136C  0x0202136C  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_02009020  0x02009020  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_02008EAC  0x02008EAC  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02017988  0x02017988  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02007A18  0x02007A18  thumb
 *   func_0201747C  0x0201747C  thumb
 *   func_0201AB48  0x0201AB48  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_020075B0  0x020075B0  thumb
 *   d_021DE270     0x021DE270  data   ov021  a1
 *   func_02007698  0x02007698  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020079BC  0x020079BC  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0201AB8C  0x0201AB8C  thumb
 */
struct Ctx;
struct BigObj;
struct Obj;
struct Rec0200E7BC;
struct Strbuf;
struct WordSet;
struct Party;
struct PartyMon;
struct Sub020075B0Entry;
struct Sub020079BCEntry;
struct Sub02008EACObj;
struct Sub02008F80Obj;
struct Mon;
struct Sub0200852CObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_02159B10(void *a0, void *a1); /* u16 return on purpose: see note above */
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern int func_0215A2E4(int a, int b, int c, int d, int e, int f, unsigned short g);
extern void func_0215897C(void *vm, void *task);
extern u16 func_02188C84(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *, u32, u32);
extern void *func_02166C4C(void *a, void *b, void *c);
extern struct Obj *func_021CBFB0(u32 a, u32 b);
extern void func_021CC040(struct Obj *o);
extern u32 func_021CC060(u8 *p);
extern u32 func_021CC068(u8 *p);
extern void *func_021CC500(void *a, u32 b, u32 c);
extern void *func_0215A5E4(void *a0);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007FA0(u8 *base, u32 id);
extern u32 func_020056EC(u32);
extern u16 *func_020081DC(void *, int, u16);
extern u16 func_020212B0(u16);
extern void *func_02012FD8(void **p);
extern void func_0200E7BC(struct Rec0200E7BC *o, int idx, void *mon);
extern u32 func_02158F7C(u8 *p);
extern void *func_02158F74(void *);
extern u32 func_0200E740(const void *obj, u32 idx);
extern void *func_0200E7AC(void *obj, u32 idx);
extern u16 func_02045A98(void);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern int func_021B6934(void *);
extern u16 func_0215A5CC(void *a0);
extern u32 func_0201293C(const struct BigObj *p);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082D44(void *src, void *dst, u32 n);
extern u32 func_0202136C(u16 v);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_02008F08(int a0);
extern int func_02009020(void *obj, int v);
extern void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_020307B0(void *p);
extern u32 func_02017988(void *p, u32 a);
extern void func_020185C4(void *mon);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *func_020185F0(void *mon);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern int func_02007698(void);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);
extern u32 func_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap);
int func_021B636C(void *a, void *b);
u32 func_021B63D4(void *a, void *b);
int func_021B647C(void *a, void *b);
u32 func_021B654C(void *a, void *b);
u32 func_021B6590(void *a, void *b);
u32 func_021B65D8(void *a, void *b);
int func_021B6628(void *a, void *b);
u32 func_021B66B8(void *a, void *b);
void func_021B6708(u32 a, int idx);
int func_021B6850(u32 a, u16 b, u16 *c, u16 *d);
void func_021B6904(void *a);
extern u8 d_021DE270[];


int func_021B636C(void *a, void *b)
{
    u16 *t10;
    u16 *t6;
    u16 tc;
    u16 t4;
    void *p7;
    void *p5;

    t10 = func_02159AE8(a, b);
    t6 = func_02159AE8(a, b);
    tc = func_02159B10(a, b);
    t4 = func_02159B10(a, b);
    p7 = func_0215A5F4(b);
    p5 = func_0215A5DC(b);
    func_0215897C(p7, (void *)func_0215A2E4((int)p5, (int)func_0201210C(p5), tc, (int)t10, (int)t6, t4 == 0, t4));
    return 1;
}


u32 func_021B63D4(void *a, void *b)
{
    u16 *out = func_02159AE8(a, b);
    void *p10 = func_0215A5F4(b);
    void *pc = func_0215A5DC(b);
    void *t8 = func_0201210C(pc);
    void *t;
    void *party;
    int n;
    int i;

    func_02188C84(t8);
    t = func_020120F4(pc);
    func_02012944(t);
    party = func_02012934(t);
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);
        u32 x = func_02017E1C(mon, 0x4c, 0);
        u32 y = func_02017E1C(mon, 3, 0);
        u32 z = func_02017E1C(mon, 9, 0);

        if (x != 0 && y == 0 && z == 0) {
            func_0215897C(p10, func_02166C4C(pc, t8, mon));
            *out = i;
            return 1;
        }
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021B647C(void *a, void *b)
{
    void *sys;
    void *w;
    u32 heap;
    u16 *out;
    u32 i2;
    u32 idx;
    void *mon;
    void *obj;
    u32 v;

    func_0215A5F4(b);
    sys = func_0215A5DC(b);
    w = func_020120F4(sys);
    heap = func_02188C84(func_0201210C(sys));
    out = func_02159AE8(a, b);
    i2 = func_02159B10(a, b);
    idx = func_02159B10(a, b);
    mon = func_0201AB28(func_02012934(w), idx);
    obj = func_021CBFB0(heap, i2);
    *out = 0;
    if (*out == 0 && func_02017E1C(mon, 0x4c, 0) == 1) {
        *out = 1;
    }
    if (*out == 0) {
        v = func_02017E1C(mon, 5, 0);
        if (v != func_021CC060(obj)) {
            *out = 2;
        }
    }
    if (*out == 0 && func_021CC068(obj) != 2) {
        v = func_02017E1C(mon, 0x6e, 0);
        if (v != func_021CC068(obj)) {
            *out = 3;
        }
    }
    func_021CC040(obj);
    return 0;
}


u32 func_021B654C(void *a, void *b)
{
    void *r7 = func_0215A5F4(b);
    void *x = func_0215A5DC(b);
    u32 t = func_02159B10(a, b);
    u32 u = func_02159B10(a, b);
    func_0215897C(r7, func_021CC500(x, (u8)t, (u8)u));
    return 1;
}


u32 func_021B6590(void *a, void *b)
{
    u16 *out = func_02159AE8(a, b);
    void *sv = func_0201292C(func_0215A5E4(b));
    int k = 2;
    u32 t = func_02007FA0(sv, 2);
    u32 id = func_020056EC(t);
    u16 v;

    if (t == 0)
        v = 0;
    else
        v = func_020212B0(*func_020081DC(sv, k, id));
    *out = v;
    return 0;
}


u32 func_021B65D8(void *a, void *b)
{
    void *t;
    void *w;
    int i;
    int j;

    func_0215A5F4(b);
    t = func_020120F4(func_0215A5DC(b));
    w = func_02012FD8(t);
    t = func_02012934(t);
    i = func_02159B10(a, b);
    j = func_02159B10(a, b);
    func_0200E7BC(w, j, func_0201AB28(t, i));
    return 0;
}


/*
 * The else arm zero is an array initialiser: `u16 s[1] = {0}` keeps &s in r6
 * for the call argument while the result store gets a fresh add sp.
 */
int func_021B6628(void *a, void *b)
{
    void *t;
    void *w;
    u32 i;
    u32 j;
    void *x;
    void *y;

    t = func_0215A5F4(b);
    w = func_02012FD8(func_020120F4(func_0215A5DC(b)));
    i = func_02159B10(a, b);
    j = func_02159B10(a, b);
    x = (void *)func_02158F7C(t);
    y = func_02158F74(t);
    if (func_0200E740(w, i)) {
        func_02045924(x, func_0200E7AC(w, i));
    } else {
        u16 s[1] = {0};
        s[0] = func_02045A98();
        func_02045924(x, s);
    }
    func_0201EE0C(y, j, x, 0, 1, 2);
    return 0;
}


u32 func_021B66B8(void *a, void *b)
{
    u32 op = func_02159B10(a, b);
    u16 *out = func_02159AE8(a, b);
    void *x = func_0215A5E4(b);

    switch (op) {
    case 0:
        if (func_021B6934(x) < 0)
            *out = 0;
        else
            *out = 1;
        break;
    case 1:
        func_021B6904(b);
        break;
    case 2:
        func_021B6708((u32)b, *out);
        func_021B6904(b);
        break;
    }
    return 0;
}


void func_021B6708(u32 a, int idx)
{
    void *sv;
    void *party;
    u32 heap;
    void *save;
    void *mon;
    u32 sz;
    void *o;
    void *buf;
    int i;
    void *m;
    u16 pos[2];

    sv = func_0215A5E4((void *)a);
    party = func_02012934((void *)sv);
    if (func_021B6850((u32)sv, 0x283, &pos[1], &pos[0]) == 0) {
        return;
    }
    heap = func_0215A5CC((void *)a);
    save = (void *)func_0201293C(sv);
    mon = func_02030734(heap, func_020173EC(), 1, (const char *)d_021DE270, 0x4c7);
    sz = func_020173EC();
    func_02082D44(func_0201AB28(party, idx), mon, sz);
    if (func_0202136C(func_02017E1C(mon, 6, 0)) == 1) {
        o = func_02008FEC(sv);
        buf = func_02008F08(func_0215A5CC((void *)a));
        i = func_02009020(o, 0);
        func_02017E1C(mon, 0xa7, (u32)buf);
        func_02012944(sv);
        if (i >= 0) {
            func_0200903C(o, 0, i, buf);
        }
        func_02008EAC(buf);
        func_02017E40(mon, 0xa7, (u32)buf);
        func_02017E40(mon, 6, 0);
        func_020307B0(buf);
    }
    if (func_02017E1C(mon, 0xab, 0) == 0x1ec) {
        func_02017988(mon, 0);
        func_020185C4(mon);
    }
    m = func_0201747C((struct Mon *)func_02007A18(save, pos[1], pos[0]), heap);
    func_0201AB48(party, idx, m);
    func_020307B0(m);
    func_020075B0(save, pos[1], pos[0], func_020185F0(mon));
    func_020307B0(mon);
}


int func_021B6850(u32 a, u16 b, u16 *c, u16 *d)
{
    int base;
    int i;
    u32 t10;
    int j;
    int m;
    u32 r4;
    u32 r6;

    func_02012934((void *)a);
    r4 = (u32)func_02012944((void *)a);
    r6 = func_0201293C((const struct BigObj *)a);
    base = func_02007698();
    t10 = func_02008530((const struct Sub0200852CObj *)r4);
    for (i = 0; i < 24; i++) {
        m = (i + base) % 24;
        for (j = 0; j < 30; j++) {
            if (func_020079BC((void **)r6, m, j, 0xa9, 0) != 0
                && t10 == func_020079BC((void **)r6, m, j, 7, 0)
                && b == func_020079BC((void **)r6, m, j, 5, 0)
                && func_020079BC((void **)r6, m, j, 0x4c, 0) == 0) {
                *c = m;
                *d = j;
                return 1;
            }
        }
    }
    return 0;
}


void func_021B6904(void *a)
{
    void *t;
    void *u;
    int r;

    t = func_0215A5E4(a);
    u = func_02012934(t);
    r = func_021B6934(t);
    if (r >= 0) {
        func_0201AB8C(u, r, 0, func_0215A5CC(a));
    }
}
