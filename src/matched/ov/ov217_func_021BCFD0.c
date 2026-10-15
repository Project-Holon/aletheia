/*
 * function: RESEARCH_LIST_CreateActors
 * address: 0x021BCFD0
 * packet: pkt_ov217_021BCFD0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: const source table and destination base without the field offset.
 * symbols:
 *   d_021C320C 0x021C320C data a4
 *   RESEARCH_LIST_GetClactUnit 0x021BC714 thumb ov217
 *   RESEARCH_LIST_GetResourceId 0x021BC708 thumb ov217
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj14733.h"
#include "../include/Obj25882.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Arg { s16 x,y,z; u8 a,b; };
struct Entry { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };
extern const struct Entry d_021C320C[];
extern u32 RESEARCH_LIST_GetClactUnit(void *,u32);
extern u32 RESEARCH_LIST_GetResourceId(void *,u32);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
void RESEARCH_LIST_CreateActors(u8 *p)
{
    struct Arg arg;
    const struct Entry *q;
    u8 *dest;
    int i;
    u32 a,b,c,d;
    for (i=0;i<3;i++) {
        q=&d_021C320C[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=RESEARCH_LIST_GetClactUnit(p,q->c);
        b=RESEARCH_LIST_GetResourceId(p,q->d);
        c=RESEARCH_LIST_GetResourceId(p,q->e);
        d=RESEARCH_LIST_GetResourceId(p,q->f);
        dest=p+i*4;
        ((struct Obj14733 *)dest)->f120=(u32)CLACT_CreateActor((void *)a,b,c,d,&arg,q->g,((struct Obj25882 *)p)->f8);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj14733 *)dest)->f120,0);
    }
}
