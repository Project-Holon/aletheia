/*
 * function: func_021DAF58
 * address:  0x021DAF58
 * packet:   pkt_ov093_021DAF58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DA8A8  0x021DA8A8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
#include "../../../matched/include/Obj13470.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021DA8A8(int a, int b, int c);
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021DAF58(int unused, void *a, int id)
{
    u8 *r;

    if (func_021DA8A8((int)a, id, 9) != 0) {
        func_021C88B4(a, 2, id);
        if (func_021D5BDC(func_021C7CF4(a, id), 13) == 0) {
            r = (u8 *)func_021C88A4(a, 4, id);
            func_021C8838(r + 4, 2, 0x1ab);
            func_021C8860((struct S *)(r + 4), id);
            func_021C88C8(a, r);
            r = (u8 *)func_021C88A4(a, 0x17, id);
            r[8] = id;
            ((struct Obj13470 *)r)->f4 = 13;
            func_021C88C8(a, r);
        } else {
            r = (u8 *)func_021C88A4(a, 4, id);
            func_021C8838(r + 4, 2, 0xd2);
            func_021C8860((struct S *)(r + 4), id);
            func_021C88C8(a, r);
        }
        func_021C88B4(a, 3, id);
    }
}
