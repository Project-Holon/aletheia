/*
 * file:     scrcmd_screeneffects_p31.c
 * unit:     yes
 * function: func_021B16F0, func_021B1700
 * address:  0x021B16F0
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
 *   func_020113D0  0x020113D0  thumb
 *   func_021B16DC  0x021B16DC  thumb  ov021
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 */
typedef unsigned int u32;

typedef unsigned short u16;

extern void func_020113D0(char *p, int val);
extern int func_021B16DC(u32 a, u32 b, u32 c, u32 d);
extern void *func_0215A5EC(void *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0216DE94(void *map, u32 id);
extern u16 func_0216D5A0(void *p);
int func_021B16F0(u32 a);
int func_021B1700(u32 a, u32 b);


int func_021B16F0(u32 a)
{
    func_020113D0((char *)a, (u32)func_021B16DC);
    return 1;
}


int func_021B1700(u32 a, u32 b)
{
    u32 t = (u32)func_0215A5EC((void *)b);
    u16 *o = func_02159AE8((void *)a, (void *)b);

    *o = 0;
    *o = func_0216D5A0(func_0216DE94((void *)t, func_02159B10((void *)a, (void *)b)));
    return 0;
}
