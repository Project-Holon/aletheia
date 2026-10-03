/*
 * function: func_021D95B4
 * address: 0x021D95B4
 * packet: pkt_ov123_021D95B4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 58 compiled bytes followed by 2 bytes of zero alignment padding.
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0202EE8C 0x0202EE8C thumb
 */
extern void func_0202F038(void *);
extern unsigned char *func_0202EE8C(unsigned int,void *,unsigned char,unsigned char,unsigned short);
void func_021D95B4(char *p) { if(*(void **)(p+0x90)) { func_0202F038(*(void **)(p+0x90)); *(void **)(p+0x90)=0; } *(void **)(p+0x90)=func_0202EE8C(*(unsigned int *)(p+0x88),*(void **)(p+0x48),15,16,*(unsigned short *)(p+0xb0)); }
