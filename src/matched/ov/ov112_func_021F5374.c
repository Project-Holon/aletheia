/*
 * function: func_021F5374
 * address: 0x021F5374
 * packet: pkt_ov112_021F5374
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F62EC 0x021F62EC thumb ov112
 *   func_021F62DC 0x021F62DC thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F62EC(int);
extern void func_021F62DC(int);
void func_021F5374(int *p,int b) { if(b==1)func_021F62EC(p[2]); else func_021F62DC(p[2]); }
