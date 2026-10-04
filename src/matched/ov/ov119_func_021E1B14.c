/*
 * function: func_021E1B14
 * address: 0x021E1B14
 * packet: pkt_ov119_021E1B14
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: retain the pre-increment byte index and independent old/base locals;
 * splitting old's base assignment and naming the else-side p+0x8c4
 * address settles the early r4/r7 allocation. No signature mutation.
 * symbols:
 *   d_021E7934 0x021E7934 data a4
 *   d_021E7914 0x021E7914 data a4
 *   d_021E794C 0x021E794C data a4
 *   func_02017E1C 0x02017E1C thumb
 *   func_02049B40 0x02049B40 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045770 0x02045770 arm
 *   func_021D8ADC 0x021D8ADC thumb ov119
 *   func_021E1430 0x021E1430 thumb ov119
 *   func_021E1670 0x021E1670 thumb ov119
 *   func_021E15F8 0x021E15F8 thumb ov119
 *   func_021E1778 0x021E1778 thumb ov119
 *   func_021E0E68 0x021E0E68 thumb ov119
 *   func_0204B84C 0x0204B84C arm
 *   func_021E0E4C 0x021E0E4C thumb ov119
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int a,b;} Pair;
extern const Pair d_021E7934,d_021E7914,d_021E794C;
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_020452E8(int);
extern int func_020450F0(u32,u8,u32,u32,u8,u8,u8);
extern void func_0201DD78(u32,u32,u32);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern int func_021D8ADC(char *p);
extern void func_021E1430(void *,void *,int,int,int,int,char *);
extern void func_021E1670(void *,void *,int,int,char *,int,int);
extern void func_021E15F8(void *,void *,int,int,char *);
extern void func_021E1778(int,int,int,int,char *);
extern void func_021E0E68(char *,void *,int,int,int,int,u16,int);
extern void func_0204B84C(void *,u32);
extern void func_021E0E4C(char *p);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(int);
extern void func_02041B6C(u32 bit);
void func_021E1B14(char *p,int i,void *mon)
{
    Pair a=d_021E7934;
    Pair b=d_021E7914;
    Pair c=d_021E794C;
    u32 flag;
    const char *old;
    u32 index;
    char *tmp;
    flag=func_02017E1C(mon,76,0);
    func_02049B40(23,5,0,448,32,*(u16 *)(p+0x5f4));
    old=p;
    old=old+0x5bc;
    index=i*4;
    if(*(const int *)(old+index))func_020452E8(*(const int *)(old+index));
    *(int *)(p+0x5bc+index)=func_020450F0(3,*(int *)((char *)&a+index),1,14,20,14,0);
    func_0201DD78(15,2,0);
    {
        void *window=func_02045770((struct Descriptor *)*(int *)(p+0x5bc+index));
        func_021E1430(mon,window,16,0,flag,func_021D8ADC(p),p);
    }
    if(flag==0) {
        char *items=p+0x5bc;
        void *window=func_02045770((struct Descriptor *)*(int *)(items+index));
        func_021E1670(mon,window,80,0,p,0,func_021D8ADC(p));
        func_0201DD78(15,2,0);
        func_021E15F8(mon,func_02045770((struct Descriptor *)*(int *)(items+index)),16,19,p);
        func_021E1778((int)mon,*(int *)(items+index),16,128,p);
        i++;
        func_021E0E68(p+0x8c4+i*20,mon,*(int *)(p+0x9c4),*(int *)((char *)&b+index)+16,16,0,*(u16 *)(p+0x5f4),*(int *)((char *)&c+index));
        func_0204B84C(*(void **)(p+i*20+0x8d4),1);
    } else {
        tmp=p+0x8c4;
        func_021E0E4C(tmp+(i+1)*20);
    }
    func_02045334((struct Descriptor *)*(const int *)(old+index));
    func_02045374(*(const int *)(old+index));
    func_02041B6C(3);
}
