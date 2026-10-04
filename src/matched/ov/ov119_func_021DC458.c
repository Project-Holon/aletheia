/*
 * function: func_021DC458
 * address: 0x021DC458
 * packet: pkt_ov119_021DC458
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_021E53F8 0x021E53F8 thumb ov119
 *   func_021E5430 0x021E5430 thumb ov119
 *   func_021E5680 0x021E5680 thumb ov119
 */
#include "../include/Obj22734.h"
typedef unsigned short u16;
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(unsigned short);
extern void func_021E53F8(char *p);
extern void func_021E5430(void *);
extern void func_021E5680(char *p);
void func_021DC458(char *p)
{
    func_0203F8F4(0x91);
    func_02045088(((struct Obj22734 *)p)->f5F4);
    func_021E53F8(p);
    func_021E5430(p);
    func_021E5680(p);
}
