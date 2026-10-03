/*
 * function: func_021C58C8
 * address: 0x021C58C8
 * packet: pkt_ov127_021C58C8
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C58B8 0x021C58B8 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C58B8(char *);
char *func_021C58C8(u8 *p) { int i,offset; for(i=0;i<*(u16 *)(p+8);i++) { offset=i*20; if(func_021C58B8(*(char **)(p+4)+offset)==1) return *(char **)(p+4)+offset; } return 0; }
