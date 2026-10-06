/*
 * function: func_021B6594
 * address: 0x021B6594
 * packet: pkt_ov174_021B6594
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020498F4 0x020498F4 arm
 *   func_02012944 0x02012944 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../include/Obj00545.h"
#include "../include/Obj24199.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u16 x,y,z; u8 a,b; } Spec;
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
typedef signed int     s32;
struct Obj;
struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204ACEC(void *,u32,u32,u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021B6594(u8 *p)
{
    int id=37;
    void *save;
    void *arc;
    Spec s;
    if(((struct Obj00545 *)p)->f8!=2) id=38;
    func_020498F4(((struct Obj00545 *)p)->f18,id,2,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(((struct Obj00545 *)p)->f18,id,3,0,0,0,((struct Obj00545 *)p)->f0);
    save=func_02012944(((struct Obj24199 *)(*(u8 * *)&((struct Obj00545 *)p)->f30))->f4);
    arc=func_020490F4(172,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f44=func_0204ACEC(arc,3,0,0,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f48=func_0204A6C8(arc,24,0,0,((struct Obj00545 *)p)->f0);
    *(int *)&((struct Obj00545 *)p)->f4C=func_0204AF28(arc,20,22,((struct Obj00545 *)p)->f0);
    if(func_02008550(save)==0) func_02049B68(arc,7,4,0,0x60,((struct Obj00545 *)p)->f0);
    else func_02049B68(arc,6,4,0,0x60,((struct Obj00545 *)p)->f0);
    func_02049658(arc,11,7,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(arc,14,7,0,0,0,((struct Obj00545 *)p)->f0);
    func_020409B4(7);
    func_02049B68(arc,0,0,0x160,0x20,((struct Obj00545 *)p)->f0);
    func_02049658(arc,8,1,0,0,0,((struct Obj00545 *)p)->f0);
    func_020498F4(arc,13,1,0,0,0,((struct Obj00545 *)p)->f0);
    func_020413B0(1,0,0,32,32,11);
    func_020409B4(1);
    func_02049238(arc);
    s.a=10; s.b=1; s.x=0;s.y=0;s.z=0;
    ((struct Obj00545 *)p)->f54=func_0204B294((void *)((struct Obj00545 *)p)->f50,((struct Obj00545 *)p)->f48,((struct Obj00545 *)p)->f44,((struct Obj00545 *)p)->f4C,&s,0,((struct Obj00545 *)p)->f0);
    func_0204B3DC(((struct Obj00545 *)p)->f54,0);
    func_0204B92C(((struct Obj00545 *)p)->f54,1);
}
