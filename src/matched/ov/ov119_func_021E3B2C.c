/*
 * function: func_021E3B2C
 * address: 0x021E3B2C
 * packet: pkt_ov119_021E3B2C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_020862F0 0x020862F0 arm
 *   func_02083194 0x02083194 arm
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj10376.h"
#include "../include/Obj22795.h"
#include "../include/Obj22796.h"
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
typedef unsigned int   u32;
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_020862F0(void *, int);
extern void func_02083194(const void *, void *, int);
extern void func_0207FA0C(void);
extern void func_0207FA40(const void *, int, int);
extern void func_0207FADC(void);
extern void func_02082D44(const void *, void *, int);
extern void func_020307B0(void *);
extern void func_02049238(void *);
void func_021E3B2C(char *p)
{
    void *v;
    void *allocation;
    void *descriptor;
    char *data;
    v = func_020490F4(0x74, ((struct Obj10376 *)p)->f5F4);
    allocation = func_02049F78(v, 0x48, (u32)(&descriptor), ((struct Obj10376 *)p)->f5F4);
    data = *(char * *)&((struct Obj22795 *)descriptor)->fC;
    func_020862F0(data + 32, 32);
    func_02083194(data + 32, data + 34, 30);
    ((struct Obj22796 *)data)->f20 = 0x14A5;
    func_020862F0(data + 32, 32);
    func_0207FA0C();
    func_0207FA40(data + 32, 0x2000, 32);
    func_0207FADC();
    func_02082D44(data + 32, p + 0x1134, 32);
    func_020307B0(allocation);
    func_02049238(v);
}
