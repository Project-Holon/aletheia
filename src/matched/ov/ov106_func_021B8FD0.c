/*
 * function: IRC_RANKING_InertiaUpdate
 * address: 0x021B8FD0
 * packet: pkt_ov106_021B8FD0
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   _ll_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int a,b,v,dirty; } State;
void IRC_RANKING_InertiaUpdate(State *p) { if(p->dirty) { p->dirty=0; p->v=p->a+p->b/2; p->v=(int)(((long long)p->v*163840+2048)>>12); } }
