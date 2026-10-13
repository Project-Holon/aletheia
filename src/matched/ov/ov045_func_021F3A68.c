/*
 * function: func_021F3A68
 * address:  0x021F3A68
 * packet:   pkt_ov045_021F3A68
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: func_021F39A8's result held in a u8 local k (truncated in place,
 * lsls r0 / lsrs r3, where passing the call inline copies it to r3 first);
 * f = 1 written after q's assignment (before it, it takes r0 and lands
 * after the copy of t). The extent past 0x021F3B36 is rodata.
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
 *   func_021F39A8  0x021F39A8  thumb  ov045
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_021F3938  0x021F3938  thumb  ov045
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
struct Big;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int func_021F39A8(int *p, int i);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(u8 *p, int v);
extern int func_021BE6BC(int *p);
extern void func_020061E4(u32 a);
extern void GFL_USE_StopAllSe(void);
extern void func_021F3938(void *a0, int a1, int a2, int a3);

int func_021F3A68(void *a, int *st)
{
    int f;
    void *s;
    u32 t;
    int *q;
    int *w;
    int i;
    u8 k;

    s = func_0201210C(func_020124E4(a));
    t = func_02188D2C(s);
    q = func_021897BC(s, 1);
    f = 1;
    w = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(s))), 9);
    switch (*st) {
    case 0:
        i = *q;
        k = func_021F39A8(w, i);
        func_021BE6B0(func_021BE674((char *)t, 0, (u8)i, (u8)k), 0);
        func_020061E4(0x6d0);
        (*st)++;
        break;
    case 1:
        i = *q;
        k = func_021F39A8(w, i);
        if (func_021BE6BC(func_021BE674((char *)t, 0, (u8)i, (u8)k))) {
            GFL_USE_StopAllSe();
            func_020061E4(0x6f0);
            if (w[*q] != 0)
                f = 0;
            func_021F3938((void *)t, f, *q, 1);
            w[*q] = w[*q] ? 0 : 1;
            return 1;
        }
        break;
    }
    return 0;
}
