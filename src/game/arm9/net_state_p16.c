/*
 * file:     net_state_p16.c
 * unit:     yes
 * function: func_020379C8, func_02037A44, func_02037A6C, func_02037B08
 * address:  0x020379C8
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
 *   func_0203D788   0x0203D788  arm
 *   func_0203D798   0x0203D798  arm
 *   func_02037858   0x02037858  arm
 *   func_02038924   0x02038924  arm
 *   func_02037288   0x02037288  arm
 *   g_020A7A20      0x020A7A20  data
 *   func_020307B0   0x020307B0  arm
 *   func_02036B88   0x02036B88  arm
 *   g_021469D0      0x021469D0  data
 */
#include "../../matched/include/Obj15930.h"
#include "../../matched/include/Obj06938.h"
#include "../../matched/include/Obj15931.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Struct_02037B08 {
    void *field_0;
    void *field_4;
    void *field_8;
    void *field_C;
    void *field_10;
    void *field_14;
    void *field_18;
    u8 pad[0xcc - 0x1c];
    char obj_CC;
    u8 pad2[0xf4 - 0xcd];
    char obj_F4;
};

extern void *func_0203D788(void);
extern char *func_0203D798(void);
extern void  func_02037858(u32 arg);
extern void  func_02038924(u32 arg);
extern int func_02037288(u32 a0, u32 heap, u32 c);
extern u32 func_020307B0(void *p);
extern void  func_02036B88(void *p);
int func_020379C8(u32 p);
void func_02037A44(int a);
void func_02037A6C(u32 a0, u32 a1, u16 a2, u32 a3);
void func_02037B08(void);
extern u8    g_020A7A20[];
extern struct Struct_02037B08 *g_021469D0;


/*
 * Context teardown through three vtable slots at +0x3c, +0xbc and +0x68 of the
 * object the context's word at +0x340 names.  The first and third are handed a
 * function address as their argument (0x02037858 and 0x02038924), which is why
 * the pool holds two code pointers; the +0xbc slot's answer decides whether the
 * rest runs, and the byte at +1 of the object at 0x020A7A20 is set to 4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020379C8.c \
 *       --func func_020379C8 --addr 0x020379C8 --cc 1.1p1 --arm
 */
int func_020379C8(u32 p)
{
    int   r;
    char *c = func_0203D788();

    (*(void (**)(u32))(*(char **)(c + 0x340) + 0x3C))((u32)func_02037858);
    r = (*(int (**)(void))(*(char **)(c + 0x340) + 0xBC))();
    if (r == 1) {
        (*(void (**)(u32))(*(char **)(c + 0x340) + 0x68))((u32)func_02038924);
        func_02037288(p, *(u16 *)(func_0203D798() + 0x56), 0);
        g_020A7A20[1] = 4;
    }
    return r;
}


void func_02037A44(int a)
{
    int *r = func_0203D788();
    int *t = *(int * *)&((struct Obj15930 *)r)->f340;
    if (t == 0)
        return;
    ((void (*)(int))t[0x30])(a);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037A6C.c \
 *       --func func_02037A6C --addr 0x02037A6C --cc 1.1p1 --arm
 */
void func_02037A6C(u32 a0, u32 a1, u16 a2, u32 a3)
{
    char *b = func_0203D788();
    char *a = func_0203D798();
    void (*f1)(void *);
    u32 flag;
    u16 val;
    void (*f2)(u32, u32, u32, u32, u32);

    f1 = *(void (**)(void *))(*(char * *)&((struct Obj06938 *)b)->f340 + 0x68);
    f1(func_02038924);

    if (a0 != 0) {
        if (((struct Obj06938 *)b)->f64 != 0 && ((struct Obj06938 *)b)->f6C != 0) {
            flag = 1;
        } else {
            flag = 0;
        }

        a = func_0203D798();
        val = ((struct Obj15931 *)a)->f56;
        func_02037288(a2, val, flag);

        g_020A7A20[1] = 4;
    }

    f2 = *(void (**)(u32, u32, u32, u32, u32))(*(char * *)&((struct Obj06938 *)b)->f340 + 0x48);
    f2(a0, a1, 0, 0, a3);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037B08.c \
 *       --func func_02037B08 --addr 0x02037B08 --cc 1.1p1 --arm
 */
void func_02037B08(void)
{
    func_0203D788();
    func_0203D798();

    if (g_021469D0 == 0) {
        return;
    }

    func_020307B0(g_021469D0->field_14);
    func_020307B0(g_021469D0->field_18);
    func_020307B0(g_021469D0->field_10);

    func_02036B88(&g_021469D0->obj_F4);
    func_02036B88(&g_021469D0->obj_CC);

    func_020307B0(g_021469D0->field_0);
    func_020307B0(g_021469D0->field_4);
    func_020307B0(g_021469D0->field_8);
    func_020307B0(g_021469D0->field_C);

    func_020307B0(g_021469D0);

    g_021469D0 = 0;
}
