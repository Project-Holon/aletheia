/*
 * function: func_021F3AA4
 * address:  0x021F3AA4
 * packet:   pkt_ov055_021F3AA4
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02189A38  0x02189A38  thumb  ov021
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   func_021F3F30  0x021F3F30  thumb  ov055
 *   func_021F3D90  0x021F3D90  thumb  ov055
 *   func_021F3CF4  0x021F3CF4  thumb  ov055
 *   func_021F4474  0x021F4474  thumb  ov055
 */
#include "../../../matched/include/Obj13120.h"

extern int func_02189A38(int);
typedef signed short   s16;
extern int func_02189A2C(int *a);
struct S;
extern void func_021F3F30(struct S *p, char *q, int k);
extern void func_021F3D90(unsigned char *p);
extern void func_021F3CF4(unsigned char *p, int a, int b);
extern void func_021F4474(s16 *a, s16 *b, int *c);

void func_021F3AA4(int a, int b, char *c)
{
    int i;

    func_021F3F30((struct S *)(c + 0x308), c, func_02189A38(b));
    if (func_02189A2C((int *)b)) {
        for (i = 0; i < 0x20; i++)
            func_021F3D90((unsigned char *)(c + 8 + i * 0x18));
    }
    for (i = 0; i < 0x20; i++)
        func_021F3CF4((unsigned char *)(c + 8 + i * 0x18), ((struct Obj13120 *)c)->f4, ((struct Obj13120 *)c)->f0);
    func_021F4474((s16 *)(c + 0x348), (s16 *)(c + 0x308), (int *)b);
}
