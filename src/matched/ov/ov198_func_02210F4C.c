/*
 * function: func_02210F4C
 * address: 0x02210F4C
 * packet: pkt_ov198_02210F4C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02210EFC 0x02210EFC thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_022110D4(u8 *,int),func_02210EFC(char **);
int func_02210F4C(u8 *p,int i) { u32 v;v=func_022110D4(p,i);if(func_02210EFC((char **)p)==1) {if(v==0 || v==3)return 1;return 0;}else {if(v<(*(u8 **)p)[34])return 1;return 0;} }
