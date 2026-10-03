/*
 * function: func_021C15C0
 * address: 0x021C15C0
 * packet: pkt_ov099_021C15C0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte alignment padding.
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_021BF03C 0x021BF03C thumb ov099
 *   func_020362DC 0x020362DC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(void *);
extern int func_021BF03C(char *);
extern u32 func_020362DC(void);
int func_021C15C0(char *p,int ret){if(!func_021BA928(p))return ret;if(func_021BF03C(p))*(int *)(p+0x1cc)=48;if(func_020362DC()&3)*(int *)(p+0x1cc)=48;return ret;}
