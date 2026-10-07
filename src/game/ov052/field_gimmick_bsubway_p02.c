/*
 * file:     field_gimmick_bsubway_p02.c
 * unit:     yes
 * function: func_021F380C, func_021F3844
 * address:  0x021F380C
 * region:   ov052
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_021F3998 0x021F3998 thumb ov052
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   d_021F3AC0     0x021F3AC0  data  ov052  a4
 */
#include "../../matched/include/Obj13111.h"

struct Big;
struct Ctx;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u16 func_02188C9C(u8 *p);
extern char *func_0200B3A4(unsigned, int);
extern u16 func_02188C84(u8 *p);
extern void func_021F3998(int, int *, int *);
extern unsigned int func_02188CD0(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021ABE30(int, int *, int);
int func_021F380C(int a);
void func_021F3844(char *a, u8 *b);
extern char d_021F3AC0[];


int func_021F380C(int a)
{
    int y, x;
    unsigned h;
    func_02188C84((u8 *)a);
    h = (unsigned int)func_02012EC4(func_020120F4(func_02188C80((void *)a)));
    func_021F3998(func_02188C9C((u8 *)a), &x, &y);
    return **(int **)(func_0200B3A4(h, x) + 0x24);
}


void func_021F3844(char *a, u8 *b)
{
    int n;
    int r4 = func_02188CD0(b);

    ((struct Obj13111 *)a)->f24 = func_02030734(((struct Obj13111 *)a)->fC, 4, 1, d_021F3AC0, 0x112);
    n = 0xe;
    func_021ABE30(r4, &n, 1);
}
