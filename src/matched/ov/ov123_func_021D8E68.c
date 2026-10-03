/*
 * function: func_021D8E68
 * address: 0x021D8E68
 * packet: pkt_ov123_021D8E68
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D62A8 0x021D62A8 thumb ov123
 *   func_021D651C 0x021D651C thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8E28 0x021D8E28 thumb ov123
 */
extern void func_021D62A8(void *);
extern void func_021D651C(unsigned char *);
extern void func_021D6EE0(char *,int,int);
extern void func_021D8E28(void);
void func_021D8E68(char *p) { if(--*(int *)(p+0x60)==0) { func_021D62A8(*(void **)(p+0x14)); func_021D651C(*(void **)(p+0x14)); *(int *)(p+0x60)=70; func_021D6EE0(p,(int)func_021D8E28,0x9e4); } }
