/*
 * unit: yes
 * function: EGG_DEMO_VIEW_ResetAnimState,EGG_DEMO_VIEW_IsFinished
 * address: 0x021F6A98
 * packet: pkt_ov215_021F6A98
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: two unlabelled leaves blocking concrete MATCH900 ov215021F5884.
 * extent: setter and predicate, each followed by two zero alignment bytes.
 */
#include "../include/Obj14710.h"
#include "../include/Obj25759.h"
void EGG_DEMO_VIEW_ResetAnimState(char *p){((struct Obj14710 *)p)->fC=6;((struct Obj14710 *)p)->f18=0;}
int EGG_DEMO_VIEW_IsFinished(char *p){if(((struct Obj25759 *)p)->fC>=9)return 1;return 0;}
