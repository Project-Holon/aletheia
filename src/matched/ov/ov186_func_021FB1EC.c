/*
 * function: func_021FB1EC
 * address: 0x021FB1EC
 * packet: pkt_ov186_021FB1EC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021FB2EE..021FB2F0 is two zero alignment bytes.
 * lever: capture from in the s16 value before the named divider, keeping its load live across the helper.
 * symbols:
 *   func_021FAEE4 0x021FAEE4 thumb ov186
 *   func_021FB548 0x021FB548 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 *   func_021FADB8 0x021FADB8 thumb ov186
 *   _s32_div_f 0x0209C0A4 arm
 */
typedef signed short s16;
typedef struct { char pad[8];void *obj;char padC[12];int target;unsigned state;s16 from,to,tick,duration; } Ctx;
extern void func_021FAEE4(char *p, int *out);
extern void func_021FB548(char *p, short *x, short *y);
extern void func_021FB514(char *p, short x, int y);
extern void func_021FADB8(char *,int);
extern int _s32_div_f(int,int);
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

