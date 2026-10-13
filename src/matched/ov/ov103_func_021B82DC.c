/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer
 * address: 0x021B82DC
 * packet: pkt_ov103_021B82DC
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Verified against the ov103 Thumb image.
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName 0x021B824C thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_PrintMessage 0x021B8138 thumb ov103
 */
#include "../include/Obj01388.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(u8 *,void *,int,u8 *,s16,s16,int); extern void IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(u8 *,void *,int,int,s16);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer(u8 *a,u8 *b,int c) { int *p=*(int * *)&((struct Obj01388 *)b)->fB0C; if(p[0])IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(a,b+0x174,c,(u8 *)p[2],0,0,0x37); else IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(a,b+0x174,c,0,0); }
