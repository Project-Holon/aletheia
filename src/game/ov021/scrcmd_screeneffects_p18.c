/*
 * file:     scrcmd_screeneffects_p18.c
 * unit:     yes
 * function: func_021B05AC, func_021B0624
 * address:  0x021B05AC
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
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159190  0x02159190  thumb  ov010
 *   func_0215A630  0x0215A630  thumb  ov010
 *   func_0202F038  0x0202F038  thumb
 *   func_0215A624  0x0215A624  thumb  ov010
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_021911B4  0x021911B4  thumb  ov021
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_021B0480  0x021B0480  thumb  ov021
 */
struct Ctx;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern u16 func_02188C84(u8 *p);
extern unsigned int func_02159B10(void *, void *);
extern int func_02159190(int a0);
extern u32 func_0215A630(u8 *p);
extern void func_0202F038(u8 *p);
extern void func_0215A624(u8 *p, u32 v);
extern int func_0215A61C(int a0);
extern u32 func_021911B4(u8 *p);
extern u32 func_020056BC(void);
extern u32 func_0202EE30(u32, u32, u32, u32, u32);
extern void func_021B0480(u32 a);
int func_021B05AC(u32 a, u32 b);
int func_021B0624(u32 a, u32 b, u32 c, u32 d);


int func_021B05AC(u32 a, u32 b)
{
    u32 r6, r4, t0;

    r6 = func_02188C84(func_0201210C(func_0215A5DC((void *)b)));
    r4 = func_02159B10((void *)a, (void *)b);
    if (!func_02159190(1)) {
        return 0;
    }
    t0 = func_0215A630((u8 *)b);
    if (t0) {
        func_0202F038((void *)t0);
        func_0215A624((u8 *)b, 0);
    }
    if (r4 == 0) {
        u32 t = func_021911B4((u8 *)func_0215A61C(b));
        func_0215A624((u8 *)b, func_0202EE30(func_020056BC(), t, 0xf, 0x10, r6));
    }
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B0624(u32 a, u32 b, u32 c, u32 d)
{
func_021B0480(b);
return 0;
}
