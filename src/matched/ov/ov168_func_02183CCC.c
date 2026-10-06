/*
 * function: func_02183CCC
 * address:  0x02183CCC
 * packet:   pkt_02183CCC
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02183D40   0x02183D40  thumb
 *   func_02183D1C   0x02183D1C  thumb
 *   func_02183FA0   0x02183FA0  thumb
 *   func_021841F4   0x021841F4  thumb
 *   func_0218441C   0x0218441C  thumb
 *   func_02030D28   0x02030D28  arm
 *
 * Gate on p+0x130, then run the four init/teardown helpers and the
 *   word at p+0x144 through func_02030D28.
 */
#include "../include/Obj23813.h"


extern int func_02183D40(unsigned int *p);
extern void func_02183D1C(int *p);
extern void func_02183FA0(void **p);
extern void func_021841F4(char *);
extern void func_0218441C(int *p);
struct Ctx;
extern void func_02030D28(struct Ctx *c);

int func_02183CCC(int a, int b, int c, char *p)
{
    if (func_02183D40((unsigned int *)(p + 0x130)))
        return 1;
    func_02183D1C((int *)(p + 0x130));
    func_02183FA0((void **)p);
    func_021841F4(p + 0xE4);
    func_0218441C((int *)(p + 0xF8));
    func_02030D28((struct Ctx *)(((struct Obj23813 *)p)->f144));
    return 0;
}
