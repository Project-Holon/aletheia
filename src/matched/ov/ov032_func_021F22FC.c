/*
 * function: func_021F22FC
 * address:  0x021F22FC
 * packet:   pkt_ov032_021F22FC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F22FC 0x021F22FC thumb
 *   func_021F30B4 0x021F30B4 thumb
 *   func_021F2FCC 0x021F2FCC thumb
 *   func_021F2EDC 0x021F2EDC thumb
 *   func_021F2CC4 0x021F2CC4 thumb
 *   func_021F2BD4 0x021F2BD4 thumb
 *   func_021F2A04 0x021F2A04 thumb
 *   func_021F28DC 0x021F28DC thumb
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00812.h"

typedef unsigned int u32;

extern void func_021F30B4(char *p);
extern void func_021F2FCC(char *p);
extern void func_021F2EDC(char *p);
extern void func_021F2CC4(char *p);
extern void func_021F2BD4(char *p);
extern void func_021F2A04(char *p);
extern void func_021F28DC(char *p);
struct Tcbl;
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void func_02049238(u32 a);
extern u32 func_020307B0(void *p);

void func_021F22FC(char *p)
{
    TCBL_DeleteAllTasks((struct Tcbl *)(((struct Obj00812 *)p)->fA0));
    func_021F30B4(p);
    func_021F2FCC(p);
    func_021F2EDC(p);
    func_021F2CC4(p);
    func_021F2BD4(p);
    func_021F2A04(p);
    func_021F28DC(p);
    func_02049238(((struct Obj00812 *)p)->f9C);
    func_020307B0(p);
}
