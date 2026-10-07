/*
 * file:     scrcmd_screeneffects_p09.c
 * unit:     yes
 * function: func_021AF684, func_021AF6C4, func_021AF6E8, func_021AF71C
 * address:  0x021AF684
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
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201292C  0x0201292C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_021AF750  0x021AF750  thumb  ov021
 */
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u16 func_0215A5CC(void *a0);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0201292C(const struct BigObj *p);
extern u16 func_02007FB8(void *, u32, u32);
extern int func_021AF750(u32 a);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
int func_021AF684(u32 a, u32 b);
int func_021AF6C4(u32 a, u32 b);
int func_021AF6E8(u32 a, u32 b);
int func_021AF71C(u32 a, u32 b);


/*
 * Addresses are Black-image addresses.
 */
int func_021AF684(u32 a, u32 b)
{
    u32 c = func_0215A5CC((void *)b);
    void *d;
    u32 e;
    u16 *p;
    d = func_0201292C(func_0215A5E4((void *)b));
    e = func_02159B10((void *)a, (void *)b);
    p = func_02159AE8((void *)a, (void *)b);
    *p = func_02007FB8(d, e, c);
    return 0;
}


int func_021AF6C4(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);

    *func_02159AE8((void *)a, (void *)b) = func_021AF750(x);
    return 0;
}


int func_021AF6E8(u32 a, u32 b)
{
    u32 y = func_0215A5CC((void *)b);
    u32 x = func_02159B10((void *)a, (void *)b);

    *func_02159AE8((void *)a, (void *)b) = func_02020FE4((void *)x, 5, y);
    return 0;
}


int func_021AF71C(u32 a, u32 b)
{
    u32 y = func_0215A5CC((void *)b);
    u32 x = func_02159B10((void *)a, (void *)b);

    *func_02159AE8((void *)a, (void *)b) = func_02020FE4((void *)x, 0xf, y);
    return 0;
}
