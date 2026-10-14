/*
 * function: GURU2_MAIN_DropEffectTask
 * address: 0x021E0C70
 * packet: pkt_ov137_021E0C70
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   gGuru2DropEffectStateTable 0x021E1CB8 data a4
 */
#include "../include/Obj23785.h"
#include "../include/Obj23786.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *);
extern int (*const gGuru2DropEffectStateTable[])(char *);
void GURU2_MAIN_DropEffectTask(struct Node *task,char *p) { int result; do { result=gGuru2DropEffectStateTable[*(int *)p](p); } while(result==1); if(result==2) { ((struct Obj23786 *)(*(char * *)&((struct Obj23785 *)p)->f10))->f8=1; func_020307B0(p); func_02030EAC(task); } }
