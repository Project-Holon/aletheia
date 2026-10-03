/*
 * function: func_021BD1A0
 * address: 0x021BD1A0
 * packet: pkt_ov209_021BD1A0
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD8C4 0x021BD8C4 thumb ov209
 *   func_021BE5D4 0x021BE5D4 thumb ov209
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bits {u16 low:1;u16 high:15;};
extern int func_021BD8C4(char *,unsigned);extern void func_021BE5D4(char *,int);
int func_021BD1A0(char *p) { if(func_021BD8C4(p,((struct Bits *)(p+0xc24))->high)==0){func_021BE5D4(p,0);return *(int *)(p+24);}return 6; }
