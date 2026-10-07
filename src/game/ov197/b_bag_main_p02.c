/*
 * file:     b_bag_main_p02.c
 * unit:     yes
 * function: func_0220BD14, func_0220BD24, func_0220BF20, func_0220BF40, func_0220C034, func_0220C06C, func_0220C0B4, func_0220C180, func_0220C220, func_0220C27C, func_0220C304
 * address:  0x0220BD14
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202CA0C 0x0202CA0C thumb
 *   func_0202CE50 0x0202CE50 thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_0202CC70 0x0202CC70 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0220BB98 0x0220BB98 thumb
 *   d_0220DB44 0x0220DB44 data a1
 *   func_0220C40C 0x0220C40C thumb ov197
 *   func_0220C68C 0x0220C68C thumb ov197
 *   func_0220C6D0 0x0220C6D0 thumb ov197
 *   sub_02043598 0x02043598 arm
 *   func_0202F138 0x0202F138 thumb
 *   func_02020F08 0x02020F08 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_02020F0C 0x02020F0C thumb
 *   func_02020F10 0x02020F10 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020216B4 0x020216B4 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_02049F78 0x02049F78 arm
 *   func_020215BC 0x020215BC thumb
 */
#include "../../matched/include/Obj25014.h"
#include "../../matched/include/Obj08355.h"
#include "../../matched/include/Obj01005.h"
#include "../../matched/include/Obj00315.h"
#include "../../matched/include/Obj25015.h"
#include "../../matched/include/Obj25016.h"
#include "../../matched/include/Obj25017.h"
#include "../../matched/include/Obj25018.h"
#include "../../matched/include/Obj25019.h"
#include "../../matched/include/Obj01075.h"
#include "../../matched/include/Obj14545.h"
#include "../../matched/include/Obj25020.h"
#include "../../matched/include/Obj25021.h"
#include "../../matched/include/Obj10833.h"
#include "../../matched/include/Obj25022.h"
#include "../../matched/include/Obj25023.h"
#include "../../matched/include/Obj25024.h"
#include "../../matched/include/Obj25025.h"
#include "../../matched/include/Obj25026.h"
#include "../../matched/include/Obj25027.h"
#include "../../matched/include/Obj25028.h"
#include "../../matched/include/Obj25029.h"
#include "../../matched/include/Obj25030.h"
#include "../../matched/include/Obj25031.h"
#include "../../matched/include/Obj25032.h"

#define MGR(p) (*(struct WinMgr **)((p) + 0x520))
struct WinMgr;
struct PalAnmSlot;
struct Sub0204A9D0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned int   u32;

struct Row { u8 a,b,c,d; };

typedef signed char    s8;

struct S { char pad0[0x520]; struct WinMgr *mgr; char pad1[0x533-0x524]; u8 idx; char pad2[5]; u8 fl[1]; };

typedef short s16;

extern void func_0202CA0C(struct WinMgr *mgr);
extern void func_0202CE50(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern unsigned func_0220BB98(const char *p, unsigned n);
extern void func_0220C06C(char *),func_0220C0B4(char *),func_0220C27C(char *),func_0220C304(char *),func_0220C40C(char *),func_0220C68C(char *),func_0220C6D0(char *);
extern void sub_02043598(u32,u32);
extern u16 func_0202F138(u32 i);
extern unsigned func_02020F08(void),func_02020E60(unsigned,unsigned);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,u16);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_02020F0C(void),func_02020F10(void);
extern int func_0204AF28(void *,unsigned,unsigned,unsigned);
extern void func_02049238(void *);
extern unsigned func_02020F08(void);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
void func_0220BD14(char *a);
void func_0220BD24(char *p, int mode);
void func_0220BF20(char *p, int v);
void func_0220BF40(char *p);
void func_0220C034(char *p);
void func_0220C06C(char *p);
void func_0220C0B4(char *p);
void func_0220C180(char *p,u16 item,unsigned slot,unsigned offset);
void func_0220C220(char *p,unsigned item,unsigned slot);
void func_0220C27C(char *p);
void func_0220C304(char *p);
extern const struct Row d_0220DB44[];


void func_0220BD14(char *a)
{
    func_0202CA0C(*(struct WinMgr * *)&((struct Obj25014 *)a)->f520);
}

/*
 * note 2026-10-05 (wave D4 lane 02): the two window calls 11/12 are written in each if/else
 *   arm with literal arguments. Tail merging sinks the common call parts into the join and keeps
 *   r4 = 0x533 live, so 0x520 comes out as 0x533 - 0x13.
 */
void func_0220BD24(char *p, int mode)
{
    u32 i;
    for (i = 0; i < 14; i++) func_0202CC70(MGR(p), i);
    switch (mode) {
    case 0:
        func_0202CB4C(MGR(p), 10, 27, 19);
        func_0202CB4C(MGR(p), 13, 1, 19);
        if (*(u16 *)(p + 0x540) == 0)
            func_0202CE50(MGR(p), 13, 0, 0, 25, 5, 3);
        else
            func_0202CE50(MGR(p), 13, 0, 0, 25, 5, 1);
        func_0202CC58(MGR(p), 0);
        func_0202CC58(MGR(p), 1);
        func_0202CC58(MGR(p), 2);
        func_0202CC58(MGR(p), 3);
        func_0202CC58(MGR(p), 10);
        func_0202CC58(MGR(p), 13);
        break;
    case 1: {
        struct WinMgr **pm;
        func_0202CB4C(MGR(p), 10, 59, 19);
        pm = (struct WinMgr **)(p + 0x520);
        for (i = 0; i < 6; i++) {
            if (func_0220BB98(p, i) == 0)
                func_0202CE50(MGR(p), i + 4, 0, 0, d_0220DB44[i + 4].c, d_0220DB44[i + 4].d, 6);
            else
                func_0202CE50(*pm, i + 4, 0, 0, d_0220DB44[i + 4].c, d_0220DB44[i + 4].d, 4);
        }
        {
            struct S *q = (struct S *)p;
            if (q->fl[q->idx] == 0) {
                func_0202CE50(q->mgr, 11, 0, 0, 5, 5, 3);
                func_0202CE50(q->mgr, 12, 0, 0, 5, 5, 3);
            } else {
                func_0202CE50(q->mgr, 11, 0, 0, 5, 5, 1);
                func_0202CE50(q->mgr, 12, 0, 0, 5, 5, 1);
            }
        }
        func_0202CC58(MGR(p), 4);
        func_0202CC58(MGR(p), 5);
        func_0202CC58(MGR(p), 6);
        func_0202CC58(MGR(p), 7);
        func_0202CC58(MGR(p), 8);
        func_0202CC58(MGR(p), 9);
        func_0202CC58(MGR(p), 11);
        func_0202CC58(MGR(p), 12);
        func_0202CC58(MGR(p), 10);
        break;
    }
    case 2:
        func_0202CE50(MGR(p), 13, 0, 0, 25, 5, 1);
        func_0202CB4C(MGR(p), 10, 27, 51);
        func_0202CB4C(MGR(p), 13, 1, 51);
        func_0202CC58(MGR(p), 10);
        func_0202CC58(MGR(p), 13);
        break;
    }
}


void func_0220BF20(char *p, int v)
{
    ((struct Obj08355 *)p)->f524 = 0;
    ((struct Obj08355 *)p)->f525 = 0;
    ((struct Obj08355 *)p)->f526 = v;
    ((struct Obj08355 *)p)->f527 = 1;
}

/*
 * matching: naming unsigned index before the u8 palette settles r0/r2;
 *   unnamed repeated index loads differ in18 bytes. Callee uses u8 palette.
 */
void func_0220BF40(char *p)
{
    if(((struct Obj01005 *)p)->f527) {
        switch(((struct Obj01005 *)p)->f524) {
        case 0: {
            unsigned index=((struct Obj01005 *)p)->f526;
            u8 color;
            color=2;
            if(index<10) color=5;
            func_0202CE50(((struct Obj01005 *)p)->f520,index,0,0,d_0220DB44[index].c,d_0220DB44[index].d,color);
            func_0202CC58(((struct Obj01005 *)p)->f520,((struct Obj01005 *)p)->f526);
            (((struct Obj01005 *)p)->f524)++;
            break;
        }
        case 1: {
            unsigned index;
            u8 color;
            if(((struct Obj01005 *)p)->f525==4) {
                index=((struct Obj01005 *)p)->f526;
                color=1;
                if(index<10) color=4;
                func_0202CE50(((struct Obj01005 *)p)->f520,index,0,0,d_0220DB44[index].c,d_0220DB44[index].d,color);
                func_0202CC58(((struct Obj01005 *)p)->f520,((struct Obj01005 *)p)->f526);
                ((struct Obj01005 *)p)->f525=0;
                (((struct Obj01005 *)p)->f524)++;
            } else (((struct Obj01005 *)p)->f525)++;
            break;
        }
        case 2:
            if(((struct Obj01005 *)p)->f525==1) {
                ((struct Obj01005 *)p)->f525=0;
                ((struct Obj01005 *)p)->f524=0;
                ((struct Obj01005 *)p)->f527=0;
            } else (((struct Obj01005 *)p)->f525)++;
            break;
        }
    }
}

/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
void func_0220C034(char *p) { func_0220C06C(p); func_0220C0B4(p); func_0220C27C(p); func_0220C304(p); func_0220C40C(p); func_0220C68C(p); func_0220C6D0(p); sub_02043598(16,1); }

void func_0220C06C(char *p)
{
    unsigned i;
    for(i=0;i<9;i++) *(int *)(p+0x544+i*4)=-1;
    for(i=0;i<9;i++) *(int *)(p+0x568+i*4)=-1;
    for(i=0;i<3;i++) *(int *)(p+0x58c+i*4)=-1;
}

/*
 * matching: arc declared before first/second fixes the three spill homes.
 *   0204ABF0 argument4 is u16: caller explicitly truncates i*32.
 *   0202F138 result widened to reproduce caller's explicit u16 narrowing;
 *   its own sub_0202F138 returns u16, which removed the observed shifts.
 */
void func_0220C0B4(char *p)
{
    u16 item,i;
    void *arc;
    unsigned first,second;
    int a;
    if(((struct Obj25015 *)(*(char * *)&((struct Obj00315 *)p)->f0))->f8==1) {item=(unsigned)func_0202F138(0);first=3;second=4;}
    else {first=1;item=1;second=2;}
    arc=func_020490F4(func_02020F08(),(u16)((((struct Obj25016 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    for(i=0;i<7;i++) {
        *(int *)(p+i*4+0x544)=func_0204A6C8(arc,func_02020E60(item,first),0,1,((struct Obj25017 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
        *(int *)(p+i*4+0x568)=func_0204ABF0(arc,func_02020E60(item,second),1,(u16)(i*32),((struct Obj25018 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    }
    a=func_02020F0C();
    ((struct Obj00315 *)p)->f58C=func_0204AF28(arc,a,func_02020F10(),((struct Obj25019 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    func_02049238(arc);
}

/*
 * matching: u16 item restores entry spill order without extra truncation; unsigned item differs in eight bytes.
 */
void func_0220C180(char *p,u16 item,unsigned slot,unsigned offset)
{
    char *q=*(char * *)&((struct Obj01075 *)p)->f0;
    unsigned first, second;
    void *arc;
    void *data,*buffer;
    if(((struct Obj14545 *)q)->f8==1) {first=3;second=4;} else {first=1;second=2;}
    arc=func_020490F4(func_02020F08(),(u16)((((struct Obj14545 *)q)->fC&0x7fff)|0x8000));
    buffer=func_02049E74(arc,func_02020E60(item,first),0,(u32)(&data),((struct Obj25020 *)(*(char * *)&((struct Obj01075 *)p)->f0))->fC);
    func_0204A9D0(*(int *)(p+slot*4+0x544),data);
    func_020307B0(buffer);
    func_020216B4(((struct Obj01075 *)p)->f8,(void *)((unsigned)arc),func_02020E60(item,second),((struct Obj25021 *)(*(char * *)&((struct Obj01075 *)p)->f0))->fC,3,32,offset*16);
    func_02049238(arc);
}

void func_0220C220(char *p,unsigned item,unsigned slot)
{
    char *q=*(char * *)&((struct Obj01075 *)p)->f0;
    unsigned archive;
    if(((struct Obj10833 *)q)->f8==1) {
        archive=func_02020F08();
        func_02049B40(archive,func_02020E60(item,4),5,slot*32,32,((struct Obj10833 *)q)->fC);
    } else {
        archive=func_02020F08();
        func_02049B40(archive,func_02020E60(item,2),5,slot*32,32,((struct Obj10833 *)q)->fC);
    }
}

void func_0220C27C(char *p)
{
    void *arc = func_020490F4(99,(u16)((((struct Obj25022 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    ((struct Obj00315 *)p)->f560=func_0204A6C8(arc,13,1,1,((struct Obj25023 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f584=func_0204ABF0(arc,14,1,224,((struct Obj25024 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f590=func_0204AF28(arc,15,16,((struct Obj25025 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    func_020216B4(((struct Obj00315 *)p)->f8,(void *)((unsigned)arc),14,((struct Obj25026 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC,3,32,112);
    func_02049238(arc);
}

void func_0220C304(char *p)
{
    void *arc = func_020490F4(11,(u16)((((struct Obj25027 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    char *data;
    void *buf;
    ((struct Obj00315 *)p)->f564=func_0204A6C8(arc,119,0,1,((struct Obj25028 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f588=func_0204AC18(arc,116,1,256,4,1,((struct Obj25029 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    ((struct Obj00315 *)p)->f594=func_0204AF28(arc,120,121,((struct Obj25030 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC);
    buf=func_02049F78(arc,116,(u32)(&data),(u16)((((struct Obj25031 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC&0x7fff)|0x8000));
    func_020215BC(((struct Obj00315 *)p)->f8,*(char * *)&((struct Obj25032 *)data)->fC+128,3,128,32);
    func_020307B0(buf);
    func_02049238(arc);
}
