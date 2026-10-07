/*
 * file:     scrcmd_screeneffects_p32.c
 * unit:     yes
 * function: func_021B1738, func_021B176C
 * address:  0x021B1738
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
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216E0E8  0x0216E0E8  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 */
typedef unsigned int u32;

typedef signed short s16;

extern void *func_0215A5EC(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0216DE94(void *map, u32 id);
extern int func_0216E0E8(int a0, int a1);
s16 *func_02159AE8(void *a0, void *a1);
int func_0216D83C(void *p);
int func_0216D86C(void *p);
int func_021B1738(u32 a, u32 b);
int func_021B176C(int a, int b);


int func_021B1738(u32 a, u32 b)
{
    u32 t = (u32)func_0215A5EC((void *)b);
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 y = func_02159B10((void *)a, (void *)b);

    func_0216E0E8((int)func_0216DE94((void *)t, x), y);
    return 0;
}


int func_021B176C(int a, int b)
{
    int r6;
    s16 *r7;
    s16 *r4;

    r6 = (int)func_0215A5EC((void *)b);
    r6 = (int)func_0216DE94((void *)r6, func_02159B10((void *)a, (void *)b));
    r7 = func_02159AE8((void *)a, (void *)b);
    r4 = func_02159AE8((void *)a, (void *)b);
    *r7 = func_0216D83C((void *)r6);
    *r4 = func_0216D86C((void *)r6);
    return 0;
}
