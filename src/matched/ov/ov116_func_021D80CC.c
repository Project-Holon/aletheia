/*
 * function: func_021D80CC
 * address: 0x021D80CC
 * packet: pkt_ov116_021D80CC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_0201CE38 0x0201CE38 thumb
 */
#include "../include/Obj06418.h"

typedef unsigned int u32;
struct Rec3;
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201CE38(void *);
int func_021D80CC(void *p) {
 int v;
 if(((struct Obj06418 *)p)->f9A4==0) return 1;
 v=func_0201CE30(((struct Obj06418 *)p)->f9A4);
 if(v==2) { func_0201CE48(((struct Obj06418 *)p)->f9A4); ((struct Obj06418 *)p)->f9A4=0; return 1; }
 if(v==1) { if(func_020362DC()==1 || func_02035C60()!=0) func_0201CE38(((struct Obj06418 *)p)->f9A4); }
 return 0;
}
