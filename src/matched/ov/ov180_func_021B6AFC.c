/*
 * function: func_021B6AFC,func_021B6B18
 * address: 0x021B6AFC
 * packet: pkt_ov180_021B6AFC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern unsigned func_020221A4(void);
int func_021B6AFC(char *p){if(func_020221A4()==1)return *(int *)(p+37268);return 2;}
int func_021B6B18(char *p){if(*(int *)(p+37256)==0)return *(int *)(p+37268);*(int *)(p+37256)-=1;return 3;}
