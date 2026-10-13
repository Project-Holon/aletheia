/*
 * function: func_021FB328
 * address:  0x021FB328
 * packet:   pkt_ov094_021FB328
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021F84D0  0x021F84D0  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF4C0  0x021FF4C0  thumb  ov094
 */
#include "../include/Obj21660.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_021F84D0(int a);
extern int func_021F8694(void);
extern void func_021FF4C0(void *obj, int a, int b, int *c, int d, int e, int f);

int func_021FB328(struct Cursor *a, char *b)
{
    int arr[3];
    int t1;
    int t0;
    int t5, t6, t7;

    t0 = func_021F84D0(VM_GetU32(a));
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    arr[2] = VM_GetU32(a);
    t5 = VM_GetU32(a);
    t6 = VM_GetU32(a);
    t7 = VM_GetU32(a);
    func_021FF4C0((void *)func_021F8694(), t0, t1, arr, t5, t6, t7);
    return ((struct Obj21660 *)b)->f23C;
}
