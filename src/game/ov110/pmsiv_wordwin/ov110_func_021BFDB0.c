/*
 * function: func_021BFDB0
 * address: 0x021BFDB0
 * packet: pkt_ov110_021BFDB0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: write clamp stores in their own arms before goto apply; low n==0
 *   has a shared label. Keep lower test as <18 and nest the upper test in else.
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../../../matched/include/Obj13802.h"
typedef unsigned char u8;
typedef signed short s16;
typedef struct { s16 x,y; } Vec2;
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BFDB0(u8 *p,unsigned a,unsigned n) {
    Vec2 pos;
    s16 lo,hi;
    pos.x=244;
    if(a==0) { pos.y=18; goto apply; }
    else if(a==n) { pos.y=149; goto apply; }
    else if(n==0) goto low;
    else {
        lo=132*a/(n+1)+18;
        hi=132*(a+1)/(n+1)+17;
        pos.y=(lo+hi)/2;
        if(pos.y<18) { pos.y=18; goto apply; }
        else {
            if(pos.y>149) { pos.y=149; goto apply; }
        }
    }
    goto apply;
low: pos.y=18;
apply:
    func_0204B404(((struct Obj13802 *)p)->f1C,(const struct Vec2 *)(&pos),0);
}
