/*
 * function: func_021C4CB4
 * address: 0x021C4CB4
 * packet: pkt_ov127_021C4CB4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C5334 0x021C5334 thumb ov127
 *   d_021C604C 0x021C604C data a4
 */
#include "../include/Obj00535.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C49A4(u8 *,unsigned);
extern void func_021C5334(char *);
extern int (*d_021C604C)(u8 *);
void func_021C4CB4(u8 *p)
{
 int i=func_021C49A4(p,5); int r=(*(int (**)(u8 *))((unsigned)&d_021C604C+i*4))(p);
 (((struct Obj00535 *)p)->f16)++;
 if(r==1) {func_021C5334((char *)p); ((struct Obj00535 *)p)->f16=0;}
}
