/*
 * function: func_021B6AFC,func_021B6B18
 * address: 0x021B6AFC
 * packet: pkt_ov180_021B6AFC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
#include "../include/Obj10719.h"
#include "../include/Obj24487.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern unsigned WIPE_SYS_EndCheck(void);
int func_021B6AFC(char *p){if(WIPE_SYS_EndCheck()==1)return ((struct Obj24487 *)p)->f9194;return 2;}
int func_021B6B18(char *p){if(((struct Obj10719 *)p)->f9188==0)return ((struct Obj10719 *)p)->f9194;((struct Obj10719 *)p)->f9188-=1;return 3;}
