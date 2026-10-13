/*
 * function: func_021DE550
 * address: 0x021DE550
 * packet: pkt_ov121_021DE550
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_DWC_Delete 0x020103E4 thumb
 *   func_021DE308 0x021DE308 thumb ov121
 *   func_0200FBA0 0x0200FBA0 thumb
 */
#include "../include/Obj10422.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIH_DWC_Delete(u8 *);
extern void func_021DE308(char *,unsigned);
extern void func_0200FBA0(void);
void func_021DE550(char *p) {if(*(u8 * *)&((struct Obj10422 *)p)->f10) {WIH_DWC_Delete(*(u8 * *)&((struct Obj10422 *)p)->f10); *(int *)&((struct Obj10422 *)p)->f10=0;} func_021DE308(p,0); func_0200FBA0();}
