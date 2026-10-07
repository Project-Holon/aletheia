/*
 * file:     musical_mcss_p08.c
 * unit:     yes
 * function: func_021F5EDC, func_021F611C, func_021F61D8, func_021F621C, func_021F622C, func_021F6230, func_021F6234, func_021F624C, func_021F6264, func_021F626C, func_021F6280, func_021F6290, func_021F62A0, func_021F62B0, func_021F62D0, func_021F62DC, func_021F62EC, func_021F62FC, func_021F63B8, func_021F6540, func_021F659C, func_021F65EC, func_021F660C, func_021F6744, func_021F675C, func_021F67E0, func_021F685C, func_021F6888, func_021F68BC
 * address:  0x021F5EDC
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
 *   func_0207D760 0x0207D760 arm
 *   func_0207D888 0x0207D888 arm
 *   d_020A1B38 0x020A1B38 data a4
 *   func_02030734 0x02030734 arm
 *   d_021F83D4 0x021F83D4 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_020627D8 0x020627D8 arm
 *   func_0206469C 0x0206469C arm
 *   func_02063790 0x02063790 arm
 *   func_020637D4 0x020637D4 arm
 *   func_02049FBC 0x02049FBC arm
 *   func_0204A03C 0x0204A03C arm
 *   func_0204A0BC 0x0204A0BC arm
 *   func_0204A13C 0x0204A13C arm
 *   func_02048F60 0x02048F60 arm
 *   func_02049DB4 0x02049DB4 arm
 *   func_02049F34 0x02049F34 arm
 *   func_020172D8 0x020172D8 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02063A54 0x02063A54 arm
 *   func_02063E54 0x02063E54 arm
 *   func_020648B4 0x020648B4 arm
 *   func_02064754 0x02064754 arm
 *   _ll_mul 0x0209C054 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017EAC 0x02017EAC thumb
 *   d_021F83E4 0x021F83E4 data a4
 *   func_0200C52C 0x0200C52C thumb
 *   func_0200C6D8 0x0200C6D8 thumb
 *   func_0200C6DC 0x0200C6DC thumb
 *   func_0200C5A4 0x0200C5A4 thumb
 *   func_0204913C 0x0204913C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A39C 0x0204A39C arm
 *   func_020493D4 0x020493D4 arm
 *   func_0204932C 0x0204932C arm
 *   func_02049238 0x02049238 arm
 */
#include "../../matched/include/Obj10306.h"
#include "../../matched/include/Obj04460.h"
#include "../../matched/include/Obj13833.h"
#include "../../matched/include/Obj22543.h"
#include "../../matched/include/Obj22544.h"
#include "../../matched/include/Obj10307.h"
#include "../../matched/include/Obj10309.h"
#include "../../matched/include/Obj22545.h"
#include "../../matched/include/Obj22546.h"
#include "../../matched/include/Obj00722.h"
#include "../../matched/include/Obj22547.h"
#include "../../matched/include/Obj22548.h"
#include "../../matched/include/Obj22549.h"
#include "../../matched/include/Obj13834.h"
#include "../../matched/include/Obj22550.h"
#include "../../matched/include/Obj22551.h"
#include "../../matched/include/Obj22552.h"
#include "../../matched/include/Obj03759.h"
#include "../../matched/include/Obj03247.h"
#include "../../matched/include/Obj03760.h"

#define SLOT (*(char ***)(a+4))[i]
struct AnimBank;
struct AnimSequence;
struct Obj0206469C;
struct Node;
struct Out;
struct Res;
struct ArcFile;
struct Blk2C;
struct MusicalDist;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

struct E2 { s16 p0; s16 f2; s16 f4; s16 p6; };

struct E1 { int p0; struct E2 *arr; };

struct H { int p0; struct E1 *tbl; };

struct S {
    int pad0;
    int f4;
    int f8;
    s16 fC;
    s16 fE;
};

typedef struct { u32 a:1,b:1,c:1,rest:29; } Flags;

typedef signed char s8;

typedef int s32;

typedef struct { int x,y,z; } Vec;

typedef struct { char pad[200]; Vec a,b,c; u32 b0:1,b1:1,b2:1,rest:29; char pad2[12]; u16 h,pad3; Vec d,e; } Object;

typedef long long s64;

typedef unsigned long long u64;

extern void func_0207D760(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern void func_0207D888(int a, int b);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx);
extern void func_0206469C(void *,void *);
extern void func_02063790(u32 *);
extern void func_020637D4(u32 *);
extern void *func_02049FBC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_0204A03C(u32,u32,u32,u32,u16);
extern void *func_0204A0BC(u32,u32,u32,u32,u16);
extern void *func_0204A13C(u32,u32,u32,u32,u16);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_020172D8(u8 *,u32);
extern void *func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *n);
extern void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063E54(void *,void *,int,void *);
extern int func_020648B4(u32,u32);
extern void func_02064754(char *,char *,void *,int,void *,int);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_02017EAC(void *);
extern struct MusicalDist *func_0200C52C(void *sys, u32 heap);
extern u32 func_0200C6D8(struct Blk2C *p);
extern u32 func_0200C6DC(struct Blk2C *p);
extern void *func_0204913C(void *a0, u32 a1, u32 heap);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_02049238(void *arc);
extern void func_0200C5A4(struct MusicalDist *p);
void func_021F5EDC(char *p, int a1, int a2, int a3, int a4, int a5, int a6, struct S *s, u16 *pa, int a9, int flag, int *pz, u8 mode);
char *func_021F611C(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g);
void func_021F61D8(char *a, char *p);
void func_021F621C(void *p);
void func_021F622C(char *p,int b);
void func_021F6230(u8 *p, int a);
void func_021F6234(char *p, int *q);
void func_021F624C(char *p, int *q);
void func_021F6264(char *p, unsigned short v);
void func_021F626C(u8 *p);
void func_021F6280(u8 *p);
void func_021F6290(u8 *p);
void func_021F62A0(char *p);
void func_021F62B0(char *p,u32 n);
u32 func_021F62D0(u8 *p);
void func_021F62DC(char *p);
void func_021F62EC(char *p);
void func_021F62FC(Object *a,Object *b);
void func_021F63B8(u8 *a,int index,u32 *res,u32 mode);
void func_021F6540(void *a, void **p);
void func_021F659C(char *p, int kind);
void func_021F65EC(void);
void func_021F660C(const int *p, const int *m, u32 *out, u32 *w);
int func_021F6744(void *p);
char *func_021F675C(void *a,u16 heap);
char *func_021F67E0(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap);
void *func_021F685C(u32 heap);
void func_021F6888(char *p);
void func_021F68BC(u8 *p, u32 unused, void *sys, u8 kind, u16 heap);
extern s16 d_020A1B38[];
extern const char d_021F83D4[];
extern const char d_021F83E4[];


static inline void G3_TexPlttBase(u32 addr, int fmt)
{
    u32 param = (u32)(addr >> (4 - (fmt == 2)));
    *(volatile u32 *)0x040004AC = param;
}


static inline void G3_Translate(int x, int y, int z)
{
    *(volatile u32 *)0x04000470 = (u32)x;
    *(volatile u32 *)0x04000470 = (u32)y;
    *(volatile u32 *)0x04000470 = (u32)z;
}


static inline void G3_Scale(int x, int y, int z)
{
    *(volatile u32 *)0x0400046C = (u32)x;
    *(volatile u32 *)0x0400046C = (u32)y;
    *(volatile u32 *)0x0400046C = (u32)z;
}


static inline u32 pk(int v)
{
    return (u16)((v << 8) >> 16);
}


static inline void G3_TexCoord(u32 s, u32 t)
{
    *(volatile u32 *)0x04000488 = s | (t << 16);
}


static inline void G3_Vtx(u32 xy, u32 z)
{
    *(volatile u32 *)0x0400048C = xy;
    *(volatile u32 *)0x0400048C = z;
}


/*
 * 2026-10-05 wD5 lane16: EXACT. The record access is written in full at each use
 *   (`(*(struct H **)(p + 0x6C))->tbl[*pa].arr[a9].f2` and `.f4`), not through e1/e2 pointer locals.
 *   The CSE of the two full expressions colours pa in r2, so its load can move above the 0x4AC store.
 */
void func_021F5EDC(char *p, int a1, int a2, int a3, int a4, int a5, int a6, struct S *s, u16 *pa, int a9, int flag, int *pz, u8 mode)
{
    u16 ang;
    int x;
    int y;
    u32 s0;
    u32 s1;
    u32 t0;
    u32 t1;

    if (flag != 0) {
        func_0207D760(0x60000, 0xFFFA1000, 0xFFF81000, 0x80000, 0x1000, 0x3E8000, 0x1000, 1, 0);
        *(volatile u32 *)0x04000440 = 2;
    }
    *(volatile u32 *)0x04000450 = 0x1D;
    G3_TexPlttBase(*(u32 *)(p + 0xBC), *(int *)(p + 0xB4));
    *(volatile u32 *)0x040004A4 = 0x001F00C0;
    x = (s->fC + (*(struct H **)(p + 0x6C))->tbl[*pa].arr[a9].f2) << 8;
    y = -((*(struct H **)(p + 0x6C))->tbl[*pa].arr[a9].f4 + s->fE) << 8;
    if (mode == 0) {
        ang = *(u16 *)(p + 0xFC);
    } else if ((mode & 1) != 0) {
        ang = (u16)(0x10000 - *(u16 *)(p + 0xFC));
    }
    func_0207D888(-d_020A1B38[(ang >> 4) * 2], d_020A1B38[(ang >> 4) * 2 + 1]);
    G3_Translate(x, y, *pz);
    func_0207D888(-d_020A1B38[(*(u16 *)((char *)s + 2) >> 4) * 2], d_020A1B38[(*(u16 *)((char *)s + 2) >> 4) * 2 + 1]);
    if (mode == 0) {
        G3_Scale(s->f4, s->f8, 0x1000);
        G3_Translate(a1, a2, 0);
        G3_Scale(a3, a4, 0x1000);
    } else if ((mode & 1) != 0) {
        G3_Scale(-s->f4, s->f8, 0x1000);
        G3_Translate(-a1, a2, 0);
        G3_Scale(a3, a4, 0x1000);
        G3_Translate(-0x100, 0, 0);
        a5 = 0x200000 - a5 - a3;
    }
    *(volatile u32 *)0x04000500 = 1;
    t0 = pk(a6) << 16;
    s0 = pk(a5);
    *(volatile u32 *)0x04000488 = s0 | t0;
    G3_Vtx(0, 0);
    s1 = pk(a5 + a3);
    *(volatile u32 *)0x04000488 = s1 | t0;
    G3_Vtx(0x100, 0);
    t1 = pk(a6 + a4) << 16;
    *(volatile u32 *)0x04000488 = s1 | t1;
    G3_Vtx(0xFF000100, 0);
    *(volatile u32 *)0x04000488 = s0 | t1;
    G3_Vtx(0xFF000000, 0);
    *(volatile u32 *)0x04000504 = 0;
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000450 = 0;
    *(volatile u32 *)0x04000440 = 2;
    if (flag == 0) {
        *pz = *pz - 0x100;
    } else {
        *pz = *pz - 0x400;
    }
}

char *func_021F611C(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g)
{
    int i;
    for(i=0;i<((struct Obj10306 *)a)->f0;i++) {
        if(SLOT==0) {
            SLOT=func_02030734((u16)((struct Obj10306 *)a)->f14,292,1,d_021F83D4,763);
            *(u32 *)(SLOT+240)=i;
            *(u32 *)(SLOT+244)=((struct Obj10306 *)a)->f14;
            *(u32 *)(SLOT+200)=b;
            *(u32 *)(SLOT+204)=c;
            *(u32 *)(SLOT+208)=d;
            *(u16 *)(SLOT+252)=0;
            *(u32 *)(SLOT+212)=4096;
            *(u32 *)(SLOT+216)=4096;
            *(u32 *)(SLOT+220)=4096;
            *(u32 *)(SLOT+248)=f;
            func_021F63B8((u8 *)a,i,(u32 *)e,g);
            break;
        }
    }
    return SLOT;
}

void func_021F61D8(char *a, char *p)
{
    func_020307B0(((struct Obj04460 *)p)->f0);
    func_020307B0(((struct Obj04460 *)p)->f10);
    func_020307B0(((struct Obj04460 *)p)->f8);
    func_020307B0(((struct Obj04460 *)p)->f18);
    func_020307B0(((struct Obj04460 *)p)->f8C);
    func_020307B0(((struct Obj04460 *)p)->f20);
    (*(u32 **)(a+4))[((struct Obj04460 *)p)->fF0] = 0;
    func_020307B0(p);
}


void func_021F621C(void *p)
{
    unsigned int v = ((struct Obj13833 *)p)->f8;
    ((struct Obj13833 *)p)->f8 = (v & ~1u) | 1u;
}

/*
 * note: blocker leaf of func_021F5438; following 021F6230 is already matched.
 */
void func_021F622C(char *p,int b) { ((struct Obj22543 *)p)->fC=b; }

void func_021F6230(u8 *p, int a)
{
    ((struct Obj22544 *)p)->f10 = a;
}


void func_021F6234(char *p, int *q)
{
    ((struct Obj10307 *)p)->fC8 = q[0];
    ((struct Obj10307 *)p)->fCC = q[1];
    ((struct Obj10307 *)p)->fD0 = q[2];
}


void func_021F624C(char *p, int *q)
{
    ((struct Obj10309 *)p)->fD4 = q[0];
    ((struct Obj10309 *)p)->fD8 = q[1];
    ((struct Obj10309 *)p)->fDC = q[2];
}


void func_021F6264(char *p, unsigned short v)
{
    ((struct Obj22545 *)p)->fFC = v;
}

void func_021F626C(u8 *p) { ((Flags *)(p+236))->a=1; }

void func_021F6280(u8 *p) { ((Flags *)(p+236))->a=0; }

void func_021F6290(u8 *p) { ((Flags *)(p+236))->b=1; }

void func_021F62A0(char *p) {((struct Obj22546 *)p)->fEC&=~2u;}

void func_021F62B0(char *p,u32 n) {void *a; a=func_020627D8(((struct Obj00722 *)p)->f1C,n);func_021F659C(p,1);func_0206469C(p+40,a);}


u32 func_021F62D0(u8 *p) { return (((struct Obj22547 *)p)->fEC << 29) >> 31; }

void func_021F62DC(char *p) {((struct Obj22548 *)p)->fEC|=4u;}

void func_021F62EC(char *p) {((struct Obj22549 *)p)->fEC&=~4u;}

void func_021F62FC(Object *a,Object *b)
{
    b->a=a->a; b->b=a->b; b->c=a->c;
    b->b0=a->b0; b->b1=a->b1; b->b2=a->b2;
    b->h=a->h; b->d=a->d; b->e=a->e;
}

/*
 * lever: an unqualified resource pointer keeps constant r2 setup before resource loads.
 * prototype: 6469C receives the sequence in r1 despite its one-argument matched definition.
 * prototype: 48F60/49F34/30734 heap inputs are narrowed immediately before each original call.
 */
void func_021F63B8(u8 *a,int index,u32 *res,u32 mode)
{
    u8 *q=(*(u8 ***)(a+4))[index];
    void **job;
    struct AnimSequence *sequence;
    u8 *table;
    ((struct Obj00722 *)q)->fEC |= 4;
    func_02063790((u32 *)(q+144));
    func_020637D4((u32 *)(q+180));
    ((struct Obj00722 *)q)->f0=func_02049FBC(res[0],res[3],0,(u32)(q+4),((struct Obj00722 *)q)->fF4);
    ((struct Obj00722 *)q)->f10=func_0204A03C(res[0],res[4],1,(u32)(q+20),((struct Obj00722 *)q)->fF4);
    ((struct Obj00722 *)q)->f8=func_0204A0BC(res[0],res[5],0,(u32)(q+12),((struct Obj00722 *)q)->fF4);
    ((struct Obj00722 *)q)->f18=func_0204A13C(res[0],res[6],0,(u32)(q+28),((struct Obj00722 *)q)->fF4);
    sequence=func_020627D8(*(struct AnimBank * *)&((struct Obj00722 *)q)->f1C,0);
    func_021F659C((char *)q,1);
    func_0206469C((struct Obj0206469C *)(q+40),sequence);
    table=func_02048F60(res[0],res[7],(u16)(((struct Obj00722 *)q)->fF4));
    *(u8 * *)&((struct Obj00722 *)q)->f20=table;
    *(u8 * *)&((struct Obj00722 *)q)->f24=table+4+56* ((struct Obj22550 *)table)->f0;
    job=func_02030734((u16)((struct Obj00722 *)q)->fF4,36,1,d_021F83D4,1104);
    job[2]=q+144;
    job[3]=q+180;
    job[6]=*(u8 * *)&((struct Obj13834 *)a)->fC+index*16384;
    job[7]=*(u8 * *)&((struct Obj13834 *)a)->f10+index*32;
    job[8]=q;
    job[4]=func_02049DB4(res[0],res[1],1,(u32)job,((struct Obj00722 *)q)->fF4);
    job[5]=func_02049F34(res[0],res[2],(u32)(job+1),(u16)(((struct Obj00722 *)q)->fF4));
    if(res[7]==6548) func_020172D8(*(u8 * *)&((struct Obj22551 *)((u8 *)job[0]))->f14,res[8]);
    if(mode==1) func_020056A0((u32)func_021F6540,(u32)job,0);
    else func_021F6540(0,job);
}

/*
 * extent: Two zero padding bytes follow the compiled body.
 */
void func_021F6540(void *a, void **p)
{
    if(p[8]) ((struct Obj22552 *)((char *)p[8]))->fEC &= ~4u;
    if(p[4]) { func_02063A54(p[0],(u32)p[6],0,p[2]); func_020307B0(p[4]); }
    if(p[1]) { func_02063E54(p[1],p[7],0,p[3]); func_020307B0(p[5]); }
    func_020307B0(p);
    if(a) func_02030EAC(a);
}

void func_021F659C(char *p, int kind)
{
    ((struct Obj00722 *)p)->f8C=func_02030734((u16)((struct Obj00722 *)p)->fF4,func_020648B4(*(u32 *)&((struct Obj00722 *)p)->fC,kind),0,d_021F83D4,1216);
    func_02064754(p+40,*(char * *)&((struct Obj00722 *)p)->f8C,((struct Obj00722 *)p)->f14,((struct Obj00722 *)p)->f4,((struct Obj00722 *)p)->fC,kind);
}

/*
 * volatile: Hardware register stores at listing 021F65F0,021F65F4,021F65FA.
 */
void func_021F65EC(void) {*(volatile u32 *)0x040004c0=0x4210ffff;*(volatile u32 *)0x040004c4=0x4210;*(volatile u32 *)0x040004a4=0x001f00c0;}

/*
 * extent: 310-byte code; 021F6742 is two zero alignment bytes.
 * lever: a named unsigned 64-bit sum pins carry accumulation before translation.
 * semantics: signed 32-bit products fit s64; u64 additions wrap like ADDS/ADCS.
 */
void func_021F660C(const int *p, const int *m, u32 *out, u32 *w)
{
    s64 y = p[1];
    s64 x = p[0];
    s64 z = p[2];
    u64 sum;
    sum = (u64)(x * m[0]) + (u64)(y * m[4]) + (u64)(z * m[8]);
    out[0] = (u32)(sum >> 12) + (u32)m[12];
    sum = (u64)(x * m[1]) + (u64)(y * m[5]) + (u64)(z * m[9]);
    out[1] = (u32)(sum >> 12) + (u32)m[13];
    sum = (u64)(x * m[2]) + (u64)(y * m[6]) + (u64)(z * m[10]);
    out[2] = (u32)(sum >> 12) + (u32)m[14];
    sum = (u64)(x * m[3]) + (u64)(y * m[7]) + (u64)(z * m[11]);
    *w = (u32)(sum >> 12) + (u32)m[15];
}

/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
int func_021F6744(void *p) {int r; r=0;if(func_02017E1C(p,170,0)!=1)r=1;return r;}

char *func_021F675C(void *a,u16 heap)
{
    char *p;
    int i;
    p=func_02030734(heap,124,1,d_021F83E4,141);
    ((struct Obj03759 *)p)->f0=4;
    ((struct Obj03759 *)p)->f4=a;
    ((struct Obj03759 *)p)->f4A=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    ((struct Obj03759 *)p)->f8=func_02017E1C(a,5,0);
    p[10]=func_02017E1C(a,110,0);
    p[11]=func_02017E1C(a,111,0);
    p[12]=func_02017EAC(a);
    ((struct Obj03759 *)p)->f10=func_02017E1C(a,0,0);
    return p;
}

char *func_021F67E0(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap)
{
    int i;
    char *p;
    int j;
    p=func_02030734(heap,124,1,d_021F83E4,165);
    ((struct Obj03247 *)p)->f0=4; ((struct Obj03247 *)p)->f4=0; ((struct Obj03247 *)p)->f4A=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    for(j=0;j<4;j++) *(u16 *)(p+76+2*j)=0;
    ((struct Obj03247 *)p)->f78=0;
    ((struct Obj03247 *)p)->f8=a; p[10]=b; p[11]=c; p[12]=d; ((struct Obj03247 *)p)->f10=e;
    return p;
}

void *func_021F685C(u32 heap) {u32 *p;int z;z=0;p=func_02030734(heap,48,0,d_021F83E4,194);p[1]=z;p[2]=z;p[3]=z;p[4]=z;p[5]=z;p[6]=z;p[7]=z;return p;}

void func_021F6888(char *p) {if(((struct Obj03760 *)p)->f4)func_020307B0(((struct Obj03760 *)p)->f4);if(((struct Obj03760 *)p)->f8)func_020307B0(((struct Obj03760 *)p)->f8);if(((struct Obj03760 *)p)->fC)func_020307B0(((struct Obj03760 *)p)->fC);if(((struct Obj03760 *)p)->f10)func_020307B0(((struct Obj03760 *)p)->f10);func_020307B0(p);}

void func_021F68BC(u8 *p, u32 unused, void *sys, u8 kind, u16 heap)
{
    void *x;
    void *arc;
    u32 c, d, e;
    u8 *q;
    *p = kind;
    if (kind >= 4) {
        x = func_0200C52C(sys, heap);
        arc = func_0204913C((void *)func_0200C6D8(x), func_0200C6DC(x), (u16)((heap & 0x7fff) | 0x8000));
    } else {
        arc = func_020490F4(kind + 0x6f, (u16)((heap & 0x7fff) | 0x8000));
    }
    *(void **)(p + 4) = func_0204A39C(arc, 0, 0, heap, (u32 *)(p + 0x20));
    *(void **)(p + 8) = func_0204A39C(arc, 1, 0, heap, (u32 *)(p + 0x24));
    *(void **)(p + 0xc) = func_0204A39C(arc, 2, 0, heap, (u32 *)(p + 0x28));
    c = func_020493D4(arc, 4);
    d = func_020493D4(arc, 3);
    e = func_020493D4(arc, 5);
    *(u32 *)(p + 0x2c) = c + 0xc + d + e;
    q = func_02030734(heap, *(u32 *)(p + 0x2c), 1, d_021F83E4, 0x104);
    *(u8 **)(p + 0x10) = q;
    *(u8 **)(p + 0x14) = q + 0xc;
    *(u8 **)(p + 0x18) = q + 0xc + c;
    *(u32 *)(p + 0x1c) = d + *(u32 *)(p + 0x18);
    *(u32 *)q = c;
    *(u32 *)(q + 4) = d;
    *(u32 *)(q + 8) = e;
    func_0204932C(arc, 4, *(void **)(p + 0x14));
    func_0204932C(arc, 3, *(void **)(p + 0x18));
    func_0204932C(arc, 5, *(void **)(p + 0x1c));
    func_02049238(arc);
    if (kind >= 4) func_0200C5A4(x);
}
