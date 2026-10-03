/*
 * function: func_02188C88
 * address: 0x02188C88
 * packet: pkt_ov096_02188C88
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C8138 0x021C8138 thumb ov093
 */
struct Q7; extern unsigned short func_021C8138(struct Q7 *);
int func_02188C88(int a, unsigned char *b) { *(int *)(b+0x38)=func_021C8138(*(struct Q7 **)(b+0xB4)); return *(int *)(b+0xC4); }
