/*
 * file:     unit_021E9728_p02.c
 * unit:     yes
 * function: func_021E97A4, func_021E97BC
 * address:  0x021E97A4
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
 *   func_021E9738  0x021E9738  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E97F8  0x021E97F8  thumb  ov093
 *   func_021E9728  0x021E9728  thumb  ov093
 *   func_021E9884  0x021E9884  thumb  ov093
 */
#include "../../matched/include/Obj21552.h"
#include "../../matched/include/Obj06280.h"

struct S;
struct QU;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021E9738(struct S *s);
extern u8 func_021D5440(u8 *p);
extern void func_021E97F8(void *a, u8 *b, int c);
extern void func_021E9728(struct QU *p, u32 v);
extern int func_021E9884(void *p);
int func_021E97A4(char *p);
void func_021E97BC(char *p, u8 *a, int b);


int func_021E97A4(char *p)
{
    if (func_021E9738((struct S *)p) != 0) {
        return ((struct Obj21552 *)p)->fC4;
    }
    return 0;
}


void func_021E97BC(char *p, u8 *a, int b)
{
    *(u8 * *)&((struct Obj06280 *)p)->fBC = a;
    ((struct Obj06280 *)p)->fC0 = func_021D5440(a);
    ((struct Obj06280 *)p)->fB8 = b;
    func_021E97F8(((struct Obj06280 *)p)->f180, *(u8 * *)&((struct Obj06280 *)p)->fBC, b);
    func_021E9728((struct QU *)p, (u32)func_021E9884);
}
