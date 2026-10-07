/*
 * file:     pokemontrade_proc_p22.c
 * unit:     yes
 * function: func_021DDB90, func_021DDBF0, func_021DDCF0, func_021DDD60, func_021DDDB8, func_021DDDF4, func_021DDE4C, func_021DDE90, func_021DDED4, func_021DDF28, func_021DDF74, func_021DE0F0, func_021DE12C, func_021DE1B4
 * address:  0x021DDB90
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
 *   func_020399A8 0x020399A8 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035C60 0x02035C60 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDB64 0x021DDB64 thumb ov119
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_021DD140  0x021DD140  thumb  ov119
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_02039CB4  0x02039CB4  arm
 *   func_021DD24C  0x021DD24C  thumb  ov119
 *   func_021DD294  0x021DD294  thumb  ov119
 *   func_021DD080  0x021DD080  thumb  ov119
 *   func_021DA76C  0x021DA76C  thumb  ov119
 *   func_021D94D4 0x021D94D4 thumb ov119
 *   func_021D95D0 0x021D95D0 thumb ov119
 *   func_021D95F0 0x021D95F0 thumb ov119
 *   func_021D9610 0x021D9610 thumb ov119
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021E12F8 0x021E12F8 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   d_021E76E4 0x021E76E4 data a4
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_02043534 0x02043534 arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_02039C68  0x02039C68  arm
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021D89CC  0x021D89CC  thumb  ov119
 *   func_021D9434  0x021D9434  thumb  ov119
 *   func_021DE8C0  0x021DE8C0  thumb  ov119
 *   func_021D9468 0x021D9468 thumb ov119
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021D89EC 0x021D89EC thumb ov119
 *   func_021E219C 0x021E219C thumb ov119
 *   func_021E6440 0x021E6440 thumb ov119
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj10359.h"
#include "../../matched/include/Obj10360.h"
#include "../../matched/include/Obj22741.h"
#include "../../matched/include/Obj01251.h"
#include "../../matched/include/Obj05329.h"

struct Entry;
struct MsgBank;
struct Link;
struct TaskMenu;
struct WordSet;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct { int a,b; } Pair;

typedef struct { char pad[0xfd8]; void *obj[2][3]; } State;

extern struct Entry *func_020399A8(void);
extern int func_021E12AC(char *p);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern int func_02035C60(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DDB64(unsigned char *p);
extern u32 func_0203D1A4(struct Link *p);
extern int func_021DD140(char *p);
extern int func_021D8A24(void *p);
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern int func_021DD24C(char *p);
extern void func_021DD294(char *p, int a, int b);
extern void func_021DD080(void *a, void *b, void *c);
extern void func_021DA76C(void *p);
extern int func_021D94D4(char *p);
extern int func_021D95D0(void *);
extern u32 func_021D95F0(void *p);
extern int func_021D9610(unsigned char *p);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021E12F8(char *p);
extern void func_021E1098(char *p);
extern void func_021E1410(void *p, int *ids, int count);
extern void func_02043534(u32 planes);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern void *func_021D8FA4(void *p, int idx);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021D89CC(char *p);
extern void func_021D9434(void *p);
extern void func_021DE8C0(char *p);
extern void func_021D9468(void *,int,void *);
extern u32 func_020173EC(void);
extern void func_02082D44(void *,const void *,int);
extern int func_021D89EC(const u8 *p);
extern void func_021E219C(char *p, void *mon, int side, int flag);
extern void func_021E6440(int p, int a, int b);
void func_021DDB90(unsigned char *p);
void func_021DDBF0(char *p);
void func_021DDCF0(unsigned char *p);
void func_021DDD60(unsigned char *p);
void func_021DDDB8(unsigned char *p);
void func_021DDDF4(unsigned char *p);
void func_021DDE4C(unsigned char *p);
void func_021DDE90(unsigned char *p);
void func_021DDED4(unsigned char *p);
void func_021DDF28(char *p);
void func_021DDF74(char *p);
void func_021DE0F0(void *p);
void func_021DE12C(char *p);
void func_021DE1B4(State *p,int index);
extern const Pair d_021E76E4;


void func_021DDB90(unsigned char *p)
{
    int v;func_020399A8();if(func_021E12AC((char *)p)){v=func_020362DC();if(v)func_020355D8(0);if(v==0){v=func_02035C60();if(v)func_020355D8(1);if(v==0)return;}func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),0x88,(void *)(*(int *)&((struct Obj00001 *)p)->f738));func_021E1024(p);func_021E1030((char *)p);func_021D8E84(p,(int)func_021DDB64);}
}


void func_021DDBF0(char *p)
{
    int a, b, c, d, m;
    a = func_0203D1A4((struct Link *)((u32)func_020399A8()));
    b = 1 - a;
    if (func_021E12AC(p) == 0) return;
    if (func_021DD140(p) == 0) return;
    if (func_021D8A24(p) != 0 && func_02039CB4((struct Link *)func_020399A8(), 0x1D, 8) == 0) {
        func_021DD24C(p);
        return;
    }
    func_021DD294(p, 0, 0);
    c = (unsigned char)(p + a)[0x11E0];
    if (c == 13 && (unsigned char)(p + b)[0x11E0] == 13) {
        func_021DD080((void *)((u32)func_020399A8()), (void *)13, p);
        func_021D8E84(p, (int)func_021DA76C);
        return;
    }
    d = (unsigned char)(p + b)[0x11E0];
    if (d == 5) m = 0x61;
    else if (c == 5) m = 0x62;
    else if (d == 7) m = 0x63;
    else if (c == 7) m = 0x64;
    else if (d == 8) m = 0x64;
    else if (c == 8) m = 0x63;
    else if (d == 6) m = 0x61;
    else if (c == 6) m = 0x6F;
    else if (d == 14) m = 0x97;
    else if (c == 14) m = 0x96;
    func_02045CAC(((struct Obj00001 *)p)->f720, m, ((struct Obj00001 *)p)->f738);
    func_021E1024(p);
    p[0x11E0] = 0;
    p[0x11E1] = 0;
    func_021D8E84(p, (int)func_021DDB90);
}

void func_021DDCF0(unsigned char *p)
{
    unsigned char b=13;if(func_021D94D4((char *)p))b=5;else if(func_021D95D0(p))b=7;else if(func_021D95F0(p))b=8;else if(func_021D9610(p))b=6;if(func_0203D3A8(func_020399A8(),0xc00,1,(u32)(&b))){func_021DD080(func_020399A8(),(void *)29,p);func_021D8E84(p,(int)func_021DDBF0);}
}


void func_021DDD60(unsigned char *p)
{
    if(func_021D8A24(p)==0){p[0x11e0]=13;p[0x11e1]=13;func_021D8E84(p,(int)func_021DDBF0);return;} if(func_02039CB4((struct Link *)func_020399A8(),30,8)==0){func_021DD24C((char *)p);return;}func_021DD294((char *)p,0,0);func_021D8E84(p,(int)func_021DDCF0);
}


void func_021DDDB8(unsigned char *p)
{
    unsigned char v=14;
    if(func_0203D3A8(func_020399A8(),0xc00,1,(u32)(&v))) {
        func_021DD080(func_020399A8(),(void *)29,p);
        func_021D8E84(p,(int)func_021DDBF0);
    }
}


void func_021DDDF4(unsigned char *p)
{
    if(func_021D8A24(p)==0){p[0x11e0]=14;p[0x11e1]=14;func_021D8E84(p,(int)func_021DDBF0);return;} if(func_02039CB4((struct Link *)func_020399A8(),30,8)==0){func_021DD24C((char *)p);return;}func_021DD294((char *)p,0,0);func_021D8E84(p,(int)func_021DDDB8);
}


void func_021DDE4C(unsigned char *p)
{
    func_021DD080((void *)((unsigned)func_020399A8()),(void *)30,p); func_02045CAC((struct MsgBank *)(((struct Obj10359 *)p)->f720),0x88,(void *)(((struct Obj10359 *)p)->f738)); func_021E1024(p); func_021E1030((char *)p); p[0x11f1]=120; func_021D8E84(p,(int)func_021DDD60);
}


void func_021DDE90(unsigned char *p)
{
    func_021DD080((void *)((unsigned)func_020399A8()),(void *)30,p); func_02045CAC((struct MsgBank *)(((struct Obj10360 *)p)->f720),0x88,(void *)(((struct Obj10360 *)p)->f738)); func_021E1024(p); func_021E1030((char *)p); p[0x11f1]=120; func_021D8E84(p,(int)func_021DDDF4);
}


void func_021DDED4(unsigned char *p)
{
    int v; if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C))==0)return;v=func_02027A04((const u8 *)(*(int *)&((struct Obj00001 *)p)->f64C));func_021E12F8((char *)p);func_021E1098((char *)p);*(int *)&((struct Obj00001 *)p)->f64C=0;switch(v){case 0:func_021D8E84(p,(int)func_021DDE4C);return;case 1:func_021D8E84(p,(int)func_021DDE90);return;}
}

void func_021DDF28(char *p)
{
    if(func_021E12AC(p)) {
        Pair t=d_021E76E4;
        func_021E1410(p,(int *)(&t),2);
        func_02043534(31);
        func_021B6558((unsigned char *)(((struct Obj22741 *)p)->f9C0),1,0);
        func_021D8E84(p,(int)func_021DDED4);
    }
}


void func_021DDF74(char *p)
{
    int a, b, c, i, m;
    a = func_0203D1A4((struct Link *)((u32)func_020399A8()));
    b = 1 - a;
    if (func_021E12AC(p) == 0) return;
    if (func_021DD140(p) == 0) return;
    if (func_021D8A24(p) != 0 && func_02039CB4((struct Link *)func_020399A8(), 0x1C, 8) == 0) {
        func_021DD24C(p);
        return;
    }
    i = 0;
    func_021DD294(p, 0, 0);
    c = (unsigned char)(p + a)[0x11E0];
    if (c == 11 && (unsigned char)(p + b)[0x11E0] == 11) {
        func_02045CAC(((struct Obj01251 *)p)->f720, 0x92, ((struct Obj01251 *)p)->f73C);
        do {
            func_0201EEF4(((struct Obj01251 *)p)->f724, i, func_021D8FA4(p, i));
            i++;
        } while (i < 2);
        func_0201F250(((struct Obj01251 *)p)->f724, ((struct Obj01251 *)p)->f738, ((struct Obj01251 *)p)->f73C);
        func_021E1024(p);
        func_021D8E84(p, (int)func_021DDF28);
        return;
    }
    if ((unsigned char)(p + b)[0x11E0] == 12) {
        (p + 0x11E0)[0x11] = 0x78;
        m = 0x93;
        if (((struct Obj01251 *)p)->f118C == 3 && (u8)p[0x11FA] >= 3) {
            func_021D89CC(p);
            func_021D8E84(p, (int)func_021D9434);
            return;
        }
    } else if (c == 12) {
        (p + 0x11E0)[0x11] = 0x78;
        m = 0x95;
        if (((struct Obj01251 *)p)->f118C == 3 && (u8)p[0x11FA] >= 3) {
            func_021D89CC(p);
            func_021D8E84(p, (int)func_021D9434);
            return;
        }
    }
    func_02045CAC(((struct Obj01251 *)p)->f720, m, ((struct Obj01251 *)p)->f738);
    func_021E1024(p);
    p[0x11E0] = 0;
    p[0x11E1] = 0;
    if (func_021D8A24(p) != 0) {
        func_02039C68((struct Link *)func_020399A8(), 0x19, 8);
    }
    ((struct Obj01251 *)p)->fF2C = 0;
    func_021D8E84(p, (int)func_021DE8C0);
}


void func_021DE0F0(void *p)
{
    u8 cmd;
    cmd = 0xB;
    if (func_0203D3A8((struct Entry *)((u32)func_020399A8()), 0xC00, 1, (u32)(&cmd)) != 0) {
        func_02039C68((struct Link *)func_020399A8(), 0x1C, 8);
        func_021D8E84(p, (int)func_021DDF74);
    }
}

void func_021DE12C(char *p)
{
    void *obj;
    int n;
    func_02045CAC((struct MsgBank *)(((struct Obj05329 *)p)->f720),0x88,(void *)(((struct Obj05329 *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    p[0x11f1]=120;
    if(func_021D8A24(p)==0) {
        p[0x11e0]=11;
        p[0x11e1]=11;
        obj=((struct Obj05329 *)p)->fFD8;
        func_021D9468(p,1,obj);
        n=func_020173EC();
        func_02082D44(obj,func_021D8FA4(p,1),n);
        func_021D8E84(p,(int)func_021DDF74);
        return;
    }
    func_021D8E84(p,(int)func_021DE0F0);
}

void func_021DE1B4(State *p,int index)
{
    int col=index%3;
    int row=index/3;
    int other=1-row;
    void *obj=p->obj[other][col];
    if(func_021D89EC(obj)) {
        func_021E219C((char *)p,obj,other,1);
        func_021E6440((int)p,row,col);
    }
}
