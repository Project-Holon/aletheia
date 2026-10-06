/*
 * function: func_021888C8
 * address:  0x021888C8
 * packet:   pkt_ov021_021888C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047CE4  0x02047CE4  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0218E104  0x0218E104  thumb  ov021
 *   func_02189A80  0x02189A80  thumb  ov021
 *   func_02189084  0x02189084  thumb  ov021
 */
#include "../include/Obj12555.h"

typedef unsigned short u16;

void func_02047CE4(void);
unsigned int func_0203630C(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
void func_0218E104(u8 *a, u32 b);
int func_02189A80(char *p);
void func_02189084(unsigned char *p);

void func_021888C8(char *o)
{
    volatile u16 *r = (volatile u16 *)0x04000204;

    func_02047CE4();
    func_0218E104((u8 *)(((struct Obj12555 *)o)->f10), (u16)func_0203630C());
    ((struct Obj12555 *)o)->f100 = func_02189A80(o);
    *r = *r & 0xFFFF7FFF;
    func_02189084((unsigned char *)o);
    *r = *r | 0x8000;
}
