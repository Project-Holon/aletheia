/*
 * file:     weather_task_p85.c
 * unit:     yes
 * function: func_021A712C, func_021A7198
 * address:  0x021A712C
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
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219F058  0x0219F058  thumb  ov021
 *   func_021A3674  0x021A3674  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A7258  0x021A7258  thumb  ov021
 *   func_021A35BC  0x021A35BC  thumb  ov021
 *   func_021A35F0  0x021A35F0  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02164208  0x02164208  thumb  ov010
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 */
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct V { u32 x, y, z; } V;

extern void *func_021A3074(unsigned char *p);
extern void func_0219F058(u32 a, u16 *o1, u16 *o2);
extern void func_021A3674(u8 *p, u32 b, u32 c);
extern u16 func_0216D5F8(void *p);
extern void func_021A7258(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern int func_021A35BC(int a);
extern int func_021A35F0(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02188C98(u8 *p);
extern void func_021A3038(unsigned char *a, struct VecFx32 *b);
extern void func_02164208(int dir, int *p, int amt);
extern int func_021AB0D4(void *a, void *b);
extern int func_021AB11C(u32 attr);
void func_021A712C(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g);
int func_021A7198(u32 a, u32 *b, V *c, u32 d);


/*
 * Addresses are Black-image addresses.
 */
void func_021A712C(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    u16 v[2];
    void *h;
    u32 fl;
    fl = 0;
    h = func_021A3074((unsigned char *)b[1]);
    func_0219F058((u32)h, &v[0], &v[1]);
    func_021A3674((u8 *)b[1], 0, 0);
    if (d == 0)
        c = func_0216D5F8(h);
    func_021A7258(a, b, 0, e, c, v[0], v[1]);
    if (func_021A35BC(b[1]) == 1)
        fl |= 1;
    func_021A35F0(b[1], f, g, fl);
}


int func_021A7198(u32 a, u32 *b, V *c, u32 d)
{
    u32 h;
    V v;
    h = func_02188C98((u8 *)a);
    func_021A3038((unsigned char *)b[1], (struct VecFx32 *)c);
    v = *c;
    func_02164208(d, (int *)(&v), 0x10000);
    if (func_021AB11C(func_021AB0D4((void *)h, &v)) == 0)
        return 1;
    return 0;
}
