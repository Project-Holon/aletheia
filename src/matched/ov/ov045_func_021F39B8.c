/*
 * function: func_021F39B8
 * address:  0x021F39B8
 * packet:   pkt_ov045_021F39B8
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021F39A8  0x021F39A8  thumb
 *   func_021F3938  0x021F3938  thumb
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 */

typedef unsigned char u8;

struct Big;
struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
typedef unsigned int   u32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int   func_021F39A8(int *p, int i);
extern void  func_021F3938(void *a0, int a1, int a2, int a3);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern int func_021BE6BC(int *p);

int func_021F39B8(void *a0, int *a1)
{
    void *r7;
    void *r6;
    int *s;
    int *p;
    int flag;
    int idx;
    u8 v;

    r7 = func_0201210C(func_020124E4(a0));
    r6 = (void *)func_02188D2C(r7);
    s = func_021897BC(r7, 1);
    flag = 1;
    p = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(r7))), 9);
    switch (*a1) {
    case 0:
        idx = s[0];
        v = func_021F39A8(p, idx);
        func_021BE6B0(func_021BE674(r6, 0, (u8)(idx + 3), v), 0);
        *a1 = *a1 + 1;
        break;
    case 1:
        idx = s[0];
        v = func_021F39A8(p, idx);
        if (func_021BE6BC(func_021BE674(r6, 0, (u8)(idx + 3), v))) {
            if (p[s[0]]) {
                flag = 0;
            }
            func_021F3938(r6, flag, s[0], 0);
            return 1;
        }
        break;
    }
    return 0;
}
