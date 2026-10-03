/*
 * function: func_021D7430
 * address: 0x021D7430
 * packet: pkt_ov123_021D7430
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_02012DD0 0x02012DD0 thumb
 *   func_020056EC 0x020056EC thumb
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D73D8 0x021D73D8 thumb ov123
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D66D0(u8 *,int);
extern int func_02012DD0(void *);
extern int func_020056EC(int);
extern void func_021D6EE0(char *,int,int);
extern void func_021D73D8(void);
void func_021D7430(u8 *p) { if(*(int *)(p+112)<100) ++*(int *)(p+112); func_021D66D0(*(u8 **)(p+20),*(int *)(p+112)); if(func_02012DD0(*(void **)(p+44))==1) { *(int *)(p+120)=func_020056EC(190); func_021D6EE0((char *)p,(int)func_021D73D8,0x2e6); } }
