/*
 * function: func_021C8FF0
 * address:  0x021C8FF0
 * packet:   pkt_ov021_021C8FF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204784C  0x0204784C  arm
 *   func_020478B8  0x020478B8  arm
 *   func_02047828  0x02047828  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DABCC     0x021DABCC  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct T { int w[15]; } T;

extern T d_021DABCC;

typedef signed int     s32;
struct AnmCtl;
extern u32 func_0204784C(struct AnmCtl *c, u32 idx, s32 *frame);
struct Arg;
extern int func_020478B8(void *a, int idx, int amount);
extern u32 func_02047828(struct AnmCtl *c, u32 idx, s32 *frame);
extern void func_0207ADC4(int *m);
extern void func_021AC1B8(u32 a, T *t);
extern int func_02047AC8(void *a0, struct Arg *a1);

void func_021C8FF0(u32 a, u32 *b)
{
    T t;
    u32 h;

    if (b[2] == 0) {
        t = d_021DABCC;
        h = *(u32 *)(b[0] + 0x30);
        func_0204784C((struct AnmCtl *)h, 0, (s32 *)(b + 1));
        if (func_020478B8((void *)h, 0, 0x1000) == 0) {
            b[2] = 1;
        }
        if (func_02047828((struct AnmCtl *)h, 0, (s32 *)(b + 1)) == 0) {
            b[2] = 1;
        }
        func_0207ADC4(&t.w[6]);
        func_021AC1B8(a, &t);
        func_02047AC8((void *)h, (struct Arg *)(&t));
    }
}
