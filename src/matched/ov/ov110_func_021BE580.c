/*
 * function: func_021BE580
 * address: 0x021BE580
 * packet: pkt_ov110_021BE580
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: BAF7C reads the selection still live in r1 from E6A6 through the ordinary-mode arm.
 * symbols:
 *   func_021BB054 0x021BB054 thumb ov110
 *   func_021BD868 0x021BD868 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BF82C 0x021BF82C thumb ov110
 *   func_021BAFAC 0x021BAFAC thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 *   func_021BEB44 0x021BEB44 thumb ov110
 *   func_021BAF7C 0x021BAF7C thumb ov110
 *   func_021BEB60 0x021BEB60 thumb ov110
 */
#include "../include/Obj00189.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int func_021BB054(u8 *);
extern void func_021BD868(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_021B9BEC(u8 *,int);
extern void func_021BF82C(u8 *);
extern int func_021BAFAC(u32 p);
extern int func_021BD894(u8 *,void *);
extern int func_021BEB44(u8 *);
extern void func_021BAF7C(unsigned p, int v);
extern int func_021BEB60(u8 *);
void func_021BE580(u8 *p,u32 *q)
{
    if((((struct Obj00189 *)p)->f34&8) && p[0x69]==1) {
        ((struct Obj00189 *)p)->f4C=252;
        if(func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C)) {
            func_021BD868(p);
            *q=2;
            return;
        }
        GFL_USE_PlaySeDefaultVolume(1367);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
        return;
    }
    if(((struct Obj00189 *)p)->f3C==0 || (((struct Obj00189 *)p)->f34&4)) {
        GFL_USE_PlaySeDefaultVolume(1355);
        p[0x69]^=1;
        func_021BF82C(p);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,25);
        *q=4;
        return;
    }
    if(((struct Obj00189 *)p)->f34&2) {
        if(p[0x69]==1 && func_021BAFAC((u32)(*(u8 * *)&((struct Obj00189 *)p)->f1C))) {
            ((struct Obj00189 *)p)->f50=((struct Obj00189 *)p)->f4C;
            *q=1;
            if(((struct Obj00189 *)p)->f4C!=253) {
                ((struct Obj00189 *)p)->f4C=253;
                func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
            }
            GFL_USE_PlaySeDefaultVolume(1363);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,32);
            func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
            return;
        }
        if(p[0x69]==1 && ((struct Obj00189 *)p)->f4C!=254) {
            ((struct Obj00189 *)p)->f4C=254;
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
        }
        GFL_USE_PlaySeDefaultVolume(1361);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,11);
        *(Handler *)&((struct Obj00189 *)p)->f28=func_021BD894;
        *q=2;
        return;
    }
    if(((struct Obj00189 *)p)->f34&1) {
        if(((struct Obj00189 *)p)->f4C==252) {
            if(func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C)) {
                func_021BD868(p);
                *q=2;
                return;
            }
            GFL_USE_PlaySeDefaultVolume(1367);
            return;
        } else if(((struct Obj00189 *)p)->f4C==253) {
            if(p[0x69]==1 && func_021BAFAC((u32)(*(u8 * *)&((struct Obj00189 *)p)->f1C))) {
                ((struct Obj00189 *)p)->f50=((struct Obj00189 *)p)->f4C;
                *q=1;
                GFL_USE_PlaySeDefaultVolume(1363);
                func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,32);
                func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C);
                func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(1367);
            return;
        } else if(((struct Obj00189 *)p)->f4C==254) {
            GFL_USE_PlaySeDefaultVolume(1361);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,11);
            *(Handler *)&((struct Obj00189 *)p)->f28=func_021BD894;
            *q=2;
            return;
        } else if(p[0x69]==0) {
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,33);
            if(func_021BEB44(p)) {
                func_021BD868(p);
                *q=2;
                return;
            }
            GFL_USE_PlaySeDefaultVolume(1367);
            return;
        } else {
            func_021BAF7C((unsigned int)(*(u8 * *)&((struct Obj00189 *)p)->f1C),((struct Obj00189 *)p)->f4C);
            GFL_USE_PlaySeDefaultVolume(1356);
            func_021BB054(*(u8 * *)&((struct Obj00189 *)p)->f1C);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,30);
            func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,33);
            return;
        }
    }
    if(func_021BEB60(p)) {
        GFL_USE_PlaySeDefaultVolume(1352);
        func_021B9BEC(*(u8 * *)&((struct Obj00189 *)p)->f14,18);
    }
}
