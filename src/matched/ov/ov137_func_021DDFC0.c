/*
 * function: func_021DDFC0
 * address: 0x021DDFC0
 * packet: pkt_ov137_021DDFC0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_021DD924 0x021DD924 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021DCF50(void *);
extern int func_021841A4(u8 *);
extern void func_021DD924(char *);
int func_021DDFC0(char *p,int state) {if(*(u32 *)(p+0x481c)){if(*(u32 *)(p+0x481c)!=(u32)func_021841A4(func_021DCF50(p))) *(u32 *)(p+0x481c)=0;}*(int *)(p+280)=21;*(int *)(p+292)=0;func_021DD924(p);return state;}
