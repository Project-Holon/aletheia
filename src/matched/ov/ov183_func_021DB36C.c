/*
 * function: func_021DB36C
 * address: 0x021DB36C
 * packet: pkt_ov183_021DB36C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj08308.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct S020315D4;
extern void func_021FD820(char *);
extern void func_021FD714(void *p);
struct PrintSys;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *);
int func_021DB36C(struct S020315D4 *task,int b,int c,char *p) { func_021FD820(*(char * *)&((struct Obj08308 *)p)->f14); func_021FD820(*(char * *)&((struct Obj08308 *)p)->f18); PRINTSYS_QUE_Delete(((struct Obj08308 *)p)->fC); func_021FD714((void *)(((struct Obj08308 *)p)->f0)); func_020315D4(task); return 1; }
