/*
 * function: ZUKAN_DETAIL_PROCSYS_RunStateCallbacks
 * address: 0x021BC274
 * packet: pkt_ov208_021BC274
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero alignment bytes at 0x021BC2EE before 0x021BC2F0.
 */
struct State;
typedef int (*Callback)(struct State *,int *,int,int,int);
struct State { Callback *callbacks; int state,counter,a,b; };
int ZUKAN_DETAIL_PROCSYS_RunStateCallbacks(struct State *p,int arg)
{
    int result=1;
    switch(p->state) {
    case 0:
        if(p->callbacks[0]) result=p->callbacks[0](p,&p->counter,p->a,p->b,arg);
        if(result==1) { p->state=1; p->counter=0; }
        break;
    case 1:
        if(p->callbacks[1]) result=p->callbacks[1](p,&p->counter,p->a,p->b,arg);
        if(result==1) { p->state=2; p->counter=0; }
        break;
    case 2:
        if(p->callbacks[2]) result=p->callbacks[2](p,&p->counter,p->a,p->b,arg);
        if(result==1) return 1;
        break;
    }
    return 0;
}
