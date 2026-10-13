/*
 * function: func_021B9CC8
 * address: 0x021B9CC8
 * packet: pkt_ov181_021B9CC8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x021B9D02.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Blit 0x020439A0 arm
 */
#include "../include/Obj14408.h"
struct Bmp;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Blit(struct Bmp *,struct Bmp *,unsigned,unsigned,int,int,unsigned,unsigned,unsigned);
void func_021B9CC8(char *p){struct Bmp *s=BMP_WIN_GetBmp(((struct Obj14408 *)p)->f2C4);BMP_Blit(*(struct Bmp **)((unsigned)p+((struct Obj14408 *)p)->f2BB*8+0xb8),s,0,0,0,192,256,16,0);}
