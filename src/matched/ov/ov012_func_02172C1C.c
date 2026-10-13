/*
 * function: UNION_COMM_Delete
 * address: 0x02172C1C
 * packet: pkt_ov012_02172C1C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02173420 0x02173420 thumb ov012
 */
#include "../include/Obj00033.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_020306F0(unsigned int heap);
extern void func_02173420(void *p);
void UNION_COMM_Delete(void *p, u8 *q)
{
    if (((struct Obj00033 *)q)->f352C != 0) func_020307B0(((struct Obj00033 *)q)->f352C);
    func_02173420(q);
    func_020307B0(q);
    func_020306F0(0x41);
    func_020307B0(p);
}
