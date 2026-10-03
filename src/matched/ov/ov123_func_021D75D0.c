/*
 * function: func_021D75D0
 * address: 0x021D75D0
 * packet: pkt_ov123_021D75D0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5BA0 0x021D5BA0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D758C 0x021D758C thumb ov123
 *   func_0203F1FC 0x0203F1FC arm
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02009108 0x02009108 thumb
 *   d_021DAB78 0x021DAB78 data ov123 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02012EBC(int);
extern u8 *func_021D5BA0(int);
typedef unsigned int   u32;
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern int func_02030734(int,int,int,const char *,u16);
extern int func_020072CC(int,int,u16,int,int);
extern void func_02082D44(const void *,void *,int);
extern void func_0200E8E0(void *obj, u32 value);
extern void func_02012E4C(int,int);
extern int func_02009210(int);
extern void func_02009108(int,u16);
extern void func_021D6EE0(int,int,int);
extern void func_021D6FF0(char *p);
extern void func_021D76B8(char *p);
extern void func_021D758C(int a);
extern const char d_021DAB78[];
void func_021D75D0(int a)
{
    u16 checksum;
    int b;
    u8 *p;
    int x;
    b=func_02012EBC(*(int *)(a+0x2c));
    p=func_021D5BA0(*(int *)(a+8));
    checksum=func_0203F1FC(p,0x2600);
    if(checksum!=*(u16 *)(p+0x2600)) {
        *(int *)(a+0x80)=0xfff0;
        func_021D6EE0(a,(int)func_021D6FF0,0x345);
        return;
    }
    *(u8 *)(a+0xae)=1;
    x=func_02030734(*(u16 *)a,0x3000,0,d_021DAB78,0x34a);
    *(int *)(a+0x40)=x;
    func_020072CC(b,4,*(u16 *)a,x,0x3000);
    func_02082D44(p,(void *)x,0x2600);
    func_02009108(func_02009210(b),checksum);
    func_02012E4C(*(int *)(a+0x2c),4);
    func_021D6EE0(a,(int)func_021D758C,0x355);
}
