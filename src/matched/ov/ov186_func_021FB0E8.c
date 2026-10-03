/*
 * function: func_021FB0E8
 * address: 0x021FB0E8
 * packet: pkt_ov186_021FB0E8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
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
extern void func_021FAEE4(void *,int *);
extern void func_021FB548(void *,s16 *,s16 *);
extern void func_021FB514(void *,s16,int);
extern void func_021FADB8(char *,int);
extern int _s32_div_f(int,int);
int func_021FB0E8(Ctx *p)
{
    s16 y,x;
    switch(p->state) {
    case 0: {
        int position[2];
        func_021FAEE4(p,position);
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
        func_021FAEE4(p,position);
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
