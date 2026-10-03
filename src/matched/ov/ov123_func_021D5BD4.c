/*
 * function: func_021D5BD4
 * address: 0x021D5BD4
 * packet: pkt_ov123_021D5BD4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C5928 0x021C5928 arm ov114
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021D5AC0 0x021D5AC0 thumb ov123
 *   func_021D5BA8 0x021D5BA8 thumb ov123
 *   d_021DAA58 0x021DAA58 data a1
 *   d_021DAA60 0x021DAA60 data a1
 */
extern char d_021DAA58[],d_021DAA60[];
extern void func_021D5AC0(void);
extern int func_021D5BA8(char *);
extern int func_021C5928(void *,char *,char *);
extern void func_02156DE0(void *,void *);
int func_021D5BD4(char *p){*(int *)(p+0xb0)=0;if(!func_021C5928(func_021D5AC0,d_021DAA58,d_021DAA60))return 0;func_02156DE0(func_021D5BA8,p);return 1;}
