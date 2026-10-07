/*
 * file:     scrcmd_screeneffects_p04.c
 * unit:     yes
 * function: func_021AEA8C, func_021AEABC, func_021AEB3C, func_021AEBB0, func_021AEC1C, func_021AEC40, func_021AEC84, func_021AECC0
 * address:  0x021AEA8C
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
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02158F8C  0x02158F8C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A460  0x0215A460  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A4C8  0x0215A4C8  thumb  ov010
 *   func_0215A4B4  0x0215A4B4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0216E818  0x0216E818  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021AEDAC  0x021AEDAC  thumb  ov021
 *   func_0215A4A0  0x0215A4A0  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0202A230  0x0202A230  thumb
 *   func_02029E20  0x02029E20  thumb
 *   func_02029AF4  0x02029AF4  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */
struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u16 func_02158F8C(u8 *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_0215A460(u32 a);
extern unsigned int func_02159B10(void *a, void *b);
extern int func_0215A4C8(int a0);
extern int func_0215A4B4(int a0);
extern void *func_02158F54(void *p);
extern int func_0216E818(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void func_0215897C(void *vm, void *task);
extern void func_021AEDAC(u32 a);
extern u32 func_0215A4A0(u32 a);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern u32 func_0202A230(void *a, u32 idx);
extern unsigned short func_02029E20(u32 k);
extern void *func_02029AF4(void *a, u32 b);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
int func_021AEA8C(u32 a, u32 b);
int func_021AEABC(u32 a, u32 b);
int func_021AEB3C(u32 a, u32 b);
int func_021AEBB0(u32 a, u32 b);
int func_021AEC1C(u32 a, u32 b);
int func_021AEC40(u32 a, u32 b);
int func_021AEC84(u32 a, u32 b);
int func_021AECC0(u32 a, u32 b);


int func_021AEA8C(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    u32 y;

    func_02158F58((int)x);
    y = func_02158F8C(x);
    *func_02159AE8((void *)a, (void *)b) = func_0215A460(y);
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021AEABC(u32 a, u32 b)
{
    void *p;
    u32 x, y, z, w;

    p = func_0215A5F4((void *)b);
    func_02158F8C((unsigned char *)p);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    w = (u32)func_0215A4C8((u32)x);
    if (y == 0 && func_0215A4B4(x) == 1) {
        y = x;
    }
    func_0215897C(p, (void *)func_0216E818((int)func_02158F54(p), ((u32 *)func_02158F58((int)p))[1], w, 0, x, y, z));
    func_021AEDAC(b);
    return 1;
}


int func_021AEB3C(u32 a, u32 b)
{
    u32 x, y, z, w;
    void *p;

    p = func_0215A5F4((void *)b);
    func_02158F8C((unsigned char *)p);
    x = func_02159B10((void *)a, (void *)b);
    y = func_02159B10((void *)a, (void *)b);
    z = func_02159B10((void *)a, (void *)b);
    w = func_02159B10((void *)a, (void *)b);
    func_0215897C(p, (void *)func_0216E818((int)func_02158F54(p), ((u32 *)func_02158F58((int)p))[1], 1, x, y, z, w));
    func_021AEDAC(b);
    return 1;
}


int func_021AEBB0(u32 a, u32 b)
{
    u32 h;
    u16 *x, *y, *z;
    u32 v0, v1, v2;

    h = func_02158F8C((unsigned char *)func_0215A5F4((void *)b));
    x = func_02159AE8((void *)a, (void *)b);
    y = func_02159AE8((void *)a, (void *)b);
    z = func_02159AE8((void *)a, (void *)b);
    if ((u16)func_0215A4B4(func_0215A460(h)) == 0) {
        v0 = 0;
        v1 = 2;
        v2 = 24;
    } else if ((u16)func_0215A4A0(h) == 0) {
        v0 = 3;
        v1 = 5;
        v2 = 6;
    } else {
        v0 = 7;
        v1 = 9;
        v2 = 10;
    }
    *x = v0;
    *y = v1;
    *z = v2;
    return 0;
}


int func_021AEC1C(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);

    *func_02159AE8((void *)a, (void *)b) = func_0215A4C8(x);
    return 0;
}


/*
 * Compiled 66 of a 68-byte extent: the trailing halfword is an unlabelled
 * follower.
 *
 * Addresses are Black-image addresses.
 */
int func_021AEC40(u32 a, u32 b)
{
    void *x;
    void *y;

    x = func_0215A5DC((void *)b);
    func_0215A5E4((void *)b);
    y = func_0215A5F4((void *)b);
    func_0215897C(y, func_02029AF4(x, func_02029E20(func_0202A230((void *)func_02159B10((void *)a, (void *)b), 1))));
    return 1;
}


int func_021AEC84(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);

    func_0215897C(x, (void *)func_021BE92C(y, (int)func_0201210C((void *)y), 0, 0, 1, 0, 0));
    return 1;
}


int func_021AECC0(u32 a, u32 b)
{
    u32 x;
    u16 *out;
    u32 v;

    x = func_02159B10((void *)a, (void *)b);
    out = func_02159AE8((void *)a, (void *)b);
    if (func_0202A230((void *)x, 9)) {
        v = 1;
    } else if (func_0202A230((void *)x, 11)) {
        v = 2;
    } else {
        v = 0;
    }
    *out = v;
    return 0;
}
