/*
 * file:     zukan.c
 * unit:     yes
 * function: func_021C8E80, func_021C8F2C, func_021C8F58, func_021C8F7C, func_021C8F90, func_021C8F98, func_021C8FA8, func_021C8FF4, func_021C9024, func_021C9098, func_021C9130, func_021C9184, func_021C91C4, func_021C9244, func_021C9288, func_021C92EC, func_021C9348, func_021C9380, func_021C93A8, func_021C93C4, func_021C93E4, func_021C940C, func_021C9428, func_021C9460, func_021C9468, func_021C976C, func_021C983C, func_021C98A8
 * address:  0x021C8E80
 * region:   ov212
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
 *   func_02082BCC 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   d_021C9944 0x021C9944 data a4
 *   func_02030734 0x02030734 arm
 *   PROCSYS_Push 0x02031348 arm
 *   d_021C99A0 0x021C99A0 data a1
 *   d_021BC8BC 0x021BC8BC data ov211 a4
 *   ov211_id 0x000000D3 data a1
 *   d_021BE794 0x021BE794 data ov209 a4
 *   ov209_id 0x000000D1 data a1
 *   func_020307B0 0x020307B0 arm
 *   d_021C0714 0x021C0714 data ov210 a4
 *   ov210_id 0x000000D2 data a1
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA8C 0x0200CA8C thumb
 *   d_021C8108 0x021C8108 data ov208 a4
 *   ov208_id 0x000000D0 data a1
 *   func_0200CA78 0x0200CA78 thumb
 *   func_0200CA70 0x0200CA70 thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200D064 0x0200D064 thumb
 *   func_0202208C 0x0202208C thumb
 *   open 0x020490F4 arm
 *   close 0x02049238 arm
 *   initial 0x021C983C thumb ov212
 *   tables 0x021C98A8 thumb ov212
 *   alloc 0x02030734 arm
 *   release 0x020307B0 arm
 *   known 0x0200D064 thumb
 *   properties 0x0200CC40 thumb
 *   seen 0x0200CED4 thumb
 *   personalFree 0x0201AE14 thumb
 *   personal 0x0201ADE4 thumb
 *   value 0x0201AE1C thumb
 *   finalTest 0x021C9918 thumb ov212
 *   site 0x021C99A8 data ov212 a1
 *   load 0x0204A298 arm
 *   names 0x0201AF80 thumb
 *   func_0204A39C  0x0204A39C  arm
 *   g_021C99A8     0x021C99A8  data
 *   g_021C9968     0x021C9968  data
 *   POKE_PERSONAL_LoadFormTable  0x0201AF80  thumb
 */
#include "../../matched/include/Obj00635.h"
#include "../../matched/include/Obj25642.h"
#include "../../matched/include/Obj25643.h"
#include "../../matched/include/Obj25644.h"
#include "../../matched/include/Obj25645.h"
#include "../../matched/include/Obj25646.h"
#include "../../matched/include/Obj25647.h"
#include "../../matched/include/Obj25648.h"
#include "../../matched/include/Obj25649.h"
#include "../../matched/include/Obj25650.h"
#include "../../matched/include/Obj08415.h"
#include "../../matched/include/Obj08416.h"
#include "../../matched/include/Obj08416.h"
#include "../../matched/include/Obj25651.h"
#include "../../matched/include/Obj06701.h"
#include "../../matched/include/Obj25653.h"
#include "../../matched/include/Obj08417.h"
#include "../../matched/include/Obj25654.h"
#include "../../matched/include/Obj25655.h"
#include "../../matched/include/Obj25656.h"
#include "../../matched/include/Obj02259.h"
#include "../../matched/include/Obj04626.h"
#include "../../matched/include/Obj25658.h"
#include "../../matched/include/Obj25659.h"
#include "../../matched/include/Obj01587.h"
#include "../../matched/include/Obj25660.h"
#include "../../matched/include/Obj25661.h"
#include "../../matched/include/Obj25662.h"
#include "../../matched/include/Obj25663.h"
#include "../../matched/include/Obj25664.h"
#include "../../matched/include/Obj25665.h"
#include "../../matched/include/Obj25666.h"
#include "../../matched/include/Obj06702.h"
#include "../../matched/include/Obj06703.h"
#include "../../matched/include/Obj25668.h"
#include "../../matched/include/Obj04627.h"
#include "../../matched/include/Obj10926.h"
#include "../../matched/include/Obj25669.h"
#include "../../matched/include/Obj04628.h"
#include "../../matched/include/Obj04629.h"
#include "../../matched/include/Obj08418.h"
#include "../../matched/include/Obj03938.h"

struct Obj0203159C;
struct Blk37;
struct S020314B8;
struct S020315D4;
struct Obj020314F4;
struct Obj;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* hidden function: 16 bytes between func_021C8F90 and func_021C8FA8 */
struct Obj021C8F98 {
    u32 f0, f4, f8, fC, f10, f14, f18, f1C, f20;
};

struct Query { u8 mode; u8 rule; u8 kind; u8 type1; u8 type2; u8 attr; u8 last; };

struct Search {
  void *save; struct Query *query; u16 state; u16 padA; void *arc;
  u16 index; u16 count; u16 *ids; u8 *reject;
  u16 count1; u16 pad1; u16 *table1; u16 count2; u16 pad2; u8 *table2;
  u16 count3; u16 pad3; u8 *table3; u16 count4; u16 pad4; u16 *table4;
  void *personal; u16 resultCount; u16 pad42; u16 *result;
};

extern void func_0203064C(unsigned,unsigned,unsigned);
extern void *func_0203159C(struct Obj0203159C *,unsigned,unsigned);
extern void func_02082BCC(void *,unsigned char,unsigned);
extern void *PROCSYS_Create(int);
extern unsigned PROCSYS_Main(void *);
extern void func_0203133C(struct S020314B8 *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32 heap);
extern u32 func_020307B0(void *p);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void PROCSYS_Push(struct Obj020314F4 *,unsigned,unsigned,unsigned);
extern void *func_0200CA1C(void *);
extern u16 func_0200CA8C(struct Blk37 *);
extern void func_0200CA78(struct Blk37 *p, u32 v);
extern unsigned func_0200CA70(struct Blk37 *);
extern unsigned func_0200CED4(struct Blk37 *,u16);
extern unsigned func_0200D064(struct Blk37 *,u16);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_02041EE4(u32,u32,u32);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void *open(u32, u16);
extern void close(void *);
extern u32 initial(void *, int, int, u32, u16 **);
extern void tables(void *, u32, u16 *, u16 **, u16 *, u8 **, u16 *, u8 **, u16 *, u16 **);
extern void *alloc(u32, u32, int, const char *, u16);
extern void release(void *);
extern u32 known(void *, u16);
extern void properties(void *, u16, u32 *, u32 *, u32 *, u16);
extern u32 seen(void *, u16);
extern void personalFree(void *);
extern void *personal(u32, int, u32);
extern u32 value(const void *, u32);
extern u8 finalTest(const u8 *, const u16 *, u32, u32);
extern void *load(int,int,int,int,u32 *);
extern u16 *names(int,u16 *);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
int func_021C8E80(struct Obj0203159C *obj,int unused,char *ctx);
int func_021C8F2C(int a,int b,int c,unsigned char *p);
int func_021C8F58(struct S020315D4 *obj, void *b, void *c, u8 *p);
void func_021C8F7C(u8 *p);
int func_021C8F90(char *p, int v);
u32 func_021C8F98(struct Obj021C8F98 *p);
void func_021C8FA8(char *p);
int func_021C8FF4(u8 *p);
void func_021C9024(char *p);
int func_021C9098(char *p);
void func_021C9130(char *p);
int func_021C9184(char *p);
void func_021C91C4(char *p);
int func_021C9244(char *p);
u16 func_021C9288(struct Blk37 *save,u16 **out,unsigned heap);
void func_021C92EC(void *p,u16 *ids,unsigned count);
int func_021C9348(struct Blk37 *p);
void func_021C9380(struct Blk37 *p, u8 *out);
void func_021C93A8(u32 heap);
void func_021C93C4(u32 heap);
void func_021C93E4(u32 a, u32 b, u32 *counter);
struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap);
void func_021C9428(int p, int b, int c);
void func_021C9460(int a0);
int func_021C9468(struct Search *p, u16 heap, u16 *outCount, u16 **out);
u32 func_021C976C(u32 mode,int heap,u16 **out);
unsigned int func_021C983C(int a0, int a1, int a2, int a3, u16 **out);
void func_021C98A8(u32 a0, u32 a1, u16 *a2, u32 *a3, u16 *a4, u32 *a5, u16 *a6, u32 *a7, u16 *a8, u32 *a9);
extern unsigned char d_021C9944[];
extern const char d_021C99A0[];
extern const unsigned d_021BC8BC[];
extern unsigned char ov211_id[];
extern const unsigned d_021BE794[];
extern unsigned char ov209_id[];
extern const unsigned d_021C0714[];
extern unsigned char ov210_id[];
extern const unsigned d_021C8108[];
extern unsigned char ov208_id[];
extern const char site[];
extern const char g_021C99A8[];
extern int g_021C9968[];




/*
 * trailing: two zero alignment bytes at 021C8F2A.
 * prototype: caller consumes r0 from legacy void 0203159C and 02031324;
 * 31324 forwards r0 to matched 31354(int), which returns allocation.
 * 3064C visibly receives three inputs here; retain caller's r2 size.
 */
int func_021C8E80(struct Obj0203159C *obj,int unused,char *ctx)
{
    char *p;
    func_0203064C(1,105,0x8000);
    p=func_0203159C(obj,44,105);
    func_02082BCC(p,0,44);
    ((struct Obj00635 *)p)->f0=ctx;
    ((struct Obj00635 *)p)->f4=PROCSYS_Create(105);
    ((struct Obj00635 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25642 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,(u16 **)(p+12),105);
    ((struct Obj00635 *)p)->f12=0;
    func_021C92EC(*(struct Blk37 * *)&((struct Obj25643 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,*(u16 * *)&((struct Obj00635 *)p)->fC,((struct Obj00635 *)p)->f10);
    func_021C9380(*(struct Blk37 * *)&((struct Obj25644 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,(unsigned char *)(p+20));
    if(((struct Obj25645 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==0){((struct Obj00635 *)p)->f1C=1;}
    else if(((struct Obj25646 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==1){((struct Obj00635 *)p)->f1C=3;}
    else if(((struct Obj25647 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==2){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=1;}
    else if(((struct Obj25648 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==3){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=2;}
    else if(((struct Obj25649 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==4){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=3;}
    else if(((struct Obj25650 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==5){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=4;}
    else {((struct Obj00635 *)p)->f1C=7;}
    return 1;
}




int func_021C8F2C(int a,int b,int c,unsigned char *p){if(((struct Obj08415 *)p)->f1C==9)return 1;((struct Obj08415 *)p)->f8=PROCSYS_Main(((struct Obj08415 *)p)->f4);((struct Obj08415 *)p)->f1C=(*(unsigned (**)(unsigned char *))(d_021C9944+*(unsigned *)(p+28)*4))(p);return 0;}




int func_021C8F58(struct S020315D4 *obj, void *b, void *c, u8 *p) {
    func_021C8F7C(p);
    func_0203133C(*(struct S020314B8 * *)&((struct Obj08416 *)p)->f4);
    func_020315D4(obj);
    func_020306F0(105);
    return 1;
}



void func_021C8F7C(u8 *p)
{
    if (((struct Obj08416 *)p)->fC != 0) {
        func_020307B0(((struct Obj08416 *)p)->fC);
        ((struct Obj08416 *)p)->fC = 0;
    }
}



int func_021C8F90(char *p, int v)
{
    ((struct Obj25651 *)p)->f20 = v;
    return 0;
}


u32 func_021C8F98(struct Obj021C8F98 *p)
{
    if (p->f8 != 1)
        return p->f20;
    return 0;
}



void func_021C8FA8(char *p)
{
    unsigned *q;
    q=func_02030734(105,12,0,d_021C99A0,297);
    ((struct Obj06701 *)p)->f28=q;
    q[0]=**(unsigned * *)&((struct Obj06701 *)p)->f0;
    q[1]=((struct Obj25653 *)(*(char * *)&((struct Obj06701 *)p)->f0))->f8;
    PROCSYS_Push(*(struct Obj020314F4 * *)&((struct Obj06701 *)p)->f4,(unsigned)ov211_id,(unsigned)d_021BC8BC,*(unsigned *)&((struct Obj06701 *)p)->f28);
    func_021C8F90(p,2);
}




int func_021C8FF4(u8 *p) {
    int result;
    switch (((struct Obj25654 *)(*(u8 * *)&((struct Obj08417 *)p)->f28))->f8) {
    case 0:
        ((struct Obj25655 *)(*(u8 * *)&((struct Obj08417 *)p)->f0))->fE = 0;
        result = 9;
        break;
    case 1:
        ((struct Obj25656 *)(*(u8 * *)&((struct Obj08417 *)p)->f0))->fE = 1;
        result = 9;
        break;
    case 2: result = 3; break;
    }
    func_020307B0(((struct Obj08417 *)p)->f28);
    return result;
}




/*
 * prototype: 02031348 legacy void(void) forwards r0-r3 to 020314F4,
 * whose matched body reads all four; this caller sets all four.
 */
void func_021C9024(char *p)
{
    char *q=func_02030734(105,20,0,d_021C99A0,359);
    ((struct Obj02259 *)p)->f28=q;
    ((struct Obj04626 *)q)->f0=**(unsigned * *)&((struct Obj02259 *)p)->f0;
    ((struct Obj04626 *)q)->f4=((struct Obj25658 *)(*(char * *)&((struct Obj02259 *)p)->f0))->f4;
    ((struct Obj04626 *)q)->f8=((struct Obj02259 *)p)->f12;
    if(((struct Obj02259 *)p)->f12==0&&func_021C9348(*(struct Blk37 * *)&((struct Obj25659 *)(*(char * *)&((struct Obj02259 *)p)->f0))->f4)==0){
        *(u16 * *)&((struct Obj04626 *)q)->fC=*(u16 * *)&((struct Obj02259 *)p)->fC+1;
        ((struct Obj04626 *)q)->fA=((struct Obj02259 *)p)->f10-1;
    }else{
        ((struct Obj04626 *)q)->fC=((struct Obj02259 *)p)->fC;
        ((struct Obj04626 *)q)->fA=((struct Obj02259 *)p)->f10;
    }
    PROCSYS_Push(*(struct Obj020314F4 * *)&((struct Obj02259 *)p)->f4,(unsigned)ov209_id,(unsigned)d_021BE794,*(unsigned *)&((struct Obj02259 *)p)->f28);
    func_021C8F90(p,4);
}




/*
 * lever: spell the empty-result arm first in the nested if/else;
 * shared failure exit remains after the switch.
 */
int func_021C9098(char *p)
{
    int result;
    switch(((struct Obj25660 *)(*(char * *)&((struct Obj01587 *)p)->f28))->f10){
    case 0:
        if(((struct Obj01587 *)p)->f12==0){
            ((struct Obj25661 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=0;result=9;
        }else{
            func_021C8F7C((u8 *)p);
            ((struct Obj01587 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25662 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
            ((struct Obj01587 *)p)->f12=0;result=3;
        }
        goto done;
    case 1:((struct Obj25663 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=1;result=9;goto done;
    case 2:
        func_021C8F7C((u8 *)p);
        ((struct Obj01587 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25664 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
        result=3;goto done;
    case 3:result=5;((struct Obj01587 *)p)->f24=1;goto done;
    case 4:
        if(((struct Obj01587 *)p)->f12==1){
            func_021C8F7C((u8 *)p);
            ((struct Obj01587 *)p)->f10=func_021C9288(*(struct Blk37 * *)&((struct Obj25665 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
        }
        result=7;goto done;
    default:break;
    }
    ((struct Obj25666 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=0;result=9;
done:
    func_020307B0(((struct Obj01587 *)p)->f28);
    return result;
}




/*
 * prototype: 02031348 legacy void(void) forwards untouched r0-r3 to
 * 020314F4; its matched body reads all four and caller sets all four.
 */
void func_021C9130(char *p)
{
    char *q;
    q=func_02030734(105,24,0,d_021C99A0,455);
    ((struct Obj06702 *)p)->f28=q;
    ((struct Obj06703 *)q)->f0=**(unsigned * *)&((struct Obj06702 *)p)->f0;
    ((struct Obj06703 *)q)->f4=((struct Obj25668 *)(*(char * *)&((struct Obj06702 *)p)->f0))->f4;
    ((struct Obj06703 *)q)->f8=p+20;
    ((struct Obj06703 *)q)->f10=0;
    ((struct Obj06703 *)q)->f14=0;
    PROCSYS_Push(*(struct Obj020314F4 * *)&((struct Obj06702 *)p)->f4,(unsigned)ov210_id,(unsigned)d_021C0714,*(unsigned *)&((struct Obj06702 *)p)->f28);
    func_021C8F90(p,8);
}




/*
 * trailing: two zero alignment bytes at 021C91C2.
 * lever: assign the result in each arm after its stores, keeping r4 reusable.
 */
int func_021C9184(char *p)
{
    char *q=*(char * *)&((struct Obj04627 *)p)->f28;
    int result;
    switch(((struct Obj10926 *)q)->fC){
    case 0:
        func_021C8F7C((u8 *)p);
        ((struct Obj04627 *)p)->fC=((struct Obj10926 *)q)->f10;
        ((struct Obj04627 *)p)->f10=((struct Obj10926 *)q)->f14;
        ((struct Obj04627 *)p)->f12=1;
        result=3;
        break;
    case 1:
        ((struct Obj04627 *)p)->f12=0;
        result=3;
        break;
    case 2:
    default:
        ((struct Obj25669 *)(*(char * *)&((struct Obj04627 *)p)->f0))->fE=1;
        result=9;
        break;
    }
    func_020307B0(((struct Obj04627 *)p)->f28);
    return result;
}




/*
 * prototype: 02031348 forwards all four original inputs to 020314F4;
 * the matched forwarding target reads each, overriding legacy void(void).
 */
void func_021C91C4(char *p)
{
    char *q;
    u16 selected,i;
    selected=func_0200CA8C(func_0200CA1C(*(void **)*(char * *)&((struct Obj04628 *)p)->f0));
    q=func_02030734(105,20,0,d_021C99A0,530);
    ((struct Obj04629 *)q)->f0=**(unsigned * *)&((struct Obj04628 *)p)->f0;
    ((struct Obj04629 *)q)->f4=((struct Obj04628 *)p)->f24;
    ((struct Obj04629 *)q)->f8=((struct Obj04628 *)p)->fC;
    ((struct Obj04629 *)q)->fC=((struct Obj04628 *)p)->f10;
    ((struct Obj04629 *)q)->fE=0;
    for(i=0;i<((struct Obj04629 *)q)->fC;i++){
        if((*(u16 **)(q+8))[i]==selected){((struct Obj04629 *)q)->fE=i;break;}
    }
    PROCSYS_Push(*(struct Obj020314F4 * *)&((struct Obj04628 *)p)->f4,(unsigned)ov208_id,(unsigned)d_021C8108,(unsigned)q);
    ((struct Obj04628 *)p)->f28=q;
    func_021C8F90(p,6);
}




int func_021C9244(char *p)
{
    struct Blk37 *save;
    char *q;
    int result;
    save = func_0200CA1C(*(void **)*(char **)p);
    q = *(char **)(p + 0x28);
    func_0200CA78(save, (*(u16 **)(q + 8))[*(u16 *)(q + 14)]);
    switch (*(int *)(q + 0x10)) {
    case 0:
        *(u16 *)(*(char **)p + 14) = 1;
        result = 9;
        break;
    case 1:
        *(u16 *)(*(char **)p + 14) = 0;
        result = 3;
        break;
    }
    func_020307B0(*(void **)(p + 0x28));
    return result;
}



/*
 * lever: branch-local calls retain the original boolean polarity and hoist
 * the shared output-address setup; initializing selected follows the call.
 */
u16 func_021C9288(struct Blk37 *save,u16 **out,unsigned heap)
{
    u16 *list;
    unsigned count,i;
    u16 selected;
    if(func_0200CA70(save)==1)count=func_021C976C(0,heap,&list);
    else count=func_021C976C(1,heap,&list);
    selected=0;
    for(i=0;i<count;i++){
        if(func_0200CED4(save,list[i])==1||func_0200D064(save,list[i])==1)selected=i+1;
    }
    *out=list;
    return selected;
}



void func_021C92EC(void *p,u16 *ids,unsigned count)
{
    unsigned current;
    u16 chosen,i;
    chosen=0xFFFF;current=func_0200CA8C(p);
    for(i=0;i<count;i++) {
        if(func_0200D064(p,ids[i])==1) {
            if(current==ids[i]) return;
            if(chosen==0xFFFF) chosen=ids[i];
        }
    }
    if(chosen!=0xFFFF) func_0200CA78(p,chosen);
}



int func_021C9348(struct Blk37 *p) {
    if (func_0200CA70(p) == 1) return 1;
    if (func_0200CED4(p,494) == 1 || func_0200D064(p,494) == 1) return 1;
    return 0;
}



void func_021C9380(struct Blk37 *p, u8 *out) {
    if(func_0200CA70(p)==1) out[0]=0; else out[0]=1;
    out[1]=0; out[2]=255; out[3]=255; out[4]=255; out[5]=255; out[6]=255;
}



void func_021C93A8(u32 heap) { func_0202208C(0,1,1,0,6,1,heap); }



void func_021C93C4(u32 heap) { func_0202208C(0,0,0,0,6,1,heap); }



void func_021C93E4(u32 a, u32 b, u32 *counter) {
    ++*counter;
    if(*counter==4) { func_02041EE4(a,1,1); func_02041EE4(b,1,1); *counter=0; }
}



struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap) {
    return func_0204B294((void *)bank,*(const u32 *)&((struct Obj08418 *)t)->f8,*(const u32 *)&((struct Obj08418 *)t)->fC,*(const u32 *)&((struct Obj08418 *)t)->f10,t,*(const u16 *)&((struct Obj08418 *)t)->f16,heap);
}




void func_021C9428(int p, int b, int c)
{
    unsigned char *q = func_02030734(c, 0x48, 1, (const char *)0x021C99A8, 0x1ce);

    ((struct Obj03938 *)q)->f0 = p;
    ((struct Obj03938 *)q)->f4 = b;
    ((struct Obj03938 *)q)->f8 = 0;
    ((struct Obj03938 *)q)->fC = 0;
    ((struct Obj03938 *)q)->f10 = 0;
    ((struct Obj03938 *)q)->f3C = 0;
    ((struct Obj03938 *)q)->f40 = 0;
    ((struct Obj03938 *)q)->f44 = 0;
}




/*
 * Bottom-up unblocker for the last unresolved site of
 * src/pending/func_021BD3AC.c.  Thumb tail-call veneer into the ARM9
 * func_020307B0 (the image is `ldr r3,[pc,#0]; bx r3; .word 0x020307B0`);
 * disasm emits it as an unlabelled `.word` run, so no listing class attests
 * it.  Addresses are Black-image addresses.
 */
void func_021C9460(int a0)
{
    func_020307B0((void *)a0);
}



/*
 * note 2026-10-05 (P24L1): rewritten from the listing, bytes equal (772/772). Only relocation
 *   without a witness is finalTest 0x021C9918; the leaf is filed as src/matched/ov/ov212_func_021C9918.c
 *   (EXACT c99 and c), so a manifest refresh should resolve it and promote this file to EXACT.
 *   Levers that closed it from 483 B off: (1) calls with each reject written as
 *   p->reject[i] = 1; continue; at every failing test (raises the use count of i, so i keeps r5
 *   and form takes the spill slot; the tail merges back to one store), (2) u16 of = outForm read
 *   once and used for both the 649 test and the compare, (3) u16 count, (4) u8 fr = finalTest(..)
 *   local before the compare to the query byte (cmp operand order), (5) u16 n = p->count read
 *   before i = p->index (load order at the top of case 3), (6) mask = 1023 as a local gives the
 *   ldr 999; adds 0x18 pair. Older draft docs/notes/pkt_ov212_021C9468.c.txt is superseded.
 */
int func_021C9468(struct Search *p, u16 heap, u16 *outCount, u16 **out)
{
  u32 unused1, unused2, outForm;
  u16 end, i, j, used, species, form;
  u16 count;
  u16 *result;
  u8 type1, type2, id;
  u16 of, n;
  switch (p->state) {
  case 0:
    p->arc = open(98, heap);
    p->state = 1;
    break;
  case 1:
    p->count = initial(p->arc, p->query->mode, p->query->rule, heap, &p->ids);
    p->reject = alloc(heap, p->count, 1, site, 551);
    p->state = 2;
    break;
  case 2:
    tables(p->arc, heap, &p->count1, &p->table1, &p->count2, &p->table2, &p->count3, (u8 **)&p->table3, &p->count4, &p->table4);
    p->state = 3;
    break;
  case 3:
    n = p->count;
    i = p->index;
    if (i >= n) { p->state = 4; break; }
    end = i + 7;
    if (end > n) end = n;
    p->index = end;
    for (; i < end; i++) {
      u32 v = p->ids[i];
      species = v & 1023;
      form = (v & 0xFC00) >> 10;
      if (!known(p->save, species)) { p->reject[i] = 1; continue; }
      properties(p->save, species, &unused1, &unused2, &outForm, heap);
      of = outForm;
      if (p->count == 649) form = of;
      if (form != of) { p->reject[i] = 1; continue; }
      if ((p->query->rule >= 2 && p->query->rule <= 5) || p->query->type1 != 255 || p->query->type2 != 255) {
        if (!seen(p->save, species)) { p->reject[i] = 1; continue; }
      }
      if (p->query->mode == 1 && p->table1[species] == 999) { p->reject[i] = 1; continue; }
      if (p->query->kind != 255 && p->query->kind != p->table2[species]) { p->reject[i] = 1; continue; }
      if (p->personal) personalFree(p->personal);
      p->personal = personal(species, form, heap);
      type1 = value(p->personal, 6);
      type2 = value(p->personal, 7);
      if (p->query->type1 != 255 && p->query->type2 != 255) {
        if ((type1 == p->query->type1 && type2 == p->query->type2) || (type1 == p->query->type2 && type2 == p->query->type1)) {
        } else { p->reject[i] = 1; continue; }
      } else if (p->query->type1 != 255 && p->query->type2 == 255) {
        if (type1 != p->query->type1 && type2 != p->query->type1) { p->reject[i] = 1; continue; }
      } else if (p->query->type1 == 255 && p->query->type2 != 255) {
        if (type1 != p->query->type2 && type2 != p->query->type2) { p->reject[i] = 1; continue; }
      }
      if (p->query->attr != 255) {
        id = value(p->personal, 33);
        if (id != p->query->attr) { p->reject[i] = 1; continue; }
      }
      if (p->query->last != 255) {
        u8 fr = finalTest(p->table3, p->table4, species, form);
        if (fr != p->query->last) { p->reject[i] = 1; continue; }
      }
    }
    break;
  case 4:
    if (p->personal) personalFree(p->personal);
    count = 0;
    for (j = 0; j < p->count; j++)
      if (p->reject[j] == 0) count++;
    if (count) {
      used = 0;
      result = alloc(heap, count * 2, 0, site, 742);
      for (j = 0; j < p->count; j++)
        if (p->reject[j] == 0) { result[used] = p->ids[j] & 1023; used++; }
    } else result = 0;
    release(p->ids);
    release(p->reject);
    release(p->table1);
    release(p->table2);
    release(p->table3);
    release(p->table4);
    p->resultCount = count;
    p->result = result;
    close(p->arc);
    p->state = 5;
    break;
  case 5:
  default:
    *out = p->result;
    *outCount = p->resultCount;
    return 1;
  }
  return 0;
}



u32 func_021C976C(u32 mode,int heap,u16 **out)
{
    u16 *result;
    u16 *map;
    u16 *ids;
    u16 count;
    u32 bytes;
    u16 used;
    u16 i;
    u16 n;
    if (mode == 0) {
        used = 0;
        result = alloc(heap,1298,0,site,825);
        do {
            result[used] = used + 1;
            used = used + 1;
        } while (used < 649);
        *out = result;
        return 649;
    }
    map = names(heap,&count);
    used = 0;
    ids = load(98,4,0,heap,&bytes);
    n = (u16)(bytes / 2);
    result = alloc(heap,count * 2,0,site,862);
    for (i = 0; i < n; i++) {
        u16 id;
        id = ids[i];
        if (map[id] != 999) {
            result[used] = id;
            used++;
        }
    }
    release(ids);
    release(map);
    *out = result;
    return count;
}




unsigned int func_021C983C(int a0, int a1, int a2, int a3, u16 **out)
{
    u16 *buf;
    unsigned int n;

    if (a1 == 0 && a2 == 0) {
        u16 i;
        buf = func_02030734(a3, 0x512, 0, g_021C99A8, 0x3B1);
        for (i = 0; i < 0x289;) {
            buf[i] = i + 1;
            i++;
        }
        n = 0x289;
    } else {
        unsigned int tmp;
        buf = (u16 *)func_0204A39C((void *)a0, g_021C9968[a2], 0, a3, &tmp);
        n = (tmp >> 1) & 0xFFFF;
    }
    *out = buf;
    return n;
}




/*
 * Addresses are Black-image addresses.
 */
void func_021C98A8(u32 a0, u32 a1, u16 *a2, u32 *a3,
                   u16 *a4, u32 *a5, u16 *a6, u32 *a7, u16 *a8, u32 *a9)
{
    u32 buf;

    *a3 = (u32)POKE_PERSONAL_LoadFormTable(a1, 0);
    *a2 = 0x28A;
    *a5 = (u32)func_0204A39C((void *)a0, 1, 0, a1, &buf);
    *a4 = buf;
    *a7 = (u32)func_0204A39C((void *)a0, 2, 0, a1, &buf);
    *a6 = buf;
    *a9 = (u32)func_0204A39C((void *)a0, 0, 0, a1, &buf);
    *a8 = buf >> 1;
}
