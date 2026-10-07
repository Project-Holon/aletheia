/*
 * file:     btl_server_p143.c
 * unit:     yes
 * function: func_021D04E4, func_021D055C, func_021D05C4, func_021D0644
 * address:  0x021D04E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021D7F2C  0x021D7F2C  thumb  ov093
 *   func_021CFBBC  0x021CFBBC  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021D799C  0x021D799C  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_0201C314  0x0201C314  thumb
 *   func_021CF5B0  0x021CF5B0  thumb  ov093
 *   func_0201C1C8  0x0201C1C8  thumb
 */
#include "../../matched/include/Obj01690.h"
#include "../../matched/include/Obj00340.h"
#include "../../matched/include/Obj03197.h"

struct Q1;
struct S2;
struct QG;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char    s8;

extern u8 func_021B9B94(struct Q1 *p);
extern u32 func_021B8588(void **p);
extern u8 func_021D7F2C(u32 a, u8 b);
extern int func_021CFBBC(s8 *p, int v);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *m);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D5B7C(void *m);
extern u16 func_021D57FC(void *m);
extern int func_021D799C(int a, int b);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u32 func_0201C314(void *p);
extern int func_021CF5B0(u8 *g, void *m, u32 move, void *out);
extern u8 func_0201C1C8(void *p);
int func_021D04E4(u8 *g, u8 a, u8 *out);
int func_021D055C(u8 *g, void *a, int b);
int func_021D05C4(u8 *g, u8 a, int b, u8 *out);
int func_021D0644(void *g, void *m, void *a, int b);


int func_021D04E4(u8 *g, u8 a, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(((struct Obj01690 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj01690 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            m = func_021B9C00(((struct Obj01690 *)g)->f118, (u8)i);
            if (func_021D5B68(m) == 0 && a == func_021D59B4(m, 0x11)) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}


int func_021D055C(u8 *g, void *a, int b)
{
    u32 n;
    u32 i;

    n = func_021B9B94(((struct Obj00340 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj00340 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            if (func_021D0644(g, func_021B9C00(((struct Obj00340 *)g)->f118, (u8)i), a, b))
                return 1;
        }
    }
    return 0;
}


int func_021D05C4(u8 *g, u8 a, int b, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(((struct Obj03197 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj03197 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            m = func_021B9C00(((struct Obj03197 *)g)->f118, (u8)i);
            if (func_021D5B7C(m) != 0 && func_021D799C(a, func_021D57FC(m)) <= b) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}


int func_021D0644(void *g, void *m, void *a, int b)
{
    int x;
    u8 n;
    u32 i;
    u32 q;

    if (func_021D5B68(m) == 0) {
        x = func_021D57FC(a);
        n = func_021D5448(m);
        for (i = 0; i < n; i++) {
            q = func_021D54C0(m, (u8)i);
            if (func_021D5584(m, (u8)i) && func_0201C314((void *)q)
                && func_021CF5B0(g, m, q, 0) == 0) {
                if (func_021D799C(func_0201C1C8((void *)q), x) >= b)
                    return 1;
            }
        }
    }
    return 0;
}
