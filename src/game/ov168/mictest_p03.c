/*
 * file:     mictest_p03.c
 * unit:     yes
 * function: func_0218441C, func_02184470, func_0218448C
 * address:  0x0218441C
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02006D64   0x02006D64  thumb
 *   func_02006D94   0x02006D94  thumb
 *   func_0208B500  0x0208B500  arm
 *   func_0208B528  0x0208B528  arm
 */
#include "../../matched/include/Obj10643.h"
#include "../../matched/include/Obj23823.h"

typedef unsigned int   u32;

extern void func_02006D64(u32 n);
extern u32 func_02006D94(void);
extern void func_0208B500(int *);
extern int func_0208B528(void);
void func_0218441C(int *p);
void func_02184470(int *p);
void func_0218448C(int *p);


/*
 * Latch the polled flag into p[0x34], arming and disarming the p[0x2c]
 *   work item while p[0x30] tracks the busy state.
 */
void func_0218441C(int *p)
{
    int x;
    int y;
    func_02006D64(1);
    x = func_02006D94();
    if (x != 0 && p[13] != 0)
        goto end;
    if (p[12] == 0) {
        if (p[10] != 0) {
            func_0218448C(p);
            p[11] = 1;
        }
        p[12] = 1;
    }
    if (x == 0)
        goto end;
    if (p[13] != 0)
        goto end;
    y = p[11];
    p[12] = 0;
    if (y != 0) {
        func_02184470(p);
        p[11] = 0;
    }
end:
    p[13] = x;
}


void func_02184470(int *p)
{
    if (((struct Obj10643 *)p)->f30 == 0) {
        func_0208B500(p);
        ((struct Obj10643 *)p)->f28 = 1;
    } else {
        ((struct Obj10643 *)p)->f2C = 1;
    }
}


void func_0218448C(int *p)
{
    func_0208B528();
    ((struct Obj23823 *)p)->f28 = 0;
}
