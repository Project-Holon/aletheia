/*
 * file:     pokemontrade_proc_p18.c
 * unit:     yes
 * function: func_021DC5F0, func_021DC62C, func_021DC720, func_021DC818, func_021DC854, func_021DC894, func_021DCA84
 * address:  0x021DC5F0
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
 *   func_020076A4 0x020076A4 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 *   func_021E64B8 0x021E64B8 thumb ov119
 *   func_021E3230 0x021E3230 thumb ov119
 *   func_021DD588 0x021DD588 thumb ov119
 *   func_021DF8E0 0x021DF8E0 thumb ov119
 *   func_021DD9DC 0x021DD9DC thumb ov119
 *   func_021E4570 0x021E4570 thumb ov119
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_021E69A4 0x021E69A4 thumb ov119
 *   func_021DF7D0 0x021DF7D0 thumb ov119
 *   func_021E2680 0x021E2680 thumb ov119
 *   func_021E4888 0x021E4888 thumb ov119
 *   func_021E2438 0x021E2438 thumb ov119
 *   func_021B639C 0x021B639C thumb ov067
 *   func_021E48E0 0x021E48E0 thumb ov119
 *   func_0204B1CC 0x0204B1CC arm
 *   func_021E11A8 0x021E11A8 thumb ov119
 *   func_021DD174 0x021DD174 thumb ov119
 *   func_021E293C 0x021E293C thumb ov119
 *   func_021E3F08 0x021E3F08 thumb ov119
 *   func_021E4000 0x021E4000 thumb ov119
 *   func_021E57A4 0x021E57A4 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02030678 0x02030678 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   d_021E8560 0x021E8560 data a4
 *   ov067_id 0x00000043 data a1
 *   ov114_id 0x00000072 data a1
 *   ov117_id 0x00000075 data a1
 *   ov118_id 0x00000076 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   func_0204363C 0x0204363C arm
 *   func_020173EC 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   d_021E80B0 0x021E80B0 data a4
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_021DC538 0x021DC538 thumb ov119
 *   func_021DC3EC 0x021DC3EC thumb ov119
 *   func_021DC458 0x021DC458 thumb ov119
 *   func_0204B100 0x0204B100 arm
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_0203A574 0x0203A574 arm
 *   d_021E7614 0x021E7614 data a4
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021DC500 0x021DC500 thumb ov119
 *   func_021E30EC 0x021E30EC thumb ov119
 *   func_02043534 0x02043534 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0B34 0x021E0B34 thumb ov119
 *   func_021E10D8 0x021E10D8 thumb ov119
 *   func_021E3FE4 0x021E3FE4 thumb ov119
 *   func_021DC494 0x021DC494 thumb ov119
 *   func_021E3C20 0x021E3C20 thumb ov119
 *   func_0203D34C 0x0203D34C arm
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_020435F4 0x020435F4 arm
 *   func_021DAC60 0x021DAC60 thumb ov119
 */
#include "../../matched/include/Obj06424.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj10357.h"
#include "../../matched/include/Obj03256.h"
#include "../../matched/include/Obj04478.h"

#define P(o) (*(void **)(p+(o)))
#define I(o) (*(int *)(p+(o)))
#define H(o) (*(u16 *)(p+(o)))
struct Bank;
struct Obj0203159C;
struct Blk37;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct Record {u16 value;u8 a,b;} Record;

typedef unsigned int   u32;

extern u8 func_020076A4(void *save);
extern void func_02082BCC(void *,int,int);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void func_021E64B8(void *);
extern void func_021E3230(void *);
extern void func_021DD588(char *p);
extern void func_021DF8E0(void *);
extern void func_021E4570(char *p);
extern void func_021DD9DC(unsigned char *),func_021E36D8(void *,int),func_021E69A4(char *),func_021DF7D0(void *),func_021E2680(char *),func_021E4888(char *),func_021E2438(char *,int);
extern void func_021B639C(u8 *p);
extern void func_021E48E0(char *);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern void func_021E11A8(char *);
extern void func_021DD174(char *);
extern void func_021E293C(char *p, int i);
extern void func_021E3F08(char *);
extern void func_021E4000(char *);
extern void func_021E57A4(int);
extern u32 func_020307B0(void *p);
extern int func_02005E9C(void);
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 a);
extern void func_02030678(void *a, u32 b, u32 c);
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern int func_02034AC4(int);
extern unsigned int func_020173EC(void);
extern int func_021D8A24(void *);
extern void func_0204363C(unsigned int swap);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_02043534(unsigned int planes);
extern void func_020435F4(unsigned int planes);
extern void func_0203D34C(unsigned int a, unsigned int b);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void *func_0200CA1C(void *);
extern u32 func_0200CA38(struct Blk37 *p);
extern void func_021DC538(char *,void *,u16),func_021DC5F0(char *),func_021DC3EC(char *),func_021DC458(char *);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0203A574(unsigned,unsigned,unsigned,unsigned);
extern void *func_020056A0(void (*)(void *,void *),void *,int);
extern void func_021DC500(int a, char *p);
extern void func_021E30EC(char *);
extern void func_021D8E84(void *,int);
extern void func_021E0B34(char *p);
extern void func_021E10D8(char *p);
extern void func_021E3FE4(char *p);
extern void func_021DC494(char *);
extern void func_021E3C20(char *p);
extern void func_021E3208(void *,int);
extern void func_021DAC60(char *p);
void func_021DC5F0(char *p);
void func_021DC62C(char *p,int n);
void func_021DC720(char *p);
void func_021DC818(char *p);
void *func_021DC854(void *a,int t);
int func_021DC894(int a,int b,char *q,char *p,int n);
void func_021DCA84(void *a, int b, int c);
extern char d_021E8560[];
extern char ov067_id[],ov114_id[],ov117_id[],ov118_id[];
extern const char d_021E80B0[];
extern char d_021E7614[];

void func_021DC5F0(char *p)
{
    int v = func_020076A4((void *)(((struct Obj06424 *)p)->f828));
    ((struct Obj06424 *)p)->f634 = v * 6 + 2;
    ((struct Obj06424 *)p)->f630 = v;
    ((struct Obj06424 *)p)->f638 = v * 0x14 + 0xC;
    ((struct Obj06424 *)p)->f63C = v * 0xA0 + 0x60;
}

/*
 * lever: output pointer declared before scalar locals; counter zero before base assignment.
 * arithmetic: signed n guard/callee argument; unsigned base/index preserve low-word MUL/ADD wrapping at 021DC6A6/021DC6A8/021DC6B2.
 */
void func_021DC62C(char *p,int n)
{
    Record *out=(Record *)(p+0x11fc);
    int i,mon,v;
    unsigned index,base;
    if(n==0) {
        func_02082BCC(out,0,0xb58);
        for(i=0;i<6;i++) {
            mon=(int)func_021D8DD0((void *)(*(int *)&((struct Obj00001 *)p)->f828),((struct Obj00001 *)p)->f630,i,p);
            if(mon && func_02017E88((void *)mon,0xa9,0)) {
                v=func_02017E88((void *)mon,0xab,0);
                if(v) {
                    out[i].value=v;
                    out[i].a=func_02017E88((void *)mon,0x6f,0);
                    out[i].b=func_02017E88((void *)mon,0x6e,0);
                }
            }
        }
    }
    while(n<24) {
        i=0;
        base=(unsigned)n*30u+6u;
        for(;i<30;i++) {
            index=(unsigned)i+base;
            mon=(int)func_021D8DD0((void *)(*(int *)&((struct Obj00001 *)p)->f828),n,i,p);
            if(mon && func_02017E88((void *)mon,0xa9,0)) {
                v=func_02017E88((void *)mon,0xab,0);
                if(v) {
                    out[index].value=v;
                    out[index].a=func_02017E88((void *)mon,0x6f,0);
                    out[index].b=func_02017E88((void *)mon,0x6e,0);
                }
            }
        }
        return;
    }
}

/*
 * volatile: 021DC726 reads hardware DISPCNT 0x04001000 before updating it.
 */
void func_021DC720(char *p)
{
    int i;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_021E64B8(p);func_021E3230(p);func_021DD588(p);func_021DF8E0(p);func_021DD9DC((unsigned char *)p);func_021E4570(p);
    func_021E36D8(p,1);func_021E69A4(p);func_021DF7D0(p);func_021E2680(p);func_021E4888(p);
    func_021E2438(p,0);func_021E2438(p,1);
    if(P(0x9c0)) {func_021B639C(P(0x9c0));P(0x9c0)=0;}
    func_021E48E0(p);
    if(P(0x9c4)) {func_0204B1CC(P(0x9c4));P(0x9c4)=0;}
    func_021E11A8(p);func_021DD174(p);
    func_021E293C(p,0);func_021E293C(p,1);func_021E3F08(p);func_021E4000(p);func_021E57A4((int)p);
    if(P(0x818)) {func_020307B0(P(0x818));P(0x818)=0;}
    for(i=0;i<4;i++) {
        char *q=p+i*4;
        if(((struct Obj10357 *)q)->f85C) {func_020307B0(((struct Obj10357 *)q)->f85C);((struct Obj10357 *)q)->f85C=0;}
    }
}

void func_021DC818(char *p)
{
    switch (((struct Obj00001 *)p)->f11F8) {
    case 0:
        break;
    case 2:
        func_02005E9C();
        func_02005DE4(0);
    case 1:
        func_02005E9C();
        func_02005DE4(0);
        func_02005DF8(30);
    }
    ((struct Obj00001 *)p)->f11F8 = 0;
}

void *func_021DC854(void *a,int t) {
 void *p;
 func_02030678(d_021E8560,0xc000,0x91);
 func_0203064C(1,31,t);
 p=func_0203159C(a,0x1d54,0x91);
 func_02082BCC(p,0,0x1d54);
 return p;
}

int func_021DC894(int a,int b,char *q,char *p,int n)
{
    if(n<5) {func_02034AC4((int)ov067_id);func_02034AC4((int)ov114_id);}
    if(n==0 || n==4) func_02034AC4((int)ov117_id);
    else func_02034AC4((int)ov118_id);
    func_0204363C(1);
    H(0x5f4)=31;
    I(0x118c)=n;
    *(char * *)&((struct Obj03256 *)p)->f8=q;
    I(0x5dc)=(int)func_02030734(0x91,func_020173EC(),1,d_021E80B0,0x110b);
    I(0x5e0)=(int)func_02030734(0x91,func_020173EC(),1,d_021E80B0,0x110c);
    I(0x10a4)=(int)func_02030734(0x91,512,0,d_021E80B0,0x110d);
    I(0x10a8)=(int)func_02030734(0x91,512,0,d_021E80B0,0x110e);
    ((struct Obj03256 *)p)->f11F6=func_0200CA38(func_0200CA1C(((struct Obj04478 *)q)->f14));
    if(q) func_021DC538(p,((struct Obj04478 *)q)->f14,((struct Obj04478 *)q)->f2E);
    func_021DC5F0(p);func_021DC3EC(p);func_021DC458(p);
    I(0x9c4)=(int)func_0204B100(0x154,0,H(0x5f4));
    if(func_021D8A24(p)) {
        func_0203A574(0xc00,(unsigned)d_021E7614,24,(unsigned)p);
        func_0203D7B0(1);func_0203D7BC(1);
    }
    I(0x9c8)=(int)func_020056A0((void (*)(void *, void *))func_021DC500,p,0);
    I(0xf60)=0;
    I(0xf84)=-1;I(0x109c)=-1;I(0xf7c)=-1;I(0xf80)=-1;I(0xf98)=-1;I(0xf94)=-1;
    func_021E30EC(p);
    if(((struct Obj04478 *)q)->f8==1) {
        func_02043534(16);func_021D8E84(p,(int)func_021E0B34);((struct Obj04478 *)q)->f8=0;return 1;
    }
    func_021E10D8(p);func_021E3FE4(p);
    if(I(0x118c)<4) {func_021DC494(p);func_021E3C20(p);func_0203D34C(1,H(0x5f4));}
    func_021E3208(p,0);func_02043534(0);func_020435F4(0);func_021D8E84(p,(int)func_021DAC60);
    return 1;
}


/*
 * Send a two-descriptor request with the timer base 0xc6000.
 */
void func_021DCA84(void *a, int b, int c)
{
    int r = (int)func_021DC854(a, 0xc6000);

    func_021DC894((int)a, b, (char *)c, (char *)r, 2);
}
