/*
 * file:     gtsnego_disp_p13.c
 * unit:     yes
 * function: func_021D588C, func_021D593C, func_021D596C
 * address:  0x021D588C
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D70F0 0x021D70F0 thumb ov120
 *   func_0200F800 0x0200F800 thumb
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D7D6C 0x021D7D6C thumb ov120
 *   func_021D4C98 0x021D4C98 thumb ov120
 *   func_021D42D8 0x021D42D8 thumb ov120
 *   func_02012934 0x02012934 thumb
 *   func_0201AA1C 0x0201AA1C thumb
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_02040588 0x02040588 arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5AD4 0x021D5AD4 thumb ov120
 *   func_021D6A9C 0x021D6A9C thumb ov120
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B64D0 0x021B64D0 thumb ov067
 *   func_021D6AC0  0x021D6AC0  thumb
 */
#include "../../matched/include/Obj01729.h"
#include "../../matched/include/Obj13933.h"
#include "../../matched/include/Obj22832.h"

struct BigObj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

extern void func_021D70F0(void *);
extern void func_0200F800(void);
extern u8 func_020355C4(void);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_021D7D6C(char *p, int a, int b);
extern void func_021D4C98(void *p, int n, u8 *s);
extern int func_021D42D8(int n, u8 *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA1C(void *);
extern void func_021D79F4(u8 *p, u16 n);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D5AD4(u8 *p);
extern int func_021D6A9C(u8 *p, u32 n);
extern u8 *func_021D6988(void *);
extern void func_021B64D0(u8 *,u32);
extern void func_020061E4(int);
extern int func_021D6AC0(u8 *p);
void func_021D588C(u8 *p);
int func_021D593C(u8 *p,int n);
int func_021D596C(u8 *p, int x);

void func_021D588C(u8 *p)
{
    func_021D70F0(((struct Obj01729 *)p)->f3C);
    if (((struct Obj01729 *)p)->f1B0) {
        if ((((struct Obj01729 *)p)->f1B4)++ < 3)
            return;
        func_0200F800();
        ((struct Obj01729 *)p)->f1B0 = 0;
    }
    if (func_020355C4() == 0)
        func_021D69F4(((struct Obj01729 *)p)->f3C, 0, ((struct Obj01729 *)p)->f15C);
    else
        func_021D69F4(((struct Obj01729 *)p)->f3C, 0, 9);
    func_021D7D6C(((struct Obj01729 *)p)->f40, (int)func_021D4C98, (int)p);
    *(void (**)(void))(p + 4) = (void (*)(void))func_021D42D8;
    if ((int)func_0201AA1C(func_02012934(((struct Obj01729 *)p)->f2C)) < 2)
        ((struct Obj01729 *)p)->f184 = 1;
    if (((struct Obj01729 *)p)->f184 == 0)
        func_021D79F4(((struct Obj01729 *)p)->f40, 0x20);
    else
        func_021D79F4(((struct Obj01729 *)p)->f40, 0x2b);
    func_02040588(4, 1);
    func_02040588(6, 1);
    func_021D4244((int *)p, (int)func_021D5AD4, 0x86c);
}

int func_021D593C(u8 *p,int n) { if (func_021D6A9C(((struct Obj13933 *)p)->f3C,n)) { func_021B64D0(func_021D6988(((struct Obj13933 *)p)->f3C),0); func_020061E4(1356); return n; } return 9; }


/*
 * Addresses are Black-image addresses.
 */
int func_021D596C(u8 *p, int x)
{
    if (func_021D6AC0(((struct Obj22832 *)p)->f3C) == 0)
        x = 9;
    return x;
}
