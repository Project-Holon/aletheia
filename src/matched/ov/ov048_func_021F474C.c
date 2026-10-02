/*
 * function: func_021F474C
 * address: 0x021F474C
 * packet: pkt_ov048_021F474C
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201D83C 0x0201D83C thumb
 *   func_021F4B40 0x021F4B40 thumb ov048
 *   func_020307B0 0x020307B0 arm
 */
extern void func_0201D83C(unsigned int p);
extern void func_021F4B40(int *p);
extern void func_020307B0(void *p);
void func_021F474C(unsigned char *p) { int i; func_0201D83C(*(unsigned int *)(p+20)); for(i=0;i<p[2];i++) func_021F4B40(((int **)*(void **)(p+8))[i]); func_020307B0(*(void **)(p+8)); func_020307B0(*(void **)(p+12)); func_020307B0(p); }
