/*
 * function: PSEL_SelectUnit
 * address: 0x021B9C90
 * packet: pkt_ov223_021B9C90
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_DisableObjectAnime 0x020477D4 arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   CLACT_SetActorAnimIndex 0x0204B908 arm
 */
#include "../include/Obj02938.h"
typedef unsigned short u16;
typedef unsigned char  u8;
extern unsigned int func_02048A18(u8 *a0, int i);
typedef signed int     s32;
typedef unsigned int   u32;
struct AnmCtl;
struct G3dSys;
struct Owner;
extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);
extern int G3D_SYSTEM_DisableObjectAnime(struct Owner *owner, u32 index);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
/* B908 reads only r0, forwarding its live r1 to D478; legacy r2/r3 unused. */
extern void CLACT_SetActorAnimIndex(int a0, int a1);
void PSEL_SelectUnit(char *p,unsigned next)
{
    void *object;
    unsigned count;
    u16 i;
    int frame;
    if(((struct Obj02938 *)p)->f22C!=4 && ((struct Obj02938 *)p)->f22C!=next) {
        object=(void *)func_02048A18(((struct Obj02938 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj02938 *)p)->f3C+68*(*(u16 *)(p+48+2*(((struct Obj02938 *)p)->f22C+2)))));
        count=G3D_SYSTEM_GetObjectAnimeCount(object);
        for(i=0;i<count;i++) G3D_SYSTEM_DisableObjectAnime(object,i);
    }
    if(next!=4 && ((struct Obj02938 *)p)->f22C!=next) {
        object=(void *)func_02048A18(((struct Obj02938 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj02938 *)p)->f3C+68*(*(u16 *)(p+48+2*(next+2)))));
        count=G3D_SYSTEM_GetObjectAnimeCount(object);
        frame=0;
        for(i=0;i<count;i++) {
            G3D_SYSTEM_EnableObjectAnime(object,i);
            G3D_SYSTEM_SetObjectAnimeFrame(object,i,&frame);
        }
        CLACT_SetActorAnimIndex((int)(((struct Obj02938 *)p)->f224),0);
    }
    ((struct Obj02938 *)p)->f22C=next;
}
