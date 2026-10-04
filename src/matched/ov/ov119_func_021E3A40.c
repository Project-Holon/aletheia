/*
 * function: func_021E3A40
 * address: 0x021E3A40
 * packet: pkt_ov119_021E3A40
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: separate x+=48 and remainder assignments restore numerator register setup.
 * volatile: hardware writes 021E3A5C,021E3A60 to 040004C8/040004CC
 * symbols:
 *   func_0207DA8C 0x0207DA8C arm
 *   func_0207D7C4 0x0207D7C4 arm
 *   func_021D8A18 0x021D8A18 thumb ov119
 *   func_021E3910 0x021E3910 thumb ov119
 *   _u32_div_f 0x0209C2B0 arm
 *   _ll_sdiv 0x0209C00C arm
 *   d_021E815C 0x021E815C data ov119 a4
 *   d_021E79AC 0x021E79AC data ov119 a4
 *   d_021E8150 0x021E8150 data ov119 a4
 *   d_021E8144 0x021E8144 data ov119 a4
 */
#include "../include/Obj22794.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;
typedef long fx32;
typedef struct { fx32 x,y,z; } VecFx32;
typedef struct { fx32 a[12]; } MtxFx43;
extern void func_0207DA8C(void);
extern void func_0207D7C4(const VecFx32 *,const VecFx32 *,const VecFx32 *,int,MtxFx43 *);
extern u8 func_021D8A18(u8 *);
extern void func_021E3910(int,int,u16,int);
extern const VecFx32 d_021E815C,d_021E79AC,d_021E8150;
extern u32 d_021E8144[];
static inline fx32 fraction(int x,int y) { return (fx32)(((long long)x*65536)/y); }
void func_021E3A40(const u8 *p)
{
    int i,stage,count,total,base;
    int x;
    unsigned delta;
    u16 angle;
    func_0207DA8C();
    func_0207D7C4(&d_021E815C,&d_021E79AC,&d_021E8150,1,0);
    *(volatile u32 *)0x040004c8=0x2d8b6127;
    *(volatile u32 *)0x040004cc=0x7fff;
    stage=func_021D8A18((u8 *)p);
    count=stage+1;
    total=count*160;
    x=((struct Obj22794 *)p)->f107E;
    if(x<96) {
        if(x<48) x=x*112/48;
        else x=x+64;
    } else x=x+64;
    base=stage*160;
    if(x>base) {
        delta=x-base;
        if(delta<80) x=base+delta*112U/80U;
        else x=base+(delta-80U)*48U/80U+112;
    }
    x=x+48;
    x=x%total;
    x=fraction(x,total);
    for(i=0;i<count;i++) {
        angle=0x10000-x;
        func_021E3910(d_021E8144[2],i,(u16)((i<<16)/count),angle);
    }
}
