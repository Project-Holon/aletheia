/*
 * function: func_021D76F0
 * address: 0x021D76F0
 * packet: pkt_ov123_021D76F0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200E8E0 0x0200E8E0 thumb
 *   func_021D5BA0 0x021D5BA0 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D76B8 0x021D76B8 thumb ov123
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
struct Sub020090B0Obj;
struct Sub02009210Obj;
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern int func_02030734(int,int,int,const char *,u16);
extern int func_020072CC(int,int,u16,int,int);
extern void func_02082D44(const void *,void *,int);
extern void func_0200E8E0(int,int);
extern void func_02012E4C(int,int);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_02009108(struct Sub020090B0Obj *obj, u16 value);
extern void func_021D6EE0(int,int,int);
extern void func_021D6FF0(char *p);
extern void func_021D76B8(char *p);
extern void func_021D758C(int a);
extern const char d_021DAB78[];
void func_021D76F0(int a)
{
    int b;
    u8 *p;
    int x;
    u16 checksum;
    b=func_02012EBC(*(int *)(a+0x2c));
    p=func_021D5BA0(*(int *)(a+8));
    checksum=func_0203F1FC(p,0x6200);
    if(checksum!=*(u16 *)(p+0x6200)) {
        *(int *)(a+0x80)=0xfff0;
        func_021D6EE0(a,(int)func_021D6FF0,0x378);
        return;
    }
    *(u8 *)(a+0xae)=1;
    x=func_02030734(*(u16 *)a,0x6800,0,d_021DAB78,0x37d);
    *(int *)(a+0x3c)=x;
    func_020072CC(b,7,*(u16 *)a,*(int *)(a+0x3c),0x6800);
    func_02082D44(p,*(void **)(a+0x3c),0x6200);
    func_0200E8E0(*(int *)(a+0x3c),1);
    func_02012E4C(*(int *)(a+0x2c),7);
    func_021D6EE0(a,(int)func_021D76B8,0x383);
}
