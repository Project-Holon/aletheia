/*
 * function: POKETRADE_SAVE_CreateStatusIconActor
 * address: 0x021E0E68
 * packet: pkt_ov119_021E0E68
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021E0EF2, labelled next function 0x021E0EF4.
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKETRADE_SAVE_DeleteStatusIconActor 0x021E0E4C thumb ov119
 *   func_020275E4 0x020275E4 thumb
 *   func_02027720 0x02027720 thumb
 *   func_0202772C 0x0202772C thumb
 *   func_02027738 0x02027738 thumb
 *   func_02027740 0x02027740 thumb
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 */
#include "../include/Obj08064.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Descriptor {int a,b,c,d,e,f,g;u8 h,i,j,k;} Descriptor;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKETRADE_SAVE_DeleteStatusIconActor(char *p);
extern u32 func_020275E4(void);
extern int func_02027720(int);
extern int func_0202772C(int);
extern int func_02027738(int,int);
extern int func_02027740(int,int);
extern void UI_SCENE_LoadActorGfx(void *,Descriptor *,int,u16);
extern int UI_SCENE_CreateActor(void *,int,u8,u8,u8,u16);
void POKETRADE_SAVE_CreateStatusIconActor(char *p,void *mon,int slot,int x,int y,int a,u16 b,int c) {Descriptor d;int v;v=POKE_TOOL_GetPartyValue(mon,152,0);POKETRADE_SAVE_DeleteStatusIconActor(p);d.a=a;d.b=0;d.c=func_020275E4();d.d=func_02027720(v);d.e=func_0202772C(v);d.f=func_02027738(v,2);d.g=func_02027740(v,2);d.h=c;d.i=0;d.j=1;UI_SCENE_LoadActorGfx(p,&d,slot,b);*(int *)&((struct Obj08064 *)p)->f10=UI_SCENE_CreateActor(p,slot,x,y,0,b);}
