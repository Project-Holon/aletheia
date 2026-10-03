/*
 * function: func_021D6294
 * address: 0x021D6294
 * packet: pkt_ov115_021D6294
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D62B4 0x021D62B4 thumb ov115
 */
typedef unsigned char u8;typedef unsigned int u32;
extern int func_021D5C70(void *);extern void func_021D6134(void *,void (*)(u8 *),int),func_021D62B4(u8 *);
void func_021D6294(u8 *p) { if(func_021D5C70(*(void **)(p+8)))func_021D6134(p,func_021D62B4,0x1f4); }
