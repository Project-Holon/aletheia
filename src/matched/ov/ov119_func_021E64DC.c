/*
 * function: func_021E64DC
 * address: 0x021E64DC
 * packet: pkt_ov119_021E64DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
#include "../include/Obj05335.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Create;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern int POKE_TOOL_GetIconPalette(void *);
typedef unsigned int   u32;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void func_021E64DC(int p, int i, int j, int x, int y, void *q) {
    Create c;
    c.x=x; c.y=y; c.z=1; c.a=0; c.b=0;
    ((struct Obj05335 *)p)->fF20=(int)CLACT_CreateActor((void *)((struct Obj05335 *)p)->f9C4,*(int *)(p+i*20+j*4+0x9cc),((struct Obj05335 *)p)->f87C,((struct Obj05335 *)p)->f8AC,&c,1,((struct Obj05335 *)p)->f5F4);
    CLACT_SetActorPaletteOffset((struct Obj *)(((struct Obj05335 *)p)->fF20),POKE_TOOL_GetIconPalette(q),1);
}
