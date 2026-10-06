/*
 * function: func_021DA0B0
 * address: 0x021DA0B0
 * packet: pkt_ov131_021DA0B0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * semantics: full-word results retained; only explicit u8 call arguments
 * narrow. No signed arithmetic or caller-domain assumptions.
 * prototype: 618C final stack argument is full u32 here: original stores
 * B6D0 result directly at 021DA182, with no u16 truncation; its body reads
 * only low 16 bits at 021D61A6. Narrow extern adds five absent shift pairs.
 * symbols:
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_021D618C 0x021D618C thumb ov131
 *   func_021D62B4 0x021D62B4 thumb ov131
 *   func_021DB6D0 0x021DB6D0 thumb ov131
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj00112.h"
#include "../include/Obj01061.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021D60A4(char *p);
extern u32 func_02017E1C(void *,u32,u32);
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021D618C(u8 *,void *,int,int,s16,u32);
extern void func_021D62B4(unsigned char *p, unsigned int a, void *b, int c, unsigned short d, unsigned short e, unsigned short f);
extern int func_021DB6D0(u32 a, u32 b, unsigned char c, u32 d);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
void func_021DA0B0(u8 *a,u8 *p)
{
    void *data;
    u32 selected;
    int one;
    void *o1,*o2,*o3,*o4,*o5,*o6,*o7;
    u32 value;
    void *t1,*t2,*str;
    data=(void *)func_021D60A4((char *)a);
    selected=func_02017E1C(data,112,0);
    one=1;
    func_021D618C(a,((struct Obj01061 *)p)->f5C,110,25,one,15424);
    o1=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o1,0,func_02017E1C(data,160,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f5C),o1,119,89,one,1088);
    func_0201ED04(o1);
    func_021D618C(a,((struct Obj01061 *)p)->f5C,117,93,one,1088);
    o2=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o2,0,func_02017E1C(data,161,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f5C),o2,118,121,one,1088);
    func_0201ED04(o2);
    func_021D618C(a,((struct Obj01061 *)p)->f64,111,one,one,func_021DB6D0((u32)a,(u32)p,selected,one));
    o3=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o3,0,func_02017E1C(data,162,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f64),o3,120,105,one,1088);
    func_0201ED04(o3);
    func_021D618C(a,((struct Obj01061 *)p)->f68,112,one,one,func_021DB6D0((u32)a,(u32)p,selected,2));
    o4=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o4,0,func_02017E1C(data,163,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f68),o4,121,105,one,1088);
    func_0201ED04(o4);
    func_021D618C(a,((struct Obj01061 *)p)->f6C,113,one,one,func_021DB6D0((u32)a,(u32)p,selected,3));
    o5=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o5,0,func_02017E1C(data,165,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f6C),o5,122,105,one,1088);
    func_0201ED04(o5);
    func_021D618C(a,((struct Obj01061 *)p)->f70,114,one,one,func_021DB6D0((u32)a,(u32)p,selected,4));
    o6=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o6,0,func_02017E1C(data,166,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f70),o6,123,105,one,1088);
    func_0201ED04(o6);
    func_021D618C(a,((struct Obj01061 *)p)->f74,115,one,one,func_021DB6D0((u32)a,(u32)p,selected,5));
    o7=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o7,0,func_02017E1C(data,164,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f74),o7,124,105,one,1088);
    func_0201ED04(o7);
    func_021D618C(a,((struct Obj01061 *)p)->f78,116,5,one,15424);
    value=func_02017E1C(data,10,0);
    t1=func_02045B38(0,2,183,((struct Obj00112 *)a)->f0);
    str=func_02045EC0(t1,value);
    func_0201C724(((struct Obj00112 *)a)->f84,(int)func_02045770(((struct Obj01061 *)p)->f78),5,17,(u32)str,*(int *)&((struct Obj00112 *)a)->f80,1088);
    func_02045808(str);
    func_02045C04(t1);
    t2=func_02045B38(0,2,182,((struct Obj00112 *)a)->f0);
    str=func_02045EC0(t2,value);
    func_0201C724(((struct Obj00112 *)a)->f84,(int)func_02045770(((struct Obj01061 *)p)->f78),65,one,(u32)str,*(int *)&((struct Obj00112 *)a)->f80,1088);
    func_02045808(str);
    func_02045C04(t2);
    ((struct Obj01061 *)p)->f4=one;
}
