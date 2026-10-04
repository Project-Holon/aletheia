/*
 * function: func_021DE7FC
 * address: 0x021DE7FC
 * packet: pkt_ov121_021DE7FC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02157928 0x02157928 thumb ov010
 *   func_02157910 0x02157910 thumb ov010
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE7BC 0x021DE7BC thumb ov121
 */
#include "../include/Obj10427.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02157928(u8 *);extern int func_02157910(u8 *);extern void func_021DEEA4(void *,void *);extern void func_021DE7BC(void);
void func_021DE7FC(void *a,int b,char *p) {func_02157928(*(u8 * *)&((struct Obj10427 *)p)->f798);if(func_02157910(*(u8 * *)&((struct Obj10427 *)p)->f798)) {((struct Obj10427 *)p)->f17A4=1;func_021DEEA4(a,func_021DE7BC);}}
