/*
 * function: func_021EDAB0
 * address: 0x021EDAB0
 * packet: pkt_ov170_021EDAB0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049E34 0x02049E34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021DEDCC 0x021DEDCC thumb ov170
 *   func_021EDBE8 0x021EDBE8 thumb ov170
 *   func_021EDC0C 0x021EDC0C thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj24024.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02082D44(const void *, void *, unsigned);
extern void func_020307B0(void *);
extern int func_021DEDCC(unsigned char *, int);
extern void func_021EDBE8(int x0, unsigned char *a, unsigned c, unsigned char d, unsigned n);
extern void func_021EDC0C(char *, int, unsigned char *);
void func_021EDAB0(char *p, int i)
{
    void *t;
    void *q = func_02049E34(0x74, 0x47, 1, (u32)(&t), 0x4c);
    func_02082D44(((struct Obj24024 *)t)->f14, *(char * *)&((struct Obj00000 *)p)->f2C + 0x3e70 + i * 0x400, 0x400);
    func_020307B0(q);
    func_021EDBE8((int)p, (unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x3e70 + i * 0x400), func_021DEDCC((unsigned char *)p, i), 8, 0x400);
    func_021EDC0C(p, i, (unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x3e70 + i * 0x400));
}
