/*
 * function: func_021FF038
 * address: 0x021FF038
 * packet: pkt_ov186_021FF038
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF0A0 0x021FF0A0 thumb ov186
 *   func_021FF248 0x021FF248 thumb ov186
 *   func_021FF334 0x021FF334 thumb ov186
 */
#include "../include/Obj06636.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021FF0A0(char *),func_021FF248(char *),func_021FF334(char *);
void func_021FF038(u8*p,u32 mode){switch(mode){case 0:*(void (**)(char*))(p+24)=0;break;case 1:*(void (**)(char*))(p+24)=func_021FF0A0;break;case 2:*(void (**)(char*))(p+24)=func_021FF248;break;case 3:*(void (**)(char*))(p+24)=func_021FF334;break;}((struct Obj06636 *)p)->f1C=0;}
