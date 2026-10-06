/*
 * function: func_021F3AA0
 * address:  0x021F3AA0
 * packet:   pkt_ov059_021F3AA0
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef unsigned int   u32;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern int *func_021897BC(char *p, int idx);
extern int func_02188D2C(int *p);
extern void func_020061E4(u32 a);
extern V *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern u8 *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void func_021BE6CC(void *p, int i, u16 j, u16 k, int flag);

void func_021F3AA0(void *a, int b, V *c)
{
    int i;
    void *t;
    void *s;
    int flag;

    t = func_0201210C(a);
    func_021897BC(t, 1);
    flag = 1;
    s = (void *)func_02188D2C(t);
    if (b == 0) {
        flag = 0;
        func_020061E4(0x567);
    } else {
        func_020061E4(0x793);
    }
    *func_021BE480(s, 0, flag) = *c;
    func_021BE4B4(s, 0, (u16)flag, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6B0(func_021BE674(s, 0, flag, i), 0);
        func_021BE700(s, 0, flag, i, 1);
        func_021BE6CC(s, 0, flag, i, 0);
    }
}
