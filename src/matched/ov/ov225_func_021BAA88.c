/*
 * function: func_021BAA88
 * address: 0x021BAA88
 * packet: pkt_ov225_021BAA88
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   sub_02041B6C 0x02041B6C arm
 */
#include "../include/Obj14806.h"
#include "../include/Obj26200.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct PrintSys;
struct TaskMenuState;
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void APP_TASKMENU_WIN_Delete(u8 *);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void sub_02041B6C(u32);
void func_021BAA88(char *p) { u8 i; PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26200 *)(*(char * *)&((struct Obj14806 *)p)->f4))->f14); for(i=0;i<8;i++) if(*(u8 **)(p+i*4+12)) APP_TASKMENU_WIN_Delete(*(u8 **)(p+i*4+12)); APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct Obj14806 *)p)->f8); sub_02041B6C(5); }
