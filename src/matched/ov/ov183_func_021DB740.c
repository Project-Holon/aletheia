/*
 * function: func_021DB740
 * address: 0x021DB740
 * packet: pkt_ov183_021DB740
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: Explicit call arms preserve the original conditional argument branch.
 * symbols:
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021F9F48 0x021F9F48 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj10727.h"
#include "../include/Obj14419.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct S020315D4;
extern void func_021FBDA4(int,unsigned),func_021F9F48(u8 *),func_021FD820(char *);
extern void func_020315D4(struct S020315D4 *);
int func_021DB740(struct S020315D4 *task,int b,char *q,char *p) { if(((struct Obj10727 *)q)->f0<5) func_021FBDA4(((struct Obj10727 *)q)->f18,3); else func_021FBDA4(((struct Obj10727 *)q)->f18,4); func_021F9F48(*(u8 * *)&((struct Obj14419 *)p)->f0); func_021FD820(*(char * *)&((struct Obj14419 *)p)->f4); func_020315D4(task); return 1; }
