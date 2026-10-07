/*
 * file:     fieldmap_func_p01.c
 * unit:     yes
 * function: func_021BB578, func_021BB5C8, func_021BB5DC
 * address:  0x021BB578
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
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_021BB778  0x021BB778  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9A90     0x021D9A90  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 */
#include "../../matched/include/Obj18172.h"

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    int w[7];
} Blk;

typedef struct {
    Blk b;
    char pad[0x10];
    int f2C;
} Out;

int func_021ABEA0(u32 a, u32 b);
int func_0216E1A4(int a0, int a1);
u32 func_021ABE14(u8 *p);
void func_021BB778(int n);
void func_021ABFA8(int a, void *b, int c, int d, void *e, int f);
extern int func_021AC1E0(u32 a);
extern Blk *func_021AC1AC(int a);
extern void func_021AC178(int a);
void func_021BB578(int a, int b, int c, int d);
int func_021BB5C8(u32 a);
void func_021BB5DC(int a, Out *out);
extern int d_021D9A90;


void func_021BB578(int a, int b, int c, int d)
{
    int s[7];

    s[0] = c;
    s[1] = d;
    s[2] = func_021ABEA0(a, 4);
    s[3] = b;
    func_0216E1A4(b, (int)(&s[4]));
    s[6] = func_021ABE14((u8 *)a);
    if (d == 1) {
        func_021BB778(c);
    }
    func_021ABFA8(a, &d_021D9A90, 0, 0, s, 0);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BB5C8(u32 a)
{
if (a != 0) {
    return ((struct Obj18172 *)((u8 *)(func_021AC1E0(a))))->f24;
}
return 1;
}


void func_021BB5DC(int a, Out *out)
{
    out->b = *func_021AC1AC(a);
    out->f2C = 0x6000;
    func_021AC178(a);
}
