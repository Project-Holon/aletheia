/*
 * function: func_021BDC88
 * address: 0x021BDC88
 * packet: pkt_ov203_021BDC88
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_020362DC 0x020362DC arm
 */
extern unsigned func_020221A4(void);
extern unsigned func_020362DC(void);
int func_021BDC88(char *p){if(*(int *)(*(char **)(p+4)+20)!=0||!func_020221A4())return 0;if(*(int *)(*(char **)(p+28)+20)!=0){if(func_020362DC()&0xcf3)return 1;}return 0;}
