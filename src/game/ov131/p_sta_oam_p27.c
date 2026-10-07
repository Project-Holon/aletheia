/*
 * file:     p_sta_oam_p27.c
 * unit:     yes
 * function: func_021DA3FC, func_021DA488, func_021DA6A4
 * address:  0x021DA3FC
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202D034 0x0202D034 thumb
 *   func_0202D01C 0x0202D01C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_02027604 0x02027604 thumb
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D618C 0x021D618C thumb ov131
 *   func_021D6214 0x021D6214 thumb ov131
 *   func_02043B5C 0x02043B5C arm
 *   func_0204AB84 0x0204AB84 arm
 *   func_0204B784 0x0204B784 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   d_021DC2C2 0x021DC2C2 data a1
 *   func_020450F0 0x020450F0 arm
 *   func_02045798 0x02045798 arm
 *   func_02043678 0x02043678 arm
 *   func_021D9EE8 0x021D9EE8 thumb ov131
 *   func_021DB7D4 0x021DB7D4 thumb ov131
 *   func_021D614C 0x021D614C thumb ov131
 *   func_021DBAD0 0x021DBAD0 thumb ov131
 *   func_021DBCA4 0x021DBCA4 thumb ov131
 */
#include "../../matched/include/Obj01061.h"
#include "../../matched/include/Obj01408.h"
#include "../../matched/include/Obj04513.h"
#include "../../matched/include/Obj23163.h"
#include "../../matched/include/Obj23164.h"
#include "../../matched/include/Obj01940.h"
#include "../../matched/include/Obj02846.h"

struct Bmp;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Obj;
struct Rec;
struct U16Vec;
struct WordSet;
struct Struct36;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short s16;

typedef struct { u32 w[9]; } Record;

typedef struct { void *bmp; s16 x,y; void *resource; u32 value; u8 a,b; u16 c; u32 d; } Descriptor;

extern int func_021D60A4(char *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern int func_0202D034(u32 a, u32 b);
extern u8 func_0202D01C(u32 a, u32 b, u32 c);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void *func_021D6064(u8 *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void func_021D618C(unsigned char *p, unsigned int a, int b, int c, unsigned short d, unsigned short e);
extern void func_021D6214(unsigned char *p, unsigned int a, void *b, int c, unsigned short d, unsigned short e, unsigned short f);
extern int func_0201C1E8(int a);
extern void func_0204AB84(u32 idx, struct Rec *dst);
extern void func_0204B784(char *dst, const struct Struct36 *src);
extern u8 func_02027604(u8);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern u32 func_0201C1D8(u16);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201BD28(u16,u32);
extern u32 func_0201C1F4(u16 id);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045798(struct Descriptor *p, u8 v);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_021D9EE8(u8 *,u8 *);
extern void func_021DB7D4(u8 *p, u8 *q, u8 *entry);
extern void func_021D614C(u8 *,int,int,int,s16,u16);
extern u8 *func_021DBAD0(u8 *a, const u8 *b);
extern void func_021DBCA4(u8 *,int);
void func_021DA3FC(u8 *a,u8 *b);
void func_021DA488(u8 *a,u8 *p);
void func_021DA6A4(u8 *a,u8 *p);
extern const u8 d_021DC2C2[];

void func_021DA3FC(u8 *a,u8 *b) {
    void *p,*bmp;
    u16 x,y;
    int kind,value,first,last;
    p=(void *)func_021D60A4((char *)a);
    x=func_02017E1C(p,161,0);
    y=func_02017E1C(p,160,0);
    kind=func_0202D034(y,x);
    value=func_0202D01C(y,x,48);
    bmp=func_02045770(((struct Obj01061 *)b)->f60);
    if((u8)(kind+254)<=1) {first=7;last=8;}
    else if(kind==1) {first=9;last=10;}
    else {first=5;last=6;}
    func_02043AF4(bmp,0,3,value,1,first);
    func_02043AF4(bmp,0,4,value,1,last);
}

/*
 * extent: two-byte zero alignment padding at 0x021DA6A2.
 * semantics: C1E8 forwards BD28(a,2); BDB4 case 2 at 0201BE0C
 * returns ldrb, bounding kind to 0..255 and (kind+16)*4 to 1084.
 * AB84 copies all 36 output bytes at 0204AB9C..0204ABB0 before B784
 * reads them. Other scalar arithmetic uses u8 indices or constants.
 */
void func_021DA488(u8 *a,u8 *p)
{
    void *data,*object1,*object2,*table,*str;
    u8 i;
    int zero,one,id,kind;
    u32 count,value;
    Record record;
    data=func_021D6064(a);
    zero=0;
    for(i=8;i<=11;i++) func_02043B5C(func_02045770(*(void **)(p+0x5c+i*4)),zero);
    if(p[41]<4) id=func_02017E88(data,p[41]+54,zero);
    else if(p[41]==255) {
        if((*(u8 **)(a+8))[13]==2 && p[43]==5) id=((struct Obj23163 *)(*(u8 * *)&((struct Obj04513 *)a)->f8))->f14;
        else id=func_02017E88(data,54,0);
    } else id=((struct Obj23164 *)(*(u8 * *)&((struct Obj04513 *)a)->f8))->f14;
    one=1;
    func_021D618C(a,(unsigned int)(((struct Obj01408 *)p)->f7C),149,1,one,15424);
    kind=func_0201C1E8((u16)id);
    func_0204AB84(*(u32 *)(a+(kind+16)*4+152),(struct Rec *)(&record));
    func_0204B784(((struct Obj01408 *)p)->f94,(const struct Struct36 *)(&record));
    func_0204B6F4(((struct Obj01408 *)p)->f94,func_02027604(kind),1);
    func_021D618C(a,(unsigned int)(((struct Obj01408 *)p)->f80),147,1,one,15424);
    count=func_0201C1D8(id);
    if(count<=1) func_021D618C(a,(unsigned int)(((struct Obj01408 *)p)->f80),154,87,one,1088);
    else {
        object1=func_0201EC64(((struct Obj04513 *)a)->f0);
        func_0201EFA4(object1,0,count,3,one,one);
        func_021D6214(a,(unsigned int)(((struct Obj01408 *)p)->f80),object1,150,81,one,1088);
        func_0201ED04(object1);
    }
    func_021D618C(a,(unsigned int)(((struct Obj01408 *)p)->f84),148,1,1,15424);
    value=func_0201BD28(id,4);
    if(func_0201C1F4(id)==1 || value==0) func_021D618C(a,(unsigned int)(((struct Obj01408 *)p)->f84),154,87,1,1088);
    else {
        object2=func_0201EC64(((struct Obj04513 *)a)->f0);
        func_0201EFA4(object2,0,value,3,1,1);
        func_021D6214(a,(unsigned int)(((struct Obj01408 *)p)->f84),object2,151,81,1,1088);
        func_0201ED04(object2);
    }
    table=func_02045B38(0,2,202,((struct Obj04513 *)a)->f0);
    str=func_02045EC0(table,id);
    func_0201C724(((struct Obj04513 *)a)->f84,(int)func_02045770(((struct Obj01408 *)p)->f88),1,1,(u32)str,((struct Obj04513 *)a)->f80,1088);
    func_02045808(str);
    func_02045C04(table);
    ((struct Obj01408 *)p)->fC=0;
    ((struct Obj01408 *)p)->f8=1;
}

/*
 * semantics: u8 loop indices bound multiplication to 255*24; no signed
 * overflow. Descriptor fields are initialized before the call. BAD0 reads
 * offsets 0,4,6,8,12,16,17,18,20; trailing padding is never read.
 */
void func_021DA6A4(u8 *a,u8 *p)
{
    u8 i;
    Descriptor desc;
    for(i=0;i<13;i++) {
        *(void **)(p+0x5c+i*4)=(void *)func_020450F0(4,d_021DC2C2[i*4],d_021DC2C2[i*4+1],d_021DC2C2[i*4+2],d_021DC2C2[i*4+3],14,1);
    }
    func_02045798(((struct Obj01940 *)p)->f60,13);
    func_021D9EE8(a,p);
    for(i=0;i<p[43];i++) func_021DB7D4(a,p,p+0xb0+i*24);
    if(p[43]==5) {
        ((struct Obj01940 *)p)->fA8=func_02043678(11,4,32,((struct Obj02846 *)a)->f0);
        func_021D614C(a,*(int *)&((struct Obj01940 *)p)->fA8,193,5,9,1088);
        desc.x=32;
        desc.y=160;
        desc.resource=((struct Obj02846 *)a)->fB8;
        desc.value=0;
        desc.a=0;
        desc.b=0;
        desc.c=0;
        desc.d=0;
        desc.bmp=((struct Obj01940 *)p)->fA8;
        *(u8 * *)&((struct Obj01940 *)p)->fAC=func_021DBAD0(((struct Obj01940 *)p)->fA4,(const u8 *)(&desc));
        func_021DBCA4(*(u8 * *)&((struct Obj01940 *)p)->fAC,0);
    }
    p[41]=255;
    ((struct Obj01940 *)p)->f0=1;
    ((struct Obj01940 *)p)->f20=0;
    p[40]=0;
}
