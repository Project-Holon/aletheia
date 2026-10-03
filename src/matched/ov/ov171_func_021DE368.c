/*
 * function: func_021DE368
 * address: 0x021DE368
 * packet: pkt_ov171_021DE368
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE34C 0x021DE34C thumb ov171
 *   func_0204B1CC 0x0204B1CC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DE34C(char *,int);
extern void func_0204B1CC(void *);
void func_021DE368(char *p) { u32 i; for(i=0;i<16;i++) func_021DE34C(p,i); func_0204B1CC(*(void **)(p+0xb70)); }
