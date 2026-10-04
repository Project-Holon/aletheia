/*
 * function: func_021E3F30
 * address: 0x021E3F30
 * packet: pkt_ov119_021E3F30
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj10379.h"
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049990(void *, unsigned int, int, int, unsigned short, int, int, unsigned int);
extern void func_02049238(void *);
void func_021E3F30(char *p)
{
    void *v;
    v = func_020490F4(0x66, ((struct Obj10379 *)p)->f5F4);
    func_02049990(v, 12, 4, 0, ((struct Obj10379 *)p)->f870, 0, 0, ((struct Obj10379 *)p)->f5F4);
    func_02049238(v);
}
