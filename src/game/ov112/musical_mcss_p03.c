/*
 * file:     musical_mcss_p03.c
 * unit:     yes
 * function: func_021F48C0, func_021F4948, func_021F4990, func_021F4AA8, func_021F4AC8, func_021F4AF0, func_021F4AFC
 * address:  0x021F48C0
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
 *   func_021F4F14 0x021F4F14 thumb ov112
 *   d_021F83A4 0x021F83A4 data a1
 *   func_02061C30 0x02061C30 arm
 *   func_021F4F40 0x021F4F40 thumb ov112
 *   func_021F4D40 0x021F4D40 thumb ov112
 *   func_020307B0 0x020307B0 arm
 *   func_021F4F60 0x021F4F60 thumb ov112
 *   func_0204F638 0x0204F638 arm
 *   func_0204F684 0x0204F684 arm
 *   func_0204F7C4 0x0204F7C4 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_02049030 0x02049030 arm
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_0204EDD0 0x0204EDD0 arm
 *   func_021F4F74 0x021F4F74 thumb ov112
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4FF4 0x021F4FF4 thumb ov112
 */
#include "../../matched/include/Obj22515.h"
#include "../../matched/include/Obj22518.h"
#include "../../matched/include/Obj22519.h"

struct Manager0204F684;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Record_021F48C0 { u16 active:1; u16 enabled:1; u16 rest:14; u8 data[34]; } Record_021F48C0;

typedef struct Object_021F48C0 { u16 heap; u16 pad; u32 owner; Record_021F48C0 *records; void *resource; u16 count; u16 slots[16]; } Object_021F48C0;

typedef struct Record_021F4948 { u16 active:1; u16 rest:15; u8 data[34]; } Record_021F4948;

typedef short s16;

typedef union {
    u16 value;
    struct { u16 active:1, dirty:1, rotate:1, rest:13; } bits;
} Flags;

typedef struct { Flags flags; u16 angle; u32 id,index,type; int x,y,z; s16 a,b; u8 *data; } Entry;

typedef struct { u32 pad; u8 *board; Entry *entries; u8 *table; u16 count; } Object_021F4990;

typedef struct { int x,y; } Offset;

typedef struct { u8 x,y; s16 b,a; } Scale;

struct Trip { u32 a,b,c; };

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 *func_021F4F14(int heap);
extern void func_02061C30(void);
extern void func_021F4F40(void **p);
extern void func_021F4D40(u8 *p, u8 *e);
extern u32 func_020307B0(void *p);
extern void func_021F4F60(u8 *,Offset *);
extern void func_0204F638(u8 *,int,struct Trip *);
extern void func_0204F684(struct Manager0204F684 *,int,const s16 *,const s16 *);
extern void func_0204F7C4(u8 *,int,u16 *);
extern u32 func_02049030(u32 a);
extern int func_021F4F70(int *);
extern void func_0204EDD0(int,u16 *,u16 *);
extern int func_021F4F74(u16 *, int);
extern u8 *func_021F4F54(u8 *,int);
extern int func_021F4FF4(u16 *,int);
Object_021F48C0 *func_021F48C0(u32 owner,int count,u16 heap);
void func_021F4948(u8 *p);
void func_021F4990(Object_021F4990 *p);
void func_021F4AA4(void *a0);
u16 func_021F4AA8(int i);
void func_021F4AC8(u8 *p,u8 *a,u8 *b);
int func_021F4AF0(u8 *p, int index);
int func_021F4AFC(u8 *p,int index,int mode);
extern char d_021F83A4[];
extern s16 FX_SinCosTable_[];

Object_021F48C0 *func_021F48C0(u32 owner,int count,u16 heap)
{
    int i=0;
    Object_021F48C0 *p;
    int j;
    p=func_02030734(heap,0x34,0,d_021F83A4,0x55);
    p->records=func_02030734(heap,count*0x24,0,d_021F83A4,0x57);
    p->heap=heap;
    p->count=count;
    p->owner=owner;
    for(;i<p->count;i++) {
        p->records[i].active=0;
        p->records[i].enabled=0;
    }
    p->resource=func_021F4F14(heap);
    for(j=0;j<16;j++) p->slots[j]=0x5a56;
    return p;
}

void func_021F4948(u8 *p)
{
    int i;
    func_02061C30();
    func_021F4F40(*(void **)(p+0xc));
    for(i=0;i<*(u16 *)(p+0x10);i++) {
        if ((*(Record_021F4948 **)(p+8))[i].active==1)
            func_021F4D40(p,(u8 *)(&(*(Record_021F4948 **)(p+8))[i]));
    }
    func_020307B0(*(void **)(p+8));
    func_020307B0(p);
}

/*
 * extent: 276-byte lead plus 4AA4 two-byte return stub; 4AA6 is zero alignment padding.
 * function_starts: 0x021F4AA4
 * lever: bitfield dirty clear retains the hoisted mask; named offset.x keeps trig load order.
 */
void func_021F4990(Object_021F4990 *p)
{
    int i;
    Entry *e;
    Offset offset;
    Scale scale;
    struct Trip v;
    int x,y,s,c,ox;
    for(i=0;i<p->count;i++) {
        e=&p->entries[i];
        if(e->flags.bits.active==1 && e->flags.bits.dirty==1) {
            if(e->flags.bits.rotate==1) {
                func_021F4F60(e->data,&offset);
                if(e->a<0) offset.x *= -1;
                ox=offset.x;
                s=FX_SinCosTable_[(e->angle>>4)*2];
                c=FX_SinCosTable_[(e->angle>>4)*2+1];
                x=ox*c-offset.y*s;
                y=ox*s+offset.y*c;
            } else { x=0; y=0; }
            v.a=(e->x-x)/16;
            v.b=(0xC0000-(e->y-y))/16;
            v.c=e->z;
            func_0204F638(p->board,e->index,&v);
            func_021F4AC8((u8 *)e,&scale.y,&scale.x);
            scale.a=e->a*scale.y;
            scale.b=e->b*scale.x;
            func_0204F684((struct Manager0204F684 *)p->board,e->index,&scale.a,&scale.b);
            func_0204F7C4(p->board,e->index,&e->angle);
            p->entries[i].flags.bits.dirty=0;
        }
    }
}

void func_021F4AA4(void *a0)
{
}

u16 func_021F4AA8(int i)
{
    u32 n = (u16)func_02049030(45) - 2;
    if (i >= (int)n) return 100;
    return (u16)i;
}

void func_021F4AC8(u8 *p,u8 *a,u8 *b) { u16 x,y; func_0204EDD0(func_021F4F70(*(int * *)&((struct Obj22515 *)p)->f20),&x,&y); *a=(u32)x>>5; *b=(u32)y>>5; }

int func_021F4AF0(u8 *p, int index)
{
    return func_021F4F74(*(u16 * *)&((struct Obj22518 *)p)->f20, index);
}

int func_021F4AFC(u8 *p,int index,int mode) { return func_021F4FF4((u16 *)func_021F4F54(*(u8 * *)&((struct Obj22519 *)p)->fC,index),mode); }
