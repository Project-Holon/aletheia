/*
 * file:     unit_021E98AC.c
 * unit:     yes
 * function: func_021E98AC, func_021E98B4, func_021E98BC, func_021E98E8
 * address:  0x021E98AC
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
 *   func_0689B0CC  0x0689B0CC  thumb
 *   func_021E9928 0x021E9928 thumb ov093
 *   func_021E9738 0x021E9738 thumb ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E9728  0x021E9728  thumb  ov093
 *   func_021E96C4  0x021E96C4  thumb  ov093
 */
#include "../../matched/include/Obj10105.h"
#include "../../matched/include/Obj21555.h"

struct S;
struct QU;
typedef unsigned int u32;

typedef unsigned char u8;

extern void func_021E9928(char *p);
extern int func_021E9738(struct S *s);
extern u8 func_021D5440(u8 *p);
extern void func_021E9728(struct QU *p, u32 v);
extern int func_021E96C4(char *p, int *st);
extern int func_0689B0CC(void *p);
void func_021E98AC(void *p);
u32 func_021E98B4(void *p);
void func_021E98BC(char *p, u8 *a, int b);
int func_021E98E8(char *p);

/*
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * interface: eight-byte ldr-r3/bx-r3 stub forwards only live r0;
 * target body reads only r0. Original caller does not read result.
 */
void func_021E98AC(void *p)
{
    func_021E9928(p);
}

/*
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * interface: eight-byte ldr-r3/bx-r3 stub forwards only live r0;
 * target body reads only r0. Original caller compares returned r0 with zero.
 */
u32 func_021E98B4(void *p)
{
    return func_021E9738(p);
}


void func_021E98BC(char *p, u8 *a, int b)
{
    *(u8 * *)&((struct Obj10105 *)p)->fBC = a;
    ((struct Obj10105 *)p)->fC0 = func_021D5440(a);
    ((struct Obj10105 *)p)->fB8 = b;
    func_021E9728((struct QU *)p, (u32)func_021E96C4);
}


int func_021E98E8(char *p)
{
    if (func_021E9738((struct S *)p) != 0) {
        if (func_0689B0CC(((struct Obj21555 *)p)->f180) != 0) {
            return 1;
        }
        return 2;
    }
    return 0;
}
