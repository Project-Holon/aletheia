/*
 * function: func_021BD6FC
 * address: 0x021BD6FC
 * packet: pkt_ov216_021BD6FC
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * region evidence: ov067 labels 021B64A8; its filed/full body reads the supplied object in r0 and enable in r1.
 * symbols:
 *   sub_020311B8 0x020311B8 arm
 *   sub_02031290 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021BD768 0x021BD768 thumb ov216
 *   func_021B64A8 0x021B64A8 thumb ov067
 */
#include "../include/Obj10949.h"
#include "../include/Obj14720.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
extern struct TcblNode *sub_020311B8(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *sub_02031290(struct S02030FB4 *);
extern void MI_CpuFill8(void *, int, int);
extern void func_021BD768(struct TcblNode *, void *);
extern void func_021B64A8(u8 *, u32);
void func_021BD6FC(char *owner, int *counter)
{
    char *work;
    work = sub_02031290((struct S02030FB4 *)sub_020311B8(*(struct Tcbl * *)&((struct Obj14720 *)owner)->f18, func_021BD768, 16, 0));
    MI_CpuFill8(work, 0, 16);
    *(char * *)&((struct Obj10949 *)work)->f8 = owner;
    ((struct Obj10949 *)work)->f1 = 150;
    func_021B64A8(*(u8 * *)&((struct Obj14720 *)owner)->f124, 0);
    *(int * *)&((struct Obj10949 *)work)->fC = counter;
    ++*counter;
}
