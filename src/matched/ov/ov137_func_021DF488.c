/*
 * function: func_021DF488
 * address: 0x021DF488
 * packet: pkt_ov137_021DF488
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E19A4 0x021E19A4 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021E19A4(void);
int func_021DF488(u8 *p) { if(*(int *)(p+12)<120) *(int *)(p+12)+=1; else if(!func_021E19A4()) { *(int *)(p+12)=0; *(int *)p=38; } return 0; }
