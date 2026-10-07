/*
 * file:     p_sta_oam_p12.c
 * unit:     yes
 * function: func_021D6F54, func_021D703C, func_021D7060, func_021D708C, func_021D7248, func_021D72E8
 * address:  0x021D6F54
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02015E4C 0x02015E4C thumb
 *   d_021DC1D4 0x021DC1D4 data a4
 *   d_020A1B38 0x020A1B38 data a2
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021D79A8 0x021D79A8 thumb ov131
 *   func_02015C48 0x02015C48 thumb
 *   func_02015C78 0x02015C78 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02015E04 0x02015E04 thumb
 */
#include "../../matched/include/Obj01740.h"
#include "../../matched/include/Obj05387.h"
#include "../../matched/include/Obj10509.h"
#include "../../matched/include/Obj02188.h"
#include "../../matched/include/Obj14068.h"
#include "../../matched/include/Obj05388.h"
#include "../../matched/include/Obj23139.h"
#include "../../matched/include/Obj00831.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {int x,y,z;} Vec;

typedef signed short s16;

extern void func_02015E4C(void *);
extern void func_021D79A8(void *p, unsigned char *q, int radius);
extern void func_02015C48(void *,u32 *);
extern void func_02015C78(void *p, u32 *src);
extern int _ffix(float);
extern void func_02015E04(void *);
void func_021D6F54(u8 *p,u8 *q);
void func_021D703C(void *unused,u8 *q);
int func_021D7060(void *unused,u8 *q,u8 *counter);
int func_021D708C(u8 *p,u8 *q);
int func_021D7248(unsigned char *p,unsigned char *q);
int func_021D72E8(u8 *p,u8 *q,int mode);
extern const Vec d_021DC1D4;
extern const short d_020A1B38[];

/*
 * follower: 021D703C complete reset helper is included; 021D7060 is filed
 *   separately. Reset contains constant stores only, preserving order.
 * semantic: unsigned full-word state dispatch guarded at six by the
 *   original; byte counters compared directly. No signed arithmetic.
 */
void func_021D6F54(u8 *p,u8 *q)
{
    switch(((struct Obj01740 *)q)->f5C) {
    case 0:
        if(q[0x78]>10) {((struct Obj01740 *)q)->f5C=1;func_021D703C(p,q);}
        if(q[0x80]>10) {((struct Obj01740 *)q)->f5C=2;func_021D703C(p,q);}
        if(q[0x88]>20) {((struct Obj01740 *)q)->f5C=3;func_021D703C(p,q);}
        break;
    case 1:
        func_021D708C(p,q);
        if(func_021D7060(p,q,q+0x78)==0) ((struct Obj01740 *)q)->f5C=4;
        break;
    case 4:
        if(func_021D708C(p,q)==1) ((struct Obj01740 *)q)->f5C=0;
        break;
    case 2:
        func_021D7248(p,q);
        if(func_021D7060(p,q,q+0x80)==0) ((struct Obj01740 *)q)->f5C=5;
        break;
    case 5:
        if(func_021D7248(p,q)==1) ((struct Obj01740 *)q)->f5C=0;
        break;
    case 3:
        func_021D72E8(p,q,1);
        if(func_021D7060(p,q,q+0x88)==0) ((struct Obj01740 *)q)->f5C=6;
        break;
    case 6:
        if(func_021D72E8(p,q,0)==1) {
            func_02015E4C(((struct Obj01740 *)q)->f0);
            ((struct Obj01740 *)q)->f5C=0;
        }
        break;
    }
}

void func_021D703C(void *unused,u8 *q)
{
    ((struct Obj05387 *)q)->f58=1;
    ((struct Obj05387 *)q)->f64=0;
    ((struct Obj05387 *)q)->f68=0;
    ((struct Obj05387 *)q)->f62=0;
    ((struct Obj05387 *)q)->f66=0;
    ((struct Obj05387 *)q)->f60=0;
}

int func_021D7060(void *unused,u8 *q,u8 *counter)
{
    if(*counter<10) {
        ++((struct Obj10509 *)q)->f60;
        if(((struct Obj10509 *)q)->f60>24) return 0;
    } else ((struct Obj10509 *)q)->f60=0;
    return 1;
}

/*
 * semantic: phase u16<<15 <=2147450880; dividing by 15 then truncating
 *   to u16 leaves a full index <=8190. Speed is explicitly a low byte;
 *   phase*speed <=16711425, division by 15 fits signed int. Signed sample
 *   times 16 fits int. All later shifts and vector additions/subtractions
 *   use u32 wrap, converted to the compiler's signed word for _fflt.
 *   _ffix is called explicitly: the original unsigned speed shift can
 *   convert to float outside int range; no C float-to-int cast is assumed.
 *   The template initializes every base word; zero initializes v.
 */
int func_021D708C(u8 *p,u8 *q)
{
    Vec base=d_021DC1D4;
    Vec v={0,0,0};
    int radius=0;
    int sample,t;
    u32 n;
    u8 speed;
    float f;
    if(((struct Obj02188 *)q)->f10==0) {
        sample=d_020A1B38[((u16)((((struct Obj02188 *)q)->f62<<15)/15)>>4)*2];
        n=((struct Obj14068 *)p)->f3C>>6;
        if(n) f=0.5f+(float)(n<<12);
        else f=(float)(n<<12)-0.5f;
        radius=(u32)(sample*16)+(u32)_ffix(f);
        v.y=radius;
        func_021D79A8(p,q,radius);
    } else {
        v.y=radius;
        func_021D79A8(p,q,radius);
    }
    speed=(u8)((((struct Obj14068 *)p)->f3C>>6)+16);
    t=(((struct Obj02188 *)q)->f62*speed)/15;
    switch(((struct Obj02188 *)q)->f64) {
    case 0:
        if(t>0) f=0.5f+(float)(int)((u32)t<<12);
        else f=(float)(int)((u32)t<<12)-0.5f;
        base.x+=(u32)_ffix(f);
        break;
    case 1:
        t=speed-t;
        if(t>0) f=0.5f+(float)(int)((u32)t<<12);
        else f=(float)(int)((u32)t<<12)-0.5f;
        base.x+=(u32)_ffix(f);
        break;
    case 2:
        if(t>0) f=0.5f+(float)(int)((u32)t<<12);
        else f=(float)(int)((u32)t<<12)-0.5f;
        base.x-=(u32)_ffix(f);
        break;
    case 3:
        t=speed-t;
        if(t>0) f=0.5f+(float)(int)((u32)t<<12);
        else f=(float)(int)((u32)t<<12)-0.5f;
        base.x-=(u32)_ffix(f);
        break;
    }
    func_02015C48(((struct Obj02188 *)q)->f0,(u32 *)&base.x);
    func_02015C78(((struct Obj02188 *)q)->f0,(u32 *)(&v));
    ++((struct Obj02188 *)q)->f62;
    if(((struct Obj02188 *)q)->f62>15) {
        ((struct Obj02188 *)q)->f62=0;
        ++((struct Obj02188 *)q)->f64;
        if(((struct Obj02188 *)q)->f64>3) {((struct Obj02188 *)q)->f64=0;return 1;}
    }
    return 0;
}

int func_021D7248(unsigned char *p,unsigned char *q) {
 Vec v={0,0,0};
 int s;
 unsigned n;
 float f;
 if(((struct Obj05388 *)q)->f10==0) {
 s=d_020A1B38[((unsigned short)((((struct Obj05388 *)q)->f62<<15)/20)>>4)*2];
 n=((struct Obj23139 *)p)->f3C>>6;
 if(n) f=0.5f+(float)(n<<12); else f=(float)(n<<12)-0.5f;
 v.y=(s<<5)+(int)f;
 func_021D79A8(p,q,v.y);
 }
 func_02015C78(((struct Obj05388 *)q)->f0,(u32 *)(&v));
 ++((struct Obj05388 *)q)->f62;
 if(((struct Obj05388 *)q)->f62>20) {((struct Obj05388 *)q)->f62=0;return 1;}
 return 0;
}

int func_021D72E8(u8 *p,u8 *q,int mode)
{
    Vec v={0,0,0};
    u32 sum;
    u8 i;
    u16 delta;
    int height;
    float f;
    if(((struct Obj00831 *)q)->f10==1) return 1;
    if(mode==1) {
        sum=0;
        for(i=0;i<5;i++) sum+=q[0x94+i];
        sum/=5U;
        if(sum<10) sum=10;
        if(sum>20) sum=20;
        delta=20-sum;
        ((struct Obj00831 *)q)->f68=2048+(6144*delta)/10;
        v.y+=*(const s16 *)((u32)d_020A1B38+((u32)((((struct Obj00831 *)q)->f62*546)>>4)<<2))*4;
        ++((struct Obj00831 *)q)->f62;
        if(((struct Obj00831 *)q)->f62>120) ((struct Obj00831 *)q)->f62=0;
    } else ((struct Obj00831 *)q)->f68=0;
    if(((struct Obj00831 *)q)->f66<((struct Obj00831 *)q)->f68) ++((struct Obj00831 *)q)->f66;
    if(((struct Obj00831 *)q)->f66>((struct Obj00831 *)q)->f68) {
        if(mode==0) {
            if(((struct Obj00831 *)q)->f66>=32) ((struct Obj00831 *)q)->f66-=32;
            else ((struct Obj00831 *)q)->f66=0;
        } else --((struct Obj00831 *)q)->f66;
    }
    height=((struct Obj00831 *)q)->f66;
    if(height) f=0.5f+(float)(height*4096);
    else f=(float)(height*4096)-0.5f;
    v.y+=(int)f/16;
    func_021D79A8(p,q,v.y);
    func_02015C78(((struct Obj00831 *)q)->f0,(u32 *)(&v));
    func_02015E04(((struct Obj00831 *)q)->f0);
    if(((struct Obj00831 *)q)->f66==0 && ((struct Obj00831 *)q)->f68==0) return 1;
    return 0;
}
