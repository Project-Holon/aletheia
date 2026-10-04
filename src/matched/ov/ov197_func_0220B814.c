/*
 * function: func_0220B814
 * address: 0x0220B814
 * packet: pkt_ov197_0220B814
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: named row index in Row[36][2] restores base-add-before-column-shift; raw byte row differs in seven bytes.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02020FB4 0x02020FB4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj04597.h"
#include "../include/Obj25005.h"
#include "../include/Obj25007.h"
#include "../include/Obj25008.h"
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02020FB4(void *,unsigned,unsigned);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern void func_02045808(struct U16Vec *vec);
typedef struct { unsigned short entry[36][2]; } Row;
void func_0220B814(char *p,int n)
{
    void *owner;
    int index;
    Row *row;
    void *buf=func_020457B0(130,((struct Obj25005 *)(*(char * *)&((struct Obj04597 *)p)->f0))->fC);
    index=((struct Obj04597 *)p)->f533;
    row=(Row *)(p+0x150);
    func_02020FB4(buf,row[index].entry[n][0],((struct Obj25007 *)(*(char * *)&((struct Obj04597 *)p)->f0))->fC);
    owner=((struct Obj04597 *)p)->f18;
    func_0201C724(owner,(unsigned)func_02045770(((struct Obj04597 *)p)->f130),4,0,(unsigned)buf,((struct Obj25008 *)(*(char * *)&((struct Obj04597 *)p)->f0))->f4,0x3c40);
    ((struct Obj04597 *)p)->f134=1;
    func_02045808(buf);
}
