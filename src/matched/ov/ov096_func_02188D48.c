/*
 * function: func_02188D48
 * address: 0x02188D48
 * packet: pkt_ov096_02188D48
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C1D8 0x0201C1D8 thumb
 */
extern unsigned short func_0201C1D8(int);
int func_02188D48(int a, unsigned char *b) { *(int *)(b+0x38)=func_0201C1D8(*(unsigned short *)(b+2)); return *(int *)(b+0xC4); }
