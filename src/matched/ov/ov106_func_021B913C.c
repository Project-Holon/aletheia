/*
 * function: func_021B913C
 * address: 0x021B913C
 * packet: pkt_ov106_021B913C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _ll_mul 0x0209C054 arm
 */
typedef struct { int a,b,v,d; signed char direction; } State;
int func_021B913C(State *p) {
 int v=p->v*p->direction;
 if(v>32768) v=32768; else if(v< -32768) v= -32768;
 p->v -= (int)(((long long)p->v*205+2048)>>12);
 if(p->v> -4096 && p->v<4096) p->v=0;
 return (short)(v>>12);
}
