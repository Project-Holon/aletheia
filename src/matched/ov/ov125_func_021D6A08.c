/*
 * function: func_021D6A08
 * address: 0x021D6A08
 * packet: pkt_ov125_021D6A08
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
int func_021D6A08(char *p,int a,int b) {if(!func_021D730C(p))return 0;*(int *)(p+0x3a4)=a;*(int *)(p+0x3a8)=b;*(int *)(p+0x3d8)=0x55f3;return 1;}
