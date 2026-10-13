/*
 * function: func_021B8524
 * address: 0x021B8524
 * packet: pkt_ov106_021B8524
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041300 0x02041300 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021B8A28 0x021B8A28 thumb ov106
 */
#include "../include/Obj01390.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_02041300(u32,int,int,int,u8,u8,u8);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021B8A28(u32 *,u32,u32,u16);
void func_021B8524(u8 *p) {
    int i, y;
    func_02041300(p[0x548],0,0,0,32,24,0);
    func_02041300(p[0x54a],0,0,0,32,24,0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01390 *)p)->f568)),0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01390 *)p)->f56C)),0);
    for (i=((struct Obj01390 *)p)->f55C-1; i<((struct Obj01390 *)p)->f55C+10; i++) {
        if (i>=0 && i<((struct Obj01390 *)p)->f554) {
            y=(i-((struct Obj01390 *)p)->f55C)*3+4;
            if (y>=0 && y<=24)
                func_021B8A28((u32 *)(p+0x188+i*32),((struct Obj01390 *)p)->f568,p[0x548],(u16)y);
        }
    }
    for (i=((struct Obj01390 *)p)->f55C+4; i<((struct Obj01390 *)p)->f55C+17; i++) {
        if (i>=0 && i<((struct Obj01390 *)p)->f554) {
            y=(i-(((struct Obj01390 *)p)->f55C+4))*3;
            if (y>=0 && y<=24)
                func_021B8A28((u32 *)(p+0x188+i*32),((struct Obj01390 *)p)->f56C,p[0x54a],(u16)y);
        }
    }
}
