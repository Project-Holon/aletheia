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
#include "../include/Obj02475.h"
#include "../include/Obj22960.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Big;
extern void *func_02012EBC(struct Big *p);
extern int func_021D5BA0(char *p);
typedef unsigned int   u32;
struct Sub020090B0Obj;
struct Sub02009210Obj;
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int func_020072CC(int,int,u16,int,int);
extern void func_02082D44(const void *,void *,int);
extern void func_0200E8E0(int,int);
extern void func_02012E4C(u8 *,u32);
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
    b=(int)func_02012EBC((struct Big *)(((struct Obj02475 *)a)->f2C));
    p=(u8 *)func_021D5BA0((char *)(((struct Obj02475 *)a)->f8));
    checksum=func_0203F1FC(p,0x6200);
    if(checksum!=((struct Obj22960 *)p)->f6200) {
        ((struct Obj02475 *)a)->f80=0xfff0;
        func_021D6EE0(a,(int)func_021D6FF0,0x378);
        return;
    }
    ((struct Obj02475 *)a)->fAE=1;
    x=(int)func_02030734(((struct Obj02475 *)a)->f0,0x6800,0,d_021DAB78,0x37d);
    *(int *)&((struct Obj02475 *)a)->f3C=x;
    func_020072CC(b,7,((struct Obj02475 *)a)->f0,*(int *)&((struct Obj02475 *)a)->f3C,0x6800);
    func_02082D44(p,((struct Obj02475 *)a)->f3C,0x6200);
    func_0200E8E0(*(int *)&((struct Obj02475 *)a)->f3C,1);
    func_02012E4C((u8 *)((struct Obj02475 *)a)->f2C,7);
    func_021D6EE0(a,(int)func_021D76B8,0x383);
}
