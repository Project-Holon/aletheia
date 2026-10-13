/*
 * function: func_02206A3C
 * address:  0x02206A3C
 * packet:   pkt_02206A3C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_Delete 0x020437AC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10827.h"

struct Obj020437AC;
extern void BMP_Delete(struct Obj020437AC *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_02206A3C(char *p, int a1)
{
    BMP_Delete(((struct Obj10827 *)p)->f10);
    func_020307B0(((struct Obj10827 *)p)->f8);
    func_020307B0(((struct Obj10827 *)p)->fC);
    func_020307B0(p);
}
