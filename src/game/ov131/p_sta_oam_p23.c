/*
 * file:     p_sta_oam_p23.c
 * unit:     yes
 * function: func_021D8AD0, func_021D8CD0, func_021D8E24, func_021D8EA8, func_021D8ED0
 * address:  0x021D8AD0
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
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021D5A9C 0x021D5A9C thumb ov131
 *   func_021D964C 0x021D964C thumb ov131
 *   func_021D9670 0x021D9670 thumb ov131
 *   func_021D9440 0x021D9440 thumb ov131
 *   func_021D949C 0x021D949C thumb ov131
 *   func_021D8F0C 0x021D8F0C thumb ov131
 *   func_021D9428 0x021D9428 thumb ov131
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_02035C08  0x02035C08  arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../../matched/include/Obj00091.h"
#include "../../matched/include/Obj00136.h"

struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} Rect;

typedef struct { u16 x; u16 y; } Point;

extern u32 func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020061E4(u32 a);
extern void func_021D5A9C(char *p, int a);
extern void func_021D964C(u8 *,u8 *);
extern void func_021D9670(u8 *,u8 *);
extern s16 func_021D9440(u8 *,u32);
extern void func_021D949C(u8 *,u8 *);
extern void func_021D8F0C(void *,u8 *,int);
extern unsigned int func_021D9428(unsigned char *p, unsigned int target);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern int func_02035C08(const void *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
int func_021D8AD0(u8 *a,u8 *p);
void func_021D8CD0(u8 *a,u8 *p);
int func_021D8E24(void *unused, u8 *p);
void func_021D8EA8(u8 *a,u8 *p);
void func_021D8ED0(u8 *a,u8 *p,u8 n);

int func_021D8AD0(u8 *a,u8 *p)
{
    u8 i,index,narrowDelta;
    s16 shortDelta;
    int position;
    if(func_020362DC()==2) {
        func_021D5A9C((char *)a,1);
        func_0204B878(((struct Obj00136 *)a)->f194,9);
        func_0204B3DC(((struct Obj00091 *)p)->f54,0);
        p[0x58]=255;
        p[0x59]=255;
        ((struct Obj00091 *)p)->f68=1;
        func_021D964C(a,p);
        func_021D9670(a,p);
        a[0x1c]=0;
        func_020061E4(1361);
        return 1;
    }
    if(a[0x1c]==1) {
        if(func_020362DC()==1 || func_020362DC()==128 || func_020362DC()==64) {
            position=-16;
            ((struct Obj00091 *)p)->f5C=0;
            *(int *)&((struct Obj00091 *)p)->f64=0;
            for(i=0;i<10;i++) {
                if(p[0x59]==*(u16 *)(p+0x70+i*20)) position=func_021D9440(p,i);
            }
            if(position < -4 || position >144) func_021D8EA8(a,p);
            func_021D964C(a,p);
            func_021D949C(a,p);
            func_020061E4(1352);
            a[0x1c]=0;
            return 1;
        }
    } else if(func_0203633C()==128) {
        index=p[0x58]+1;
        if(index>=10) index-=10;
        if(*(u16 *)(p+0x70+index*20)!=0xffff) {
            p[0x58]=index;
            ((struct Obj00091 *)p)->f68=1;
            if(func_021D9440(p,p[0x58])>128) {
                narrowDelta=func_021D9440(p,p[0x58])-128;
                func_021D8F0C(a,p,narrowDelta);
            }
            func_021D8ED0(a,p,p[0x58]);
            func_021D964C(a,p);
            func_021D949C(a,p);
            func_020061E4(1352);
        }
        return 1;
    } else if(func_0203633C()==64) {
        index=p[0x58];
        if(index==0) index=9;
        else index-=1;
        if(*(u16 *)(p+0x70+index*20)!=0xffff) {
            p[0x58]=index;
            ((struct Obj00091 *)p)->f68=1;
            if(func_021D9440(p,p[0x58])<8) {
                shortDelta=func_021D9440(p,p[0x58])-8;
                func_021D8F0C(a,p,shortDelta);
            }
            func_021D8ED0(a,p,p[0x58]);
            func_021D964C(a,p);
            func_021D949C(a,p);
            func_020061E4(1352);
        }
        return 1;
    }
    return 0;
}

/*
 * proof: The delta subtract at 021D8D9C is full-word modulo arithmetic,
 *   then sign-extends its low halfword. Twice that s16 is -65536..65534,
 *   spelled multiply, permitting negative input. Velocity sums wrap as
 *   u32 before conversion to signed int and truncating division by 2.
 *   Negative velocity +1 and positive velocity -1 cannot overflow int;
 *   their halved outgoing values are explicitly narrowed to s16.
 * interface: 02035C60's result is read by the original despite its matched
 *   void forwarding declaration. 021D9428 forwards target in live r1 to
 *   021D93E4; the original explicitly narrows target to u8 before the call.
 */
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


int func_021D8E24(void *unused, u8 *p)
{
    Rect r[11];
    u8 i;
    int v;

    for (i = 0; i < 10; i++) {
        v = func_021D9440(p, i);
        r[i].w = 8;
        r[i].h = 0x90;
        if (v < 0)
            r[i].x = 0;
        else if (v > 0xa8)
            r[i].x = 0xa8;
        else
            r[i].x = v;
        if (v + 0x18 < 0)
            r[i].y = 0;
        else if (v + 0x18 > 0xa8)
            r[i].y = 0xa8;
        else
            r[i].y = v + 0x18;
        if (r[i].x == 0 && r[i].y == 0)
            r[i].x = 0xfd;
        if (func_021D9428(p, i) == 0xffff)
            r[i].x = 0xfd;
    }
    r[10].x = 0xff;
    return func_02035C08(r);
}

void func_021D8EA8(u8 *a,u8 *p)
{
    func_021D8ED0(a,p,(u8)(((((struct Obj00091 *)p)->f14+23)/24)%10));
}

void func_021D8ED0(u8 *a,u8 *p,u8 n)
{
    Point pt;
    pt.x=8;
    pt.y=func_021D9440(p,n);
    func_0204B404(((struct Obj00091 *)p)->f54,(const struct Vec2 *)(&pt),0);
    p[0x58]=n;
    *(int *)&((struct Obj00091 *)p)->f68=1;
    p[0x59]=func_021D9428(p,n);
}
