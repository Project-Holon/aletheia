/*
 * file:     br_btn_p13.c
 * unit:     yes
 * function: func_021FB7D0, func_021FB884, func_021FB92C, func_021FB964, func_021FBDA4, func_021FBE54, func_021FC0C8, func_021FC124, func_021FC148, func_021FC1F8, func_021FC20C, func_021FC214, func_021FC21C, func_021FC224, func_021FC230, func_021FC238, func_021FC240, func_021FC31C, func_021FC344, func_021FC36C, func_021FC394
 * address:  0x021FB7D0
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020458F8 0x020458F8 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045808 0x02045808 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC74 0x0201EC74 thumb
 *   d_02200D3C 0x02200D3C data a1
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   d_02200D48       0x02200D48  data
 *   func_02034714    0x02034714  arm
 *   func_0204A6C8    0x0204A6C8  arm
 *   func_0204AC18    0x0204AC18  arm
 *   func_0204AF28    0x0204AF28  arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02049B68 0x02049B68 arm
 *   func_021FE8E8 0x021FE8E8 thumb ov186
 *   d_022008C0 0x022008C0 data a4
 *   d_022008A0 0x022008A0 data a4
 *   d_02200880 0x02200880 data a4
 *   d_022008E0 0x022008E0 data a4
 */
#include "../../matched/include/Obj10788.h"
#include "../../matched/include/Obj02235.h"
#include "../../matched/include/Obj01770.h"
#include "../../matched/include/Obj24829.h"
#include "../../matched/include/Obj24830.h"
#include "../../matched/include/Obj24831.h"
#include "../../matched/include/Obj24832.h"
#include "../../matched/include/Obj24833.h"
#include "../../matched/include/Obj24834.h"
#include "../../matched/include/Obj05501.h"

struct MsgBank;
struct WordSet;
struct U16Vec;
struct GfFont;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Object {char pad[0xe8];void *a,*b,*c;volatile unsigned flag,mode;} Object;

struct Rec {void *a,*b;unsigned char pad[12];void *handle;};

typedef signed int     s32;

typedef struct {unsigned a,b,c;} Triple;

typedef unsigned char u8;

typedef signed char s8;

typedef signed short s16;

extern int func_021FB7B0(void *,int);
extern struct WordSet *func_0201EC64(unsigned int heap);
extern void func_0201EE0C(struct WordSet *p, unsigned int i, const void *src, unsigned int n, unsigned int f, unsigned int c);
extern void *func_02045EC0(struct MsgBank *bank, unsigned int index);
extern u16 func_020458F8(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);
extern void func_02082BCC(void *,int,int);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201EC74(unsigned,unsigned,unsigned);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201D83C(void *ptr);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern void func_02049238(void *);
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 index);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_0204A6C8(void *h, u32 a1, u32 a2, u32 a3, u32 s0);
extern u32 func_0204AC18(void *h, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_021FE8E8(char *p, void *arc, u32 file, u32 idx, u32 off, u32 count, u16 tag);
void *func_021FB7D0(unsigned *const *p,void *record,struct MsgBank *archive,unsigned short heap);
void *func_021FB884(unsigned mode,unsigned flag,unsigned heap);
void func_021FB92C(char *p);
void func_021FB964(void *ctx,unsigned kind,unsigned short heap);
void func_021FBDA4(int a,unsigned mode);
void func_021FBE54(char *base, u32 idx, u32 area);
void func_021FC0C8(char *p,unsigned i);
int func_021FC124(char *p,unsigned i,Triple *out);
void func_021FC148(char *p,unsigned i,unsigned heap);
void func_021FC1F8(int *p, int i);
unsigned func_021FC20C(char *p);
int func_021FC214(char *p);
int func_021FC21C(char *p);
int func_021FC224(char *p);
void func_021FC230(char *p,int v);
int func_021FC238(char *p);
void func_021FC240(char *p,void *owner,unsigned short heap);
unsigned short func_021FC31C(unsigned i);
unsigned short func_021FC344(unsigned i);
unsigned short func_021FC36C(unsigned i);
u16 func_021FC394(u32 n);
extern const char d_02200D3C[];
extern char d_02200D48[];
extern const unsigned d_022008C0[];
extern const unsigned d_022008A0[];
extern const unsigned d_02200880[];
extern const u32 d_022008E0[];

void *func_021FB7D0(unsigned *const *p,void *record,struct MsgBank *archive,unsigned short heap)
{
    int n,index,ok;
    void *tmp,*src,*result;
    n=func_021FB7B0(record,11);
    ok=0;
    if(n>=1 && n<=4){index=n-1;ok=1;}
    if(ok){
        if((*p)[index]!=0){
            tmp=func_0201EC64((unsigned short)((heap&0x7fff)|0x8000));
            func_0201EE0C(tmp,0,(const void *)((*p+index)[4]),(*p+index)[8],1,2);
            src=func_02045EC0(archive,(int)func_021FB7B0(record,3));
            result=func_020457B0(func_020458F8(src)+7,heap);
            func_0201F250(tmp,result,src);
            func_0201ED04(tmp);
            func_02045808(src);
        }else{
            result=func_02045EC0(archive,(int)func_021FB7B0(record,3));
        }
    }else{
        result=func_02045EC0(archive,(int)func_021FB7B0(record,3));
    }
    return result;
}

/*
 * volatile: allocated fields +F4 and +F8 re-read after their stores at 021FB8B0 and 021FB8C0.
 */
void *func_021FB884(unsigned mode,unsigned flag,unsigned heap)
{
    Object *p;
    p=func_02030734(heap,0xfc,0,d_02200D3C,0x60);
    func_02082BCC(p,0,0xfc);
    p->flag=flag;
    if(p->flag){p->mode=mode;if(p->mode==1)p->mode=0;}
    else p->mode=1;
    p->a=func_0201D7EC(0x17,0,0,0,heap);
    p->b=func_02045B38(0,2,5,heap);
    p->c=func_0201EC74(8,0x40,heap);
    func_021FC148((char *)p,0,heap);
    func_021FC148((char *)p,1,heap);
    return p;
}

void func_021FB92C(char *p) {func_021FC1F8((int *)p,0);func_021FC1F8((int *)p,1);func_0201ED04(((struct Obj10788 *)p)->fF0);func_02045C04(*(struct Rec * *)&((struct Obj10788 *)p)->fEC);func_0201D83C(((struct Obj10788 *)p)->fE8);func_020307B0(p);}

void func_021FB964(void *ctx,unsigned kind,unsigned short heap)
{
    void *h;
    h=func_020490F4(0x89,heap);
    switch(kind) {
    case 0:
        func_02049658(h,0x26,3,0,0,0,heap);
        func_020498F4(h,0x28,3,0,0,0,heap);
        break;
    case 1:
        func_02049658(h,0x26,6,0,0,0,heap);
        func_020498F4(h,0x28,6,0,0,0,heap);
        break;
    case 2:
        func_02049658(h,0x6b,0,0,0,0,heap);
        func_020498F4(h,0x2,0,0,0,0,heap);
        break;
    case 3:
        func_02049658(h,0x26,2,0,0,0,heap);
        func_020498F4(h,0x27,2,0,0,0,heap);
        break;
    case 4:
        func_02049658(h,0x26,2,0,0,0,heap);
        func_020498F4(h,0x1a,2,0,0,0,heap);
        break;
    case 5:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x5,5,0,0,0,heap);
        break;
    case 6:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x2d,2,0,0,0,heap);
        break;
    case 7:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x2c,2,0,0,0,heap);
        break;
    case 8:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x2b,2,0,0,0,heap);
        break;
    case 9:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x61,5,0,0,0,heap);
        break;
    case 10:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x63,2,0,0,0,heap);
        break;
    case 11:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x64,2,0,0,0,heap);
        break;
    case 12:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x65,2,0,0,0,heap);
        break;
    case 13:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x66,2,0,0,0,heap);
        break;
    case 19:
        func_02049658(h,0x6b,2,0,0,0,heap);
        func_020498F4(h,0x2,2,0,0,0,heap);
        break;
    case 14:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x62,2,0,0,0,heap);
        break;
    case 15:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x67,5,0,0,0,heap);
        break;
    case 18:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x68,2,0,0,0,heap);
        break;
    case 17:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x69,2,0,0,0,heap);
        break;
    case 16:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x6a,2,0,0,0,heap);
        break;
    case 20:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1f,5,0,0,0,heap);
        break;
    case 21:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1d,5,0,0,0,heap);
        break;
    case 22:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0xd,5,0,0,0,heap);
        break;
    case 23:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0xe,5,0,0,0,heap);
        break;
    case 24:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x3,2,0,0,0,heap);
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,6,5,0,0,0,heap);
        break;
    case 25:
        func_02049658(h,0x21,2,0,0,0,heap);
        func_020498F4(h,0x1b,2,0,0,0,heap);
        break;
    case 26:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1e,5,0,0,0,heap);
        break;
    case 28:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x1c,5,0,0,0,heap);
        break;
    case 27:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x20,5,0,0,0,heap);
        break;
    case 29:
        func_02049658(h,0x26,5,0,0,0,heap);
        func_020498F4(h,0x12,5,0,0,0,heap);
        break;
    case 30:
        func_02049658(h,0x21,5,0,0,0,heap);
        func_020498F4(h,0x2f,5,0,0,0,heap);
        break;
    }
    func_02049238(h);
}

void func_021FBDA4(int a,unsigned mode)
{
    switch(mode){
    case 24:
        func_020414EC(2);func_020409B4(2);
        func_020414EC(5);func_020409B4(5);break;
    case 0:func_020414EC(3);func_020409B4(3);break;
    case 1:func_020414EC(6);func_020409B4(6);break;
    case 2:func_020414EC(0);func_020409B4(0);break;
    case 5:case 9:case 15:case 20:case 21:case 22:case 23:case 26:case 27:case 28:case 29:case 30:
        func_020414EC(5);func_020409B4(5);break;
    case 3:case 4:case 6:case 7:case 8:case 10:case 11:case 12:case 13:case 16:case 17:case 18:case 19:case 25:
        func_020414EC(2);func_020409B4(2);break;
    case 14:break;
    }
}


void func_021FBE54(char *base, u32 idx, u32 area)
{
    u32 *r4;

    r4 = (u32 *)(base + 8 + idx * 12);

    if (*(u32 *)(base + 0xb0 + idx * 4) != 0) {
        func_02034714(d_02200D48, 0, d_02200D48);
    }

    switch (idx) {
    case 4: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[1] = func_0204A6C8(h, 0x24, 0, 0, area);
        r4[0] = (u32)func_0204AF28(h, 0x15, 0x14, area);
        func_02049238(h);
        break;
    }
    case 5: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = func_0204A6C8(h, 0x24, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x15, 0x14, area);
        func_02049238(h);
        break;
    }
    case 0: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[1] = func_0204A6C8(h, 0x22, 0, 0, area);
        r4[0] = (u32)func_0204AF28(h, 9, 0xa, area);
        func_02049238(h);
        break;
    }
    case 1: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = func_0204A6C8(h, 0x22, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 9, 0xa, area);
        func_02049238(h);
        break;
    }
    case 2: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[1] = func_0204A6C8(h, 0x3f, 0, 0, area);
        r4[0] = (u32)func_0204AF28(h, 0x3d, 0x3e, area);
        func_02049238(h);
        break;
    }
    case 3: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = func_0204A6C8(h, 0x3f, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x3d, 0x3e, area);
        func_02049238(h);
        break;
    }
    case 6: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = func_0204A6C8(h, 0x23, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 7, 8, area);
        func_02049238(h);
        break;
    }
    case 8: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = func_0204A6C8(h, 0x56, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x55, 0x54, area);
        func_02049238(h);
        break;
    }
    case 7: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[1] = func_0204A6C8(h, 0x56, 0, 0, area);
        r4[0] = (u32)func_0204AF28(h, 0x55, 0x54, area);
        func_02049238(h);
        break;
    }
    case 11: {
        void *h = func_020490F4(0x89, area);
        r4[2] = func_0204AC18(h, 0x13, 1, 0x80, 0, 1, area);
        r4[1] = func_0204A6C8(h, 0xf, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x10, 0x11, area);
        func_02049238(h);
        break;
    }
    case 12: {
        void *h = func_020490F4(0x89, area);
        r4[2] = func_0204AC18(h, 0x33, 1, 0xa0, 0, 1, area);
        r4[1] = func_0204A6C8(h, 0x32, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x30, 0x31, area);
        func_02049238(h);
        break;
    }
    case 9: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[1] = func_0204A6C8(h, 0x36, 0, 0, area);
        r4[0] = (u32)func_0204AF28(h, 0x34, 0x35, area);
        func_02049238(h);
        break;
    }
    case 10: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f4;
        r4[1] = func_0204A6C8(h, 0x36, 0, 1, area);
        r4[0] = (u32)func_0204AF28(h, 0x34, 0x35, area);
        func_02049238(h);
        break;
    }
    case 13: {
        void *h = func_020490F4(0x89, area);
        r4[2] = ((struct Obj02235 *)base)->f0;
        r4[0] = (u32)func_0204AF28(h, 0x29, 0x2a, area);
        r4[1] = func_0204A6C8(h, 0x25, 0, 0, area);
        func_02049238(h);
        break;
    }
    default:
        break;
    }

    *(u32 *)(base + 0xb0 + idx * 4) = 1;
}

void func_021FC0C8(char *p,unsigned i)
{
    int *r=(int *)(p+8+i*12);
    switch(i){
    case 11: case 12:
        func_0204ADA4(r[2]);
        func_0204A8D4(r[1]);
        func_0204AFD8(r[0]);
        break;
    case 0: case 1: case 2: case 3: case 6: case 7: case 8: case 9: case 10: case 13:
        func_0204A8D4(r[1]);
        func_0204AFD8(r[0]);
        break;
    case 4: case 5: break;
    }
    *(int *)(p+0xb0+i*4)=0;
}

int func_021FC124(char *p,unsigned i,Triple *out) { if(*(int *)((unsigned)(p+0xb0)+i*4)) *out=*(Triple *)((unsigned)p+i*12+8);return *(int *)((unsigned)(p+0xb0)+i*4); }

void func_021FC148(char *p,unsigned i,unsigned heap)
{
    void *h;
    h=func_020490F4(0x89,heap);
    *(unsigned *)(p+i*4)=func_0204AC18(h,func_021FC31C(((struct Obj01770 *)p)->fF8),i,0,0,13,heap);
    if(i==0){
        func_02049B68(h,func_021FC344(((struct Obj01770 *)p)->fF8),0,0,0,heap);
        func_02049B68(h,func_021FC36C(((struct Obj01770 *)p)->fF8),0,0x1c0,0x20,heap);
    }else{
        func_02049B68(h,func_021FC344(((struct Obj01770 *)p)->fF8),4,0,0,heap);
        func_02049B68(h,func_021FC36C(((struct Obj01770 *)p)->fF8),4,0x1c0,0x20,heap);
    }
    func_02049238(h);
}


void func_021FC1F8(int *p, int i)
{
    func_0204ADA4(p[i]);
    p[i] = -1;
}

unsigned func_021FC20C(char *p) { return ((struct Obj24829 *)p)->fE8; }


int func_021FC214(char *p)
{
    return ((struct Obj24830 *)p)->fEC;
}

/*
 * trailing: two zero padding bytes at 021FC222, then existing matched 021FC224.
 */
int func_021FC21C(char *p)
{
    return ((struct Obj24831 *)p)->fF0;
}


/*
 * Extent runs long: 0x021FC230 is an unlabelled follower leaf (a plain
 * `p[0x3e] = v` setter), so this is EXACT*.
 */
int func_021FC224(char *p)
{
    return func_021FC394(((struct Obj24832 *)p)->fF8);
}

/*
 * blocker-leaf: ov183 021DB770; source/unit/shard ownership checked, parent cleared.
 */
void func_021FC230(char *p,int v){((struct Obj24833 *)p)->fF8=v;}

int func_021FC238(char *p) { return ((struct Obj24834 *)p)->fF8; }

/*
 * prototype: 490F4 receives full heap, no caller truncation; E8E8 reads stack heap halfword.
 */
void func_021FC240(char *p,void *owner,unsigned short heap)
{
    void *h;
    h=func_020490F4(0x89,heap);
    func_021FE8E8(owner,h,func_021FC31C(((struct Obj05501 *)p)->fF8),2,0,0x1C0,heap);
    func_021FE8E8(owner,h,func_021FC31C(((struct Obj05501 *)p)->fF8),3,0,0x1C0,heap);
    func_021FE8E8(owner,h,func_021FC344(((struct Obj05501 *)p)->fF8),0,0,0,heap);
    func_021FE8E8(owner,h,func_021FC344(((struct Obj05501 *)p)->fF8),1,0,0,heap);
    func_021FE8E8(owner,h,func_021FC36C(((struct Obj05501 *)p)->fF8),0,0xE0,0x20,heap);
    func_021FE8E8(owner,h,func_021FC36C(((struct Obj05501 *)p)->fF8),1,0xE0,0x20,heap);
    func_02049238(h);
}

unsigned short func_021FC31C(unsigned i) { if(i>=8)func_02034714(d_02200D48,0,d_02200D48);return d_022008C0[i]; }

unsigned short func_021FC344(unsigned i) { if(i>=8)func_02034714(d_02200D48,0,d_02200D48);return d_022008A0[i]; }

unsigned short func_021FC36C(unsigned i) { if(i>=8)func_02034714(d_02200D48,0,d_02200D48);return d_02200880[i]; }

u16 func_021FC394(u32 n){if(n>=8)func_02034714(d_02200D48,0,d_02200D48);return *(const u32*)((u32)d_022008E0+n*4);}
