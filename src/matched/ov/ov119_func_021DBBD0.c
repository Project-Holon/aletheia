/*
 * function: func_021DBBD0
 * address: 0x021DBBD0
 * packet: pkt_ov119_021DBBD0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021DBB6C 0x021DBB6C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
#include "../include/Obj00001.h"
extern void func_021DF7AC(void *,int); extern void func_02082BCC(void *,int,int); extern void func_021D8C84(void *); extern void APP_TASKMENU_CloseMenu(int); extern void func_021E4420(void *); extern void func_021E6700(void *); extern void func_021DBB6C(void *); extern void func_021D8E84(void *,int); extern void func_021DBE70(void);
void func_021DBBD0(char *p) { func_021DF7AC(p,1); func_02082BCC(p+0xca0,0,0x78); func_02082BCC(p+0xd18,0,0x3c); func_02082BCC(p+0xd54,0,0x3c); func_021D8C84(p); if(*(int *)&((struct Obj00001 *)p)->f64C) {APP_TASKMENU_CloseMenu(*(int *)&((struct Obj00001 *)p)->f64C); *(int *)&((struct Obj00001 *)p)->f64C=0;} func_021E4420(p);func_021E6700(p);func_021DBB6C(p);func_021D8E84(p,(int)func_021DBE70);}
