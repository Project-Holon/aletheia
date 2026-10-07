/*
 * file:     scrcmd_screeneffects_p35.c
 * unit:     yes
 * function: func_021B1BF4, func_021B1C2C
 * address:  0x021B1BF4
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
 *   func_02158F90  0x02158F90  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021B1E74  0x021B1E74  thumb  ov021
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 */
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int     s32;

typedef unsigned char  u8;

extern void *func_0215A5F4(void *p);
extern int func_021B1E74(u32 a);
extern u16 func_0216D5F8(void *p);
extern u16 func_021642A4(int i);
extern void *func_02158F90(void *p);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D674(void *p, u16 v);
int func_02158F58(int a0);
s16 *func_02159AE8(void *a0, void *a1);
unsigned int func_02159B10(void *a, void *b);
void *func_02188C7C(unsigned char *p);
u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
u16 func_0216D588(void *p);
int func_021B1BF4(u32 a, u32 b);
int func_021B1C2C(int a, int b);


int func_021B1BF4(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    u32 v = func_021642A4(func_0216D5F8((void *)func_021B1E74(b)));
    u32 o = (u32)func_02158F90(s);

    if (o != 0) {
        func_0216D5E0(o, v);
        func_0216D674((void *)o, 0);
    }
    return 0;
}


int func_021B1C2C(int a, int b)
{
    int r7;
    s16 *s8;
    s16 *r6;
    int sc;
    int s10;
    int r4;
    int r0;

    r7 = ((int *)func_02158F58((int)func_0215A5F4((void *)b)))[1];
    s8 = func_02159AE8((void *)a, (void *)b);
    r6 = func_02159AE8((void *)a, (void *)b);
    sc = func_02159B10((void *)a, (void *)b);
    s10 = func_02159B10((void *)a, (void *)b);
    r4 = func_02159B10((void *)a, (void *)b);
    r0 = (int)func_0216DDDC((u32)func_02188C7C((void *)r7), (s16)sc, (s16)r4, s10 << 16, 0x8000, (int)0);
    if (r0) {
        *r6 = 1;
        *s8 = func_0216D588((void *)r0);
    } else {
        *r6 = 0;
    }
    return 0;
}
