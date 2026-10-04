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
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_021D60A4(u8 *);
extern u32 func_02017E1C(void *,u32,u32);
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201ED04(struct WordSet *p);
extern void func_021D618C(u8 *,void *,int,int,s16,u32);
extern void func_021D62B4(unsigned char *p, unsigned int a, void *b, int c, unsigned short d, unsigned short e, unsigned short f);
extern u32 func_021DB6D0(u8 *,u8 *,u8,int);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *,int,s16,s16,void *,int,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045C04(struct Rec *rec);
void func_021DA0B0(u8 *a,u8 *p)
{
    void *data;
    u32 selected;
    int one;
    void *o1,*o2,*o3,*o4,*o5,*o6,*o7;
    u32 value;
    void *t1,*t2,*str;
    data=func_021D60A4(a);
    selected=func_02017E1C(data,112,0);
    one=1;
    func_021D618C(a,*(void **)(p+92),110,25,one,15424);
    o1=func_0201EC64(*(u16 *)a);
    func_0201EFA4(o1,0,func_02017E1C(data,160,0),3,one,one);
    func_021D62B4(a,(unsigned int)(*(void **)(p+92)),o1,119,89,one,1088);
    func_0201ED04(o1);
    func_021D618C(a,*(void **)(p+92),117,93,one,1088);
    o2=func_0201EC64(*(u16 *)a);
    func_0201EFA4(o2,0,func_02017E1C(data,161,0),3,one,one);
    func_021D62B4(a,(unsigned int)(*(void **)(p+92)),o2,118,121,one,1088);
    func_0201ED04(o2);
    func_021D618C(a,*(void **)(p+100),111,one,one,func_021DB6D0(a,p,selected,one));
    o3=func_0201EC64(*(u16 *)a);
    func_0201EFA4(o3,0,func_02017E1C(data,162,0),3,one,one);
    func_021D62B4(a,(unsigned int)(*(void **)(p+100)),o3,120,105,one,1088);
    func_0201ED04(o3);
    func_021D618C(a,*(void **)(p+104),112,one,one,func_021DB6D0(a,p,selected,2));
    o4=func_0201EC64(*(u16 *)a);
    func_0201EFA4(o4,0,func_02017E1C(data,163,0),3,one,one);
    func_021D62B4(a,(unsigned int)(*(void **)(p+104)),o4,121,105,one,1088);
    func_0201ED04(o4);
    func_021D618C(a,*(void **)(p+108),113,one,one,func_021DB6D0(a,p,selected,3));
    o5=func_0201EC64(*(u16 *)a);
    func_0201EFA4(o5,0,func_02017E1C(data,165,0),3,one,one);
    func_021D62B4(a,(unsigned int)(*(void **)(p+108)),o5,122,105,one,1088);
    func_0201ED04(o5);
    func_021D618C(a,*(void **)(p+112),114,one,one,func_021DB6D0(a,p,selected,4));
    o6=func_0201EC64(*(u16 *)a);
    func_0201EFA4(o6,0,func_02017E1C(data,166,0),3,one,one);
    func_021D62B4(a,(unsigned int)(*(void **)(p+112)),o6,123,105,one,1088);
    func_0201ED04(o6);
    func_021D618C(a,*(void **)(p+116),115,one,one,func_021DB6D0(a,p,selected,5));
    o7=func_0201EC64(*(u16 *)a);
    func_0201EFA4(o7,0,func_02017E1C(data,164,0),3,one,one);
    func_021D62B4(a,(unsigned int)(*(void **)(p+116)),o7,124,105,one,1088);
    func_0201ED04(o7);
    func_021D618C(a,*(void **)(p+120),116,5,one,15424);
    value=func_02017E1C(data,10,0);
    t1=func_02045B38(0,2,183,*(u16 *)a);
    str=func_02045EC0(t1,value);
    func_0201C724(*(void **)(a+132),(int)func_02045770(*(void **)(p+120)),5,17,str,*(int *)(a+128),1088);
    func_02045808(str);
    func_02045C04(t1);
    t2=func_02045B38(0,2,182,*(u16 *)a);
    str=func_02045EC0(t2,value);
    func_0201C724(*(void **)(a+132),(int)func_02045770(*(void **)(p+120)),65,one,str,*(int *)(a+128),1088);
    func_02045808(str);
    func_02045C04(t2);
    *(int *)(p+4)=one;
}
