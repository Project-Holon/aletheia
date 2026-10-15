/*
 * function: COMM_BTL_DEMO_MAIN_BindModelPalette
 * address: 0x021BA920
 * packet: pkt_ov213_021BA920
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   G3D_SYSTEM_GetObjectRender 0x02047788 arm
 *   G3D_SYSTEM_GetRenderTexRes 0x02047554 arm
 *   G3D_SYSTEM_GetRenderObj 0x0204755C arm
 *   G3D_SYSTEM_GetResourceTex 0x02047250 arm
 *   NNS_G3dReleaseMdlPltt 0x0206A67C arm
 *   NNS_G3dBindMdlPlttEx 0x0206A5B4 arm
 */
#include "../include/Obj25711.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int G3D_SYSTEM_GetObjectRender(int *),G3D_SYSTEM_GetRenderTexRes(int *),G3D_SYSTEM_GetRenderObj(int *);
extern int G3D_SYSTEM_GetResourceTex(char *);
extern void NNS_G3dReleaseMdlPltt(char *);
extern int NNS_G3dBindMdlPlttEx(char *,char *,u32,u32);
int COMM_BTL_DEMO_MAIN_BindModelPalette(int *p,u32 b,u32 c) { int *q; char *a,*h,*r; q=(int *)G3D_SYSTEM_GetObjectRender(p); a=(char *)G3D_SYSTEM_GetRenderTexRes(q); h=*(char * *)&((struct Obj25711 *)((char *)G3D_SYSTEM_GetRenderObj(q)))->f4; r=(char *)G3D_SYSTEM_GetResourceTex(a); NNS_G3dReleaseMdlPltt(h); return NNS_G3dBindMdlPlttEx(h,r,b,c)&1; }
