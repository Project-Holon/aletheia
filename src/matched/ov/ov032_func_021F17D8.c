/*
 * function: BEACON_VIEW_ScrollStepTask
 * address: 0x021F17D8
 * packet: pkt_ov032_021F17D8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj03636.h"

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);
void BEACON_VIEW_ScrollStepTask(void *task, u8 *q)
{
    u32 old;
    int x;
    old = q[2];
    q[2] = old + 1;
    if (old < q[1]) {
        x = ((struct Obj03636 *)q)->f3;
        q[3] = x + ((struct Obj03636 *)q)->f4;
        BG_SYS_FillScrollArea(6, 3, ((struct Obj03636 *)q)->f3);
        return;
    }
    (**(int * *)&((struct Obj03636 *)q)->f8)--;
    TCBL_DeleteTask(task);
}
