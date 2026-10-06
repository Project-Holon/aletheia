/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov045_021F36C0
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The BE480 result goes through the local e: assigning through the call
 * directly schedules the i*12 table offset before the call.
 *
 * symbols:
 *   d_021F3B50     0x021F3B50  data  ov045
 *   d_021F3B80     0x021F3B80  data  ov045  a4
 *   d_021F3BA4     0x021F3BA4  data  ov045  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021F3938  0x021F3938  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern int d_021F3B50;
extern V d_021F3B80[];
extern V d_021F3BA4[];

struct Ctx;
extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32   func_02012EC4(u32 a);
extern int  *func_0200B3A4(u32 a, u32 b);
typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void  func_021BE760(void *p, void *a, int b);
extern V    *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void  func_021F3938(void *a0, int a1, int a2, int a3);

void func_021F36C0(void *a0)
{
    void *r4;
    int *q;
    int i;
    int j;
    int k;
    void *b;
    V *e;

    r4 = (void *)func_02188D2C(a0);
    q = func_0200B3A4(func_02012EC4((u32)func_020120F4(func_02188C80(a0))), 9);
    func_02189764(a0, 1, func_02188C84(a0), 4);
    func_021BE760(r4, &d_021F3B50, 0);
    for (i = 0; i < 3; i++) {
        e = func_021BE480(r4, 0, i);
        *e = d_021F3B80[i];
        func_021BE4A4(r4, 0, (u16)i, 1);
        for (j = 0; j < 2; j++) {
            b = func_021BE674(r4, 0, i, j);
            func_021BE6B8(b, 0);
            func_021BE6B0(b, 1);
        }
        k = i + 3;
        e = func_021BE480(r4, 0, k);
        *e = d_021F3BA4[i];
        func_021BE4A4(r4, 0, (u16)k, 1);
        for (j = 0; j < 2; j++) {
            b = func_021BE674(r4, 0, k, j);
            func_021BE6B8(b, 0);
            func_021BE6B0(b, 1);
        }
        func_021F3938(r4, q[i], i, 1);
        func_021F3938(r4, q[i], i, 0);
    }
}
