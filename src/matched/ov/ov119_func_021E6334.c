/*
 * function: func_021E6334
 * address: 0x021E6334
 * packet: pkt_ov119_021E6334
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * initialization: both coordinate arms initialize x/y; z/a/b are stored before creation.
 * domain: primary calls 021D9084, 021DD670 and 021E25FA prove i=0..1,j=0..2. Wrappers 021D90AC/C0/D4 supply j=0/1/2; 021DD428 returns -1 or 0..2 and caller rejects -1; 021E24E8 has bounded 2x3 loops. Table row i*3+j=0..5 and byte offset i*12+j*4=0..20.
 * interface: 0204B294's fifth full-word payload is a Create address; its body forwards unchanged to 0204CFDC's request pointer. r0 is consumed after that void-declared wrapper.
 * interface: 020185F0 is an empty forwarder; caller supplies r0 and consumes its unchanged pointer result at 021E6346.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021E62D4 0x021E62D4 thumb ov119
 *   d_021E7D70 0x021E7D70 data a4
 *   d_021E7DA0 0x021E7DA0 data a4
 *   POKE_TOOL_GetIconPalette  0x0201BBE8  thumb  arm9
 *   POKE_TOOL_Dummy  0x020185F0  thumb  arm9
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb  arm9
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { short x,y,z; u8 a,b; } Create;
extern const int d_021E7D70[6][2];
extern const int d_021E7DA0[6][2];
extern void *POKE_TOOL_Dummy(void *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_021E62D4(void *,int,int);
extern u32 POKE_TOOL_GetGraphicIndex(void *);
typedef signed int     s32;
struct Obj;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern int POKE_TOOL_GetIconPalette(void *);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void ARC_TOOL_DeleteHandle(int);
void func_021E6334(char *p,int i,int j,void *mon,int selected,u32 visible)
{
    Create c;
    void *q = POKE_TOOL_Dummy(mon);
    void *h = func_020490F4(7,((struct Obj00001 *)p)->f5F4);
    int n;
    func_021E62D4(p,i,j);
    if (selected) {
        c.x=d_021E7D70[i*3+j][0]; c.y=d_021E7D70[i*3+j][1]; n=0;
    } else {
        c.x=d_021E7DA0[i*3+j][0]; c.y=d_021E7DA0[i*3+j][1]; n=1;
    }
    c.z=1; c.a=16; c.b=1;
    *(int *)(p+0x1020+i*12+j*4) = CLACT_RegisterCharacter((void *)((u32)h),POKE_TOOL_GetGraphicIndex(q),0,n,((struct Obj00001 *)p)->f5F4);
    *(int *)(p+0x1008+i*12+j*4) = (int)CLACT_CreateActor((void *)((struct Obj00001 *)p)->f9C4,*(int *)(p+0x1020+i*12+j*4),*(int *)&((struct Obj00001 *)p)->f890,*(int *)&((struct Obj00001 *)p)->f8C0,&c,n,((struct Obj00001 *)p)->f5F4);
    CLACT_SetActorPaletteOffset((struct Obj *)(*(int *)(p+0x1008+i*12+j*4)),POKE_TOOL_GetIconPalette(q),1);
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)(p+0x1008+i*12+j*4),0);
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p+0x1008+i*12+j*4),visible);
    ARC_TOOL_DeleteHandle((int)h);
}
