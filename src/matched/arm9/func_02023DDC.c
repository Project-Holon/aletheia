/*
 * function: WIPE_SUB_WindowRectTask
 * address:  0x02023DDC
 * packet:   pkt_02023DDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   WIPE_SUB_SetWindowRect  0x02023C3C  thumb
 */
#include "../include/Obj04734.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct Node;
extern void WIPE_SUB_SetWindowRect(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub);
extern void func_02030EAC(struct Node *n);

void WIPE_SUB_WindowRectTask(void *a0, short *a1)
{
    WIPE_SUB_SetWindowRect(a1[0], a1[1], a1[2], a1[3],
                  ((struct Obj04734 *)a1)->f8, ((struct Obj04734 *)a1)->fC);
    func_02030EAC(a0);
}
