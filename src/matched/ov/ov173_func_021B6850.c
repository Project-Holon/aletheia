/*
 * function: func_021B6850
 * address: 0x021B6850
 * packet: pkt_ov173_021B6850
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 */
#include "../include/Obj04557.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
void func_021B6850(char *p) { ((struct Obj04557 *)p)->f44=func_02045B38(0,2,204,79); ((struct Obj04557 *)p)->f48=func_0201EC64(79); ((struct Obj04557 *)p)->f4C=STRBUF_Create(256,79); ((struct Obj04557 *)p)->f50=func_02045EC0(((struct Obj04557 *)p)->f44,25); ((struct Obj04557 *)p)->f54=func_02045EC0(((struct Obj04557 *)p)->f44,31); }
