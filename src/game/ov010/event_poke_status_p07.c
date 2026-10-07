/*
 * file:     event_poke_status_p07.c
 * unit:     yes
 * function: func_02159708, func_02159728, func_02159750, func_02159778, func_021597AC, func_021597CC, func_021597EC, func_0215980C, func_02159830, func_02159854, func_02159874, func_02159894, func_021598AC, func_021598C8, func_021598E4, func_021598EC, func_02159934, func_02159960, func_02159974, func_02159984, func_02159998, func_021599A8, func_02159A64, func_02159AE8
 * address:  0x02159708
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
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_02014460  0x02014460  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02014314  0x02014314  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02011330  0x02011330  thumb
 *   func_021B1BB8  0x021B1BB8  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_021B1BE8  0x021B1BE8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_020288C4  0x020288C4  thumb
 *   func_0202972C  0x0202972C  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159204 0x02159204 thumb ov010
 *   func_020362DC  0x020362DC  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02012DD0  0x02012DD0  thumb
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A153C  0x021A153C  thumb  ov021
 *   func_021A1548  0x021A1548  thumb  ov021
 *   func_021590FC  0x021590FC  thumb  ov010
 *   func_021D11D8  0x021D11D8  thumb
 *   func_021D1194  0x021D1194  thumb
 *   func_021590F4  0x021590F4  thumb  ov010
 *   func_02188C84  0x02188C84  thumb
 *   func_021D1164  0x021D1164  thumb
 *   func_021D11B0  0x021D11B0  thumb
 *   func_021A1524  0x021A1524  thumb  ov021
 *   func_021A1530  0x021A1530  thumb  ov021
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02012DAC  0x02012DAC  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_02158FE0   0x02158FE0  thumb  ov010
 */
struct BigObj;
struct Sub02014444Obj;
struct Stream;
struct Ctx;
struct Sys;
struct Sub02008C20Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned long long u64;

extern void *func_0215A5E4(void *a0);
extern void *func_02012B38(const struct BigObj *p);
extern u8 func_02014460(struct Sub02014444Obj *o);
extern u32 func_0201296C(const struct BigObj *p);
extern unsigned int func_02159B10(void *, void *);
extern int func_02014314();
extern int func_0201433C();
extern u32 func_020142E8(void *bitmap, s32 id);
extern int func_0209C2B0();
extern u64 _u32_div_f(u32, u32);
extern u16 func_02011330(struct Stream *s);
extern int func_021B1BB8(int a, void *b);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void func_021B1BE8(int);
extern unsigned int func_02012A30(const struct BigObj *p);
extern s32 func_020288C4(struct Sys *s);
extern void *func_0202972C(void *a, u16 b);
extern void func_0215897C(void *vm, void *task);
extern void *func_02159204(void *);
extern u32 func_020362DC(void);
extern void func_020113D0(char *, int);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188CCC(void *);
extern u8 func_02012E40(const u8 *o);
extern int func_02012DD0(u8 *p);
extern u32 func_021A0F90(u8 *p);
extern int func_021A153C(u32 *p);
extern void func_021A1548(u32 *p);
extern u32 func_021590FC(void *p);
extern void func_021D11D8(int);
extern void func_021D1194(int);
extern void func_021590F4(void *p, u32 v);
extern int func_02188C84(void *);
extern int func_021D1164(int, void *);
extern void func_021D11B0(int);
extern void func_021A1524(u32 *p);
extern void func_021A1530(u32 *p);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_02012DAC(int a0);
extern u16 *func_02158FE0(void *, void *, unsigned int);
int func_02159708(int a0, int a1);
int func_02159728(int a0, int a1);
int func_02159750(int a0, int a1);
int func_02159778(int a0, int a1);
int func_021597AC(void *a, void *b);
int func_021597CC(int a0, int a1);
int func_021597EC(void *a, void *b);
int func_0215980C(int a0, int a1);
int func_02159830(void *a, void *b);
int func_02159854(int a0, int a1);
int func_02159874(int a0, int a1);
int func_02159894(int a0, int a1);
int func_021598AC(int a0, int a1);
int func_021598C8(int a0, int a1);
int func_021598E4(int a0, void *a1);
int func_021598EC(int a, int b);
int func_02159934(void *a, void *b);
int func_02159960(int a0, int a1);
int func_02159974(char *p);
int func_02159984(int a0, int a1);
int func_02159998(char *p);
int func_021599A8(int a, int b);
int func_02159A64(int a, int b);
u16 *func_02159AE8(void *a0, void *a1);


int func_02159708(int a0, int a1)
{
    int t5;
    void *p;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_02159710:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_02159718:
    p = func_02012B38((const struct BigObj *)v0);
loc_0215971C:
    a0 = func_02014460(p);
loc_02159720:
*q = a0;
a0 = 0;
    return a0;}


int func_02159728(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_02159734:
    a0 = func_0201296C(v0);
loc_02159738:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_02159742:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_02014314(a0, a1);
loc_0215974A:
a0 = 0;
    return a0;}


int func_02159750(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215975C:
    a0 = func_0201296C(v0);
loc_02159760:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0215976A:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0201433C(a0, a1);
loc_02159772:
a0 = 0;
    return a0;}


int func_02159778(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    u16 *q;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_02159784:
    a0 = func_0201296C(v0);
loc_02159788:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_02159792:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215979C:
a0 = t6 + 0;
a1 = t7 + 0;
    a0 = func_020142E8((void *)a0, a1);
loc_021597A6:
*q = a0;
a0 = 0;
    return a0;}

/*
 * extent: two bytes of zero alignment padding at 0x021597CA.
 */
int func_021597AC(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    *p = *p + func_02159B10(a, b);
    return 0;
}


int func_021597CC(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_021597D6:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021597E0:
a1 = *q;
a0 = a1 - a0;
*q = a0;
a0 = 0;
    return a0;}

/*
 * extent: two bytes of zero alignment padding at 0x0215980A.
 */
int func_021597EC(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    *p = *p * func_02159B10(a, b);
    return 0;
}


int func_0215980C(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_02159816:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_02159820:
a1 = a0 + 0;
a0 = *q;
    a0 = func_0209C2B0(a0, a1);
loc_02159828:
*q = a0;
a0 = 0;
    return a0;}

/*
 * extent: two bytes of zero alignment padding at 0x02159852.
 * prototype: named runtime helper has opaque combined scalar return;
 * the original and compiled helper arguments are numerator r0, divisor r1.
 * low word is original r0 output, high word is original r1 remainder.
 * The original admits zero divisors. Direct helper call preserves that
 * behavior without expressing undefined C remainder on a zero divisor.
 * Fixed-flag run 1 proves u64 return in r0/r1: high-word extraction emits
 * no shift, and strh r1 immediately follows the original helper call.
 */
int func_02159830(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    u32 divisor = func_02159B10(a, b);
    *p = (u32)(_u32_div_f(*p, divisor) >> 32);
    return 0;
}


int func_02159854(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215985E:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_02159868:
a1 = *q;
a0 = a0 & a1;
*q = a0;
a0 = 0;
    return a0;}


int func_02159874(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215987E:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_02159888:
a1 = *q;
a0 = a0 | a1;
*q = a0;
a0 = 0;
    return a0;}


int func_02159894(int a0, int a1)
{
    int t5;
    u16 *q;

t5 = a0 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215989C:
a0 = t5 + 0;
    a0 = func_02011330((struct Stream *)a0);
loc_021598A4:
*q = a0;
a0 = 0;
    return a0;}


int func_021598AC(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;
    u16 *dst;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_021598B6:
a0 = t5 + 0;
a1 = t6 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_021598C0:
a0 = *dst;
*q = a0;
a0 = 0;
    return a0;}


int func_021598C8(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_021598D2:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_021598DC:
*q = a0;
a0 = 0;
    return a0;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_021B1BB8, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021598E4.c \
 *       --func func_021598E4 --addr 0x021598E4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_021598E4(int a0, void *a1)
{
    return func_021B1BB8(a0, a1);
}


int func_021598EC(int a, int b)
{
    void *x = func_0215A5F4((void *)b);
    void *y = func_0215A5DC((void *)b);
    int h = (int)func_020120F4(y);
    int r = 0;
    func_021B1BE8(b);
    if (func_020288C4((struct Sys *)((int)func_02012A30((const struct BigObj *)h)))) {
        func_0215897C(x, func_0202972C(y, r));
        r = 1;
    }
    return r;
}

/*
 * extent: two bytes of zero alignment padding at 0x0215995E.
 */
int func_02159934(void *a, void *b)
{
    void *x = func_0215A5F4(b);
    void *t;
    func_0215A5DC(b);
    t = func_02159204(b);
    if (t == 0)
        return 1;
    func_0215897C(x, t);
    return 1;
}


int func_02159960(int a0, int a1)
{

    a0 = func_020362DC();
loc_02159966:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_02159970;
loc_0215996C:
a0 = 1;
    return a0;
loc_02159970:
a0 = 0;
    return a0;}

int func_02159974(char *p)
{
    func_020113D0(p, (int)func_02159960);
    return 1;
}


int func_02159984(int a0, int a1)
{

    a0 = func_020362DC();
loc_0215998A:
a1 = 0xf3;
    if ((a0 & a1) == 0) goto loc_02159994;
loc_02159990:
a0 = 1;
    return a0;
loc_02159994:
a0 = 0;
    return a0;}

int func_02159998(char *p)
{
    func_020113D0(p, (int)func_02159984);
    return 1;
}


int func_021599A8(int a, int b)
{
    void *s4 = func_0215A5E4((void *)b);
    void *s0 = func_0215A5F4((void *)b);
    int h;
    int ret;
    h = func_02188CCC(func_0201210C(func_0215A5DC((void *)b)));
    if (func_02012E40(s4) == 0) {
        ret = 1;
        if (func_021A0F90((u8 *)h) == 7) {
            if (func_021A153C((u32 *)h) == 0)
                ret = 0;
        }
    } else {
        switch (func_02012DD0(s4)) {
        case 0:
        case 1:
            ret = 0;
            break;
        case 2:
            *func_02159AE8((void *)a, (void *)b) = 1;
            ret = 0;
            break;
        case 3:
            *func_02159AE8((void *)a, (void *)b) = 0;
            ret = 1;
            if (func_021A0F90((u8 *)h) == 7)
                func_021A1548((u32 *)h);
            break;
        }
    }
    if (ret == 1) {
        int t = func_021590FC(s0);
        func_021D11D8(t);
        func_021D1194(t);
        func_021590F4(s0, 0);
    }
    return ret;
}


int func_02159A64(int a, int b)
{
    void *s0 = func_0215A5F4((void *)b);
    void *s4 = func_0215A5E4((void *)b);
    int y, z, t;
    void *x;
    x = func_0201210C(func_0215A5DC((void *)b));
    y = func_02188C84(x);
    z = func_02188CCC(x);
    t = func_021D1164(y, x);
    func_021D11B0(t);
    if (func_021A0F90((u8 *)z) == 7) {
        func_021A1524((u32 *)z);
        func_021A1530((u32 *)z);
    }
    func_021590F4(s0, t);
    func_02008DF0(func_02012F2C(s4), 1);
    func_02012DAC((int)s4);
    func_020113D0((char *)a, (int)func_021599A8);
    return 1;
}


/*
 * Two record lookups on the second argument and a classification of the
 * first, submitted as three arguments.
 */
u16 *func_02159AE8(void *a0, void *a1)
{
    void *v = func_0215A5E4(a1);

    return func_02158FE0(func_0215A5F4(a1), v, func_02011330(a0));
}
