/*
 * function: func_021DD0E8
 * address: 0x021DD0E8
 * packet: pkt_ov171_021DD0E8
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE388 0x021DE388 thumb ov171
 *   func_021DD964 0x021DD964 thumb ov171
 *   func_021DDAF0 0x021DDAF0 thumb ov171
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DE388(char *p);
extern void func_021DD964(u8*);
extern void func_021DDAF0(u8*);
int func_021DD0E8(u8*p){p[0xc5c]=0;func_021DE388((char *)p);func_021DD964(p);func_021DDAF0(p);return 4;}
