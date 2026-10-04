/*
 * function: func_021D5E6C
 * address: 0x021D5E6C
 * packet: pkt_ov115_021D5E6C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02034714 0x02034714 arm
 *   d_021D663C 0x021D663C data a1
 */
#include "../include/Obj10334.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern const char d_021D663C[];
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern void func_02034714(const char *expr, u32 line, const char *file);
int func_021D5E6C(u8 *p) { switch(((struct Obj10334 *)p)->f0) { case 0: return func_020279E8(((struct Obj10334 *)p)->f20); case 1: if(((struct Obj10334 *)p)->f28!=-1) return 1; else return 0; default: func_02034714(d_021D663C,0,d_021D663C); return 0; } }
