/*
 * file:     tr_ai_p16.c
 * unit:     yes
 * function: func_02189CEC, func_02189D48, func_02189E70, func_02189E80, func_02189E90
 * address:  0x02189CEC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021B8DE4 0x021B8DE4 thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021B9C98 0x021B9C98 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021C7E14 0x021C7E14 thumb ov093
 *   func_0218A308 0x0218A308 thumb ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D5B68  0x021D5B68  thumb  ov093
 */
#include "../../matched/include/Obj10192.h"
#include "../../matched/include/Obj21973.h"
#include "../../matched/include/Obj21974.h"
#include "../../matched/include/Obj21975.h"
#include "../../matched/include/Obj21976.h"
#include "../../matched/include/Obj21977.h"

struct Cursor;
struct QG;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021B8DE4(char *p, int i);
extern u8 *func_021B9AF8(u8 *, int);
extern int func_021B99B8(void *pp, unsigned int b);
extern int func_021B9C98(u8 *p, u32 v);
extern u8 func_021D5440(u8 *);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern int func_021D5B7C(void *);
extern u16 func_021C7E14(u8 *p, u8 a, u8 b, u32 c, int e0, int e1);
extern u8 *func_0218A308(void *p, u32 i);
extern int func_0218A0F4(u8 *, int, int, int, int);
extern int func_021D5B68(void *m);
int func_02189CEC(struct Cursor *a, int b);
int func_02189D30(int a, int b);
int func_02189D38(int a, int b);
int func_02189D40(int a, int b);
u32 func_02189D48(struct Cursor *a, u8 *p);
int func_02189E70(struct Cursor *a, u8 *b);
int func_02189E80(struct Cursor *a, u8 *b);
int func_02189E90(struct Cursor *a, u8 *b, int c);


/*
 * func_02189D30, func_02189D38 and func_02189D40 are the unlabelled
 * return-field stubs after the lead function (function_starts seeds).
 * The unit ends at 0x02189D48, where the next function starts.
 */
int func_02189CEC(struct Cursor *a, int b) {
    int r6;
    int r4;
    u8 s;
    u8 *t;
    int x;
    r6 = func_0201134C(a);
    r4 = func_0201134C(a);
    s = func_0218A160((u8 *)b, r6);
    t = func_0218A2FC((u8 *)b, s);
    x = func_021D59B4(t, r4);
    ((struct Obj10192 *)b)->f38 = x - func_021D59B4(*(u8 * *)&((struct Obj10192 *)b)->fBC, r4);
    return ((struct Obj10192 *)b)->fC4;
}


int func_02189D30(int a, int b) {
    return ((struct Obj21973 *)b)->fC4;
}


int func_02189D38(int a, int b) {
    return ((struct Obj21974 *)b)->fC4;
}


int func_02189D40(int a, int b) {
    return ((struct Obj21975 *)b)->fC4;
}

/*
 * 2026-10-05 (wD5 lane16): EXACT*. func_021C7E14 takes u8 position arguments (a, b), and x, y, z are
 *   u8 locals (func_021D5440 returns u8). That moves the `adds r1,rX` before the y reload at both calls.
 *   The ov093 callee also compiles EXACT with `u8 a, u8 b` (scratch test only, file not changed).
 */
u32 func_02189D48(struct Cursor *a, u8 *p)
{
    int t, k;
    u8 x, z;
    u8 *g;
    int j, sel;
    u8 y;
    u32 best;
    int n;
    t = func_0201134C(a);
    k = func_021B8DE4((char *)(*(u8 **)(p + 0xB0)), p[0x94]);
    g = func_021B9AF8(*(u8 **)(p + 0xB8), k);
    n = func_021B99B8(*(u8 **)(p + 0xB0), k);
    sel = func_021B9C98(g, (u32)(*(u8 **)(p + 0xBC)));
    x = func_021D5440(*(u8 **)(p + 0xBC));
    y = func_021D5440(*(u8 **)(p + 0xC0));
    best = func_021C7E14(*(u8 **)(p + 0xB4), x, y, *(u16 *)(p + 2), 1, t);
    if (sel < 0 || best == 0) {
        *(u32 *)(p + 0x38) = 0;
        return *(u32 *)(p + 0xC4);
    }
    for (j = 0; j < n; j++) {
        u8 *m = func_0218A308(g, (u8)j);
        z = func_021D5440(m);
        if (func_021D5B7C(m) != 0 && j != sel) {
            int i;
            *(u32 *)(p + 0x38) = 2;
            for (i = 0; i < (int)func_021D5448((struct QG *)m); i++) {
                u16 c = func_021D54C0(m, (u8)i);
                if (i != p[1]) {
                    u32 r = func_021C7E14(*(u8 **)(p + 0xB4), z, y, c, 1, t);
                    if (r > best) {
                        *(u32 *)(p + 0x38) = 1;
                        break;
                    }
                }
            }
        }
    }
    return *(u32 *)(p + 0xC4);
}

int func_02189E70(struct Cursor *a, u8 *b)
{
    func_02189E90(a,b,2); return ((struct Obj21976 *)b)->fC4;
}

int func_02189E80(struct Cursor *a, u8 *b)
{
    func_02189E90(a,b,3); return ((struct Obj21977 *)b)->fC4;
}


int func_02189E90(struct Cursor *a, u8 *b, int c)
{
    int t;
    int n;
    t = func_0201134C(a);
    n = func_0201134C(a);
    return func_0218A0F4((u8 *)a, c, func_021D5B68(func_0218A2FC(b, func_0218A160(b, t))), 1, n);
}
