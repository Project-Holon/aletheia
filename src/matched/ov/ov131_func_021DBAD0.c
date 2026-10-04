/*
 * function: func_021DBAD0
 * address: 0x021DBAD0
 * packet: pkt_ov131_021DBAD0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-02): b is const-qualified; that frees the b loads from ordering behind the stack
 *   stores (d fields, outgoing args), which fixes both scheduling residues. bm local feeds the first size call.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021DBEA4 0x021DBEA4 thumb ov131
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02049238 0x02049238 arm
 *   d_021DC854 0x021DC854 data a1
 */
#include "../include/Obj01549.h"
#include "../include/Obj06487.h"
#include "../include/Obj06488.h"
#include "../include/Obj10527.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Desc {s16 x,y;u16 z;u8 kind,flag;};
struct Bmp;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
extern int func_021DBEA4(u8 *p, int screen, u32 owner);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B6F4(void *,u8,u32);
extern void func_02049238(void *);
extern const char d_021DC854[];
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
            func_0204B6F4(*(void **)(blk+(u32)j*4+4),*(const u32 *)&((struct Obj01549 *)b)->fC,0);
        }
    }
    func_02049238(heap);
    return blk;
}
