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
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021BAC78 0x021BAC78 thumb ov110
 *   func_021BD0F8 0x021BD0F8 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj01249.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { void *root; u8 pad[0x6c]; void *items[8]; } Object;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_021BAC64(void *,void *,int,int);
typedef signed int     s32;
struct Obj;
extern s32 CLACT_RegisterCharacter(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *func_021BAC78(char *p, unsigned int *r, short x, short y, unsigned int a, int mode);
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
    ((struct Obj01249 *)p)->f14=(void *)CLACT_RegisterCharacter(h,13,0,0,42);
    ((struct Obj01249 *)p)->f18=(void *)CLACT_RegisterCellAnim(h,35,41,42);
    ARC_TOOL_DeleteHandle(h);
    for(i=0;i<8;i++) {
        x=24*i;
        if(i==7) x=0;
        p->items[i]=func_021BAC78(p->root,(unsigned int *)((u8 *)p+0x10),x,168,0,1);
        func_021BD0F8((u8 *)p,i,0);
        func_0204B3DC(p->items[i],0);
    }
}
