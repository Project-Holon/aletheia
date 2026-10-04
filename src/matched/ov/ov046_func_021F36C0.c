/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov046_021F36C0
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The [sp,#0xc] word the loop passes is mwcc's hoisted constant 1, spilled,
 * and f = (func_021F40D8(vec) != 0 ? 1 : 0) coalesces with it; a named
 * f = 1 before the loop is propagated as a literal instead (41 bytes off).
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021F3838  0x021F3838  thumb  ov046
 *   func_021F38D4  0x021F38D4  thumb  ov046
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F40D8  0x021F40D8  thumb  ov046
 *   func_021F3FA8  0x021F3FA8  thumb  ov046
 *   func_021F4078  0x021F4078  thumb  ov046
 *   d_021F4120     0x021F4120  data  a4
 *   d_021F4108     0x021F4108  data  a2
 *   d_021F4194     0x021F4194  data  a4
 *   d_021F4170     0x021F4170  data  a4
 *   d_021F4204     0x021F4204  data  a4
 *   d_021F41B8     0x021F41B8  data  a4
 */
#include "../include/Obj20520.h"

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern int func_02188D2C(int *p);
struct Big;
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u8 *func_0200B3A4(u32 a, u32 b);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021BE760(u32 p, void *a, int b);
extern void func_021F3838(u32 a0, int a1, V *a2, u16 *a3, int a4, int a5);
extern void func_021F38D4(u8 *base, u32 t, int idx);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void *func_02188CB4(u8 *p);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern int func_021F40D8(int *p);
extern void func_021F3FA8(u32 a, u32 b, u32 c);
extern void func_021F4078(u32 a, int b, int c);

extern int d_021F4120;
extern u16 d_021F4108[];
extern V d_021F4194[];
extern V d_021F4170[];
extern V d_021F4204[];
extern V d_021F41B8;

void func_021F36C0(void *a0)
{
    V tmp;
    int vec[3];
    u16 v;
    int i;
    u32 t;
    u8 *w;
    u8 *x;
    int n;
    int f;

    t = func_02188D2C(a0);
    w = func_0200B3A4((u32)func_02012EC4(func_020120F4(func_02188C80(a0))), 10);
    x = func_02189764(a0, 1, func_02188C84(a0), 0x28);
    func_021BE760(t, &d_021F4120, 0);
    for (i = 0; i < 3; i++) {
        v = 0;
        v = d_021F4108[i];
        n = i * 5;
        func_021F3838(t, n, &d_021F4194[i], &v, 8, 0);
        func_021F3838(t, n + 1, &d_021F4170[i], &v, 2, 0);
        func_021F3838(t, n + 2, &d_021F4170[i], &v, 2, 0);
        func_021F3838(t, n + 3, &d_021F4204[i * 2], 0, 1, 1);
        func_021F3838(t, n + 4, &d_021F4204[i * 2 + 1], 0, 1, 1);
        func_021F38D4(w, t, i);
    }
    tmp = d_021F41B8;
    func_021F3838(t, 0xf, &tmp, 0, 0, 0);
    func_021BE700((void *)t, 0, 0xf, 0, 1);
    func_021A3038(func_02188CB4((void *)a0), (struct VecFx32 *)vec);
    f = func_021F40D8(vec) != 0 ? 1 : 0;
    func_021F3FA8(t, (u32)a0, f);
    ((struct Obj20520 *)x)->f24 = f;
    for (i = 0; i < 3; i++)
        func_021F4078((u32)a0, i, *(int *)(w + i * 12));
}
