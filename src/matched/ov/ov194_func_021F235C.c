/*
 * function: NAMEIN_GRAPHIC_CommitSecondary
 * address: 0x021F235C
 * packet: pkt_ov194_021F235C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   NAMEIN_GRAPHIC_AppendChar 0x021F2190 thumb ov194
 *   STRBUF_GetEosChar 0x02045A98 arm
 */
#include "../include/Obj02909.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int NAMEIN_GRAPHIC_AppendChar(char *,u16);
extern u16 STRBUF_GetEosChar(void);
void NAMEIN_GRAPHIC_CommitSecondary(char *p) { int i; for(i=0;i<((struct Obj02909 *)p)->f20;i++)NAMEIN_GRAPHIC_AppendChar(p,*(u16 *)((u32)p+(u32)i*2+22));((struct Obj02909 *)p)->f20=0;*(u16 *)((u32)p+((struct Obj02909 *)p)->f20*2+22)=STRBUF_GetEosChar();((struct Obj02909 *)p)->f28=1; }
