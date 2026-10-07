/*
 * file:     scrcmd_proc_p02.c
 * unit:     yes
 * function: func_0215BBD0, func_0215BCA0, func_0215BCE8, func_0215BD2C, func_0215BE24, func_0215BF30, func_0215BF7C, func_0215BFD4, func_0215C01C, func_0215C064
 * address:  0x0215BBD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215C510  0x0215C510  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017D30  0x02017D30  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020181F4  0x020181F4  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02008500  0x02008500  thumb
 *   func_0204589C  0x0204589C  arm
 *   func_02045808  0x02045808  arm
 *   func_02008550  0x02008550  thumb
 *   g0209DF08      0x0209DF08  data  a1
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0215B4DC  0x0215B4DC  thumb  ov010
 *   func_020185C4  0x020185C4  thumb
 *   d_02171180     0x02171180  data   ov010  a2
 *   d_0217118E     0x0217118E  data   ov010  a2
 *   d_02171190     0x02171190  data   ov010  a2
 *   func_02017A20  0x02017A20  thumb
 *   func_0216F948  0x0216F948  thumb  ov010
 *   func_0216FAA0  0x0216FAA0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */
struct BigObj;
struct Sav;
struct Buf;
struct Sub0200852CObj;
struct U16Vec;
struct Blk37;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u16 h;
    int p0;
    int p1;
    int p2;
    int z;
    int c0;
    int c1;
    int c2;
    int c3;
} Req;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u16 func_0215A5CC(void *);
extern void *func_02012934(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_02159B10(void *, void *);
extern int func_0215C510(void *a, void *b);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017D30(struct Sav *p);
extern void func_020180F4(void *p, int move);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_020181F4(void *p, u16 move, u32 slot);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02008500(void *player, void *str);
extern int func_0204589C(struct Buf *a, struct Buf *b);
extern void func_02045808(struct U16Vec *vec);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_0215A5F4(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017988(void *p, u32 a);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern u32 func_02017A20(void *p, u32 idx, u32 val);
extern u16 *func_0216F948(void *mon, u32 heap);
extern int func_0216FAA0(u16 *p);
extern u32 func_020307B0(void *p);
extern int func_0215B4DC(void *a0, void *a1, void *a2);
int func_0215BBD0(void *a0, void *a1);
int func_0215BCA0(int a0, int a1, int a2);
int func_0215BCE8(void *a0, void *a1);
int func_0215BD2C(void *c, void *vm);
int func_0215BE24(void *c, void *vm);
int func_0215BF30(void *a0, void *a1);
int func_0215BF7C(void *a0, void *a1);
int func_0215BFD4(int a0, int a1, int a2);
int func_0215C01C(void *a0, void *a1);
int func_0215C064(void *a0, void *a1);
extern u8 g0209DF08;
extern u16 d_02171180[];


/*
 * Sibling of func_0215BB50 (same request record, eight reads instead of
 * three, three of them clamped to 2), and of func_0215C200: the u16 locals
 * are what make the second clamp reload its value from the spill slot.
 */
int func_0215BBD0(void *a0, void *a1)
{
    void *h;
    u16 n;
    u16 *out;
    u16 t1;
    u16 t2;
    u16 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u16 t7;
    u16 t8;
    Req r;

    func_0215A5DC(a1);
    h = func_0215A5E4(a1);
    n = func_0215A5CC(a1);
    func_02012934(h);
    func_02012944(h);
    out = func_02159AE8(a0, a1);
    t1 = func_02159B10(a0, a1);
    t2 = func_02159B10(a0, a1);
    t3 = func_02159B10(a0, a1);
    t4 = func_02159B10(a0, a1);
    t5 = func_02159B10(a0, a1);
    t6 = func_02159B10(a0, a1);
    t7 = func_02159B10(a0, a1);
    t8 = func_02159B10(a0, a1);
    r.h = n;
    r.p0 = t1;
    r.p1 = t2;
    r.p2 = t3;
    r.z = t7;
    r.c0 = t4;
    if (r.c0 >= 3)
        r.c0 = 2;
    r.c1 = t5;
    if (r.c1 >= 3)
        r.c1 = 2;
    r.c2 = t6;
    if (r.c2 >= 3)
        r.c2 = 2;
    r.c3 = t8;
    *out = func_0215C510(h, &r);
    return 0;
}


int func_0215BCA0(int a0, int a1, int a2)
{
    int v0;
    int t4;
    int t5;
    int t6;
    u16 *q;
t5 = a0 + 0;
t4 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215BCAA:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BCB4:
a1 = a0 + 0;
a0 = t4 + 0;
a2 = (int)&v0;
t5 = 0;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215BCC0:
    if (a0 != 1) goto loc_0215BCE0;
loc_0215BCC4:
t4 = t5 + 0;
t6 = t5 + 0;
loc_0215BCC8:
a1 = t4 + 0;
    a0 = v0;
a1 = a1 + 0x36;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215BCD4:
    if (a0 == 0) goto loc_0215BCDA;
loc_0215BCD8:
t5 = t5 + 1;
loc_0215BCDA:
t4 = t4 + 1;
    if (t4 < 4) goto loc_0215BCC8;
loc_0215BCE0:
*q = t5;
a0 = 0;
    return a0;
}


int func_0215BCE8(void *a0, void *a1)
{
    u16 *out;
    void *k;
    char *p;
    void *v;

    out = func_02159AE8(a0, a1);
    k = (char *)func_02159B10(a0, a1);
    p = (char *)func_02159B10(a0, a1);
    if (func_0215B4AC(a1, (u32)k, &v) == 1) {
        *out = func_02017E1C(v, (u32)(p + 0x36), 0);
    } else {
        *out = 0;
    }
    return 0;
}


/*
 * Script command: reads a party slot, a move slot and a move. A move slot
 * past 4 goes to func_020180F4 (teach into a free slot); a zero move deletes
 * the slot, shifting the later moves (ids 0x36 move, 0x3A pp, 0x3E pp-ups)
 * down one; otherwise func_020181F4 sets the move into the slot.
 */
int func_0215BD2C(void *c, void *vm)
{
    u16 slot;
    u16 moveSlot;
    u16 move;
    void *mon;
    u32 saved;
    u8 i;
    u32 m;
    u32 ppUp;
    u32 pp;

    slot = func_02159B10(c, vm);
    moveSlot = func_02159B10(c, vm);
    move = func_02159B10(c, vm);
    if (func_0215B4AC(vm, slot, &mon) == 0) {
        return 0;
    }
    saved = func_02017D30(mon);
    if (moveSlot > 4) {
        func_020180F4(mon, move);
    } else if (move == 0) {
        i = moveSlot;
        if (moveSlot < 3) {
            for (; i < 3; i++) {
                m = func_02017E1C(mon, i + 0x37, 0);
                if (m == 0) {
                    break;
                }
                ppUp = func_02017E1C(mon, i + 0x3F, 0);
                pp = func_02017E1C(mon, i + 0x3B, 0);
                func_02017E40(mon, i + 0x36, m);
                func_02017E40(mon, i + 0x3E, ppUp);
                func_02017E40(mon, i + 0x3A, pp);
            }
        }
        func_02017E40(mon, i + 0x36, 0);
        func_02017E40(mon, i + 0x3E, 0);
        func_02017E40(mon, i + 0x3A, 0);
    } else {
        func_020181F4(mon, move, (u8)moveSlot);
    }
    func_02017D70(mon, saved);
    return 0;
}


/*
 * Script command: is the party member in the given slot the player's own
 * catch (trainer id, OT name, OT gender and game version all match)?
 * Writes the answer to a script variable.
 *
 * Levers (2026-09-28 tree_ov010_4): the allocation check as
 * `if (a && b) {...} else fail` (moves the failure block after the name
 * test), the name test as `== 0` (func_0204589C answers "equal"), and the
 * version read into a local before the compare (`cmp r0, r1`).
 */
int func_0215BE24(void *c, void *vm)
{
    void *player;
    void *mon;
    u16 *res;
    u32 slot;
    u32 heap;
    void *a;
    void *b;
    u32 ver;

    res = func_02159AE8(c, vm);
    slot = func_02159B10(c, vm);
    player = func_02012944(func_0215A5E4(vm));
    mon = 0;
    if (!func_0215B4AC(vm, slot, &mon)) {
        *res = 0;
        return 0;
    }
    if (func_02017E1C(mon, 7, 0) != func_02008530(player)) {
        *res = 0;
        return 0;
    }
    heap = func_0215A5CC(vm);
    a = func_020457B0(16, heap);
    b = func_020457B0(16, heap);
    if (a != 0 && b != 0) {
        func_02017E1C(mon, 0x8D, (u32)a);
        func_02008500(player, b);
        if (func_0204589C(a, b) == 0) {
            func_02045808(a);
            func_02045808(b);
            *res = 0;
            return 0;
        }
    } else {
        *res = 0;
        return 0;
    }
    func_02045808(a);
    func_02045808(b);
    if (func_02017E1C(mon, 0x9A, 0) != func_02008550(player)) {
        *res = 0;
        return 0;
    }
    ver = func_02017E1C(mon, 0x77, 0);
    if (ver != g0209DF08) {
        *res = 0;
        return 0;
    }
    *res = 1;
    return 0;
}


int func_0215BF30(void *a0, void *a1)
{
    void *k = (void *)func_02159B10(a0, a1);
    void *v = (void *)func_02159B10(a0, a1);
    void *h;
    void *e;

    func_0215A5F4(a1);
    h = func_020120F4(func_0215A5DC(a1));
    e = func_0201AB28(func_02012934(h), (u32)k);
    func_02017988(e, (u32)v);
    func_0200CFA0(func_0200CA1C(h), e);
    return 0;
}


int func_0215BF7C(void *a0, void *a1)
{
    void *k = (void *)func_02159B10(a0, a1);
    void *v = (void *)func_02159B10(a0, a1);
    void *w = (void *)func_02159B10(a0, a1);
    void *h;
    void *e;

    func_0215A5F4(a1);
    h = func_020120F4(func_0215A5DC(a1));
    e = func_0201AB28(func_02012934(h), (u32)k);
    func_02017A20(e, (u32)w, (u32)v);
    func_0200CFA0(func_0200CA1C(h), e);
    return 0;
}


int func_0215BFD4(int a0, int a1, int a2)
{
    int v0;
    int t5;
    int t6;
    int t7;
    void *buf;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215BFDE:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BFE8:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215A5CC((void *)a0);
loc_0215BFF0:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
a2 = (int)&v0;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215BFFC:
    if (a0 != 1) goto loc_0215C016;
loc_0215C000:
    a0 = v0;
a1 = t7 + 0;
    buf = func_0216F948((void *)a0, a1);
loc_0215C008:
    a0 = func_0216FAA0(buf);
loc_0215C00E:
*q = a0;
    a0 = func_020307B0(buf);
loc_0215C016:
a0 = 0;
    return a0;
}


int func_0215C01C(void *a0, void *a1)
{
    u16 *out = func_02159AE8(a0, a1);
    int k = func_02159B10(a0, a1);
    int j = func_02159B10(a0, a1);
    u16 t = func_0215B4DC(a1, (void *)k, (void *)0x95);

    if (t == d_02171180[j]) {
        *out = 1;
    } else {
        *out = 0;
    }
    return 0;
}


int func_0215C064(void *a0, void *a1)
{
    u16 *o0 = func_02159AE8(a0, a1);
    u16 *o1 = func_02159AE8(a0, a1);
    u16 *o2 = func_02159AE8(a0, a1);
    void *v;

    if (func_0215B4AC(a1, func_02159B10(a0, a1), &v) == 1) {
        *o0 = func_02017E1C(v, 0x92, 0);
        *o1 = func_02017E1C(v, 0x93, 0);
        *o2 = func_02017E1C(v, 0x94, 0);
    } else {
        *o0 = 0;
        *o1 = 0;
        *o2 = 0;
    }
    return 0;
}
