/*
 * file:     irc_ranking_p01.c
 * unit:     yes
 * function: func_021B7560, func_021B7798, func_021B7848, func_021B7890
 * address:  0x021B7560
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   fill 0x02082BCC arm
 *   func_020120F4 0x020120F4 thumb
 *   func_020124F4 0x020124F4 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_021B8B9C 0x021B8B9C thumb ov106
 *   func_021B7FF8 0x021B7FF8 thumb ov106
 *   func_021B80B0 0x021B80B0 thumb ov106
 *   func_02025538 0x02025538 thumb
 *   func_021B78E0 0x021B78E0 thumb ov106
 *   func_021B8D90 0x021B8D90 thumb ov106
 *   func_021B8FB8 0x021B8FB8 thumb ov106
 *   func_021B80AC 0x021B80AC thumb ov106
 *   func_021B80D0 0x021B80D0 thumb ov106
 *   func_021B70DC 0x021B70DC thumb ov101
 *   func_020490F4 0x020490F4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 *   func_021B92D4 0x021B92D4 thumb ov106
 *   func_021B93D8 0x021B93D8 thumb ov106
 *   func_021B93DC 0x021B93DC thumb ov106
 *   func_021B9380 0x021B9380 thumb ov106
 *   d_021B94D4 0x021B94D4 data a4
 *   func_021B9360 0x021B9360 thumb ov106
 *   func_021B71C0 0x021B71C0 thumb ov101
 *   func_021B8304 0x021B8304 thumb ov106
 *   func_021B8FC4 0x021B8FC4 thumb ov106
 *   func_021B8D9C 0x021B8D9C thumb ov106
 *   func_021B78AC 0x021B78AC thumb ov106
 *   func_021B807C 0x021B807C thumb ov106
 *   func_021B8D5C 0x021B8D5C thumb ov106
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02025588 0x02025588 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02012704 0x02012704 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021B78B8 0x021B78B8 thumb ov106
 *   func_021B80A0 0x021B80A0 thumb ov106
 *   func_021B93E4 0x021B93E4 thumb ov106
 *   func_021B78CC 0x021B78CC thumb ov106
 *   func_02082BCC 0x02082BCC arm
 *   func_021B78D0 0x021B78D0 thumb ov106
 */
#include "../../matched/include/Obj00978.h"
#include "../../matched/include/Obj03744.h"
#include "../../matched/include/Obj22255.h"
#include "../../matched/include/Obj22256.h"

#define SLOT(p,i) (*(u8 **)((u8 *)((u32 *)(p)+(i))+0x62c))
struct Obj0203159C;
struct Ctx;
struct GfFont;
struct MsgBank;
struct PrintSys;
struct Rec;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct { s16 x,y; u16 a,b; } Entry;

typedef struct { s16 x,y; u16 flags; u8 a,b; } Pos;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void fill(void *,int,u32);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020124F4(u16);
extern u32 func_0201C440(void *);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_021B8B9C(void *sys, u16 heap);
extern void func_021B7FF8(u8 *,void *,u32);
extern void *func_021B80B0(u8 *);
extern u32 func_021B80AC(u8 *);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_021B78E0(u8 *a, int *state, u8 *p);
extern void func_021B8D90(void *,u32),func_021B8FB8(void *);
extern void func_021B80D0(u8 *p, u32 a1, u8 a2, u8 a3, u8 s0, u32 s1, void *s2, void *s3, u8 *s4, u16 heap);
extern void *func_021B70DC(u32 a, u32 b, u16 layer, u16 x, u8 y, u32 extra, u32 c, u32 d, u16 heap);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *);
extern void *func_021B92D4(const u8 *,u8,u8,int,u8,int,void *,void *,u16);
extern void func_021B93D8(u8 *,u16),func_021B93DC(u8 *,u32,u32,u32),func_021B9380(u8 *,void *,void *,int);
extern void func_021B9360(u8 *p);
extern void func_021B71C0(void *);
extern void func_021B8304(u8 *p);
extern void func_021B8FC4(void *);
extern void func_021B8D9C(void *);
extern void func_021B78AC(void *);
extern void func_021B807C(u8 *p);
extern void func_021B8D5C(u8 *p);
extern void func_0204ADA4(u32 i);
extern void func_02025588(void *);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02012704(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_021B78B8(u8 *);
extern void func_021B80A0(u8 *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern int func_021B93E4(u8 *p);
extern u32 func_021B78CC(u8 *);
extern void func_02082BCC(void *,unsigned char,unsigned int);
extern void func_021B78D0(unsigned char *,unsigned int);
int func_021B7560(void *sys,u32 unused,void **args);
int func_021B7798(void *a,int b,int *state,u8 *p);
int func_021B7848(int a, int b, int c, u8 *p);
void func_021B7890(unsigned char *p,unsigned int a,unsigned int b);
extern const Entry d_021B94D4[];

int func_021B7560(void *sys,u32 unused,void **args) {
    u8 *p;
    u32 e;
    void *arc;
    Pos pos;
    int i;
    func_0203064C(1,67,6<<16);
    p=func_0203159C(sys,0x648,67);
    fill(p,0,0x648);
    if(*args)((struct Obj00978 *)p)->f628=func_020120F4(*args);
    else ((struct Obj00978 *)p)->f628=func_020124F4(1);
    *(u32 *)&((struct Obj00978 *)p)->f61C=func_0201C440((void *)67);
    ((struct Obj00978 *)p)->f618=(u32)func_0201D7EC(23,0,0,0,67);
    ((struct Obj00978 *)p)->f620=func_02045B38(0,2,50,67);
    ((struct Obj00978 *)p)->f63C=(unsigned int)func_021B8B9C(((struct Obj00978 *)p)->f628,67);
    func_021B7FF8(p,((struct Obj00978 *)p)->f628,67);
    ((struct Obj00978 *)p)->f624=func_02025538(67,func_021B80B0(p));
    func_021B7890(p+0x28,(unsigned int)p,(u32)func_021B78E0);
    func_021B8D90(p+0x5d4,67);func_021B8FB8(p+0x600);
    e=func_021B80AC(p);
    func_021B80D0(p+0x38,1,2,5,6,e,func_021B80B0(p),((struct Obj00978 *)p)->f620,(u8 *)(((struct Obj00978 *)p)->f63C),67);
    ((struct Obj00978 *)p)->f614=func_021B70DC(2,(u32)func_021B80B0(p),4,13,0,2,((struct Obj00978 *)p)->f618,*(u32 *)&((struct Obj00978 *)p)->f61C,67);
    arc=func_020490F4(23,67);
    ((struct Obj00978 *)p)->f644=func_0204ACEC(arc,5,0,448,67);
    func_02049238(arc);
    fill(&pos,0,8);
    pos.x=8;pos.y=41;pos.a=0;pos.b=0;
    for(i=0;i<4;i++) {
        pos.x=d_021B94D4[i].x;pos.y=d_021B94D4[i].y;
        SLOT(p,i)=func_021B92D4((u8 *)&pos,d_021B94D4[i].a,d_021B94D4[i].b,*(int *)&((struct Obj00978 *)p)->f644,3,0,((struct Obj00978 *)p)->f624,((struct Obj00978 *)p)->f61C,67);
        func_021B93D8(SLOT(p,i),1088);
        func_021B93DC(SLOT(p,i),0,0,1);
        func_021B9380(SLOT(p,i),((struct Obj00978 *)p)->f620,(void *)(i+1),*(int *)&((struct Obj00978 *)p)->f618);
    }
    return 1;
}

int func_021B7798(void *a,int b,int *state,u8 *p)
{
 int i;
 for(i=0;i<4;i++)func_021B9360(*(void **)(p+0x62C+i*4));
 func_0204ADA4((u32)(((struct Obj03744 *)p)->f644));
 func_021B71C0(((struct Obj03744 *)p)->f614);
 func_021B8304(p+0x38);
 func_021B8FC4(p+0x600); func_021B8D9C(p+0x5D4);func_021B78AC(p+0x28);
 func_02025588(((struct Obj03744 *)p)->f624);func_021B807C(p);func_021B8D5C(((struct Obj03744 *)p)->f63C);
 func_02045C04(((struct Obj03744 *)p)->f620);func_0201D83C(((struct Obj03744 *)p)->f618);func_0201C4C0(((struct Obj03744 *)p)->f61C);
 if(*state==0)func_02012704(((struct Obj03744 *)p)->f628);
 func_020315D4(a);func_020306F0(67);return 1;
}

int func_021B7848(int a, int b, int c, u8 *p)
{
    int i;
    func_021B78B8(p + 0x28);
    func_021B80A0(p);
    func_0201C4E4((struct PrintSys *)(((struct Obj22255 *)p)->f61C));
    for (i = 0; i < 4; i++) func_021B93E4((u8 *)(*(u32 *)(p + 0x62C + i * 4)));
    if (func_021B78CC(p + 0x28)) return 1;
    return 0;
}

void func_021B7890(unsigned char *p,unsigned int a,unsigned int b) { func_02082BCC(p,0,16); ((struct Obj22256 *)p)->fC=a; func_021B78D0(p,b); }
