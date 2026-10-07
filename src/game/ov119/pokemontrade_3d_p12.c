/*
 * file:     pokemontrade_3d_p12.c
 * unit:     yes
 * function: func_021E3A40, func_021E3B2C
 * address:  0x021E3A40
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
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
 *   func_020490F4 0x020490F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_020862F0 0x020862F0 arm
 *   func_02083194 0x02083194 arm
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 */
#include "../../matched/include/Obj22794.h"
#include "../../matched/include/Obj10376.h"
#include "../../matched/include/Obj22795.h"
#include "../../matched/include/Obj22796.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned long u32_021E3A40;

typedef long fx32;

typedef struct { fx32 x,y,z; } VecFx32;

typedef struct { fx32 a[12]; } MtxFx43;

typedef unsigned int   u32_021E3B2C;

extern void func_0207DA8C(void);
extern void func_0207D7C4(const VecFx32 *,const VecFx32 *,const VecFx32 *,int,MtxFx43 *);
extern u8 func_021D8A18(u8 *);
extern void func_021E3910(int,int,u16,int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_02049F78(void *a0, u32_021E3B2C a1, u32_021E3B2C a2, u32_021E3B2C a3);
extern void func_020862F0(void *, int);
extern void func_02083194(const void *, void *, int);
extern void func_0207FA0C(void);
extern void func_0207FA40(const void *, int, int);
extern void func_0207FADC(void);
extern void func_02082D44(const void *, void *, int);
extern u32_021E3B2C func_020307B0(void *p);
extern void func_02049238(void *);
void func_021E3A40(const u8 *p);
void func_021E3B2C(char *p);
extern const VecFx32 d_021E815C,d_021E79AC,d_021E8150;
extern u32_021E3A40 d_021E8144[];

static inline fx32 fraction(int x,int y) { return (fx32)(((long long)x*65536)/y); }

/*
 * lever: separate x+=48 and remainder assignments restore numerator register setup.
 * volatile: hardware writes 021E3A5C,021E3A60 to 040004C8/040004CC
 */
void func_021E3A40(const u8 *p)
{
    int i,stage,count,total,base;
    int x;
    unsigned delta;
    u16 angle;
    func_0207DA8C();
    func_0207D7C4(&d_021E815C,&d_021E79AC,&d_021E8150,1,0);
    *(volatile u32_021E3A40 *)0x040004c8=0x2d8b6127;
    *(volatile u32_021E3A40 *)0x040004cc=0x7fff;
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

void func_021E3B2C(char *p)
{
    void *v;
    void *allocation;
    void *descriptor;
    char *data;
    v = func_020490F4(0x74, ((struct Obj10376 *)p)->f5F4);
    allocation = func_02049F78(v, 0x48, (u32_021E3B2C)(&descriptor), ((struct Obj10376 *)p)->f5F4);
    data = *(char * *)&((struct Obj22795 *)descriptor)->fC;
    func_020862F0(data + 32, 32);
    func_02083194(data + 32, data + 34, 30);
    ((struct Obj22796 *)data)->f20 = 0x14A5;
    func_020862F0(data + 32, 32);
    func_0207FA0C();
    func_0207FA40(data + 32, 0x2000, 32);
    func_0207FADC();
    func_02082D44(data + 32, p + 0x1134, 32);
    func_020307B0(allocation);
    func_02049238(v);
}
