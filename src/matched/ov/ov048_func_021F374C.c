/*
 * function: func_021F374C
 * address: 0x021F374C
 * packet: pkt_ov048_021F374C
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F37C4 0x021F37C4 thumb ov048
 *   func_021F474C 0x021F474C thumb ov048
 *   func_021F38EC 0x021F38EC thumb ov048
 */
#include "../include/Obj05133.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int *func_021897BC(char *,int);
extern void func_021F37C4(u8 *);
extern void func_021F474C(unsigned char *p);
extern void func_021F38EC(int *p);
void func_021F374C(char *a) { u8 *p; p=(u8 *)func_021897BC(a,0); func_021F37C4(p); if(((struct Obj05133 *)p)->f14)func_021F474C(((struct Obj05133 *)p)->f14); func_021F38EC((int *)p); }
