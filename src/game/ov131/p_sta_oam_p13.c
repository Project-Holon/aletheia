/*
 * file:     p_sta_oam_p13.c
 * unit:     yes
 * function: func_021D7460, func_021D75A4
 * address:  0x021D7460
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
 *   func_02035CB8 0x02035CB8 arm
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_021D77E8 0x021D77E8 thumb ov131
 *   d_021DC1E0 0x021DC1E0 data a1
 *   func_021D77F8 0x021D77F8 thumb ov131
 *   func_021D7810 0x021D7810 thumb ov131
 */
#include "../../matched/include/Obj00200.h"
#include "../../matched/include/Obj23140.h"
#include "../../matched/include/Obj00219.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {u8 b[12];} Rects;

typedef signed char s8;

typedef enum { D0,D1,D2,D3,D4 } Direction;

typedef enum { F0,F1 } Flag;

struct hdr { u8 f0,f1,f2,f3; int f4; };

typedef struct { u8 pad[0x94]; u8 ring[5]; u8 f99,f9a; } Ring;

extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern int func_02035BA4(const void *);
extern void func_021D77E8(u8 *p, u32 a, u32 b);
extern void func_021D77F8(struct hdr *,u32,u32,int);
extern void func_021D7810(int,Ring *,int);
void func_021D7460(u8 *a,u8 *p);
void func_021D75A4(int a,u8 *p);
extern const Rects d_021DC1E0;

/*
 * note 2026-10-02 (lane R4): the loop stores 0 (the copy of r4 before the loop is the
 *   zero already in r4), not the counter; the three post-loop stores are 0 too.
 */
void func_021D7460(u8 *a,u8 *p) {
    Rects r=d_021DC1E0;
    u32 x,y;
    int t,g,k;
    u8 i;
    func_02035CB8(&x,&y);
    if(((struct Obj23140 *)a)->f38!=0) return;
    t=func_02035C60();
    g=func_02035C38();
    k=func_02035BA4(&r);
    if(((struct Obj00200 *)p)->f8==0) {
        if(k==0 || (k==1 && t==0)) {
            if(t==1) {
                ((struct Obj00200 *)p)->f6C=1;
                ((struct Obj00200 *)p)->f58=0;
                func_021D77E8(p+0x78,x,y);
                func_021D77E8(p+0x80,x,y);
                func_021D77E8(p+0x88,x,y);
                for(i=0;i<5;i++) p[0x94+i]=0;
                p[0x99]=0;
                p[0x9a]=0;
                ((struct Obj00200 *)p)->f90=0;
            } else if(g==1 && ((struct Obj00200 *)p)->f6C==1) {
                func_021D75A4((int)a,p);
            }
            ((struct Obj00200 *)p)->f70=x;
            ((struct Obj00200 *)p)->f74=y;
        } else {
            if(((struct Obj00200 *)p)->f6C==1 && ((struct Obj00200 *)p)->f58==0 && ((struct Obj00200 *)p)->f5C==0) {
                ((struct Obj00200 *)p)->f8=1;
                p[0x9b]=0;
            }
            func_021D77E8(p+0x78,x,y);
            func_021D77E8(p+0x80,x,y);
            func_021D77E8(p+0x88,x,y);
            ((struct Obj00200 *)p)->f6C=0;
        }
    } else if(((struct Obj00200 *)p)->f8==2) {
        if(k==0 || (k==1 && t==0)) {
            if(t==1) ((struct Obj00200 *)p)->f6C=1;
        } else if(((struct Obj00200 *)p)->f6C==1) {
            ((struct Obj00200 *)p)->f6C=0;
            ((struct Obj00200 *)p)->f8=3;
            p[0x9b]=0;
        }
    }
}

/*
 * note: three coordinate pairs (x,y from func_02035CB8) are compared against
 *   byte histories at +0x7A/+0x82/+0x8A and dispatched to func_021D77F8 /
 *   func_021D77E8. direction=0 is written before ++p[0x81] and flag=0 after
 *   ry; this places the r3/r4 zero registers.
 * note 2026-10-02 (lane R5): the rotation x delta is spelled
 *   `rx=p[0x8a]; rx=(s8)(x-rx);`. The byte is loaded into rx's own register
 *   (r1, the register that later holds the s8 result), so the subtraction
 *   reads ldrb r1 / ldr r0,x / subs r0,r0,r1. A separate byte temporary or a
 *   direct (s8)(x-p[0x8a]) put the byte in r0 (3 bytes off).
 */
void func_021D75A4(int a,u8 *p)
{
    u32 x,y;
    int dx,dy,rx,ry;
    Direction direction;
    Flag flag;
    u32 tmp;
    u32 *tmp1;
    func_02035CB8(&x,&y);
    dx=(s8)(x-p[0x7a]);
    dy=(s8)(y-p[0x7b]);
    if ((((struct Obj00219 *)p)->f7C==0 || ((struct Obj00219 *)p)->f7C==3) && dx>16)
        func_021D77F8((struct hdr *)(p+0x78),x,y,1);
    if (((struct Obj00219 *)p)->f7C<=1 && dx < -16)
        func_021D77F8((struct hdr *)(p+0x78),x,y,3);
    if (dy>16 || dy < -16 || p[0x79]>20)
        func_021D77E8((u8 *)p+0x78,x,y);
    ++((u8 *)p)[0x79];
    dx=(s8)(x-p[0x82]);
    dy=(s8)(y-p[0x83]);
    if ((((struct Obj00219 *)p)->f84==0 || ((struct Obj00219 *)p)->f84==4) && dy>16)
        func_021D77F8((struct hdr *)(p+0x80),x,y,2);
    if ((((struct Obj00219 *)p)->f84==0 || ((struct Obj00219 *)p)->f84==2) && dy < -16)
        func_021D77F8((struct hdr *)(p+0x80),x,y,4);
    if (dx>16 || dx < -16 || p[0x81]>20)
        func_021D77E8((u8 *)p+0x80,x,y);
    direction=0;
    ++((u8 *)p)[0x81];
    rx=p[0x8a];
    rx=(s8)(x-rx);
    ry=(s8)(y-p[0x8b]);
    flag=0;
    if (rx>16) direction=1;
    else if (rx < -16) direction=3;
    else if (ry>16) direction=2;
    else if (ry < -16) direction=4;
    if (direction!=0 && (u32)direction!=((struct Obj00219 *)p)->f8C) {
        if (((struct Obj00219 *)p)->f8C+1==(u32)direction ||
            (((struct Obj00219 *)p)->f8C==4 && direction==1)) {
            tmp=((struct Obj00219 *)p)->f90;
            if (tmp<=1) {
                ((struct Obj00219 *)p)->f90=1;
                func_021D77F8((struct hdr *)(p+0x88),x,y,direction);
                if (((struct Obj00219 *)p)->f8C==4) flag=1;
            } else {
                ((struct Obj00219 *)p)->f90=0;
                func_021D77E8((u8 *)p+0x88,x,y);
            }
        } else if (((struct Obj00219 *)p)->f8C-1==(u32)direction ||
            (((struct Obj00219 *)p)->f8C==1 && direction==4)) {
            tmp1=(u32 *)(p+0x90);
            if (*tmp1==2 || ((struct Obj00219 *)p)->f90==0) {
                ((struct Obj00219 *)p)->f90=2;
                func_021D77F8((struct hdr *)(p+0x88),x,y,direction);
                if (((struct Obj00219 *)p)->f8C==4) flag=1;
            } else {
                ((struct Obj00219 *)p)->f90=0;
                func_021D77E8((u8 *)p+0x88,x,y);
            }
        } else if (((struct Obj00219 *)p)->f8C==0) {
            ((struct Obj00219 *)p)->f8C=direction;
        }
    }
    if (p[0x89]>20) {
        ((struct Obj00219 *)p)->f90=0;
        func_021D77E8((u8 *)p+0x88,x,y);
    }
    func_021D7810(a,(Ring *)p,flag);
    ++((u8 *)p)[0x89];
}
