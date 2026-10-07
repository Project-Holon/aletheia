/*
 * function: func_021DE180
 * address:  0x021DE180
 * packet:   pkt_ov093_021DE180
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../../matched/include/Obj10068.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
struct QQ;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B68(void *p);
extern int func_021DCFF8(int a, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);

void func_021DE180(int a, void *b, int c, int *d)
{
    u8 *m;
    void *mon;
    u8 k;
    u8 j;

    if (c == func_021D775C(2) && *d != 0) {
        k = *d - 1;
        mon = func_021C7CF4(b, k);
        if (func_021D5B68(mon) == 0) {
            j = func_021DCFF8(a, 2);
            m = (u8 *)func_021C88A4(b, 7, c);
            m[6] = k;
            ((struct Obj10068 *)m)->f4 = func_021D7B74(mon, j);
            func_021C8838(m + 0xc, 2, 0x407);
            func_021C8860((struct S *)(m + 0xc), m[6]);
            func_021C8860((struct S *)(m + 0xc), c);
            func_021C8860((struct S *)(m + 0xc), func_021D70A8((void *)a));
            func_021C88C8(b, m);
        }
    }
}
