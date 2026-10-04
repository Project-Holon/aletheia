/*
 * function: func_021D5890
 * address: 0x021D5890
 * packet: pkt_ov123_021D5890
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045808 0x02045808 arm
 *   func_0207D658 0x0207D658 arm
 */
#include "../include/Obj01734.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Config { u32 size; u8 flag; u8 pad[3]; void *target; u32 mode; u8 x,y,z,w; } Config;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02045808(struct U16Vec *vec);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_0207D658(u32 addr, int plane, int brightness);
int func_021D5890(char *p,int mode)
{
    Config c;
    int result;
    c.size=((struct Obj01734 *)p)->fB0;
    c.flag=2;
    c.target=p+0x8c;
    switch (mode) {
    case 0: c.x=32; c.y=12; c.mode=1; break;
    case 1: c.x=32; c.y=24; c.mode=1; break;
    }
    c.z=13;
    c.w=3;
    ((struct Obj01734 *)p)->f8C=func_020457B0(100,((struct Obj01734 *)p)->fB0);
    func_02045CAC(((struct Obj01734 *)p)->f20,4,((struct Obj01734 *)p)->f8C);
    ((struct Obj01734 *)p)->f90=0x39e0;
    ((struct Obj01734 *)p)->f98=func_020457B0(100,((struct Obj01734 *)p)->fB0);
    func_02045CAC(((struct Obj01734 *)p)->f20,5,((struct Obj01734 *)p)->f98);
    ((struct Obj01734 *)p)->f9C=0x39e0;
    result=(int)func_02027778((struct TaskMenuTmpl *)(&c),((struct Obj01734 *)p)->fA4);
    func_02045808(((struct Obj01734 *)p)->f8C);
    func_02045808(((struct Obj01734 *)p)->f98);
    func_0207D658(0x04001050,9,-8);
    return result;
}
