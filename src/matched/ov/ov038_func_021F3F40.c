/*
 * function: func_021F3F40
 * address:  0x021F3F40
 * packet:   pkt_ov038_021F3F40
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     k (0x021BE674/0x021BE700/0x021BE6CC fourth argument) is an enum
 *           local incremented as `k = (u8)(k + 1)`: a u8 local folds 2+1 to
 *           `movs #3`, and the enum keeps the unfolded adds plus truncation.
 *           Those callees take the enum through an `int` parameter; a u16
 *           parameter adds a second truncation before each bl.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { K_0 } KType;

typedef struct {
    int a;
    int b;
    int c;
} V3;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
struct Big;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern V3 *func_021BE480(int p, int i, int j);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_021BE6CC(int p, int i, int j, int k, int flag);
extern int func_021BE6BC(int *p);
extern void func_020061E4(u32 se);

int func_021F3F40(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    int *p;
    u8 c;
    int j;
    KType k;
    void *e;
    V3 *src;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    func_02188CB4(sys);
    p = func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(sys))), 6);
    if (*(int *)((char *)p + s[3] * 4 + 0x48) == 0) {
        c = s[3] + 0x12;
        j = 0x21;
    } else {
        c = s[3] + 0x19;
        j = 0x22;
    }
    k = 2;
    if (s[6] == 1)
        k = (u8)(k + 1);
    e = func_021BE674((char *)h, 0, j, k);
    switch (*a1) {
    case 0:
        func_021BE4B4((char *)h, 0, c, 1);
        func_021BE4B4((char *)h, 0, j, 0);
        src = func_021BE480(h, 0, c);
        *func_021BE480(h, 0, j) = *src;
        func_021BE700((void *)h, 0, j, k, 1);
        func_021BE6B0(e, 0);
        func_021BE6CC(h, 0, j, k, 0);
        func_020061E4(0x6C5);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_021BE6BC(e)) {
            func_021BE700((void *)h, 0, j, k, 0);
            func_021BE4B4((char *)h, 0, j, 1);
            func_021BE4B4((char *)h, 0, c, 0);
            return 1;
        }
        break;
    }
    return 0;
}
