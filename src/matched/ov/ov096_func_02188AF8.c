/*
 * function: func_02188AF8
 * address: 0x02188AF8
 * packet: pkt_ov096_02188AF8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 */
struct Cursor; extern unsigned int func_0201134C(struct Cursor *); extern int func_0218A0F4(unsigned char *,int,int,int,int);
int func_02188AF8(struct Cursor *a, unsigned char *b, int c) { int x,y; x=func_0201134C(a); y=func_0201134C(a); return func_0218A0F4((unsigned char *)a,c,*(unsigned short *)(b+2),x,y); }
