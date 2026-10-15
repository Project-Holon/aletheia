/*
 * function: EGG_DEMO_VIEW_Delete
 * address: 0x021F67B0
 * packet: pkt_ov215_021F67B0
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: zero halfword at 021F67DE is alignment padding.
 * symbols:
 *   EGG_DEMO_VIEW_RemoveModel 0x021F7028 thumb ov215
 *   EGG_DEMO_VIEW_DeleteModel 0x021F6F18 thumb ov215
 *   EGG_DEMO_VIEW_DeleteParticles 0x021F6E4C thumb ov215
 *   EGG_DEMO_VIEW_DeletePokeMcss 0x021F6CAC thumb ov215
 *   EGG_DEMO_VIEW_DeleteMcss 0x021F6AE0 thumb ov215
 *   TCB_DeleteTask 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj04636.h"
struct Node;
extern void EGG_DEMO_VIEW_RemoveModel(char *);
extern void EGG_DEMO_VIEW_DeleteModel(char *);
extern void EGG_DEMO_VIEW_DeleteParticles(char *);
extern void EGG_DEMO_VIEW_DeletePokeMcss(char *);
extern void EGG_DEMO_VIEW_DeleteMcss(char *);
extern void TCB_DeleteTask(struct Node *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void EGG_DEMO_VIEW_Delete(char *p){EGG_DEMO_VIEW_RemoveModel(p);EGG_DEMO_VIEW_DeleteModel(p);EGG_DEMO_VIEW_DeleteParticles(*(char * *)&((struct Obj04636 *)p)->f44);EGG_DEMO_VIEW_DeletePokeMcss(p);EGG_DEMO_VIEW_DeleteMcss(p);TCB_DeleteTask(*(struct Node * *)&((struct Obj04636 *)p)->f2C);func_020307B0(p);}
