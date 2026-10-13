/*
 * function: PLIST_PLATE_Redraw
 * address: 0x021BB2C0
 * packet: pkt_ov091_021BB2C0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PLIST_PLATE_Draw 0x021BAAE4 thumb ov091
 */
#include "../include/Obj20878.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PLIST_PLATE_Draw(u8 *,u8 *,int);
void PLIST_PLATE_Redraw(u8 *a,u8 *s) {BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj20878 *)s)->f20)),0);PLIST_PLATE_Draw(a,s,0);}
