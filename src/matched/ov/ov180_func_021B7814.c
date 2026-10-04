/*
 * function: func_021B7814
 * address: 0x021B7814
 * packet: pkt_ov180_021B7814
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: paired Grid/Bmp holder pointer formed before allocation preserves
 *   the destination across the call; direct raw stores were eight bytes short.
 * symbols:
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_021B77DC 0x021B77DC thumb ov180
 */
#include "../include/Obj00547.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
struct Bmp; struct Sys; struct Grid; struct CharBuf; struct MsgBank; struct U16Vec;
typedef struct { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; } Param;
typedef struct { struct Grid *grid; struct Bmp *bmp; } Holder;
extern struct Bmp *func_02043678(u32,u32,u32,u32);
extern struct Grid *func_020255A0(struct Sys *,const Param *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *);
extern void func_021B77DC(char *,int,void *,struct U16Vec *,s16,s16);
void func_021B7814(char *p) {
    Param d;
    struct U16Vec *s;
    Holder *h;
    d.f8=*(u32 *)&((struct Obj00547 *)p)->f90F0; d.fc=0;
    d.f10=4; d.f11=0; d.f12=0xffff; d.f14=0;
    h=(Holder *)(p+0x9120);
    h->bmp=func_02043678(22,2,32,141);
    d.bmp=h->bmp; d.x=-184; d.y=16;
    *(struct Grid * *)&((struct Obj00547 *)p)->f9120=func_020255A0(*(struct Sys * *)&((struct Obj00547 *)p)->f911C,&d);
    func_02043B5C(*(struct CharBuf * *)&((struct Obj00547 *)p)->f9124,0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct Obj00547 *)p)->f9038,0);
    func_021B77DC(p,0,((struct Obj00547 *)p)->f9030,s,12,0);
    func_02045808(s);
    h=(Holder *)(p+0x9128);
    h->bmp=func_02043678(22,2,32,141);
    d.bmp=h->bmp; d.x=264; d.y=160;
    *(struct Grid * *)&((struct Obj00547 *)p)->f9128=func_020255A0(*(struct Sys * *)&((struct Obj00547 *)p)->f911C,&d);
}
