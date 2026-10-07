/*
 * file:     br_btn_p06.c
 * unit:     yes
 * function: func_021FAEC0, func_021FAEE4, func_021FAF08, func_021FAF24, func_021FAFA0, func_021FAFB0, func_021FAFC0, func_021FAFCC, func_021FAFD0, func_021FB058, func_021FB0E8
 * address:  0x021FAEC0
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 *   func_021FB548 0x021FB548 thumb ov186
 *   func_02034714 0x02034714 arm
 *   d_02200D18 0x02200D18 data a1
 *   func_021FB578  0x021FB578  thumb  ov186
 *   func_021FB5A0  0x021FB5A0  thumb  ov186
 *   func_021FB5C4 0x021FB5C4 thumb ov186
 *   func_021FADB8 0x021FADB8 thumb ov186
 *   _s32_div_f 0x0209C0A4 arm
 */
#include "../../matched/include/Obj14454.h"
#include "../../matched/include/Obj24819.h"
#include "../../matched/include/Obj14455.h"
#include "../../matched/include/Obj02900.h"
#include "../../matched/include/Obj24822.h"
#include "../../matched/include/Obj24823.h"
#include "../../matched/include/Obj01280.h"
#include "../../matched/include/Obj01281.h"

typedef unsigned int   u32;

typedef struct {
    char  pad_00[8];
    void *f8;
} T;

typedef signed short s16;

typedef struct { char pad[8];void *obj;char padC[12];int target;unsigned state;s16 from,to,tick,duration; } Ctx;

extern int func_021FB7B0(void *p, int i);
extern void func_021FB514(char *p, short x, int y);
extern void func_021FB548(char *p, short *x, short *y);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_021FB578(void *, unsigned char);
extern int func_021FB5A0(void *, unsigned char);
extern void func_021FB5C4(char *p, int n);
extern void func_021FADB8(char *,int);
extern int _s32_div_f(int,int);
void func_021FAEC0(char *p,unsigned index);
void func_021FAEE4(char *p,int *out);
void func_021FAF08(char *p, int a1);
int func_021FAF24(char *ctx, int kind);
int func_021FAFA0(T *p, int b);
int func_021FAFB0(T *p, int b);
void func_021FAFC0(char *p, unsigned value);
void func_021FAFCC(char *p, unsigned value);
int func_021FAFD0(char *ctx);
int func_021FB058(char *ctx);
int func_021FB0E8(Ctx *p);
extern char d_02200D18[];

void func_021FAEC0(char *p,unsigned index) { short x=(short)func_021FB7B0((void *)(((struct Obj14454 *)p)->fC),0);func_021FB514(((struct Obj14454 *)p)->f8,x,(short)(169-(index<<4))); }

void func_021FAEE4(char *p,int *out) { short x,y;func_021FB548(((struct Obj24819 *)p)->f8,&x,&y);out[0]=x;out[1]=y; }


void func_021FAF08(char *p, int a1)
{
    short r = (short)func_021FB7B0((void *)(((struct Obj14455 *)p)->fC), 0);

    func_021FB514(((struct Obj14455 *)p)->f8, r, a1);
}

int func_021FAF24(char *ctx, int kind)
{
    int result;
    switch (kind) {
    case 0: result = func_021FB7B0((void *)(((struct Obj02900 *)ctx)->fC), 5); break;
    case 1: result = func_021FB7B0((void *)(((struct Obj02900 *)ctx)->fC), 6); break;
    case 2: result = func_021FB7B0((void *)(((struct Obj02900 *)ctx)->fC), 7); break;
    case 5: result = func_021FB7B0((void *)(((struct Obj02900 *)ctx)->fC), 9); break;
    case 6: result = func_021FB7B0((void *)(((struct Obj02900 *)ctx)->fC), 10); break;
    case 3: result = func_021FB7B0((void *)(((struct Obj02900 *)ctx)->fC), 8); break;
    case 4: result = func_021FB7B0((void *)(((struct Obj02900 *)ctx)->fC), 2); break;
    case 7: result = func_021FB7B0((void *)(((struct Obj02900 *)ctx)->fC), 11); break;
    case 8: result = func_021FB7B0((void *)(((struct Obj02900 *)ctx)->fC), 0); break;
    case 9: result = func_021FB7B0((void *)(((struct Obj02900 *)ctx)->fC), 1); break;
    default: result = 0; func_02034714(d_02200D18, 0, d_02200D18); break;
    }
    return result;
}


int func_021FAFA0(T *p, int b)
{
    return func_021FB578(p->f8, (unsigned char)b);
}


int func_021FAFB0(T *p, int b)
{
    return func_021FB5A0(p->f8, (unsigned char)b);
}

void func_021FAFC0(char *p, unsigned value) { func_021FB5C4(((struct Obj24822 *)p)->f8,value); }

void func_021FAFCC(char *p, unsigned value) { ((struct Obj24823 *)p)->f2C = value; }

/*
 * tail: 021FB056..021FB058 is two zero alignment bytes.
 */
int func_021FAFD0(char *ctx)
{
    int position[2];
    short x;
    short value;
    switch (((struct Obj01280 *)ctx)->f1C) {
    case 0:
        func_021FAEE4(ctx, position);
        ((struct Obj01280 *)ctx)->f20 = position[1];
        ((struct Obj01280 *)ctx)->f22 = ((struct Obj01280 *)ctx)->f18;
        ((struct Obj01280 *)ctx)->f24 = 0;
        ((struct Obj01280 *)ctx)->f26 = 10;
        ((struct Obj01280 *)ctx)->f1C = 1;
        break;
    case 1:
        value = ((struct Obj01280 *)ctx)->f20 + ((((struct Obj01280 *)ctx)->f22 - ((struct Obj01280 *)ctx)->f20) * ((struct Obj01280 *)ctx)->f24) / ((struct Obj01280 *)ctx)->f26;
        func_021FB548(((struct Obj01280 *)ctx)->f8, &x, 0);
        func_021FB514(((struct Obj01280 *)ctx)->f8, x, value);
        if ((((struct Obj01280 *)ctx)->f24)++ >= ((struct Obj01280 *)ctx)->f26) ((struct Obj01280 *)ctx)->f1C = 2;
        break;
    case 2: return 1;
    }
    return 0;
}

/*
 * tail: 021FB0E6..021FB0E8 is two zero alignment bytes.
 * lever: load position[1] to a local before the target and step stores.
 */
int func_021FB058(char *ctx)
{
    int position[2];
    short x;
    short value;
    int target;
    int start;
    switch (((struct Obj01281 *)ctx)->f1C) {
    case 0:
        func_021FAEE4(ctx, position);
        target = func_021FB7B0(((struct Obj01281 *)ctx)->fC, 1);
        start = position[1];
        ((struct Obj01281 *)ctx)->f22 = target;
        ((struct Obj01281 *)ctx)->f24 = 0;
        ((struct Obj01281 *)ctx)->f20 = start;
        ((struct Obj01281 *)ctx)->f26 = 16;
        ((struct Obj01281 *)ctx)->f1C = 1;
        break;
    case 1:
        value = ((struct Obj01281 *)ctx)->f20 + ((((struct Obj01281 *)ctx)->f22 - ((struct Obj01281 *)ctx)->f20) * ((struct Obj01281 *)ctx)->f24) / ((struct Obj01281 *)ctx)->f26;
        func_021FB548(((struct Obj01281 *)ctx)->f8, &x, 0);
        func_021FB514(((struct Obj01281 *)ctx)->f8, x, value);
        if ((((struct Obj01281 *)ctx)->f24)++ >= ((struct Obj01281 *)ctx)->f26) ((struct Obj01281 *)ctx)->f1C = 2;
        break;
    case 2: return 1;
    }
    return 0;
}

int func_021FB0E8(Ctx *p)
{
    s16 y,x;
    switch(p->state) {
    case 0: {
        int position[2];
        func_021FAEE4((char *)p,position);
        p->from=position[1];p->to=-32;p->tick=0;p->duration=14;p->state=1;
        break;
    }
    case 1: {
        s16 value;
        value=p->from;
        value=value+_s32_div_f((p->to-value)*p->tick,p->duration);
        func_021FB548(p->obj,&y,0);
        func_021FB514(p->obj,y,value);
        if(p->tick++>=p->duration)p->state=2;
        break;
    }
    case 2:func_021FADB8((char *)p,0);p->state=3;break;
    case 3: {
        int position[2];
        func_021FAEE4((char *)p,position);
        p->from=position[1];p->to=p->target;p->tick=0;p->duration=14;p->state=4;
        break;
    }
    case 4: {
        s16 value;
        value=p->from;
        value=value+_s32_div_f((p->to-value)*p->tick,p->duration);
        func_021FB548(p->obj,&x,0);
        func_021FB514(p->obj,x,value);
        if(p->tick++>=p->duration)p->state=5;
        break;
    }
    case 5:return 1;
    }
    return 0;
}
