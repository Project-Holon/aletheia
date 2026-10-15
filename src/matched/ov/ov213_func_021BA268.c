/*
 * function: COMM_BTL_DEMO_MAIN_InitRowContext
 * address: 0x021BA268
 * packet: pkt_ov213_021BA268
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BA2DE..021BA2E0 is two zero alignment bytes; following021BA2E0 already filed separately.
 * lever: logical owner,a,b,c,zero field order restores stack-load scheduling; const owner and typed destination alone did not.
 * symbols:
 *   COMM_BTL_DEMO_MAIN_InitActorRow 0x021B9EE4 thumb ov213
 *   STRBUF_Create 0x020457B0 arm
 *   func_02008500 0x02008500 thumb
 *   func_02008550 0x02008550 thumb
 *   COMM_BTL_DEMO_MAIN_CreateRowWindow 0x021BA200 thumb ov213
 *   COMM_BTL_DEMO_MAIN_HasVisibleActors 0x021B9E80 thumb ov213
 *   COMM_BTL_DEMO_MAIN_DrawRowText 0x021BA330 thumb ov213
 */
#include "../include/Obj25698.h"
#include "../include/Obj25699.h"
#include "../include/Obj25700.h"
struct C;
extern void COMM_BTL_DEMO_MAIN_InitActorRow(struct C *p, void *owner, unsigned char kind, unsigned char index, void *a, void *parent, const unsigned char *types);
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02008500(void *,void *);
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern unsigned COMM_BTL_DEMO_MAIN_CreateRowWindow(unsigned,unsigned);
extern int COMM_BTL_DEMO_MAIN_HasVisibleActors(unsigned);
extern void COMM_BTL_DEMO_MAIN_DrawRowText(void *,int);
typedef struct {const char *owner;void *a,*b;int c;unsigned char kind,index;char pad12[2];unsigned v14;void *v18;unsigned v1C;char sub[48];int v50;} Context;
void COMM_BTL_DEMO_MAIN_InitRowContext(Context *p,unsigned char kind,unsigned char index,const char *owner,void *a,void *b,int c)
{
    void *first,*second;
    int value;
    value=c;first=a;second=b;
    p->owner=owner;p->a=first;p->b=second;
    p->c=value;p->v50=0;
    p->kind=kind;p->index=index;
    COMM_BTL_DEMO_MAIN_InitActorRow((struct C *)p->sub,((struct Obj25698 *)owner)->f0,kind,index,a,b,(const unsigned char *)(owner+10));
    p->v18=STRBUF_Create(16,116);
    func_02008500(((struct Obj25699 *)(p->owner))->f4,p->v18);
    p->v14=func_02008550(((struct Obj25700 *)(p->owner))->f4);
    p->v1C=COMM_BTL_DEMO_MAIN_CreateRowWindow(kind,index);
    if(COMM_BTL_DEMO_MAIN_HasVisibleActors(p->kind)==0) COMM_BTL_DEMO_MAIN_DrawRowText(p,p->c);
}
