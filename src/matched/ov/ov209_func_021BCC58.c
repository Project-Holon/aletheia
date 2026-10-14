/*
 * function: ZUKAN_LIST_RunState
 * address: 0x021BCC58
 * packet: pkt_ov209_021BCC58
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BE96C 0x021BE96C data a4
 *   ZUKAN_LIST_UpdateActors 0x021BD838 thumb ov209
 *   ZUKAN_LIST_FlushWindows 0x021BD3FC thumb ov209
 *   func_021C93E4 0x021C93E4 thumb ov212
 */
#include "../include/Obj08408.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Context;extern void ZUKAN_LIST_UpdateActors(char *),ZUKAN_LIST_FlushWindows(const struct Context *),func_021C93E4(u32,u32,u8 *);
extern int (*const d_021BE96C[])(char *);
int ZUKAN_LIST_RunState(char *p) { ((struct Obj08408 *)p)->f10=(*(int (**)(char *))((u32)d_021BE96C+*(u32 *)(p+16)*4))(p);if(((struct Obj08408 *)p)->f10==9)return 0;ZUKAN_LIST_UpdateActors(p);ZUKAN_LIST_FlushWindows((const struct Context *)p);func_021C93E4(3,7,(u8 *)p+0xc3c);return 1; }
