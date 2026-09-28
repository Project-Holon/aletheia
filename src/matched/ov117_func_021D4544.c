/*
 * function: func_021D4544
 * address:  0x021D4544
 * packet:   pkt_ov117_021D4544
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4484  0x021D4484  thumb  ov117
 *   func_02030734  0x02030734  arm
 *   func_021D4480  0x021D4480  thumb  ov117
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFB84  0x021DFB84  thumb  ov119
 *   func_02015F2C  0x02015F2C  thumb
 *   func_021DFD0C  0x021DFD0C  thumb  ov119
 *   func_02015F50  0x02015F50  thumb
 *   func_021E106C  0x021E106C  thumb  ov119
 *   func_02040EBC  0x02040EBC  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D4664  0x021D4664  thumb  ov117
 *   d_021D55B0     0x021D55B0  data
 *   d_021D51F4     0x021D51F4  data
 *   d_021D51E8     0x021D51E8  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D4484(void *p, int a);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern int func_021D4480(int);
extern void func_021DFD24(u32);
extern u32 func_021DFB84(u32, int, Vec *, u32);
extern void func_02015F2C(u32 obj, void *arg, void (*cb)(void), int a);
extern void func_021DFD0C(void);
extern void func_02015F50(u32, u32, u32, s32, u32);
extern void func_021E106C(void *p);
extern void func_02040EBC(int a, int b);
extern void func_021D8E84(void *p, int next);
extern void func_021D4664(u8 *p);
extern const char d_021D55B0[];
extern const Vec d_021D51F4;
extern const Vec d_021D51E8;

#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define SLOT1 (*(u32 *)(p + 0x860))
#define FADE (*(s8 **)(p + 0x818))

void func_021D4544(u8 *p)
{
    Vec a;
    Vec b;

    func_021D4484(p, 0);
    FADE = func_02030734(HEAP, 4, 1, d_021D55B0, 0xF5);
    FADE[0] = func_021D4480(0xE);
    FADE[1] = 0;
    FADE[2] = 0;
    FADE[3] = -0x10;
    a = d_021D51F4;
    func_021DFD24(SLOT0);
    SLOT0 = func_021DFB84(OBJ(0), func_021D4480(0x2A), &a, HEAP);
    b = d_021D51E8;
    func_021DFD24(SLOT1);
    SLOT1 = func_021DFB84(OBJ(1), func_021D4480(0x54), &b, HEAP);
    func_02015F2C(OBJ(0), p, func_021DFD0C, 1);
    func_02015F50(OBJ(1), 0, 0x10, (s8)(func_021D4480(0xE) / 16), 0);
    func_021E106C(p);
    func_02040EBC(1, 0);
    func_02040EBC(5, 0);
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D4664);
}
