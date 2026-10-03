/*
 * function: func_021E7D04
 * address: 0x021E7D04
 * packet: pkt_ov170_021E7D04
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E95F8 0x021E95F8 thumb ov170
 *   func_021E96E8 0x021E96E8 thumb ov170
 *   func_021E9848 0x021E9848 thumb ov170
 *   func_021E22B8 0x021E22B8 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021E95F8(u8 *);
extern int func_021E96E8(u8 *);
extern int func_021E9848(u8 *);
extern int func_021E22B8(int);
int func_021E7D04(u8 *p){switch(*(int *)(*(char **)p+0x24)){case 2:*(int *)(*(char **)(p+0x2c)+0xa198)=func_021E95F8(p);break;case 3:*(int *)(*(char **)(p+0x2c)+0xa198)=func_021E96E8(p);break;case 4:*(int *)(*(char **)(p+0x2c)+0xa198)=func_021E9848(p);break;}return func_021E22B8((int)p);}
