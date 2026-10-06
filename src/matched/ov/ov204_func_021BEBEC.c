/*
 * function: func_021BEBEC
 * address: 0x021BEBEC
 * packet: pkt_ov204_021BEBEC
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02008550 0x02008550 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021BDD78 0x021BDD78 thumb ov204
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   init 0x021BFFCC data a2
 */
#include "../include/Obj00550.h"
#include "../include/Obj06672.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 v[12];} Init;
extern const Init init;
extern void *func_020490F4(u32,u16);
typedef unsigned char  u8;
struct Obj;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern unsigned func_021BDD78(char *p);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
int func_021BEBEC(char *p)
{
    Init local;
    void *arc;
    u32 i;
    char *row;
    arc=func_020490F4(170,((struct Obj00550 *)p)->f0);
    if(func_02008550(**(void ** *)&((struct Obj00550 *)p)->f4)==0){
        ((struct Obj00550 *)p)->f10B4=(void *)func_0204A6C8(arc,6,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10C0=(void *)func_0204ABF0(arc,7,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10CC=(void *)func_0204AF28(arc,5,4,((struct Obj00550 *)p)->f0);
    }else{
        ((struct Obj00550 *)p)->f10B4=(void *)func_0204A6C8(arc,10,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10C0=(void *)func_0204ABF0(arc,11,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10CC=(void *)func_0204AF28(arc,9,8,((struct Obj00550 *)p)->f0);
    }
    ((struct Obj00550 *)p)->f10B8=(void *)func_0204A6C8(arc,17,0,0,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10C4=(void *)func_0204ABF0(arc,18,0,32,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10D0=(void *)func_0204AF28(arc,16,15,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10BC=(void *)func_0204A6C8(arc,21,0,0,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10C8=(void *)func_0204ABF0(arc,22,0,64,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10D4=(void *)func_0204AF28(arc,20,19,((struct Obj00550 *)p)->f0);
    func_02049238(arc);
    local=init;
    for(i=0;i<3;i++){
        row=p+i*4;
        ((struct Obj06672 *)row)->f10A8=func_0204B294((void *)func_021BDD78(((struct Obj00550 *)p)->f14),(unsigned int)((struct Obj06672 *)row)->f10B4,(unsigned int)((struct Obj06672 *)row)->f10C0,(unsigned int)((struct Obj06672 *)row)->f10CC,(char *)&local+i*8,0,((struct Obj00550 *)p)->f0);
        func_0204B3DC(((struct Obj06672 *)row)->f10A8,0);
    }
    return 1;
}
