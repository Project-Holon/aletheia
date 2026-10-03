/*
 * function: func_021D6A10
 * address: 0x021D6A10
 * packet: pkt_ov116_021D6A10
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Remaining extent: existing matched accessor files at 021D6A40 and 021D6A44.
 * symbols:
 *   func_021D70EC 0x021D70EC thumb ov116
 *   func_021D7158 0x021D7158 thumb ov116
 */
extern int func_021D70EC(unsigned char *,int *);
extern int func_021D7158(void *);
int func_021D6A10(unsigned char *a,unsigned char *b) { int result; if(*(int *)(a+4)) return 1; if(func_021D70EC(b,&result) && func_021D7158(b)==0) { *(int *)(a+4)=1; return 1; } return 0; }
