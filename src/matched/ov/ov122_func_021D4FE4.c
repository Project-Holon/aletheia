/*
 * function: func_021D4FE4
 * address: 0x021D4FE4
 * packet: pkt_ov122_021D4FE4
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   func_021D503C 0x021D503C thumb ov122
 *   func_021D4D98 0x021D4D98 thumb ov122
 */
#include "../include/Obj00265.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);extern int BUTTON_MAN_UpdateSlots(void *);extern void func_021D503C(char *);extern void func_021D4D98(char *);
void func_021D4FE4(char *p) {if(WIPE_SYS_EndCheck())BUTTON_MAN_UpdateSlots(((struct Obj00265 *)p)->f40);func_021D503C(p);func_021D4D98(p);}
