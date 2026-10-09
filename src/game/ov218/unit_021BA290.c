/*
 * file:     unit_021BA290.c
 * unit:     yes
 * function: func_021BA290, func_021BA2EC, func_021BA328, func_021BA4B4, func_021BA4D4, func_021BA4FC, func_021BA554, func_021BA61C, func_021BA680, func_021BA6BC, func_021BA6E8, func_021BA720, func_021BA75C, func_021BA780, func_021BA7A4
 * address:  0x021BA290
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_021BA960 0x021BA960 thumb ov218
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   d_021BABC8 0x021BABC8 data ov218 a4
 *   d_021BAB68 0x021BAB68 data a4
 *   d_021BAB98 0x021BAB98 data ov218 a4
 *   d_021BABB0 0x021BABB0 data ov218 a4
 *   d_021BAB80 0x021BAB80 data ov218 a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BAED8 0x021BAED8 data a2
 */
#include "../../matched/include/Obj00243.h"
#include "../../matched/include/Obj01983.h"
#include "../../matched/include/G_Config.h"
#include "../../matched/include/Obj08448.h"
#include "../../matched/include/Obj14773.h"
#include "../../matched/include/Obj03959.h"
#include "../../matched/include/Obj03959.h"

struct Obj;
struct Actor;
struct PtS;
struct PtS;
typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed short s16;

typedef struct Config Config;

typedef struct Pair_021BA290 {short x,y;} Pair_021BA290;

struct Row0 {char pad[0x294];void *item;};

struct Row1 {char pad[0x2b0];void *item;};

typedef struct Pair_021BA61C { short x, y; } Pair_021BA61C;

typedef struct Row { char pad[0x244]; void *item; char gap[0x94]; unsigned id; } Row;

typedef struct PtS{s16 x,y;} PtS;

typedef enum { FogMode0 = 0 } FogMode;

typedef enum { FogSlope0 = 0 } FogSlope;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern u32 func_021BA960(char *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B294(u32,u32,u32,u32,u32,u16,u16);
extern void func_0204B92C(struct Obj *,u32);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u32 space);
extern void func_0204B404(struct Obj *p, const struct PtS *delta, u32 which);
extern void func_020434DC(unsigned, unsigned);
extern void func_0207DC44(int, FogMode, FogSlope, int);
extern void func_0207DD24(unsigned short, int, int, int, int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned, unsigned);
void func_021BA290(char *ctx);
void func_021BA2EC(char *p);
void func_021BA328(char *p);
void func_021BA4B4(char *p);
struct Obj *func_021BA4D4(u32 owner,char *p);
void func_021BA4FC(char *ctx);
void func_021BA554(const char *p,int delta);
void func_021BA61C(char *ctx);
void func_021BA680(char *p,int v);
void func_021BA6BC(char *p,int y);
void func_021BA6E8(u32 p, int sel, u32 y);
int func_021BA720(u32 base,u32 i,u32 space,int y);
int func_021BA75C(char *p, int v);
unsigned int func_021BA780(int v);
void func_021BA7A4(void);
extern struct Config d_021BAB68;
extern const Config d_021BABC8, d_021BAB98, d_021BABB0, d_021BAB80;
extern int tbl_021BAC80[];
extern const unsigned short d_021BAED8[];



void func_021BA290(char *ctx)
{
    unsigned short heap = ((struct Obj00243 *)ctx)->f0;
    void *archive;
    *(int *)&((struct Obj00243 *)ctx)->f2D0 = -1;
    *(int *)&((struct Obj00243 *)ctx)->f2D4 = -1;
    *(int *)&((struct Obj00243 *)ctx)->f2D8 = -1;
    archive = func_020490F4(193, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D0 = func_0204A6C8((void *)((unsigned)archive), 10, 0, 2, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D4 = func_0204ABF0((void *)archive, 11, 2, 96, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D8 = func_0204AF28((void *)((unsigned)archive), 9, 8, heap);
    func_02049238(archive);
}



void func_021BA2EC(char *p){if(((struct Obj01983 *)p)->f2D0!=-1)func_0204A8D4(((struct Obj01983 *)p)->f2D0);if(((struct Obj01983 *)p)->f2D4!=-1)func_0204ADA4(((struct Obj01983 *)p)->f2D4);if(((struct Obj01983 *)p)->f2D8!=-1)func_0204AFD8(((struct Obj01983 *)p)->f2D8);}



void func_021BA328(char *p)
{
    Config a,b,c,d,e;
    void *manager,*item;
    int i,j;
    manager=(void *)func_021BA960(((struct Obj00243 *)p)->f4);
    for(j=0;j<36;j++)*(u32 *)(p+0x240+j*4)=0;
    a=d_021BABC8;
    a.c=((struct Obj00243 *)p)->f2D0;a.d=((struct Obj00243 *)p)->f2D4;a.e=((struct Obj00243 *)p)->f2D8;
    ((struct Obj00243 *)p)->f240=func_021BA4D4((u32)manager,(char *)(&a));
    b=d_021BAB68;
    b.c=((struct Obj00243 *)p)->f2D0;b.d=((struct Obj00243 *)p)->f2D4;b.e=((struct Obj00243 *)p)->f2D8;
    for(i=0;i<20;i++)*(void **)(p+0x244+i*4)=func_021BA4D4((u32)manager,(char *)(&b));
    c=d_021BAB98;
    c.c=((struct Obj00243 *)p)->f2D0;c.d=((struct Obj00243 *)p)->f2D4;c.e=((struct Obj00243 *)p)->f2D8;
    for(j=0;j<7;j++) {
        item=func_021BA4D4((u32)manager,(char *)(&c));
        func_0204B3DC(item,0);
        *(void **)(p+0x294+j*4)=item;
    }
    d=d_021BABB0;
    d.c=((struct Obj00243 *)p)->f2D0;d.d=((struct Obj00243 *)p)->f2D4;d.e=((struct Obj00243 *)p)->f2D8;
    for(i=0;i<7;i++) {
        item=func_021BA4D4((u32)manager,(char *)(&d));
        func_0204B688(item,1);
        func_0204B3DC(item,0);
        *(void **)(p+0x2b0+i*4)=item;
    }
    e=d_021BAB80;
    e.c=((struct Obj00243 *)p)->f2D0;e.d=((struct Obj00243 *)p)->f2D4;e.e=((struct Obj00243 *)p)->f2D8;
    ((struct Obj00243 *)p)->f2CC=func_021BA4D4((u32)manager,(char *)(&e));
}




void func_021BA4B4(char *p)
{
    int i;
    for (i = 0; i < 0x24; i++)
    {
        void *q = *(void **)(p + 0x240 + i * 4);
        if (q != 0)
        {
            func_0204B3B4(q);
        }
    }
}



struct Obj *func_021BA4D4(u32 owner,char *p){struct Obj *r;r=(struct Obj *)func_0204B294(owner,((struct Obj08448 *)p)->f8,((struct Obj08448 *)p)->fC,((struct Obj08448 *)p)->f10,(u32)p,((struct Obj08448 *)p)->f16,122);func_0204B92C(r,1);return r;}



void func_021BA4FC(char *ctx)
{
    int i;
    void *item;
    if (((struct Obj14773 *)ctx)->f32C != 0) {
        ((struct Obj14773 *)ctx)->f32C = 0;
        for (i = 0; i < 7; i++) {
            item = *(void **)(ctx + 0x294 + i * 4);
            if (func_0204B3F4(item) != 0)
                func_0204B3DC(item, 0);
        }
        for (i = 0; i < 7; i++) {
            item = *(void **)(ctx + 0x2b0 + i * 4);
            if (func_0204B3F4(item) != 0)
                func_0204B3DC(item, 0);
        }
    }
}



static inline void scroll(const char *p,short delta,int space,Pair_021BA290 *pos)
{
    void *item;
    long i;
    int value;
    for(i=0;i<7;i++){
        if(space==0)item=((struct Row0 *)(p+i*4))->item;
        else item=((struct Row1 *)(p+i*4))->item;
        if(func_0204B3F4(item)){
            func_0204B454(item,(struct PtS *)pos,space);
            pos->y+=delta;
            value=pos->y;
            func_0204B404(item,(const struct PtS *)pos,space);
            if(space==0){
                if(value<=-20 || value>=220)func_0204B3DC(item,0);
            }else{
                if(value<=-28 || value>=212)func_0204B3DC(item,0);
            }
        }
    }
}



static inline void scrollSecond(const char *p,short delta,int space,Pair_021BA290 *pos)
{
    long i;
    void *item;
    int value;
    for(i=0;i<7;i++){
        if(space==0)item=((struct Row0 *)(p+i*4))->item;
        else item=((struct Row1 *)(p+i*4))->item;
        if(func_0204B3F4(item)){
            func_0204B454(item,(struct PtS *)pos,space);
            pos->y+=delta;
            value=pos->y;
            func_0204B404(item,(const struct PtS *)pos,space);
            if(space==0){
                if(value<=-20 || value>=220)func_0204B3DC(item,0);
            }else{
                if(value<=-28 || value>=212)func_0204B3DC(item,0);
            }
        }
    }
}



/*
 * checks: 1 actor accessor/unit bodies fix return and three-argument position calls; 2 ov218 A61C confirms Pair_021BA290 ABI, no two-loop twin; 3 long index and const p each unchanged; 4 inline short-parameter helper reproduces both raw-parameter recasts, shared Pair_021BA290 fixes frame; 5 full idiom listing and A61C/other ov218 callers reread.
 * Two manual scheduling variants used; once-only permuter 300/jobs1/types unchanged, emitted baseline agrees at DIFF 200/200 with 9 concrete bytes.
 * single-lever: separate inline helpers use item-before-index in the first loop and index-before-item in the second; shared helper order swaps one loop's r4/r5 pair (9 bytes out).
 */
void func_021BA554(const char *p,int delta)
{
    Pair_021BA290 pos;
    scroll(p,delta,0,&pos);
    scrollSecond(p,delta,1,&pos);
}


/*
 * single-lever: row base retains ctx+i*4; fields at 244/2DC reproduce rematerialized id offset instead of hoisting a second array base.
 */
void func_021BA61C(char *ctx)
{
    int i;
    void *item;
    Pair_021BA61C pos;
    Row *row;
    for (i = 0; i < 20; i++) {
        row = (Row *)(ctx + i * 4);
        item = row->item;
        if (row->id == 65535) {
            func_0204B3DC(item, 0);
        } else {
            func_0204B454(item, (struct PtS *)&pos, 65535);
            pos.y = row->id * 2 + 92;
            func_0204B404(item, (const struct PtS *)(&pos), 65535);
        }
    }
}



/*
 * extent: 2 zero alignment bytes at 021BA6BA.
 */
void func_021BA680(char *p,int v){PtS pos;s16 y;void *o;o=((struct Obj03959 *)p)->f2CC;y=(s16)v;if(y<16)y=16;else if(y>152)y=152;func_0204B454(o,&pos,0);pos.y=y;func_0204B404(o,&pos,0);}




void func_021BA6BC(char *p,int y){PtS pos;void *o=((struct Obj03959 *)p)->f240;func_0204B454(o,&pos,65535);pos.y=y;func_0204B404(o,&pos,65535);}




void func_021BA6E8(u32 p, int sel, u32 y)
{
    u32 base;
    u32 space;
    int i;
    int n;
    if (sel) {
        space = 0;
        base = p + 0x294;
        n = 7;
    } else {
        space = 1;
        base = p + 0x2B0;
        n = 7;
    }
    for (i = 0; i < n; i++) {
        if (func_021BA720(base, i, space, y)) break;
    }
}



int func_021BA720(u32 base,u32 i,u32 space,int y){PtS pos;int r;void *o;o=*(void **)(base+i*4);r=0;if(func_0204B3F4(o)==0){func_0204B3DC(o,1);r=1;func_0204B454(o,&pos,space);pos.y=y;func_0204B404(o,&pos,space);}return r;}



int func_021BA75C(char *p, int v)
{
    int i;
    for (i = 0; i < 0x14; i++)
    {
        if (v == *(int *)(p + 0x2dc + i * 4))
        {
            return 1;
        }
    }
    return 0;
}




unsigned int func_021BA780(int v)
{
    int i;
    for (i = 0; i < 0x82; i++)
    {
        if (v == tbl_021BAC80[i])
        {
            break;
        }
    }
    if (i >= 0x82)
    {
        return 0xffff;
    }
    return i;
}



void func_021BA7A4(void)
{
    unsigned i;
    func_020434DC(1, 1);
    *(volatile unsigned short *)0x04000008 = *(volatile unsigned short *)0x04000008 & ~3;
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~(2 | 0x3000)) | 2;
    *(volatile unsigned short *)0x04000060 &= ~(0x10 | 0x3000);
    *(volatile unsigned short *)0x04000060 &= ~(4 | 0x3000);
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~0x3000) | 8;
    *(volatile unsigned short *)0x04000060 &= ~(0x20 | 0x3000);
    func_0207DC44(0, 0, 0, 0);
    func_0207DD24(0, 0, 0x7fff, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        func_02046A94((unsigned char)i, &d_021BAED8[i * 4]);
    func_02046BE0(0, 0);
}
