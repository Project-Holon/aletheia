/*
 * function: func_021FB214
 * address:  0x021FB214
 * packet:   pkt_ov094_021FB214
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF6B0  0x021FF6B0  thumb  ov094
 */
#include "../include/Obj00177.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_021FCA04(int b, int t, int *out);
extern int func_021F8694(void);
extern void func_021FF6B0(void *p, int key, int a, int *arr, int b, int c, int d);

int func_021FB214(struct Cursor *a, char *b)
{
    int arr[3];
    int buf[8];
    int n;
    int i;
    int t1, t4, t5, t6;

    n = func_021FCA04((int)b, VM_GetU32(a), buf);
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    arr[2] = 0x1000;
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    t6 = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF6B0((void *)func_021F8694(), buf[i], t1, arr, t4, t5, t6);
    }
    return ((struct Obj00177 *)b)->f23C;
}
