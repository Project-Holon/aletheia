/*
 * function: ZUKAN_DETAIL_COMMON_RequestFade
 * address: 0x021BC7B4
 * packet: pkt_ov208_021BC7B4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_RequestFade 0x0202173C thumb
 */
#include "../include/Obj02252.h"
extern int PALANM_RequestFade(void *,unsigned short,unsigned short,short,unsigned char,unsigned char,unsigned short,void *);
void ZUKAN_DETAIL_COMMON_RequestFade(char *p,short b,unsigned char c,unsigned char d)
{
    if(((struct Obj02252 *)p)->fC&1)PALANM_RequestFade(((struct Obj02252 *)p)->f8,1,0x1fff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&4)PALANM_RequestFade(((struct Obj02252 *)p)->f8,4,0xff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&2)PALANM_RequestFade(((struct Obj02252 *)p)->f8,2,0x1fff,b,c,d,0,((struct Obj02252 *)p)->f0);
    if(((struct Obj02252 *)p)->fC&8)PALANM_RequestFade(((struct Obj02252 *)p)->f8,8,0x3fff,b,c,d,0,((struct Obj02252 *)p)->f0);
}
