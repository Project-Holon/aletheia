/*
 * function: func_021D74B0
 * address: 0x021D74B0
 * packet: pkt_ov120_021D74B0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8AB0 0x021D8AB0 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B908 0x0204B908 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj03259.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Table { u32 a[16]; } Table;
extern const Table d_021D8AB0;
extern void *func_020490F4(unsigned int id, u16 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B908(int a0, int a1);
extern void func_02041B6C(u32);
void func_021D74B0(u8 *p,int n)
{
    Table a=d_021D8AB0;
    void *t=func_020490F4(144,((struct Obj03259 *)p)->fF4);
    func_02049990(t,15,0,0,(u16)(((struct Obj03259 *)p)->f4),0,0,((struct Obj03259 *)p)->fF4);
    func_02049238(t);
    func_0204B92C(((struct Obj03259 *)p)->f130,0);
    func_0204B878(((struct Obj03259 *)p)->f130,a.a[n]+11);
    func_0204B908((int)(((struct Obj03259 *)p)->f130),4);
    func_0204B878(((struct Obj03259 *)p)->f12C,28);
    func_02041B6C(0);
    ((struct Obj03259 *)p)->f110=0;
    ((struct Obj03259 *)p)->f114=0;
}
