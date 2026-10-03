/*
 * function: func_021DA0B8
 * address: 0x021DA0B8
 * packet: pkt_ov123_021DA0B8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Unsigned result-minus-two range test emits subs/cmp/bhi.
 * symbols:
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021D9514 0x021D9514 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021DA090 0x021DA090 thumb ov123
 */
extern int func_02012DD0(unsigned char *);
extern void func_021D9514(char *,int);
extern void func_021DA034(char *,int,int);
extern void func_021DA090(char *p);
void func_021DA0B8(char *p) { if((unsigned int)(func_02012DD0(*(void **)(p+0x20))-2)<=1) { *(int *)(p+0x6c)=0; func_021D9514(*(char **)(p+0x10),11); func_021DA034(p,(int)func_021DA090,0xfe); } }
