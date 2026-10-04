/*
 * function: func_0220BF40
 * address: 0x0220BF40
 * packet: pkt_ov197_0220BF40
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * matching: naming unsigned index before the u8 palette settles r0/r2;
 *   unnamed repeated index loads differ in18 bytes. Callee uses u8 palette.
 * symbols:
 *   func_0202CE50 0x0202CE50 thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   d_0220DB44 0x0220DB44 data a1
 */
#include "../include/Obj01005.h"
typedef unsigned char u8;
struct Row { u8 a,b,c,d; };
extern const struct Row d_0220DB44[];
typedef signed int     s32;
typedef unsigned int   u32;
struct WinMgr;
extern void func_0202CE50(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
void func_0220BF40(char *p)
{
    if(((struct Obj01005 *)p)->f527) {
        switch(((struct Obj01005 *)p)->f524) {
        case 0: {
            unsigned index=((struct Obj01005 *)p)->f526;
            u8 color;
            color=2;
            if(index<10) color=5;
            func_0202CE50(((struct Obj01005 *)p)->f520,index,0,0,d_0220DB44[index].c,d_0220DB44[index].d,color);
            func_0202CC58(((struct Obj01005 *)p)->f520,((struct Obj01005 *)p)->f526);
            (((struct Obj01005 *)p)->f524)++;
            break;
        }
        case 1: {
            unsigned index;
            u8 color;
            if(((struct Obj01005 *)p)->f525==4) {
                index=((struct Obj01005 *)p)->f526;
                color=1;
                if(index<10) color=4;
                func_0202CE50(((struct Obj01005 *)p)->f520,index,0,0,d_0220DB44[index].c,d_0220DB44[index].d,color);
                func_0202CC58(((struct Obj01005 *)p)->f520,((struct Obj01005 *)p)->f526);
                ((struct Obj01005 *)p)->f525=0;
                (((struct Obj01005 *)p)->f524)++;
            } else (((struct Obj01005 *)p)->f525)++;
            break;
        }
        case 2:
            if(((struct Obj01005 *)p)->f525==1) {
                ((struct Obj01005 *)p)->f525=0;
                ((struct Obj01005 *)p)->f524=0;
                ((struct Obj01005 *)p)->f527=0;
            } else (((struct Obj01005 *)p)->f525)++;
            break;
        }
    }
}
