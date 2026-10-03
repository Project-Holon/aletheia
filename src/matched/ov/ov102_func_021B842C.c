/*
 * function: func_021B842C
 * address: 0x021B842C
 * packet: pkt_ov102_021B842C
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7CB0 0x021B7CB0 thumb ov102
 *   func_021B7DC4 0x021B7DC4 thumb ov102
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   func_021B78E4 0x021B78E4 thumb ov102
 */
extern void func_021B7CB0(unsigned char *); extern int func_021B7DC4(unsigned char *,unsigned char *); extern void func_021B71E4(int); extern void func_021B78E4(void *);
void func_021B842C(unsigned char *p) { func_021B7CB0(p+0x9c); func_021B7DC4(p+0xac,p+0x9c); func_021B7DC4(p+0x46c,p+0x9c); func_021B71E4(*(int *)(p+0x468)); func_021B78E4(p); }
