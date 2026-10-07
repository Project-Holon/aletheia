/*
 * file:     wf2dmap_scrdraw.c
 * unit:     yes
 * function: func_021C59DC, func_021C59E4, func_021C59EC, func_021C59F4, func_021C5A4C, func_021C5A60, func_021C5AAC, func_021C5B0C, func_021C5B98, func_021C5C8C, func_021C5E14, func_021C5E2C
 * address:  0x021C59DC
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02049EB4 0x02049EB4 arm
 *   d_021C6144 0x021C6144 data a1
 *   func_020307B0  0x020307B0  arm
 *   func_0204B09C 0x0204B09C arm
 *   d_021C60C4 0x021C60C4 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_02041300 0x02041300 arm
 *   func_020410D0 0x020410D0 arm
 */
#include "../../matched/include/Obj23060.h"
#include "../../matched/include/Obj02840.h"
#include "../../matched/include/Obj14033.h"

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { void *f0; u32 f4; void *f8; u32 fC, f10, f14, f18; } Obj;

typedef signed int     s32;

typedef struct { u32 a[4]; u8 b[12]; u32 c; } Descriptor;

typedef signed char s8;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void *func_02049EB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 func_020307B0(void *p);
extern void func_0204B09C(void *,int,void *);
extern void func_020403F4(u32 i);
extern void func_0203FCA0(u8,void *,int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02041B6C(u32 bit);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_02041300(u8,int,int,int,u8,u8,u8);
extern void func_020410D0(u8, u8, u8, u8, u8, void *, u8, u8, u32, u32);
void func_021C59DC(s16 *p, s16 a, s16 b);
int func_021C59E4(const s16 *p);
int func_021C59EC(const s16 *p);
Obj *func_021C59F4(void *p, u32 n, const u8 *q, u32 heap);
void func_021C5A4C(u8 *p);
void func_021C5A60(char *p,void *q);
void func_021C5AAC(void *unused, u32 id, u8 *p);
void func_021C5B0C(char *p,int x,int y);
void func_021C5B98(void *p,int layer,unsigned int q,s16 x,s16 y);
void func_021C5C8C(void *p, u8 layer, u8 x, u8 y, u8 w, u8 h, void *q, u8 sx, u8 sy, int width, int height);
int func_021C5E14(unsigned int a, unsigned int b);
char *func_021C5E2C(char *p, u8 x, u8 y, unsigned mode, int w, int h, u16 *out);
extern const char d_021C6144[];
extern const Descriptor d_021C60C4;

void func_021C59DC(s16 *p, s16 a, s16 b) { p[0]=a; p[1]=b; }

int func_021C59E4(const s16 *p) { return p[0]; }

int func_021C59EC(const s16 *p) { return p[1]; }

Obj *func_021C59F4(void *p, u32 n, const u8 *q, u32 heap)
{
    Obj *o = func_02030734((u16)heap, 28, 1, d_021C6144, 104);
    o->f0 = p;
    o->f4 = n;
    o->f10 = q[0];
    o->f14 = q[1];
    func_021C5AAC((void *)n, q[1], (u8 *)q);
    o->f8 = func_02049EB4(q[8], q[9], q[10], (u32)(&o->fC), heap);
    return o;
}


void func_021C5A4C(u8 *p)
{
    func_020307B0(((struct Obj23060 *)p)->f8);
    func_020307B0(p);
}

/*
 *   typedef unsigned char u8; typedef unsigned int u32; typedef signed short s16;
 *   struct Item { int x; int y; u8 pad_08[0x40]; };
 *   struct Owner { u8 pad_00[0x98]; struct Item *items; };
 *   struct Pt { s16 x; s16 y; };
 *   void sub_0204B09C(struct Owner *owner,u32 index,struct Pt *in) {
 *       int x=in->x; int y=in->y; struct Item *it=owner->items; struct Item *p;
 *       it[index].x=x<<12; p=&it[index]; p->y=y<<12;
 *   }
 */
void func_021C5A60(char *p,void *q)
{
    int y,x;
    struct { s16 x,y; } pos;
    y=func_021C59E4(q);
    x=func_021C59EC(q);
    pos.x=x;
    pos.y=y;
    if(*(int *)(p+16)==0) func_0204B09C(*(void **)p,0,&pos);
    else { pos.y+=192; func_0204B09C(*(void **)p,1,&pos); }
    func_021C5B0C(p,x,y);
}

void func_021C5AAC(void *unused, u32 id, u8 *p)
{
    Descriptor d;
    d=d_021C60C4;
    d.b[1]=p[2]; d.b[2]=p[3]; d.b[3]=p[4];
    d.b[8]=p[5]; d.b[9]=p[6]; d.b[10]=0; d.c=p[7];
    func_020403F4((u8)id);
    func_0203FCA0(id,&d,0);
    func_02040588(id,1);
}

void func_021C5B0C(char *p,int x,int y)
{
    s16 tx,ty,rx,ry;
    tx=x/8; ty=y/8; rx=x%8; ry=y%8;
    if(tx!=((struct Obj02840 *)p)->f18||ty!=((struct Obj02840 *)p)->f1A) {
        ((struct Obj02840 *)p)->f1A=ty; ((struct Obj02840 *)p)->f18=tx;
        func_021C5B98(((struct Obj02840 *)p)->f4,((struct Obj02840 *)p)->f14,(unsigned int)(((struct Obj02840 *)p)->fC),-tx,-ty);
        func_02041B6C((u8)(((struct Obj02840 *)p)->f14));
    }
    func_02041EE4((u8)(((struct Obj02840 *)p)->f14),(int)0,(int)rx);
    func_02041EE4((u8)(((struct Obj02840 *)p)->f14),(int)3,(int)ry);
}

/*
 * extent: Two bytes of zero alignment padding precede func_021C5C8C.
 * lever: Integer address q spills; a pointer q consumes the clipping register.
 */
void func_021C5B98(void *p,int layer,unsigned int q,s16 x,s16 y)
{
    s16 width=((struct Obj14033 *)q)->f0/8;
    s16 height=((struct Obj14033 *)q)->f2/8;
    s16 sx,sy,w,h;
    if(x<0) sx=-x; else sx=0;
    if(y<0) sy=-y; else sy=0;
    if(x<=0) x=0;
    if(y<=0) y=0;
    w=33-x;
    h=25-y;
    if(width<sx+w) w-= (s16)(sx+w-width);
    if(height<sy+h) h-= (s16)(sy+h-height);
    func_02041300(layer,0,0,0,33,25,17);
    q+=12;
    func_021C5C8C(p,layer,x,y,w,h,(void *)q,sx,sy,(u8)width,(u8)height);
}

/*
 * note 2026-10-05 wD4 lane03: EXACT. Keys: width/height are int params (word prologue copy, raw in call 1);
 *   func_020410D0 declared (u8 x5, void *, u8, u8, u32, u32) in this unit, so out[] (s16) is cast (u8) in call 2;
 *   mode is unsigned (int mode coalesced with the call temp and took the lowest slot); ox/oy are int;
 *   sy/y advance by (u8)n (the listing truncates n before both adds); u8 params for tx/ty in func_021C5E2C.
 */
void func_021C5C8C(void *p, u8 layer, u8 x, u8 y, u8 w, u8 h, void *q, u8 sx, u8 sy, int width, int height)
{
    s16 out[2];
    int ox, oy;
    s8 hh, n;
    unsigned mode;
    s8 ccx, ww, cs, cx, m, tx, ty, cw, ccs;
    mode = func_021C5E14(width, height);
    if (mode == 0) {
        func_020410D0(layer, x, y, w, h, q, sx, sy, width, height);
        return;
    }
    hh = h;
    if (hh <= 0) return;
    ww = w;
    cs = sx;
    cx = x;
    do {
        oy = sy % 32;
        if (oy + hh <= 32) {
            n = hh;
            hh = 0;
        } else {
            n = 32 - oy;
            hh = hh - n;
        }
        ty = sy / 32;
        cw = ww;
        ccs = cs;
        ccx = cx;
        while (cw > 0) {
            ox = ccs % 32;
            if (ox + cw <= 32) {
                m = cw;
                cw = 0;
            } else {
                m = 32 - ox;
                cw = cw - m;
            }
            tx = ccs / 32;
            func_020410D0(layer, ccx, y, m, n,
                func_021C5E2C(q, tx, ty, mode, width, height, (u16 *)out),
                ox, oy, (u8)out[0], (u8)out[1]);
            ccs = ccs + m;
            ccx = ccx + m;
        }
        sy = sy + (u8)n;
        y = y + (u8)n;
    } while (hh > 0);
}


int func_021C5E14(unsigned int a, unsigned int b)
{
    int r;

    if (a <= 0x20) {
        r = 0;
        if (b > 0x20)
            r = 2;
    } else {
        r = 1;
        if (b > 0x20)
            r = 3;
    }
    return r;
}

char *func_021C5E2C(char *p, u8 x, u8 y, unsigned mode, int w, int h, u16 *out)
{
    u16 offset;
    switch(mode) {
    case 0: out[0]=w; out[1]=h; return p;
    case 1:
        out[0]=(x+1)*32<=w?32:w-x*32;
        out[1]=h;
        return p+(s16)(h*64)*x;
    case 2:
        out[0]=w;
        out[1]=(y+1)*32<=h?32:h-y*32;
        return p+(s16)(w*64)*y;
    case 3:
        out[0]=(x+1)*32<=w?32:w-x*32;
        out[1]=(y+1)*32<=h?32:h-y*32;
        if(y==0) { offset=0; if(x!=0) offset+=2048; }
        else { offset=(u16)(w*64); if(x!=0) offset+=(u16)(h*64); }
        return p+offset;
    }
    return 0;
}
