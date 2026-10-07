/*
 * file:     musical_mcss_p04.c
 * unit:     yes
 * function: func_021F4B10, func_021F4B24, func_021F4B30, func_021F4B3C, func_021F4B4C, func_021F4B54, func_021F4B88, func_021F4C1C
 * address:  0x021F4B10
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
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F5064 0x021F5064 thumb ov112
 *   func_021F50D0  0x021F50D0  thumb  ov112
 *   func_021F50E0  0x021F50E0  thumb  ov112
 *   func_021F4AA8 0x021F4AA8 thumb ov112
 *   func_02046DB8 0x02046DB8 arm
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_021F4AC8 0x021F4AC8 thumb ov112
 *   func_021F4C94 0x021F4C94 thumb ov112
 *   func_0204EF58 0x0204EF58 arm
 */
#include "../../matched/include/Obj22520.h"
#include "../../matched/include/Obj22521.h"
#include "../../matched/include/Obj22522.h"
#include "../../matched/include/Obj06407.h"

struct Tagged;
struct Desc;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef signed char s8;

typedef int s32;

typedef struct { u16 used:1; u16 rest:15; } Bits;

typedef struct { u16 flags,zero; u32 id,index,type; int x,y,z; s16 a,b; u8 *data; } Entry;

typedef struct { u32 pad; void *board; Entry *entries; u8 *table; } Object;

typedef struct { u8 x,y; } Pair;

extern u8 *func_021F4F54(u8 *,int);
extern int func_021F5064(u8 *,int);
extern int func_021F50D0(const unsigned char *p);
extern int func_021F50E0(const unsigned char *p);
extern u16 func_021F4AA8(int);
extern void *func_02046DB8(u32,u32);
extern void func_02046EFC(struct Tagged *p);
extern int func_021F4F70(int *);
extern void func_021F4AC8(u8 *p, u8 *a, u8 *b);
extern Entry *func_021F4C94(Object *,u16,int *,s16,s16);
extern u32 func_0204EF58(struct Desc *desc, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
int func_021F4B10(u8 *p,int index,int mode);
int func_021F4B24(u8 *p);
int func_021F4B30(u8 *p);
void *func_021F4B3C(int type);
void func_021F4B4C(struct Tagged *a0);
u16 func_021F4B54(u32 p);
Entry *func_021F4B88(Object *p,int type,u32 id,int *v);
Entry *func_021F4C1C(Object *p, int type, u32 id, int *v);

int func_021F4B10(u8 *p,int index,int mode) { return func_021F5064(func_021F4F54(*(u8 * *)&((struct Obj22520 *)p)->fC,index),mode); }

int func_021F4B24(u8 *p) { return func_021F50D0((const unsigned char *)(((struct Obj22521 *)p)->f20)); }

int func_021F4B30(u8 *p) { return func_021F50E0((const unsigned char *)(((struct Obj22522 *)p)->f20)); }

void *func_021F4B3C(int type) { return func_02046DB8(45,func_021F4AA8(type)); }

void func_021F4B4C(struct Tagged *a0) { func_02046EFC(a0); }

u16 func_021F4B54(u32 p) { u16 n; int i; n=((struct Obj06407 *)p)->f10; for (i=0;i<n;i++) { if (((Bits *)(((struct Obj06407 *)p)->f8+i*36))->used==0) break; } if (i==n) return 0; return i; }

Entry *func_021F4B88(Object *p,int type,u32 id,int *v)
{
    int index;
    int data;
    Pair pair;
    index=func_021F4B54((u32)p);
    p->entries[index].type=func_021F4AA8(type);
    p->entries[index].data=func_021F4F54(p->table,type);
    data=func_021F4F70((int *)p->entries[index].data);
    func_021F4AC8((u8 *)(&p->entries[index]),&pair.y,&pair.x);
    p->entries[index].id=func_0204EF58(p->board,id,0,data,pair.y<<5,pair.x<<5);
    p->entries[index].flags |= 16;
    func_021F4C94(p,index,v,pair.y,pair.x);
    return &p->entries[index];
}

Entry *func_021F4C1C(Object *p, int type, u32 id, int *v)
{
    int index;
    Pair pair;
    index=func_021F4B54((u32)p);
    p->entries[index].type=func_021F4AA8(type);
    p->entries[index].data=func_021F4F54(p->table,type);
    func_021F4F70((int *)p->entries[index].data);
    func_021F4AC8((u8 *)(&p->entries[index]),&pair.y,&pair.x);
    p->entries[index].id=id;
    p->entries[index].flags=p->entries[index].flags & ~16;
    func_021F4C94(p,index,v,pair.y,pair.x);
    return &p->entries[index];
}
