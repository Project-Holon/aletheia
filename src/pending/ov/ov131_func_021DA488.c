/*
 * function: func_021DA488
 * address: 0x021DA488
 * packet: pkt_ov131_021DA488
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: ARM9 0x02027604 Thumb byte-table accessor has no witness
 * outside 021DA488..021DA6A2; owner evidence only, no blocker C.
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
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 w[9]; } Record;
extern void *func_021D6064(u8 *);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u32);
extern int func_02017E88(void *,int,int);
extern void func_021D618C(u8 *,void *,int,int,s16,u32);
extern void func_021D6214(u8 *,void *,void *,int,u16,s16,u16);
extern int func_0201C1E8(u16);
extern void func_0204AB84(u32,Record *);
extern void func_0204B784(void *,const Record *);
extern u8 func_02027604(u8);
extern void func_0204B6F4(void *,u8,u32);
extern u32 func_0201C1D8(u16);
extern void *func_0201EC64(u32);
extern void func_0201EFA4(void *,u32,u32,u32,u32,u32);
extern void func_0201ED04(void *);
extern u32 func_0201BD28(u16,u32);
extern int func_0201C1F4(u16);
extern void *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(void *,u32);
extern void func_0201C724(void *,int,s16,s16,void *,int,u16);
extern void func_02045808(void *);
extern void func_02045C04(void *);
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
        if((*(u8 **)(a+8))[13]==2 && p[43]==5) id=*(u16 *)(*(u8 **)(a+8)+20);
        else id=func_02017E88(data,54,0);
    } else id=*(u16 *)(*(u8 **)(a+8)+20);
    one=1;
    func_021D618C(a,*(void **)(p+124),149,1,one,15424);
    kind=func_0201C1E8(id);
    func_0204AB84(*(u32 *)(a+(kind+16)*4+152),&record);
    func_0204B784(*(void **)(p+148),&record);
    func_0204B6F4(*(void **)(p+148),func_02027604(kind),1);
    func_021D618C(a,*(void **)(p+128),147,1,one,15424);
    count=func_0201C1D8(id);
    if(count<=1) func_021D618C(a,*(void **)(p+128),154,87,one,1088);
    else {
        object1=func_0201EC64(*(u16 *)a);
        func_0201EFA4(object1,0,count,3,one,one);
        func_021D6214(a,*(void **)(p+128),object1,150,81,one,1088);
        func_0201ED04(object1);
    }
    func_021D618C(a,*(void **)(p+132),148,1,1,15424);
    value=func_0201BD28(id,4);
    if(func_0201C1F4(id)==1 || value==0) func_021D618C(a,*(void **)(p+132),154,87,1,1088);
    else {
        object2=func_0201EC64(*(u16 *)a);
        func_0201EFA4(object2,0,value,3,1,1);
        func_021D6214(a,*(void **)(p+132),object2,151,81,1,1088);
        func_0201ED04(object2);
    }
    table=func_02045B38(0,2,202,*(u16 *)a);
    str=func_02045EC0(table,id);
    func_0201C724(*(void **)(a+132),(int)func_02045770(*(void **)(p+136)),1,1,str,*(int *)(a+128),1088);
    func_02045808(str);
    func_02045C04(table);
    *(int *)(p+12)=0;
    *(int *)(p+8)=1;
}
