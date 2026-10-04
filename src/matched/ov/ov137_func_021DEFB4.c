/*
 * function: func_021DEFB4
 * address: 0x021DEFB4
 * packet: pkt_ov137_021DEFB4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * symbols:
 *   func_021E16C4 0x021E16C4 thumb ov137
 */
#include "../include/Obj01753.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021E16C4(char *,int);
int func_021DEFB4(char *p) { if(func_021E16C4(p,4)==1) { ((struct Obj01753 *)p)->f0=22; return 1; } return 0; }
