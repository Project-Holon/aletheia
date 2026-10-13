/*
 * function: func_021BE1B8
 * address: 0x021BE1B8
 * packet: pkt_ov110_021BE1B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: BABE8 forwards BC6DC's full-word getter result despite its legacy void declaration.
 * symbols:
 *   func_021BABE8 0x021BABE8 thumb ov110
 *   func_021BDB50 0x021BDB50 thumb ov110
 *   func_021BD740 0x021BD740 thumb ov110
 *   func_021BDAA4 0x021BDAA4 thumb ov110
 *   func_021BF680 0x021BF680 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BD6F8 0x021BD6F8 thumb ov110
 *   func_021BD6B4 0x021BD6B4 thumb ov110
 *   func_021BAC30 0x021BAC30 thumb ov110
 *   func_021BF82C 0x021BF82C thumb ov110
 *   func_021B9C90 0x021B9C90 thumb ov110
 *   func_021BF4F8 0x021BF4F8 thumb ov110
 *   func_021BF53C 0x021BF53C thumb ov110
 *   func_021BF608 0x021BF608 thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BE3B8 0x021BE3B8 thumb ov110
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 */
#include "../include/Obj00012.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef struct { s16 a; s8 b,c; } State;
typedef int (*Handler)(u8 *,void *);
extern int func_021BABE8(u8 *p);
extern int func_021BDB50(u32 *);
extern void func_021BD740(u8 *p, void *out, int v);
extern int func_021BDAA4(u8 *);
extern int func_021BF680(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_021B9BEC(u8 *,int);
extern void func_021BD6F8(State *,void *);
extern void func_021BD6B4(State *,void *);
extern void func_021BAC30(u8 *,int);
extern void func_021BF82C(u8 *);
extern int func_021B9C90(unsigned int a, int b);
extern void func_021BF4F8(u8 *,u32);
extern void func_021BF53C(u8 *,u32 *);
extern void func_021BF608(u8 *,u32 *);
extern int func_021B9C74(unsigned int a);
extern void func_021BD7A0(u8 *,Handler);
extern int func_021BE3B8(u8 *,u32 *);
extern int func_021BE4C0(u8 *,u32 *);
int func_021BE1B8(u8 *p,u32 *q)
{
    int hit;
    int index;
    switch(*q) {
    case 0:
        p[0x68]=func_021BABE8(*(u8 * *)&((struct Obj00012 *)p)->f14);
        *q=1;
    case 1:
    case 2:
        index=func_021BDB50((u32 *)p);
        if(index>-1) {
            ((struct Obj00012 *)p)->f4A=0;
            func_021BD740((u8 *)(p+0x64),p+8,index);
            func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
            GFL_USE_PlaySeDefaultVolume(1352);
            *q=3;
        } else {
            hit=func_021BDAA4(p);
            switch(hit) {
            case 0:
                if(func_021BF680(p)) GFL_USE_PlaySeDefaultVolume(1356);
                else GFL_USE_PlaySeDefaultVolume(1367);
                ((struct Obj00012 *)p)->f48=0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,8);
                *q=hit+4;
                break;
            case 1:
                GFL_USE_PlaySeDefaultVolume(1361);
                ((struct Obj00012 *)p)->f48=1;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,8);
                *q=hit+4;
                break;
            case 2:
            case 4:
                GFL_USE_PlaySeDefaultVolume(1636);
                ((struct Obj00012 *)p)->f4A=0;
                func_021BD6F8((State *)(p+0x64),p+8);
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
                func_021BAC30(*(u8 * *)&((struct Obj00012 *)p)->f14,0);
                *q=3;
                break;
            case 3:
            case 5:
                GFL_USE_PlaySeDefaultVolume(1636);
                ((struct Obj00012 *)p)->f4A=0;
                func_021BD6B4((State *)(p+0x64),p+8);
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,3);
                func_021BAC30(*(u8 * *)&((struct Obj00012 *)p)->f14,1);
                *q=3;
                break;
            case 6:
            case 7:
                GFL_USE_PlaySeDefaultVolume(1356);
                func_021BF82C(p);
                ((struct Obj00012 *)p)->f4A=hit-6;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10);
                *q=8;
                break;
            }
        }
        break;
    case 3: if(func_021B9C90((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14),3)) *q=0; break;
    case 4: *q=6; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 5: *q=6; func_021BF4F8(p,(u32)func_021BF608); break;
    case 6: *q=2; break;
    case 7: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE3B8); break;
    case 8: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0); break;
    }
    return 0;
}
