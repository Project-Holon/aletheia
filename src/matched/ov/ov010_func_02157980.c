/*
 * function: DELIVERY_IRC_RecvRequest
 * address: 0x02157980
 * packet: pkt_ov010_02157980
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov010/script_work_p01.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 a, b; } V;
typedef struct { u8 pad[0x67c]; V v; } D_02157980;
void DELIVERY_IRC_RecvRequest(int x, int y, const V *s, D_02157980 *d);

void DELIVERY_IRC_RecvRequest(int x, int y, const V *s, D_02157980 *d) { d->v = *s; }
