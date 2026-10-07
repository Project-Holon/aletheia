/*
 * file:     btl_rec_sel_p09.c
 * unit:     yes
 * function: func_021BAE88, func_021BAE9C, func_021BAF30, func_021BAF64
 * address:  0x021BAE88
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BABA4 0x021BABA4 thumb ov214
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02021518 0x02021518 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   site 0x021BB658 data ov214
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030D28 0x02030D28 arm
 *   func_02021ED8 0x02021ED8 thumb
 *   func_0202173C 0x0202173C thumb
 *   func_02021D50 0x02021D50 thumb
 */
#include "../../matched/include/Obj00182.h"
#include "../../matched/include/Obj00636.h"
#include "../../matched/include/Obj25729.h"

struct Ctx;
struct Obj02021EE4;
struct PalAnmSlot;
struct PalAnmObj;
struct S02021D50;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

struct S { u8 pad[0x2D8]; void *heap; u32 unused2DC; char *anm; u32 request,state; };

extern void func_021BABA4(void *,void *);
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_02021518(u32);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_020215A0(struct PalAnmSlot *,u32);
extern void func_02021540(void *);
extern void func_02030DA4(void *);
extern void func_020307B0(void *);
extern void func_02030D28(struct Ctx *c);
extern u32 func_02021ED8(const char *);
extern int func_0202173C(struct PalAnmObj *,u16,u32,s16,u8,u8,u16,void *);
extern void func_02021D50(struct S02021D50 *);
void func_021BAE88(int unused,u8 *p);
void func_021BAE9C(int unused,char *p);
void func_021BAF30(int unused,u8 *p);
void func_021BAF64(void *unused,struct S *p);
void func_021BB0C4(char *p);
extern const char site[];

void func_021BAE88(int unused,u8 *p){func_021BABA4(p+0x2c4,((struct Obj00182 *)p)->f2D4);}

void func_021BAE9C(int unused,char *p)
{
    ((struct Obj00182 *)p)->f2DC=func_02030734(((struct Obj00182 *)p)->f0,func_02030CB0(2),1,site,2403);
    ((struct Obj00182 *)p)->f2D8=func_02030CBC(2,((struct Obj00182 *)p)->f2DC);
    ((struct Obj00182 *)p)->f2E0=func_02021518(((struct Obj00182 *)p)->f0);
    func_02021EE4(((struct Obj00182 *)p)->f2E0,1);
    func_0202155C(((struct Obj00182 *)p)->f2E0,0,448,((struct Obj00182 *)p)->f0);
    func_0202155C(((struct Obj00182 *)p)->f2E0,2,448,((struct Obj00182 *)p)->f0);
    func_020216D4(((struct Obj00182 *)p)->f2E0,0,0,448);
    func_020216D4(((struct Obj00182 *)p)->f2E0,2,0,448);
    ((struct Obj00182 *)p)->f2E8=2;
    ((struct Obj00182 *)p)->f2E4=0;
}

void func_021BAF30(int unused,u8 *p){func_020215A0(*(struct PalAnmSlot * *)&((struct Obj00636 *)p)->f2E0,0);func_020215A0(*(struct PalAnmSlot * *)&((struct Obj00636 *)p)->f2E0,2);func_02021540(((struct Obj00636 *)p)->f2E0);func_02030DA4(((struct Obj00636 *)p)->f2D8);func_020307B0(((struct Obj00636 *)p)->f2DC);}

/*
 * prototype: 0202173C's third parameter is widened to the observed full-word
 *   caller payload; own u16 declaration inserted four extra truncation pairs.
 *   Both fixed-flag TU runs preserve its low-halfword colour; widening gives EXACT368.
 * extent: lead and tail-call follower 021BB0C4.
 */
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
