/*
 * file:     unit_021C6180_p01.c
 * unit:     yes
 * function: func_021C6180, func_021C6208, func_021C6304, func_021C6354, func_021C6360, func_021C6390, func_021C63AC, func_021C63EC, func_021C6420, func_021C6438, func_021C6440, func_021C6460
 * address:  0x021C6180
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
 *   id127 0x0000007F data
 *   id67 0x00000043 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021C658C 0x021C658C thumb ov128
 *   func_020056A0 0x020056A0 thumb
 *   func_021C6EC0 0x021C6EC0 thumb ov128
 *   func_021C76F8 0x021C76F8 thumb ov128
 *   func_021C8C04 0x021C8C04 thumb ov128
 *   func_021C8E2C 0x021C8E2C thumb ov128
 *   func_021C9244 0x021C9244 thumb ov128
 *   func_021C6638 0x021C6638 thumb ov128
 *   func_02030EAC 0x02030EAC arm
 *   func_021C6664 0x021C6664 thumb ov128
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021C665C 0x021C665C thumb ov128
 *   id43 0x00000043 data
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_020457B0 0x020457B0 arm
 *   func_020355C4 0x020355C4 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_020355D8 0x020355D8 arm
 *   func_02045808 0x02045808 arm
 *   func_02045838 0x02045838 arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 *   func_0205994C 0x0205994C arm
 *   func_02009A1C 0x02009A1C thumb
 *   func_021CA014 0x021CA014 thumb ov128
 *   func_02059354 0x02059354 arm
 *   func_0200F43C 0x0200F43C thumb
 *   func_020099C8 0x020099C8 thumb
 *   func_02059980 0x02059980 arm
 *   func_02009A00 0x02009A00 thumb
 *   func_02009918 0x02009918 thumb
 */
#include "../../matched/include/Obj06476.h"
#include "../../matched/include/Obj03279.h"
#include "../../matched/include/Obj23062.h"
#include "../../matched/include/Obj23063.h"
#include "../../matched/include/Obj10480.h"
#include "../../matched/include/Obj08125.h"
#include "../../matched/include/Obj04503.h"
#include "../../matched/include/Obj10482.h"
#include "../../matched/include/Obj00227.h"
#include "../../matched/include/Obj00298.h"
#include "../../matched/include/Obj23065.h"

struct Obj0203159C;
struct Node;
struct S020315D4;
struct Descriptor;
struct CharBuf;
struct U16Vec;
struct BigObj;
struct Sub020097BCObj;
struct DWCstAccUserData;
struct Sub020097BCFriend;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int     s32;

typedef unsigned long long u64;

extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,int);
extern void func_021C658C(char *p, void *q, int heap);
extern void *func_020056A0(void *,void *,int);
extern int func_021C6EC0(u8 *p, u8 *q, u8 *ctx, int heap);
extern int func_021C76F8(u8 *p, u8 *q, u8 *ctx, u16 heap);
extern int func_021C8C04(void **p, u8 *a, u8 *b, void *unused, int heap);
extern int func_021C8E2C(void *p, u8 *q, u8 *r, int heap);
extern int func_021C9244(u8 *p, u8 *q, u8 *r, u16 heap);
extern void func_021C6638(u8 *p);
extern void func_02030EAC(struct Node *n);
extern void func_021C6664(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(s32 handle);
extern void func_021C665C(void *);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_021CA458(char *p, void *q);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u8 func_020355C4(void);
extern signed char func_02012FFC(void);
extern void func_020355D8(int);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern u32 func_0201283C(const struct BigObj *p);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern unsigned long long func_0205994C(struct DWCstAccUserData *userdata);
extern int func_02009A1C(struct Sub020097BCObj *obj, u32 i);
extern u64 func_021CA014(void *,int *);
extern int func_02059354(void *,u32,u32);
extern int func_0200F43C(void *,u32,u32,int *);
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);
extern void func_02059980(void *,u32,u32);
extern void func_02009A00(struct Sub020097BCObj *obj, int i, void *dest);
extern void func_02009918(struct Sub020097BCObj *obj, u32 i, u32 field, u32 value);
int func_021C6180(void *p,int unused,void *q);
int func_021C6208(int result,int *stage,int unused,char *p);
int func_021C6304(void *p,int a,int b,char *q);
void func_021C6354(void *p,char *q);
void func_021C6360(char *p,int heap);
void func_021C6390(u8 *p);
void func_021C63AC(void *p,u32 *out,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u32 unused,u8 g);
void func_021C63EC(u8 *p, const u32 *q, int heap);
void func_021C6420(u8 *p, void *a1);
void func_021C6438(u8 *p, u8 a, u8 b);
void func_021C6440(u8 *p,void *a,void *b);
int func_021C6460(char *p,void *q,u32 arg);
void func_021C6514(char *p,int x);
void func_021C651C(char *p,int x);
extern char id127[],id67[];
extern char id43[],id127[];

int func_021C6180(void *p,int unused,void *q)
{
    char *v;
    func_02034AC4((u32)id127); func_02034AC4((u32)id67);
    func_0203064C(1,52,0xc0000);
    v=func_0203159C(p,0x5b0,52);
    func_02082BCC(v,0,0x5b0);
    ((struct Obj06476 *)v)->f1F8=q; ((struct Obj06476 *)v)->f5A8=0;
    func_021C63EC((u8 *)(v+0x190),((struct Obj06476 *)v)->f1F8,52);
    func_021C658C(v+4,v+0x190,52);
    if(((struct Obj06476 *)v)->f5A8==0) ((struct Obj06476 *)v)->f5A8=func_020056A0(func_021C6354,v,16);
    return 1;
}

int func_021C6208(int result,int *stage,int unused,char *p)
{
    switch(*stage) {
    case 0:
        switch(((struct Obj03279 *)p)->f0) {
        case 0: result=func_021C6EC0((u8 *)(p+0x1fc),(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 1: result=func_021C76F8((u8 *)(p+0x24c),(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 2: result=func_021C8C04((void **)(p+0x3f8),(u8 *)p,(u8 *)(p+0x190),p+4,52); break;
        case 3: result=func_021C8E2C(p+0x404,(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 4: result=func_021C9244((u8 *)(p+0x420),(u8 *)(p+0x190),(u8 *)(p+4),52); break;
        case 5: ((struct Obj23062 *)(*(char * *)&((struct Obj03279 *)p)->f1F8))->f4=0; return 1;
        case 6: ((struct Obj23063 *)(*(char * *)&((struct Obj03279 *)p)->f1F8))->f4=1; return 1;
        }
        if(result==1) {
            *(int *)&((struct Obj03279 *)p)->f0=((struct Obj03279 *)p)->f199;
            ((struct Obj03279 *)p)->f198=((struct Obj03279 *)p)->f19A;
            ((struct Obj03279 *)p)->f5AC=4;
            *stage=1;
        }
        break;
    case 1:
        if(--((struct Obj03279 *)p)->f5AC<=0) *stage=0;
        break;
    }
    func_021C6638((u8 *)(p+4));
    return 0;
}

int func_021C6304(void *p,int a,int b,char *q)
{
    func_02030EAC(((struct Obj10480 *)q)->f5A8); ((struct Obj10480 *)q)->f5A8=0;
    func_021C6664((u8 *)(q+4));
    func_021C6420((u8 *)(q+0x190),((struct Obj10480 *)q)->f1F8);
    func_020315D4(p); func_020306F0(52);
    func_02034A5C((u32)id43); func_02034A5C((u32)id127);
    return 1;
}

void func_021C6354(void *p,char *q) { func_021C665C(q+4); }

void func_021C6360(char *p,int heap) {func_021C658C(p+4,p+0x190,heap); if(!((struct Obj08125 *)p)->f5A8) ((struct Obj08125 *)p)->f5A8=func_020056A0(func_021C6354,p,16);}


/*
 * Addresses are Black-image addresses.
 */
void func_021C6390(u8 *p)
{
    func_02030EAC(((struct Obj08125 *)p)->f5A8);
    *(u32 *)&((struct Obj08125 *)p)->f5A8 = 0;
    func_021C6664(p + 4);
}

void func_021C63AC(void *p,u32 *out,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u32 unused,u8 g)
{
    *out=func_020450F0(a,b,c,d,e,f,1);
    func_02043B5C(func_02045770((struct Descriptor *)*out),g);
    func_02045334((struct Descriptor *)*out);
    func_021CA458(p,out);
}

void func_021C63EC(u8 *p, const u32 *q, int heap) {((struct Obj04503 *)p)->f4=*q;((struct Obj04503 *)p)->f58=func_020457B0(128,heap);((struct Obj04503 *)p)->f5C=func_020457B0(128,heap);((struct Obj04503 *)p)->f0=func_020355C4();p[12]=func_02012FFC();p[13]=0;p[14]=1;}

void func_021C6420(u8 *p, void *a1) { func_020355D8(((struct Obj10482 *)p)->f0); func_02045808(((struct Obj10482 *)p)->f58); func_02045808(((struct Obj10482 *)p)->f5C); }

/*
 * extent: Six code bytes followed by two zero alignment bytes.
 */
void func_021C6438(u8 *p, u8 a, u8 b)
{
    p[9] = a;
    p[10] = b;
}

void func_021C6440(u8 *p,void *a,void *b) { if(a) func_02045838(((struct Obj00227 *)p)->f58,a); if(b) func_02045838(((struct Obj00227 *)p)->f5C,b); }

int func_021C6460(char *p,void *q,u32 arg)
{
    int i;
    void *v;
    u64 old,id;
    int valid,result;
    v=(void *)func_0201283C(((struct Obj23065 *)p)->f4);
    old=func_0205994C((struct DWCstAccUserData *)func_02009860(v));
    for(i=0;i<32;i++) {
        if(func_02009A1C(v,i)==0) {
            id=func_021CA014(q,&valid);
            if(valid==1 && id!=old) {
            if(func_02059354(func_02009860(v),(u32)id,(u32)(id>>32))==0) return 1;
            if(func_0200F43C(v,(u32)id,(u32)(id>>32),&result)==0) return 2;
            func_02059980(func_020099C8(v,i),(u32)id,(u32)(id>>32));
            func_02009A00(v,i,(void *)arg);
            func_02009918(v,i,9,2);
            return 0;
            }
            return 1;
        }
    }
    return 0;
}

void func_021C6514(char *p,int x) { ((struct Obj00298 *)p)->f60=x; ((struct Obj00298 *)p)->f64=1; }

void func_021C651C(char *p,int x) { p[11]=x; }
