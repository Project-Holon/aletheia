/*
 * function: func_021F407C
 * address:  0x021F407C
 * packet:   pkt_ov038_021F407C
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     `k++` on the u8 local keeps the increment of the stored zero
 *           (adds; lsls; lsrs); `k = k + 1` folds it to `movs #1` and swaps
 *           a1/sys between r5 and r6.
 *
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE4B4 0x021BE4B4 thumb ov021
 *   func_021BE480 0x021BE480 thumb ov021
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_021BE6CC 0x021BE6CC thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 *   func_020061E4 0x020061E4 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int x, y, z;
} Vec;

struct Ctx;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188D2C(int *p);
extern u8 *func_021897BC(void *p, int idx);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern Vec *func_021BE480(char *p, int i, int j);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern int func_021BE6BC(int *p);
extern void func_020061E4(u32 a);

int func_021F407C(int a0, int *a1)
{
    void *sys;
    char *h;
    u8 *s;
    u8 c;
    u8 k;
    void *o;
    Vec *v;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = (char *)func_02188D2C(sys);
    s = func_021897BC(sys, 1);
    func_02188CB4(sys);
    k = 0;
    c = s[3] + 0x12;
    if (s[6] == 1) {
        k++;
    }
    o = func_021BE674(h, 0, 0x21, k);
    switch (*a1) {
    case 0:
        func_021BE4B4(h, 0, c, 1);
        func_021BE4B4(h, 0, 0x21, 0);
        v = func_021BE480(h, 0, c);
        *func_021BE480(h, 0, 0x21) = *v;
        func_021BE700(h, 0, 0x21, k, 1);
        func_021BE6B0(o, 0);
        func_021BE6CC((int)h, 0, 0x21, k, 0);
        func_020061E4(0x6C5);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_021BE6BC(o)) {
            func_021BE700(h, 0, 0x21, k, 0);
            func_021BE4B4(h, 0, 0x21, 1);
            func_021BE4B4(h, 0, c, 0);
            return 1;
        }
        break;
    }
    return 0;
}
