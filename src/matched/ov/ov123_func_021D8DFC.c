/*
 * function: func_021D8DFC
 * address: 0x021D8DFC
 * packet: pkt_ov123_021D8DFC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8D98 0x021D8D98 thumb ov123
 */
extern void func_021D62B4(void *,int);
extern void func_021D6EE0(char *,int,int);
extern void func_021D8D98(void);
void func_021D8DFC(char *p) { if(--*(int *)(p+0x60)==0) { func_021D62B4(*(void **)(p+0x14),4); *(int *)(p+0x60)=60; func_021D6EE0(p,(int)func_021D8D98,0x9b9); } }
