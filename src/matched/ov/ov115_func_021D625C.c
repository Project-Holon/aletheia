/*
 * function: func_021D625C
 * address: 0x021D625C
 * packet: pkt_ov115_021D625C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D6274 0x021D6274 thumb ov115
 */
typedef unsigned char u8;typedef unsigned int u32;
extern void func_021D6134(void *,void (*)(u8 *),int),func_021D6274(u8 *);
void func_021D625C(u8 *p) { if(*(u32 *)(p+24))func_021D6134(p,func_021D6274,0x1d8); }
