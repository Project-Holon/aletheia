/*
 * function: func_021F3A44
 * address:  0x021F3A44
 * packet:   pkt_ov064_021F3A44
 * region:   ov064
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern void *func_0201210C(void *p);
extern int func_02188D2C(int *p);
extern void func_020061E4(int a);
extern int func_021BE480(int a, unsigned b, int c);
extern void func_021BE4B4(int a, int b, int c, int d);
extern u8 *func_021BE674(int a, int b, int c, u16 d);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(int a, int b, int c, u16 d, int e);
extern void func_021BE6CC(int a, int b, int c, u16 d, int e);

void func_021F3A44(int a, V3 *v)
{
    int i;
    int s;

    s = func_02188D2C(func_0201210C((void *)a));
    func_020061E4(0x567);
    *(V3 *)func_021BE480(s, 0, 1) = *v;
    func_021BE4B4(s, 0, 1, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0(func_021BE674(s, 0, 1, i), 0);
        func_021BE700(s, 0, 1, i, 1);
        func_021BE6CC(s, 0, 1, i, 0);
    }
}
