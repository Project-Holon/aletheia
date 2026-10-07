/*
 * file:     br_btn_p07.c
 * unit:     yes
 * function: func_021FB1EC, func_021FB2F0
 * address:  0x021FB1EC
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
 *   func_021FAEE4 0x021FAEE4 thumb ov186
 *   func_021FB548 0x021FB548 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 *   func_021FADB8 0x021FADB8 thumb ov186
 *   _s32_div_f 0x0209C0A4 arm
 */
#include "../../matched/include/Obj01282.h"

typedef signed short s16;

typedef struct { char pad[8];void *obj;char padC[12];int target;unsigned state;s16 from,to,tick,duration; } Ctx;

extern void func_021FAEE4(char *p, int *out);
extern void func_021FB548(char *p, short *x, short *y);
extern void func_021FB514(char *p, short x, int y);
extern void func_021FADB8(char *,int);
extern int _s32_div_f(int,int);
int func_021FB1EC(Ctx *p);
int func_021FB2F0(char *ctx);

/*
 * tail: 021FB2EE..021FB2F0 is two zero alignment bytes.
 * lever: capture from in the s16 value before the named divider, keeping its load live across the helper.
 */
int func_021FB1EC(Ctx *p)
{
    s16 y,x;
    switch(p->state) {
    case 0: {
        int position[2];
        func_021FAEE4((char *)p,position);
        p->from=position[1];p->to=224;p->tick=0;p->duration=14;p->state=1;
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
    case 2:func_021FADB8((char *)p,1);p->state=3;break;
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

int func_021FB2F0(char *ctx)
{
    int position[2];
    short x;
    short value;
    switch (((struct Obj01282 *)ctx)->f1C) {
    case 0:
        func_021FAEE4(ctx, position);
        ((struct Obj01282 *)ctx)->f20 = position[1];
        ((struct Obj01282 *)ctx)->f22 = ((struct Obj01282 *)ctx)->f18;
        ((struct Obj01282 *)ctx)->f24 = 0;
        ((struct Obj01282 *)ctx)->f26 = 26;
        ((struct Obj01282 *)ctx)->f1C = 1;
        break;
    case 1:
        value = ((struct Obj01282 *)ctx)->f20 + ((((struct Obj01282 *)ctx)->f22 - ((struct Obj01282 *)ctx)->f20) * ((struct Obj01282 *)ctx)->f24) / ((struct Obj01282 *)ctx)->f26;
        func_021FB548(((struct Obj01282 *)ctx)->f8, &x, 0);
        func_021FB514(((struct Obj01282 *)ctx)->f8, x, value);
        if ((((struct Obj01282 *)ctx)->f24)++ >= ((struct Obj01282 *)ctx)->f26) ((struct Obj01282 *)ctx)->f1C = 2;
        break;
    case 2: return 1;
    }
    return 0;
}
