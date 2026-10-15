/*
 * function: DEMO3D_CMDSYS_Create
 * address: 0x021BF7C0
 * packet: pkt_ov203_021BF7C0
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   DEMO3D_CMDSYS_Init 0x021BF8E8 thumb ov203
 *   DEMO3D_CMDSYS_Seek 0x021BF964 thumb ov203
 *   d_021C3D4C 0x021C3D4C data a4
 */
#include "../include/Obj10867.h"
typedef struct {unsigned short heap,alternate;int config;int ended;int done;int previous;int index;char flags[4];char *owner;int task;int text;int assets;int extra;} Context;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void DEMO3D_CMDSYS_Init(char *p);
extern int DEMO3D_CMDSYS_Seek(char *p, char *owner, int *index);
extern const char d_021C3D4C[];
Context *DEMO3D_CMDSYS_Create(char *owner,unsigned heap)
{
    Context *p;
    p=func_02030734(heap,0x30,1,d_021C3D4C,78);
    p->owner=owner;p->heap=heap;p->alternate=(heap&0x7FFF)|0x8000;
    p->config=((struct Obj10867 *)owner)->f78;p->previous=-1;
    DEMO3D_CMDSYS_Init((char *)p);
    p->ended=DEMO3D_CMDSYS_Seek((char *)p,owner,&p->index);
    return p;
}
