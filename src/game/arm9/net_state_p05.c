/*
 * file:     net_state_p05.c
 * unit:     yes
 * function: func_020377B8, func_0203781C, func_02037858, func_02037894, func_02037928
 * address:  0x020377B8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D798   0x0203D798  arm
 *   func_0203D788   0x0203D788  arm
 *   func_02037288   0x02037288  arm
 *   func_02037680   0x02037680  arm
 *   func_020377AC   0x020377AC  arm
 *   func_020387A0   0x020387A0  arm
 *   func_02038924   0x02038924  arm
 *   g_020A7A20      0x020A7A20  data
 */
#include "../../matched/include/Obj11351.h"
#include "../../matched/include/Obj15917.h"
#include "../../matched/include/Obj15920.h"
#include "../../matched/include/Obj15922.h"
#include "../../matched/include/Obj05734.h"
#include "../../matched/include/Obj11352.h"
#include "../../matched/include/Obj05735.h"
#include "../../matched/include/Obj15929.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern int func_02037288(u32 a0, u32 heap, u32 c);
extern void func_02037680(int i);
extern void  func_020377AC(void);
extern int func_020387A0(u32 i, u8 *p, s32 n);
extern void  func_02038924(void);
u32 func_020377B8(u8 arg0);
void func_0203781C(u32 arg);
void func_02037858(u32 arg);
void func_02037894(u8 a0, u16 a1, u32 a2, u32 a3);
u32 func_02037928(u32 a0, u16 a1);
extern u8 g_020A7A20[];



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020377B8.c \
 *       --func func_020377B8 --addr 0x020377B8 --cc 1.1p1 --arm
 */
u32 func_020377B8(u8 arg0)
{
    u32 zero;
    char *a = func_0203D798();
    char *b = func_0203D788();
    u16 val;
    void (*f)(void *);

    ((struct Obj11351 *)a)->f66 = arg0;
    f = *(void (**)(void *))(*(char * *)&((struct Obj15917 *)b)->f340 + 0x68);
    f(func_020377AC);

    zero = 0;
    val = ((struct Obj11351 *)a)->f56;
    func_02037288(0x80, val, zero);

    func_02037680(zero);
    func_02037680(1);
    func_02037680(2);

    return 1;
}



/*
 * Reset-and-notify hook: two context getters, the per-slot reset for `arg`,
 * and then the hook at +8 of the first context if it is installed, called with
 * the first context's word at +0x34C and the incoming argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203781C.c \
 *       --func func_0203781C --addr 0x0203781C --cc 1.1p1 --arm
 */
void func_0203781C(u32 arg)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(arg);

    hook = *(void (**)(u32, u32))(a + 8);
    if (hook == 0)
        return;
    hook(((struct Obj15920 *)b)->f34C, arg);
}



/*
 * Byte-for-byte twin of func_0203781C (same 60 bytes, same call order): two
 * context getters, the per-slot reset for `arg`, then the hook at +8 of the
 * first context when it is installed, called with the first context's word at
 * +0x34C and the argument.  Two copies of the same 60 bytes exist in the image
 * and this is the second, so the pair also demonstrates that the listing's
 * duplicate-glue pattern is real code and not one function reached twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037858.c \
 *       --func func_02037858 --addr 0x02037858 --cc 1.1p1 --arm
 */
void func_02037858(u32 arg)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(arg);

    hook = *(void (**)(u32, u32))(a + 8);
    if (hook == 0)
        return;
    hook(((struct Obj15922 *)b)->f34C, arg);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037894.c \
 *       --func func_02037894 --addr 0x02037894 --cc 1.1p1 --arm
 */
void func_02037894(u8 a0, u16 a1, u32 a2, u32 a3)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    u32 flag;
    u16 val;
    void (*f1)(void *);
    void (*f2)(void *);
    void (*f3)(u32, u32);

    ((struct Obj11352 *)a)->f66 = a0;

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x3C);
    f1(func_0203781C);

    f2 = *(void (**)(void *))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x68);
    f2(func_020387A0);

    if (((struct Obj05734 *)b)->f64 != 0 && ((struct Obj05734 *)b)->f6C != 0) {
        flag = 1;
    } else {
        flag = 0;
    }

    a = func_0203D798();
    val = ((struct Obj11352 *)a)->f56;
    func_02037288(a1, val, flag);

    f3 = *(void (**)(u32, u32))(*(char * *)&((struct Obj05734 *)b)->f340 + 0x40);
    f3(a2, a3);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037928.c \
 *       --func func_02037928 --addr 0x02037928 --cc 1.1p1 --arm
 */
u32 func_02037928(u32 a0, u16 a1)
{
    char *b = func_0203D788();
    void (*f1)(void *);
    u32 (*f2)(u32, u32);
    void (*f3)(void *);
    u32 res;
    u32 flag;
    char *a;
    u16 val;

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x3C);
    f1(func_02037858);

    f2 = *(u32 (**)(u32, u32))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x44);
    res = f2(a0, 0);

    if (res == 1) {
        f3 = *(void (**)(void *))(*(char * *)&((struct Obj05735 *)b)->f340 + 0x68);
        f3(func_02038924);

        if (((struct Obj05735 *)b)->f64 != 0 && ((struct Obj05735 *)b)->f6C != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = ((struct Obj15929 *)a)->f56;
        func_02037288(a1, val, flag);

        g_020A7A20[1] = 4;
    }

    return res;
}
