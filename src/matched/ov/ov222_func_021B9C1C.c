/*
 * function: func_021B9C1C
 * address: 0x021B9C1C
 * packet: pkt_ov222_021B9C1C
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040E78 0x02040E78 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045768 0x02045768 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021BA378 0x021BA378 data a1
 */
#include "../include/Obj06725.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021BA378[];
extern void *func_02030734(u32,u32,int,const char*,u16);
extern u32 func_020307B0(void *p);
extern void func_02040E78(u32,void*,u32,u32);
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern u16 func_02045768(struct Descriptor *p);
extern void func_02041090(u32,u32,u32,u32,u8,u8);
extern void func_020409B4(u32);
void func_021B9C1C(char *p)
{
 u16 *tiles;
 u16 *buf;
 u16 index;
 unsigned long tile;
 u8 x,y;
 buf=func_02030734(((struct Obj06725 *)p)->f0,32,1,d_021BA378,0x3db);
 index=0;
 buf[0]=0;
 buf[1]=0x1d29;
 buf[2]=0x3210;
 buf[3]=0;
 func_02040E78(2,buf,32,480);
 func_020307B0(buf);
 func_02043B5C(func_02045770(*(void* *)&((struct Obj06725 *)p)->f20),3);
 func_02045334(*(void* *)&((struct Obj06725 *)p)->f20);
 tiles=func_02030734(((struct Obj06725 *)p)->f0,1536,1,d_021BA378,0x3ec);
 tile=func_02045768(*(void* *)&((struct Obj06725 *)p)->f20)|0xf000;
 for(y=0;y<24;y++) for(x=0;x<32;x++) {tiles[index]=tile;index++;}
 func_02041090(2,(u32)tiles,0,24,32,24);
 func_020409B4(2);
 func_020307B0(tiles);
}
