/*
 * function: func_021F31B8
 * address: 0x021F31B8
 * packet: pkt_ov194_021F31B8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021F2608 0x021F2608 thumb ov194
 *   func_021F1A10 0x021F1A10 thumb ov194
 */
#include "../include/Obj24905.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020452E8(void *),func_020307B0(void *),func_02082BCC(void *,int,u32),func_021F2608(void *),func_021F1A10(void *);
void func_021F31B8(u8 *p) {int off;func_020452E8(((struct Obj24905 *)p)->fE0);func_021F2608(p);func_021F1A10(p+36);off=0x11c;func_020307B0(*(void **)(p+off));func_020307B0(*(void **)(p+off+4));off+=20;func_02082BCC(p,0,off);}
