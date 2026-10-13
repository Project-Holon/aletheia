/*
 * function: func_021B7DFC
 * address: 0x021B7DFC
 * packet: pkt_ov103_021B7DFC
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Pointer prototypes and an element pointer retain the zero copied from the loop counter; 2-byte padding follows.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   G3D_SYSTEM_CreateResourceArcHandle 0x02046E24 arm
 *   G3D_SYSTEM_CheckResourceType 0x02046F50 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_GetRenderObj 0x0204755C arm
 *   G3D_SYSTEM_CreateAnime 0x02047564 arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   NNS_G3dMdlSetMdlPolygonIDAll 0x0206E5EC arm
 *   func_0207ADC4 0x0207ADC4 arm
 */
#include "../include/Obj01708.h"
#include "../include/Obj10241.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void func_02082BCC(void *,int,int); extern void *G3D_SYSTEM_CreateResourceArcHandle(int,u16); extern int G3D_SYSTEM_CheckResourceType(void *,int); extern void G3D_SYSTEM_TransVramTexture(void *); extern void *G3D_SYSTEM_CreateRender(void *,unsigned,void *); extern int *G3D_SYSTEM_GetRenderObj(void *); extern void *G3D_SYSTEM_CreateAnime(void *,const void *,int); extern void *G3D_SYSTEM_CreateObject(void *,void *,int); extern void G3D_SYSTEM_EnableObjectAnime(void *,u16); extern void NNS_G3dMdlSetMdlPolygonIDAll(int,int); extern void func_0207ADC4(void *);
void func_021B7DFC(u8 *p, int a, const u16 *t, int c, int a4) {int i,j; void *d=0; int *q; u8 *e; func_02082BCC(p,0,0x60); ((struct Obj01708 *)p)->f0=G3D_SYSTEM_CreateResourceArcHandle(a,t[0]); if(G3D_SYSTEM_CheckResourceType(((struct Obj01708 *)p)->f0,2)){d=((struct Obj01708 *)p)->f0; G3D_SYSTEM_TransVramTexture(d);} if(G3D_SYSTEM_CheckResourceType(((struct Obj01708 *)p)->f0,1)) { i=0; ((struct Obj01708 *)p)->fC=G3D_SYSTEM_CreateRender(((struct Obj01708 *)p)->f0,0,d); q=G3D_SYSTEM_GetRenderObj(((struct Obj01708 *)p)->fC); for(;i<2;i++) {e=p+i*4; ((struct Obj10241 *)e)->f4=G3D_SYSTEM_CreateResourceArcHandle(a,t[i+1]); ((struct Obj10241 *)e)->f14=G3D_SYSTEM_CreateAnime(((struct Obj01708 *)p)->fC,((struct Obj10241 *)e)->f4,0);} ((struct Obj01708 *)p)->f10=G3D_SYSTEM_CreateObject(((struct Obj01708 *)p)->fC,p+20,2); for(j=0;j<2;j++)G3D_SYSTEM_EnableObjectAnime(((struct Obj01708 *)p)->f10,j); NNS_G3dMdlSetMdlPolygonIDAll(q[1],c); } func_0207ADC4(p+0x34); ((struct Obj01708 *)p)->f28=4096; ((struct Obj01708 *)p)->f2C=4096; ((struct Obj01708 *)p)->f30=4096; }
