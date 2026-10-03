/*
 * function: func_021B70F4
 * address:  0x021B70F4
 * packet:   pkt_ov067_021B70F4
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B76C8  0x021B76C8  thumb  ov067
 *   func_0204B404  0x0204B404  arm
 *   func_021B7718  0x021B7718  thumb  ov067
 *   func_02040588  0x02040588  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

struct S {
    u8 _0[0x8];
    u32 f8;
    u32 fC;
    u32 f10;
    u8 f14;
    u8 _15;
    u8 f16;
    u8 f17;
    u8 f18;
    u8 _19[0x1c - 0x19];
    u32 f1C;
    u8 _20[0x22 - 0x20];
    u8 f22[0x88 - 0x22];
    int f88;
    int f8c;
    u32 f90;
    u32 f94;
    u32 f98;
    u32 f9c;
    int arrA0[4];
    u8 _b0[0xc0 - 0xb0];
    u32 fC0;
};

typedef struct {
    u16 x;
    u16 y;
} Pt;

extern u8 func_021B76C8(u32 a, u32 b, u32 c);
extern void func_0204B404(int h, Pt *pt, u16 v);
extern void func_021B7718(int which, int idx, void *data);
extern void func_02040588(u32 which, u32 enable);
extern int func_02045770(int a);
extern void func_02043B5C(int a, int b);
extern u32 func_0201D304(u32 a, u32 b, u32 c);
extern void func_0201C724(u32 a, u32 b, s16 x, s16 y, u32 str, u32 font, u16 color);
extern int func_0201C6C4(u32 a, u32 b);
extern void func_02045334(int a);
extern void func_02045374(int a);
extern int func_02045730(int a);
extern void func_02041B6C(u32 bit);
extern u8 func_020355C4(void);
extern void func_0204B3DC(int a, int b);
extern void func_0204B92C(int a, int b);

void func_021B70F4(struct S *s, u32 a1, u32 a2)
{
    Pt pt;
    u8 i;
    u32 t;
    int p;

    s->f98 = 1;
    s->f9c = 2;
    s->fC0 = 0;
    for (i = 0; i < 4; i++) {
        pt.x = func_021B76C8(s->fC0, i, 0);
        pt.y = func_021B76C8(s->fC0, i, 1);
        func_0204B404(s->arrA0[i], &pt, s->f1C);
    }
    func_021B7718(s->f10, s->f16, s->f22);
    func_021B7718(s->f10, s->f17, s->f22);
    func_02040588(s->f14, 1);
    func_02043B5C(func_02045770(s->f88), 0);
    func_02043B5C(func_02045770(s->f8c), 0);
    t = func_0201D304(a1, s->f8, 0);
    func_0201C724(s->fC, func_02045770(s->f88), (u16)((0x100 - t) / 2), 0x10, a1, s->f8, 0x3c40);
    t = func_0201D304(a2, s->f8, 0);
    func_0201C724(s->fC, func_02045770(s->f8c), (u16)((0x100 - t) / 2), 0x10, a2, s->f8, 0x3c40);
    s->f90 = 0;
    s->f94 = 0;
    func_02040588(s->f18, 1);
    if (s->f90 == 0 && func_0201C6C4(s->fC, func_02045770(s->f88)) == 0) {
        p = s->f88;
        func_02045334(p);
        func_02045374(p);
        func_02041B6C(func_02045730(p));
        s->f90 = 1;
    }
    if (s->f94 == 0 && func_0201C6C4(s->fC, func_02045770(s->f8c)) == 0) {
        p = s->f8c;
        func_02045334(p);
        func_02045374(p);
        func_02041B6C(func_02045730(p));
        s->f94 = 1;
    }
    if (func_020355C4() == 0) {
        for (i = 0; i < 4; i++) {
            func_0204B3DC(s->arrA0[i], 1);
            func_0204B92C(s->arrA0[i], 1);
        }
    }
}
