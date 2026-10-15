/*
 * function: CHIHOU_ZUKAN_AWARD_SetupTiles
 * address: 0x021B9B84
 * packet: pkt_ov221_021B9B84
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_GetCharOffset 0x02045768 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021BA2D8 0x021BA2D8 data a1
 */
#include "../include/Obj06724.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021BA2D8[];
extern void *func_02030734(u32,u32,int,const char*,u16);
extern u32 func_020307B0(void *p);
extern void BG_SYS_LoadPltt(u32,void*,u32,u32);
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u16 BMP_WIN_GetCharOffset(struct Descriptor *p);
extern void BG_SYS_DrawTile(u32,u32,u32,u32,u8,u8);
extern void func_020409B4(u32);
void CHIHOU_ZUKAN_AWARD_SetupTiles(char *p)
{
 u16 *tiles;
 u16 *buf;
 u16 index;
 unsigned long tile;
 u8 x,y;
 buf=func_02030734(((struct Obj06724 *)p)->f0,32,1,d_021BA2D8,0x391);
 index=0;
 buf[0]=0;
 buf[1]=0x256c;
 buf[2]=0x4a74;
 buf[3]=0;
 BG_SYS_LoadPltt(2,buf,32,480);
 func_020307B0(buf);
 BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct Obj06724 *)p)->f20),3);
 BMP_WIN_TransferChars(*(void* *)&((struct Obj06724 *)p)->f20);
 tiles=func_02030734(((struct Obj06724 *)p)->f0,1536,1,d_021BA2D8,0x3a2);
 tile=BMP_WIN_GetCharOffset(*(void* *)&((struct Obj06724 *)p)->f20)|0xf000;
 for(y=0;y<24;y++) for(x=0;x<32;x++) {tiles[index]=tile;index++;}
 BG_SYS_DrawTile(2,(u32)tiles,0,24,32,24);
 func_020409B4(2);
 func_020307B0(tiles);
}
