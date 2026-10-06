/*
 * function: func_021D708C
 * address: 0x021D708C
 * packet: pkt_ov131_021D708C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * semantic: phase u16<<15 <=2147450880; dividing by 15 then truncating
 *   to u16 leaves a full index <=8190. Speed is explicitly a low byte;
 *   phase*speed <=16711425, division by 15 fits signed int. Signed sample
 *   times 16 fits int. All later shifts and vector additions/subtractions
 *   use u32 wrap, converted to the compiler's signed word for _fflt.
 *   _ffix is called explicitly: the original unsigned speed shift can
 *   convert to float outside int range; no C float-to-int cast is assumed.
 *   The template initializes every base word; zero initializes v.
 * symbols:
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
 */
#include "../include/Obj02188.h"
#include "../include/Obj14068.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
extern const Vec d_021DC1D4;
extern const short d_020A1B38[];
extern void func_021D79A8(void *p, unsigned char *q, int radius);
extern void func_02015C48(void *,u32 *);
extern void func_02015C78(void *p, u32 *src);
extern int _ffix(float);
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
