/*
 * function: PSEL_CreateTaskRes
 * address: 0x021BB38C
 * packet: pkt_ov223_021BB38C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 */
#include "../include/Obj00739.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct R;extern struct R *APP_TASKMENU_RES_Create(u16,u16,u32,u32,u16);
void PSEL_CreateTaskRes(char *p) {*(struct R * *)&((struct Obj00739 *)p)->f25C=APP_TASKMENU_RES_Create(3,11,*(u32 *)&((struct Obj00739 *)p)->f18,((struct Obj00739 *)p)->f1C,((struct Obj00739 *)p)->f0);}
