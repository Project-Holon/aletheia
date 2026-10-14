/*
 * function: GSYNC_DISP_CreateMonIconActor
 * address: 0x021D6458
 * packet: pkt_ov123_021D6458
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DA738 0x021DA738 data a4
 *   d_021DA748 0x021DA748 data a4
 *   func_020490F4 0x020490F4 arm
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj02181.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Pair { int a,b; };
struct Point { s16 x,y; u16 f4; u8 f6,f7; };
extern const struct Pair d_021DA738, d_021DA748;
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern u32 POKE_TOOL_GetGraphicIndex(void *mon);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern int POKE_TOOL_GetIconPalette(void *a0);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void ARC_TOOL_DeleteHandle(void *);
void GSYNC_DISP_CreateMonIconActor(struct Obj02181 *p, void *n, int i)
{
    struct Pair a = d_021DA738;
    struct Pair b = d_021DA748;
    struct Point pt;
    void *h;
    h = func_020490F4(7, p->f43C4);
    p->f40 = (void *)CLACT_RegisterCharacter(h,POKE_TOOL_GetGraphicIndex((void *)n),0,2,p->f43C4);
    if(i==0) { pt.x=a.b; pt.y=b.b; }
    else { pt.x=a.a; pt.y=b.a; }
    pt.f4=0; pt.f6=3; pt.f7=1;
    p->fA8 = CLACT_CreateActor((void *)p->fC,(unsigned int)p->f40,p->f28,p->f5C,&pt,(u16)i,p->f43C4);
    CLACT_SetActorAutoAnim(p->fA8,0);
    CLACT_SetActorDrawEnable(p->fA8,1);
    CLACT_SetActorPaletteOffset(p->fA8,POKE_TOOL_GetIconPalette(n),1);
    ARC_TOOL_DeleteHandle(h);
}
