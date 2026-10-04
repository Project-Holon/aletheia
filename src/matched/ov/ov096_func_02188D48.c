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
typedef unsigned short u16;
extern u16 func_0201C1D8(void *p);
int func_02188D48(int a, unsigned char *b) { *(int *)(b+0x38)=func_0201C1D8((void *)(*(unsigned short *)(b+2))); return *(int *)(b+0xC4); }
