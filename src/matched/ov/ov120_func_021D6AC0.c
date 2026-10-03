/*
 * function: func_021D6AC0
 * address: 0x021D6AC0
 * packet: pkt_ov120_021D6AC0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_0204B898(void *);
extern u32 func_0204B98C(void *);
int func_021D6AC0(u8 *p){if(!*(void **)(p+0x134))return 0;if((u32)func_0204B898(*(void **)(p+0x134))>=29){if(func_0204B98C(*(void **)(p+0x134))==0)return 1;return 0;}return 0;}
