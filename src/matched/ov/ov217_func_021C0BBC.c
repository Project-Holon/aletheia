/*
 * function: RESEARCH_COMMON_CreateActor
 * address: 0x021C0BBC
 * packet: pkt_ov217_021C0BBC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: DBC reads only r0/r1; original r2 was an earlier local-store base, not a live reader input. B294 caller observes r0 despite legacy void return.
 * symbols:
 *   d_021C3F80 0x021C3F80 data a4
 *   RESEARCH_COMMON_GetClactUnit 0x021C0DBC thumb ov217
 *   RESEARCH_COMMON_GetResourceId 0x021C0DB4 thumb ov217
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00791.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Arg { s16 x,y,z; u8 a,b; };
struct Entry { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };
struct Obj;
extern const struct Entry d_021C3F80;
extern u32 RESEARCH_COMMON_GetClactUnit(void *, u32);
extern u32 RESEARCH_COMMON_GetResourceId(void *, u32);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *, u32);
void RESEARCH_COMMON_CreateActor(u8 *p)
{
    struct Arg arg;
    u32 a,b,c,d;
    arg.x=d_021C3F80.x; arg.y=d_021C3F80.y; arg.z=d_021C3F80.z;
    arg.a=d_021C3F80.a; arg.b=d_021C3F80.b;
    a=RESEARCH_COMMON_GetClactUnit(p,d_021C3F80.c);
    b=RESEARCH_COMMON_GetResourceId(p,d_021C3F80.d);
    c=RESEARCH_COMMON_GetResourceId(p,d_021C3F80.e);
    d=RESEARCH_COMMON_GetResourceId(p,d_021C3F80.f);
    *(u32 *)&((struct Obj00791 *)p)->f24=(u32)CLACT_CreateActor((void *)a,b,c,d,&arg,d_021C3F80.g,((struct Obj00791 *)p)->f0);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00791 *)p)->f24,1);
}
