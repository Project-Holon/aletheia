/*
 * file:     beacon_detail_gra_p02.c
 * unit:     yes
 * function: func_021BC0C8, func_021BC178, func_021BC1E4, func_021BC378, func_021BC398, func_021BC3D4, func_021BC3DC, func_021BC3E4, func_021BC43C
 * address:  0x021BC0C8
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203101C 0x0203101C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C450 0x0201C450 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC74 0x0201EC74 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02031140 0x02031140 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062A98 0x02062A98 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_020307B0 0x020307B0 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B62E0 0x021B62E0 thumb ov067
 *   d_021BDB4C 0x021BDB4C data a4
 *   func_021B639C 0x021B639C thumb ov067
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 */
#include "../../matched/include/Obj00366.h"
#include "../../matched/include/Obj01437.h"
#include "../../matched/include/Obj01591.h"
#include "../../matched/include/Obj25769.h"
#include "../../matched/include/Obj25770.h"
#include "../../matched/include/Obj10945.h"

struct Tcbl;
struct GfFont;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Rec;
struct PrintSys;
struct S02031140;
struct ArcFile;
struct NitroFileHeader;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {unsigned char *f0;unsigned f4;int f8;unsigned fC,f10,f14;int f18,f1c;} A;

typedef struct R R;

typedef struct S S;

typedef struct { unsigned char a,b,c,pad; unsigned short first,second,third; } Config;

typedef signed int     s32;

extern struct Tcbl *func_0203101C(u16 heap, u16 tag, unsigned int count, unsigned int workSize);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0201DD78(unsigned,unsigned,unsigned);
extern void *func_0201C450(unsigned short,unsigned);
extern struct GfFont *func_0201D7EC(int,int,int,int,unsigned);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct MsgBank *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern struct U16Vec *func_020457B0(unsigned,unsigned);
extern void func_02045808(struct U16Vec *);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_0201DD68(void);
extern void func_02031140(struct S02031140 *);
extern void func_02049238(void *);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32);
extern void *func_02049250(struct ArcFile *,u32,u32);
extern int func_02062A98(struct NitroFileHeader *,void **);
extern void func_0207D63C(u32 *,u32,u32,int,int);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *,int,int);
extern R *func_021B62E0(A *,int);
extern void func_021B639C(unsigned char *);
extern void func_021B63D0(struct S *p);
extern signed int func_0204AC18(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned short e, unsigned short f, unsigned short g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
void func_021BC0C8(char *p);
void func_021BC178(char *p);
void func_021BC1E4(char *p,u16 heap);
void func_021BC378(char *p);
R *func_021BC398(int manager,int heap);
void func_021BC3D4(unsigned char *p);
void func_021BC3DC(S *p);
void func_021BC3E4(unsigned short *p,int *out,const Config *cfg,void *handle);
void func_021BC43C(void *unused, char *p);
extern const unsigned char d_021BDB4C[];

void func_021BC0C8(char *p)
{
    *(struct Tcbl * *)&((struct Obj00366 *)p)->f18=func_0203101C(((struct Obj00366 *)p)->f0,((struct Obj00366 *)p)->f0,64,128);
    ((struct Obj00366 *)p)->f54=func_020490F4(173,((struct Obj00366 *)p)->f0);
    func_0201DD78(7,8,15);
    ((struct Obj00366 *)p)->f12C=func_0201C450(2048,((struct Obj00366 *)p)->f0);
    *(struct GfFont * *)&((struct Obj00366 *)p)->f128=func_0201D7EC(23,0,0,0,((struct Obj00366 *)p)->f0);
    *(struct WordSet * *)&((struct Obj00366 *)p)->f138=func_0201EC74(8,64,((struct Obj00366 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00366 *)p)->f130=func_02045B38(0,2,7,((struct Obj00366 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00366 *)p)->f134=func_02045B38(0,2,231,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f13C=func_020457B0(109,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f140=func_020457B0(109,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f144=func_020457B0(109,((struct Obj00366 *)p)->f0);
}

void func_021BC178(char *p)
{
    func_02045808(*(struct U16Vec * *)&((struct Obj01437 *)p)->f144);
    func_02045808(*(struct U16Vec * *)&((struct Obj01437 *)p)->f140);
    func_02045808(*(struct U16Vec * *)&((struct Obj01437 *)p)->f13C);
    func_02045C04(*(struct Rec * *)&((struct Obj01437 *)p)->f134);
    func_02045C04(*(struct Rec * *)&((struct Obj01437 *)p)->f130);
    func_0201ED04(*(struct WordSet * *)&((struct Obj01437 *)p)->f138);
    func_0201D83C(((struct Obj01437 *)p)->f128);
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj01437 *)p)->f12C);
    func_0201C4C0(*(struct PrintSys * *)&((struct Obj01437 *)p)->f12C);
    func_0201DD68();
    func_02031140(*(struct S02031140 * *)&((struct Obj01437 *)p)->f18);
    func_02049238(((struct Obj01437 *)p)->f54);
}

void func_021BC1E4(char *p,u16 heap)
{
    struct ArcFile *arc;
    arc=func_020490F4(85,heap);
    func_02049B68(arc,0,0,0,512,heap);
    func_02049B68(((struct Obj01591 *)p)->f54,28,4,0,512,heap);
    func_02049658(((struct Obj01591 *)p)->f54,30,4,0,0,1,heap);
    func_02049658(((struct Obj01591 *)p)->f54,30,5,0,0,1,heap);
    func_02049658(((struct Obj01591 *)p)->f54,30,7,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,32,4,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,32,5,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,33,7,0,0,1,heap);
    func_020413B0(5,0,0,32,24,1);
    func_020409B4(5);
    func_02049658(((struct Obj01591 *)p)->f54,31,1,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,34,1,0,2048,1,heap);
    func_02049658(arc,5,2,0,0,0,heap);
    func_020498F4(arc,17,2,0,2048,0,heap);
    func_02049658(arc,7,3,0,0,0,heap);
    func_020498F4(arc,16,3,0,2048,0,heap);
    ((struct Obj01591 *)p)->f120=func_02049250(*(struct ArcFile * *)&((struct Obj01591 *)p)->f54,29,((struct Obj01591 *)p)->f0);
    func_02062A98(*(struct NitroFileHeader * *)&((struct Obj01591 *)p)->f120,(void **)(p+280));
    ((struct Obj01591 *)p)->f11C=((struct Obj25769 *)(*(char * *)&((struct Obj01591 *)p)->f118))->fC;
    func_02049238(arc);
    func_0207D63C((u32 *)0x04000050,2,30,11,5);
    func_0207D63C((u32 *)0x04001050,3,31,13,3);
}


void func_021BC378(char *p)
{
    func_020307B0(((struct Obj25770 *)p)->f120);
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned short *)0x04000050 = 0;
}

R *func_021BC398(int manager,int heap){A a;enum {Zero} zero=Zero;func_02082BCC(&a,0,32);a.f0=(unsigned char *)d_021BDB4C;a.f4=3;a.f10=13;a.f14=11;a.f8=manager;a.fC=zero;a.f18=zero;return func_021B62E0(&a,heap);}

void func_021BC3D4(unsigned char *p){func_021B639C(p);}

void func_021BC3DC(S *p){func_021B63D0(p);}

void func_021BC3E4(unsigned short *p,int *out,const Config *cfg,void *handle)
{
    func_02082BCC(out,0,12);
    out[0]=func_0204AC18(handle,cfg->first,cfg->a,(unsigned short)(cfg->b<<5),0,cfg->c,*p);
    out[1]=func_0204A6C8((void *)handle,cfg->second,0,cfg->a,*p);
    out[2]=func_0204AF28((void *)handle,cfg->third,cfg->third+1,*p);
}


void func_021BC43C(void *unused, char *p)
{
    func_0204AFD8(((struct Obj10945 *)p)->f8);
    func_0204A8D4(((struct Obj10945 *)p)->f4);
    func_0204ADA4(((struct Obj10945 *)p)->f0);
}
