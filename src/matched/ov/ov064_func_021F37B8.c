/*
 * function: func_021F37B8
 * address:  0x021F37B8
 * packet:   pkt_ov064_021F37B8
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F384C  0x021F384C  thumb  ov064
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern int func_0201210C(int a);
extern int func_02188D2C(int a);
extern int func_02188CB4(int a);
extern void func_021A3038(int a, V3 *v);
extern int func_021BE480(int a, unsigned b, int c);
extern void func_021BE4B4(int a, int b, int c, int d);
extern u8 *func_021BE674(int a, int b, int c, u16 d);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(int a, int b, int c, u16 d, int e);
extern void func_021BE6CC(int a, int b, int c, u16 d, int e);
extern int func_020122C0(int a, int b, void *cb, int c);
extern int func_021F384C(void *task, int *st);

void func_021F37B8(int a)
{
    int i;
    int sys;
    int s;
    V3 v;

    sys = func_0201210C(a);
    s = func_02188D2C(sys);
    func_021A3038(func_02188CB4(sys), &v);
    *(V3 *)func_021BE480(s, 0, 0) = v;
    func_021BE4B4(s, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        func_021BE6B0(func_021BE674(s, 0, 0, i), 0);
        func_021BE700(s, 0, 0, i, 1);
        func_021BE6CC(s, 0, 0, i, 0);
    }
    func_020122C0(a, 0, (void *)func_021F384C, 0);
}
