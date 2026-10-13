/*
 * function: func_021BB424,func_021BB440
 * unit: yes
 * address: 0x021BB424
 * packet: pkt_ov223_021BB424
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 */
#include "../include/Obj00084.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;extern void APP_TASKMENU_WIN_SetActive(struct Obj *,u32);extern void APP_TASKMENU_WIN_SetDecide(char *,int);
void func_021BB424(char *p) {u32 off;off=0x260;APP_TASKMENU_WIN_SetActive(*(struct Obj **)(p+off),1);APP_TASKMENU_WIN_SetDecide(*(char **)(p+off),1);}
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *);
u32 func_021BB440(char *p) {return APP_TASKMENU_WIN_IsFinish(*(u8 * *)&((struct Obj00084 *)p)->f260);}
