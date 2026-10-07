/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov038_021F36C0
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     each loop keeps its own index variables: the third loop's n and
 *           t = n + 0x12 are separate from the second loop's i and k (sharing
 *           them moves the spilled index to another slot), the q lookups
 *           are spelled q[i + 8] / q[n + 0x12] (q[k] scales k instead), and
 *           i is declared before q.
 *
 * symbols:
 *   d_021F464C     0x021F464C  data  a4
 *   d_021F46E8     0x021F46E8  data  a4
 *   d_021F4748     0x021F4748  data  a4
 *   d_021F4694     0x021F4694  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02030344  0x02030344  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 */

#include "../include/G_S3A08.h"

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern int d_021F464C;
extern V d_021F46E8[];
extern V d_021F4748[];
extern struct S3A08 d_021F4694[];

struct Ctx;
extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
struct Big;
extern unsigned char *func_02012EC4(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
typedef unsigned char  u8;
extern void *func_02030344(u32 heapId);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void  func_021BE760(void *p, void *a, int b);
extern V    *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void  func_021BE4B4(void *p, int i, u16 j, int v);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void  func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void  func_021BE6CC(void *p, int i, u16 j, u16 k, int v);
extern int func_021BE748(u32 a);

void func_021F36C0(void *a0)
{
    void *r5;
    int i;
    int *q;
    int n;
    int j;
    int k;
    int t;
    int m;
    void *b;
    V *e;
    V v;

    r5 = (void *)func_02188D2C(a0);
    q = func_0200B3A4((struct Rec94 *)func_02012EC4((struct Big *)func_020120F4(func_02188C80(a0))), 6);
    func_02030344(0x15);
    func_02189764(a0, 1, func_02188C84(a0), 0x24);
    func_021BE760(r5, &d_021F464C, 0);
    func_02030344(0x15);
    for (i = 0; i < 8; i++) {
        e = func_021BE480(r5, 0, i);
        *e = d_021F46E8[i];
        func_021BE4A4(r5, 0, (u16)i, 1);
        for (j = 0; j < 2; j++) {
            b = func_021BE674(r5, 0, i, j);
            func_021BE6B8(b, 0);
            func_021BE700(r5, 0, i, j, 1);
            func_021BE6B0(b, 1);
            if (q[i] != 0)
                func_021BE6CC(r5, 0, i, j, func_021BE748((u32)b));
        }
    }
    for (i = 0; i < 10; i++) {
        k = i + 8;
        e = func_021BE480(r5, 0, k);
        *e = d_021F4748[i];
        func_021BE4A4(r5, 0, (u16)k, 1);
        for (j = 0; j < 2; j++) {
            b = func_021BE674(r5, 0, k, j);
            func_021BE6B8(b, 0);
            func_021BE700(r5, 0, k, j, 1);
            func_021BE6B0(b, 1);
            if (q[i + 8] != 0)
                func_021BE6CC(r5, 0, k, j, func_021BE748((u32)b));
        }
    }
    for (n = 0; n < 7; n++) {
        t = n + 0x12;
        m = n + 0x19;
        e = func_021BE480(r5, 0, t);
        v = ((V *)d_021F4694)[n];
        *e = v;
        *func_021BE480(r5, 0, m) = v;
        func_021BE4A4(r5, 0, (u16)t, 1);
        func_021BE4A4(r5, 0, (u16)m, 1);
        switch (q[n + 0x12]) {
        case 0:
            func_021BE4B4(r5, 0, m, 1);
            break;
        case 1:
            func_021BE4B4(r5, 0, t, 1);
            break;
        }
    }
    func_021BE4A4(r5, 0, (u16)0x20, 1);
    for (i = 0; i < 2; i++) {
        b = func_021BE674(r5, 0, 0x20, i);
        func_021BE6B8(b, 0);
        func_021BE6B0(b, 1);
    }
    for (i = 0; i < 8; i++) {
        b = func_021BE674(r5, 0, 0x21, i);
        func_021BE6B8(b, 0);
        func_021BE700(r5, 0, 0x21, i, 0);
    }
    for (i = 0; i < 4; i++) {
        b = func_021BE674(r5, 0, 0x22, i);
        func_021BE6B8(b, 0);
    }
    func_021BE4B4(r5, 0, 0x21, 1);
    func_021BE4B4(r5, 0, 0x22, 1);
    func_02030344(0x15);
}
