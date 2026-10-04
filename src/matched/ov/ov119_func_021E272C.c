/*
 * function: func_021E272C
 * address: 0x021E272C
 * packet: pkt_ov119_021E272C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: each final handle index is recomputed through a 32-bit long local;
 * an int copy CSEs the shift and shortens the function by four bytes.
 * symbols:
 *   d_021E7924 0x021E7924 data a4
 *   d_021E791C 0x021E791C data a4
 *   d_021E7974 0x021E7974 data a4
 *   d_021E790C 0x021E790C data a4
 *   func_02017E1C 0x02017E1C thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_021D8ADC 0x021D8ADC thumb ov119
 *   func_021E1430 0x021E1430 thumb ov119
 *   func_021E1670 0x021E1670 thumb ov119
 *   func_021E15F8 0x021E15F8 thumb ov119
 *   func_021E1778 0x021E1778 thumb ov119
 *   func_021E0E68 0x021E0E68 thumb ov119
 *   func_021E1CA8 0x021E1CA8 thumb ov119
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int a,b;} Pair;
typedef struct {u32 a,b,c,d;} Quad;
extern const Pair d_021E7924,d_021E791C,d_021E790C;
extern const Quad d_021E7974;
extern u32 func_02017E1C(void *,u32,u32);
extern void func_020452E8(int);
extern int func_020450F0(u32,u8,u32,u32,u8,u8,u8);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32,u32,u32);
extern int func_021D8ADC(char *p);
extern void func_021E1430(void *,void *,int,int,int,int,char *);
extern void func_021E1670(void *,void *,int,int,char *,int,int);
extern void func_021E15F8(void *,void *,int,int,char *);
extern void func_021E1778(int,int,int,int,char *);
extern void func_021E0E68(char *,void *,int,int,int,int,u16,int);
extern void func_021E1CA8(char *p);
extern void func_02045334(int);
extern void func_02045374(int);
extern void func_02041B6C(u32 bit);
void func_021E272C(char *p,int i,void *mon)
{
    Pair a=d_021E7924;
    Pair b=d_021E791C;
    Quad colors=d_021E7974;
    Pair c=d_021E790C;
    u32 flag;
    int layer,idx2;
    u32 col,col2;
    int index;
    char *items,*items2;
    flag=func_02017E1C(mon,76,0);
    index=i*4;
    if(*(int *)(p+i*4+0x5c4)) {
        func_020452E8(*(int *)(p+i*4+0x5c4));
        func_020452E8(*(int *)(p+i*4+0x5cc));
    }
    layer=*(int *)((char *)&a+index);
    items=p+0x5c4;
    *(int *)(items+index)=func_020450F0(1,layer,0,14,5,5,0);
    items2=p+0x5cc;
    *(int *)(items2+index)=func_020450F0(1,layer,17,13,2,5,0);
    idx2=i*2;
    col=((u32 *)&colors)[idx2];
    func_02043B5C(func_02045770((struct Descriptor *)*(int *)(items+index)),(u8)(col|(col<<4)));
    col2=((u32 *)&colors)[idx2+1];
    func_02043B5C(func_02045770((struct Descriptor *)*(int *)(items2+index)),(u8)(col2|(col2<<4)));
    func_0201DD78(1,2,(u8)col);
    {
        void *window=func_02045770((struct Descriptor *)*(int *)(items+index));
        func_021E1430(mon,window,16,4,flag,func_021D8ADC(p),p);
    }
    if(flag==0) {
        char *first=p+0x5c4;
        void *window=func_02045770((struct Descriptor *)*(int *)(first+index));
        func_021E1670(mon,window,80,4,p,1,func_021D8ADC(p));
        func_021E15F8(mon,func_02045770((struct Descriptor *)*(int *)(first+index)),16,19,p);
        func_0201DD78(1,2,(u8)col2);
        func_021E1778((int)mon,*(int *)(items2+index),0,0,p);
        func_021E0E68(p+0x8c4+(i+1)*20,mon,*(int *)(p+0x9c4),*(int *)((char *)&b+index)+16,16,0,*(u16 *)(p+0x5f4),*(int *)((char *)&c+index));
    } else func_021E1CA8(p);
    {
        char *first=p+0x5c4;
        char *second=p+0x5cc;
        long endindex=(long)i*4;
        func_02045334(*(int *)(first+endindex));
        func_02045334(*(int *)(second+endindex));
        func_02045374(*(int *)(first+endindex));
        func_02045374(*(int *)(second+endindex));
    }
    func_02041B6C(1);
    *(u8 *)(p+i+0x11e2)=120;
}
