/*
 * function: func_02203FA0
 * address: 0x02203FA0
 * packet: pkt_ov195_02203FA0
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 0203159C and 02031324 own files return void; caller consumes r0.
 * ABI: 02031324 also receives the heap in r0, preserved in this extern.
 * symbols:
 *   sub_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   sub_0201AB28 0x0201AB28 thumb
 *   sub_020457B0 0x020457B0 arm
 *   func_02017E1C 0x02017E1C thumb
 *   sub_02030734 0x02030734 arm
 *   func_0204E720 0x0204E720 arm
 *   func_02204DC4 0x02204DC4 thumb ov195
 *   sub_020056A0 0x020056A0 thumb
 *   func_022051A8 0x022051A8 thumb ov195
 *   func_02031324 0x02031324 arm
 *   func_02204C24 0x02204C24 thumb ov195
 *   func_0203D34C 0x0203D34C arm
 *   d_02208F40 0x02208F40 data a4
 */
#include "../include/Obj00734.h"
#include "../include/Obj05515.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Obj0203159C;
struct U16Vec;
struct App;
struct Scene;
extern void sub_0203064C(u32 src, u32 dst, u32 size);
extern char *func_0203159C(struct Obj0203159C *,u32,u32);
extern void func_02082BCC(void *,u32,u32);
extern void *sub_0201AB28(void *,u32);
extern struct U16Vec *sub_020457B0(u32,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void *sub_02030734(u32,u32,int,const char *,u16);
extern void func_0204E720(u32,int,int,int);
extern void func_02204DC4(u8 *,u8 *);
extern void *sub_020056A0(u32,u32,u32);
extern void func_022051A8(int task, char *p);
extern u32 func_02031324(u16);
extern void func_02204C24(struct App *,struct Scene *);
extern void func_0203D34C(u32,u32);
extern const char d_02208F40[];
int func_02203FA0(struct Obj0203159C *owner,int unused,u8 *app)
{
    char *p;
    sub_0203064C(1,0x94,0x10000);
    p=func_0203159C(owner,0x120,0x94);
    func_02082BCC(p,0,0x120);
    ((struct Obj00734 *)p)->f0=0x94;
    ((struct Obj00734 *)p)->f28=0;
    ((struct Obj00734 *)p)->f2C=5;
    ((struct Obj00734 *)p)->f30=0;
    ((struct Obj00734 *)p)->f10=sub_0201AB28(((struct Obj05515 *)app)->f4,app[0xa]);
    *(struct U16Vec * *)&((struct Obj00734 *)p)->f14=sub_020457B0(0x100,((struct Obj00734 *)p)->f0);
    func_02017E1C(((struct Obj00734 *)p)->f10,0x73,*(u32 *)&((struct Obj00734 *)p)->f14);
    ((struct Obj00734 *)p)->f24=0;
    ((struct Obj00734 *)p)->fA0=0;
    ((struct Obj00734 *)p)->fA4=0;
    ((struct Obj00734 *)p)->fA8=0;
    ((struct Obj00734 *)p)->fAC=0;
    ((struct Obj00734 *)p)->f100=sub_02030734(((struct Obj00734 *)p)->f0,0x28,1,d_02208F40,0x242);
    func_0204E720(3,16,16,-16);
    func_02204DC4(app,(u8 *)p);
    ((struct Obj00734 *)p)->f38=sub_020056A0((u32)func_022051A8,(u32)p,1);
    ((struct Obj00734 *)p)->f10C=0;
    ((struct Obj00734 *)p)->f110=0;
    ((struct Obj00734 *)p)->f114=0;
    ((struct Obj00734 *)p)->f118=0;
    ((struct Obj00734 *)p)->f11C=func_02031324(((struct Obj00734 *)p)->f0);
    func_02204C24((struct App *)app,(struct Scene *)p);
    func_0203D34C(0,((struct Obj00734 *)p)->f0);
    return 1;
}
