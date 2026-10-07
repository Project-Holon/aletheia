/*
 * file:     unit_02198D3C_p06.c
 * unit:     yes
 * function: func_02199088, func_021990A0, func_021990B8, func_021990D4, func_0219912C, func_021991F0
 * address:  0x02199088
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
 *   func_02199034  0x02199034  thumb  ov021
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   d_021D4C1C     0x021D4C1C  data   a4
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0216DA70  0x0216DA70  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D848  0x0216D848  thumb  ov010
 *   func_0216D860  0x0216D860  thumb  ov010
 *   func_0216D87C  0x0216D87C  thumb  ov010
 *   func_02163F8C  0x02163F8C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } Vec;

typedef struct { int w[10]; } T40;

extern u32 func_0216D7CC(u32);
extern int func_02199034(u32 a, u32 b, u32 c, u32 d);
extern void func_0216D674(void *p, u16 v);
extern void *func_0216D6BC(int a0, int a1, int a2);
extern void *func_0216D6D4(void *p);
extern void func_0216D8C0(u32, Vec *);
extern void func_0216D5E0(int a0, int a1);
extern int func_0216D600(int a0, u16 a1);
extern void func_0216DA70(void *a0);
extern int func_0216D83C(void *p);
extern u32 func_0216D80C(u32, u32);
extern int func_0216D854(void *p);
extern u32 func_0216D818(u32, u32);
extern int func_0216D86C(void *p);
extern u32 func_0216D824(u32, u32);
extern void func_0216D848(char *p, short v);
extern void func_0216D860(char *p, short v);
extern void func_0216D87C(char *p, short v);
extern u32 func_02163F8C(u32, int *);
extern void *func_0216D568(void *p, u32 v);
extern int func_02163F10(int a0);
int func_02199088(u32 a, u32 b, u32 c, u32 d);
int func_021990A0(u32 a, u32 b, u32 c, u32 d);
int func_021990B8(u32 a, u32 b, u32 c, u32 d);
int func_021990D4(u32 a);
void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);
int func_021991F0(u32 a);
extern T40 d_021D4C1C;


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02199088(u32 a, u32 b, u32 c, u32 d)
{
func_02199034(a, 2, 40, d);
func_0216D7CC(a);
return 0;
}


int func_021990A0(u32 a, u32 b, u32 c, u32 d)
{
func_02199034(a, 0, 12, d);
func_0216D7CC(a);
return 0;
}


int func_021990B8(u32 a, u32 b, u32 c, u32 d)
{
func_0216D6BC(a, 4, c);
func_0216D674((void *)a, 1);
func_0216D7CC(a);
return 1;
}


int func_021990D4(u32 a)
{
    Vec v = { 0, 0, 0 };
    T40 t;
    int *p;
    int i;

    t = d_021D4C1C;
    p = func_0216D6D4((void *)a);
    i = p[0];
    if (i >= 10) {
        i = 9;
    }
    v.y = t.w[i];
    func_0216D8C0(a, &v);
    p[0] = p[0] + 1;
    if (p[0] >= 20) {
        func_0216D7CC(a);
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f)
{
    u32 *q;

    q = func_0216D6BC(a, 16, c);
    q[0] = e;
    *(Vec *)(q + 1) = *b;
    func_0216D5E0(a, (u16)c);
    func_0216D600(a, (u16)d);
    func_0216D674((void *)a, f);
    func_0216DA70((void *)a);
    func_0216D80C(a, func_0216D83C((void *)a));
    func_0216D818(a, func_0216D854((void *)a));
    func_0216D824(a, func_0216D86C((void *)a));
    if (b->x < 0) {
        func_0216D848((char *)a, -1);
    } else if (b->x > 0) {
        func_0216D848((char *)a, 1);
    }
    if (b->y < 0) {
        func_0216D860((char *)a, -1);
    } else if (b->y > 0) {
        func_0216D860((char *)a, 1);
    }
    if (b->z < 0) {
        func_0216D87C((char *)a, -1);
    } else if (b->z > 0) {
        func_0216D87C((char *)a, 1);
    }
    func_0216D7CC(a);
}


int func_021991F0(u32 a)
{
    int *p;

    p = func_0216D6D4((void *)a);
    func_02163F8C(a, p + 1);
    p[0] = p[0] - 1;
    if (p[0] > 0) {
        return 0;
    }
    func_0216D568((void *)a, 1088);
    func_02163F10(a);
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}
