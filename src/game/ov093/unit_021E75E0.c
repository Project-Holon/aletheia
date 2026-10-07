/*
 * file:     unit_021E75E0.c
 * unit:     yes
 * function: func_021E75E0, func_021E7634, func_021E7760, func_021E781C
 * address:  0x021E75E0
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F28B8     0x021F28B8  data   ov093  a4
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C8374 0x021C8374 thumb ov093
 *   func_021C8234 0x021C8234 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021E89C0 0x021E89C0 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   d_021F274C 0x021F274C data a4
 *   d_021F2714     0x021F2714  data   ov093  a4
 *   func_021D57FC   0x021D57FC  thumb ov093
 */
#include "../../matched/include/Obj13543.h"
#include "../../matched/include/Obj02139.h"
#include "../../matched/include/Obj00663.h"
#include "../../matched/include/Obj07237.h"

struct QQ;
struct Unk021D62A8;
struct UtilWork;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
extern void *func_021C7CF4(int *p, int i);
extern int func_021C8374(u8 *p, int i);
extern int func_021C8234(u8 *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern Word func_021E89C0(u32);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *, u32);
u16 func_021D57FC(void *p);
void func_021E75E0(int a, int b, int c);
int *func_021E7628(int *p);
void func_021E7634(int a, int b, int c);
int *func_021E7754(int *p);
void func_021E7760(int a, int b, int c);
int *func_021E7810(int *p);
void func_021E781C(void *a, int b, int c);
extern int d_021F28B8[];
extern int d_021F274C[];
extern int d_021F2714[];


void func_021E75E0(int a, int b, int c)
{
    u8 *p;
    int k, r;

    if (c == func_021D775C(3)) {
        p = func_021C88A4((char *)b, 0x2e, c);
        p[6] = func_021D775C(6);
        r = func_021D70A8((void *)a);
        k = 0x1fd;
        if (r == k)
            k += 0x8e;
        else
            k += 0x8f;
        ((struct Obj13543 *)p)->f4 = k;
        func_021C88C8((void *)b, p);
    }
}


/*
 * The call result is bound to `r` before `k = 0x1fd`: with the constant
 * assigned first it is hoisted above the call into a callee-saved register.
 */
int *func_021E7628(int *p)
{
    *p = 2;
    return d_021F28B8;
}

/*
 * lever: func_021E89C0 returns a one-word aggregate, reserving its frame temporary.
 */
void func_021E7634(int a, int b, int c)
{
    u8 k;
    void *x;
    int flag;
    u8 *p;
    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        x = func_021C7CF4((int *)b, k);
        flag = 0;
        if (func_021C8374((u8 *)b, k) == 0) {
            if (func_021C8234((u8 *)b, k) != 0 && func_021D62C4(x, 0x21) == 0) {
                p = func_021C88A4((char *)b, 12, c);
                p[15] = k;
                ((struct Obj02139 *)p)->f4 = 0x1f;
                *(Word *)(p + 8) = func_021E89C0(0x1f);
                func_021C8838(p + 20, 2, 0x468);
                func_021C8860((struct S *)(p + 20), k);
                func_021C88C8((void *)b, p);
                flag = 1;
                if (func_021D62C4(x, 0x1e) != 0) {
                    p = func_021C88A4((char *)b, 11, c);
                    p[20] = 1;
                    p[8] = k;
                    p[21] = 1;
                    ((struct Obj02139 *)p)->f4 = 0x1e;
                    func_021C88C8((void *)b, p);
                }
                if (func_021D62C4(x, 0x20) != 0) {
                    p = func_021C88A4((char *)b, 11, c);
                    p[20] = 1;
                    p[8] = k;
                    p[21] = 1;
                    ((struct Obj02139 *)p)->f4 = 0x20;
                    func_021C88C8((void *)b, p);
                }
            }
            if (func_021D5BDC(x, 3) != 0) {
                p = func_021C88A4((char *)b, 0x36, c);
                p[4] = k;
                *(int *)(p + 8) = 3;
                if (flag == 0) {
                    func_021C8838(p + 12, 2, 0x468);
                    func_021C8860((struct S *)(p + 12), k);
                }
                func_021C88C8((void *)b, p);
            }
        }
    }
}


int *func_021E7754(int *p)
{
    *p = 1;
    return d_021F274C;
}


void func_021E7760(int a, int b, int c)
{
    u8 *p;

    if (c == func_021D775C(3)) {
        p = func_021C88A4((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 2;
        ((struct Obj00663 *)p)->fC = -1;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8((void *)b, p);
        p = func_021C88A4((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 4;
        ((struct Obj00663 *)p)->fC = -1;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8((void *)b, p);
        p = func_021C88A4((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 1;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8((void *)b, p);
        p = func_021C88A4((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 3;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8((void *)b, p);
        p = func_021C88A4((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 5;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8((void *)b, p);
    }
}


int *func_021E7810(int *p)
{
    *p = 1;
    return d_021F2714;
}


/*
 * Gate on func_021D775C(3); the (u8) of func_021D775C(6) keys func_021C7CF4,
 * whose result is halfword-stored through func_021D57FC in record #0x14.  A
 * second record #4 gets the 4<<22 flag in its header word and the two-string
 * tail (c and the key).
 */
void func_021E781C(void *a, int b, int c)
{
    u8 k;
    void *r;
    u8 *p;

    if (c != func_021D775C(3))
        return;
    k = (u8)func_021D775C(6);
    r = func_021C7CF4((int *)b, k);
    p = func_021C88A4((char *)b, 0x14, c);
    ((struct Obj07237 *)p)->f6 = c;
    ((struct Obj07237 *)p)->f4 = func_021D57FC(r);
    ((struct Obj07237 *)p)->f7 = 1;
    func_021C88C8((void *)b, p);
    p = func_021C88A4((char *)b, 4, c);
    ((struct Obj07237 *)p)->f0 |= 4 << 22;
    func_021C8838(p + 4, 2, 0x441);
    func_021C8860((struct S *)(p + 4), c);
    func_021C8860((struct S *)(p + 4), k);
    func_021C88C8((void *)b, p);
}
