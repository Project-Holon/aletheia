/*
 * function: DELIVERY_IRC_RecvNotFound
 * address: 0x02157998
 * packet: pkt_ov010_02157998
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
typedef struct { u8 pad[0x66c]; u32 w; } D_02157998;
void DELIVERY_IRC_RecvNotFound(int x, int y, u32 *s, D_02157998 *d);

void DELIVERY_IRC_RecvNotFound(int x, int y, u32 *s, D_02157998 *d) { d->w = *s; }
