/*
 * unit: yes
 * function: EGG_DEMO_VIEW_StartModelAnim,EGG_DEMO_VIEW_IsModelAnimDone,EGG_DEMO_VIEW_EndModelAnim
 * address: 0x021F70F8
 * packet: pkt_ov215_021F70F8
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: three contiguous unlabelled blockers of 021F67E0; only code through
 *   021F7116 included, then two-byte padding and rodata beginning 021F7118.
 * function_starts: 0x021F70F8,0x021F7100,0x021F7110
 */
#include "../include/Obj25764.h"
#include "../include/Obj25765.h"
#include "../include/Obj25766.h"
void EGG_DEMO_VIEW_StartModelAnim(char *p){((struct Obj25764 *)p)->f5C=1;}
int EGG_DEMO_VIEW_IsModelAnimDone(char *p){return ((struct Obj25765 *)p)->f5C==2;}
void EGG_DEMO_VIEW_EndModelAnim(char *p){((struct Obj25766 *)p)->f5C=3;}
