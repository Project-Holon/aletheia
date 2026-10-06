/*
 * function: func_021F37DC
 * address:  0x021F37DC
 * packet:   pkt_ov065_021F37DC
 * region:   ov065
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 */

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void func_021BE580(int a);
extern int func_021BE6E8(int a, int b, int c, int d);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern int func_021BE6BC(int *p);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);

void func_021F37DC(int a)
{
    int s;
    int *w;

    s = func_02188D2C((int *)a);
    w = func_021897BC((char *)a, 1);
    if (w[0] != 0) {
        func_021BE580(s);
        if (w[1] == 0) {
            if (func_021BE6E8(s, 0, 0, 0) == 0x3C000)
                func_020061E4(0x7F9);
        }
        if (func_021BE6BC(func_021BE674((char *)s, 0, 0, 0)) != 0) {
            func_021BE4B4((char *)s, 0, 0, 1);
            w[0] = 0;
            *func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))), 0x36) = 0;
        }
    }
}
