/*
 * file:     btl_server_p137.c
 * unit:     yes
 * function: func_021CEEB8, func_021CEFFC
 * address:  0x021CEEB8
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
 *   func_021CF448 0x021CF448 thumb ov093
 *   func_021E9D04 0x021E9D04 thumb ov093
 *   func_021CE0BC 0x021CE0BC thumb ov093
 *   func_021E9E70 0x021E9E70 thumb ov093
 *   func_021E9E80 0x021E9E80 thumb ov093
 *   func_021EA01C 0x021EA01C thumb ov093
 *   func_021EA044 0x021EA044 thumb ov093
 *   func_021EA030 0x021EA030 thumb ov093
 *   func_021EA04C 0x021EA04C thumb ov093
 *   func_021CF430 0x021CF430 thumb ov093
 *   func_021D8358 0x021D8358 thumb ov093
 *   func_021EA058 0x021EA058 thumb ov093
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021CF37C 0x021CF37C thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 *   func_021CF220 0x021CF220 thumb ov093
 *   func_021CE4D0 0x021CE4D0 thumb ov093
 *   func_021CE3C8 0x021CE3C8 thumb ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B8670  0x021B8670  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 */
#include "../../matched/include/Obj00967.h"
#include "../../matched/include/Obj09993.h"

struct QV;
struct Q1;
struct S2;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { VALUE_ZERO, VALUE_ONE } Value;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u8 func_021CF448(u8 *);
extern void func_021E9D04(void *, int, int, int, u32, u32);
extern int func_021CE0BC(u8 *p, void *q);
extern void func_021E9E70(u8 *p);
extern int func_021E9E80(u8 *p);
extern u16 func_021EA01C(u8 *p);
extern u8 func_021EA044(struct QV *p);
extern u8 func_021EA030(u8 *p);
extern u8 func_021EA04C(u8 *p);
extern void func_021CF430(u8 *, u32, u32);
extern void func_021D8358(u32 *p, u32 id, u32 sub, u32 val);
extern void func_021EA058(char *p);
extern u32 func_021D805C(void *p, u32 n);
extern void func_021CF37C(u8 *, u32, u32);
extern void func_021CE150(u8 *p, void *q);
extern u32 func_021CF220(u8 *p, int *st);
extern int func_021CE4D0(u8 *p, u32 *st);
extern int func_021CE3C8(u8 *p, int *state);
extern void *func_021B86B8(void ***p);
extern char *func_021B9AF8(char *p, int i);
extern u8 func_021B9B94(struct Q1 *p);
extern unsigned int func_021B8670(unsigned int **p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *m);
extern int func_021D5C30(struct UtilWork *p);
u32 func_021CEEB8(u8 *p, int *st);
u32 func_021CEFFC(u8 *p);


static inline u8 same_index(u8 *p)
{
    return p[0x11d] == p[0x11f] ? 1 : 0;
}


/*
 * lever: u16 b/d retain the spilled reload and narrow only at the u8 call;
 *        enum same retains the early ternary truncation.
 */
u32 func_021CEEB8(u8 *p, int *st)
{
    u32 a, c, z;
    u16 b, d;
    Value same;
    u32 flag;
    switch (*st) {
    case 0:
        a = func_021CF448(p);
        same = same_index(p);
        flag = (u8)func_021CEFFC(p);
        func_021E9D04(((struct Obj00967 *)p)->f54, p[0x1aa], p[0x1ab], a, same, flag);
        ++*st;
        break;
    case 1:
        z = 0;
        if (func_021CE0BC(p, 0)) {
            func_021E9E70(((struct Obj00967 *)p)->f54);
            *st = 2;
            return z;
        }
        if (func_021E9E80(((struct Obj00967 *)p)->f54)) {
            a = func_021EA01C(((struct Obj00967 *)p)->f54);
            b = func_021EA044(((struct Obj00967 *)p)->f54);
            if (a && b != 6) {
                c = func_021EA030(((struct Obj00967 *)p)->f54);
                d = func_021EA04C(((struct Obj00967 *)p)->f54);
                if (p[0x1ab] >= c) p[0x1ab] = p[0x1ab] - c;
                else {
                    p[0x1ab] = z;
                    c = p[0x1ab];
                }
                func_021CF430(p, p[0x11d], c);
                func_021D8358(((struct Obj00967 *)p)->fC, a, (u8)b, (u8)d);
                func_021EA058(((struct Obj00967 *)p)->f54);
                if (func_021D805C((void *)a, 0xf) == 4) p[0x1b2] |= 4;
                func_021CF37C(p, p[0x11d], a);
                func_021CE150(p, (void *)((u32)func_021CF220));
            } else func_021CE150(p, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9E80(((struct Obj00967 *)p)->f54)) func_021CE150(p, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}


u32 func_021CEFFC(u8 *p)
{
    char *arr;
    u32 lim;
    u32 flag;
    u32 i;
    u32 c;
    u8 *w;
    u32 cnt;
    if (func_021B86B8(*(void *** *)&((struct Obj09993 *)p)->f0) == 0) {
        arr = func_021B9AF8(*(char * *)&((struct Obj09993 *)p)->f4, 1);
        cnt = func_021B9B94((struct Q1 *)arr);
        lim = func_021B8670((unsigned int **)(*(void *** *)&((struct Obj09993 *)p)->f0));
        if (lim > cnt) {
            lim = cnt;
        }
        flag = 0;
        c = 0;
        for (i = 0; i < lim; i++) {
            w = func_021B9C00((struct S2 *)arr, (u8)i);
            if (func_021D5B68(w) == 0) {
                c++;
                if (func_021D5C30((struct UtilWork *)w) != 0) {
                    flag = 1;
                }
            }
        }
        if (c == 1 && flag != 0) {
            return 1;
        }
    }
    return 0;
}
