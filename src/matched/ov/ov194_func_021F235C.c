/*
 * function: func_021F235C
 * address: 0x021F235C
 * packet: pkt_ov194_021F235C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F2190 0x021F2190 thumb ov194
 *   STRBUF_GetEosChar 0x02045A98 arm
 */
#include "../include/Obj02909.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F2190(char *,u16);
extern u16 STRBUF_GetEosChar(void);
void func_021F235C(char *p) { int i; for(i=0;i<((struct Obj02909 *)p)->f20;i++)func_021F2190(p,*(u16 *)((u32)p+(u32)i*2+22));((struct Obj02909 *)p)->f20=0;*(u16 *)((u32)p+((struct Obj02909 *)p)->f20*2+22)=STRBUF_GetEosChar();((struct Obj02909 *)p)->f28=1; }
