/*
 * function: func_021DFBAC
 * address:  0x021DFBAC
 * packet:   pkt_ov093_021DFBAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
#include "../../../matched/include/Obj13501.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021DFBAC(void *self, void *q, int id)
{
    u8 *r;

    if (id != func_021D775C(4))
        return;
    r = (u8 *)func_021C88A4(q, 0x20, id);
    r[6] = id;
    ((struct Obj13501 *)r)->f4 = 0;
    func_021C8838(r + 0xc, 2, 0x19b);
    func_021C8860((struct S *)(r + 0xc), id);
    func_021C88C8(q, r);
}
