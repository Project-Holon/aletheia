/*
 * function: func_021B7FC8
 * address: 0x021B7FC8
 * packet: pkt_ov103_021B7FC8
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj07982.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet;
extern u32 func_0201ED04(struct WordSet *p); extern void MSGDATA_Delete(void *); extern void func_0201C4C0(void *); extern void GF_FONT_Delete(void *); extern void func_02082BCC(void *,int,u32);
void func_021B7FC8(u8 *p) {func_0201ED04(((struct Obj07982 *)p)->fC);MSGDATA_Delete(((struct Obj07982 *)p)->f4);func_0201C4C0(((struct Obj07982 *)p)->f8);GF_FONT_Delete(((struct Obj07982 *)p)->f0);func_02082BCC(p,0,16);}
