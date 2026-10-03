/*
 * function: func_021FF6B4
 * address: 0x021FF6B4
 * packet: pkt_ov186_021FF6B4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7414 0x021D7414 thumb ov125
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021D7414(char*,void*,int);
int func_021FF6B4(char*p,void*buffer,int count,int*out){int present;present=*(int*)(p+1480);if(present)*out=func_021D7414(p,buffer,count);if(*out!=0 && present!=0)return 1;return 0;}
