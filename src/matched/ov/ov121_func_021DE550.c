/*
 * function: func_021DE550
 * address: 0x021DE550
 * packet: pkt_ov121_021DE550
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020103E4 0x020103E4 thumb
 *   func_021DE308 0x021DE308 thumb ov121
 *   func_0200FBA0 0x0200FBA0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020103E4(u8 *);
extern void func_021DE308(char *,unsigned);
extern void func_0200FBA0(void);
void func_021DE550(char *p) {if(*(u8 **)(p+16)) {func_020103E4(*(u8 **)(p+16)); *(int *)(p+16)=0;} func_021DE308(p,0); func_0200FBA0();}
