/*
 * file:     demo3d_cmdsys.c
 * unit:     yes
 * function: func_021BF7C0, func_021BF810, func_021BF858, func_021BF8E8, func_021BF924, func_021BF964, func_021BF9B8
 * address:  0x021BF7C0
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from demo3d_graphic.c, demo3d_data.c, demo3d_cmdsys.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021BF7C0 0x021BF7C0 thumb ov203
 *   func_021BF810 0x021BF810 thumb ov203
 *   func_021BF858 0x021BF858 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   DEMO3D_DATA_DeleteCapture 0x021BE9E8 thumb
 *   d_021C3D4C 0x021C3D4C data a4
 *   DEMO3D_DATA_GetRecordField 0x021BE9A4 thumb ov203
 *   TCBL_Main 0x020310C4 arm
 *   func_021BE990 0x021BE990 thumb ov203
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_020490F4 0x020490F4 arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   d_021C3D00 0x021C3D00 data a4
 */
#include "../../matched/include/Obj10867.h"
#include "../../matched/include/Obj02250.h"
#include "../../matched/include/Obj01776.h"
#include "demo3d_graphic_shared_types.h"
#include "demo3d_data_shared_types.h"

extern u32 func_020307B0(void *p);

struct GfFont;

struct S02031140;

typedef struct {unsigned short heap,alternate;int config;int ended;int done;int previous;int index;char flags[4];char *owner;struct Tcbl *task;int text;int assets;int extra;} Context;

typedef struct {int kind;unsigned time;int values[8];} Record;

extern void GFL_USE_FadeInBgmFull(u32 a);

extern void GFL_USE_SetBgmPlayerParam(void *);

extern void DEMO3D_DATA_DeleteCapture(int);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 DEMO3D_DATA_GetRecordField(u32 id);

extern void TCBL_Main(struct Tcbl *p);

extern Record *func_021BE990(int);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, unsigned int count, unsigned int workSize);

extern struct GfFont *GF_FONT_Create(int,int,int,int,unsigned);

extern void *func_020490F4(u32 id, u32 heap);

extern signed char MSG_SPEED_GetWait(void);

extern void TCBL_DeleteAllTasks(struct Tcbl *p);

extern void ARC_TOOL_DeleteHandle(void *);

extern u32 GF_FONT_Delete(void *ptr);

extern void TCBL_Destroy(struct S02031140 *p);

Context *func_021BF7C0(char *owner,unsigned heap);

void func_021BF810(char *p);

void func_021BF858(Context *p,int time,int flag);

void func_021BF8E8(char *p);

void func_021BF924(char *p);

int func_021BF964(char *p,char *owner,int *index);

void func_021BF9B8(Context *ctx,char *owner,Record *r);

extern const char d_021C3D4C[];

Context *func_021BF7C0(char *owner,unsigned heap)
{
    Context *p;
    p=func_02030734(heap,0x30,1,d_021C3D4C,78);
    p->owner=owner;p->heap=heap;p->alternate=(heap&0x7FFF)|0x8000;
    p->config=((struct Obj10867 *)owner)->f78;p->previous=-1;
    func_021BF8E8((char *)p);
    p->ended=func_021BF964((char *)p,owner,&p->index);
    return p;
}

void func_021BF810(char *p)
{
    Record *r;
    int owner,i;
    owner=((struct Obj02250 *)p)->f1C;r=(Record *)DEMO3D_DATA_GetRecordField(((struct Obj02250 *)p)->f4);
    for(i=0;i<9999;i++,r++) {
        if(r->kind==18) break;
        func_021BF9B8((Context *)p,(char *)owner,r);
    }
    ((struct Obj02250 *)p)->fC=1;
    TCBL_Main(((struct Obj02250 *)p)->f20);func_021BF924(p);func_020307B0(p);
}

void func_021BF858(Context *p,int time,int flag)
{
    Record *r;
    char *owner;
    int i;
    owner=p->owner;
    p->flags[2]=flag?1:0;
    TCBL_Main(p->task);
    if(p->ended==0 && time!=-4096) {
        r=func_021BE990(p->config)+p->index;
        time>>=12;
        if(r->time==time && p->previous!=time) {
            i=0;
            do {
                func_021BF9B8(p,owner,r);
                r++;
                p->ended=r->kind==18?1:0;
                p->index++;
                if(p->ended==1) break;
                if(r->time!=time) break;
                i++;
            } while(i<9999);
        }
        p->previous=time;
    }
}

extern void (*d_021C3D00[])(Context *, char *, int *);

void func_021BF8E8(char *p){*(struct Tcbl * *)&((struct Obj01776 *)p)->f20=TCBL_Create(((struct Obj01776 *)p)->f0,((struct Obj01776 *)p)->f0,16,128);*(struct GfFont * *)&((struct Obj01776 *)p)->f24=GF_FONT_Create(23,0,0,0,((struct Obj01776 *)p)->f0);((struct Obj01776 *)p)->f28=func_020490F4(161,((struct Obj01776 *)p)->f0);p[0x18]=MSG_SPEED_GetWait();}

void func_021BF924(char *p)
{
    if(((struct Obj02250 *)p)->f2C) DEMO3D_DATA_DeleteCapture(((struct Obj02250 *)p)->f2C);
    TCBL_DeleteAllTasks(((struct Obj02250 *)p)->f20);
    if(((struct Obj02250 *)p)->f19) {
        GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);GFL_USE_FadeInBgmFull(60);
    }
    ARC_TOOL_DeleteHandle(((struct Obj02250 *)p)->f28);GF_FONT_Delete(((struct Obj02250 *)p)->f24);TCBL_Destroy(((struct Obj02250 *)p)->f20);
}

int func_021BF964(char *p,char *owner,int *index)
{
    Record *r;
    int i;
    r=func_021BE990(((struct Obj10867 *)owner)->f78);
    for(i=0;i<9999;i++) {
        if(r[i].kind==18) return 1;
        if(r[i].time==-1) func_021BF9B8((Context *)p,owner,&r[i]);
        else if(r[i].time>=((struct Obj10867 *)owner)->f7C) {*index=i;return 0;}
    }
    return 0;
}

void func_021BF9B8(Context *ctx,char *owner,Record *r){d_021C3D00[r->kind](ctx,owner,r->values);}
