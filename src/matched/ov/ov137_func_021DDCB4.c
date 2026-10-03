/*
 * function: func_021DDCB4
 * address: 0x021DDCB4
 * packet: pkt_ov137_021DDCB4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DD924(void *);
extern u16 func_02039338(void);
extern void *func_021DCF50(void *);
extern int func_021841A4(u8 *);
int func_021DDCB4(char *p,int state) {if(func_02039338()==0)func_021841A4(func_021DCF50(p));if(*(int *)(*(char **)(p+16)+32)==func_021841A4(func_021DCF50(p))) *(int *)(p+280)=27;return state;}
