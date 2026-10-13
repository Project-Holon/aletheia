/*
 * function: func_021B6C70
 * address: 0x021B6C70
 * packet: pkt_ov174_021B6C70
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02005728 0x02005728 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_021B7004 0x021B7004 thumb ov174
 *   func_021B6F3C 0x021B6F3C thumb ov174
 *   func_021B71B8 0x021B71B8 thumb ov174
 *   d_021B74BC 0x021B74BC data
 */
#include "../include/Obj01422.h"
#include "../include/Obj01759.h"
#include "../include/Obj24205.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02005728(u32 range);
extern u8 *GAME_DATA_GetMyStatus(void *p);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_021B7004(u8 *p, u8 *q);
extern void func_021B6F3C(char *p, u8 *q);
extern void func_021B71B8(u8 *p, u8 *q);
extern char d_021B74BC[];
char *func_021B6C70(char *p,int index)
{
    char *q;
    if((*(u8 **)(p+0x3c))[index]==0xff) return 0;
    q=func_02030734(((struct Obj01422 *)p)->f0,0x3c,0,d_021B74BC,0x7a);
    ((struct Obj01759 *)q)->f0=index;
    ((struct Obj01759 *)q)->f2=(*(u8 **)(p+0x3c))[index];
    ((struct Obj01759 *)q)->f3=(*(u8 * *)&((struct Obj01422 *)p)->f3C+index)[4];
    ((struct Obj01759 *)q)->f4=0;
    ((struct Obj01759 *)q)->f5=0;
    ((struct Obj01759 *)q)->f14=0;
    ((struct Obj01759 *)q)->f34=0;
    ((struct Obj01759 *)q)->f30=func_02005728(0x4b);
    if(((struct Obj01759 *)q)->f2==0 && func_02008550((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct Obj24205 *)(*(char * *)&((struct Obj01422 *)p)->f30))->f4))==1) ((struct Obj01759 *)q)->f2=5;
    func_021B7004((u8 *)p,(u8 *)q);
    func_021B6F3C(p,(u8 *)q);
    func_021B71B8((u8 *)p,(u8 *)q);
    ((struct Obj01759 *)q)->f8=0;
    ((struct Obj01759 *)q)->f10=0;
    ((struct Obj01759 *)q)->f6=func_02005728(40);
    ((struct Obj01759 *)q)->f38=0;
    return q;
}
