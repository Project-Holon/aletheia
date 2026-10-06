/*
 * function: func_0219912C
 * address:  0x0219912C
 * packet:   pkt_ov021_0219912C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
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
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern void *func_0216D6BC(int a0, int a1, int a2);
extern void func_0216D5E0(int a0, int a1);
extern u32 func_0216D600(u32, u32);
extern void func_0216D674(void *p, u16 v);
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
extern u32 func_0216D7CC(u32);

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
