/*
 * function: func_021FB790
 * address:  0x021FB790
 * packet:   pkt_ov094_021FB790
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_021F86F0  0x021F86F0  thumb  ov094
 *   func_02201CD0  0x02201CD0  thumb  ov094
 */
#include "../include/Obj21669.h"
typedef short s16;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_021F86F0(void);
extern void func_02201CD0(char *o, int idx, int c, s16 *p, int s1, int s2, int s3);

int func_021FB790(struct Cursor *a, char *b)
{
    s16 arr[2];
    int t0, t1, t3, t4, t5;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    arr[0] = VM_GetU32(a);
    arr[1] = VM_GetU32(a);
    t3 = VM_GetU32(a);
    t4 = VM_GetU32(a);
    t5 = VM_GetU32(a);
    func_02201CD0((char *)func_021F86F0(), *(int *)(b + t0 * 4 + 0xcc), t1, arr, t3, t4, t5);
    return ((struct Obj21669 *)b)->f23C;
}
