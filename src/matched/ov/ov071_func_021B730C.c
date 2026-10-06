/*
 * function: func_021B730C
 * address:  0x021B730C
 * packet:   pkt_ov071_021B730C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B7880  0x021B7880  thumb  ov071
 *   func_021B78F4  0x021B78F4  thumb  ov071
 *   func_021B7924  0x021B7924  thumb  ov071
 *   func_021B7A68  0x021B7A68  thumb  ov071
 *   func_021B7B10  0x021B7B10  thumb  ov071
 *   func_021B7BD8  0x021B7BD8  thumb  ov071
 *   func_021B7014  0x021B7014  thumb  ov071
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   d_021BA8A0     0x021BA8A0  data  a4
 */
#include "../include/Obj13174.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021B7880(void);
extern void func_021B78F4(void *p, void **q);
extern void func_021B7924(void **p, void **q);
extern void func_021B7A68(void *a, void *b);
extern void func_021B7B10(int *a, char *b);
extern void func_021B7BD8(void *p, int a);
extern int func_021B7014(int *, const int *, int);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_02043598(u32 mask, u32 enable);
extern const char d_021BA8A0[];

int func_021B730C(void *ctx, int *st, int *w)
{
    u8 *m;

    switch (st[0]) {
    case 0:
        m = func_0203159C(ctx, 0x84, 0x61);
        func_02082BCC(m, 0, 0x84);
        m[0x82] = 0;
        func_021B7880();
        func_021B78F4(w, (void *)w[1]);
        func_021B7924((void **)m, (void *)w[1]);
        func_021B7A68(m, w);
        func_021B7B10(w, (char *)m);
        func_021B7BD8(w, (int)m);
        ((struct Obj13174 *)m)->f7C = func_021B7014((int *)w[1], (const int *)(d_021BA8A0 + *(u8 *)w[2] * 8), 1);
        st[0]++;
        break;
    case 1:
        func_02040588(6, 1);
        func_02043598(0x10, 1);
        return 1;
    }
    return 0;
}
