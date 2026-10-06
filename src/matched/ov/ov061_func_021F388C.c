/*
 * function: func_021F388C
 * address:  0x021F388C
 * packet:   pkt_ov061_021F388C
 * region:   ov061
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_02162560, func_02162A64 (a thunk) and func_02162CE8 behind it are
 * unlabelled ov010 leaves filed alongside this function.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162560  0x02162560  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02162A64  0x02162A64  thumb  ov010
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern u16 func_02162560(u8 *p);
extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern void *func_021625CC(char *p, unsigned i);
extern u8 func_021626E8(u8 *p);
extern void func_02162A64(const void *p, V3 *out);
extern u16 func_02188C9C(u8 *p);
extern void *func_021BE480(int a, int b, u16 c);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE700(int a, int b, u16 c, u16 d, int e);

void func_021F388C(int *o, int a)
{
    int h;
    int n;
    int s;
    int i;
    void *e;
    V3 v;

    h = func_02012844(func_020120F4(func_02188C80((void *)a)));
    n = func_02162560((u8 *)h);
    func_02188C84((u8 *)a);
    s = func_02188D2C((int *)a);
    for (i = 0; i < 8; i++) {
        func_021BE4B4((char *)s, 0, (u16)(i + 1), 1);
    }
    for (i = 0; i < n; i++) {
        e = func_021625CC((char *)h, (u16)i);
        if (e != 0 && func_021626E8(e) == 6) {
            func_02162A64(e, &v);
            if (func_02188C9C((u8 *)a) == 0x12E) {
                v.b -= 0x2000;
            }
            func_021BE4B4((char *)s, 0, (u16)(i + 1), 0);
            *(V3 *)func_021BE480(s, 0, i + 1) = v;
            func_021BE674((char *)s, 0, (u16)(i + 1), (u16)0);
            func_021BE700(s, 0, i + 1, 0, 1);
        }
    }
}
