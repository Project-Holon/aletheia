/*
 * function: func_021D7BF0
 * address: 0x021D7BF0
 * packet: pkt_ov131_021D7BF0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D7E84 0x021D7E84 thumb ov131
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02844.h"

extern void func_021D7E84(void *p, void **q);
struct Rec;
extern unsigned int func_02045C04(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021D7BF0(void *a, unsigned char *p)
{
    if (((struct Obj02844 *)p)->f4 == 1) func_021D7E84(a, (void **)p);
    func_02045C04(((struct Obj02844 *)p)->f38);
    func_02045C04(((struct Obj02844 *)p)->f3C);
    func_02045C04(((struct Obj02844 *)p)->f40);
    func_02045C04(((struct Obj02844 *)p)->f44);
    func_02045C04(((struct Obj02844 *)p)->f48);
    func_020307B0(((struct Obj02844 *)p)->f50);
    func_020307B0(((struct Obj02844 *)p)->f58);
    func_020307B0(((struct Obj02844 *)p)->f60);
    func_020307B0(((struct Obj02844 *)p)->f68);
}
