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
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   UNION_COMM_ReleaseWorks 0x02173420 thumb ov012
 */
#include "../include/Obj00033.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void UNION_COMM_ReleaseWorks(void *p);
void UNION_COMM_Delete(void *p, u8 *q)
{
    if (((struct Obj00033 *)q)->f352C != 0) func_020307B0(((struct Obj00033 *)q)->f352C);
    UNION_COMM_ReleaseWorks(q);
    func_020307B0(q);
    GFL_HEAP_DeleteChecked(0x41);
    func_020307B0(p);
}
