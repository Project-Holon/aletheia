/*
 * function: func_021D4544
 * address:  0x021D4544
 * packet:   pkt_ov118_021D4544
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4484  0x021D4484  thumb  ov118
 *   func_02030734  0x02030734  arm
 *   func_021D4480  0x021D4480  thumb  ov118
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFB84  0x021DFB84  thumb  ov119
 *   MCSS_SetAnimCallback  0x02015F2C  thumb
 *   func_021DFD0C  0x021DFD0C  thumb  ov119
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   func_021E106C  0x021E106C  thumb  ov119
 *   func_02040EBC  0x02040EBC  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D4664  0x021D4664  thumb  ov118
 *   d_021D7FB8     0x021D7FB8  data
 *   d_021D7C84     0x021D7C84  data
 *   d_021D7C9C     0x021D7C9C  data
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

extern void func_021D4484(u8 *p, u32 v);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021D4480(int);
struct McssFade;
extern void func_021DFD24(u32 *p);
extern void *func_021DFB84(void *a0, void *a1, void *a2, u32 heapId);
extern void MCSS_SetAnimCallback(u32 obj, void *arg, void (*cb)(void), int a);
extern void func_021DFD0C(char *p);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void func_021E106C(char *p);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_021D8E84(void *p, int next);
extern void func_021D4664(u8 *p);
extern const char d_021D7FB8[];
extern const Vec d_021D7C84;
extern const Vec d_021D7C9C;

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
    FADE = func_02030734(HEAP, 4, 1, d_021D7FB8, 0xF5);
    FADE[0] = func_021D4480(0xE);
    FADE[1] = 0;
    FADE[2] = 0;
    FADE[3] = -0x10;
    a = d_021D7C84;
    func_021DFD24((u32 *)SLOT0);
    SLOT0 = (u32)func_021DFB84((void *)OBJ(0), (void *)func_021D4480(0x2A), &a, HEAP);
    b = d_021D7C9C;
    func_021DFD24((u32 *)SLOT1);
    SLOT1 = (u32)func_021DFB84((void *)OBJ(1), (void *)func_021D4480(0x54), &b, HEAP);
    MCSS_SetAnimCallback(OBJ(0), p, (void (*)(void))func_021DFD0C, 1);
    MCSS_SetPaletteFade((struct McssFade *)OBJ(1), 0, 0x10, (s8)(func_021D4480(0xE) / 16), 0);
    func_021E106C((char *)p);
    func_02040EBC(1, 0);
    func_02040EBC(5, 0);
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D4664);
}
