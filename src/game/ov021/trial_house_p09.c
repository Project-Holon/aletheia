/*
 * file:     trial_house_p09.c
 * unit:     yes
 * function: func_021CF560, func_021CF564, func_021CF580, func_021CF59C, func_021CF5AC, func_021CF5D8, func_021CF748, func_021CF7DC, func_021CF844, func_021CF8E4, func_021CF940, func_021CF9AC, func_021CFA04, func_021CFA1C, func_021CFA58
 * address:  0x021CF560
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
 *   func_02034AC4  0x02034AC4  arm
 *   abs_id_4b      0x0000004B  data
 *   abs_id_4d      0x0000004D  data
 *   ov075_id       0x0000004B  data
 *   func_02034A5C  0x02034A5C  arm
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013E40  0x02013E40  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB2BC  0x021AB2BC  thumb  ov021
 *   func_021AB364  0x021AB364  thumb  ov021
 *   func_021AB37C  0x021AB37C  thumb  ov021
 *   func_0202A230  0x0202A230  thumb
 *   func_0202A3FC  0x0202A3FC  thumb
 *   func_0202A3D8  0x0202A3D8  thumb
 *   func_02188D58  0x02188D58  thumb  ov021
 *   func_020140D8  0x020140D8  thumb
 *   d_021DB7E0     0x021DB7E0  data  ov021  a2
 *   d_021DB7F6     0x021DB7F6  data  ov021  a1
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_020079BC  0x020079BC  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBEC  0x0200BBEC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   abs_id_39      0x00000039  data
 *   d_021F3900     0x021F3900  data  ov057  a4
 */
struct Res021CF;
struct Obj00020;
struct Sub020140BCObj;
struct Desc;
struct Obj;
struct Sub0200852CObj;
struct Ctx;
struct BigObj;
struct Big;
struct IdList021CFA1C;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Res021CF {
    u8 pad0[0xc];
    u32 ids[3];
    int n;
} Res021CF;

typedef signed int     s32;

typedef int BOOL;

typedef struct Work_021CF7DC {
    u32 f00;
    u32 f04;
    u16 *f08;
    u32 f0c;
} Work_021CF7DC;

typedef struct Work_021CF844 {
    u32 f00;
    int f04;
    u16 *f08;
    int f0c;
} Work_021CF844;

typedef struct IdList021CFA1C {
    int n;
    int ids[50];
} IdList021CFA1C;

extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern u16 func_02188C9C(u8 *p);
extern u16 func_02013E40(u32 a);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_021A30C8(void **ctx);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern BOOL func_021AB2BC(u16 id);
extern BOOL func_021AB364(u16 id);
extern int func_021AB37C(u32 id);
extern u32 func_0202A230(void *a, u32 idx);
extern u8 func_0202A3FC(u32 key);
extern u8 func_0202A3D8(u32 key);
extern u32 func_02188D58(u8 *p);
extern u8 func_020140D8(struct Sub020140BCObj *p);
extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
extern void *func_0215A5F4(void *vm);
extern u16 *func_02159AE8(void *c, void *vm);
extern void  func_0215897C(void *vm, void *task);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u8 *func_02012944(void *p);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_020124E4(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32   func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0201293C(const struct BigObj *p);
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *p);
extern void *func_0200BBEC(void *base, u32 i, u32 j);
extern u32   func_02017E88(void *p, u32 id, u32 v);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188D24(u8 *p);
extern int *func_021BB990(int a, int *d, const int *c);
u32 func_021CF560(u32 *p);
void func_021CF564(Res021CF *r, u32 id);
void func_021CF580(void *r);
void func_021CF59C(struct Res021CF *r);
void func_021CF5AC(Res021CF *r);
void func_021CF5D8(int id, int kind, int flag, struct Obj00020 *pos, u32 *outType, u16 *outMsg);
void func_021CF748(u32 a, u32 x, int *out, u16 *out2);
int func_021CF7DC(void *c, void *vm);
int func_021CF844(void *a, int *task, Work_021CF844 *w);
int func_021CF8E4(void *a, void *src, int c);
int func_021CF940(void *a, void *src, void *b, int *c);
int func_021CF9AC(void *a, void *heap, int x, int y);
int func_021CFA04(int a, int v, void *l);
int func_021CFA1C(int v, IdList021CFA1C *l);
int func_021CFA58(void *a, void *b);
extern char abs_id_4b[];
extern char abs_id_4d[];
extern unsigned char ov075_id[];
extern const u16 d_021DB7E0[];
extern const u8  d_021DB7F6[];
extern char abs_id_39[];
extern char d_021F3900[];


/*
 * Addresses are Black-image addresses.
 */
u32 func_021CF560(u32 *p)
{
    return p[7];
}


void func_021CF564(Res021CF *r, u32 id)
{
    func_02034AC4(id);
    r->ids[r->n++] = id;
}


/*
 * 0x4B and 0x4D are FS_OVERLAY_ID symbols: func_021CF564 forwards its r1
 * to func_02034AC4 (overlay_id class, ov021-qualified consumer entry,
 * 2026-10-02).  The listing extent (44 bytes) also covers an unlabelled
 * thunk at 0x021CF59C.
 */
void func_021CF580(void *r)
{
    func_021CF564(r, (u32)abs_id_4b);
    func_021CF564(r, (u32)abs_id_4d);
}


/*
 * Thumb tail call through r3; the second argument is the ov075 overlay id
 * (a pool word, 0x4B).
 */
void func_021CF59C(struct Res021CF *r)
{
    func_021CF564(r, (u32)ov075_id);
}


void func_021CF5AC(Res021CF *r)
{
    int i;

    if (r->n > 0) {
        while (r->n > 0) {
            i = r->n - 1;
            if (r->ids[i] != 0) {
                func_02034A5C(r->ids[i]);
            }
            r->n--;
        }
    }
}


/*
 * func_02013E40 returns u16 (its body ends in ldrh); declaring it u32, or
 * keeping its result in a u32 local, hoists the spilled local's reload
 * above the final *outType store (4 bytes).
 *
 * Addresses are Black-image addresses.
 */
void func_021CF5D8(int id, int kind, int flag, struct Obj00020 *pos, u32 *outType, u16 *outMsg)
{
    u32 attr;
    u16 m;
    u16 sp;
    u32 type;
    u16 msg;

    sp = func_02013E40(func_02188C9C((u8 *)pos));
    switch (id) {
    case 0x23B:
        *outMsg = 0x469;
        *outType = 0x23;
        return;
    case 0x283:
        *outMsg = 0x474;
        *outType = 0x20;
        return;
    case 0x284:
        *outMsg = 0x475;
        *outType = 0x20;
        return;
    case 0x286:
        *outMsg = 0x476;
        *outType = 0x20;
        return;
    case 0x27D:
        *outMsg = 0x468;
        *outType = 0x1f;
        return;
    case 0x1EE:
        *outMsg = 0x478;
        *outType = 0x1f;
        return;
    case 0x27E:
    case 0x27F:
    case 0x280:
    case 0x287:
        *outMsg = 0x478;
        *outType = 0x22;
        return;
    case 0x281:
    case 0x282:
    case 0x285:
        *outMsg = 0x477;
        *outType = 0x21;
        return;
    }
    if (kind == 1) {
        *outMsg = 0x469;
        *outType = 0x1f;
        return;
    }
    if (kind == 4) {
        if (sp == 0xd6) {
            *outMsg = 0x469;
        } else {
            *outMsg = 0x468;
        }
        *outType = 2;
        return;
    }
    attr = func_021A30C8(func_02188CB4(pos));
    m = func_021AB0F0(attr);
    if (func_021AB0F8(attr) & 2) {
        msg = 0x468;
        type = 2;
    } else if (func_021AB2BC(m)) {
        if (flag) {
            msg = 0x469;
            type = 1;
        } else {
            msg = 0x468;
            type = 0;
        }
    } else if (func_021AB364(m)) {
        msg = 0x468;
        type = 0;
    } else {
        if (func_021AB37C(m)) {
            msg = 0x468;
            type = 4;
        } else {
            msg = 0x468;
            type = 3;
        }
    }
    *outType = type;
    if (sp == 0xd6) {
        *outMsg = 0x469;
    } else {
        *outMsg = msg;
    }
}


/*
 * Picks a value pair from two small tables, or a state code from the field
 * state when the index is out of range.
 *
 * Addresses are Black-image addresses.
 */
void func_021CF748(u32 a, u32 x, int *out, u16 *out2)
{
    int flag = 1;
    u32 t = func_0202A230((void *)a, 1);
    u32 k = func_0202A3FC(t);
    u32 m = func_0202A3D8(t);
    int code;

    if (k < 0xb) {
        *out2 = d_021DB7E0[k];
        *out = d_021DB7F6[m];
        return;
    }
    {
        u32 y = func_021A30C8(func_02188CB4((void *)x));
        u32 z = func_021AB0F0(y);

        if (func_021AB0F8(y) & 2) {
            code = 6;
        } else if (func_021AB37C(z) != 0) {
            code = 8;
        } else {
            if (func_020140D8((struct Sub020140BCObj *)func_02188D58((u8 *)x)) == 0) {
                flag = 0;
            }
            code = 5;
            if (flag == 0) {
                code = 7;
            }
        }
    }
    *out2 = 0x46a;
    *out = code;
}


/*
 * Script command: starts the func_021CF844 task over a 0xD8-byte work and
 * fills its header.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF7DC(void *c, void *vm)
{
    void *owner = func_0215A5F4(vm);
    void *sys = func_0215A5DC(vm);
    void *heap = func_0215A5E4(vm);
    u16 *var = func_02159AE8(c, vm);
    void *task;
    void *h2;
    Work_021CF7DC *w;

    task = func_020122C0(sys, 0, func_021CF844, 0xd8);
    h2 = func_02012944(heap);
    w = func_020124E8(task);
    w->f00 = func_02008530(h2);
    w->f0c = 0;
    w->f04 = 0;
    w->f08 = var;
    func_0215897C(owner, task);
    return 1;
}


/*
 * Task body started by func_021CF7DC: a three-state counter walk.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF844(void *a, int *task, Work_021CF844 *w)
{
    int *out;
    int flag = 0;
    void *sys;
    int i;

    sys = func_020120F4(func_020124E4(a));
    switch (*task) {
    case 0:
        func_021CF8E4((void *)w->f00, sys, (int)(&w->f0c));
        (*task)++;
        break;
    case 1: {
        int base = w->f04;
        out = &w->f0c;
        for (i = flag; i < 2; i++) {
            func_021CF940((void *)w->f00, sys, (void *)(base + i), out);
            w->f04++;
            if (w->f04 >= 0x18) {
                (*task)++;
                break;
            }
        }
        break;
    }
    case 2:
        func_021CF9AC((void *)w->f00, sys, flag, (int)(&w->f0c));
        flag = 1;
        break;
    }
    if (w->f0c >= 0x32) {
        flag = 1;
    }
    if (flag) {
        *w->f08 = w->f0c;
        return 1;
    }
    return 0;
}


/*
 * Counts the party members whose value func_021CFA04 accepts.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF8E4(void *a, void *src, int c)
{
    void *party = func_02012934(src);
    int cnt = func_0201AA18(party);
    int n = 0;
    int i;

    for (i = 0; i < cnt; i++) {
        void *p = func_0201AB28(party, i);
        if (func_02017E1C(p, 0x4c, 0) == 0) {
            u32 v = func_02017E1C(p, 7, 0);
            if (func_021CFA04((int)a, v, (void *)c) != 0) {
                n++;
            }
        }
    }
    return n;
}


/*
 * Counts the 30 slots whose value func_021CFA04 accepts.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF940(void *a, void *src, void *b, int *c)
{
    void *h = (void *)func_0201293C(src);
    int n = 0;
    int i;

    for (i = 0; i < 30; i++) {
        if (func_020079BC(h, (u32)b, i, 0xa9, 0) != 0) {
            if (func_020079BC(h, (u32)b, i, 0x4c, 0) == 0) {
                u32 v = func_020079BC(h, (u32)b, i, 7, 0);
                if (func_021CFA04((int)a, v, (void *)c) != 0) {
                    n++;
                }
            }
        }
    }
    return n;
}


/*
 * Counts the six entries for which func_021CFA04 accepts the value read from them.
 *
 * Addresses are Black-image addresses.
 */
int func_021CF9AC(void *a, void *heap, int x, int y)
{
    void *h;
    int i;
    int n;

    h = func_0200BAC8(func_02012EBC(heap));
    n = 0;
    for (i = 0; i < 6; i++) {
        void *p = func_0200BBEC(h, x, i);
        if (func_02017E88(p, 0xa9, 0) != 0) {
            u32 v = func_02017E88(p, 7, 0);
            if (func_021CFA04((int)a, v, (void *)y) != 0) {
                n++;
            }
        }
    }
    return n;
}


int func_021CFA04(int a, int v, void *l)
{
    int r = 0;

    if (a != v) {
        r = func_021CFA1C(v, l);
    }
    return r;
}


int func_021CFA1C(int v, IdList021CFA1C *l)
{
    int i;

    if (l->n >= 50) {
        return 0;
    }
    for (i = 0; i < l->n; i++) {
        if (v == l->ids[i]) {
            return 0;
        }
    }
    l->ids[i] = v;
    l->n++;
    return 1;
}


/*
 * 2026-10-02: abs_id_39 is overlay id 57 (pool ABS32 0x39, the id argument
 * of func_021BB990); d_021F3900 resolves as ov057 data once the symbols line
 * carries the ov057 region hint (this function loads ov057).
 */
int func_021CFA58(void *a, void *b)
{
    func_0215A5F4(b);
    func_021BB990((int)abs_id_39, (int *)func_02188D24((u8 *)((u32)func_0201210C((void *)func_0215A5DC(b)))), (const int *)d_021F3900);
    return 0;
}
