/*
 * function: func_021D8CD0
 * address: 0x021D8CD0
 * packet: pkt_ov131_021D8CD0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * proof: The delta subtract at 021D8D9C is full-word modulo arithmetic,
 *   then sign-extends its low halfword. Twice that s16 is -65536..65534,
 *   spelled multiply, permitting negative input. Velocity sums wrap as
 *   u32 before conversion to signed int and truncating division by 2.
 *   Negative velocity +1 and positive velocity -1 cannot overflow int;
 *   their halved outgoing values are explicitly narrowed to s16.
 * interface: 02035C60's result is read by the original despite its matched
 *   void forwarding declaration. 021D9428 forwards target in live r1 to
 *   021D93E4; the original explicitly narrows target to u8 before the call.
 * symbols:
 *   func_021D5A9C 0x021D5A9C thumb ov131
 *   func_021D964C 0x021D964C thumb ov131
 *   func_021D9670 0x021D9670 thumb ov131
 *   func_021D8E24 0x021D8E24 thumb ov131
 *   func_021D9428 0x021D9428 thumb ov131
 *   func_021D949C 0x021D949C thumb ov131
 *   func_021D8F0C 0x021D8F0C thumb ov131
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 */
#include "../include/Obj00091.h"
#include "../include/Obj00136.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021D5A9C(char *p, int a);
extern void func_021D964C(u8 *,u8 *);
extern void func_021D9670(u8 *,u8 *);
extern int func_021D8E24(u8 *,u8 *);
struct Obj;
extern unsigned int func_021D9428(unsigned char *p, unsigned int target);
extern void func_021D949C(u8 *,u8 *);
extern void func_021D8F0C(void *,u8 *,int);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020061E4(u32 a);
extern int func_02035C60(void);
extern int func_02035C38(void);
void func_021D8CD0(u8 *a,u8 *p)
{
    int index, delta, velocity;
    if(((struct Obj00136 *)a)->f24==7) {
        func_021D5A9C((char *)a,1);
        func_0204B878(((struct Obj00136 *)a)->f194,9);
        func_0204B3DC(((struct Obj00091 *)p)->f54,0);
        p[0x58]=255;
        p[0x59]=255;
        ((struct Obj00091 *)p)->f68=1;
        a[0x1c]=1;
        func_021D964C(a,p);
        func_021D9670(a,p);
        func_020061E4(1361);
        return;
    }
    if(func_02035C60()==1 && ((struct Obj00136 *)a)->f28>8 && ((struct Obj00136 *)a)->f28<144) {
        index=func_021D8E24(a,p);
        if(index!=-1) {
            p[0x58]=(u8)index;
            ((struct Obj00091 *)p)->f68=1;
            p[0x59]=func_021D9428(p,(u8)index);
            ((struct Obj00091 *)p)->f64=1;
            ((struct Obj00091 *)p)->f5C=0;
            func_0204B3DC(((struct Obj00091 *)p)->f54,0);
            func_021D964C(a,p);
            func_021D949C(a,p);
        }
        a[0x1c]=1;
        return;
    }
    if(func_02035C38()==1 && ((struct Obj00091 *)p)->f64==1 && ((struct Obj00136 *)a)->f28>8 && ((struct Obj00136 *)a)->f28<144) {
        delta=(s16)(((struct Obj00136 *)a)->f34-((struct Obj00136 *)a)->f2C);
        velocity=delta*2;
        func_021D8F0C(a,p,delta);
        if(velocity>=0 && ((struct Obj00091 *)p)->f5C>0 && velocity<((struct Obj00091 *)p)->f5C) {
            ((struct Obj00091 *)p)->f5C=(int)((u32)((struct Obj00091 *)p)->f5C+(u32)velocity)/2;
            return;
        }
        if(velocity<=0 && ((struct Obj00091 *)p)->f5C<0 && velocity>((struct Obj00091 *)p)->f5C) {
            ((struct Obj00091 *)p)->f5C=(int)((u32)((struct Obj00091 *)p)->f5C+(u32)velocity)/2;
            return;
        }
        ((struct Obj00091 *)p)->f5C=velocity;
        return;
    }
    ((struct Obj00091 *)p)->f64=0;
    if(((struct Obj00091 *)p)->f5C<0) {
        ((struct Obj00091 *)p)->f5C+=1;
        func_021D8F0C(a,p,(s16)(((struct Obj00091 *)p)->f5C/2));
    }
    if(((struct Obj00091 *)p)->f5C>0) {
        ((struct Obj00091 *)p)->f5C-=1;
        func_021D8F0C(a,p,(s16)(((struct Obj00091 *)p)->f5C/2));
    }
}
