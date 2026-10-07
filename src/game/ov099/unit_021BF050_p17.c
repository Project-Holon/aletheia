/*
 * file:     unit_021BF050_p17.c
 * unit:     yes
 * function: func_021C15FC, func_021C1614, func_021C1634, func_021C169C
 * address:  0x021C15FC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BA928  0x021BA928  thumb  ov099
 *   func_021BA828  0x021BA828  thumb  ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CD98 0x0203CD98 arm
 */
#include "../../matched/include/Obj18279.h"
#include "../../matched/include/Obj00008.h"

struct Sub020097BCObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C15FC;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021C1614;

typedef unsigned int   u32_021C1634;

extern void func_021BA8EC(char *p);
extern int func_021BA928(void *p, int v);
extern void func_021BA828(char *p);
extern u32_021C1634 func_021BA858(char *p);
extern void func_021BAAB8(char *, int, int);
extern void func_021C2408(char *);
extern int func_0203CEAC(int a0);
extern int func_0203CD98(void);
extern void func_02009B3C(struct Sub020097BCObj *obj);
int func_021C15FC(char *p, int v);
int func_021C1614(char *p, int v);
int func_021C1634(char *p, int ret);
int func_021C169C(char *p, int ret);


/*
 * Runs the setup for selector 0x0B and stamps it 0x1CC bytes in.
 */
int func_021C15FC(char *p, int v)
{
    func_021BA8EC(p);
    ((struct Obj18279 *)p)->f1CC = 0x0B;
    return v;
}


/*
 * Runs the setup and stamps selector 0x32 when the guard answers true.
 */
int func_021C1614(char *p, int v)
{
    if (func_021BA928(p, v) != 0) {
        func_021BA828(p);
        *(u32_021C1614 *)&((struct Obj00008 *)p)->f1CC = 0x32;
    }

    return v;
}

int func_021C1634(char *p, int ret)
{
    int choice;
    if (func_021BA928(p, ret) == 0) return ret;
    choice = func_021BA858(p);
    if (choice == -1) return ret;
    if (choice == 0) {
        *(int *)&((struct Obj00008 *)p)->f108 = 0;
        func_021BAAB8(p, 26, 1);
        ((struct Obj00008 *)p)->f1CC = 51;
        ((struct Obj00008 *)p)->f1E0 = 1;
    } else {
        *(int *)&((struct Obj00008 *)p)->f108 = 0;
        func_021BA8EC(p);
        ((struct Obj00008 *)p)->f1CC = 11;
        func_021C2408(p);
    }
    return ret;
}

/*
 * follower: two zero alignment bytes at 0x021C16EA.
 * lever: func_0203CEAC receives the live zero in r0.
 */
int func_021C169C(char *p, int ret)
{
    if (func_021BA928(p, ret) == 0) return ret;
    if (((struct Obj00008 *)p)->f1E0 == 1) {
        ((struct Obj00008 *)p)->f1E0 = 0;
        func_0203CEAC(0);
    }
    if (func_0203CD98() == 0) {
        func_02009B3C(((struct Obj00008 *)p)->f4);
        func_021BAAB8(p, 27, 1);
        ((struct Obj00008 *)p)->f1CC = 52;
        ((struct Obj00008 *)p)->f1E0 = 30;
    }
    return ret;
}
