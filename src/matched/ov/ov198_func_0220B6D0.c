/*
 * function: func_0220B6D0
 * address: 0x0220B6D0
 * packet: pkt_ov198_0220B6D0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: byte parameters, u32 dimensions and unsigned long byte-table offset.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0220B5AC 0x0220B5AC thumb ov198
 *   d_02211A74 0x02211A74 data a4
 *   d_02212540 0x02212540 data a4
 */
#include "../include/Obj25125.h"
#include "../include/Obj25126.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Rect { u8 x,y,w,h; } Rect;
extern const Rect d_02211A74[];
extern char d_02212540[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern void func_02041090(u32,u32,u32,u32,u8,u8);
extern void func_02041B6C(u32);
extern void func_0220B5AC(u8 *,void *,u8,u8,u8);
void func_0220B6D0(u8 *p,u8 state,u8 flag,u8 mode)
{
    unsigned long off=state*4;
    u32 h=((const u8 *)d_02211A74)[off+3];
    u32 w=((const u8 *)d_02211A74)[off+2];
    void *buf=func_02030734((u16)((((struct Obj25126 *)(*(char * *)&((struct Obj25125 *)p)->f0))->f10&0x7FFF)|0x8000),w*h*2,0,d_02212540,0x205);
    func_0220B5AC(p,buf,state,flag,mode);
    func_02041090(6,(u32)buf,((const u8 *)d_02211A74)[off],((const u8 *)d_02211A74)[off+1],w,h);
    func_02041B6C(6);
    func_020307B0(buf);
}
