/*
 * function: MONOLITH_TOOL_TITLE_Main
 * address: 0x021B7D00
 * packet: pkt_ov071_021B7D00
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MONOLITH_TOOL_UpdateLabel 0x021B6F04 thumb ov071
 *   MONOLITH_TOOL_TITLE_UpdateSlotIcons 0x021B7E3C thumb ov071
 */
#include "../include/Obj13176.h"

typedef unsigned char  u8;
extern int MONOLITH_TOOL_UpdateLabel(void **p, u8 *q);
extern void MONOLITH_TOOL_TITLE_UpdateSlotIcons(void **,void *);
int MONOLITH_TOOL_TITLE_Main(int a,int *p,char *c,void **d) { if((unsigned char)c[0x2d]==1) return 1; MONOLITH_TOOL_UpdateLabel(((struct Obj13176 *)c)->f4,(u8 *)d); MONOLITH_TOOL_TITLE_UpdateSlotIcons(d,c); switch(*p) { case 0:return 0; default:return 0; } }
