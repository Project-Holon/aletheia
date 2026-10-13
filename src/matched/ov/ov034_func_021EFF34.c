/*
 * function: REPORT_Delete
 * address: 0x021EFF34
 * packet: pkt_ov034_021EFF34
 * region: ov034
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   REPORT_ExitWindows 0x021F0700 thumb ov034
 *   REPORT_ExitActors 0x021F0930 thumb ov034
 *   REPORT_ExitBgs 0x021F01F8 thumb ov034
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj20477.h"
struct Node;
extern void func_02030EAC(struct Node *n);
extern void REPORT_ExitWindows(char *);
extern void REPORT_ExitActors(int *);
extern void REPORT_ExitBgs(void);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void REPORT_Delete(char *p) { func_02030EAC((struct Node *)(((struct Obj20477 *)p)->f10C)); REPORT_ExitWindows(p); REPORT_ExitActors((int *)p); REPORT_ExitBgs(); func_020307B0(p); }
