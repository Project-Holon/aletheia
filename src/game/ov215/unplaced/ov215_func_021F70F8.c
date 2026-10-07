/*
 * unit: yes
 * function: func_021F70F8,func_021F7100,func_021F7110
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
#include "../../../matched/include/Obj25764.h"
#include "../../../matched/include/Obj25765.h"
#include "../../../matched/include/Obj25766.h"
void func_021F70F8(char *p){((struct Obj25764 *)p)->f5C=1;}
int func_021F7100(char *p){return ((struct Obj25765 *)p)->f5C==2;}
void func_021F7110(char *p){((struct Obj25766 *)p)->f5C=3;}
