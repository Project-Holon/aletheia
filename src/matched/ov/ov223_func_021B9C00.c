/*
 * function: func_021B9C00
 * address: 0x021B9C00
 * packet: pkt_ov223_021B9C00
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021B95A0 0x021B95A0 thumb ov223
 *   func_021BC52C 0x021BC52C thumb ov223
 *   ICA_ANIME_SetCameraStatus 0x02011B8C thumb
 *   d_021BC790 0x021BC790 data a2
 */
#include "../include/Obj05573.h"
typedef unsigned short u16;
struct TableRow { u16 h[5]; };
extern const struct TableRow d_021BC790[];
extern int func_021B95A0(int,int);
extern unsigned func_021BC52C(unsigned char *p);
extern void ICA_ANIME_SetCameraStatus(void *,void *);
void func_021B9C00(char *p,unsigned index)
{
    u16 value;
    int coordinate;
    value=d_021BC790[index].h[0];
    if(value!=0) coordinate=(int)((float)(value<<12)+0.5f);
    else coordinate=(int)((float)(value<<12)-0.5f);
    func_021B95A0(*(int *)&((struct Obj05573 *)p)->f40,coordinate);
    ICA_ANIME_SetCameraStatus((void *)func_021BC52C(((struct Obj05573 *)p)->f14),((struct Obj05573 *)p)->f40);
    ((struct Obj05573 *)p)->f44=index;
    ((struct Obj05573 *)p)->f48=0;
    ((struct Obj05573 *)p)->f4C=value;
}
