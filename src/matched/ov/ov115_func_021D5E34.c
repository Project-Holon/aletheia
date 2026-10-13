/*
 * function: func_021D5E34
 * address: 0x021D5E34
 * packet: pkt_ov115_021D5E34
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 */
#include "../include/Obj13853.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *);
enum Kind { K0,K1 };
void func_021D5E34(u8 *p) { switch(((struct Obj13853 *)p)->f0) { case K0: APP_TASKMENU_CloseMenu(*(struct TaskMenu * *)&((struct Obj13853 *)p)->f20); break; case K1: break; } }
