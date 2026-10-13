/*
 * function: func_021BD2F4
 * address: 0x021BD2F4
 * packet: pkt_ov209_021BD2F4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FRAME_LIST_GetItemValue 0x021B9398 thumb ov067
 */
#include "../include/Obj00088.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 FRAME_LIST_GetItemValue(char *,int);
int func_021BD2F4(char *p,int i) { if((FRAME_LIST_GetItemValue(*(char * *)&((struct Obj00088 *)p)->fC2C,i)&0xf0000000u)>>28)return 1;return 0; }
