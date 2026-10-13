/*
 * function: func_021C824C
 * address: 0x021C824C
 * packet: pkt_ov093_021C824C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes alignment padding follow.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_FIELD_GetStaticSlotObject 0x021EF948 thumb ov093
 */
#include "../include/Obj21115.h"
typedef unsigned char u8;
extern u8 *func_021B9934(char *p, int i);
extern int func_021D59B4(u8 *p, int k);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_FIELD_GetStaticSlotObject(int);
int func_021C824C(u8 *p, int v) { void *m; m=func_021B9934(*(char * *)&((struct Obj21115 *)p)->f8,v); if(func_021D59B4(m,17)==103) return 0; if(BTL_POKEPARAM_HasSick(m,19)) return 0; if(BTL_FIELD_GetStaticSlotObject(7)==0) return 1; return 0; }
