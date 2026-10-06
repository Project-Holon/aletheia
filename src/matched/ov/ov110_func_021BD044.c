/*
 * function: func_021BD044
 * address: 0x021BD044
 * packet: pkt_ov110_021BD044
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_021BAC64 0x021BAC64 thumb ov110
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_021BD0F8 0x021BD0F8 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj01249.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { void *root; u8 pad[0x6c]; void *items[8]; } Object;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_021BAC64(void *,void *,int,int);
extern void *func_0204A6C8(void *,int,int,int,u16);
extern void *func_0204AF28(void *,int,int,u16);
extern void func_02049238(void *);
extern void *func_021BAC78(void *,void *,int,int,int,int);
extern void func_021BD0F8(u8 *p, int i, int flag);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021BD044(Object *p) {
    void *h;
    int i;
    s16 x;
    h=func_020490F4(43,42);
    func_021BAC64(p->root,(u8 *)p+0x10,0,0);
    ((struct Obj01249 *)p)->f14=func_0204A6C8(h,13,0,0,42);
    ((struct Obj01249 *)p)->f18=func_0204AF28(h,35,41,42);
    func_02049238(h);
    for(i=0;i<8;i++) {
        x=24*i;
        if(i==7) x=0;
        p->items[i]=func_021BAC78(p->root,(u8 *)p+0x10,x,168,0,1);
        func_021BD0F8((u8 *)p,i,0);
        func_0204B3DC(p->items[i],0);
    }
}
