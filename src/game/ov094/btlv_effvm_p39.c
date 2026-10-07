/*
 * file:     btlv_effvm_p39.c
 * unit:     yes
 * function: func_021FB298, func_021FB2D0, func_021FB328, func_021FB390
 * address:  0x021FB298
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FCA04 0x021FCA04 thumb ov094
 *   func_021F7F04 0x021F7F04 thumb ov094
 *   func_021FCF2C  0x021FCF2C  thumb  ov094
 *   func_021F7F58  0x021F7F58  thumb  ov094
 *   func_021F84D0  0x021F84D0  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF4C0  0x021FF4C0  thumb  ov094
 *   func_0220041C 0x0220041C thumb ov094
 *   func_02200468 0x02200468 thumb ov094
 */
#include "../../matched/include/Obj00177.h"
#include "../../matched/include/Obj13586.h"
#include "../../matched/include/Obj21660.h"
#include "../../matched/include/Obj21661.h"

struct Cursor;
typedef unsigned int   u32;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021FCA04(char *, int, int *);
extern void func_021F7F04(int);
extern int func_021FCF2C(int a, int b);
extern void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e);
extern int func_021F84D0(int a);
extern int func_021F8694(void);
extern void func_021FF4C0(void *obj, int a, int b, int *c, int d, int e, int f);
extern int func_0220041C(void *, int, int);
extern void func_02200468(void *, int);
int func_021FB298(void *a, char *s);
int func_021FB2D0(struct Cursor *a, char *b);
int func_021FB328(struct Cursor *a, char *b);
int func_021FB390(void *a, char *s);


/*
 * Script command: runs func_021F7F04 on each id listed by func_021FCA04.
 */
int func_021FB298(void *a, char *s)
{
    int ids[8];
    int n;
    int i;

    n = func_021FCA04(s, func_0201134C(a), ids);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021F7F04(ids[i]);
    }
    return ((struct Obj00177 *)s)->f23C;
}


int func_021FB2D0(struct Cursor *a, char *b)
{
    int t0, t1, t2, t3, t4;

    t0 = func_0201134C(a);
    t1 = func_021FCF2C((int)a, func_0201134C(a));
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    t4 = func_0201134C(a);
    if (t0 == -1)
        t0 = ((struct Obj13586 *)b)->f4;
    func_021F7F58(t0, t1, t2, t3, t4);
    return ((struct Obj13586 *)b)->f23C;
}


int func_021FB328(struct Cursor *a, char *b)
{
    int arr[3];
    int t1;
    int t0;
    int t5, t6, t7;

    t0 = func_021F84D0(func_0201134C(a));
    t1 = func_0201134C(a);
    arr[0] = func_0201134C(a);
    arr[1] = func_0201134C(a);
    arr[2] = func_0201134C(a);
    t5 = func_0201134C(a);
    t6 = func_0201134C(a);
    t7 = func_0201134C(a);
    func_021FF4C0((void *)func_021F8694(), t0, t1, arr, t5, t6, t7);
    return ((struct Obj21660 *)b)->f23C;
}


/*
 * Script command: when func_0220041C(x, y) reports 1, calls func_02200468(x).
 */
int func_021FB390(void *a, char *s)
{
    int x = func_0201134C(a);
    int y = func_0201134C(a);

    if (func_0220041C((void *)func_021F8694(), x, y) == 1)
        func_02200468((void *)func_021F8694(), x);
    return ((struct Obj21661 *)s)->f23C;
}
