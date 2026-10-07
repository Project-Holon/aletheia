/*
 * file:     scrcmd_screeneffects_p16.c
 * unit:     yes
 * function: func_021AFC38, func_021AFC88, func_021AFCD8, func_021AFD44, func_021AFDAC, func_021AFE64, func_021AFECC, func_021AFEFC, func_021AFF7C
 * address:  0x021AFC38
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0200C1C4  0x0200C1C4  thumb
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02012104  0x02012104  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02184D38  0x02184D38  thumb  ov020
 *   func_02185534  0x02185534  thumb  ov020
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216282C  0x0216282C  thumb  ov010
 *   func_02162A6C  0x02162A6C  thumb  ov010
 *   func_02184E40  0x02184E40  thumb  ov020
 *   func_021BB578  0x021BB578  thumb  ov021
 *   func_02185050  0x02185050  thumb  ov020
 *   func_021850A8  0x021850A8  thumb
 *   func_021854B0  0x021854B0  thumb  ov020
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB3E8  0x021BB3E8  thumb  ov021
 *   func_02184D90  0x02184D90  thumb  ov020
 */
struct Big;
struct Blk34;
struct WordSet;
struct Ctx;
struct Evt;
struct Stream;
struct Rec;
struct BigObj;
struct Obj00020;
struct VecFx32;
typedef unsigned char u8;

typedef struct {
    char pad[0x14];
    u8 *cur;
} Ctx;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short   s16_021AFECC;

typedef signed char    s8;

typedef short          s16_021AFF7C;

typedef struct { u16 f0; u16 f2; s16_021AFF7C f4; u16 f6; } Q;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern void *func_02158F74(void *p);
extern u32 func_0200C1DC(struct Blk34 *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_0200C1C4(struct Blk34 *p);
extern void *func_02158F54(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern u16 func_02011330(struct Stream *s);
extern u32 func_02012104(const struct Ctx *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02184D38();
extern void *func_02185534();
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02188CD0(u8 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void *func_021A3074(unsigned char *p);
extern struct Rec *func_0216282C(struct Ctx *c, void *a, int *key, int mode);
extern void func_02162A6C(int a, int b);
extern void *func_02184E40();
extern void func_021BB578(int a, int b, int c, int d);
extern void *func_02185050();
extern u32 func_021850A8(u32 a, void *b);
extern void *func_021854B0();
extern u32 func_02188C5C(u8 *p);
extern int func_021BB3E8();
extern void *func_02184D90(void *p, void *unused, int a, const Q *q, int s, int t);
int func_021AFC38(Ctx *a0, int a1);
int func_021AFC88(Ctx *a0, int a1);
int func_021AFCD8(int a0, int a1);
int func_021AFD44(int a0, int a1);
int func_021AFDAC(int a0, int a1);
int func_021AFE64(int a0, int a1);
int func_021AFECC(u32 a, u32 b);
int func_021AFEFC(int a0, int a1);
int func_021AFF7C(int a0, int a1);


int func_021AFC38(Ctx *a0, int a1)
{
    void *t = func_0215A5F4((void *)a1);
    void *h;
    int r;
    u8 *p;
    int b;

    h = func_0200C0F0(func_02012EBC(func_0215A5E4((void *)a1)));
    r = (int)func_02158F74(t);
    p = a0->cur;
    b = *p;
    a0->cur = p + 1;
    func_0201EFA4((struct WordSet *)r, b, func_0200C1DC(h), 9, 1, 1);
    return 0;
}


int func_021AFC88(Ctx *a0, int a1)
{
    void *t = func_0215A5F4((void *)a1);
    void *h;
    int r;
    u8 *p;
    int b;

    h = func_0200C0F0(func_02012EBC(func_0215A5E4((void *)a1)));
    r = (int)func_02158F74(t);
    p = a0->cur;
    b = *p;
    a0->cur = p + 1;
    func_0201EFA4((struct WordSet *)r, b, func_0200C1C4(h), 9, 1, 1);
    return 0;
}


int func_021AFCD8(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int arr[3];
    int w;

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C(h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = func_02012104(h);
    func_02012374((struct Evt *)w, func_02184D38(h, a, b, arr, e, 0));
    return 1;
}


int func_021AFD44(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int arr[3];
    int w;

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C(h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = func_02012104(h);
    func_02012374((struct Evt *)w, func_02185534(h, a, b, arr, e));
    return 1;
}


int func_021AFDAC(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    void *e;
    int f;
    void *g;
    int w;
    struct Rec *r;
    int out[3];
    int arr[3];
    int buf[3];

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C(h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_020120F4(h);
    f = func_02012844(e);
    g = (void *)func_0201296C(e);
    func_021A3038(func_02188CB4((void *)a), (struct VecFx32 *)buf);
    r = func_0216282C((struct Ctx *)f, (void *)g, buf, 9);
    if (r != 0)
        func_02162A6C((int)r, (int)out);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = func_02012104(h);
    func_02012374((struct Evt *)w, func_02184E40(h, a, out, b, arr));
    g = func_021A3074(func_02188CB4((void *)a));
    func_021BB578(func_02188CD0(a), (int)g, 0, 1);
    return 1;
}


int func_021AFE64(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int arr[3];
    int w;

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C(h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    arr[0] = c << 16;
    arr[1] = 0;
    arr[2] = d << 16;
    w = func_02012104(h);
    func_02012374((struct Evt *)w, func_02185050(h, a, b, arr, e));
    return 1;
}


int func_021AFECC(u32 a, u32 b)
{
    u32 p = (u32)func_02158F54(func_0215A5F4((void *)b));
    void *q = func_0201210C((void *)p);
    u32 r = func_02012104((const struct Ctx *)p);

    func_02012374((struct Evt *)r, (struct Evt **)func_021850A8(p, q));
    return 1;
}


int func_021AFEFC(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int arr[3];
    int w;

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C(h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    f = func_02011330((struct Stream *)a0);
    func_021A3074(func_02188CB4((void *)a));
    arr[0] = c << 16;
    arr[1] = d << 16;
    arr[2] = e << 16;
    w = func_02012104(h);
    func_02012374((struct Evt *)w, func_021854B0(h, a, b, arr, f));
    return 1;
}


int func_021AFF7C(int a0, int a1)
{
    void *h;
    void *a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int w;
    int loc[2];

    h = (void *)func_02158F54(func_0215A5F4((void *)a1));
    a = func_0201210C(h);
    b = func_02011330((struct Stream *)a0);
    c = func_02011330((struct Stream *)a0);
    d = func_02011330((struct Stream *)a0);
    e = func_02011330((struct Stream *)a0);
    f = func_02011330((struct Stream *)a0);
    w = func_02012104(h);
    func_021BB3E8(func_02188C5C(a), b, c, d, e, loc, 0x15);
    func_02012374((struct Evt *)w, func_02184D90(h, a, b, (const Q *)loc, f, 0));
    return 1;
}
