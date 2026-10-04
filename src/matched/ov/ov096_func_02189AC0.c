/*
 * function: func_02189AC0
 * address:  0x02189AC0
 * packet:   pkt_ov096_02189AC0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_020113B0  0x020113B0  thumb
 *   func_0218A308  0x0218A308  thumb  ov096
 *   func_0218A390  0x0218A390  thumb  ov096
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *
 * Lever: the second parameter is a struct pointer (see 02189B78).
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct { u8 p0[0x38]; int f38; u8 p1[0x58]; u8 f94; u8 p2[0x1b]; int fb0, fb4; char *fb8; u8 *fbc, *fc0; int fc4; } Obj;

extern int func_0201134C(int);
struct Cur;
extern void func_020113B0(struct Cur *c, u32 v);
extern u8 *func_0218A308(void *, u32);
extern u32 func_0218A390(int, u8 *, u8 *, int);
extern unsigned char func_021B8DE4(char *p, int i);
extern char *func_021B9AF8(char *p, int i);
extern int func_021B99B8(void *pp, unsigned int b);
struct Q1;
extern u8 func_021B9B94(struct Q1 *p);
extern u8 func_021D5440(u8 *p);
extern int func_021D5B68(void *);

int func_02189AC0(int a, Obj *b) {
    int c;
    int x;
    int r4;
    char *r7;
    u8 *r6;
    u32 base;
    c = func_0201134C(a);
    x = func_0201134C(a);
    r4 = func_021B8DE4((char *)b->fb0, b->f94);
    r7 = func_021B9AF8(b->fb8, r4);
    r4 = func_021B99B8((void *)b->fb0, r4);
    base = func_0218A390((int)b, b->fbc, b->fc0, c);
    for (; r4 < func_021B9B94((struct Q1 *)r7); r4++) {
        r6 = func_0218A308(r7, (u8)r4);
        func_021D5440(r6);
        if (func_021D5B68(r6) == 0) {
            if (func_0218A390((int)b, r6, b->fc0, c) > base) {
                func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + x);
                break;
            }
        }
    }
    return b->fc4;
}
