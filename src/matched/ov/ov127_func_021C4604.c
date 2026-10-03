/*
 * function: func_021C4604
 * address: 0x021C4604
 * packet: pkt_ov127_021C4604
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4790 0x021C4790 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021C4790(char *);
void *func_021C4604(u8 *p) { u32 i; for(i=0;i<*(u32 *)(p+12);i++) { if(func_021C4790(*(char **)(p+8)+i*24)==1) return *(char **)(p+8)+i*24; } return 0; }
