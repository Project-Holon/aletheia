/*
 * function: func_021D6814
 * address: 0x021D6814
 * packet: pkt_ov125_021D6814
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D730C 0x021D730C thumb ov125
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D730C(char *);
int func_021D6814(char *p,int v) {if(!func_021D730C(p))return 0;*(u16 *)(p+0x3a4)=v;*(int *)(p+0x3d8)=0x5209;return 1;}
