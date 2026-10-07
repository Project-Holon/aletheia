/*
 * file:     field_msgbg_p16.c
 * unit:     yes
 * function: func_0218BDD8, func_0218BE84, func_0218BEE8, func_0218BF84
 * address:  0x0218BDD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0218BFB4  0x0218BFB4  thumb  ov021
 *   d_021DD9CC     0x021DD9CC  data  ov021  a1
 *   func_020307B0  0x020307B0  arm
 *   func_0218C0D8  0x0218C0D8  thumb  ov021
 *   func_02046C94  0x02046C94  arm
 *   func_02046CE0  0x02046CE0  arm
 *   func_0218B924  0x0218B924  thumb  ov021
 *   func_0218BC00  0x0218BC00  thumb  ov021
 *   func_0218BC10  0x0218BC10  thumb  ov021
 *   func_0218BC8C  0x0218BC8C  thumb  ov021
 *   func_0218BCAC  0x0218BCAC  thumb  ov021
 */
#include "../../matched/include/Obj00572.h"
#include "../../matched/include/Obj07411.h"
#include "../../matched/include/Obj01114.h"
#include "../../matched/include/Obj04986.h"
#include "../../matched/include/Obj09454.h"

struct S02046CE0;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int f0;
    void *f4;
    void *arr[4];
} S;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0218BFB4(u8 *a, u32 *out, u32 *st);
extern u32 func_020307B0(void *p);
extern void func_0218C0D8(void **s);
extern int func_02046C94(void);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);
extern int func_0218B924(u8 *p, u32 a1);
extern char *func_0218BC00(char *p, int i);
extern u8 *func_0218BC10(u8 *p, int i);
extern int func_0218BC8C(int *p);
extern u8 *func_0218BCAC(u8 *p);
void func_0218BDD8(u8 *s, u32 *out);
void func_0218BE84(u8 *s, u8 *e);
void func_0218BEE8(u8 *s, void **out, int x);
void func_0218BF84(S *p);
extern char d_021DD9CC[];


void func_0218BDD8(u8 *s, u32 *out)
{
    u32 n;
    u32 i;

    n = ((struct Obj00572 *)s)->f1AC;
    if (n != 0) {
        out[1] = n;
        out[0] = (u32)func_02030734(((struct Obj00572 *)s)->f0, n << 3, 1, d_021DD9CC, 0x490);
        ((struct Obj00572 *)s)->f1D4 = n;
        *(u32 *)&((struct Obj00572 *)s)->f1D8 = (u32)func_02030734(((struct Obj00572 *)s)->f0, n * 0x18, 1, d_021DD9CC, 0x494);
        for (i = 0; i < ((struct Obj00572 *)s)->f1D4; i++) {
            u8 *a = *(u8 * *)&((struct Obj00572 *)s)->f1D8;
            u8 *b = *(u8 * *)&((struct Obj00572 *)s)->f1CC;
            func_0218BFB4(s, (u32 *)(a + i * 0x18), (u32 *)(b + i * 0x18));
            *(u32 *)(*(u8 * *)&((struct Obj07411 *)out)->f0 + i * 8) = *(u32 *)(a + i * 0x18);
            *(u32 *)(*(u8 * *)&((struct Obj07411 *)out)->f0 + i * 8 + 4) = 0;
        }
    }
}


void func_0218BE84(u8 *s, u8 *e)
{
    u32 i;

    if (((struct Obj04986 *)e)->f0 != 0) {
        func_020307B0(((struct Obj04986 *)e)->f0);
        ((struct Obj04986 *)e)->f0 = 0;
    }
    if (((struct Obj04986 *)e)->f8 != 0) {
        func_020307B0(((struct Obj04986 *)e)->f8);
        ((struct Obj04986 *)e)->f8 = 0;
    }
    if (*(u8 * *)&((struct Obj01114 *)s)->f1D8 != 0) {
        for (i = 0; i < ((struct Obj01114 *)s)->f1D4; i++)
            func_0218C0D8((void **)(*(u8 * *)&((struct Obj01114 *)s)->f1D8 + i * 0x18));
        func_020307B0(*(u8 * *)&((struct Obj01114 *)s)->f1D8);
        ((struct Obj01114 *)s)->f1D4 = 0;
        *(u8 * *)&((struct Obj01114 *)s)->f1D8 = 0;
    }
}


void func_0218BEE8(u8 *s, void **out, int x)
{
    u8 *t;
    int cnt;
    int i;

    out[0] = (void *)func_0218B924(s, x);
    out[1] = func_02030734(((struct Obj09454 *)s)->f0, func_02046C94(), 1, d_021DD9CC, 0x4d0);
    func_02046CE0(out[1], (u32 *)func_0218BC00(((struct Obj09454 *)s)->f18, x));
    t = func_0218BCAC(out[0]);
    cnt = func_0218BC8C((int *)t);
    for (i = 0; i < 4; i++) {
        if (i < cnt) {
            out[2 + i] = func_02030734(((struct Obj09454 *)s)->f0, func_02046C94(), 1, d_021DD9CC, 0x4db);
            func_02046CE0(out[2 + i], (u32 *)func_0218BC10(t, i));
        } else {
            out[2 + i] = 0;
        }
    }
}


void func_0218BF84(S *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p->arr[i] != 0) {
            func_020307B0(p->arr[i]);
            p->arr[i] = 0;
        }
    }
    if (p->f4 != 0) {
        func_020307B0(p->f4);
        p->f4 = 0;
    }
}
