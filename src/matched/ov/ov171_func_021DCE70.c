/*
 * function: func_021DCE70
 * address: 0x021DCE70
 * packet: pkt_ov171_021DCE70
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DEB5C 0x021DEB5C data a4
 *   func_021DE030 0x021DE030 thumb ov171
 *   func_021DD8DC 0x021DD8DC thumb ov171
 */
#include "../include/Obj14286.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 d_021DEB5C[];
extern void func_021DE030(u8*);
extern void func_021DD8DC(char*);
int func_021DCE70(u8*p){typedef int(*Fn)(u8*);((struct Obj14286 *)p)->fC6C=(*(Fn*)((u32)d_021DEB5C+*(u32*)(p+0xc6c)*4))(p);if(((struct Obj14286 *)p)->fC6C==11)return 0;func_021DE030(p);func_021DD8DC((char*)p);return 1;}
