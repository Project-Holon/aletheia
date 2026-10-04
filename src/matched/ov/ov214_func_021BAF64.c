/*
 * unit: yes
 * function: func_021BAF64,func_021BB0C4
 * address: 0x021BAF64
 * packet: pkt_ov214_021BAF64
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 0202173C's third parameter is widened to the observed full-word
 *   caller payload; own u16 declaration inserted four extra truncation pairs.
 *   Both fixed-flag TU runs preserve its low-halfword colour; widening gives EXACT368.
 * extent: lead and tail-call follower 021BB0C4.
 * symbols:
 *   func_02030D28 0x02030D28 arm
 *   func_02021ED8 0x02021ED8 thumb
 *   func_0202173C 0x0202173C thumb
 *   func_02021D50 0x02021D50 thumb
 */
#include "../include/Obj25729.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct PalAnmObj; struct S02021D50;
struct S { u8 pad[0x2D8]; void *heap; u32 unused2DC; char *anm; u32 request,state; };
struct Ctx;
extern void func_02030D28(struct Ctx *c);
extern u32 func_02021ED8(const char *);
extern int func_0202173C(struct PalAnmObj *,u16,u32,s16,u8,u8,u16,void *);
extern void func_02021D50(struct S02021D50 *);
void func_021BAF64(void *unused,struct S *p)
{
    u32 mask;
    u8 i;
    func_02030D28(p->heap);
    if (func_02021ED8(p->anm)!=0) return;
    switch (p->state) {
    case 1: p->state=2; break;
    case 3: p->state=0; break;
    }
    switch (p->request) {
    case 1:
        if (p->state==1) return;
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        func_0202173C((struct PalAnmObj *)p->anm,1,mask,-2,16,0,0,p->heap);
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        func_0202173C((struct PalAnmObj *)p->anm,4,mask,-2,16,0,0,p->heap);
        p->state=1;
        p->request=0;
        return;
    case 2:
        if (p->state==3) break;
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        func_0202173C((struct PalAnmObj *)p->anm,1,mask,-2,0,16,0,p->heap);
        mask=0;
        for (i=0;i<14;i++) mask|=(u16)(1<<i);
        func_0202173C((struct PalAnmObj *)p->anm,4,mask,-2,0,16,0,p->heap);
        p->state=3;
        p->request=0;
        break;
    }
}
void func_021BB0C4(char *p)
{
    func_02021D50(*(struct S02021D50 * *)&((struct Obj25729 *)p)->f2E0);
}
