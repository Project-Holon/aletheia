/*
 * function: func_021BDB98
 * address: 0x021BDB98
 * packet: pkt_ov110_021BDB98
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * control-flow: inner hits 2/3 reach DC0A; outer states 2/3 preserve p for F4F8.
 * lever: preserve incoming r0 p at DA84/DA94 calls with their ignored pointer argument.
 * symbols:
 *   func_021BDA84 0x021BDA84 thumb ov110
 *   func_021BDA94 0x021BDA94 thumb ov110
 *   func_021BF680 0x021BF680 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021BF82C 0x021BF82C thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BF4F8 0x021BF4F8 thumb ov110
 *   func_021BF53C 0x021BF53C thumb ov110
 *   func_021BF608 0x021BF608 thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int func_021BDA84(u8 *);
extern int func_021BDA94(u8 *);
extern int func_021BF680(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_021BF82C(u8 *);
extern void func_021B9BEC(u8 *,int);
extern void func_021BF4F8(u8 *,u32);
extern void func_021BF53C(u8 *,u32 *);
extern void func_021BF608(u8 *,u32 *);
extern int func_021B9C74(unsigned int a);
extern void func_021BD7A0(u8 *,Handler);
extern int func_021BE4C0(u8 *,unsigned *);
int func_021BDB98(u8 *p,u32 *q)
{
    int hit;
    switch(*q) {
    case 0:
    case 1:
        if(((struct Obj00012 *)p)->f4==0) hit=func_021BDA84(p);
        else hit=func_021BDA94(p);
        switch(hit) {
        case 0:
            if(func_021BF680(p)) GFL_USE_PlaySeDefaultVolume(1356);
            else GFL_USE_PlaySeDefaultVolume(1367);
            *q=2;
            break;
        case 1:
            GFL_USE_PlaySeDefaultVolume(1361);
            *q=3;
            break;
        case 2:
        case 3:
            GFL_USE_PlaySeDefaultVolume(1356);
            func_021BF82C(p);
            ((struct Obj00012 *)p)->f4A=hit-2;
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
            *q=5;
            break;
        }
        break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 3: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 4: *q=0; break;
    case 5:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0);
        break;
    }
    return 0;
}
