/*
 * function: BR_BTN_AnimFlyOut
 * address: 0x021FB0E8
 * packet: pkt_ov186_021FB0E8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: capture from in the s16 value before the named divider, keeping its load live across the helper.
 * symbols:
 *   BR_BTN_GetPos 0x021FAEE4 thumb ov186
 *   BR_BTN_GetObjectPos 0x021FB548 thumb ov186
 *   BR_BTN_SetObjectPos 0x021FB514 thumb ov186
 *   BR_BTN_SetMode 0x021FADB8 thumb ov186
 *   _s32_div_f 0x0209C0A4 arm
 */
typedef signed short s16;
typedef struct { char pad[8];void *obj;char padC[12];int target;unsigned state;s16 from,to,tick,duration; } Ctx;
extern void BR_BTN_GetPos(char *p, int *out);
extern void BR_BTN_GetObjectPos(char *p, short *x, short *y);
extern void BR_BTN_SetObjectPos(char *p, short x, int y);
extern void BR_BTN_SetMode(char *,int);
extern int _s32_div_f(int,int);
int BR_BTN_AnimFlyOut(Ctx *p)
{
    s16 y,x;
    switch(p->state) {
    case 0: {
        int position[2];
        BR_BTN_GetPos((char *)p,position);
        p->from=position[1];p->to=-32;p->tick=0;p->duration=14;p->state=1;
        break;
    }
    case 1: {
        s16 value;
        value=p->from;
        value=value+_s32_div_f((p->to-value)*p->tick,p->duration);
        BR_BTN_GetObjectPos(p->obj,&y,0);
        BR_BTN_SetObjectPos(p->obj,y,value);
        if(p->tick++>=p->duration)p->state=2;
        break;
    }
    case 2:BR_BTN_SetMode((char *)p,0);p->state=3;break;
    case 3: {
        int position[2];
        BR_BTN_GetPos((char *)p,position);
        p->from=position[1];p->to=p->target;p->tick=0;p->duration=14;p->state=4;
        break;
    }
    case 4: {
        s16 value;
        value=p->from;
        value=value+_s32_div_f((p->to-value)*p->tick,p->duration);
        BR_BTN_GetObjectPos(p->obj,&x,0);
        BR_BTN_SetObjectPos(p->obj,x,value);
        if(p->tick++>=p->duration)p->state=5;
        break;
    }
    case 5:return 1;
    }
    return 0;
}
