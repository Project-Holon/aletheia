/*
 * function: func_021BBC34
 * address: 0x021BBC34
 * packet: pkt_ov099_021BBC34
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes r0 from empty hook020185F4 and void-declared0204B294; extern returns retain those live results.
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 */
#include "../include/Obj03731.h"
#include "../include/Obj07943.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 a,b,c; u8 d,e; } Rec;
extern u32 POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *, u32);
extern void *POKE_TOOL_GetBoxParam(void *);
extern u32 POKE_TOOL_GetGraphicIndex(void *);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern int POKE_TOOL_GetIconPalette(void *);
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void func_021BBC34(char *p, void *a, int k, u32 o)
{
    int i,n;
    char *base,*dst;
    void *mon;
    Rec rec;
    n = POKEPARTY_GetCount(a);
    for (i=0;i<n;i++) {
        base = p + k*4;
        mon = POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(a,i));
        rec.a = i*40+22;
        rec.b = 54;
        rec.c = 0;
        rec.d = 0;
        rec.e = 0;
        dst = base+i*4;
        *(int *)&((struct Obj07943 *)dst)->f118 = CLACT_RegisterCharacter((void *)o,POKE_TOOL_GetGraphicIndex(mon),0,0,0x21);
        *(u32 *)&((struct Obj07943 *)dst)->f150 = (u32)CLACT_CreateActor((void *)((struct Obj03731 *)p)->f110,((struct Obj07943 *)dst)->f118,*(u32 *)&((struct Obj03731 *)p)->f148,*(u32 *)&((struct Obj03731 *)p)->f14C,&rec,0,0x21);
        CLACT_SetActorPaletteOffset(((struct Obj07943 *)dst)->f150,POKE_TOOL_GetIconPalette(mon),1);
    }
}
