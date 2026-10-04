/*
 * function: func_021C9FC8
 * address: 0x021C9FC8
 * packet: pkt_ov128_021C9FC8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 */
#include "../include/Obj00329.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6AE4(u8 *,u32,u16,u16,u32,u32,u16,u32);
void func_021C9FC8(u8 *p,void *unused,u8 *q,u32 item,int x,int y,int color)
{
    func_02045CAC(((struct Obj00329 *)q)->f4,item,((struct Obj00329 *)q)->f20);
    func_0201F250(((struct Obj00329 *)q)->f0,(void *)(((struct Obj00329 *)q)->f1C),((struct Obj00329 *)q)->f20);
    func_021B6AE4(p,*(u32 *)&((struct Obj00329 *)q)->f34,x,y,((struct Obj00329 *)q)->f1C,*(u32 *)&((struct Obj00329 *)q)->f17C,color,0);
}
