/*
 * unit: yes
 * function: func_02188F2C, func_02188F50
 * address: 0x02188F2C
 * packet: pkt_ov096_02188F2C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A220 0x0218A220 thumb ov096
 */
struct Cursor; extern unsigned int func_0201134C(struct Cursor *); extern unsigned char func_0218A160(unsigned char *,int); extern int func_0218A220(int,int,int);
int func_02188F2C(struct Cursor *a,unsigned char *b) { int k; k=func_0201134C(a); *(int *)(b+0x38)=func_0218A220((int)b,k,func_0218A160(b,k)); return *(int *)(b+0xC4); }
int func_02188F50(int a, unsigned char *b) { return *(int *)(b+0xC4); }
