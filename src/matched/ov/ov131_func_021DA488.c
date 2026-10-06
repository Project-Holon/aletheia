/*
 * function: func_021DA488
 * address: 0x021DA488
 * packet: pkt_ov131_021DA488
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DA6A2.
 * semantics: C1E8 forwards BD28(a,2); BDB4 case 2 at 0201BE0C
 * returns ldrb, bounding kind to 0..255 and (kind+16)*4 to 1084.
 * AB84 copies all 36 output bytes at 0204AB9C..0204ABB0 before B784
 * reads them. Other scalar arithmetic uses u8 indices or constants.
 * symbols:
 *   func_0201C1E8 0x0201C1E8 thumb
 *   func_02027604 0x02027604 thumb
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D618C 0x021D618C thumb ov131
 *   func_021D6214 0x021D6214 thumb ov131
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0204AB84 0x0204AB84 arm
 *   func_0204B784 0x0204B784 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj01408.h"
#include "../include/Obj04513.h"
#include "../include/Obj23163.h"
#include "../include/Obj23164.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 w[9]; } Record;
extern void *func_021D6064(u8 *);
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Obj;
struct Rec;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void func_021D618C(unsigned char *p, unsigned int a, int b, int c, unsigned short d, unsigned short e);
extern void func_021D6214(unsigned char *p, unsigned int a, void *b, int c, unsigned short d, unsigned short e, unsigned short f);
struct Struct36;
extern int func_0201C1E8(int a);
extern void func_0204AB84(u32 idx, struct Rec *dst);
extern void func_0204B784(char *dst, const struct Struct36 *src);
extern u8 func_02027604(u8);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern u32 func_0201C1D8(u16);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201ED04(struct WordSet *p);
extern u32 func_0201BD28(u16,u32);
extern u32 func_0201C1F4(u16 id);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *,int,s16,s16,void *,int,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045C04(struct Rec *rec);
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
    func_0201C724(((struct Obj04513 *)a)->f84,(int)func_02045770(((struct Obj01408 *)p)->f88),1,1,str,((struct Obj04513 *)a)->f80,1088);
    func_02045808(str);
    func_02045C04(table);
    ((struct Obj01408 *)p)->fC=0;
    ((struct Obj01408 *)p)->f8=1;
}
