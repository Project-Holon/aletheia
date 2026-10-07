/*
 * file:     wifi_bsubway_graphic_p02.c
 * unit:     yes
 * function: func_021D7C58, func_021D7CF4, func_021D7D0C, func_021D7F54, func_021D7FC4, func_021D8010, func_021D80CC, func_021D8118, func_021D8134, func_021D8168, func_021D8190, func_021D81B4, func_021D81D0, func_021D81EC, func_021D821C, func_021D82AC, func_021D82F8, func_021D8304, func_021D8364
 * address:  0x021D7C58
 * region:   ov116
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02031140 0x02031140 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020310C4 0x020310C4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0203FA08 0x0203FA08 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02021F64 0x02021F64 thumb
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_02040618 0x02040618 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201FDA0 0x0201FDA0 thumb
 *   d_021D8560 0x021D8560 data a4
 *   d_021D8560_menu 0x021D8560 data a4
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_020056BC 0x020056BC thumb
 *   func_0202EE30 0x0202EE30 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_02030734 0x02030734 arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   d_021D858C 0x021D858C data a1
 *   d_021D83C0 0x021D83C0 data a4
 *   func_021D839C 0x021D839C thumb ov116
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021D83B0 0x021D83B0 data a4
 *   d_021D83F0 0x021D83F0 data a4
 *   g_021D83F0  0x021D83F0  data
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */
#include "../../matched/include/Obj01721.h"
#include "../../matched/include/Obj13869.h"
#include "../../matched/include/Obj03252.h"
#include "../../matched/include/Obj05322.h"
#include "../../matched/include/Obj22630.h"
#include "../../matched/include/Obj06418.h"
#include "../../matched/include/Obj22631.h"
#include "../../matched/include/Obj08048.h"
#include "../../matched/include/Obj10343.h"
#include "../../matched/include/Obj10344.h"
#include "../../matched/include/Obj10345.h"
#include "../../matched/include/Obj13870.h"
#include "../../matched/include/Obj10346.h"
#include "../../matched/include/Obj22632.h"
#include "../../matched/include/Obj22633.h"
#include "../../matched/include/Obj10347.h"

#define I(k) (*(u32_021D8010 *)((char *)p+(k)))
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct WordSet;
struct Tcbl;
struct Node;
struct CharBuf;
struct MsgBank;
struct WinDat;
struct BmpMenu;
struct DispVram;
struct BgTemplate;
struct DispConfig;
typedef unsigned char u8;

typedef unsigned int   u32_021D7C58;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32_021D7CF4;

typedef unsigned int u32_021D7D0C;

struct Arc { int f0; int f4; int f8; u8 *fC; };

typedef unsigned int   u32_021D7F54;

typedef unsigned int u32_021D7FC4;

typedef unsigned u32_021D8010;

typedef unsigned int u32_021D80CC;

typedef unsigned int u32_021D8118;

typedef unsigned int u32_021D8134;

typedef unsigned int u32_021D8168;

typedef unsigned int u32_021D8190;

typedef unsigned int u32_021D81B4;

typedef unsigned int u32_021D81D0;

typedef unsigned int u32_021D81EC;

typedef unsigned int   u32_021D821C;

typedef unsigned int   u32_021D82AC;

typedef unsigned int   u32_021D8304;

typedef unsigned int u32_021D8364;

extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32_021D7C58 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201FEF4(u8 *o);
extern u32_021D7C58 func_020452E8(struct Descriptor *d);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
extern void func_020310C4(struct Tcbl *p);
extern void *func_020490F4(u32_021D7D0C, u32_021D7D0C);
extern void func_02049B68(void *, int, int, int, int, u32_021D7D0C);
extern u32_021D7D0C func_02049740(void *, int, int, int, int, u32_021D7D0C);
extern void func_02049990(void *, int, int, int, u16, int, int, u32_021D7D0C);
extern void *func_02049F78(void *a0, u32_021D7D0C a1, u32_021D7D0C a2, u32_021D7D0C a3);
extern void func_02049238(void *);
extern int func_02049B40(int, int, int, int, int, u32_021D7D0C);
extern void func_02082D44(const void *, void *, u32_021D7D0C);
extern u32_021D7D0C func_020307B0(void *p);
extern void *func_020056A0(void *, void *, int);
extern void func_020862F0(void *, u32_021D7D0C);
extern void func_0207D63C(void *, int, int, int, int);
extern u32_021D7D0C func_0203FA08(u32_021D7D0C layer, u32_021D7D0C size, u32_021D7D0C top);
extern void *func_0201F5DC(void *a0, u32_021D7D0C a1, u32_021D7D0C a2, u32_021D7D0C a3);
extern void func_02021F64(void *, void *, u16, u8, u16);
extern void func_0207E3D0(void *,int,int);
extern void func_0207E468(void *,int,int);
extern void func_02040618(u32_021D7F54 layer, u32_021D7F54 a, u32_021D7F54 b);
extern void func_0203FB44(u32_021D7FC4 layer, u32_021D7FC4 offset, u32_021D7FC4 size);
extern void func_02030EAC(struct Node *n);
extern void func_02045CAC(struct MsgBank *bank, u32_021D8010 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32_021D8010 r, u32_021D8010 g, u32_021D8010 b);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(u32_021D8010,int,int,u32_021D8010,u32_021D8010,u32_021D8010,u32_021D8010,int,u16,int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern u32_021D80CC func_0201CE30(void *p);
extern u32_021D80CC func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201CE38(void *);
extern void func_0201EFA4(struct WordSet *p, u32_021D8118 i, u32_021D8118 a, u32_021D8118 b, u32_021D8118 c, u32_021D8118 d);
extern struct BmpMenu *func_0201FDA0(const struct WinDat *,u16,u8,u8,u16);
extern u32_021D8168 func_0201FEBC(u8 *);
extern u32_021D8190 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0202F038(u8 *);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
extern void *func_02030734(u32_021D821C heapId, u32_021D821C size, int clear, const char *site, u16 tag);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32_021D821C swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021D839C(void *);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32_021D8304 bgId, const struct BgTemplate *tmpl, u32_021D8304 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
void func_020403F4(u32_021D8364 i);
void func_020450C8(void);
void func_0203F9B4(void);
void func_021D7C58(u8 *p);
void func_021D7CF4(u8 *p);
void func_021D7D0C(u8 *p, short heap);
void func_021D7F54(void *unused,u8 *p);
void func_021D7FC4(u8 *p);
void func_021D8010(void *p,u32_021D8010 a);
int func_021D80CC(void *p);
void func_021D8118(u8 *p, u32_021D8118 i, u32_021D8118 a, u32_021D8118 b);
void func_021D8134(u8 *p);
u32_021D8168 func_021D8168(u8 *p);
void func_021D8190(u8 *p);
void func_021D81B4(u8 *p);
void func_021D81D0(u8 *p);
int func_021D81EC(u8 *p);
void *func_021D821C(int a,unsigned heap);
void func_021D82AC(void *p);
void func_021D82F8(void *a,void *b);
void func_021D8304(void *p,unsigned heap);
void func_021D8364(void *a0);
extern u8 d_021D8560[];
extern u8 d_021D8560_menu[];
extern char d_021D858C[], d_021D83C0[];
extern char d_021D83B0[],d_021D83F0[];
extern u8 g_021D83F0[];

void func_021D7C58(u8 *p) {
    if(((struct Obj01721 *)p)->f0!=0) {
        if(((struct Obj01721 *)p)->f9A4) func_0201CE48(((struct Obj01721 *)p)->f9A4);
        func_02031140(((struct Obj01721 *)p)->f9A8);
        func_02045C04(((struct Obj01721 *)p)->f990);
        func_0201ED04(((struct Obj01721 *)p)->f994);
        func_0201D83C(((struct Obj01721 *)p)->f998);
        func_02045808(((struct Obj01721 *)p)->f99C);
        func_02045808(((struct Obj01721 *)p)->f9A0);
        func_021D7FC4(p);
        func_021D81B4(p);
        if(((struct Obj01721 *)p)->f980) {
            func_0201FEF4(((struct Obj01721 *)p)->f980);
            ((struct Obj01721 *)p)->f980=0;
        }
        func_020452E8(((struct Obj01721 *)p)->f97C);
        func_021D82AC(((struct Obj01721 *)p)->f8);
        func_0201DD68();
        func_02082BCC(p,0,0x9ac);
    }
}

void func_021D7CF4(u8 *p)
{
    if (((struct Obj13869 *)p)->f0 != 0) func_020310C4(((struct Obj13869 *)p)->f9A8);
}

/*
 * lever: 2026-10-05 (wD9r lane92): the heap parameter is a signed 16-bit value (`short heap`). With u32
 *   heap the last call hoisted the heap reload above `str r6,[sp]` (10 bytes, waves D3 to D9r). The
 *   image truncates heap only for func_02049F78 (u16 cast); the other callees take it unchanged.
 */
void func_021D7D0C(u8 *p, short heap) {
    struct Arc *res;
    u8 *pa;
    u8 *pb;
    void *arc;
    int done;
    int t;
    int j;
    int k;
    u8 *q;
    void *blk;
    int m;
    int n;
    int sh;
    u8 *a;
    u8 *b;
    arc = func_020490F4(0x91, heap);
    j = 0;
    func_02049B68(arc, 3, 4, 0, j, heap);
    func_02049990(arc, 6, 4, 0, (u16)func_02049740(arc, 4, 4, 0, j, heap), j, j, heap);
    func_02049B68(arc, 3, 0, 0, j, heap);
    func_02049990(arc, 5, 0, 0, (u16)func_02049740(arc, 4, 0, 0, j, heap), j, j, heap);
    func_02049990(arc, 7, 3, 0, (u16)func_02049740(arc, 4, 3, 0, j, heap), j, j, heap);
    func_02082BCC(p + 0xc, 0, 0x970);
    blk = func_02049F78(arc, 2, (u32_021D7D0C)(&res), (u16)heap);
    func_02082D44(res->fC, p + 0x14, 0x1e0);
    func_02082D44(res->fC, p + 0x1f4, 0x1e0);
    func_020307B0(blk);
    k = 0;
    pa = p + 0x1f4;
    pb = p;
    pb += 0x14;
    for (; k < 15; k++) {
        n = k + 1;
        if (n >= 15) n -= 15;
        t = 0;
        done = 0;
        q = p + n * 32;
        for (;;) {
            a = pb + k * 32;
            sh = t >> 8;
            b = pa + j * 32;
            for (m = 4; m < 11; m++) {
                func_02021F64(a + m * 2, b + m * 2, 1, (u8)sh, *(u16 *)(q + 0x14 + m * 2));
            }
            j++;
            if (done == 1) break;
            t += 0x600;
            if (t >= 0x1000) { t = 0x1000; done = 1; }
        }
    }
    func_020862F0(p + 0x1f4, 0x780);
    *(u32_021D7D0C *)(p + 0x10) = 1;
    *(void **)(p + 0xc) = func_020056A0((void *)func_021D7F54, p + 0xc, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    p[0x978] = 0;
    func_02049238(arc);
    func_0203FA08(1, 0x20, 0);
    func_0203FA08(2, 0x20, 0);
    *(void **)(p + 0x984) = func_0201F5DC((void *)1, 0xd, 0, heap);
    *(void **)(p + 0x988) = func_0201F5DC((void *)2, 0xd, 0, heap);
    func_02049B40(0x17, 5, 0, 0x180, 0x20, heap);
}

void func_021D7F54(void *unused,u8 *p) {
    if(((struct Obj03252 *)p)->f4!=0) {
        p[0x96b]^=1;
        if((p[0x96b]&1)==0) {
            func_0207E3D0(p+0x1f0+(((struct Obj03252 *)p)->f968<<5),40,14);
            func_0207E468(p+0x1f0+(((struct Obj03252 *)p)->f968<<5),40,14);
            (((struct Obj03252 *)p)->f968)++;
            if(((struct Obj03252 *)p)->f968>=60) ((struct Obj03252 *)p)->f968=0;
            func_02040618(p[0x96c],2,7);
        }
    }
}

void func_021D7FC4(u8 *p) {
    u32_021D7FC4 x=((struct Obj05322 *)p)->f984;
    func_0203FB44(1,(u16)x,(u16)(x>>16));
    x=((struct Obj05322 *)p)->f988;
    func_0203FB44(2,(u16)x,(u16)(x>>16));
    if(((struct Obj05322 *)p)->fC) {
        func_02030EAC(((struct Obj05322 *)p)->fC);
        *(u32_021D7FC4 *)&((struct Obj05322 *)p)->fC=0;
        ((struct Obj05322 *)p)->f10=0;
    }
    *(u16 *)0x04000050=0;
}

void func_021D8010(void *p,u32_021D8010 a) {
 if(I(0x9a4)!=0) {func_0201CE48((void *)I(0x9a4)); I(0x9a4)=0;}
 func_02045CAC((struct MsgBank *)I(0x990),a,(void *)I(0x99c));
 func_0201F250((struct WordSet *)I(0x994),(void *)I(0x9a0),(void *)I(0x99c));
 func_02043B5C((struct CharBuf *)((u32_021D8010)func_02045770((struct Descriptor *)I(0x97c))),15);
 func_0201DD78(1,2,15);
 I(0x9a4)=(u32_021D8010)func_0201CCE4(I(0x97c),0,0,I(0x9a0),I(0x998),func_02012FFC(),I(0x9a8),2,((struct Obj22630 *)p)->f4,15);
 func_0201F73C((void *)I(0x97c),1,(u16)I(0x984),13);
 func_02045334((struct Descriptor *)I(0x97c));
}

int func_021D80CC(void *p) {
 int v;
 if(((struct Obj06418 *)p)->f9A4==0) return 1;
 v=func_0201CE30(((struct Obj06418 *)p)->f9A4);
 if(v==2) { func_0201CE48(((struct Obj06418 *)p)->f9A4); ((struct Obj06418 *)p)->f9A4=0; return 1; }
 if(v==1) { if(func_020362DC()==1 || func_02035C60()!=0) func_0201CE38(((struct Obj06418 *)p)->f9A4); }
 return 0;
}

void func_021D8118(u8 *p, u32_021D8118 i, u32_021D8118 a, u32_021D8118 b)
{
    func_0201EFA4(((struct Obj22631 *)p)->f994, i, a, b, 2, 1);
}

/*
 * The duplicated 021D8560 pool words require separate extern names;
 * see the duplicated-pool-word idiom.
 */
void func_021D8134(u8 *p) { *(u16 *)(d_021D8560+4)=((struct Obj08048 *)p)->f988; *(struct BmpMenu * *)&((struct Obj08048 *)p)->f980=func_0201FDA0((const struct WinDat *)d_021D8560_menu,((struct Obj08048 *)p)->f988,13,0,((struct Obj08048 *)p)->f4); }

u32_021D8168 func_021D8168(u8 *p) { u32_021D8168 result=-2; if(*(u8 * *)&((struct Obj10343 *)p)->f980!=0) { result=func_0201FEBC(*(u8 * *)&((struct Obj10343 *)p)->f980); if(result!=-1) *(u32_021D8168 *)&((struct Obj10343 *)p)->f980=0; } return result; }

void func_021D8190(u8 *p) { *(u8 * *)&((struct Obj10344 *)p)->f98C=func_0202EE30((void *)func_020056BC(),((struct Obj10344 *)p)->f97C,15,16,((struct Obj10344 *)p)->f4); }

void func_021D81B4(u8 *p) { if(*(u8 * *)&((struct Obj10345 *)p)->f98C!=0) { func_0202F038(*(u8 * *)&((struct Obj10345 *)p)->f98C); *(u32_021D81B4 *)&((struct Obj10345 *)p)->f98C=0; } }

void func_021D81D0(u8 *p) { func_02012DAC(((struct Obj13870 *)p)->f1844); ((struct Obj13870 *)p)->fB6A=1; }

int func_021D81EC(u8 *p) { if(((struct Obj10346 *)p)->fB6A==0) return 1; if(func_02012DD0(*(u8 * *)&((struct Obj10346 *)p)->f1844)==2) { ((struct Obj10346 *)p)->fB6A=0; return 1; } return 0; }

/*
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 are read/written at 021D8244..021D8258 or 021D82C4..021D82DA.
 */
void *func_021D821C(int a,unsigned heap) {
 void *p;
 p=func_02030734(heap,16,0,d_021D858C,0x1bc);
 func_02082BCC(p,0,16);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 func_0204335C(0); func_020433E0((const struct DispVram *)d_021D83C0); func_0204363C(a);
 func_0204361C(); func_020434CC(); func_02043588(); func_0201DD60();
 func_021D8304(p,heap);
 ((struct Obj22632 *)p)->fC=func_020056A0((void *)func_021D82F8,p,0);
 return p;
}

void func_021D82AC(void *p) {
 func_02030EAC(((struct Obj22633 *)p)->fC); func_021D8364(p); func_0201DD68();
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 func_02082BCC(p,0,16); func_020307B0(p);
}

void func_021D82F8(void *a,void *b) {func_021D839C(b);}

void func_021D8304(void *p,unsigned heap) {
 unsigned i; char *q; unsigned n;
 func_02082BCC(p,0,4);
 func_0203F8F4(heap); func_02045088(heap); func_0203FC28((struct DispConfig *)d_021D83B0);
 for(i=0;i<8;i++) {
 q=d_021D83F0+i*44; n=((struct Obj10347 *)q)->f0;
 func_0203FCA0((u8)n,(const struct BgTemplate *)(q+4),(u8)(((struct Obj10347 *)q)->f24));
 func_020414AC(n); func_02040588(n,((struct Obj10347 *)q)->f28);
 }
}


void func_021D8364(void *a0)
{
    unsigned int i;

    for (i = 0; i < 8; i++) {
        func_020403F4((u8)*(u32_021D8364 *)(g_021D83F0 + i * 0x2c));
    }
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(a0, 0, 4);
}
