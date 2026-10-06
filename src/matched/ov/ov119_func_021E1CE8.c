/*
 * function: func_021E1CE8
 * address:  0x021E1CE8
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E1CA8  0x021E1CA8  thumb  ov119
 *   func_021E1CC8  0x021E1CC8  thumb  ov119
 *   func_021E36D8  0x021E36D8  thumb  ov119
 *   func_021E3F70  0x021E3F70  thumb  ov119
 *   func_021E5BE4  0x021E5BE4  thumb  ov119
 *   func_021E5EF8  0x021E5EF8  thumb  ov119
 *   func_021E625C  0x021E625C  thumb  ov119
 *   func_020456F8  0x020456F8  arm
 *   func_020452E8  0x020452E8  arm
 */
#include "../include/Obj00001.h"

extern void func_021E1CA8(char *p);
extern void func_021E1CC8(char *p);
extern void func_021E36D8(void *p, int a);
extern void func_021E3F70(void *p);
struct Descriptor;
extern void func_021E5BE4(int a);
extern void func_021E5EF8(void *p);
extern void func_021E625C(void *p);
extern void func_020456F8(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);

void func_021E1CE8(void *p, int a1)
{
    unsigned int v;

    func_021E5EF8((char *)p + 0x964);
    func_021E5EF8((char *)p + 0x978);
    func_021E625C(p);
    if (a1 != 0) {
        v = *(volatile unsigned int *)0x04001000;
        v &= 0xFFFF1FFF;
        *(volatile unsigned int *)0x04001000 = v;
    }
    func_021E1CA8(p);
    func_021E1CC8(p);
    func_021E5EF8((char *)p + 0x950);
    func_021E5BE4((int)p);
    func_021E36D8(p, 0);
    func_021E36D8(p, 1);
    func_020456F8((struct Descriptor *)(*(int *)&((struct Obj00001 *)p)->f6B4));
    func_020452E8((struct Descriptor *)(*(int *)&((struct Obj00001 *)p)->f6B4));
    *(int *)&((struct Obj00001 *)p)->f6B4 = 0;
    func_021E3F70(p);
}
