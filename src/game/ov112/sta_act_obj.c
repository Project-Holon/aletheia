/*
 * file:     sta_act_obj.c
 * unit:     yes
 * function: func_021F69E4, func_021F6A24, func_021F6A58, func_021F6A80, func_021F6AF0, func_021F6B18, func_021F6B80
 * address:  0x021F69E4
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F83F8 0x021F83F8 data a4
 *   func_020307B0 0x020307B0 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   BILLBOARD_SetElemPos 0x0204F638 arm
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   d_021F8328 0x021F8328 data a4
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   BILLBOARD_DeleteImage 0x0204F150 arm
 */
#include "../../matched/include/Obj08023.h"

struct Trip;
struct Board;
struct Vec3;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 a,b,c,d,e,f,g; } Entry_021F69E4;

typedef struct { u16 heap,n; void *p; Entry_021F69E4 entries[5]; } Object_021F69E4;

typedef struct { int x,y,z; } Vec;

typedef struct { u32 a,b,c,d,e,f,g; } Entry_021F6AF0;

typedef struct { u16 heap,n; void *p; Entry_021F6AF0 entries[5]; } Object_021F6AF0;

typedef signed int     s32;

typedef struct { u32 active,dirty; int x,y,z,id,index; } Entry_021F6B18;

typedef struct { u16 heap,n; void *board; Entry_021F6B18 entries[5]; } Object_021F6B18;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020307B0(void *);
extern void BILLBOARD_SetElemPos(u8 *a0, int i, struct Trip *src);
extern s32 BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void BILLBOARD_SetElemVisible(void *,u32,u32 *);
extern void BILLBOARD_FreeElem(void *, u32);
extern void BILLBOARD_DeleteImage(u8 *a0, int i);
Object_021F69E4 *func_021F69E4(u16 heap, void *p);
void func_021F6A24(char *p);
void func_021F6A58(char *p);
void func_021F6A80(char *o,u32 *p);
void func_021F6AF0(Object_021F6AF0 *o,u16 n);
Entry_021F6B18 *func_021F6B18(Object_021F6B18 *o);
void func_021F6B80(u32 *a, u32 *b);
void func_021F6B9C(void *a, u32 *b, u32 *c);
void func_021F6BB0(void *a, u32 *b, u32 *c);
extern const char d_021F83F8[];
extern u32 d_021F8328;

Object_021F69E4 *func_021F69E4(u16 heap, void *p)
{
    Object_021F69E4 *o;
    u8 i;
    i=0;
    o=func_02030734(heap,148,0,d_021F83F8,79);
    o->heap=heap;
    o->p=p;
    o->n=0;
    for (;i<5;i++) { o->entries[i].a=0; o->entries[i].b=0; }
    return o;
}

void func_021F6A24(char *p) {u8 i;for(i=0;i<5;i++)if(*(u32 *)(p+i*28+8)==1)func_021F6B80((u32 *)p,(u32 *)(p+8+i*28));func_020307B0(p);}

/*
 * lever: Load adds the index before offset eight; the call adds offset eight before the index.
 */
void func_021F6A58(char *p) {int i;for(i=0;i<5;i++)if(*(u32 *)(p+i*28+8)==1)func_021F6A80(p,(u32 *)(p+8+i*28));}

/*
 * extent: Padding then separately verified follower func_021F6AF0.
 */
void func_021F6A80(char *o,u32 *p)
{
    Vec v;
    float f;
    if(p[1]==1) {
        if(((struct Obj08023 *)o)->f2!=0) f=0.5f+(float)(((struct Obj08023 *)o)->f2<<12);
        else f=(float)(((struct Obj08023 *)o)->f2<<12)-0.5f;
        v.x=((int)p[2]-(int)f)/16;
        v.y=(786432-(int)p[3])/16;
        v.z=p[4];
        BILLBOARD_SetElemPos(((struct Obj08023 *)o)->f4,p[6],(struct Trip *)(&v));
        p[1]=0;
    }
}

void func_021F6AF0(Object_021F6AF0 *o,u16 n)
{
    u8 i;
    o->n=n;
    for(i=0;i<5;i++) if(o->entries[i].a==1) o->entries[i].b=1;
}

Entry_021F6B18 *func_021F6B18(Object_021F6B18 *o)
{
    u8 i;
    Entry_021F6B18 *p;
    for(i=0;i<5;i++) if(o->entries[i].active==0) break;
    p=&o->entries[i];
    p->active=1; p->dirty=1; p->x=0; p->y=0; p->z=0;
    p->index=BILLBOARD_AddElem(o->board,p->id,4096,4096,(struct Vec3 *)(&p->x),31,0,0);
    BILLBOARD_SetElemVisible(o->board,p->index,&d_021F8328);
    return p;
}

void func_021F6B80(u32 *a, u32 *b)
{
    BILLBOARD_FreeElem((void *)a[1], b[6]);
    BILLBOARD_DeleteImage((void *)a[1], b[5]);
    b[0]=0;
}

void func_021F6B9C(void *a, u32 *b, u32 *c)
{
    b[2]=c[0]; b[3]=c[1]; b[4]=c[2]; b[1]=1;
}

void func_021F6BB0(void *a, u32 *b, u32 *c)
{
    c[0]=b[2]; c[1]=b[3]; c[2]=b[4];
}
