/*
 * function: func_021BD6BC
 * address: 0x021BD6BC
 * packet: pkt_ov216_021BD6BC
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02040618 0x02040618 arm
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj04637.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct TcblNode;
extern void func_02040618(u32,u32,u32);
extern void TCBL_DeleteTask(struct TcblNode*);
void func_021BD6BC(struct TcblNode*task,u8*p){u32 old=p[2]++;if(old<p[1]){((struct Obj04637 *)p)->f3=((struct Obj04637 *)p)->f3+((struct Obj04637 *)p)->f4;func_02040618(1,3,((struct Obj04637 *)p)->f3);}else{--**(u32* *)&((struct Obj04637 *)p)->f8;TCBL_DeleteTask(task);}}
