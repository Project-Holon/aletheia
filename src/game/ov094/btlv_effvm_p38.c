/*
 * file:     btlv_effvm_p38.c
 * unit:     yes
 * function: func_021FB1C4, func_021FB214
 * address:  0x021FB1C4
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
 *   func_0201134C  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF470  0x021FF470  thumb  ov094
 *   func_021FF6B0  0x021FF6B0  thumb  ov094
 */
#include "../../matched/include/Obj00177.h"

struct Cursor;
typedef unsigned char u8;

typedef unsigned int   u32;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021FCA04(int b, int t, int *out);
extern int func_021F8694(void);
extern void func_021FF470(void *p, int key, u8 v);
extern void func_021FF6B0(void *p, int key, int a, int *arr, int b, int c, int d);
int func_021FB1C4(struct Cursor *a, char *b);
int func_021FB214(struct Cursor *a, char *b);


int func_021FB1C4(struct Cursor *a, char *b)
{
    int buf[8];
    int n;
    int i;
    int v;

    n = func_021FCA04((int)b, func_0201134C(a), buf);
    v = func_0201134C(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF470((void *)func_021F8694(), buf[i], v);
    }
    return ((struct Obj00177 *)b)->f23C;
}


int func_021FB214(struct Cursor *a, char *b)
{
    int arr[3];
    int buf[8];
    int n;
    int i;
    int t1, t4, t5, t6;

    n = func_021FCA04((int)b, func_0201134C(a), buf);
    t1 = func_0201134C(a);
    arr[0] = func_0201134C(a);
    arr[1] = func_0201134C(a);
    arr[2] = 0x1000;
    t4 = func_0201134C(a);
    t5 = func_0201134C(a);
    t6 = func_0201134C(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF6B0((void *)func_021F8694(), buf[i], t1, arr, t4, t5, t6);
    }
    return ((struct Obj00177 *)b)->f23C;
}
