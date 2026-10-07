/*
 * file:     p_sta_oam_p35.c
 * unit:     yes
 * function: func_021DBAC0, func_021DBAD0, func_021DBC3C, func_021DBCA4, func_021DBCF4, func_021DBE2C, func_021DBE98, func_021DBEA4, func_021DBF0C, func_021DBF2C
 * address:  0x021DBAC0
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734 0x02030734 arm
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02049238 0x02049238 arm
 *   d_021DC854 0x021DC854 data a1
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020437D4 0x020437D4 arm
 *   func_020437EC 0x020437EC arm
 *   func_020862F0 0x020862F0 arm
 *   func_0204ABBC 0x0204ABBC arm
 *   func_0207E780 0x0207E780 arm
 *   func_0207E804 0x0207E804 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   d_021DC2F8 0x021DC2F8 data a4
 */
#include "../../matched/include/Obj01549.h"
#include "../../matched/include/Obj06487.h"
#include "../../matched/include/Obj06488.h"
#include "../../matched/include/Obj10527.h"
#include "../../matched/include/Obj02191.h"
#include "../../matched/include/Obj08149.h"
#include "../../matched/include/Obj23174.h"

struct Bmp;
struct Obj;
struct Vec2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short s16;

struct Desc {s16 x,y;u16 z;u8 kind,flag;};

struct Point { s16 x, y; };

struct Entry { u32 a; u16 b, c, d, e; u8 f; u8 pad[3]; };

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_02049238(void *);
extern void func_0204A8D4(u32 i);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_020862F0(void *,int);
extern int func_0204ABBC(u32 idx, u32 flag);
extern void func_0207E780(void *,void *,u32);
extern void func_0207E804(void *,void *,u32);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204AFD8(u32 i);
void func_021DBAC0(u8 *p);
u8 *func_021DBAD0(u8 *a,const u8 *b);
void func_021DBC3C(u8 *p);
void func_021DBCA4(u8 *p, int v);
void func_021DBCF4(u8 *p);
void func_021DBE2C(u8 *p, s16 x, s16 y);
void func_021DBE98(int *a, int *b);
int func_021DBEA4(u8 *p, int screen, u32 owner);
void func_021DBF0C(int *p);
u32 func_021DBF2C(u32 i, u32 field);
extern const char d_021DC854[];
extern const struct Entry d_021DC2F8[];


/*
 * Addresses are Black-image addresses.
 */
void func_021DBAC0(u8 *p)
{
    func_021DBF0C((int *)p);
    func_020307B0(p);
}

/*
 * note (2026-10-02): b is const-qualified; that frees the b loads from ordering behind the stack
 *   stores (d fields, outgoing args), which fixes both scheduling residues. bm local feeds the first size call.
 */
u8 *func_021DBAD0(u8 *a,const u8 *b)
{
    struct Desc d={0};
    u8 *blk;
    u8 cols,rows,i,j;
    void *heap;
    u8 *row;
    u8 *e;
    int mode;
    void *bm;
    blk=func_02030734(((struct Obj06487 *)a)->f4,0x24,1,d_021DC854,0x8a);
    bm=*(void *const *)&((struct Obj01549 *)b)->f0;
    ((struct Obj06488 *)blk)->f0=bm;
    cols=((u32)func_020437DC(bm)>>6)&0xff;
    rows=((u32)func_020437E4(*(void *const *)&((struct Obj01549 *)b)->f0)>>5)&0xff;
    if(func_020437DC(*(void *const *)&((struct Obj01549 *)b)->f0)%64!=0) cols=cols+1;
    if(func_020437E4(*(void *const *)&((struct Obj01549 *)b)->f0)%32!=0) rows=rows+1;
    blk[0x22]=cols;
    blk[0x23]=rows;
    ((struct Obj06488 *)blk)->f20=*(const u16 *)&((struct Obj01549 *)b)->f12;
    ((struct Obj06488 *)blk)->f10=*(const u32 *)&((struct Obj01549 *)b)->f14;
    heap=func_020490F4(0x4e,((struct Obj06487 *)a)->f4);
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            row=blk+i*cols*4;
            mode=func_021DBEA4(a,*(const u32 *)&((struct Obj01549 *)b)->f14,(u32)heap);
            e=row+j*4;
            ((struct Obj10527 *)e)->f14=(void *)func_0204A6C8(heap,7,0,*(const u32 *)&((struct Obj01549 *)b)->f14,((struct Obj06487 *)a)->f4);
            d.x=*(const s16 *)&((struct Obj01549 *)b)->f4+(j<<6);
            d.y=*(const s16 *)&((struct Obj01549 *)b)->f6+(i<<5);
            d.kind=b[0x10];
            d.flag=b[0x11];
            ((struct Obj10527 *)e)->f4=func_0204B294((void *)((struct Obj06487 *)a)->f0,*(u32 *)&((struct Obj10527 *)e)->f14,*(const u32 *)&((struct Obj01549 *)b)->f8,*(u32 *)(a+8+mode*4),&d,*(const u16 *)&((struct Obj01549 *)b)->f12,((struct Obj06487 *)a)->f4);
            func_0204B6F4(*(void **)(blk+(u32)j*4+4),(u8)(*(const u32 *)&((struct Obj01549 *)b)->fC),0);
        }
    }
    func_02049238(heap);
    return blk;
}

void func_021DBC3C(u8 *p)
{
    u8 i, j;
    for (i = 0; i < p[0x23]; i++) {
        for (j = 0; j < p[0x22]; j++) {
            func_0204A8D4((u32)(*(void **)(p + 0x14 + (j + i * p[0x22]) * 4)));
            func_0204B3B4(*(void **)(p + 4 + (j + i * p[0x22]) * 4));
        }
    }
    func_020307B0(p);
}

void func_021DBCA4(u8 *p, int v)
{
    u8 i, j;
    for (i = 0; i < p[0x23]; i++) {
        for (j = 0; j < p[0x22]; j++) {
            func_0204B3DC(*(void **)(p + 4 + (j + i * p[0x22]) * 4), v);
        }
    }
}

void func_021DBCF4(u8 *p)
{
    u8 *dst0;
    int c,r;
    u32 off,seg,edge;
    int rem;
    u32 wt;
    u8 *src;
    u8 k;
    void (*fn)(void *,void *,u32);
    dst0=func_020437D4(((struct Obj02191 *)p)->f0);
    func_020862F0(dst0,func_020437EC(((struct Obj02191 *)p)->f0));
    if(((struct Obj02191 *)p)->f10==0) fn=func_0207E780; else fn=func_0207E804;
    wt=(u32)func_020437DC(((struct Obj02191 *)p)->f0)>>3;
    rem=(u32)func_020437E4(((struct Obj02191 *)p)->f0)>>3;
    rem=rem%4;
    edge=func_020437DC(((struct Obj02191 *)p)->f0)%64/8*32;
    if(edge==0) edge=256;
    off=0;
    for(r=0;r<p[0x23];r++) {
        for(c=0;c<p[0x22];c++) {
            if(c==p[0x22]-1) seg=edge; else seg=256;
            src=(u8 *)func_0204ABBC((u32)(*(void **)(p+0x14+(c+r*p[0x22])*4)),((struct Obj02191 *)p)->f10);
            for(k=0;k<4;k++) {
                if(r==p[0x23]-1 && rem!=0 && k>=rem) continue;
                fn(dst0+(off+k*(wt*32)),src,seg);
                src+=256;
            }
            off+=seg;
        }
        off+=wt*32;
    }
}

void func_021DBE2C(u8 *p, s16 x, s16 y)
{
    struct Point pt;
    int i, j;
    for (i = 0; i < p[0x23]; i++) {
        for (j = 0; j < p[0x22]; j++) {
            pt.x = (s16)(x + (j << 6));
            pt.y = (s16)(y + (i << 5));
            func_0204B404(*(void **)(p + 4 + (j + i * p[0x22]) * 4), (const struct Vec2 *)(&pt), ((struct Obj08149 *)p)->f20);
        }
    }
}

void func_021DBE98(int *a, int *b) {
 int t = *a;
 *a = *b;
 *b = t;
}

/*
 * volatile: hardware register read at 021DBEB4
 */
int func_021DBEA4(u8 *p, int screen, u32 owner)
{
    int mode;
    u32 bits;
    bits = *(volatile u32 *)(screen == 0 ? 0x04000000 : 0x04001000) & 0x00300010;
    switch (bits) {
    case 0x00200010: mode = 0; break;
    case 0x00100010: mode = 1; break;
    case 0x10: mode = 2; break;
    default: mode = 0; break;
    }
    if (*(int *)(p + 8 + mode * 4) != -1) return mode;
    *(int *)(p + 8 + mode * 4) = func_0204AF28((void *)owner, 0x4d, 0x80, ((struct Obj23174 *)p)->f4);
    return mode;
}

void func_021DBF0C(int *p) {
 int i;
 for (i = 0; i < 3; i++) {
  if (p[2 + i] != -1) {
   func_0204AFD8(p[2 + i]);
   p[2 + i] = -1;
  }
 }
}

u32 func_021DBF2C(u32 i, u32 field)
{
    switch (field) {
    case 0: return d_021DC2F8[i].a;
    case 1: return d_021DC2F8[i].b;
    case 2: return d_021DC2F8[i].c;
    case 3: return d_021DC2F8[i].d;
    case 4: return d_021DC2F8[i].e;
    case 5: return d_021DC2F8[i].f;
    default: return 0;
    }
}
