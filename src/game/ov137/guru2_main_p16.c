/*
 * file:     guru2_main_p16.c
 * unit:     yes
 * function: func_021E0980, func_021E09C0, func_021E0A44, func_021E0B14, func_021E0B38, func_021E0BA4, func_021E0BC0
 * address:  0x021E0980
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E15DC 0x021E15DC thumb ov137
 *   d_020A1B38 0x020A1B38 data a2
 *   func_0203F63C 0x0203F63C arm
 *   func_0203F5FC 0x0203F5FC arm
 *   d_021E1FDC 0x021E1FDC data a2
 *   func_02048A18 0x02048A18 arm
 *   func_02047910 0x02047910 arm
 */
#include "../../matched/include/Obj23778.h"
#include "../../matched/include/Obj23779.h"
#include "../../matched/include/Obj01555.h"
#include "../../matched/include/Obj23780.h"
#include "../../matched/include/Obj23781.h"
#include "../../matched/include/Obj23782.h"
#include "../../matched/include/Obj23783.h"
#include "../../matched/include/Obj14239.h"
#include "../../matched/include/Obj23784.h"
#include "../../matched/include/Obj08221.h"
#include "../../matched/include/Obj14240.h"

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {u8 pad[0x2c]; int index,count;} Obj;

typedef struct { int x,y,z; } Vec;

typedef signed char s8;

typedef signed int s32;

extern void func_021E15DC(int *,int);
extern s16 func_0203F63C(u32 x);
extern int func_0203F5FC(u32 x);
extern u32 func_02048A18(u8 *a0, int i);
extern int func_02047910(void *a, int idx, int amount);
void func_021E0980(char *p,int amount);
void func_021E09C0(char *p,int *q,int amount,int extra);
void *func_021E0A44(Obj *p);
void func_021E0B14(char *p,char *q);
void func_021E0B38(char *p,char *q,int amount);
void func_021E0BA4(char *p, char *q);
void func_021E0BC0(char *p,char *q,int i);
extern const u16 d_021E1FDC[];

void func_021E0980(char *p,int amount)
{
    int count = ((struct Obj23778 *)p)->f30;
    int i = 0;
    char *base = p+0x1a0;
    for (;i<count;i++) {
        if (*(int *)(base+0x140+i*0xb4))
            func_021E15DC((int *)(base+0x15c+i*0xb4),amount);
    }
}

/*
 * extent: two-byte alignment padding at 0x021E0A42.
 * Verified ARM scratch C: S12/blocker_0203F63C-r1.log EXACT (72 bytes),
 * S13/blocker_0203F5FC-r1.log EXACT (64 bytes). Both use this symbol:
 *   d_020A1B38 0x020A1B38 data a2
 * typedef unsigned short u16;
 * extern const short d_020A1B38[];
 * int func_0203F63C(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return d_020A1B38[((angle * 65535 / 360) >> 4) * 2 + 1];
 * }
 * int func_0203F5FC(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return d_020A1B38[((angle * 65535 / 360) >> 4) * 2];
 * }
 */
void func_021E09C0(char *p,int *q,int amount,int extra)
{
    u16 angle;
    func_021E15DC(&amount,*(int *)(p+0x20));
    angle=amount/4096;
    *(int *)(p+0x44)=*(int *)(p+0x50)+q[0]+22*func_0203F63C(angle);
    *(int *)(p+0x48)=extra+(*(int *)(p+0x54)-0x6000+q[1]);
    *(int *)(p+0x4c)=*(int *)(p+0x58)+q[2]+22*func_0203F5FC(angle);
    *(short *)(p+0x24)=*(int *)(p+0x2c)/4096;
    *(short *)(p+0x26)=*(int *)(p+0x30)/4096;
    *(short *)(p+0x28)=*(int *)(p+0x34)/4096;
}

/*
 * lever: (pass 2 2026-10-06 P2L40) i zeroed before the angle statement, the row offset
 *   count*10 in a named local as in the twin func_021DEE4C, and a separate local for the
 *   insertion-sort value in the third loop.
 * history: wave P12 lane A8 33 of 208 bytes off; final push G7L3 26 (initialised declarations
 *   count, table, base); pass 2 P2L40: early i 13, separate sort-value local 6, named row 0.
 */
void *func_021E0A44(Obj *p)
{
    int distance[5],indices[5];
    int angle,i,j,key,value,delta,dist,row;
    long count=p->count;
    const u8 *base=(const u8 *)p+0x1a0;
    i=0;
    row=count*10;
    angle=*(const u16 *)((unsigned)d_021E1FDC+row+p->index*2)<<12;
    do {indices[i]=i;distance[i]=65535;i++;} while(i<count);
    for(i=0;i<count;i++) {
        value=*(int *)(base+i*0xb4+0x15c);
        delta=angle-value;
        if(delta<0)delta=angle+0x168000-value;
        distance[i]=delta/4096;
    }
    for(i=1;i<count;i++) {
        key=indices[i];dist=distance[key];
        j=i-1;
        while(j>=0 && distance[indices[j]]>dist) {indices[j+1]=indices[j];j--;}
        indices[j+1]=key;
    }
    return (void *)(base+0x140+indices[0]*0xb4);
}

void func_021E0B14(char *p,char *q) { char *r; int offset; r=p+0x664; offset=((struct Obj23779 *)q)->f10*0x7c; *(int *)(r+offset)=1; *(char **)(r+offset+0x78)=q; func_021E0B38(p,r+offset,0); }

void func_021E0B38(char *p,char *q,int amount)
{
    int n;
    ((struct Obj01555 *)q)->f4=0;
    ((struct Obj01555 *)q)->f6=0;
    ((struct Obj01555 *)q)->f8=0;
    *(Vec *)(q+0x18)=*(Vec *)(*(char * *)&((struct Obj01555 *)q)->f78+0x44);
    ((struct Obj01555 *)q)->f18-=((struct Obj23780 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f50;
    ((struct Obj01555 *)q)->f1C-=((struct Obj23781 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f54+amount;
    ((struct Obj01555 *)q)->f20-=((struct Obj23782 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f58;
    ((struct Obj01555 *)q)->f1C+=0x2000;
    n=((struct Obj23783 *)(*(char * *)&((struct Obj01555 *)q)->f78))->f54+amount;
    if (n<0) n=-n;
    n/=128;
    if (n>0x800) n=0x800;
    ((struct Obj01555 *)q)->fC=0x1000-n;
    ((struct Obj01555 *)q)->f10=0x1000-n;
    ((struct Obj01555 *)q)->f14=0x1000-n;
}


void func_021E0BA4(char *p, char *q)
{
    char *r = p + 0x8D0 + ((struct Obj23784 *)q)->f10 * 0x68;

    ((struct Obj14239 *)r)->f0 = 1;
    *(char * *)&((struct Obj14239 *)r)->f64 = q;
}

void func_021E0BC0(char *p,char *q,int i)
{
    void *r = (void *)func_02048A18(((struct Obj08221 *)p)->fAF4,(u16)(*(int *)(p+0xae0+i*4)));
    *(Vec *)(q+4) = *(Vec *)(*(char * *)&((struct Obj14240 *)q)->f64+0x44);
    ((struct Obj14240 *)q)->f8 += 0x14000;
    func_02047910(r,0,0x1000);
}
