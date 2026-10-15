/*
 * function: PSEL_CreateUnits
 * address: 0x021B9D9C
 * packet: pkt_ov223_021B9D9C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: bind the file table record before the sprite record to reproduce their address scheduling.
 * symbols:
 *   ids 0x021BC710 data a2
 *   banks 0x021BC6FC data a1
 *   motion 0x021BC7F0 data a1
 *   files 0x021BC73C data a1
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PSEL_GRAPHIC_GetClactBank 0x021BC520 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_CreateAffineActor 0x0204B324 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   _fgr 0x0209BBB0 arm
 *   _ffltu 0x0209BE04 arm
 *   _ffix 0x0209C494 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fdiv 0x0209CE10 arm
 */
#include "../include/Obj00211.h"
#include "../include/Obj01595.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Request {u16 x,y,z;u8 a,b;};
struct Desc {u16 x,y,z;u8 a,b;u16 c,d;u32 sx,sy;u16 e,f;};
typedef struct {u8 b[14];} Motion;
typedef struct {u8 b[5];} Files;
extern const u16 ids[];
extern const u8 banks[];
extern const Motion motion[];
extern const Files files[];
extern int POKEGRA_OpenHandle(int a0);
extern u32 POKEGRA_RegisterCgr(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern u32 POKEGRA_RegisterPalette(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern u32 POKEGRA_RegisterCellAnim(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(u32);
extern void MI_CpuFill8(void *,int,u32);
extern unsigned PSEL_GRAPHIC_GetClactBank(unsigned char *p);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern struct Obj *CLACT_CreateAffineActor(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
typedef signed int     s32;
extern void *func_020490F4(u32 id, u32 heap);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))
void PSEL_CreateUnits(char *p)
{
    struct Desc desc;
    struct Request request;
    u32 arc,other,id;
    char *r;
    const Files *f;
    u8 i,j;
    arc=POKEGRA_OpenHandle(((struct Obj00211 *)p)->f0);
    for(i=0;i<3;i++) {
        id=ids[i];r=p+i*148;
        ((struct Obj01595 *)r)->f54=POKEGRA_RegisterCgr(arc,id,0,0,0,0,0,0,1,((struct Obj00211 *)p)->f0);
        ((struct Obj01595 *)r)->f58=POKEGRA_RegisterPalette(arc,id,0,0,0,0,0,1,(u16)(banks[i]<<5),((struct Obj00211 *)p)->f0);
        ((struct Obj01595 *)r)->f5C=POKEGRA_RegisterCellAnim(id,0,0,0,0,0,0,1,((struct Obj00211 *)p)->f0);
    }
    ARC_TOOL_DeleteHandle(arc);
    for(j=0;j<3;j++) {
        MI_CpuFill8(&request,0,8);
        request.x=motion[j].b[0];request.y=motion[j].b[1];request.z=0;request.a=2;request.b=3;
        r=p+j*148;
        ((struct Obj01595 *)r)->f6C=(u32)CLACT_CreateActor((void *)PSEL_GRAPHIC_GetClactBank(((struct Obj00211 *)p)->f14),((struct Obj01595 *)r)->f54,((struct Obj01595 *)r)->f58,((struct Obj01595 *)r)->f5C,&request,1,((struct Obj00211 *)p)->f0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01595 *)r)->f6C,0);
    }
    other=(u32)func_020490F4(205,((struct Obj00211 *)p)->f0);
    for(i=0;i<3;i++) {
        f=files+i;
        r=p+i*148;
        ((struct Obj01595 *)r)->f60=CLACT_RegisterCharacter((void *)other,f->b[0],0,1,((struct Obj00211 *)p)->f0);
        ((struct Obj01595 *)r)->f68=CLACT_RegisterCellAnim((void *)other,f->b[2],f->b[3],((struct Obj00211 *)p)->f0);
    }
    ARC_TOOL_DeleteHandle(other);
    for(j=0;j<3;j++) {
        MI_CpuFill8(&desc,0,24);
        desc.x=motion[j].b[0];desc.y=motion[j].b[1];desc.z=0;desc.a=2;desc.b=3;desc.c=0;desc.d=0;
        desc.sx=FIX((float)motion[j].b[6]/16.0f);desc.sy=FIX((float)motion[j].b[6]/16.0f);
        desc.e=0;desc.f=1;
        r=p+j*148;
        ((struct Obj01595 *)r)->f70=(unsigned int)CLACT_CreateAffineActor(PSEL_GRAPHIC_GetClactBank(((struct Obj00211 *)p)->f14),((struct Obj01595 *)r)->f60,((struct Obj01595 *)r)->f58,((struct Obj01595 *)r)->f68,(u32)(&desc),1,((struct Obj00211 *)p)->f0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01595 *)r)->f70,0);
    }
    for(i=0;i<3;i++) {
        *(u16 *)(p+i*148+216)=0;
        *(u32 *)(p+i*148+220)=0;
        *(u32 *)(p+i*148+224)=0;
        *(u32 *)(p+i*148+228)=0;
    }
    ((struct Obj00211 *)p)->f210=0;((struct Obj00211 *)p)->f214=0;
}
