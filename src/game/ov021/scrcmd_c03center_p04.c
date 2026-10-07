/*
 * file:     scrcmd_c03center_p04.c
 * unit:     yes
 * function: func_021B5F24, func_021B5FB4, func_021B5FB8, func_021B6048, func_021B60F4, func_021B6124, func_021B6164, func_021B61E8, func_021B627C, func_021B62C8, func_021B631C
 * address:  0x021B5F24
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
 *   func_0201891C  0x0201891C  thumb
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02159B10  0x02159B10  thumb ov010
 *   func_02159AE8  0x02159AE8  thumb ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_0215B500  0x0215B500  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A0E8  0x0215A0E8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0202130C  0x0202130C  thumb
 *   func_020188AC  0x020188AC  thumb
 *   func_02018790  0x02018790  thumb
 *   func_021C5AAC  0x021C5AAC  thumb  ov021
 */
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_0201891C(void *p, s32 v);
extern void *func_0215A5E4(void *a0);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern int func_0215B500(int a0, int a1);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A0E8(void *t, u16 *o1, u16 *o2, u8 c, u32 v);
extern void func_0215897C(void *s, void *v);
extern u32 func_0202130C(u32 id);
extern u32 func_020188AC(void *p, int v);
extern u32 func_02018790(void *p);
extern int func_021C5AAC(void *a, int b, int c, int d);
int func_021B5F24(u32 a, int sel);
int func_021B5FB4(u32 a);
int func_021B5FB8(u32 a, int sel);
int func_021B6048(u32 a, u32 b, u32 key, u8 *mask, u32 flag);
int func_021B60F4(void *a, void *b);
int func_021B6124(u32 a, u32 b);
int func_021B6164(u32 a, u32 b);
int func_021B61E8(u32 a, u32 b);
int func_021B627C(u32 a, u32 b);
int func_021B62C8(void *a, void *b);
int func_021B631C(u32 a, u32 b);


/*
 * Addresses are Black-image addresses.
 */
int func_021B5F24(u32 a, int sel)
{
    switch (sel) {
    case 1:
        if (func_0201891C((void *)a, 3))
            return 0x152;
        if (func_0201891C((void *)a, 4))
            return 0x133;
        if (func_0201891C((void *)a, 5))
            return 0x134;
        break;
    case 0:
        return 0x1b2;
    case 2:
        if (func_0201891C((void *)a, 0))
            return 0x208;
        if (func_0201891C((void *)a, 1))
            return 0x207;
        if (func_0201891C((void *)a, 2))
            return 0x206;
        break;
    }
    return 0x133;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B5FB4(u32 a)
{
return 255;
}


int func_021B5FB8(u32 a, int sel)
{
    switch (sel) {
    case 1:
        if (func_0201891C((void *)a, 3))
            return 1;
        if (func_0201891C((void *)a, 4))
            return 1;
        if (func_0201891C((void *)a, 5))
            return 1;
        return 0;
    case 0:
        if (func_0201891C((void *)a, 6))
            return 1;
        return 0;
    case 2:
        if (func_0201891C((void *)a, 0))
            return 1;
        if (func_0201891C((void *)a, 1))
            return 1;
        if (func_0201891C((void *)a, 2))
            return 1;
        return 0;
    }
    return 0;
}


int func_021B6048(u32 a, u32 b, u32 key, u8 *mask, u32 flag)
{
    void *lst;
    int n;
    int i;
    int found;
    int all;
    u32 item;

    lst = func_02012934(func_0215A5E4((void *)b));
    n = func_0201AA18(lst);
    found = 0;
    all = 0;
    *mask = found;
    for (i = 0; i < n; i++) {
        item = (u32)func_0201AB28(lst, i);
        if (func_02017E1C((void *)item, 0x4c, 0) == 1)
            continue;
        if (func_021B5FB8(item, key) == 0)
            continue;
        found = 1;
        if (flag != 0) {
            item = func_02017E1C((void *)item, 9, 0);
            if (item < func_021B5FB4(key))
                continue;
        }
        all = 1;
        *mask = *mask | (u8)(1 << i);
    }
    if (found == 0)
        return 1;
    if (all == 0)
        return 2;
    return 0;
}


int func_021B60F4(void *a, void *b)
{
    u32 v;
    u16 *p;
    u32 tmp;

    v = func_02159B10(a, b);
    p = func_02159AE8(a, b);
    *p = func_021B6048((u32)a, (u32)b, v, (u8 *)(&tmp), 1);
    return 0;
}


int func_021B6124(u32 a, u32 b)
{
    u32 x;
    u32 y;
    u16 *o;
    u32 rec;
    int v;

    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    o = func_02159AE8((void *)a, (void *)b);
    if (func_0215B4AC((void *)b, y, (void **)(&rec)) == 1)
        v = func_021B5F24(rec, x);
    else
        v = 0;
    *o = v;
    return 0;
}


int func_021B6164(u32 a, u32 b)
{
    u32 x;
    u32 y;
    u16 *o;
    u32 rec;

    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    o = func_02159AE8((void *)a, (void *)b);
    *o = 1;
    if (func_0215B4AC((void *)b, y, (void **)(&rec)) == 0)
        return 0;
    if (func_021B5FB8(rec, x) == 0) {
        *o = 1;
    } else if (func_0215B500(rec, func_021B5F24(rec, x)) == 1) {
        *o = 3;
    } else if (func_02017E1C((void *)rec, 9, 0) < func_021B5FB4(x)) {
        *o = 2;
    } else {
        *o = 0;
    }
    return 0;
}


int func_021B61E8(u32 a, u32 b)
{
    u32 mode;
    u16 *o1;
    u16 *o2;
    void *s;
    void *t;
    u32 v;
    u8 c;

    mode = func_02159B10((void *)a, (void *)b);
    o1 = func_02159AE8((void *)a, (void *)b);
    o2 = func_02159AE8((void *)a, (void *)b);
    s = func_0215A5F4((void *)b);
    t = func_0215A5DC((void *)b);
    if (func_021B6048(a, b, mode, &c, 0)) {
        *o1 = 0;
    } else {
        switch (mode) {
        case 1:
            v = 0xfffe;
            break;
        case 2:
            v = 0xfffd;
            break;
        case 0:
            v = 0x1b2;
            break;
        default:
            v = 0xa5;
            break;
        }
        func_0215897C(s, func_0215A0E8(t, o1, o2, c, v));
    }
    return 1;
}


int func_021B627C(u32 a, u32 b)
{
    u16 *o;
    void *lst;
    u32 n;
    u32 i;

    o = func_02159AE8((void *)a, (void *)b);
    *o = 0;
    lst = func_02012934(func_0215A5E4((void *)b));
    n = func_0201AA18(lst);
    for (i = 0; i < n; i++) {
        if (func_02017E1C(func_0201AB28(lst, i), 0x97, 0) != 0) {
            *o = 1;
            break;
        }
    }
    return 0;
}


int func_021B62C8(void *a, void *b)
{
    u16 *p;
    u32 v;
    u32 w;
    u32 x;
    u16 r;

    p = func_02159AE8(a, b);
    v = func_02159B10(a, b);
    w = func_0202130C(0x151);
    if (func_0215B4AC(b, v, (void **)(&x)) == 0) {
        *p = 0xFFFF;
    } else if (func_020188AC((void *)x, w) == 0) {
        *p = 0xFFFF;
    } else {
        *p = func_02018790((void *)x);
    }
    return 0;
}


int func_021B631C(u32 a, u32 b)
{
    void *x;
    void *y;
    u16 *p;
    u32 q;

    x = func_0215A5F4((void *)b);
    y = func_0215A5DC((void *)b);
    p = func_02159AE8((void *)a, (void *)b);
    q = func_02159B10((void *)a, (void *)b);
    func_0215897C(x, (void *)func_021C5AAC(y, (int)p, q, func_02159B10((void *)a, (void *)b)));
    return 1;
}
