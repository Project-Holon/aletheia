/*
 * function: func_021F7878
 * address: 0x021F7878
 * packet: pkt_ov135_021F7878
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * func_0204B294 returns the object consumed by the subsequent calls and stores.
 * Matched ov135 neighbours prove its pointer request in the fifth slot.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B974 0x0204B974 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj00778.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 x,y,z; u8 a,b; } Pos;
extern void func_02082BCC(void *,u32,u32);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Actor;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B974(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021F7878(u8 *p)
{
    Pos pos;
    func_02082BCC(&pos,0,8);
    pos.x=0xA0;
    pos.y=0x20;
    ((struct Obj00778 *)p)->fBF8=func_0204B294(((struct Obj00778 *)p)->fBC0,(unsigned int)((struct Obj00778 *)p)->fBE8,(unsigned int)((struct Obj00778 *)p)->fBC8,(unsigned int)((struct Obj00778 *)p)->fBF0,&pos,0,0x48);
    func_0204B878(((struct Obj00778 *)p)->fBF8,12);
    func_0204B92C(((struct Obj00778 *)p)->fBF8,1);
    func_0204B974(((struct Obj00778 *)p)->fBF8);
    func_0204B3DC(((struct Obj00778 *)p)->fBF8,0);
    pos.x=0xE4;
    pos.y=0x75;
    ((struct Obj00778 *)p)->fD2C=func_0204B294(((struct Obj00778 *)p)->fBC0,(unsigned int)((struct Obj00778 *)p)->fBC4,(unsigned int)((struct Obj00778 *)p)->fBC8,(unsigned int)((struct Obj00778 *)p)->fBCC,&pos,0,0x48);
    func_0204B878(((struct Obj00778 *)p)->fD2C,0x26);
    func_0204B3DC(((struct Obj00778 *)p)->fD2C,0);
    pos.x=0x8C;
    ((struct Obj00778 *)p)->fD30=func_0204B294(((struct Obj00778 *)p)->fBC0,(unsigned int)((struct Obj00778 *)p)->fBC4,(unsigned int)((struct Obj00778 *)p)->fBC8,(unsigned int)((struct Obj00778 *)p)->fBCC,&pos,0,0x48);
    func_0204B878(((struct Obj00778 *)p)->fD30,0x27);
    func_0204B3DC(((struct Obj00778 *)p)->fD30,0);
}
