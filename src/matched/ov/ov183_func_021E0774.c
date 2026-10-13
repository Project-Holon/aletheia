/*
 * function: func_021E0774
 * address: 0x021E0774
 * packet: pkt_ov183_021E0774
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are alignment padding.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021E08E4 0x021E08E4 thumb ov183
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10751.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021E08E4(char *);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BUTTON_MAN_Delete(void *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021E0774(char *p){func_02030EAC(((struct Obj10751 *)p)->f314);func_021E08E4(p);ARC_TOOL_DeleteHandle(((struct Obj10751 *)p)->f258);BUTTON_MAN_Delete(((struct Obj10751 *)p)->f294);func_020307B0(p);}
