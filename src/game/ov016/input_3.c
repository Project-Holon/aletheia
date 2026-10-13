/*
 * file:     input_3.c
 * unit:     yes
 * function: func_021D657C, func_021D668C, func_021D6824, func_021D6864, func_021D68A4, func_021D68E4, func_021D696C, func_021D69F4, func_021D6A7C, func_021D6B04, func_021D6B64, func_021D6BC8
 * address:  0x021D657C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021DE688     0x021DE688 data
 *   _ZZ13func_021D657CvE5count 0x021DE690 data
 *   func_0208AF08  0x0208AF08  arm
 *   func_0208B104  0x0208B104  arm
 *   func_021D5FE8  0x021D5FE8  arm  ov016
 *   func_0207C994  0x0207C994  arm
 *   PM_SetLCDPower 0x0208C64C  arm
 *   func_02087AE4  0x02087AE4  arm
 *   func_0207D46C  0x0207D46C  arm
 *   func_0207D42C  0x0207D42C  arm
 */
struct TPData;
typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short touch;
    unsigned short validity;
} TPData;

typedef struct tagCOORD {
    unsigned short x;
    unsigned short y;
} COORD;

typedef struct {
    TPData tp[5];
    COORD coord;
    COORD last;
    unsigned short cont;
    unsigned short trg;
    unsigned short repeat;
    unsigned short release;
    unsigned char touch : 1;
    unsigned char trig : 1;
    unsigned char repeatTp : 1;
    unsigned char releaseTp : 1;
} InputWork;

typedef struct {
    unsigned char fold;
    unsigned char cnt;
    unsigned char pad2[2];
    InputWork *work;
} InputStatics;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef long           s32;

typedef _Bool bool;

typedef struct {
    unsigned char f0 : 1;
    unsigned char f1 : 1;
    unsigned char f2 : 1;
    unsigned char f3 : 1;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char f6 : 1;
    unsigned char f7 : 1;
} ByteBits;

typedef struct tagAREA { unsigned short x, y, w, h; } AREA;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

extern u16 func_0208AF08(void);
extern void func_0208B104(struct TPData *disp, const struct TPData *raw);
extern void func_021D5FE8(int a, int b, unsigned short *p);
extern s32 func_0207C994(s32 a, s32 b);
extern int PM_SetLCDPower(int sw);
extern void func_02087AE4(void);
extern void func_0207D46C(void);
extern void func_0207D42C(void);
void func_021D657C(void);
void func_021D668C(void);
int func_021D6824(unsigned int f);
int func_021D6864(unsigned int f);
int func_021D68A4(unsigned int f);
int func_021D68E4(u16 *a);
int func_021D696C(u16 *a);
int func_021D69F4(u16 *a);
int func_021D6A7C(u16 *a);
int func_021D6B04(const AREA *a);
int func_021D6B64(COORD *c);
void func_021D6BC8(void);
extern InputStatics g_021DE688;




void func_021D657C(void)
{
    static unsigned char count[14];
    unsigned short *input;
    int i;
    unsigned short bit;

    input = (unsigned short *)0x04000130;
    bit = ((*input | *(unsigned short *)0x02FFFFA8) ^ 0x2FFF) & 0x2FFF;
    input = &g_021DE688.work->cont;
    bit = bit & ~((bit & 0x40) << 1) & ~((bit & 0x20) >> 1);
    g_021DE688.work->trg = (*input ^ bit) & bit;
    g_021DE688.work->release = (*input ^ bit) & *input;
    g_021DE688.work->cont = bit;
    g_021DE688.work->repeat = g_021DE688.work->trg;
    for (i = 0; i < 14; i++) {
        if (!(bit & (unsigned short)(1 << i))) {
            count[i] = 0;
        } else {
            count[i]++;
            if (count[i] == 40) {
                g_021DE688.work->repeat |= (unsigned short)(1 << i);
            } else if (count[i] == 47) {
                g_021DE688.work->repeat |= (unsigned short)(1 << i);
                count[i] = 40;
            }
        }
    }
}








/*
 * sdk:      readTouch (libdwcutil.TWL.HYB.a(input.o))
 *
 * input.o's statics sit in one block; the vendor reaches them through one
 * pool word anchored at 0x021DE688 (DWCi_IPTlCheckFold's local static fold),
 * so the block is a struct overlay named by offset.
 */
void func_021D668C(void)
{
    TPData p;
    int idx;
    int lastIdx;
    int i;
    bool last;
    bool touch;

    last = g_021DE688.work->touch;
    touch = 0;
    idx = func_0208AF08();
    g_021DE688.work->last = g_021DE688.work->coord;
    for (i = 0; i < 4; i++, idx = func_0207C994(idx + 4, 5)) {
        if (g_021DE688.work->tp[idx].touch == 1 && g_021DE688.work->tp[idx].validity == 0) {
            touch = 1;
            func_0208B104((struct TPData *)(&p), (const struct TPData *)(&g_021DE688.work->tp[idx]));
            func_021D5FE8(p.x, p.y, (short unsigned int *)(&g_021DE688.work->coord));
            break;
        }
    }
    g_021DE688.work->trig = touch & (touch ^ last);
    g_021DE688.work->releaseTp = last & (touch ^ last);
    g_021DE688.work->touch = touch;
    g_021DE688.work->repeatTp = g_021DE688.work->trig;
    if (!touch) {
        g_021DE688.cnt = 0;
        return;
    }
    if (++g_021DE688.cnt == 40) {
        g_021DE688.work->repeatTp = 1;
        return;
    }
    if (g_021DE688.cnt == 47) {
        g_021DE688.work->repeatTp = 1;
        g_021DE688.cnt = 40;
    }
}







int func_021D6824(unsigned int f)
{
    int *g = (int *)0x021DE688;
    unsigned short v = *(unsigned short *)0x02FFFFA8;

    if ((v & 0x8000) >> 0xf)
        return 0;
    return (f & *(unsigned short *)(g[1] + 0x32)) == f;
}







/*
 * Gate on the hardware bit, then test the flag word at +0x34 for the whole mask.
 * Addresses are Black-image addresses.
 */
int func_021D6864(unsigned int f)
{
    int *g = (int *)0x021DE688;
    unsigned short v = *(unsigned short *)0x02FFFFA8;

    if ((v & 0x8000) >> 0xf)
        return 0;
    return (f & *(unsigned short *)(g[1] + 0x34)) == f;
}







/*
 * Gate on the hardware bit, then test the flag word at +0x36 for the whole mask.
 * Addresses are Black-image addresses.
 */
int func_021D68A4(unsigned int f)
{
    int *g = (int *)0x021DE688;
    unsigned short v = *(unsigned short *)0x02FFFFA8;

    if ((v & 0x8000) >> 0xf)
        return 0;
    return (f & *(unsigned short *)(g[1] + 0x36)) == f;
}








/*
 * Validity test for a records window: bails out unless the shared flag word
 * (0x02FFFFA8 bit 0x8000) and bit 0 of the current record's +0x38 byte are
 * set, then checks a[0]/a[2] against the +0x28 bound and a[1]/a[3] against the
 * +0x2a bound. Addresses are Black-image addresses.
 */
int func_021D68E4(u16 *a)
{
    u8 *g = (u8 *)0x021DE688;
    u8 *p;

    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0)
        return 0;

    p = *(u8 **)(g + 4);

    if (((ByteBits *)(p + 0x38))->f0 == 0)
        return 0;

    if (a[0] > *(u16 *)(p + 0x28))
        return 0;
    if (a[2] < *(u16 *)(p + 0x28))
        return 0;
    if (a[1] > *(u16 *)(p + 0x2a))
        return 0;
    return a[3] >= *(u16 *)(p + 0x2a);
}







int func_021D696C(u16 *a)
{
    u8 *g = (u8 *)0x021DE688;
    u8 *p;

    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0)
        return 0;

    p = *(u8 **)(g + 4);

    if (((ByteBits *)(p + 0x38))->f1 == 0)
        return 0;

    if (a[0] > *(u16 *)(p + 0x28))
        return 0;
    if (a[2] < *(u16 *)(p + 0x28))
        return 0;
    if (a[1] > *(u16 *)(p + 0x2a))
        return 0;
    return a[3] >= *(u16 *)(p + 0x2a);
}







int func_021D69F4(u16 *a)
{
    u8 *g = (u8 *)0x021DE688;
    u8 *p;

    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0)
        return 0;

    p = *(u8 **)(g + 4);

    if (((ByteBits *)(p + 0x38))->f2 == 0)
        return 0;

    if (a[0] > *(u16 *)(p + 0x28))
        return 0;
    if (a[2] < *(u16 *)(p + 0x28))
        return 0;
    if (a[1] > *(u16 *)(p + 0x2a))
        return 0;
    return a[3] >= *(u16 *)(p + 0x2a);
}







/*
 * Validity test for a records window: bails out unless the shared flag word
 * (0x02FFFFA8 bit 0x8000) and bit 3 of the current record's +0x38 byte are
 * set, then checks a[0]/a[2] against the +0x28 bound and a[1]/a[3] against the
 * +0x2a bound. Addresses are Black-image addresses.
 */
int func_021D6A7C(u16 *a)
{
    u8 *g = (u8 *)0x021DE688;
    u8 *p;

    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0)
        return 0;

    p = *(u8 **)(g + 4);

    if (((ByteBits *)(p + 0x38))->f3 == 0)
        return 0;

    if (a[0] > *(u16 *)(p + 0x28))
        return 0;
    if (a[2] < *(u16 *)(p + 0x28))
        return 0;
    if (a[1] > *(u16 *)(p + 0x2a))
        return 0;
    return a[3] >= *(u16 *)(p + 0x2a);
}





/*
 * sdk:      DWCi_TPlCheckATrigger (libdwcutil.TWL.HYB.a input.o)
 *
 * notes:    const input lets all four halfwords load before the first store.
 *           The fold test reads the shared word at 0x02FFFFA8 through a
 *           volatile u16 cast (a fixed address, no variable, so the vendor
 *           DWARF has nothing to say about it either way).
 */
int func_021D6B04(const AREA *a)
{
    RECT r;

    if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
        return 0;
    r.l = a->x;
    r.t = a->y;
    r.r = a->x + a->w;
    r.b = a->y + a->h;
    return func_021D696C((u16 *)(&r));
}



/*
 * sdk:      DWCi_TPlGet (libdwcutil.TWL.HYB.a input.o)
 */
int func_021D6B64(COORD *c)
{
    InputWork *t;
    if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
        return 0;
    t = g_021DE688.work;
    if (!t->touch) {
        *c = t->last;
        return 0;
    }
    *c = t->coord;
    return 1;
}


/*
 * sdk:      DWCi_IPTlCheckFold (libdwcutil.TWL.HYB.a input.o)
 */
void func_021D6BC8(void)
{
    if (g_021DE688.fold) {
        if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
            return;
        if (PM_SetLCDPower(1)) {
            func_02087AE4();
            func_0207D46C();
            *(volatile unsigned int *)0x04001000 |= 0x10000;
            func_02087AE4();
            g_021DE688.fold = 0;
        }
    } else {
        if (!((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15))
            return;
        func_02087AE4();
        func_0207D42C();
        *(volatile unsigned int *)0x04001000 &= ~0x10000;
        func_02087AE4();
        if (PM_SetLCDPower(0))
            g_021DE688.fold = 1;
    }
}
