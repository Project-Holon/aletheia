/*
 * function: func_021D6198
 * address: 0x021D6198
 * packet: pkt_ov115_021D6198
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D61B8 0x021D61B8 thumb ov115
 */
typedef unsigned char u8;typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void);extern void func_021D6134(void *,void (*)(u8 *),int);extern void func_021D61B8(u8 *);
void func_021D6198(u8 *p) { if(WIPE_SYS_EndCheck())func_021D6134(p,func_021D61B8,0x169); }
