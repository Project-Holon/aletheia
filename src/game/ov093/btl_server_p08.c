/*
 * file:     btl_server_p08.c
 * unit:     yes
 * function: func_021BC550, func_021BC55C, func_021BC568, func_021BC610, func_021BC874, func_021BC8EC, func_021BC948, func_021BCA08, func_021BCA50, func_021BCAAC
 * address:  0x021BC550
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021E02DC  0x021E02DC  thumb  ov093
 *   func_021C6394  0x021C6394  thumb  ov093
 *   func_021E0394  0x021E0394  thumb  ov093
 *   func_021BB85C  0x021BB85C  thumb  ov093
 *   func_021BB8A8  0x021BB8A8  thumb  ov093
 *   func_021BB8B0  0x021BB8B0  thumb  ov093
 *   func_021D83E0  0x021D83E0  thumb  ov093
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021C6350  0x021C6350  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_0201BD28  0x0201BD28  thumb
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D7674  0x021D7674  thumb  ov093
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021D8340  0x021D8340  thumb  ov093
 */
struct S2;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 kind : 4; u32 pad : 3; u32 id : 16; u32 rest : 9; } B_021BC550;

typedef struct { u8 *a; B_021BC550 b; u32 c; u32 d; } E_021BC550;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E_021BC550 e[6]; } S;

typedef struct { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; } B_021BC610;

typedef struct { u32 lo : 13; u32 f : 3; u32 g : 6; u32 h : 3; u32 rest : 7; } C;

typedef struct { u8 *a; B_021BC610 b; u32 c; u8 d; u8 e; u8 f; } E_021BC610;

typedef struct { u32 x; void *m; } Q;

typedef struct { u8 *a; B_021BC610 b; u32 c; u8 d; u8 e; u8 f; } E2;

typedef struct { u32 a, b, key, d; } E_021BC874;

typedef struct { u8 *a; u32 b, c, d; } E_021BC8EC;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E_021BC8EC e[4]; } S_021BC874;

typedef struct { u32 a; u32 b, c; u8 d0; u8 flag; u16 pad; } E;

typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[4]; } S_021BCAAC;

extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021D59B4(u8 *p, int k);
extern int func_021E02DC(u8 *a, u16 key, u32 sub_pri);
extern void func_021C6394(u8 *p, u8 *a, unsigned int n);
extern void func_021E0394(u8 *a, int b);
extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern u8 func_021BB8A8(u8 *p, u8 i);
extern B_021BC610 func_021BB8B0(u8 *p, u8 i, u8 j);
extern int func_021D83E0(B_021BC610 *p);
extern u32 func_021D8454(u32 *);
extern u8 func_021B9AB0(u8 k);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern void *func_021B86B8(void ***p);
extern u8 func_021C6350(u8 *p, u8 *a);
extern u32 func_021D78AC(u32 range);
extern u32 func_0201BD28(u32 v, u32 n);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021D7674(int key, u32 a, u32 b, u32 c);
extern u32 func_021D7B10(u32 a, u32 b);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern u32 func_021D8340(u32 *m);
u8 *func_021BC550(u8 *p);
u8 func_021BC55C(u8 *p);
void func_021BC568(S *p);
u8 func_021BC610(S *p, u8 *o, E_021BC610 *e);
void func_021BC874(E_021BC874 *p, u32 n);
int func_021BC8EC(u8 *p, u32 x, u8 *a);
u16 func_021BC948(u8 *p, u8 *x, int flag);
E_021BC8EC *func_021BCA08(S_021BC874 *p, u8 x);
E_021BC8EC *func_021BCA50(S_021BC874 *p, E_021BC8EC *cur, u32 x);
E *func_021BCAAC(S_021BCAAC *p, u8 x, u32 i);




u8 *func_021BC550(u8 *p)
{
    return p + 0x4b8;
}




u8 func_021BC55C(u8 *p)
{
    return p[0x784];
}





void func_021BC568(S *p)
{
    u32 lk = func_021CC8D8((u8 *)p + 0x1d74, 1425);
    u32 i;
    for (i = 0; i < p->n; i++) {
        u16 id;
        u8 *a;
        E_021BC550 *e;
        e = &p->e[i];
        if (e->b.kind == 1)
            id = e->b.id;
        else
            id = 0;
        if (id != 0) {
            a = p->e[i].a;
            if (func_021E02DC(a, id, func_021D59B4(a, 12))) {
                func_021C6394((u8 *)p, a, id);
                func_021E0394(a, id);
            }
        }
    }
    func_021CC95C((u32 *)((u8 *)p + 0x1d74), lk, 0x5a0);
}



u8 func_021BC610(S *p, u8 *o, E_021BC610 *e)
{
    u8 cnt;
    u32 k;
    u8 *a;
    u32 lock;
    u8 i;
    u8 j;
    u8 n;
    u32 flag;
    u8 l;
    Q *q;
    E_021BC610 *r;

    flag = 0;
    for (i = 0, cnt = 0; i < 4; i++) {
        q = (Q *)func_021BB85C((u8 *)(*(u32 *)p), i);
        if (q != 0) {
            u8 r5;
            n = func_021BB8A8(o, i);
            r5 = 0;
            for (j = 0; j < n; j++) {
                u32 t;
                r = &e[cnt];
                r->b = func_021BB8B0(o, i, j);
                if (func_021D83E0(&r->b) != 0)
                    break;
                t = func_021D8454((u32 *)&r->b) & 0xff;
                switch (t) {
                case 6:
                    r5 = func_021B9AB0(r->b.sub);
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r5);
                    flag = 1;
                    break;
                case 3:
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r->b.sub);
                    r5++;
                    break;
                default:
                    r->a = (u8 *)func_021B9BF0(q->m, (u8)r5);
                    r5++;
                    break;
                }
                r->d = i;
                r->e = 0;
                r->f = 0;
                cnt++;
            }
        }
    }
    for (l = 0; l < cnt; l++) {
        u32 m = 0x1FFF;
        u8 r5;
        u32 sub;
        lock = func_021CC8D8((u8 *)p + 0x1d74, 0x678 - 0x38);
        r = &e[l];
        a = e[l].a;
        switch (r->b.kind) {
        case 4:
            if (func_021B86B8(*(void **)((u8 *)p + 4)) == 0 && r->d == 1) {
                r5 = 0;
            } else {
                r5 = 4;
            }
            break;
        case 3:
            r5 = 3;
            break;
        case 2:
            r5 = 2;
            break;
        case 6:
            r5 = 1;
            break;
        case 7:
            r5 = 0;
            break;
        case 5:
            r5 = 0;
            break;
        case 1:
            r5 = 0;
            break;
        case 0:
            *(u32 *)&r->c = 0x01002000;
            continue;
        case 8:
            continue;
        default:
            r5 = 0;
            break;
        }
        if (r->b.kind == 1) {
            u16 id;
            if (((E2 *)e)[l].b.kind == 1)
                id = ((E2 *)e)[l].b.id;
            else
                id = 0;
            sub = func_021BC8EC((u8 *)p, id, a);
        } else if (r->b.kind == 5 || r->b.kind == 7) {
            sub = 7;
        } else {
            sub = 0;
        }
        k = func_021BC948((u8 *)p, a, 1);
        func_021CC95C((u32 *)((u8 *)p + 0x1d74), lock, 0x678);
        r->c = (k & m) | ((m + 1) | (((r5 & 7) << 22) | ((sub & 0x3f) << 16)));
    }
    func_021BC874((E_021BC874 *)e, cnt);
    if (flag == 0) {
        for (i = 0; i < cnt; i++) {
            r = &e[i];
            if (r->b.kind == 1 || r->b.kind == 5) {
                u32 lock = func_021CC8D8((u8 *)p + 0x1d74, 0x68A);
                u32 v = func_021C6350((u8 *)p, r->a);
                r->c = (r->c & 0xFFFF1FFF) | ((v & 7) << 13);
                func_021CC95C((u32 *)((u8 *)p + 0x1d74), lock, 0x68A + 3);
            }
        }
        func_021BC874((E_021BC874 *)e, cnt);
    }
    return cnt;
}




void func_021BC874(E_021BC874 *p, u32 n)
{
    u32 i;
    u32 j;
    E_021BC874 *a;
    E_021BC874 *b;
    E_021BC874 t;
    for (i = 0; i < n; i++) {
        j = i + 1;
        if (j < n) {
            a = &p[i];
            do {
                b = &p[j];
                if (a->key <= b->key && (a->key != b->key || func_021D78AC(2) != 0)) {
                    t = *a;
                    *a = *b;
                    *b = t;
                }
                j++;
            } while (j < n);
        }
    }
}





int func_021BC8EC(u8 *p, u32 x, u8 *a)
{
    u8 n = func_0201BD28(x, 6) + 7;
    u8 r;
    func_021D74F8(1735);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, x);
    func_021D75A8(0x18, n);
    func_021D70F0(p, 0x11);
    r = func_021D775C(0x18);
    func_021D7540(1741);
    return r;
}





u16 func_021BC948(u8 *p, u8 *x, int flag)
{
    u32 r;
    int k = func_021D59B4(x, 0xc);
    int one;
    func_021D74F8(1760);
    func_021D75EC(2, func_021D5440(x));
    func_021D75EC(0x2f, k);
    one = 1;
    func_021D75A8(0x51, 1);
    func_021D75A8(0x4a, 0);
    func_021D7674(0x35, one << 12, 410, one << 17);
    func_021D70F0(p, 0x13);
    r = func_021D7B10(func_021D775C(0x2f), func_021D775C(0x35));
    if (func_021D62A8((struct Unk021D62A8 *)x) == 1 && func_021D775C(0x51) != 0)
        r = r * 25 / 100;
    if (r > 10000)
        r = 10000;
    if (flag != 0 && func_021D775C(0x4a) != 0)
        r = 10000 - r;
    func_021D7540(1792);
    return r;
}





E_021BC8EC *func_021BCA08(S_021BC874 *p, u8 x)
{
    u32 i;
    u32 y = x;
    for (i = 0; i < p->n; i++) {
        if (y == func_021D5440(p->e[i].a))
            return &p->e[i];
    }
    return 0;
}





E_021BC8EC *func_021BCA50(S_021BC874 *p, E_021BC8EC *cur, u32 x)
{
    u32 i;
    for (i = 0; i < p->n; i++) {
        if (&p->e[i] == cur) {
            i++;
            break;
        }
    }
    for (; i < p->n; i++) {
        if (x == func_021D5440(p->e[i].a))
            return &p->e[i];
    }
    return 0;
}



E *func_021BCAAC(S_021BCAAC *p, u8 x, u32 i)
{
    for (; i < p->n; i++) {
        if (p->e[i].flag == 0 && func_021D8454((u32 *)((B_021BC610 *)(&p->e[i].b))) == 1 && x == func_021D8340(&p->e[i].b))
            return &p->e[i];
    }
    return 0;
}
