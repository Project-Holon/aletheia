/*
 * function: func_021BE934
 * address: 0x021BE934
 * packet: pkt_ov110_021BE934
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: E800/E8B4/E890 receive the object visibly loaded by this caller.
 * symbols:
 *   func_021BE7B8 0x021BE7B8 thumb ov110
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   func_021BD894 0x021BD894 thumb ov110
 *   func_021BF82C 0x021BF82C thumb ov110
 *   func_021BE800 0x021BE800 thumb ov110
 *   func_021B999C 0x021B999C thumb ov110
 *   func_021BD868 0x021BD868 thumb ov110
 *   func_021BE8B4 0x021BE8B4 thumb ov110
 *   func_021BAF7C 0x021BAF7C thumb ov110
 *   func_021BB054 0x021BB054 thumb ov110
 *   func_021BE890 0x021BE890 thumb ov110
 *   func_021BAFAC 0x021BAFAC thumb ov110
 */
#include "../include/Obj00586.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Handler)(u8 *,void *);
extern int func_021BE7B8(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_021B9BEC(u8 *,int);
extern int func_021BD894(u8 *,void *);
extern void func_021BF82C(u8 *);
extern int func_021BE800(u8 *);
extern u32 func_021B999C(u8 *,int);
extern void func_021BD868(u8 *);
extern int func_021BE8B4(u8 *);
extern void func_021BAF7C(unsigned p, int v);
extern int func_021BB054(u8 *);
extern int func_021BE890(void *a0);
extern int func_021BAFAC(u32 p);
void func_021BE934(u8 *p,u32 *q)
{
    int r;
    switch(func_021BE7B8(p)) {
    case 1:
        GFL_USE_PlaySeDefaultVolume(1361);
        func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,11);
        *(Handler *)&((struct Obj00586 *)p)->f28=func_021BD894;
        *q=2;
        return;
    case 2:
        GFL_USE_PlaySeDefaultVolume(1355);
        p[0x69]^=1;
        func_021BF82C(p);
        func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,25);
        *q=4;
        return;
    }
    if(p[0x69]==0) {
        r=func_021BE800(p);
        if(r>=0) {
            ((struct Obj00586 *)p)->f4C=r;
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,33);
            if(r>=12 || !func_021B999C(*(u8 * *)&((struct Obj00586 *)p)->f18,((struct Obj00586 *)p)->f4C)) {
                GFL_USE_PlaySeDefaultVolume(1367);
                return;
            }
            func_021BD868(p);
            *q=2;
            return;
        }
    } else {
        r=func_021BE8B4(p);
        if(r>-1) {
            ((struct Obj00586 *)p)->f4C=r;
            func_021BAF7C((unsigned int)(*(u8 * *)&((struct Obj00586 *)p)->f1C),((struct Obj00586 *)p)->f4C);
            func_021BB054(*(u8 * *)&((struct Obj00586 *)p)->f1C);
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,30);
            GFL_USE_PlaySeDefaultVolume(1356);
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,33);
            return;
        }
        switch(func_021BE890(p)) {
        case 0:
            ((struct Obj00586 *)p)->f4C=252;
            if(func_021BB054(*(u8 * *)&((struct Obj00586 *)p)->f1C)) {
                func_021BD868(p);
                *q=2;
                return;
            } else {
                GFL_USE_PlaySeDefaultVolume(1367);
                return;
            }
        case 1:
            ((struct Obj00586 *)p)->f4C=253;
            if(func_021BAFAC((u32)(*(u8 * *)&((struct Obj00586 *)p)->f1C))) {
                ((struct Obj00586 *)p)->f50=((struct Obj00586 *)p)->f4C;
                *q=1;
                GFL_USE_PlaySeDefaultVolume(1363);
                func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,32);
                func_021BB054(*(u8 * *)&((struct Obj00586 *)p)->f1C);
                func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,30);
                return;
            } else {
                GFL_USE_PlaySeDefaultVolume(1367);
                return;
            }
        case 2:
            ((struct Obj00586 *)p)->f4C=254;
            GFL_USE_PlaySeDefaultVolume(1361);
            func_021B9BEC(*(u8 * *)&((struct Obj00586 *)p)->f14,11);
            *(Handler *)&((struct Obj00586 *)p)->f28=func_021BD894;
            *q=2;
            break;
        case -1:
            break;
        }
    }
}
