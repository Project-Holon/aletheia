/*
 * function: MYSTERY_NET_Step
 * address: 0x021DE300
 * packet: pkt_ov121_021DE300
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_NET_Dispatch 0x021DEE90 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MYSTERY_NET_Dispatch(char *);
void MYSTERY_NET_Step(char *p) {MYSTERY_NET_Dispatch(p);}
