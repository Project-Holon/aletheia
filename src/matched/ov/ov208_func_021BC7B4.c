/*
 * function: func_021BC7B4
 * address: 0x021BC7B4
 * packet: pkt_ov208_021BC7B4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202173C 0x0202173C thumb
 */
#include "../include/Obj02252.h"
extern int func_0202173C(void *,unsigned short,unsigned short,short,unsigned char,unsigned char,unsigned short,void *);
void func_021BC7B4(char *p,short b,unsigned char c,unsigned char d)
{
    if(((struct Obj02252 *)p)->fC&1)func_0202173C(((struct Obj02252 *)p)->f8,1,0x1fff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&4)func_0202173C(((struct Obj02252 *)p)->f8,4,0xff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&2)func_0202173C(((struct Obj02252 *)p)->f8,2,0x1fff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&8)func_0202173C(((struct Obj02252 *)p)->f8,8,0x3fff,b,c,d,0,((struct Obj02252 *)p)->f0);
}
