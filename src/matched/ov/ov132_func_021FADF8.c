/*
 * function: func_021FADF8
 * address: 0x021FADF8
 * packet: pkt_ov132_021FADF8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_020605B4 0x020605B4 arm
 */
#include "../include/Obj14096.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);
struct DList;
extern void func_020605B4(volatile struct DList *list, void *elem);
void func_021FADF8(char *p, char *q)
{
    func_020307B0(((struct Obj14096 *)q)->f8);
    func_02030EAC(((struct Obj14096 *)q)->fC);
    func_020605B4((volatile struct DList *)(p + 0x38), q);
    func_020307B0(q);
}
