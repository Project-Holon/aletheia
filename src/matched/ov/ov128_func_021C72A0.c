/*
 * function: func_021C72A0
 * address: 0x021C72A0
 * packet: pkt_ov128_021C72A0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021CA444 0x021CA444 thumb ov128
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj04505.h"
typedef unsigned char u8;
extern void func_021CA444(char *);
extern void func_021CA458(void *,void *);
struct Descriptor;
struct TaskMenuState;
struct U16Vec;
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_02045808(struct U16Vec *vec);
extern void func_020452E8(struct Descriptor *d);
extern void func_020307B0(void *);
void func_021C72A0(u8 *p, int unused, u8 *q)
{
    func_021CA444((char *)q);
    func_021CA458(q,q+12);
    func_02027FD8(((struct Obj04505 *)p)->f48);
    func_02045808(((struct Obj04505 *)p)->f30);
    func_02045808(((struct Obj04505 *)p)->f3C);
    func_02045808(((struct Obj04505 *)p)->f2C);
    func_020452E8(((struct Obj04505 *)p)->f1C);
    func_020452E8(((struct Obj04505 *)p)->fC);
    func_020307B0(((struct Obj04505 *)p)->f14);
}
