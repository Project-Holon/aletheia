/*
 * function: func_021D8E98
 * address: 0x021D8E98
 * packet: pkt_ov123_021D8E98
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020185F0 0x020185F0 thumb
 *   func_021D6458 0x021D6458 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8E68 0x021D8E68 thumb ov123
 */
extern int func_020185F0(void *);
extern void func_021D6458(unsigned char *,int,int);
extern void func_021D6EE0(char *,int,int);
extern void func_021D8E68(char *p);
void func_021D8E98(char *p) { func_021D6458(*(void **)(p+0x14),func_020185F0(*(void **)(p+0xc)),1); *(int *)(p+0x60)=10; func_021D6EE0(p,(int)func_021D8E68,0x9f6); }
