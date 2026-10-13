/*
 * function: func_021F51E4
 * address: 0x021F51E4
 * packet: pkt_ov194_021F51E4
 * region: ov194
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   func_02030734 0x02030734 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   CLACT_TransferCharacterPart 0x0204AA94 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020862F0 0x020862F0 arm
 *   CLACT_GetActorPaletteProxy 0x0204B764 arm
 *   func_02063800 0x02063800 arm
 *   func_0207E51C 0x0207E51C arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021F513C 0x021F513C thumb ov194
 *   d_021F57A8 0x021F57A8 data ov194 a1
 */
#include "../include/Obj14518.h"
#include "../include/Obj14519.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { int w[5]; } Palette;
extern void *func_020490F4(unsigned,u16);
struct ArcFile;
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern u8 *NNS_G3dGetTex(u8 *);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern u16 CLACT_GetActorCharacterIndex(u8 *);
extern void CLACT_TransferCharacterPart(int,void *,u32,int,int);
extern u32 func_020307B0(void *p);
extern void func_020862F0(void *,unsigned);
struct Struct20;
extern void CLACT_GetActorPaletteProxy(const char *src, struct Struct20 *dst);
extern int func_02063800(char *,int);
extern void func_0207E51C(void *,int,unsigned);
extern void func_0207E5D0(void *,int,unsigned);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_021F513C(const char *src, int width, int x, int y, int w, int h, char *dst);
extern const char d_021F57A8[];
static inline u8 *entry(u8 *p,u32 i) {
    if(p) {
        u8 *q=p+0x3c;
        if(q && i<((struct Obj14518 *)p)->f3D) {
                u16 off=((struct Obj14518 *)p)->f42;
                u16 stride=*(u16 *)(q+off);
                return q+off+4+stride*i;
        } else return 0;
    }
    return 0;
}
void func_021F51E4(u8 *dst,unsigned arc,u32 member,u32 index,u16 width,u16 height,int pos,int mode,u16 heap)
{
    Palette pal;
    u32 size=width*height*32;
    void *archive=func_020490F4(arc,heap);
    u8 *raw=ARC_TOOL_LoadHandleMember(archive,member,heap);
    u8 *tex=NNS_G3dGetTex(raw);
    u8 *pixels;
    u32 offset;
    offset=(*(u32 *)entry(tex,index)&0xffff)*8;
    pixels=tex+((struct Obj14519 *)tex)->f14;
    void *buf=func_02030734((u16)((heap&0x7fff)|0x8000),size,0,d_021F57A8,95);
    func_021F513C((const char *)(pixels+offset),width,0,0,width,height,buf);
    CLACT_TransferCharacterPart(CLACT_GetActorCharacterIndex(dst),buf,size,pos,mode);
    func_020307B0(buf);
    u32 poff=((struct Obj14519 *)tex)->f38;
    func_020862F0(tex+poff,32);
    CLACT_GetActorPaletteProxy((const char *)dst,(struct Struct20 *)(&pal));
    if(mode==0 || mode==2) func_0207E51C(tex+poff,func_02063800((char *)&pal,1),32);
    if(mode==1 || mode==2) func_0207E5D0(tex+poff,func_02063800((char *)&pal,2),32);
    func_020307B0(raw);
    ARC_TOOL_DeleteHandle(archive);
}
