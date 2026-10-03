/*
 * function: func_021DE220
 * address: 0x021DE220
 * packet: pkt_ov137_021DE220
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_02184180 0x02184180 thumb ov022
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021DCF50(void *);
extern char *func_02184180(u8 *,u8);
int func_021DE220(void *p) {int i,n;n=0;for(i=0;i<5;i++) if(func_02184180(func_021DCF50(p),i)) n++;return n;}
