/*
 * function: func_021F3A28
 * address:  0x021F3A28
 * packet:   pkt_ov046_021F3A28
 * region:   ov046
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F40D8  0x021F40D8  thumb  ov046
 *   func_021F3FA8  0x021F3FA8  thumb  ov046
 */

typedef unsigned int u32;
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern void *func_0200B3A4(u32, u32);
extern void func_021BE580(u32);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern int func_021F40D8(int *);
extern void func_021F3FA8(char *a, u32 b, u32 c);

void func_021F3A28(void *a)
{
    int v[3];
    u32 r7 = func_02188D2C(a);
    int *r6 = func_021897BC(a, 1);
    int r4 = 1;

    func_0200B3A4((u32)func_02012EC4(func_020120F4(func_02188C80(a))), 10);
    func_021BE580(r7);
    func_021A3038(func_02188CB4((void *)a), (struct VecFx32 *)v);
    if (func_021F40D8(v) == 0)
        r4 = 0;
    if (r6[9] != r4) {
        func_021F3FA8((char *)r7, (u32)a, r4);
        r6[9] = r4;
    }
}
