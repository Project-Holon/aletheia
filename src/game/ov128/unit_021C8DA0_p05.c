/*
 * file:     unit_021C8DA0_p05.c
 * unit:     yes
 * function: func_021C9730, func_021C97A0, func_021C987C, func_021C98EC, func_021C991C, func_021C9BC4, func_021C9BEC, func_021C9BF8, func_021C9CCC, func_021C9D0C, func_021C9D88, func_021C9E10, func_021C9E54, func_021C9E6C, func_021C9EB4, func_021C9ED0
 * address:  0x021C9730
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CA444 0x021CA444 thumb ov128
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_021C9EFC 0x021C9EFC thumb ov128
 *   func_021C9EF0 0x021C9EF0 thumb ov128
 *   func_020452E8 0x020452E8 arm
 *   func_021C6BCC 0x021C6BCC thumb ov128
 *   func_021C6ADC 0x021C6ADC thumb ov128
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021C6E18 0x021C6E18 thumb ov128
 *   func_021C6DD8 0x021C6DD8 thumb ov128
 *   func_02041300 0x02041300 arm
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   func_021CA4C8 0x021CA4C8 thumb ov128
 *   func_021C9F6C 0x021C9F6C thumb ov128
 *   func_0201283C 0x0201283C thumb
 *   func_02009864 0x02009864 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045748 0x02045748 arm
 *   func_021B6B2C 0x021B6B2C thumb ov067
 *   func_021C9FC8 0x021C9FC8 thumb ov128
 *   func_021C6C94 0x021C6C94 thumb ov128
 *   func_021C6C20 0x021C6C20 thumb ov128
 *   func_02045334 0x02045334 arm
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 *   func_02025C88 0x02025C88 thumb
 *   func_0202DA04 0x0202DA04 thumb
 *   func_0202DA48 0x0202DA48 thumb
 *   func_0202DA18 0x0202DA18 thumb
 *   func_0202DA6C 0x0202DA6C thumb
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   d_021CA640 0x021CA640 data a2
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020410D0 0x020410D0 arm
 *   d_021CA544 0x021CA544 data a1
 *   d_021CA4F7 0x021CA4F7 data a1
 *   d_021CA554 0x021CA554 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02049EF4 0x02049EF4 arm
 *   d_021CA648 0x021CA648 data a2
 *   func_020307B0  0x020307B0  arm
 *   func_021C63AC 0x021C63AC thumb ov128
 *   d_021CA5A2 0x021CA5A2 data a2
 */
#include "../../matched/include/Obj00773.h"
#include "../../matched/include/Obj00992.h"
#include "../../matched/include/Obj00329.h"
#include "../../matched/include/Obj02842.h"
#include "../../matched/include/Obj10494.h"
#include "../../matched/include/Obj14046.h"
#include "../../matched/include/Obj00227.h"
#include "../../matched/include/Obj23107.h"
#include "../../matched/include/Obj23108.h"
#include "../../matched/include/Obj23109.h"
#include "../../matched/include/Obj08133.h"

struct Descriptor;
struct BigObj;
struct CharBuf;
struct Sub020097BCObj;
struct Obj;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed char s8;

typedef struct {u16 v[4];} Bounds;

typedef signed int     s32;

extern void func_021CA444(char *p);
extern void func_021CA458(char *p, void *q);
extern void func_021C9EFC(void *,int);
extern void func_021C9EF0(void *);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021C6BCC(u8 *,u8 *,int,unsigned);
extern void func_021C6ADC(u8 *,u8 *,unsigned);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041B6C(u32);
extern void func_021C6E18(u8 *p, int i, u16 a);
extern void func_021C6DD8(u8 *p, u32 a);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void func_021C6B38(u8 *p);
extern void func_021CA4C8(int *p);
extern void func_021C9F6C(char *p, void *q);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u8 func_02045748(struct Descriptor *p);
extern void func_021B6B2C(u32 a0, void *a1, u32 a2, u16 a3, u16 a4, u16 a5, u32 a6, u32 a7, u16 heap);
extern void func_021C9FC8(u8 *,void *,u8 *,u32,int,int,int);
extern void func_021C6C94(char **,int);
extern int func_021C6C20(u8 *,u8 *,int);
extern void func_02045334(struct Descriptor *),func_021CA4B4(char *);
extern u32 func_02025C88(u32);
extern int func_0202DA04(int);
extern u32 func_0202DA48(u32,u32,u32,u32);
extern s32 func_0202DA18(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int func_0202DA6C(int a0, int a1, int a2, unsigned short a3);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern u32 func_020307B0(void *p);
extern void func_021C63AC(void *,u32 *,u32,u32,u8,u8,u8,u8,u32,u8);
void func_021C9730(u8 *p,void *unused,u8 *q);
void func_021C97A0(u8 *p,u8 *q,u8 *r,u16 heap);
void func_021C987C(u8 *p,u8 *q);
void func_021C98EC(char *p,u8 *q);
void func_021C991C(u8 *p,u8 *q,u8 *ctx,u16 heap);
void func_021C9BC4(u32 p);
void func_021C9BEC(u16 *p, void *b, void *c, int flag, int value, int a5);
void func_021C9BF8(u8 *p,u8 *q,int idx);
void func_021C9CCC(void *unused,u8 *p);
int func_021C9D0C(u8 *p,int direction);
int func_021C9D88(u8 *p,int direction);
void func_021C9E10(u8 *p,u8 *q,u16 heap);
void func_021C9E54(u8 *p);
void func_021C9E6C(u8 *p,void *q);
void func_021C9EB4(u8 *p, void *a1);
void func_021C9ED0(u32 p,int unused,const u16 *q,u32 value,u16 heap);
extern const Bounds d_021CA640;
extern const u8 d_021CA544[],d_021CA4F7[],d_021CA554[];
extern const u16 d_021CA648[4];
extern const u8 d_021CA5A2[10][4];

/*
 * extent: two-byte zero padding at 021C979E before next label 021C97A0.
 */
void func_021C9730(u8 *p,void *unused,u8 *q)
{
    u8 *base;
    int j;
    int i;
    func_021CA444((char *)q);
    func_021CA458((char *)q,q+12);
    base=p+20;
    for(i=0;i<3;i++) {
        for(j=0;j<8;j++) func_021C9EFC(base+i*76,j);
        func_021C9EF0(base+i*76);
    }
    for(i=0;i<2;i++) func_020452E8(*(void **)(p+i*8+0x118));
    func_021C9EB4(p,q);
    p+=0xf8;
    func_021C9E54(p);
}

/*
 * lever: u16 heap keeps its word spill before the first indexed load.
 */
void func_021C97A0(u8 *p,u8 *q,u8 *r,u16 heap)
{
    u16 *t;
    func_021C6BCC(r,(u8 *)q,(q+((struct Obj00992 *)q)->fB)[24],heap);
    func_021C6ADC(r,r+12,13);
    t=*(u16 * *)&((struct Obj00773 *)p)->fFC;
    func_02041090(0,(u32)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(0);
    t=*(u16 * *)&((struct Obj00773 *)p)->f104;
    func_02041090(2,(u32)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(2);
    func_021C991C(p,(u8 *)q,r,heap);
    func_021C9BEC((u16 *)p,(u8 *)q,r,0,*(s16 *)&((struct Obj00773 *)p)->f0,heap);
    if(func_021C9D88((u8 *)q,0)==1) {
        func_021C6E18(r,1,3);
        func_021C6E18(r,0,2);
    } else {
        func_021C6E18(r,1,17);
        func_021C6E18(r,0,16);
    }
    func_021C6DD8(r,1);
}

void func_021C987C(u8 *p,u8 *q)
{
    u16 *t;
    func_021C6DD8(q,0);
    func_021C9CCC(p,q);
    func_021C9BC4((u32)p);
    func_02041300(2,0,0,0,32,32,0);
    func_02041B6C(2);
    t=*(u16 * *)&((struct Obj00773 *)p)->f10C;
    func_02041090(0,(u32)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(0);
    func_021C6B38(q);
    func_021CA4C8((int *)p);
}

void func_021C98EC(char *p,u8 *q) {char *base;int i;i=0;base=p+20;for(;i<3;i++) func_021C9F6C(base+i*76,q);func_021C6B38(q);func_021CA4C8((int *)p);}

/*
 * calls: 0202DA18/48 and 0204B294 leave the consumed handle in r0 despite
 * their void declarations. Heap externs are widened when no truncation
 * occurs. 0202DA04's legacy a1-a3 are neither read nor forwarded.
 * bounds: two unsigned loops cover ten eight-byte records at p+0x128;
 * signed q[11] accesses retain modular address arithmetic.
 */
void func_021C991C(u8 *p,u8 *q,u8 *ctx,u16 heap)
{
    u32 i,base,id,archive,offset;
    int pos;
    Bounds bounds;
    base=func_0201283C(((struct Obj00992 *)q)->f4);
    func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),9);
    for(i=0;i<10;i++) func_02043B5C(func_02045770(*(void **)(p+i*8+0x128)),0);
    offset=0x128;
    pos=func_02045748(*(void **)(p+offset));
    func_021B6B2C((u32)(p+offset),(void *)(*(u32 *)&((struct Obj00329 *)ctx)->f34),*(u32 *)&((struct Obj00329 *)ctx)->f17C,
        (int)((u32)pos*8)/2,0,0x3C40,
        *(u8 *)((u32)q+((struct Obj00992 *)q)->fB+0x38)+1,((struct Obj00992 *)q)->f14,heap);
    func_021C9FC8(p+(offset+8),q,ctx,19,0,0,0x3C40);
    func_021C9FC8(p+(offset+16),q,ctx,20,0,0,0x3C40);
    func_021C9FC8(p+0x140,q,ctx,21,0,0,0x3C40);
    func_021C6C94((char **)ctx,func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),2));
    func_021C9FC8(p+(offset+32),q,ctx,22,0,0,0x3C40);
    func_021C6C94((char **)ctx,func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),3));
    func_021C9FC8(p+0x150,q,ctx,22,0,0,0x3C40);
    func_021C9FC8(p+(offset+48),q,ctx,23,0,0,0x3C40);
    func_021C6C94((char **)ctx,func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),4));
    func_021C9FC8(p+0x160,q,ctx,24,0,0,0x3C40);
    func_021C9FC8(p+(offset+=64),q,ctx,27,0,0,0x3C40);
    if(func_021C6C20(ctx,q,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24))!=0)
        func_021C9FC8(p+0x170,q,ctx,28,0,0,0x3C40);
    else func_02045334(((struct Obj00773 *)p)->f170);
    for(i=0;i<10;i++) func_021CA4B4(*(char **)(p+i*8+0x128));
    bounds=d_021CA640;
    id=func_02025C88(func_02009864((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((struct Obj00992 *)q)->fB+24),8));
    archive=func_0202DA04(heap);
    ((struct Obj00773 *)p)->f17C=func_0202DA48(archive,id,0,heap);
    ((struct Obj00773 *)p)->f180=func_0202DA18(archive,id,0,192,heap);
    ((struct Obj00773 *)p)->f184=func_0202DA6C(id,2,0,heap);
    func_02049238((void *)archive);
    ((struct Obj00773 *)p)->f178=(u32)func_0204B294((void *)((struct Obj00329 *)ctx)->f138,((struct Obj00773 *)p)->f17C,
        ((struct Obj00773 *)p)->f180,((struct Obj00773 *)p)->f184,&bounds,0,heap);
}

void func_021C9BC4(u32 p) { int i;void *q;for(i=0;i<10;i++) {q=*(void **)(p+296+i*8);func_020456F8(q);func_02041B6C(func_02045730(q));}}

void func_021C9BEC(u16 *p, void *b, void *c, int flag, int value, int a5) { if(flag==0) *p=value; }

/*
 * lever: the table value in r1 supplies both destination x and clip x;
 * raw u32 address arithmetic preserves base-plus-row accesses without
 * imposing unproven row or index bounds; all shifts/adds wrap at 32 bits.
 */
void func_021C9BF8(u8 *p,u8 *q,int idx)
{
    u16 *t;
    if (((struct Obj02842 *)p)->f10==1) {
        t=*(u16 * *)&((struct Obj10494 *)q)->f178;
        func_020410D0(2,0,20,32,4,(u32)((u8 *)t+12),0,12,(u32)t[0]>>3,(u32)t[1]>>3);
    } else {
        t=*(u16 * *)&((struct Obj10494 *)q)->f178;
        func_020410D0(2,0,20,32,4,(u32)((u8 *)t+12),0,20,(u32)t[0]>>3,(u32)t[1]>>3);
    }
    if (idx==255) {
        func_02041B6C(2);
        return;
    }
    t=*(u16 * *)&((struct Obj10494 *)q)->f178;
    func_020410D0(2,*(const u8 *)((u32)d_021CA544+((u32)((struct Obj02842 *)p)->f10<<3)+(u32)idx),20,
        *(const u8 *)((u32)d_021CA554+((u32)((struct Obj02842 *)p)->f10<<3)+(u32)idx),4,(u32)((u8 *)t+12),
        *(const u8 *)((u32)d_021CA544+((u32)((struct Obj02842 *)p)->f10<<3)+(u32)idx),
        *(const u8 *)((u32)d_021CA4F7+(u32)((struct Obj02842 *)p)->f10),(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(2);
}

void func_021C9CCC(void *unused,u8 *p)
{
    u16 *q = *(u16 * *)&((struct Obj14046 *)p)->f178;
    func_020410D0(2,0,20,32,4,(u32)((u8 *)q+12),0,28,(u32)q[0]>>3,(u32)q[1]>>3);
    func_02041B6C(2);
}

/*
 * extent: two-byte zero padding at 021C9D86 before next label 021C9D88.
 */
int func_021C9D0C(u8 *p,int direction)
{
    int index;
    u32 data;
    u32 count;
    data=func_0201283C(((struct Obj00227 *)p)->f4);
    index=*(s8 *)&((struct Obj00227 *)p)->fB;
    if(direction==0) {
        for(count=0;count<((struct Obj00227 *)p)->f10-1;count++) {
            index--;
            if(index<0) index+=((struct Obj00227 *)p)->f10;
            if(func_02009864((const struct Sub020097BCObj *)data,p[index+24],9)!=2) {
                p[11]=index;
                return 1;
            }
        }
    } else {
        for(count=0;count<((struct Obj00227 *)p)->f10-1;count++) {
            index=(u32)(index+1)%((struct Obj00227 *)p)->f10;
            if(func_02009864((const struct Sub020097BCObj *)data,p[index+24],9)!=2) {
                p[11]=index;
                return 1;
            }
        }
    }
    return 0;
}

/*
 * extent: two-byte zero padding at 021C9E0E before next label 021C9E10.
 * lever: writing the reloaded signed byte on the left of == fixes both cmp operands.
 */
int func_021C9D88(u8 *p,int direction)
{
    int index;
    u32 data;
    u32 count;
    data=func_0201283C(((struct Obj00992 *)p)->f4);
    index=((struct Obj00992 *)p)->fB;
    if(direction==0) {
        for(count=0;count<((struct Obj00992 *)p)->f10-1;count++) {
            index--;
            if(index<0) index+=((struct Obj00992 *)p)->f10;
            if(((struct Obj00992 *)p)->fB==index) goto fail;
            if(func_02009864((const struct Sub020097BCObj *)data,p[index+24],9)!=2) return 1;
        }
    } else {
        for(count=0;count<((struct Obj00992 *)p)->f10-1;count++) {
            index=(u32)(index+1)%((struct Obj00992 *)p)->f10;
            if(((struct Obj00992 *)p)->fB==index) goto fail;
            if(func_02009864((const struct Sub020097BCObj *)data,p[index+24],9)!=2) return 1;
        }
    }
fail:
    return 0;
}

void func_021C9E10(u8 *p,u8 *q,u16 heap)
{
    u16 ids[4];
    int i;
    ids[0]=d_021CA648[0]; ids[1]=d_021CA648[1];
    ids[2]=d_021CA648[2]; ids[3]=d_021CA648[3];
    for(i=0;i<4;i++) {
        ((struct Obj23107 *)p)->f0=func_02049EF4(((struct Obj23108 *)q)->f8,ids[i],0,(void **)(p+4),heap);
        p+=8;
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C9E54(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        func_020307B0(((struct Obj23109 *)p)->f0);
        p += 8;
    }
}

void func_021C9E6C(u8 *p,void *q)
{
    int i;
    p+=0x128;
    for(i=0;i<10;i++)
        func_021C63AC(q,(u32 *)(p+i*8),1,d_021CA5A2[i][0],d_021CA5A2[i][1],d_021CA5A2[i][2],d_021CA5A2[i][3],10,0,0);
}


void func_021C9EB4(u8 *p, void *a1)
{
    int i;
    for (i = 0; i < 10; i++)
        func_020452E8(*(void **)(p + 0x128 + i * 8));
}

void func_021C9ED0(u32 p,int unused,const u16 *q,u32 value,u16 heap) { int i; ((struct Obj08133 *)p)->f8=value; ((struct Obj08133 *)p)->f0=q[0]; ((struct Obj08133 *)p)->f2=q[1]; ((struct Obj08133 *)p)->f4=q[2]; for(i=0;i<8;i++) *(u32 *)(p+44+i*4)=0; }
