/*
 * function: func_021F3714
 * address:  0x021F3714
 * packet:   pkt_ov049_021F3714
 * region:   ov049
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the 12-byte table is copied field by field from a const table: a
 *           V3 struct assignment gives ldm/stm, and a non-const table keeps
 *           the third load below the second store.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F3894     0x021F3894  data  ov049  a4
 *   d_021F38A4     0x021F38A4  data  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

extern const V3 d_021F38A4[];
extern char d_021F3894[];

extern u32 func_02188C80(u32 a);
extern u32 func_020120F4(u32 a);
extern void *func_0201296C(u32 a);
extern int func_020142E8(void *bitmap, int id);
extern u32 func_02188D2C(u32 a);
extern void func_021BE760(u32 a, void *b, int c);
extern V3 *func_021BE480(u32 a, int b, u16 c);
extern void func_021BE700(u32 a, int b, int c, int d, int e);

void func_021F3714(u32 a0, u32 a)
{
    int f0;
    int f1;
    int f2;
    int f3;
    void *sv;
    u32 s;
    int i;
    V3 *p;

    sv = func_0201296C(func_020120F4(func_02188C80(a)));
    f0 = func_020142E8(sv, 0x96B);
    f1 = func_020142E8(sv, 0x96A);
    f2 = func_020142E8(sv, 0x969);
    f3 = func_020142E8(sv, 0x96C);
    s = func_02188D2C(a);
    func_021BE760(s, d_021F3894, 0);
    for (i = 0; i < 6; i++) {
        p = func_021BE480(s, 0, i);
        p->a = d_021F38A4[i].a;
        p->b = d_021F38A4[i].b;
        p->c = d_021F38A4[i].c;
    }
    if (f0 && f1 && f2 && f3) {
        func_021BE700(s, 0, 0, 0, 1);
        func_021BE700(s, 0, 1, 0, 1);
    }
    if (f0)
        func_021BE700(s, 0, 2, 1, 1);
    else
        func_021BE700(s, 0, 2, 0, 1);
    if (f1)
        func_021BE700(s, 0, 3, 1, 1);
    else
        func_021BE700(s, 0, 3, 0, 1);
    if (f2)
        func_021BE700(s, 0, 4, 1, 1);
    else
        func_021BE700(s, 0, 4, 0, 1);
    if (f3)
        func_021BE700(s, 0, 5, 1, 1);
    else
        func_021BE700(s, 0, 5, 0, 1);
}
