/*
 * function: func_021BD854
 * address: 0x021BD854
 * packet: pkt_ov216_021BD854
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD13C 0x021BD13C thumb ov216
 *   func_021BD0E4 0x021BD0E4 thumb ov216
 *   sub_02031194 0x02031194 arm
 */
#include "../include/Obj02927.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int   u32;
extern void func_021BD13C(u8 *p, int a);
extern void func_021BD0E4(char *p, u8 index, u32 enable);
struct TcblNode;
extern void sub_02031194(struct TcblNode *);
void func_021BD854(struct TcblNode *task, char *p)
{
    u8 count;
    count = ((struct Obj02927 *)p)->f1;
    ((struct Obj02927 *)p)->f1 = count - 1;
    if (count != 0) {
        ((struct Obj02927 *)p)->f4 += ((struct Obj02927 *)p)->f6;
        func_021BD13C(((struct Obj02927 *)p)->fC, ((struct Obj02927 *)p)->f4);
        return;
    }
    if (((struct Obj02927 *)p)->f4 != 0)
        func_021BD0E4(((struct Obj02927 *)p)->f10, ((struct Obj02927 *)p)->f0, 0);
    --**(int * *)&((struct Obj02927 *)p)->f14;
    sub_02031194(task);
}
