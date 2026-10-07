/*
 * file:     unit_02183B60_p10.c
 * unit:     yes
 * function: func_02185AC8, func_02185B74, func_02185C84
 * address:  0x02185AC8
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02048AE8 0x02048AE8 arm
 *   func_02048B30 0x02048B30 arm
 *   func_02048AFC 0x02048AFC arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207CEE4 0x0207CEE4 arm
 *   func_02047964  0x02047964  arm
 *   func_02047970  0x02047970  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02048C58  0x02048C58  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02047A60  0x02047A60  arm
 *   func_0207B388  0x0207B388  arm
 *   func_02185848  0x02185848  thumb  ov219
 *   func_02184790 0x02184790 thumb ov219
 *   func_02045B38 0x02045B38 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045C04 0x02045C04 arm
 *   func_02025BA0 0x02025BA0 thumb
 */
#include "../../matched/include/Obj02935.h"

struct Arg;
struct Light;
struct LightSlot;
struct MsgBank;
struct Rec;
typedef struct {long x,y,z;} Vec;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } V3;

typedef struct { V3 a; V3 b; } Pair;

typedef struct { int m[9]; } M33;

extern void func_02048AE8(void *,Vec *),func_02048B30(void *,Vec *),func_02048AFC(void *,const Vec *);
extern void func_0207CA00(const Vec *,const Vec *,Vec *),func_0207CCA4(const Vec *,Vec *),func_0207CEE4(long,const Vec *,const Vec *,Vec *);
extern long func_0207CBD0(const Vec *);
extern void func_02047964(void);
extern void func_02047970(void);
extern void func_020479D8(void);
extern void func_02048C58(struct LightSlot *slots);
extern void func_02048AD0(struct Light *l);
extern void func_0207ADC4(M33 *);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_0207B388(const void *, const M33 *, M33 *);
extern void func_02185848(M33 *, char *);
extern unsigned func_02184790(unsigned),func_02025BA0(unsigned);
extern void *func_02045B38(unsigned,unsigned,u16,u16);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
int func_02185AC8(char *p);
void func_02185B74(char *p);
int func_02185C84(unsigned key,unsigned optional,void *first,void *second,unsigned heap);

int func_02185AC8(char *p)
{
    Vec position,target,direction;
    long distance;
    int done;
    done=0;
    func_02048AE8(((struct Obj02935 *)p)->fC36C,&position);
    func_02048B30(((struct Obj02935 *)p)->fC36C,&target);
    func_0207CA00(&position,&target,&direction);
    distance=func_0207CBD0(&direction);
    func_0207CCA4(&direction,&direction);
    switch(((struct Obj02935 *)p)->fC30C) {
    case 1:
        if(distance>360448) {
            distance-=32768;
            ((struct Obj02935 *)p)->fC300-=128;
            ((struct Obj02935 *)p)->fC304=((struct Obj02935 *)p)->fC300;
        } else {distance=327680;done=1;}
        break;
    case 0:
        if(distance<1179648) {
            distance+=32768;
            ((struct Obj02935 *)p)->fC300+=128;
            ((struct Obj02935 *)p)->fC304=((struct Obj02935 *)p)->fC300;
        } else {distance=1212416;done=1;}
        break;
    }
    func_0207CEE4(distance,&direction,&target,&position);
    func_02048AFC(((struct Obj02935 *)p)->fC36C,&position);
    return done;
}


void func_02185B74(char *p)
{
    int state = *(int *)(p + 0xC310);

    switch (state) {
    case 0:
        break;
    case 2:
        func_02047964();
        func_02047970();
        *(int *)(p + 0xC310) = 0;
        break;
    case 1: {
        M33 m;
        Pair s;
        M33 m2;
        Pair s2;
        u32 i;

        func_02048C58(*(void **)(p + 0xC370));
        func_02048AD0(*(void **)(p + 0xC36C));
        func_02047964();
        func_020479D8();
        s.a = *(V3 *)(p + 0xC2DC);
        func_0207ADC4(&m);
        s.b = *(V3 *)(p + 0xC300);
        func_02047A60((void *)(*(u32 *)(p + 0xC3B8)), (struct Arg *)(&s));
        s.b = *(V3 *)(p + 0xC2E8);
        func_02185848(&m, p + 0xC2F4);
        func_02047A60((void *)(*(u32 *)(p + 0xC3A4)), (struct Arg *)(&s));
        s2.a = *(V3 *)(p + 0xC2DC);
        s2.b = *(V3 *)(p + 0xC300);
        for (i = 0; i < *(u32 *)(p + 0x14); i++) {
            u16 f;
            func_0207B388(p + 0x1c + i * 0x30, &m, &m2);
            f = *(u16 *)(p + i * 0x30 + 0x40);
            if (f != 0)
                func_02047A60((void *)(*(u32 *)(p + f * 4 + 0xC3A8)), (struct Arg *)(&s2));
        }
        func_02047970();
        break;
    }
    }
}

/*
 * prototype: caller explicitly truncatesB5B38 member/heap at secondsite; useu16extern for those observed narrow inputs.4790 is tailstubto02025B3C readingonlykey.
 */
int func_02185C84(unsigned key,unsigned optional,void *first,void *second,unsigned heap)
{
    unsigned index;
    void *bank;
    int found;
    index=func_02184790(key);
    found=0;
    bank=func_02045B38(0,2,231,heap);
    func_02045CAC(bank,key,first);
    func_02045C04(bank);
    if(index==0) {index=1;optional=0;}
    else found=1;
    bank=func_02045B38(0,2,func_02025BA0(index),heap);
    func_02045CAC(bank,optional,second);
    func_02045C04(bank);
    return found;
}
