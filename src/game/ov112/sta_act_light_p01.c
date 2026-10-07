/*
 * file:     sta_act_light_p01.c
 * unit:     yes
 * function: func_021F6BC0, func_021F6BD8, func_021F6C7C, func_021F6CB0, func_021F6CE0, func_021F6D68, func_021F6E74, func_021F6E78, func_021F6EE4, func_021F6EF4, func_021F6F04, func_021F6F14
 * address:  0x021F6BC0
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
 *   func_0204F720 0x0204F720 arm
 *   func_02030734 0x02030734 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   d_021F8408 0x021F8408 data a4
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F9E04 0x021F9E04 thumb ov132
 *   func_021F9E18 0x021F9E18 thumb ov132
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../../matched/include/Obj22554.h"
#include "../../matched/include/Obj08024.h"
#include "../../matched/include/Obj00771.h"
#include "../../matched/include/Obj05317.h"
#include "../../matched/include/Obj13836.h"
#include "../../matched/include/Obj05318.h"
#include "../../matched/include/Obj08025.h"

struct Bank;
struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32_021F6BD8;

typedef struct { u16 heap,pad; void *a; u32 entries[4][8]; u32 other[8]; void *bank; u32 x,y,z; } Object;

typedef struct { short x, y; } Point_021F6CE0;

typedef struct { short x,y; } Point_021F6D68;

typedef struct { Point_021F6D68 pos; u16 x,y,z; u8 a,b; } Desc;

typedef struct { int x,y,z; } Vec_021F6D68;

typedef short s16;

typedef signed char s8;

typedef int s32_021F6E74;

typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

typedef struct {int x,y,z;} Vec_021F6F04;

extern void func_0204F720(void *,u32,u32 *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void *func_020490F4(u32 id, u32 heap);
extern signed int func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32_021F6BD8 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021F6BD8 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_0204B1CC(void *);
extern void func_020307B0(void *);
extern u16 func_021F9E04(u8 *p);
extern int func_021F9E18(char *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void func_021F8044(void *unused, u32 *p, u32 *q);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3B4(struct Obj *p);
void func_021F6BC0(char *p,u32 *q,u32 flag);
Object *func_021F6BD8(u16 heap,void *a);
void func_021F6C7C(char *p);
void func_021F6CB0(char *p);
void func_021F6CE0(char *p, char *q);
void func_021F6D68(char *p);
void func_021F6E74(void);
u8 *func_021F6E78(u8 *p, int v);
void func_021F6EE4(void *unused,u8 *p);
void func_021F6EF4(void *unused,u32 *p,const u32 *q);
void func_021F6F04(void *ctx,char *p,Vec_021F6F04 *out);
void func_021F6F14(void *a,char *p,u16 b,u8 c);
extern const char d_021F8408[];

/*
 * note: True entry includes push {r0-r3}; handed 021F6BC2 is an interior prologue label.
 */
void func_021F6BC0(char *p,u32 *q,u32 flag) {func_0204F720(((struct Obj22554 *)p)->f4,q[6],&flag);}

Object *func_021F6BD8(u16 heap,void *a)
{
    u8 i;
    Object *p;
    void *q;
    i=0;
    p=func_02030734(heap,184,0,d_021F8408,87);
    p->heap=heap; p->a=a;
    for(;i<4;i++) p->entries[i][0]=0;
    p->other[0]=0;
    p->bank=func_0204B100(5,0,p->heap);
    func_0204B270(p->bank);
    q=func_020490F4((unsigned int)47,p->heap);
    p->x=func_0204ABF0((void *)q,4,0,0,p->heap);
    p->y=func_0204A6C8((void *)((u32)q),10,0,0,p->heap);
    p->z=func_0204AF28((void *)((u32)q),20,23,p->heap);
    func_02049238(q);
    return p;
}

/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
void func_021F6C7C(char *p) {func_0204ADA4(((struct Obj08024 *)p)->fAC);func_0204A8D4(((struct Obj08024 *)p)->fB0);func_0204AFD8(((struct Obj08024 *)p)->fB4);func_0204B1CC(((struct Obj08024 *)p)->fA8);func_020307B0(p);}

void func_021F6CB0(char *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*32+8)) func_021F6CE0(p,p+8+i*32); if(*(int *)&((struct Obj00771 *)p)->f4) func_021F6D68(p); }

void func_021F6CE0(char *p, char *q) {
    u16 n;
    int tmp;
    Point_021F6CE0 point;
    if (*(int *)&((struct Obj00771 *)p)->f4 == 0) tmp = 0x80;
    else tmp = func_021F9E04((u8 *)(*(int *)&((struct Obj00771 *)p)->f4));
    n = tmp;
    if (((struct Obj05317 *)q)->f0 == 1) {
        point.x = (short)((float)((struct Obj05317 *)q)->f8 / 4096.0f - (float)(unsigned)n);
        point.y = (short)((float)((struct Obj05317 *)q)->fC / 4096.0f);
        func_0204B404((struct Obj *)(((struct Obj05317 *)q)->f1C), (const struct Vec2 *)(&point), 0);
        if (*(int *)&((struct Obj00771 *)p)->f4 != 0 && func_021F9E18((char *)(*(int *)&((struct Obj00771 *)p)->f4)) != 4) {
            func_0204B3DC((struct Obj *)((struct Obj05317 *)q)->f1C, 0);
            return;
        }
        func_0204B3DC((struct Obj *)((struct Obj05317 *)q)->f1C, 1);
    }
}

/*
 * ABI: B294 leaves live r0 which the original stores and passes to B3DC despite its legacy void declaration.
 */
void func_021F6D68(char *p)
{
    Vec_021F6D68 v;
    Desc d;
    void *a;
    char *ctx;
    char *model;
    u16 n;
    if(((struct Obj00771 *)p)->f88==0 && func_021F9E18(*(char * *)&((struct Obj00771 *)p)->f4)!=4) {
        ((struct Obj00771 *)p)->f88=1;
        d.x=128;
        d.y=96;
        d.z=0;
        d.a=0;
        d.b=2;
        a=func_0204B294((void *)((struct Obj00771 *)p)->fA8,((struct Obj00771 *)p)->fB0,((struct Obj00771 *)p)->fAC,((struct Obj00771 *)p)->fB4,&d.x,0,((struct Obj00771 *)p)->f0);
        ((struct Obj00771 *)p)->fA4=a;
        func_0204B3DC(a,1);
    }
    if(((struct Obj00771 *)p)->f88==1) {
        if(func_021F9E18(*(char * *)&((struct Obj00771 *)p)->f4)==4) {
            func_0204B3B4(((struct Obj00771 *)p)->fA4);
            ((struct Obj00771 *)p)->f88=0;
            return;
        }
        ctx=func_021F9DA0(((struct Obj00771 *)p)->f4);
        model=func_021F9DA4(((struct Obj00771 *)p)->f4,func_021F9E18(*(char * *)&((struct Obj00771 *)p)->f4));
        n=func_021F9E04(((struct Obj00771 *)p)->f4);
        func_021F8044(ctx,(u32 *)model,(u32 *)(&v));
        d.pos.x=(short)((float)v.x/4096.0f-(float)(unsigned)n);
        d.pos.y=(short)((float)v.y/4096.0f-32.0f);
        func_0204B404(((struct Obj00771 *)p)->fA4,(const struct Vec2 *)(&d.pos),0);
    }
}


void func_021F6E74(void) { }

u8 *func_021F6E78(u8 *p, int v)
{
    u8 i = 0;
    u8 *q;
    Pos pos;
    struct Obj *o;
    do {
        if (*(u32 *)(p + i * 32 + 8) == 0) break;
        i++;
    } while (i < 4);
    *(u32 *)(p + 8 + i * 32) = v;
    q = p + 8 + i * 32;
    pos.x = 0x80;
    pos.y = 0x60;
    pos.z = 0;
    pos.a = 0;
    pos.b = 2;
    o = func_0204B294(*(void **)(p + 0xa8), *(u32 *)(p + 0xb0), *(u32 *)(p + 0xac), *(u32 *)(p + 0xb4), &pos, 0, *(u16 *)p);
    *(struct Obj **)(q + 0x1c) = o;
    func_0204B3DC(o, 1);
    return q;
}

void func_021F6EE4(void *unused,u8 *p) { func_0204B3B4(*(struct Obj * *)&((struct Obj13836 *)p)->f1C); ((struct Obj13836 *)p)->f0=0; }

/*
 * extent: two zero padding bytes then existing ov112_func_021F6F04, 021F6F14, 021F6F1C sources and shards.
 */
void func_021F6EF4(void *unused,u32 *p,const u32 *q) { p[2]=q[0]; p[3]=q[1]; p[4]=q[2]; }

/*
 * extent: trailing zero halfword at 021F6F12 is alignment padding.
 */
void func_021F6F04(void *ctx,char *p,Vec_021F6F04 *out)
{
    out->x=*(int *)&((struct Obj05318 *)p)->f8;
    out->y=*(int *)&((struct Obj05318 *)p)->fC;
    out->z=*(int *)&((struct Obj05318 *)p)->f10;
}

void func_021F6F14(void *a,char *p,u16 b,u8 c)
{
    ((struct Obj08025 *)p)->f4=b;
    ((struct Obj08025 *)p)->f6=c;
}
