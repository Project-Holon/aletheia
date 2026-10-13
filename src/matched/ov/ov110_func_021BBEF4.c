/*
 * function: PMSIV_EDIT_StartPanelScroll
 * address: 0x021BBEF4
 * packet: pkt_ov110_021BBEF4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_02005624 0x02005624 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021BBE80 0x021BBE80 thumb ov110
 *   PMSIV_EDIT_UpdateFramePosition 0x021BBE8C thumb ov110
 */
#include "../include/Obj02816.h"
typedef unsigned char u8;
struct Node;
extern void func_02030EAC(struct Node *n);
typedef unsigned int   u32;
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void *func_020056A0(void *, void *, unsigned);
extern void func_021BBE80(void);
extern void PMSIV_EDIT_UpdateFramePosition(void *unused, u8 *p);
void PMSIV_EDIT_StartPanelScroll(u8 *p, u8 value)
{
    p[0x19c] = 0;
    p[0x19d] = value;
    if (((struct Obj02816 *)p)->f1A4) func_02030EAC(((struct Obj02816 *)p)->f1A4);
    ((struct Obj02816 *)p)->f1A4 = func_02005624((u32)func_021BBE80, (u32)p, 1);
    ((struct Obj02816 *)p)->f1A8 = 0;
    ((struct Obj02816 *)p)->f1AC = 0;
    if (((struct Obj02816 *)p)->f1B0) func_02030EAC(((struct Obj02816 *)p)->f1B0);
    ((struct Obj02816 *)p)->f1B0 = func_020056A0(PMSIV_EDIT_UpdateFramePosition, p, 1);
}
